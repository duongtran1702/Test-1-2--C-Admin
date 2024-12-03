#include<stdio.h>
#include<math.h>
int main(){
	printf("MENU\n1.Nhap so phan tu va gia tri cac phan tu\n2.In gia tri cac phan tu\n3.In ra gia tri lon nhat cua mang\n");
	printf("4.In ra cac phan tu la so nguyen to\n5.Them mot phan tu\n6.Xoa mot phan tu\n7.Sap xep mang tang dan\n8.Tim kiem phan tu va in ra vi tri\n");
	printf("9.Thoat\n");
	do{
		int choice;
		printf("Nhap lua chon cua ban :");
		scanf("%d",&choice);
		int n;
		int a[100];
		if(choice==1){
			printf("Nhap so phan tu va nhap phan tu\n");
			printf("Nhap vao so phan tu :");
			scanf("%d",&n);
			if(n<1){
				printf("So phan tu khong hop le!\n");
			 	continue;
			}
			for(int i=0;i<n;i++){
				printf("Nhap vao phan tu thu %d :",i+1);
				scanf("%d",&a[i]);
			}
		}
		else if(choice==2){
			printf("In ra cac phan tu dang quan li\n");
			printf("In mang :");
			for(int i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
		}
		else if(choice==3){
			printf("In ra phan tu lon nhat cua mang\n");
			int max=a[0];
			for(int i=0;i<n;i++){
				if(a[i]>max){
					max=a[i];
				}
			}
			printf("Phan tu lon nhat cua mang la :%d\n",max);
		}
		else if(choice==4){
			printf("In ra cac phan tu la so nguyen to\n");
			printf("Cac phan tu la so nguyen to trong mang la :");
			int prime;
			int index=0;
			for(int i=0;i<n;i++){
				prime=0;
				if(a[i]>1){
					for(int x=2;x<=sqrt(a[i]);x++){
						if(a[i]%x==0){
							prime+=1;
						}
					}
					if(prime==0){
						index+=1;
						printf("%d ",a[i]);
					}
				}
			}
			if(index==0){
				printf("\nKhong co so ngguyen to nao!");
			}		    	
			printf("\n");		
		}
		else if(choice==5){
			printf("Them mot phan tu\n");
			printf("Nhap vao vi tri(0-%d) :",n+1);
			int pos;
			scanf("%d",&pos);
			if(pos==0){
				pos=1;
			}
			if(pos<1||pos>n+1){
				printf("Vi tri khong hop le !\n");
				continue;
			}
			printf("Nhap vao gia tri :");
			int value;
			scanf("%d",&value);
			for(int i=n;i>=pos;i--){
				a[i]=a[i-1];
			}
			a[pos-1]=value;
			n+=1;
			printf("Them thanh cong\n");
		}
		else if(choice==6){
			printf("Xoa phan tu trong mang\n");
			printf("Nhap vao vi tri muon xoa(1-%d) :",n);
			int pos;
			scanf("%d",&pos);
			if(pos<1||pos>n){
				printf("Vi tri khong hop le!\n");
				continue;
			}
			for(int i=pos-1;i<n;i++){
				a[i]=a[i+1];
			}
			printf("Xoa phan tu thanh cong\n");
			n-=1;
		}
		else if(choice==7){
			printf("Sap xep cac phan tu tang dan\n");
			int min;
			for(int i=0;i<n-1;i++){
				min=i;
				for(int j=i+1;j<n;j++){
					if(a[min]>a[j]){
						min=j;
					}
				}
				int temp=a[min];
				a[min]=a[i];
				a[i]=temp;
			}
			printf("Sap xep mang thanh cong!\n");
		}
		else if(choice==8){
			printf("Tim kiem phan tu\n");
			printf("Nhap vao phan tu muon tim kiem :");
			int pos=-1;
			int number;
			scanf("%d",&number);
			for(int i=0;i<n;i++){
				if(a[i]==number){
					pos=i;
				}
			}
			if(pos==-1){
				printf("Khong tim thay phan tu ban nhap !\n");
			}
			else{
				printf("Vi tri cua %d trong mang la :%d\n",number,pos);
			}
		}
		else {
			printf("Finish!\n");
			return 0;
		}
	}while(true);	
}
