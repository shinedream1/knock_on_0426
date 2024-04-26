#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ����ü ����
typedef struct {
    char name[20];
    int hp;
    int level;
} Pokemon;

typedef struct {
    char name[20];
    int price;
} Item;

// ���� ����
Pokemon playerPokemons[5] = { {"��ī��", 100, 5}, {"���α�", 100, 1}, {"���̸�", 100, 3}, {"������", 100, 1}, {"�����", 100000000, 100000000} };
Item shopItems[5] = { {"Potion", 300}, {"Pokeball", 200}, {"Revive", 500}, {"Antidote", 100}, {"Escape Rope", 150} };
int playerMoney = 1000;
Pokemon* selectedPokemon = NULL; 

// �Լ� ����
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
        printf("������ �����Ͻðڽ��ϱ�?\n");
        printf(" 1. ��  2. ����  3. ����  4. ���ϸ���  5. ���ϸ� ����  6. ���� �ҷ�����  7. ���� ����\n");
        printf("����: ");
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
            printf("������ �����մϴ�.\n");
            return 0; // ���α׷� ����
        default:
            printf("�߸��� �����Դϴ�.\n");
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
    printf("������ ���� ���� ȯ���մϴ�!\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - %d��\n", i + 1, shopItems[i].name, shopItems[i].price);
    }
    printf("6. ���ư���\n");
    printf("������ �����Ͻðڽ��ϱ�?: ");
    scanf_s("%d", &choice);

    if (choice == 6) {
        return; 
    }
    else if (choice < 1 || choice > 5) {
        printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
    }
    else {
        if (playerMoney >= shopItems[choice - 1].price) {
            playerMoney -= shopItems[choice - 1].price;
            printf("%s�� �����Ͽ����ϴ�! ���� ���� ���� %d���Դϴ�.\n", shopItems[choice - 1].name, playerMoney);
        }
        else {
            printf("���� �����մϴ�!\n");
        }
    }
}

void pokemonCenter() {
    printf("===============================\n");
    printf("���ϸ� ���Ϳ� ���� ���� ȯ���մϴ�!\n");
    printf("��� ���ϸ��� HP�� ȸ���Ǿ����ϴ�.\n");
    for (int i = 0; i < 5; i++) {
        playerPokemons[i].hp = 100; 
    }
}

void pokedex() {
    printf("===============================\n");
    printf("���ϸ� ������ Ȯ���մϴ�.\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - HP: %d, Level: %d\n", playerPokemons[i].name, playerPokemons[i].hp, playerPokemons[i].level);
    }
}

void selectPokemon() {
    int choice;
    printf("================================\n");
    printf("���ϸ��� �����ϼ���.\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - HP: %d, Level: %d\n", i + 1, playerPokemons[i].name, playerPokemons[i].hp, playerPokemons[i].level);
    }
    printf("����: ");
    scanf_s("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
        selectPokemon(); 
    }
    else {
        selectedPokemon = &playerPokemons[choice - 1];
        printf("����� %s�� �����߽��ϴ�!\n", selectedPokemon->name);
    }
}

void adventure() {
    printf("===============================\n");
    printf("������ �����մϴ�!\n");
    // �߻� ���ϸ� ���� �� �ο�� �ڵ�� �ۼ��� ���߽��ϴ�.
    printf("������ ���ƽ��ϴ�!\n");
}