    #include <stdio.h>     
    #include <conio.h>     
    #include <stdlib.h>     
    #include <math.h>     
    #include <string.h>
     
    long int p,q,n,t,control,e[100],d[100],son[100],j,dnctext[100],enctext[100],i;
     
    char msg[100];
     
     int AsalSay(long int sayi) {     
    	int i;     
    	j=sqrt(sayi);
     
    	for (i=2;i<=j;i++) {     
    		if(sayi%i==0)
     			return 0;     
    	}     
    	return 1;     
    }
     
    void OklitAlg() {
     
    	int k;     
    	k=0;
     
    	for (i=2;i<t;i++) {     
    		if(t%i==0)
              continue;     
    		control=AsalSay(i);     
    		if(control==1&&i!=p&&i!=q) {     
    			e[k]=i;     
    			control=Dec(e[k]);
				 printf("%d\t",control);    
    			if(control>0) {     
    				d[k]=control;     
    				k++;
				     
    			}     
    			if(k==99)
                	break;     
    		}     
    	}     
    }
     
    int Dec(int x) {
     
    	long int k=1;     
    	while(1) {     
    		k=k+t; 
			//printf("%d",k) ;   
    		if(k%x==0)     
    			return(k/x);     
    	}     
    }
     
    void encrypt() {
     
    	long int pt,ct,key=e[0],k,len;     
    	i=0;     
    	len=strlen(msg);
     
    	while(i!=len) {
     
    		pt=dnctext[i];     
    		pt=pt-96;     
    		k=1;
     
    		for (j=0;j<key;j++) {     
    			k=k*pt;     
    			k=k%n;
				//printf("%d",k);	     
    		}     
    		son[i]=k;     
    		ct=k+96;     
    		enctext[i]=ct;
    		//printf("%c",enctext[i]);			     
    		i++;     
    	}     
    	enctext[i]=-1;     
    	printf("\n-Sifrelenmis Mesaj(Encrypt text):");
     
    	for (i=0;enctext[i]!=-1;i++)     
    	{
			printf("%c",enctext[i]);
    	
    		}
    	printf("\n");
    	for (i=0;enctext[i]!=-1;i++)     
    	{
    		printf("%ld,",enctext[i]);
    		}
    	printf("\n");
     
    }
     
    void decrypt() {     
    	long int pt,ct,key=d[0],k;     
    	i=0;
     
    	while(enctext[i]!=-1) {
     
    		ct=son[i];     
    		k=1;
     
    		for (j=0;j<key;j++) {     
    			k=k*ct;     
    			k=k%n;
     
    		}
      		pt=k+96;     
    		dnctext[i]=pt;     
    		i++;     
    	}
     
    	dnctext[i]=-1;     
    	printf("\n-Cozulen Mesaj(Decrypt):");
     
    	for (i=0;dnctext[i]!=-1;i++)     
    		printf("%c",dnctext[i]);    	
    	printf("\n");
     
    }
     
    void main() {
     
     
    	printf("\nAsal Sayi giriniz:(Enter Prime number):");     
    	scanf("%d",&p);     
    	control=AsalSay(p);
     
    	if(control==0) {
     
    		printf("\nSayi Asal degil-Not Prime Num.\n");     
    		getch(); 
			exit(1);
			//return 0;        	
     
    	}
     
    	printf("\nAsal Sayi giriniz:(Enter Prime number):");     
    	scanf("%d",&q);     
    	control=AsalSay(q);
     
    	if(control==0||p==q) {
     
    		printf("\nSayi Asal degil-Not Prime Num.\n");     
    		getch(); 
			//return 0;
			exit(1);       
    	
    	}     
    	printf("\nMesaji giriniz(Enter Text Message):\n");     
    	fflush(stdin);//set string mesaj     
    	scanf("%s",msg);
     
    	for (i=0;msg[i]!='\0';i++)     
    		dnctext[i]=msg[i];    
    	
		n=p*q;     
    	t=(p-1)*(q-1);
		printf("%d ",t);  
		OklitAlg();     
    	printf("\nEncrypt-Asal\tDecrypt-Asal\n");
     
    	for (i=0;i<j-1;i++)     
    		printf("\n%ld\t\t\t%ld",e[i],d[i]);     
    	encrypt();     
    	decrypt();
     
    	getch();
     
    }
     
   
     
   
     
   
     
   
     

     
