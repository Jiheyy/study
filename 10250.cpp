 #include <iostream>
 using namespace std;
 int main() {
     int n;
     scanf("%d", &n);
     while(n--) {
         int h, w, no;
         scanf("%d %d %d", &h, &w, &no);

         int cur = 0;
         
         for(int i=1; i<=w; i++) 
            for(int floor=1; floor<=h; floor++)
                if(++cur == no)
                    printf("%d%02d\n", floor, i);
         
     }
 }