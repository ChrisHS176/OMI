#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimización para lectura y escritura rápida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    if (!(cin >> n >> t)) return 0;

    // Vector de diferencias de tamaño n + 2 para manejar índices de 1 a n
    vector<int> diff(n + 2, 0);

    // Leer cada rociada y actualizar los límites en el arreglo de diferencias
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    // Calcular las alturas finales usando sumas acumuladas
    int current_height = 0;
    for (int i = 1; i <= n; i++) {
        current_height += diff[i];
        cout << current_height << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}