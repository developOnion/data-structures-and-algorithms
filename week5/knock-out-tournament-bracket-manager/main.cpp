#include "./Tournament.hpp"

int main()
{
    Tournament T;
    vector<string> players = {"Ronaldo", "Messi", "Neymar"};
    T.buildBracket(players);

    cout << "\n\nInitial bracket:\n";
    T.printBracket();

    cout << "\n\nRecord result M2: Messi wons\n";
    T.recordResult("M2", "Messi");

    cout << "\n\nUpdated bracket:\n";
    T.printBracket();

    cout << "\n\nRecord result M1: Messi wins\n";
    T.recordResult("M1", "Messi");

    cout << "\n\nFinal bracket:\n";
    T.printBracket();

    cout << "\n\nPath to final for Messi:\n";
    vector<Node *> path = T.pathToFinal("Messi");
    for (int i = 0; i < path.size(); i++)
    {
        const Node *match = path[i];
        int round = T.maxLeafLevel - match->level + 1;

        if (match->level == 0)
            cout << "Final";
        else if (match->level == 1)
            cout << "Semi Final";
        else if (match->level == 2)
            cout << "Quarter Final";
        else if (match->level == 3)
            cout << "Round of 16";
        else
            cout << "Round " << round;
        cout << ": " << match->matchId;
        cout << "-Opponent(";
        if (T.participantName(match->left) == "Messi")
            cout << T.participantName(match->right);
        else
            cout << T.participantName(match->left);
        cout << ")\n";
    }

    return 0;
}