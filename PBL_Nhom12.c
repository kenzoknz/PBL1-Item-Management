#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct Infor{
 char maVatTu[100], tenVatTu[100], loaiVatTu[100], DVT[100], NSX[100];
 int ngay, thang, soLuong;
 long long donGia;
 double  thanhTien;
};
typedef struct Infor Infor;
struct Node{
    Infor infor;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *Vattu;
Vattu createNode(Infor infor);

int is_empty(Vattu vattu);
void readfromKeyboard(Vattu *vattu);
void readfromFile(Vattu *vattu, char *fn);
void editInfor(Vattu *vattu);
void output(Vattu vattu);
void searchCode(Vattu vattu, char *maVatTu);
void searchSL(Vattu vattu, int soLuong);
void searchMax(Vattu vattu);
void insertFirst(Vattu *vattu, Infor infor);
void insertBot(Vattu *vattu, Infor infor);
void insert(Vattu *vattu, Infor infor, int viTri);
void sapXepTangDan(Vattu *vattu);
void sapXepGiamDan(Vattu *vattu);
void thanhTien(Vattu vattu);
double thanhTien1(Infor infor);
int checkDate(int ngay, int thang);
void xoaVatTu(Vattu *vattu, char *tenVatTu);
void xoaVatTu100(Vattu *vattu);
void destroy(Vattu *vattu);
Infor typeInfor();
void printStatistics(Vattu vattu);
void writeFile(Vattu vattu, char *fn);
int main(){	
	int choice, false_count = 0;
	char choice1, choice3, choice4, choice5;
	int sl,tt;
	char find[100], fn[100];

    char filename[100] = "input.txt";
	
	FILE *f = fopen(filename,"r");
	Vattu header=NULL;
	
	if (f!=NULL) {
	readfromFile(&header,filename);
    }
	
	MENU:	do{
		writeFile(header,filename);
		fflush(stdin); //Xoa bo nho dem, de tranh bi xung dot input truoc do
		system("cls");
		printf("\t+");
		for(int i = 0; i < 31; i++)
		printf("-");
		printf("+\n");
		printf("\t| %-30s|\n","      Nhom 12 - 23T_DT2");
		printf("\t| %-30s|\n","      Nguyen Chi Thanh");
		printf("\t| %-30s|\n","      Nguyen Ta Dinh Viet");
		printf("\t+");
		for(int i=0;i<31;i++) printf("-");printf("+\n");
		
		printf("\tCHUONG TRINH QUAN LY VAT TU\n");
		printf("Moi ban nhap 1 trong cac lua chon sau day:\n");
		printf("\t1. Nhap thong tin vat tu");
		printf("\n\t2. In danh sach vat tu.");
		printf("\n\t3. Tim kiem thong tin vat tu theo yeu cau.");
		printf("\n\t4. Sap xep theo thu tu tang dan/giam dan.");
		printf("\n\t5. Xoa thong tin vat tu.");
		printf("\n\t6. Sua thong tin vat tu.");
		printf("\n\t7. In bang thong ke vat tu.");
		printf("\n\t8. Truy cap mot file khac.");
		printf("\n\t0. Ket thuc chuong trinh.");
		if (f!=NULL ) printf("\nChuong trinh dang truy cap file: %s",filename);
		else printf("\nChuong trinh khong truy cap file nao.");
		printf("\nNhap lua chon: ");
        choice = getche();
		switch (choice) {
			case '1': 
			readfromKeyboard(&header);
			goto MENU;
			case '2': 
			output(header);
			break;
			case '3':
			if (is_empty(header)) {
			printf("\nDanh sach chua co du lieu de tim kiem!");
			getch();
			break;
			}
			else do {
				
				system("cls");
				printf("\nMoi ban chon cach tim kiem:");
				printf("\n\t1. Tim theo ma vat tu");
				printf("\n\t2. Tim theo so luong lon hon yeu cau (>=SL)");
				printf("\n\t3. Tim vat tu co so luong lon nhat.");
				printf("\nNhap lua chon: ");
				do{
					choice3 = getche();
					switch (choice3){
					case '1':
						getchar();
						printf("\nNhap ma vat tu can tim: ");
						gets(find);
						searchCode(header,find);
						getch();
			 			goto Continue;
			 		
			 		case '2':
			 			printf("\nNhap so luong: ");scanf("%d",&sl);
			 			searchSL(header, sl);
			 			getch();
			 			goto Continue;
			 		case '3':
			 			searchMax(header);
			 			getch();
			 			goto Continue;
			 		default:false_count++;
					if (false_count<3) printf("\nLua chon khong hop le, vui long nhap lai: ");
					if (false_count == 3) {
						printf("\nBan da nhap sai 3 lan, chuong trinh se ve menu.\n");
						getch();
						goto MENU;
						}
					
			 	}
			 			
			 	}while (1);
			 	
			 	Continue:printf("\nBan co muon tiep tuc tim kiem?\nNhan phim bat ki de tiep tuc, nhan N de huy");
			 	char tt = getche();
			 	
   				 if (tt=='N'||tt=='n') goto MENU;
			 } while (1);
			case '4':
				false_count = 0;
				if (is_empty(header)) {
				printf("\nDanh sach chua co du lieu de tim kiem!");
				getch();
				break;
				}
			else 
				printf("\nVui long chon cach sap xep:");
				printf("\n1. Sap xep so luong tang dan");
				printf("\n2. Sap xep so luong giam dan");
				do {
				printf("\nNhap lua chon:");scanf("%d",&choice4);
				switch (choice4) {
					case 1: 
					sapXepTangDan(&header); 
					goto MENU;
					case 2: 
					sapXepGiamDan(&header);
					 goto MENU;
					default: 
					false_count++;
					printf("\nLua chon khong hop le.");
					if (false_count == 3) {
						printf("\nBan da nhap sai 3 lan, chuong trinh se ve menu.\n");
						getch();
						goto MENU;
						}
				}
			} while (1);
				printf("\nDa sap xep theo yeu cau, bam phim bat ki de quay lai menu.");
				break; 
			case '5':
				printf("\nVui long chon yeu cau can xoa: ");
				printf("\n\t1. Xoa vat tu theo ma");
				printf("\n\t2. Xoa vat tu co so luong lon hon 100");
				printf("\n\t3. Xoa tat ca cac vat tu");
				do{
				
				false_count = 0;
				printf("\nNhap lua chon: ");
				choice5 = getche();
				switch (choice5) {
					
					case '1':
					 if (is_empty(header)) {
						printf("\nChua co du lieu vat tu. Khong the xoa.");
					 	getch();
					 	goto MENU;
					 }
					else
					{
					output(header);
					 printf("\nNhap ma vat tu: ");
					 fgets(find, sizeof(find), stdin);
					 find[strcspn(find,"\n")] = '\0';
					 xoaVatTu(&header,find);
					 printf("\nBam phim bat ki de quay ve menu.");
					 getch(); goto MENU;
					case '2': xoaVatTu100(&header); 
					printf("\nBam phim bat ki de quay ve menu.");
					getch();goto MENU;
					case '3': 
					printf("\nBan co muon xoa tat ca vat tu khong?\nNhan Y de tiep tuc, nhan phim bat ki de huy bo.\n");
					char tt = getch();
					if (tt == 'y' || tt == 'Y'){
					destroy(&header); 
					printf("Da xoa tat ca vat tu, bam phim bat ki de quay ve menu.");
					getch();
			     	}
					goto MENU;
					default:
					false_count++;
					if (false_count<3) printf("\nLua chon khong hop le, Vui long nhap lai!\n");
					if (false_count == 3) {
						printf("\nBan da nhap sai 3 lan, chuong trinh se ve menu.\n");
						getch();
						goto MENU;
						}
					getch();
					}
				}
					} while(1);
				break;
			case '6': 
				do {
				if (is_empty(header)){
					printf("\nKhong co vat tu nao.");
					getch();
					break;
				}
				output(header);
				editInfor(&header);
				writeFile(header,filename);
				printf("\nBan co muon tiep tuc chinh sua? \nNhap phim bat ki de tiep tuc. Nhap N de huy.\n");
    			char tt = getche();
   				 if (tt=='N'||tt=='n') break;
				} while(1);
				 break;
			case '7':
				printStatistics(header);
        		getch();
        		break;
        	case '8':
        		printf("\nVui long nhap ten file (Luu y nhap ca duoi file: *.txt, *.inp)\nNeu muon thoat qua trinh nhap thi go 'exit' hoac 'thoat': ");
        		fgets(fn, sizeof(fn), stdin);
        		fn[strcspn(fn, "\n")] = '\0';
        		if (strcmp(fn, "exit") == 0 || strcmp(fn, "thoat") == 0) break;
        		f = fopen(fn,"r");
        		if (f==NULL) {
				 printf("\nKhong the mo file %s",fn);
				 f = fopen(filename,"r");
				 getchar();
				}
        		else {
        			strcpy(filename,fn);
        			destroy(&header); //xoa du lieu cu trong console
        			readfromFile(&header,filename);
        			getchar();
				}
				break;
			case '0':
					printf("\nDa ket thuc chuong trinh, See you later and have a good day.");
                    exit(0);
            default: 
            false_count++;
			if (false_count<3) printf("\nLua chon khong hop le, bam phim bat ki de nhap lai!\n");
					else {
						printf("\nBan da nhap sai 3 lan, chuong trinh se tu dong thoat.\n");
						exit(1);
						}
			getch();
        }
    } while (1);
}

Vattu createNode(Infor infor){
    Vattu newNode  = malloc(sizeof(struct Node));
    newNode->infor = infor;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
int count(Vattu vattu){
    int cnt=0;
    while (vattu!=NULL){
        cnt++;
        vattu=vattu->next;
    }
    return cnt;
}
int is_empty(Vattu vattu){
	if (vattu==NULL) return 1;
	return 0;
}
//Ham xuat vat tu ra man hinh
void output(Vattu vattu){
    if (vattu==NULL) {
        printf("\nKhong co vat tu nao");
        getch();
        return;
    }
    system("cls");
    int i = 0;    
    printf("+-----+------------+-------------------------------+----------------+----------------+-------+--------+----------------+------------+-------------+\n");
    printf("| STT | Ma VT      | Ten VT                        | Loai           | DVT            | Date  | SL     | NSX            | Don gia    | Thanh tien  |\n");
    printf("+-----+------------+-------------------------------+----------------+----------------+-------+--------+----------------+------------+-------------+\n");
    while (vattu!= NULL){
        printf("|  %-3d| %-10s | %-30s| %-14s | %-14s | %02d/%02d | %-6d | %-14s | %-10lld | %-11.2lf |\n",++i, 
        vattu->infor.maVatTu, vattu->infor.tenVatTu, vattu->infor.loaiVatTu, vattu->infor.DVT, 
        vattu->infor.ngay, vattu->infor.thang, vattu->infor.soLuong, 
        vattu->infor.NSX, vattu->infor.donGia, vattu->infor.thanhTien);
        vattu = vattu->next;
    	
    }
	printf("+-----+------------+-------------------------------+----------------+----------------+-------+--------+----------------+------------+-------------+\n");
	getch();
}

//Ham tim kiem vat tu theo ma vat tu
void searchCode(Vattu vattu, char *maVatTu){
    if (vattu==NULL){
        printf("\nDanh sach rong");
        return;   
    }
    Vattu temp = NULL;
    int dk=0;
    while (vattu!= NULL){
        if (strcmp(vattu->infor.maVatTu, maVatTu)==0) {
            dk=1;
            insertFirst(&temp,vattu->infor);
    
        }
        vattu= vattu->next;
    
    }
    if (dk==0) printf("\nKhong co vat tu %s can tim \n",maVatTu);
    else output(temp);
    
}
int checkCode(Vattu *vattu, char *maVatTu) {
    Vattu current = vattu;
    while (current != NULL) {
        if (strcmp(current->infor.maVatTu, maVatTu) == 0) {
            return 1;  // Found duplicate code
        }
        current = current->next;
    }
    return 0;  // No duplicate found
}

//Ham tim kiem theo so luong vat tu
void searchSL(Vattu vattu, int soLuong){
    if (vattu==NULL) {
        printf("Danh sach rong\n");
        return;
    }
    int dk=0;
    Vattu temp = NULL;
    while (vattu!=NULL){
    	
        if (vattu->infor.soLuong >= soLuong) {
            dk=1;
            insertFirst(&temp,vattu->infor);
        }
        vattu= vattu->next;
        }
    if (dk==0) printf("\nKhong co vat tu can tim co so luong >=%d \n", soLuong);
    else output(temp);
    }
//Ham tim kiem vat tu co so luong lon nhat
void searchMax(Vattu vattu){
    if (vattu==NULL) {
        printf("Danh sach rong\n");
        
        return;
    }
    int max=0;
    Vattu temp= vattu;
    while (temp!=NULL){
        max= fmax(max, temp->infor.soLuong);
        temp=temp->next;
    }
    temp = NULL;
    while (vattu!=NULL){
        if (vattu->infor.soLuong==max){
        
            insertFirst(&temp,vattu->infor);
        }
        vattu= vattu->next;
        }
   output(temp);
}
//Ham chen dau
void insertFirst(Vattu *vattu, Infor infor){
    Vattu newNode= createNode(infor);
    newNode->next= *vattu;
    if (*vattu!=NULL){
        (*vattu)->prev= newNode;
    }
    *vattu= newNode;
}
//Ham chen cuoi
void insertBot(Vattu *vattu, Infor infor){
    Vattu newNode= createNode(infor);
    if (*vattu ==NULL) {
        *vattu= newNode;
        return;}
        Vattu temp= *vattu;
        while (temp->next!= NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev= temp;
    }
//Ham chen o vi tri bat ki
//Ham nay truoc lam bi sai, da sua lai de chay binh thuong
void insert(Vattu *vattu, Infor infor, int viTri) {
    int cnt = count(*vattu);
    
    Vattu newNode = createNode(infor);
    if (viTri == 1) {
        insertFirst(vattu, infor);
        return;
    }
    if (viTri == cnt + 1) {
        insertBot(vattu, infor);
        return;
    }
    
    Vattu temp = *vattu;
    for (int i = 1; i < viTri; i++) {
        temp = temp->next;
    }
    
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

//Ham sap xep theo thu tu tang dan
void sapXepTangDan(Vattu *vattu){
    if (*vattu == NULL) {
        printf("\nDanh sach rong\n");
        getch();
        return;}
    for (Vattu i=*vattu; i!=NULL; i=i->next){
        Vattu min= i;
        for (Vattu j=i->next; j!=NULL; j=j->next){
            if (j->infor.soLuong<min->infor.soLuong){
                min = j;
            }
        }
        if (min!=i){
            Infor temp= i->infor;
            i->infor= min->infor;
            min->infor=temp;
        }
    }
    printf("Da sap xep theo so luong tang dan.");
    getch();
}
//Ham sx theo thu tu giam dan
void sapXepGiamDan(Vattu *vattu){
   if (*vattu == NULL) {
        printf("\nDanh sach rong\n");
        getch();
        return;}
    for (Vattu i=*vattu; i!=NULL; i=i->next){
        Vattu max= i;
        for (Vattu j=i->next; j!=NULL; j=j->next){
            if (j->infor.soLuong>max->infor.soLuong){
                max = j;
            }
        }
        if (max!=i){
            Infor temp= i->infor;
            i->infor= max->infor;
            max->infor=temp;
        }
    }  
    printf("Da sap xep theo so luong giam dan.");
    getch();
}

//Ham tinh thanh tien:
double thanhTien1(Infor infor){
    if (infor.soLuong>200){
        infor.thanhTien= infor.donGia*infor.soLuong*25/100;
    }
    else if (infor.soLuong>100 &&infor.soLuong<=200){
        infor.thanhTien= infor.donGia*infor.soLuong*10/100;
    }
    else infor.thanhTien= infor.donGia*infor.soLuong;
    return infor.thanhTien;
}
void thanhTien(Vattu vattu){
    if (vattu==NULL){
        printf("Danh sach rong");
        return;}
    while (vattu!=NULL){
        thanhTien1(vattu->infor);
    vattu=vattu->next;}
}
int checkDate(int ngay, int thang){
	switch (thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (ngay<=0||ngay>31) return 0; else return 1;
		case 4:
		case 6:
		case 9:
		case 11:
			if (ngay<=0||ngay>30) return 0; else return 1;
		case 2: 
			if (ngay<=0||ngay>29) return 0; else return 1;
		
		default: return 0;
	}
}
//Ham xoa vat tu theo ma
void xoaVatTu(Vattu *vattu, char *maVatTu){
    if (*vattu==NULL) return;
    Vattu temp= *vattu;
    int dk=0;
    if (strcmp(temp->infor.maVatTu, maVatTu)==0) {
        *vattu= temp->next;
        dk = 1;
        if (vattu!=NULL){
            (*vattu)->prev= NULL;
        }
        free(temp);
        
        
    }
    while (temp!=NULL){
        if (strcmp(temp->infor.maVatTu, maVatTu)==0){
        	dk = 1;
            temp->prev->next= temp->next;
            if (temp->next!=NULL){
                temp->next->prev= temp->prev;
            }
            free(temp);
            
        }
        temp=temp->next; 
        
    }
    if (dk==0) printf("\nKhong co vat tu %s can xoa \n",maVatTu);
    else printf("\nDa xoa thanh cong vat tu co ma %s",maVatTu);
}
//Ham xoa vat tu co so luong >100
void xoaVatTu100(Vattu *vattu){
    if (*vattu==NULL){
        printf("\nDanh sach rong");
        return;
    }
    int dk=0;
    Vattu temp= *vattu;
    if (temp->infor.soLuong >100){
    	
        *vattu= temp->next;
        if (*vattu!=NULL){
            (*vattu)->prev= NULL;
        }
        free(temp);
        
    }
    while (temp!=NULL){
    	
        if (temp->infor.soLuong>100){
        	dk=1;
            temp->prev->next= temp->next;
        if (temp->next!=NULL){
            temp->next->prev=temp->prev;
            }
        free(temp);
        }
        temp=temp->next;
    }
    if (dk) printf("\nDa xoa vat tu co so luong >100. ");
	else printf("\nKhong co vat tu nao co so luong >100");
    
}
void destroy(Vattu *head)
{
    Vattu current = *head;
    Vattu *next;
    while (current != NULL)
    {
       next = current -> next;
       free(current);
       current = next;
    }
    *head = NULL;
}
void readfromKeyboard(Vattu *vattu) {
    Infor infor;
    Vattu **temp = vattu;

   fflush(stdin);
    do {
        printf("\nNhap ma vat tu: ");
        gets(infor.maVatTu);
        
        if (checkCode(*temp, infor.maVatTu)) {
            printf("\nMa vat tu ban vua nhap trung voi du lieu san co. Ban co muon ghi de? (Y/N): ");
            char choice = getche();
            if (choice == 'Y' || choice == 'y') {
                editInfor2(temp, infor.maVatTu);
                return;
            } 
            else return;
        }
        break;
    } while (1);

    printf("\nNhap ten vat tu: ");
    gets(infor.tenVatTu);
    printf("\nNhap loai vat tu: ");
    gets(infor.loaiVatTu);
    printf("\nNhap DVT cua vat tu: ");
    gets(infor.DVT);

    int dk = 4, toggle_stop = 1;
    printf("\nNhap ngay thang nhap cua vat tu (theo dinh dang dd/mm): ");
    do {
        scanf("%d%d", &infor.ngay, &infor.thang);
        if (checkDate(infor.ngay, infor.thang)) {
            toggle_stop = 0;
        } else {
            dk--;
            if (dk == 0) {
                printf("\nNhap sai qua 3 lan! Ket thuc qua trinh nhap.");
                return;
            }
            printf("\nBan con %d lan thu", dk);
            printf("\nNgay thang ban nhap co dinh dang khong phu hop! Vui long nhap lai: ");
        }
    } while (toggle_stop);

    getchar();
    printf("\nNhap NSX: ");
    gets(infor.NSX);
    printf("Nhap don gia: ");
    scanf("%lld", &infor.donGia);
    printf("Nhap so luong: ");
    scanf("%d", &infor.soLuong);
    infor.thanhTien = thanhTien1(infor);

    printf("\nDa doc thong tin thanh cong, vui long chon cach chen thong tin:");
    int c1, k;
    printf("\n1. Chen vao dau danh sach");
    printf("\n2. Chen vao cuoi danh sach");
    printf("\n3. Chen vao vi tri ban chon");
    
    MENU2: printf("\nNhap lua chon: ");
    scanf("%d", &c1);
    switch (c1) {
        case 1:
            insertFirst(vattu, infor);
            break;
        case 2:
            insertBot(vattu, infor);
            break;
        case 3:
        	output(*temp);
        	do {
            printf("Nhap vi tri: ");
            scanf("%d", &k);
            if (k>0&&k<=count(*temp)+1) break;
            else printf("Vi tri khong hop le, nhap lai!\n");
            }
            while (1); 
            insert(vattu, infor, k);
            break;
        	
        default:
            printf("Lua chon khong hop le, Nhap lai!");
            getch();
            goto MENU2;
    }
    printf("\nNhap thanh cong. Bam phim bat ki de quay lai menu.");
   
    getch();
}

void readfromFile(Vattu *vattu, char *c1) {
  char fn[101];
  strcpy(fn, c1);
  FILE *file = fopen(c1,"r");
  int j = 0;

	int count = 0, count1 = 0;
  // Doc du lieu
  while (fgets(c1, 100, file) != NULL) {
    // Xoa xuong dong
    c1[strcspn(c1, "\n")] = '\0';

    struct Infor info;
	++count;
    // Dung dau ',' de ngan cach
    // Su dung strtok de tach chuoi
    char *token = strtok(c1, ",");
    if (token != NULL) {
      strcpy(info.maVatTu, token);
    }

    token = strtok('\0', ",");
    if (token != NULL) {
      strcpy(info.tenVatTu, token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
      strcpy(info.loaiVatTu, token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
      strcpy(info.DVT, token);
    }
    
	token = strtok(NULL, ",");
    if (token != NULL) {
      sscanf(token, "%d", &info.ngay);
    }
    
    token = strtok(NULL, ",");
    if (token != NULL) {
      sscanf(token, "%d", &info.thang);
    }
    
 	token = strtok(NULL, ",");
    if (token != NULL) {
      sscanf(token, "%d", &info.soLuong); 
    }
    
    token = strtok(NULL, ",");
    if (token != NULL) {
      strcpy(info.NSX, token);
    }
    
    token = strtok(NULL, ",");
    if (token != NULL) {
      sscanf(token, "%lld", &info.donGia); 
    }
	if (checkDate(info.ngay,info.thang)){
   	info.thanhTien= thanhTien1(info);
	insertBot(vattu,info);
	count1++;
	}
	
  }

  fclose(file); // Close the file after reading
  strcpy(c1, fn);
  printf("\nDa doc thanh cong %d vat tu. Bam phim bat ki de quay lai menu",count1);
}
void editInfor(Vattu *vattu) {
  char find[100];
  int found = 0, toggle_stop = 1, dk = 4, SL;
  int ngay, thang;
 if (*vattu == NULL) return;
  
  printf("\nNhap ma cua vat tu can sua: ");

  fgets(find, sizeof(find), stdin);
  
  find[strcspn(find, "\n")] = '\0';

  Vattu temp = *vattu;
  while (temp != NULL) {
    if (strcmp(temp->infor.maVatTu, find) == 0) {
      found = 1;
      printf("Thong tin hien tai cua vat tu:\n");

      // Print current information of the item
      printf("Ma vat tu: %s\n", temp->infor.maVatTu);
      printf("Ten vat tu: %s\n", temp->infor.tenVatTu);
      printf("Loai vat tu: %s\n", temp->infor.loaiVatTu);
      printf("Don vi tinh: %s\n", temp->infor.DVT);
      printf("Ngay nhap: %d/%d\n", temp->infor.ngay, temp->infor.thang);
      printf("NSX: %s\n", temp->infor.NSX);
      printf("So luong: %d\n", temp->infor.soLuong);
      printf("Don gia: %lld\n", temp->infor.donGia);

      printf("\nMoi ban chon 1 trong cac lua chon de chinh sua:\n ");
      printf("\n1. Ten vat tu\n2. Loai vat tu\n3. Don vi tinh\n4. Ngay thang\n5. NSX\n6. So luong\n7. Don gia");
	  char choice, choice6;
	  do {
	  	printf("\nNhap lua chon: ");
	  	scanf("%d",&choice);
      // Prompt user for new information for each field
      switch (choice){
	  case 1:
	  getchar(); // xoa xuong dong
      printf("Ten vat tu moi: ");
      gets(temp->infor.tenVatTu); goto cont;
	  case 2:
	  getchar();
      printf("Loai vat tu moi: ");
      gets(temp->infor.loaiVatTu); goto cont;
      case 3:
      	getchar();
      printf("Don vi tinh moi: ");
      gets(temp->infor.DVT); goto cont;
      case 4:
      printf("Nhap ngay nhap moi (theo dinh dang dd/mm): ");
    	do{
    		ngay = temp->infor.ngay;
    		thang = temp->infor.thang;
      scanf("%d%d", &temp->infor.ngay, &temp->infor.thang);
      if (checkDate(temp->infor.ngay,temp->infor.thang)) 	toggle_stop = 0;
    	else {
    	dk--;
    	if (dk==0) {
    		printf("Nhap sai qua 3 lan! Ket thuc qua trinh nhap.");
    		temp->infor.ngay = ngay;
    		temp->infor.thang = thang;
    		return;
		}
        printf("\nBan con %d lan thu", dk);
    	printf("\nNgay thang ban nhap co dinh dang khong phu hop! Vui long nhap lai: ");
    	
	}
	} while (toggle_stop);
    goto cont;
	case 5:
	  getchar(); // xoa xuong dong
      printf("NSX moi: ");
      gets(temp->infor.NSX); goto cont;
    case 6: 
      printf("\nBan muon thay doi so luong nhu the nao?");
	  printf("\n1. Them/Giam so luong vao vat tu.");
	  printf("\n2. Nhap so luong moi.");
	  printf("\nNhap lua chon: ");
	  	scanf("%d",&choice6);
	  switch (choice6){
	  	case 1:
	  		printf("Nhap so luong muon them/giam (Neu giam thi nhap dau tru '-': )");
	  		scanf("%d",&SL);
	  		temp->infor.soLuong += SL;
	  		break;
	  	case 2:
    		  printf("So luong moi: ");
     	 	  scanf("%d", &temp->infor.soLuong);
  }
       thanhTien1(temp->infor);
      goto cont;
  
	case 7:
      printf("Don gia moi: ");
      scanf("%lld", &temp->infor.donGia);
       thanhTien1(temp->infor);
	  goto cont;
     case 0: goto cont;
    default: printf("Nhap lai."); 
      }
    
    } while (1);
     
    }
    temp = temp->next;
  }
	
 cont:
  if (!found) 
    printf("Khong tim thay vat tu co ma %s\n", find);
  else printf("\nDa sua thong tin vat tu!\n");
    
}

void editInfor2(Vattu *vattu, char *maVatTu) {
  
 int toggle_stop = 1, dk = 4;
 int ngay, thang;
 if (*vattu == NULL) return;

  Vattu temp = *vattu;
  while (temp != NULL) {
    if (strcmp(temp->infor.maVatTu, maVatTu) == 0) {
      printf("\nNhap thong tin moi cho vat tu:\n");
      fflush(stdin);
      printf("Ten vat tu moi: ");
      gets(temp->infor.tenVatTu); 
      printf("Loai vat tu moi: ");
      gets(temp->infor.loaiVatTu);
      printf("Don vi tinh moi: ");
      gets(temp->infor.DVT);
      
      printf("Nhap ngay nhap moi (theo dinh dang dd/mm): ");
    do{
      scanf("%d%d", &temp->infor.ngay, &temp->infor.thang);
      if (checkDate(temp->infor.ngay,temp->infor.thang)) 	toggle_stop = 0;
    else {
    	dk--;
    	if (dk==0) {
    		printf("Nhap sai qua 3 lan! Ket thuc qua trinh nhap.");
    		temp->infor.ngay = ngay;
    		temp->infor.thang = thang;
    		return;
		}
        printf("\nBan con %d lan thu", dk);
    	printf("\nNgay thang ban nhap co dinh dang khong phu hop! Vui long nhap lai: ");
    	
	}
	} while (toggle_stop);
      getchar(); // xoa xuong dong

      printf("NSX moi: ");
      gets(temp->infor.NSX);

      printf("So luong moi: ");
      scanf("%d", &temp->infor.soLuong);

      printf("Don gia moi: ");
      scanf("%lld", &temp->infor.donGia);

	cont:
      printf("\nDa sua thong tin vat tu!\n");
      getch();
      break;
    }
    temp = temp->next;
  }

    
}
void printStatistics(Vattu vattu) {
    if (vattu == NULL) {
        printf("\nDanh sach rong");
        return;
    }
// Khai bao so tien va so luong
    double totalPrice = 0;
    int totalAmount = 0;
    struct TypeStats {
        char loaiVatTu[100];
        int soLuong;
        double thanhTien;
    }; //Khai bao struct luu tru du lieu

    struct TypeStats stats[100]; // khai bao 
    int typeCount = 0;

    Vattu temp = vattu; 
	while (temp != NULL) { //Chung nao het list thi dung
   		 totalPrice += temp->infor.thanhTien; // tinh tong cua tat ca vat tu 
    	 totalAmount += temp->infor.soLuong;

   		int found = 0; //toggle neu nhu ton tai vat tu da co
    	for (int i = 0; i < typeCount; i++) {
        if (strcmp(stats[i].loaiVatTu, temp->infor.loaiVatTu) == 0) { //kiem tra vat tu da co trong du lieu chua
            stats[i].soLuong += temp->infor.soLuong;
            stats[i].thanhTien += temp->infor.thanhTien;
            found = 1;
            break;
        }
    	}
    if (!found) { 
        strcpy(stats[typeCount].loaiVatTu, temp->infor.loaiVatTu); //neu khong trung thi them vao stack
        stats[typeCount].soLuong = temp->infor.soLuong; 
        stats[typeCount].thanhTien = temp->infor.thanhTien;
        typeCount++;
    }
    	temp = temp->next;
}
	free(temp); //giai phong bo nho
	system("cls");
    printf("\nThong ke vat tu:\n");
    printf("+----------------+--------------+-------------+\n");
    printf("| Loai vat tu    | So luong     | Thanh tien  |\n");
    printf("+----------------+--------------+-------------+\n");
    for (int i = 0; i < typeCount; i++) {
        printf("| %-14s | %-12d | %-11.2lf |\n", stats[i].loaiVatTu, stats[i].soLuong, stats[i].thanhTien);
    }
    printf("+----------------+--------------+-------------+\n");
    printf("| Tong cong      | %-12d | %-11.2lf |\n", totalAmount, totalPrice);
    printf("+----------------+--------------+-------------+\n");
}
void writeFile(Vattu vattu, char *fn){
	FILE *fp = fopen(fn,"w");
	while (vattu!= NULL){
        fprintf(fp,"%s,%s,%s,%s,%02d,%02d,%d,%s,%lld\n", 
        vattu->infor.maVatTu, vattu->infor.tenVatTu, vattu->infor.loaiVatTu, vattu->infor.DVT, 
        vattu->infor.ngay, vattu->infor.thang, vattu->infor.soLuong, 
        vattu->infor.NSX, vattu->infor.donGia);
        vattu = vattu->next;
    }
	fclose(fp);
}