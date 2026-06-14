#include "raylib.h"
#include "example.hpp"

int main() {
    // Inizializza la finestra
    InitWindow(800, 600, "Esempio di Disegno");

    // Imposta il frame rate
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 posizione = {400, 300};
        float raggio = 50;
        Color colore = RED;
        DisegnaCerchioPulsante(posizione, raggio, colore);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}