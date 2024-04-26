#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 구조체 정의
typedef struct {
    char name[20];
    int hp;
    int level;
} Pokemon;

typedef struct {
    char name[20];
    int price;
} Item;

// 전역 변수
Pokemon playerPokemons[5] = { {"피카츄", 100, 5}, {"꼬부기", 100, 1}, {"파이리", 100, 3}, {"라이츄", 100, 1}, {"김수민", 100000000, 100000000} };
Item shopItems[5] = { {"Potion", 300}, {"Pokeball", 200}, {"Revive", 500}, {"Antidote", 100}, {"Escape Rope", 150} };
int playerMoney = 1000;
Pokemon* selectedPokemon = NULL; 

// 함수 선언
void saveGame();
void loadGame();
void shop();
void pokemonCenter();
void pokedex();
void adventure();
void selectPokemon();

int main() {
    int choice;

    while (1) {
        printf("===============================\n");
        printf("모험을 진행하시겠습니까?\n");
        printf(" 1. 네  2. 저장  3. 상점  4. 포켓몬센터  5. 포켓몬 도감  6. 게임 불러오기  7. 게임 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            selectPokemon();
            adventure();
            break;
        case 2:
            saveGame();
            break;
        case 3:
            shop();
            break;
        case 4:
            pokemonCenter();
            break;
        case 5:
            pokedex();
            break;
        case 6:
            loadGame();
            break;
        case 7:
            printf("게임을 종료합니다.\n");
            return 0; // 프로그램 종료
        default:
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}

void saveGame() {
    FILE* fp = fopen("game_save.txt", "w");
    if (fp == NULL) {
        printf("Failed to save the game.\n");
        return;
    }
    fprintf(fp, "Money: %d\n", playerMoney); 
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "Pokemon: %s, HP: %d, Level: %d\n", playerPokemons[i].name, playerPokemons[i].hp, playerPokemons[i].level); 
    }
    fclose(fp);
    printf("Game saved.\n");
}

void loadGame() {
    FILE* fp = fopen("game_save.txt", "r");
    if (fp == NULL) {
        printf("Failed to load the game.\n");
        return;
    }
    scanf_s(fp, "Money: %d\n", &playerMoney); 
    for (int i = 0; i < 5; i++) {
        scanf_s(fp, "Pokemon: %[^,], HP: %d, Level: %d\n", playerPokemons[i].name, &playerPokemons[i].hp, &playerPokemons[i].level); 
    }
    fclose(fp);
    printf("Game loaded.\n");
}

void shop() {
    int choice;
    printf("===============================\n");
    printf("상점에 오신 것을 환영합니다!\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - %d원\n", i + 1, shopItems[i].name, shopItems[i].price);
    }
    printf("6. 돌아가기\n");
    printf("무엇을 구매하시겠습니까?: ");
    scanf_s("%d", &choice);

    if (choice == 6) {
        return; 
    }
    else if (choice < 1 || choice > 5) {
        printf("잘못된 선택입니다. 다시 선택해주세요.\n");
    }
    else {
        if (playerMoney >= shopItems[choice - 1].price) {
            playerMoney -= shopItems[choice - 1].price;
            printf("%s를 구매하였습니다! 현재 남은 돈은 %d원입니다.\n", shopItems[choice - 1].name, playerMoney);
        }
        else {
            printf("돈이 부족합니다!\n");
        }
    }
}

void pokemonCenter() {
    printf("===============================\n");
    printf("포켓몬 센터에 오신 것을 환영합니다!\n");
    printf("모든 포켓몬의 HP가 회복되었습니다.\n");
    for (int i = 0; i < 5; i++) {
        playerPokemons[i].hp = 100; 
    }
}

void pokedex() {
    printf("===============================\n");
    printf("포켓몬 도감을 확인합니다.\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - HP: %d, Level: %d\n", playerPokemons[i].name, playerPokemons[i].hp, playerPokemons[i].level);
    }
}

void selectPokemon() {
    int choice;
    printf("================================\n");
    printf("포켓몬을 선택하세요.\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - HP: %d, Level: %d\n", i + 1, playerPokemons[i].name, playerPokemons[i].hp, playerPokemons[i].level);
    }
    printf("선택: ");
    scanf_s("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        selectPokemon(); 
    }
    else {
        selectedPokemon = &playerPokemons[choice - 1];
        printf("당신은 %s를 선택했습니다!\n", selectedPokemon->name);
    }
}

void adventure() {
    printf("===============================\n");
    printf("모험을 시작합니다!\n");
    // 야생 포켓몬 출현 및 싸우는 코드는 작성을 못했습니다.
    printf("모험을 마쳤습니다!\n");
}