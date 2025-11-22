#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string matchId;
    string player;
    string winner;
    int scoreLeft = 0;
    int scoreRight = 0;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
    int level = -1;
    bool isLeaf() { return left == nullptr && right == nullptr; }
};

class Tournament
{
private:
    // assign levels to every node and record max leaf level
    void assignLevel(Node *node, int level)
    {
        node->level = level;
        if (node->isLeaf())
        {
            this->maxLeafLevel = level;
        }
        else
        {
            assignLevel(node->left, level + 1);
            assignLevel(node->right, level + 1);
        }
    }

    // assign matchIds in level order to internal nodes
    void assignMatchIds()
    {
        queue<Node *> q;
        q.push(this->root);
        int id = 1;

        while (!q.empty())
        {
            Node *tmp = q.front();
            q.pop();

            if (!tmp->isLeaf())
            {
                tmp->matchId = "M" + to_string(id);
                this->matchMap[tmp->matchId] = tmp;
                q.push(tmp->left);
                q.push(tmp->right);
                id++;
            }
        }
    }

    // collect leaves left to right
    vector<Node *> gatherLeavesLeftToRight()
    {
        vector<Node *> leaves;
        // do an in order traversal leaves left to right
        gatherLeaves(root, leaves);
        return leaves;
    }

    void gatherLeaves(Node *n, vector<Node *> &leaves)
    {
        if (!n)
            return;
        if (n->isLeaf())
        {
            leaves.push_back(n);
            return;
        }
        gatherLeaves(n->left, leaves);
        gatherLeaves(n->right, leaves);
    }

    // propagate if this node can auto declare a winner
    void propagateWinnerToParent(Node *node)
    {
        Node *curr = node->parent;
        while (curr)
        {
            if (curr->winner != "")
            { // already decided
                curr = curr->parent;
                continue;
            }
            string leftP = participantName(curr->left);
            string rightP = participantName(curr->right);
            if (leftP == "BYE" && rightP != "?")
            {
                curr->winner = rightP;
                cout << "Auto-advance: " << rightP << " wins " << curr->matchId << " (opponent BYE)\n";
            }
            else if (rightP == "BYE" && leftP != "?")
            {
                curr->winner = leftP;
                cout << "Auto-advance: " << leftP << " wins " << curr->matchId << " (opponent BYE)\n";
            }
            else
            {
                // if both participants known not auto: we don't auto decide between two players require recordResult
                // but if both sides already have winners and they match names still undecided until recordResult called
            }
            curr = curr->parent;
        }
    }

    // initial auto advance pass across all internal nodes bottom up
    void propagateAutoAdvanceAll()
    {
        // collect internal nodes in reverse level order (bottom to top)
        vector<Node *> internals;
        queue<Node *> q;
        q.push(this->root);
        while (!q.empty())
        {
            Node *tmp = q.front();
            q.pop();
            if (!tmp->isLeaf())
            {
                internals.push_back(tmp);
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        // reverse so bottom up
        reverse(internals.begin(), internals.end());
        for (Node *n : internals)
        {
            if (n->winner != "")
                continue;
            string leftP = participantName(n->left);
            string rightP = participantName(n->right);
            if (leftP == "BYE" && rightP != "?")
            {
                n->winner = rightP;
            }
            else if (rightP == "BYE" && leftP != "?")
            {
                n->winner = leftP;
            }
        }
        // after assigning winners bottom up propagate to parents if needed
        for (Node *n : internals)
        {
            if (n->winner != "")
                propagateWinnerToParent(n);
        }
    }

    // LCA computation using ancestor marking
    Node *lowestCommonAncestor(Node *parent, Node *a, Node *b)
    {
        if (parent == nullptr || parent == a || parent == b)
            return parent;

        Node *left = lowestCommonAncestor(parent->left, a, b);
        Node *right = lowestCommonAncestor(parent->right, a, b);

        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return parent;
    }

public:
    Node *root = nullptr;
    int leavesCount = 0;
    int maxLeafLevel = 0;
    unordered_map<string, Node *> matchMap;
    unordered_map<string, Node *> playerLeafMap;

    // Get participantName if
    string participantName(Node *child)
    {
        if (!child)
            return "?";
        if (child->isLeaf())
            return child->player;
        return child->winner == "" ? "?" : child->winner;
    }

    // Build bracket from player list left to right
    void buildBracket(vector<string> players)
    {
        if (players.empty())
        {
            cout << "No players provided\n";
            return;
        }

        // next power of two
        int n = players.size();
        int L = 1;
        int levelCount = 0;
        while (L < n)
        {
            L *= 2;
        }
        this->leavesCount = L;

        // create leaves
        vector<Node *> leaves;
        for (int i = 0; i < L; ++i)
        {
            Node *leaf = new Node();
            if (i < n)
            {
                playerLeafMap[players[i]] = leaf;
                leaf->player = players[i];
            }
            else
                leaf->player = "BYE";

            leaves.push_back(leaf);
        }

        // build internal nodes bottom up
        vector<Node *> curr = leaves;
        int level = 0;
        while (curr.size() > 1)
        {
            vector<Node *> next;
            for (int i = 0; i < curr.size(); i += 2)
            {
                Node *internal = new Node();
                internal->left = curr[i];
                internal->right = curr[i + 1];
                internal->left->parent = internal;
                internal->right->parent = internal;
                next.push_back(internal);
            }
            curr = next;
            level++;
        }
        this->root = curr[0];

        // compute levels
        assignLevel(root, 0);

        // assign matchIds to internal nodes in level order
        assignMatchIds();

        // initial auto advance pass
        propagateAutoAdvanceAll();

        cout << "Bracket built: " << players.size() << " players, " << leavesCount << " leaves (" << leavesCount - players.size() << " BYEs)\n";
    }

    // record a result returns true if accepted, false for rejection
    bool recordResult(string matchId, string winnerName)
    {
        auto it = matchMap.find(matchId);
        if (it == matchMap.end())
        {
            cout << "recordResult: matchId not found: " << matchId << "\n";
            return false;
        }
        Node *node = it->second;
        if (node->winner != "")
        {
            cout << "recordResult: match already decided: " << matchId << " winner=" << node->winner << "\n";
            return false;
        }
        // determine left/right participants
        string leftP = participantName(node->left);
        string rightP = participantName(node->right);

        // BYE auto advance check: if one is BYE and other known
        if (leftP == "BYE" && rightP != "?")
        {
            // auto advance rightP
            node->winner = rightP;
            cout << "Auto-advance by BYE: " << rightP << " advanced at " << matchId << "\n";
            propagateWinnerToParent(node);
            return true;
        }
        if (rightP == "BYE" && leftP != "?")
        {
            node->winner = leftP;
            cout << "Auto-advance by BYE: " << leftP << " advanced at " << matchId << "\n";
            propagateWinnerToParent(node);
            return true;
        }

        // both participants must be known
        if (leftP == "?" || rightP == "?")
        {
            cout << "recordResult: both participants are not yet known (left=" << leftP << ", right=" << rightP << ")\n";
            return false;
        }
        // winnerName must match one of the participants
        if (winnerName != leftP && winnerName != rightP)
        {
            cout << "recordResult: winner '" << winnerName << "' is not one of the match participants (" << leftP << ", " << rightP << ")\n";
            return false;
        }
        node->winner = winnerName;
        cout << "Recorded: " << matchId << " winner = " << winnerName << "\n";
        propagateWinnerToParent(node);
        return true;
    }

    // path to final: list matchIds from first match up to final
    vector<Node *> pathToFinal(string player)
    {
        vector<Node *> res;
        auto it = playerLeafMap.find(player);
        if (it == playerLeafMap.end())
        {
            cout << "pathToFinal: player not found: " << player << "\n";
            return res;
        }
        Node *node = it->second;
        Node *curr = node->parent;
        while (curr != nullptr)
        {
            if (!curr->matchId.empty())
                res.push_back(curr);
            curr = curr->parent;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    pair<string, int> wouldMeet(string p1, string p2)
    {
        if (playerLeafMap.find(p1) == playerLeafMap.end() || playerLeafMap.find(p2) == playerLeafMap.end())
        {
            return {"", -1};
        }

        Node *a = playerLeafMap[p1];
        Node *b = playerLeafMap[p2];
        Node *lca = lowestCommonAncestor(this->root, a, b);

        if (!lca)
            return {"", -1};
        if (lca->matchId.empty())
            return {"", -1};

        int round = (maxLeafLevel - lca->level); // round 1 = parent of leaves
        return {lca->matchId, round};
    }

    // Print bracket grouped by rounds
    void printBracket()
    {
        if (!this->root)
        {
            cout << "No bracket.\n";
            return;
        }

        // level order
        queue<Node *> q;
        q.push(this->root);
        int currLevel = 0;
        cout << "Total Rounds = " << maxLeafLevel << "\n";
        while (!q.empty())
        {
            int len = q.size();

            // only one player
            if (maxLeafLevel == 0)
            {
                Node *only = q.front();
                q.pop();
                cout << "Winner: " << only->player << "\n\n";
                break;
            }

            // reached leaves
            if (currLevel == maxLeafLevel)
            {
                break;
            }

            if (currLevel == 0)
                cout << "Final:\n";
            else if (currLevel == 1)
                cout << "Semi Final:\n";
            else if (currLevel == 2)
                cout << "Quarter Final:\n";
            else if (currLevel == 3)
                cout << "Round of 16:\n";
            else
                cout << "Round " << maxLeafLevel - currLevel + 1 << ":\n";

            for (int i = 0; i < len; ++i)
            {
                Node *tmp = q.front();
                q.pop();
                string leftP = participantName(tmp->left);
                string rightP = participantName(tmp->right);
                string win = (tmp->winner == "" ? "?" : tmp->winner);
                cout << "  " << tmp->matchId << "  L=" << leftP << "  R=" << rightP << "  W=" << win << "\n";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            currLevel++;
            cout << "\n";
        }
        // print players
        vector<Node *> players = gatherLeavesLeftToRight();
        cout << "Players:\n";
        for (auto *p : players)
            cout << "  " << p->player << "\n";
    }
};