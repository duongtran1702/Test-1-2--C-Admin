#include<stdio.h>
#include<math.h>
int main(){
	printf("MENU\n1.Nhap kich co va cac phan tu cua mang\n2.In gia tri cac phan tu theo ma tran\n3.In ra phan tu nam tren bien va tinh tich\n");
	printf("4.In ra cac phan tu nam tren duong cheo chinh\n5.In ra cac phan tu nam tren duong cheo phu\n6.Sap xep duong cheo chinh tang dan\n7.Tim kiem phan tu va in ra vi tri\n");
	printf("8.Thoat\n");
	do{
		int choice;
		printf("Nhap lua chon cua ban :");
		scanf("%d",&choice);
		int row,col;
		int a[100][100];
		int b[100];
		if(choice==1){
			printf("Nhap kich co va cac phan tu cua mang\n");
			printf("Nhap vao so hang :");
			scanf("%d",&row);
			printf("Nhap vao so cot :");
			scanf("%d",&col);
			if(row<1){
				printf("So hang khong hop le!\n");
			 	continue;
			}
			if(col<1){
				printf("So cot khong hop le!\n");
			 	continue;
			}
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					printf("Nhap vao phan tu o hang %d cot %d :",i+1,j+1);
					scanf("%d",&a[i][j]);
				}
			}
		}
		else if(choice==2){
			printf("In ra cac phan tu dang quan li\n");
			printf("In mang :\n");
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					printf("%3d",a[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if(choice==3){
			printf("In ra phan tu nam tren bien va tinh tich\n");
			int multi=1;
			printf("Cac phan tu o bien :\n");
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(i==0||j==0||i==row-1||j==col-1){
						printf("%3d",a[i][j]);
						multi*=a[i][j];
					}
					else {
						printf("   ");
					}
				}
				printf("\n");
			}
			printf("\nTich cac so o bien la :%d\n",multi);
		}
		else if(choice==4){
			printf("In ra cac so nam tren duong cheo chinh\n");
			if(row!=col){
				printf("Cot va hang khac nhau --> khong co duong cheo chinh\n");
				continue;
			}
			printf("Cac phan tu nam tren duong cheo chinh la :\n");
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(j==i){
						printf("%3d",a[i][j]);
					}
					else {
						printf("    ");
					}
				}
				printf("\n");
			}		
		}
		else if(choice==5){
			printf("In ra cac so nam tren duong cheo phu\n");
			if(row!=col){
				printf("Cot va hang khac nhau --> khong co duong cheo phu\n");
				continue;
			}
			printf("Cac phan tu nam tren duong cheo phu la :\n");
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(j==row-i-1){
						printf("%3d",a[i][j]);
					}
					else {
						printf("    ");
					}
				}
				printf("\n");
			}		
		}
		else if(choice==6){
			printf("Sap xep duong cheo chinh tang dan\n");
			if(row!=col){
				printf("Cot va hang khac nhau --> khong co duong cheo chinh\n");
				continue;
			}
			for(int i=0;i<row;i++){
				b[i]=a[i][i];
			}
			for(int x=1;x<row;x++){
				int temp=b[x];
				int y=x-1;
				while(y>=0&&temp<b[y]){
					b[y+1]=b[y];
					y-=1;
				}
				b[y+1]=temp;
			}
			for(int i=0;i<row;i++){
				a[i][i]=b[i];
			}
			printf("Sap xep thanh cong duong cheo chinh\n");
		}
		else if(choice==7){
			printf("Tim kiem phan tu\n");
			printf("Nhap vao phan tu muon tim kiem :");
			int temp_row=-1;
			int temp_col=-1;
			int number;
			scanf("%d",&number);
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(a[i][j]==number){
						temp_row=i;
						temp_col=j;	
					}
				}				
			}
			if(temp_row==-1&&temp_col==-1){
				printf("Khong co phan tu nay trong mang \n");
			}
			else{
				printf("Vi tri cua %d o hang %d cot %d\n",number,temp_row,temp_col);
			}
		}
		else {
			printf("Finish!\n");
			return 0;
		}
	}while(true);	
}