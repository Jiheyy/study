void mvBlock(table& t, crashed& c, int sy, int sx, int i) {
    int ny, nx;
    int next, prev;
    bool first = false;
    ny = 0;
    nx = 0;

    while(true) {
        ny = sy + dy[i];
        nx = sx + dx[i];

        if(ny <0 || ny>=n || nx <0 || nx >= n) break;

        if(t[ny][nx]== 0) {
            swap(t[ny][nx], t[sy][sx]); // swap!!!
            sy = ny;
            sx = nx;
            continue;
        }
        else {
            next = t[ny][nx];
            prev = t[sy][sx];
            // 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
            if(next == prev && !c[ny][nx] && !first) {
                t[ny][nx] *= 2;
                t[sy][sx] = 0;
                first = true;
                c[ny][nx] = true;
                sy = ny;
                sx = nx;
                continue;
            }
            else
                break;
        }
    }
}