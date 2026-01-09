#include "library.h"
#include "stdio.h"
/* Display main menu */
void displayMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("   QUAN LY THU VIEN\n");
    printf("========================================\n");
    printf("1.  Them sach\n");
    printf("2.  Chinh sua sach\n");
    printf("3.  Xoa sach\n");
    printf("4.  Hien thi danh sach sach\n");
    printf("5.  Them nguoi dung\n");
    printf("6.  Chinh sua nguoi dung\n");
    printf("7.  Xoa nguoi dung\n");
    printf("8.  Hien thi danh sach nguoi dung\n");
    printf("9.  Muon sach\n");
    printf("10. Tra sach\n");
    printf("0.  Thoat\n");
    printf("========================================\n");
    printf("Lua chon cua ban: ");
}

int main(void)
{
    int choice = 0;
    
    printf("\n");
    printf("**************************************\n");
    printf("  CHAO MUNG DEN VOI HE THONG\n");
    printf("     QUAN LY THU VIEN\n");
    printf("**************************************\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                editBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                addUser();
                break;
            case 6:
                editUser();
                break;
            case 7:
                deleteUser();
                break;
            case 8:
                displayUsers();
                break;
            case 9:
                borrowBook();
                break;
            case 10:
                returnBook();
                break;
            case 0:
                printf("\nCam on ban da su dung he thong!\n");
                printf("Hen gap lai!\n\n");
                return 0;
            default:
                printf("\nLua chon khong hop le!\n");
                printf("Vui long chon tu 0-10.\n");
        }
        
        printf("\nNhan Enter de tiep tuc...");
        clearInputBuffer();
        getchar();
    }
    
    return 0;
}
