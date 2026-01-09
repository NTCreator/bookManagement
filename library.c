#include "library.h"

/* Global variables */
static Book s_books[MAX_BOOKS];
static User s_users[MAX_USERS];
static int s_bookCount = 0;
static int s_userCount = 0;
static int s_nextBookId = 1;
static int s_nextUserId = 1;

/* Clear input buffer */
void clearInputBuffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) 
    {
          
    }
}

/*
 * Find book index by ID
 * Returns: Index if found, -1 if not found
 */
int findBookById(int bookId)
{
    int i = 0;
    
    for (i = 0; i < s_bookCount; i++) {
        if (s_books[i].id == bookId) {
            return i;
        }
    }
    return -1;
}

/*
 * Find user index by ID
 * Returns: Index if found, -1 if not found
 */
int findUserById(int userId)
{
    int i = 0;
    
    for (i = 0; i < s_userCount; i++) {
        if (s_users[i].id == userId) {
            return i;
        }
    }
    return -1;
}

/* Add book */
void addBook(void)
{
    Book newBook;
    
    if (s_bookCount >= MAX_BOOKS) {
        printf("\nThu vien da day! Khong the them sach.\n");
        return;
    }
    
    newBook.id = s_nextBookId;
    newBook.isBorrowed = false;
    s_nextBookId++;
    
    printf("\n=== THEM SACH MOI ===\n");
    printf("Nhap tieu de sach: ");
    clearInputBuffer();
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';
    
    printf("Nhap tac gia: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    
    s_books[s_bookCount] = newBook;
    s_bookCount++;
    
    printf("\nThem sach thanh cong! ID: %d\n", newBook.id);
}

/* Edit book */
void editBook(void)
{
    int bookId = 0;
    int index = 0;
    
    printf("\n=== CHINH SUA THONG TIN SACH ===\n");
    printf("Nhap ID sach can sua: ");
    scanf("%d", &bookId);
    
    index = findBookById(bookId);
    if (index == -1) {
        printf("\nKhong tim thay sach voi ID: %d\n", bookId);
        return;
    }
    
    printf("\nThong tin hien tai:\n");
    printf("ID: %d\n", s_books[index].id);
    printf("Tieu de: %s\n", s_books[index].title);
    printf("Tac gia: %s\n", s_books[index].author);
    
    printf("\nNhap tieu de moi: ");
    clearInputBuffer();
    fgets(s_books[index].title, MAX_TITLE_LENGTH, stdin);
    s_books[index].title[strcspn(s_books[index].title, "\n")] = '\0';
    
    printf("Nhap tac gia moi: ");
    fgets(s_books[index].author, MAX_AUTHOR_LENGTH, stdin);
    s_books[index].author[strcspn(s_books[index].author, "\n")] = '\0';
    
    printf("\nCap nhat thong tin thanh cong!\n");
}

/* Delete book */
void deleteBook(void)
{
    int bookId = 0;
    int index = 0;
    int i = 0;
    
    printf("\n=== XOA SACH ===\n");
    printf("Nhap ID sach can xoa: ");
    scanf("%d", &bookId);
    
    index = findBookById(bookId);
    if (index == -1) {
        printf("\nKhong tim thay sach voi ID: %d\n", bookId);
        return;
    }
    
    if (s_books[index].isBorrowed) {
        printf("\nKhong the xoa! Sach dang duoc muon.\n");
        return;
    }
    
    /* Shift books to fill the gap */
    for (i = index; i < s_bookCount - 1; i++) {
        s_books[i] = s_books[i + 1];
    }
    s_bookCount--;
    
    printf("\nXoa sach thanh cong!\n");
}

/* Display book */
void displayBooks(void)
{
    int i = 0;
    
    printf("\n=== DANH SACH SACH ===\n");
    if (s_bookCount == 0) {
        printf("Thu vien chua co sach nao.\n");
        return;
    }
    
    printf("%-5s %-30s %-20s %-15s\n", 
           "ID", "Tieu de", "Tac gia", "Trang thai");
    printf("--------------------------------------------");
    printf("-------------------------------\n");
    
    for (i = 0; i < s_bookCount; i++) {
        printf("%-5d %-30s %-20s %-15s\n",
               s_books[i].id,
               s_books[i].title,
               s_books[i].author,
               s_books[i].isBorrowed ? "Dang muon" : "San sang");
    }
}

/* Add user */
void addUser(void)
{
    User newUser;
    int i = 0;
    
    if (s_userCount >= MAX_USERS) {
        printf("\nDa dat gioi han nguoi dung!\n");
        return;
    }
    
    newUser.id = s_nextUserId;
    newUser.borrowedCount = 0;
    s_nextUserId++;
    
    for (i = 0; i < MAX_BORROWED_BOOKS; i++) {
        newUser.borrowedBookIds[i] = 0;
    }
    
    printf("\n=== THEM NGUOI DUNG MOI ===\n");
    printf("Nhap ten nguoi dung: ");
    clearInputBuffer();
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';
    
    s_users[s_userCount] = newUser;
    s_userCount++;
    
    printf("\nThem nguoi dung thanh cong! ID: %d\n", newUser.id);
}

/* Edit user */
void editUser(void)
{
    int userId = 0;
    int index = 0;
    
    printf("\n=== CHINH SUA THONG TIN NGUOI DUNG ===\n");
    printf("Nhap ID nguoi dung can sua: ");
    scanf("%d", &userId);
    
    index = findUserById(userId);
    if (index == -1) {
        printf("\nKhong tim thay nguoi dung voi ID: %d\n", userId);
        return;
    }
    
    printf("\nThong tin hien tai:\n");
    printf("ID: %d\n", s_users[index].id);
    printf("Ten: %s\n", s_users[index].name);
    
    printf("\nNhap ten moi: ");
    clearInputBuffer();
    fgets(s_users[index].name, MAX_NAME_LENGTH, stdin);
    s_users[index].name[strcspn(s_users[index].name, "\n")] = '\0';
    
    printf("\nCap nhat thong tin thanh cong!\n");
}

/* Delete user */
void deleteUser(void)
{
    int userId = 0;
    int index = 0;
    int i = 0;
    
    printf("\n=== XOA NGUOI DUNG ===\n");
    printf("Nhap ID nguoi dung can xoa: ");
    scanf("%d", &userId);
    
    index = findUserById(userId);
    if (index == -1) {
        printf("\nKhong tim thay nguoi dung voi ID: %d\n", userId);
        return;
    }
    
    if (s_users[index].borrowedCount > 0) {
        printf("\nKhong the xoa! Nguoi dung dang muon sach.\n");
        return;
    }
    
    /* Shift users to fill the gap */
    for (i = index; i < s_userCount - 1; i++) {
        s_users[i] = s_users[i + 1];
    }
    s_userCount--;
    
    printf("\nXoa nguoi dung thanh cong!\n");
}

/* Display all users */
void displayUsers(void)
{
    int i = 0;
    int j = 0;
    
    printf("\n=== DANH SACH NGUOI DUNG ===\n");
    if (s_userCount == 0) {
        printf("Chua co nguoi dung nao.\n");
        return;
    }
    
    for (i = 0; i < s_userCount; i++) {
        printf("\nID: %d | Ten: %s\n", 
               s_users[i].id, s_users[i].name);
        printf("So sach dang muon: %d\n", s_users[i].borrowedCount);
        
        if (s_users[i].borrowedCount > 0) {
            printf("Danh sach sach da muon: ");
            for (j = 0; j < s_users[i].borrowedCount; j++) {
                printf("%d ", s_users[i].borrowedBookIds[j]);
            }
            printf("\n");
        }
    }
}

/* Borrow a book */
void borrowBook(void)
{
    int userId = 0;
    int bookId = 0;
    int userIndex = 0;
    int bookIndex = 0;
    
    printf("\n=== MUON SACH ===\n");
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &userId);
    
    userIndex = findUserById(userId);
    if (userIndex == -1) {
        printf("\nKhong tim thay nguoi dung!\n");
        return;
    }
    
    if (s_users[userIndex].borrowedCount >= MAX_BORROWED_BOOKS) {
        printf("\nNguoi dung da muon toi da sach!\n");
        return;
    }
    
    printf("Nhap ID sach can muon: ");
    scanf("%d", &bookId);
    
    bookIndex = findBookById(bookId);
    if (bookIndex == -1) {
        printf("\nKhong tim thay sach!\n");
        return;
    }
    
    if (s_books[bookIndex].isBorrowed) {
        printf("\nSach da duoc muon roi!\n");
        return;
    }
    
    /* Update book status */
    s_books[bookIndex].isBorrowed = true;
    
    /* Update user borrowed list */
    s_users[userIndex].borrowedBookIds[s_users[userIndex].borrowedCount]
        = bookId;
    s_users[userIndex].borrowedCount++;
    
    printf("\nMuon sach thanh cong!\n");
    printf("Sach: %s\n", s_books[bookIndex].title);
    printf("Nguoi muon: %s\n", s_users[userIndex].name);
}

/* Return a book */
void returnBook(void)
{
    int userId = 0;
    int bookId = 0;
    int userIndex = 0;
    int bookIndex = 0;
    int i = 0;
    int j = 0;
    bool found = false;
    
    printf("\n=== TRA SACH ===\n");
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &userId);
    
    userIndex = findUserById(userId);
    if (userIndex == -1) {
        printf("\nKhong tim thay nguoi dung!\n");
        return;
    }
    
    printf("Nhap ID sach can tra: ");
    scanf("%d", &bookId);
    
    bookIndex = findBookById(bookId);
    if (bookIndex == -1) {
        printf("\nKhong tim thay sach!\n");
        return;
    }
    
    /* Find book in user's borrowed list */
    for (i = 0; i < s_users[userIndex].borrowedCount; i++) {
        if (s_users[userIndex].borrowedBookIds[i] == bookId) {
            found = true;
            /* Shift remaining books */
            for (j = i; j < s_users[userIndex].borrowedCount - 1; j++) {
                s_users[userIndex].borrowedBookIds[j] = 
                    s_users[userIndex].borrowedBookIds[j + 1];
            }
            s_users[userIndex].borrowedCount--;
            break;
        }
    }
    
    if (!found) {
        printf("\nNguoi dung nay khong muon sach nay!\n");
        return;
    }
    
    /* Update book status */
    s_books[bookIndex].isBorrowed = false;
    
    printf("\nTra sach thanh cong!\n");
    printf("Sach: %s\n", s_books[bookIndex].title);
    printf("Nguoi tra: %s\n", s_users[userIndex].name);
}
