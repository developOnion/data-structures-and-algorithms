#include "./Student.hpp"
#include "./StudentManager.hpp"

int main(void)
{
    std::vector<Student> students = {
        {20250050, "Anna"},
        {20250020, "Bora"},
        {20250080, "Chenda"},
        {20250010, "Dara"},
        {20250030, "Eang"},
        {20250070, "Fara"},
    };

    StudentManager studentManager;

    for (int i = 0; i < students.size(); ++i)
    {
        std::cout << students[i].getName() << ":\n";
        studentManager.addStudent(students[i]);
    }
    std::cout << "\n";

    std::cout << "Inorder Traversal\n";
    studentManager.inorderPrint();
    std::cout << "\n";

    int idToSearch = 20250000;
    std::cout << "Search for Student with ID " << idToSearch << "\n";
    Student stu1 = studentManager.searchById(idToSearch);
    std::cout << "Student ID " << idToSearch << " ";
    if (stu1.getName() == "")
        std::cout << "(does not exists)\n";
    else
        std::cout << "(exists)\n";
    std::cout << "\n";

    int idToDelete = 20250050;
    std::cout << "Delete Student with ID " << idToDelete << "\n";
    studentManager.deleteStudentById(idToDelete);
    std::cout << "\n";

    std::cout << "Inorder Traversal\n";
    studentManager.inorderPrint();
    std::cout << "\n";

    idToDelete = 20250020;
    std::cout << "Delete Student with ID " << idToDelete << "\n";
    studentManager.deleteStudentById(idToDelete);
    std::cout << "\n";

    std::cout << "Inorder Traversal\n";
    studentManager.inorderPrint();

    return 0;
}