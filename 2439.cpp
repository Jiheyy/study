#include <iostream>
using namespace std;

int main() {
    int x, y, ny, nx;
    cin >> y >> x >> ny >> nx;
    int close = 987654321;
    close = min(x, close);
    close = min(y, close);
    close = min(ny-y, close);
    close = min(nx-x, close);

    printf("%d\n", close);
}