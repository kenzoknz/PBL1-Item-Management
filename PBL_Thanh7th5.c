#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
struct Infor{
 char maVatTu[100];
 char tenVatTu[100];
 char loaiVatTu[100];
 char DVT[100];
 int ngay;
 int thang;
 int soLuong;
 char NSX[100];
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
int count(Vattu vattu);
int is_empty(Vattu vattu);
void readfromKeyboard(Vattu *vattu);
void readfromFile(Vattu *vattu);
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
void sapXepPlus(Vattu *vattu, Infor infor);
void thanhTien(Vattu vattu);
double thanhTien1(Infor infor);
int checkDate(int ngay, int thang);
void xoaVatTu(Vattu *vattu, char *tenVatTu);
void xoaVatTu100(Vattu *vattu);
void destroy(Vattu *vattu);
Infor typeInfor();


int main(){	
	int choice, false_count = 0;
	char choice1, choice3, choice4, choice5;
	int sl;
	char find[100];
	
	Vattu header=NULL;
	MENU:	do{
		system("cls");
		printf("\tCHUONG TRINH QUAN LY VAT TU created by N12\n");
		printf("Moi ban nhap 1 trong cac lua chon sau day:\n");
		printf("\t1. Nhap thong tin vat tu");
		printf("\n\t2. In bang thong ke cua vat tu.");
		printf("\n\t3. Tim kiem thong tin vat tu theo yeu cau.");
		printf("\n\t4. Sap xep theo thu tu tang dan/giam dan.");
		printf("\n\t5. Xoa thong tin vat tu.");
		printf("\n\t6. Sua thong tin vat tu.");
		printf("\n\t0. Ket thuc chuong trinh.");
		printf("\nNhap lua chon: ");
        choice = getche();
		switch (choice) {
			case '1': 
			system("cls");
				printf("\nVui long chon nhap du lieu tu ban phim hoac tu file.");
				printf("\n\t1. Nhap tu ban phim");
				printf("\n\t2. Nhap tu file");
				do{
				printf("\nNhap lua chon: ");
				scanf("%d",&choice1);
				switch (choice1){
					case 1: 
					printf("Doc thong tin:");
					readfromKeyboard(&header);
					getch();
					goto MENU;
			
				case 2:
					readfromFile(&header);
					
					goto MENU;
				default: printf("\nLua chon khong hop le, vui long nhap lai.");
				}
				
				}while (1);
					
			case '2': 

			output(header);
			getch();
				break;
			case '3':
				do {
				
				system("cls");
				printf("\nMoi ban chon cach tim kiem:");
				printf("\n\t1. Tim theo ma vat tu");
				printf("\n\t2. Tim theo so luong");
				printf("\n\t3. Tim vat tu co so luong lon nhat.");
				printf("\nNhap lua chon: ");
				do{
					choice3 = getche();
					switch (choice3){
					case '1':
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
					if (false_count<3) printf("\nLua chon khong hop le, bam phim bat ki de nhap lai!\n");
					if (false_count == 3) {
						printf("\nBan da nhap sai 3 lan, chuong trinh se ve menu.\n");
						getch();
						goto MENU;
						}
					getch();
			 	}
			 			
			 	}while (1);
			 	
			 	Continue:printf("\nBan co muon tiep tuc tim kiem?\nNhan phim bat ki de tiep tuc, nhan N de huy");
			 	char tt = getche();
			 	
   				 if (tt=='N'||tt=='n') goto MENU;
			 } while (1);
			case '4':
				false_count = 0;
				printf("\nVui long chon cach sap xep:");
				printf("\n1. Sap xep so luong tang dan");
				printf("\n2. Sap xep so luong giam dan");
				do {
				printf("\nNhap lua chon:");scanf("%d",&choice4);
				switch (choice4) {
					case 1: sapXepTangDan(&header); goto MENU;
					case 2: sapXepGiamDan(&header); goto MENU;
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
				printf("\n\t1. Xoa vat tu theo ten");
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
					if (false_count<3) printf("\nLua chon khong hop le, bam phim bat ki de nhap lai!\n");
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
				output(header);
				editInfor(&header);
				getch(); break;
				
			case '0':
					printf("\nDa ket thuc chuong trinh, See you later and have a good day.");
                    exit(0);
            default: 
            false_count++;
					if (false_count<3) printf("\nLua chon khong hop le, bam phim bat ki de nhap lai!\n");
					if (false_count == 3) {
						printf("\nBan da nhap sai 3 lan, chuong trinh se tu dong thoat.\n");
						exit(1);
						}
			getch();
        }
    } while (1);
}

Vattu createNode(Infor infor){
    Vattu newNode= malloc(sizeof(struct Node));
    newNode->infor= infor;
    newNode->next= NULL;
    newNode->prev= NULL;
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
        return;
    }
    system("cls");
    printf("+------------+-------------------------------+----------------+----------------+-------+--------+----------------+------------+-------------+\n");
    printf("| Ma VT      | Ten VT                        | Loai           | DVT            | Date  | SL     | NSX            | Don gia    | Thanh tien  |\n");
    printf("+------------+-------------------------------+----------------+----------------+-------+--------+----------------+------------+-------------+\n");
    while (vattu!= NULL){
        printf("| %-10s | %-30s| %-14s | %-14s | %02d/%02d | %-6d | %-14s | %-10lld | %-11.2lf |\n", 
        vattu->infor.maVatTu, vattu->infor.tenVatTu, vattu->infor.loaiVatTu, vattu->infor.DVT, 
        vattu->infor.ngay, vattu->infor.thang, vattu->infor.soLuong, 
        vattu->infor.NSX, vattu->infor.donGia, vattu->infor.thanhTien);
        vattu = vattu->next;
    }
     printf("+------------+-------------------------------+----------------+----------------+-------+--------+----------------+------------+-------------+\n");
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
//Ham tim kiem theo so luong vat tu
void searchSL(Vattu vattu, int soLuong){
    if (vattu==NULL) {
        printf("Danh sach rong\n");
        return;
    }
    int dk=0;
    Vattu temp = NULL;
    while (vattu!=NULL){
    	
        if (vattu->infor.soLuong== soLuong) {
            dk=1;
            insertFirst(&temp,vattu->infor);
        }
        vattu= vattu->next;
        }
    if (dk==0) printf("\nKhong co vat tu can tim \n");
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
void insert(Vattu *vattu, Infor infor, int viTri){
    int cnt= count(*vattu);
    if (viTri <1 || viTri>cnt+1){
        printf("Vi tri can chen khong hop le");
        return;
    }
    Vattu newNode= createNode(infor);
    if (viTri==1) {insertFirst(*vattu, infor); return;}
    if (viTri==cnt+1) {insertBot(*vattu, infor); return;}
    Vattu temp= *vattu;
    while (temp!=NULL){
        for (int i=0; i<viTri; i++){
            temp=temp->next;
        }
    newNode->next= temp;
    temp->prev->next=newNode;
    newNode->prev= temp->prev;
    temp->prev=newNode;
    }
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
}
//Insert newNode without changing the order (Progressing)
void sapXepPlus(Vattu *vattu, Infor infor){
    Vattu newNode= createNode(infor);
    Vattu tail= *vattu; Vattu head= *vattu;
    while (tail->next!=NULL){
        tail=tail->next;
    }
    if (tail->infor.soLuong > head->infor.soLuong){
        for (Vattu i=*vattu; i->next!=NULL; i=i->next){
            if (i->infor.soLuong < newNode->infor.soLuong&& i->next->infor.soLuong > newNode->infor.soLuong){
                newNode->next= i->next;
                i->next= newNode;
                newNode->prev= i;
                i->next->prev= newNode;
                return;
            }
            i=i->next;}
    }
    if (tail->infor.soLuong<head->infor.soLuong){
        for (Vattu j=*vattu; j->next!=NULL; j=j->next ){
            if (j->infor.soLuong > newNode->infor.soLuong&& j->next->infor.soLuong < newNode->infor.soLuong){
                newNode->next= j->next;
                j->next= newNode;
                newNode->prev= j;
                j->next->prev= newNode;
                return;
            }
            j=j->next;}    
    }
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
void readfromKeyboard(Vattu *vattu){
	Infor  infor;
    getchar();
    printf("\nNhap ma vat tu: ");
    gets(infor.maVatTu);
    printf("\nNhap ten vat tu: ");
    gets(infor.tenVatTu);
    printf("\nNhap loai vat tu: ");
    gets(infor.loaiVatTu);
    printf("\nNhap DVT cua vat tu: ");
    gets(infor.DVT);
    int dk=4, toggle_stop = 1;
   printf("\nNhap ngay thang nhap cua vat tu (theo dinh dang dd/mm): ");
    do{
    
    scanf("%d%d", &infor.ngay, &infor.thang);
    if (checkDate(infor.ngay,infor.thang)) 	toggle_stop = 0;
    else {
    	dk--;
    	if (dk==0) {
    		printf("\nNhap sai qua 3 lan! Ket thuc qua trinh nhap.");
    		return;
		}
        printf("\nBan con %d lan thu", dk);
    	printf("\nNgay thang ban nhap co dinh dang khong phu hop! Vui long nhap lai: ");
    	
	}
	} while (toggle_stop);
    getchar();
    printf("\nNhap NSX: "); gets(infor.NSX);
    printf("Nhap don gia: "); 
    scanf("%lld", &infor.donGia);
    printf("Nhap so luong: "); 
    scanf("%d", &infor.soLuong);
    infor.thanhTien= thanhTien1(infor);
	printf("\nDa doc thong tin thanh cong, vui long chon cach chen thong tin:");
	int c1, k;
	printf("\n1. Chen vao dau danh sach");
	printf("\n2. Chen vao cuoi danh sach");
	printf("\n3. Chen vao vi tri ban chon");
	MENU2:printf("\nNhap lua chon: ");scanf("%d",&c1);                      
	switch (c1){    
		case 1:  insertFirst(vattu, infor); break;
		case 2:  insertBot(vattu,infor);break;
		case 3:  
			printf("Nhap vi tri: ");scanf("%d",&k);
			insert(&vattu,infor,k);break;
		default: printf("Lua chon khong hop le, Nhap lai!"); getch(); goto MENU2;
}
	printf("Da nhap du lieu thanh cong, bam phim bat ki de quay lai menu");

}
void readfromFile(Vattu *vattu) {
  FILE *file;
  int j = 0;
  char c1[100]; 
	int false_check = 0;
	printf("Khi nhap du lieu dam bao moi dong co dinh dang input:\n <ma VT>,<Ten VT>,<Loai VT>,<DVT>,<ngay>,<thang>,<So luong>,<NSX>,<Don gia>");
  do {
  	printf("\n\nLuu y: Nhap ca duoi file de chuong trinh co the nhan dang.\nVi du: example.txt");
    printf("\nMoi nhap ten file du lieu: ");
    fflush(stdin); // Xoa ki tu rac
    fgets(c1, 100, stdin);
    // Xoa xuong dong
    c1[strcspn(c1, "\n")] = '\0';
    file = fopen(c1, "r");
    if (file == NULL) {
    	false_check++;
      printf("File khong ton tai! Vui long nhap lai ten file\n");
    }
    if (false_check==3) {
    	printf("Ban da nhap sai 3 lan, chuong trinh se quay ve menu.");
    	getch();
    	return;
	}
  } while (file == NULL);
	printf("Truy cap file %s thanh cong.",c1);
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
      sscanf(token, "%d", &info.soLuong); // Read integer for soLuong
    }
    
    token = strtok(NULL, ",");
    if (token != NULL) {
      strcpy(info.NSX, token);// Read integer for soLuong
    }
    
    token = strtok(NULL, ",");
    if (token != NULL) {
      sscanf(token, "%lld", &info.donGia); // Read long long for donGia
    }
	if (checkDate(info.ngay,info.thang)){
   	info.thanhTien= thanhTien1(info);
	insertBot(vattu,info);
	count1++;
	}
	else printf("\nVat tu thu %d co dinh dang ngay khong phu hop, vui long chinh sua lai file.",count);
	
  }

  fclose(file); // Close the file after reading
  printf("\nDa doc thanh cong %d vat tu. Bam phim bat ki de quay lai menu",count1);
  getch();
}
void editInfor(Vattu *vattu) {
  char find[100];
  int found = 0, stop = 1, toggle_stop = 1, dk = 4;
 if (*vattu == NULL) return;

 do {
  printf("Nhap ma cua vat tu can sua: ");

  fgets(find, sizeof(find), stdin); // 
  

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

      printf("\nNhap thong tin moi cho vat tu:\n");

      // Prompt user for new information for each field
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


      printf("\nDa sua thong tin vat tu!\n");
      break;
    }
    temp = temp->next;
  }

  if (!found) 
    printf("Khong tim thay vat tu co ma %s\n", find);
    printf("Ban co muon tiep tuc chinh sua? \nNhap phim bat ki de tiep tuc. Nhap N de huy.\n");
    char tt = getche();
    if (tt=='N'||tt=='n') stop = 0;
    system("cls");
  } while (stop);
}
