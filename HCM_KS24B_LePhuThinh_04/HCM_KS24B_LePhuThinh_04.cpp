#include <stdio.h>
int main() {
    int arrayInt[100], currentSize = 0;
    while (true) {
        printf("\n\n%20s", "MENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao co trong mang\n");
        printf("4. Tim gia tri lon thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien trong mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu tang dan (Insertion sort)\n");
        printf("8. Nhap phan tu, tim kiem phan tu co ton tai trong mang khong\n");
        printf("9. Sap xep lai mang va hien thi toan bo phan tu trong mang: chan truoc, le sau\n");
        printf("10. Dao nguoc thu tu cua cac phan tu trong mang\n");
        int choose;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choose);
        switch (choose){
            case 1: {
                int n;
                printf("Nhap so phan tu cho mang (max: 100): ");
                scanf("%d", &n);
                if (n < 0) {
                    n = 0;
                }else if (n > 100) {
                    n = 100;
                }
                currentSize = n;
                for (int i = 0; i < currentSize; i++) {
                    printf("arrayInt[%d] = ", i);
                    scanf("%d", &arrayInt[i]);
                }
                break;
            }
            case 2: {
                for (int i = 0; i < currentSize; i++) {
                    if (i != currentSize-1) {
                        printf("arrrayInt[%d] = %d, ", i, arrayInt[i]);
                    }else {
                        printf("arrrayInt[%d] = %d", i, arrayInt[i]);
                    }
                }
                break;
            }
            case 3: {
                int count = 0;
                for (int i = 0; i < currentSize; i++) {
                    int sum = 0;
                    for (int j = 1; j < arrayInt[i]; j++) {
                        if (arrayInt[i] % j == 0) {
                            sum += j; 
                        }
                    }
                    if (sum == arrayInt[i]) {
                        count++;
                    }
                }
                printf("Co %d so hoan hao trong mang", count);
                break;
            }
            case 4: {
                int max = 0, res;
                for (int i = 0; i < currentSize; i++){
                    if (arrayInt[i] > arrayInt[max]) {
                        max = i;
                    }
                }
            }
            case 5: {
                int n, newValue;
                printf("Nhap vi tri muon them vao mang: ");
                scanf("%d", &n);
                if (n < 0) {
                    n = 0;
                }else if (n > currentSize) {
                    if (n > 100) {
                        currentSize = n = 100;
                    }else {
                        currentSize = n;
                    }
                }
                printf("Nhap gia tri muon them vao vi tri %d: ", n);
                scanf("%d", &newValue);
                if (n < currentSize) {
                    for (int i = currentSize; i >= n; i--) {
                        arrayInt[i] = arrayInt[i-1];
                    }
                }
                currentSize++;
                arrayInt[n] = newValue;
            }
            case 6: {
                int n;
                printf("Nhap vi tri ban muon xoa: ");
                scanf("%d", &n);
                if (n < 0 || n > 100) {
                    printf("Vi tri nhap khong hop le");
                    return 0;
                }
                for (int i = n; i < currentSize-1; i++) {
                    arrayInt[i] = arrayInt[i+1];
                }
                currentSize--;
            }
            case 7: {
                for (int i = 1; i < currentSize; i++) {
                    int key = arrayInt[i];
                    int j = i - 1;
                    while (j >= 0 && arrayInt[j] > key) {
                        arrayInt[j +1] = arrayInt[j];
                        j --;
                    }
                    arrayInt[j + 1] = key;
                    break;
                }
                case 8: {
                    int n;
                    printf("Nhap gia tri ban muon tim kiem: ");
                    scanf("%d", &n);
                    int l = 0, r = currentSize - 1;
                    int check = 0;
                    while (l <= r) {
                        int m = l+(r-l)/2;
                        if (arrayInt[m] == n) {
                            printf("Gia tri %d o vi tri %d\n", n, m);
                            check = 1;
                            break;
                        } else if (arrayInt[m] < n) {
                            l = m + 1;
                        } else {
                            r = m - 1;
                        }
                    }
                    if (check==0) {
                        printf("Gia tri %d khong ton tai trong mang\n", n);
                    }
                    break;
                }
                case 9: {
                    int num = 0;
                    for (int i = 0; i < currentSize; i++) {
                        if (arrayInt[i] % 2 == 0) {
                            int temp = arrayInt[num];
                            arrayInt[num] = arrayInt[i];
                            arrayInt[i] = temp;
                        }

                        
                    }
                    break;
                }

                    break;
                }
                case 10: {
                    for (int i = 0; i < currentSize/2; i++) {
                        int temp = arrayInt[i];
                        arrayInt[i] = arrayInt[currentSize - 1 - i];
                        arrayInt[currentSize-1-i] = temp;
                    }
                    break;
                }
                default: {
                printf("Lua chon cua ban khong hop le");
                break;
        }
    }
    return 0;
}
