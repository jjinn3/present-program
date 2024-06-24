#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Gift {
    char name[50];
    char category[50];
    float price;
    int ageGroup;
    char preference[50]; 
} Gift;

typedef struct Node {
    Gift gift;
    struct Node* next;
} Node;

Node* createNode(const char* name, const char* category, float price, int ageGroup, const char* preference) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy_s(newNode->gift.name, name);
    strcpy_s(newNode->gift.category, category);
    newNode->gift.price = price;
    newNode->gift.ageGroup = ageGroup;
    strcpy_s(newNode->gift.preference, preference);
    newNode->next = NULL;
    return newNode;
}

void addGift(Node** head, const char* name, const char* category, float price, int ageGroup, const char* preference) {
    Node* newNode = createNode(name, category, price, ageGroup, preference);
    newNode->next = *head;
    *head = newNode;
}

void printGifts(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Name: %s, Category: %s, Price: %.2f, Age Group: %d, Preference: %s\n",
            current->gift.name, current->gift.category, current->gift.price, current->gift.ageGroup, current->gift.preference);
        current = current->next;
    }
}

const char* addMessage(const char* occasion) {
    if (strcmp(occasion, "birthday") == 0) {
        return "Happy Birthday! Wishing you a day filled with love, joy, and wonderful surprises! May your year ahead be full of great adventures and opportunities. Celebrate your special day to the fullest, and know that you are loved and appreciated.\n";
    }
    else if (strcmp(occasion, "anniversary") == 0) {
        return "Happy Anniversary! May your love continue to grow and flourish with each passing year. Today marks another beautiful milestone in your journey together. May your bond be stronger, your love deeper, and your joy greater as you celebrate this special day.\n";
    }
    else if (strcmp(occasion, "christmas") == 0) {
        return "Merry Christmas! May your holidays be filled with warmth, happiness, and joy. May this festive season bring you closer to your loved ones and fill your heart with peace and love. Wishing you a holiday season that's merry and bright, and a new year filled with promise and potential.\n";
    }
    else if (strcmp(occasion, "graduation") == 0) {
        return "Congratulations on your Graduation! Wishing you success and happiness in your future endeavors. You've worked hard and achieved so much, and now a world of opportunities awaits you. May your future be as bright as your achievements and as rewarding as your efforts. Celebrate your success and embrace the exciting journey ahead.\n";
    }
    else {
        return "Best wishes for a wonderful day! No matter the occasion, may it be filled with happiness, laughter, and unforgettable moments. You deserve all the joy and success that life has to offer. Enjoy every moment and make beautiful memories.\n";
    }
}


void recommendGifts(Node* head, int ageGroup, const char* preference, const char* occasion) {
    Node* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->gift.ageGroup == ageGroup && strcmp(current->gift.preference, preference) == 0) {
            printf("Recommended Gift: Name: %s, Category: %s, Price: %.2f, Age Group: %d, Preference: %s\n",
                current->gift.name, current->gift.category, current->gift.price, current->gift.ageGroup, current->gift.preference);
            found = 1;
            printf("Message: %s\n", addMessage(occasion));
        }
        current = current->next;
    }
    if (!found) {
        printf("No gifts found for age group %d with preference '%s'\n", ageGroup, preference);
    }
}

int main() {
    Node* head = NULL;

    addGift(&head, "Teddy Bear", "Toy", 20.0, 1, "동물");
    addGift(&head, "Chocolate Box", "Food", 15.0, 3, "음식");
    addGift(&head, "Smart Watch", "Electronics", 150.0, 2, "전자기기");
    addGift(&head, "Book", "Education", 25.0, 3, "책");
    addGift(&head, "Basketball", "Sports", 30.0, 2, "운동");
    addGift(&head, "Lego Set", "Toy", 60.0, 1, "블록");
    addGift(&head, "Headphones", "Electronics", 80.0, 2, "음악");
    addGift(&head, "Scarf", "Fashion", 20.0, 4, "패션");
    addGift(&head, "Puzzle", "Toy", 15.0, 1, "게임");
    addGift(&head, "Sketchbook", "Art", 10.0, 2, "미술");
    addGift(&head, "Cooking Kit", "Food", 35.0, 5, "요리");
    addGift(&head, "Bike", "Sports", 200.0, 2, "운동");
    addGift(&head, "Fitness Tracker", "Electronics", 120.0, 6, "운동");
    addGift(&head, "Board Game", "Game", 40.0, 1, "게임");
    addGift(&head, "Concert Tickets", "Entertainment", 150.0, 7, "음악");
    addGift(&head, "Video Game", "Game", 60.0, 2, "게임");
    addGift(&head, "Art Supplies", "Art", 50.0, 2, "미술");
    addGift(&head, "Gym Membership", "Health", 300.0, 6, "운동");
    addGift(&head, "Camera", "Electronics", 500.0, 7, "사진");
    addGift(&head, "Toy Car", "Toy", 20.0, 1, "자동차");
    addGift(&head, "Painting Set", "Art", 30.0, 2, "미술");
    addGift(&head, "Football", "Sports", 25.0, 2, "운동");
    addGift(&head, "Fitness Equipment", "Health", 100.0, 6, "운동");
    addGift(&head, "Laptop", "Electronics", 1000.0, 7, "전자기기");
    addGift(&head, "Action Figure", "Toy", 20.0, 1, "영웅");
    addGift(&head, "Music Album", "Entertainment", 15.0, 2, "음악");
    addGift(&head, "Sunglasses", "Fashion", 50.0, 3, "패션");
    addGift(&head, "RC Helicopter", "Toy", 70.0, 1, "전자기기");
    addGift(&head, "Yoga Mat", "Health", 25.0, 5, "운동");
    addGift(&head, "Movie Tickets", "Entertainment", 30.0, 6, "영화");
    addGift(&head, "Drone", "Electronics", 300.0, 2, "전자기기");
    addGift(&head, "Novel", "Book", 20.0, 3, "책");
    addGift(&head, "Tablet", "Electronics", 400.0, 7, "전자기기");
    addGift(&head, "Basketball Hoop", "Sports", 200.0, 2, "운동");
    addGift(&head, "Music Instrument", "Music", 150.0, 2, "음악");
    addGift(&head, "Knitting Kit", "Craft", 30.0, 8, "수공예");
    addGift(&head, "Flower Bouquet", "Decoration", 50.0, 7, "장식");
    addGift(&head, "Gardening Tools", "Outdoors", 45.0, 6, "정원");
    addGift(&head, "Fishing Rod", "Outdoors", 100.0, 6, "낚시");
    addGift(&head, "Rocking Chair", "Furniture", 150.0, 8, "가구");
    addGift(&head, "Walking Cane", "Health", 40.0, 8, "건강");
    addGift(&head, "Classical Music CD", "Music", 20.0, 7, "음악");
    addGift(&head, "Wool Blanket", "Home", 80.0, 7, "홈");
    addGift(&head, "Bird Feeder", "Outdoors", 25.0, 8, "정원");
    addGift(&head, "Board Game", "Game", 40.0, 5, "게임");
    addGift(&head, "Wine", "Food", 100.0, 6, "음료");
    addGift(&head, "Electric Kettle", "Home", 60.0, 5, "주방");
    addGift(&head, "Leather Wallet", "Fashion", 80.0, 6, "패션");
    addGift(&head, "Bonsai Tree", "Decoration", 70.0, 7, "장식");

    // 선물 리스트 출력
    //printf("Gift List:\n");
    //printGifts(head);

    int ageGroup;
    char preference[50];
    char occasion[50];
    printf("\nEnter the age group (1: 10대, 2: 20대, 3: 30대, 4: 40대, 5: 50대, 6: 60대, 7: 70대, 8: 80대): ");
    scanf_s("%d", &ageGroup);
    printf("Enter the preference (e.g., 동물, 음식, 전자기기, 음악, 패션, 장식, 게임, 건강, 정원, 자동차, 요리 등): ");
    scanf_s("%49s", preference, (unsigned)_countof(preference));
    printf("Enter the occasion (e.g., birthday, anniversary, christmas, graduation): ");
    scanf_s("%49s", occasion, (unsigned)_countof(occasion));

    printf("\n===================================================================================\n");
    printf("\nGift Recommendations for age group %d with preference '%s' on occasion '%s':\n", ageGroup, preference, occasion);
    recommendGifts(head, ageGroup, preference, occasion);
    printf("\n===================================================================================\n");

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
