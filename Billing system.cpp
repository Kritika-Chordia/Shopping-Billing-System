#include<iostream>
#include<fstream>
using namespace std;
class shopping{

    private:
    int pcode;//product code
    float price;
    float discount;
    string pname;//product name

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t_____________________________________\n";
    cout<<"\t\t\t                                     \n";
    cout<<"\t\t\t   Main menu of SuperMarket          \n";
    cout<<"\t\t\t                                     \n";
    cout<<"\t\t\t_____________________________________\n";
    cout<<"\t\t\t                                     \n";
    cout<<"\t\t\t| 1) Administrator   |\n";
    cout<<"\t\t\t|                    |\n";
    cout<<"\t\t\t| 2) Buyer           |\n";
    cout<<"\t\t\t|                    |\n";
    cout<<"\t\t\t| 3) Exit            |\n";
    cout<<"\t\t\t|                    |\n";
    cout<<"\n\t\t  Please Select!";
    cin>>choice;
    switch(choice){
        case 1:cout<<"\t\t\t Please Login \n";
               cout<<"\t\t\t Enter Email  \n";
               cin>>email;
               cout<<"\t\t\t Password     \n";
               cin>>password;
               if(email=="zunomi@gmail.com" && password=="zunomi@123"){
                administrator();
               }
               else{
                cout<<"Invalid email and password\n";
               }
               break;
        case 2:buyer();
                break;
        case 3:exit(0);
                break;
        case 4:menu();
                break;
        default:cout<<"Invalid choice\n";

    }
    goto m;

}
void shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|____1) Add the product______|\n";
    cout<<"\n\t\t\t|____________________________|\n";
    cout<<"\n\t\t\t|____2) Modify the product___|\n";
    cout<<"\n\t\t\t|____________________________|\n";
    cout<<"\n\t\t\t|____3) Delete the product___|\n";
    cout<<"\n\t\t\t|____________________________|\n";
    cout<<"\n\t\t\t|____4) Back to Main Menu____|\n";
    
    cout<<"\n\n\t Please enter your choice";
    cin>>choice;
    switch (choice)
    {
        case 1:add();
            break;
        case 2:edit();
            break;
        case 3:rem();
            break;
        default:
            break;
    }
    goto m;
}
void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t    Buyer       \n";
    cout<<"                      \n";
    cout<<"\t\t\t 1) Buy product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2) Go back     \n";
    cout<<"                      \n";
    cout<<"\t\t\t Enter your Choice :";
    cin>>choice;
    switch (choice)
    {
        case 1:receipt();
            break;
        case 2:menu();
            break;
        
        default:cout<<"Invalid choice\n";
    }
    goto m;
}
void shopping::add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t\t\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t\t\t Enter the name of the product";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of the product";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on product";
    cin>>discount;
    data.open("database.txt",ios::in);//will open the file in reading mode
    if(!data){
        data.open("database.txt",ios::app|ios::out);//append mode, write mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while (!data.eof())//end of file
        {//iterate over all values
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1){
            goto m;
        }
        else{
            //the token value is not increamented so the 
            //product code is unique
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            data.close();

        }
    }
    cout<<"\n\n\t\t Record Inserted !";
}
void shopping::edit(){
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile does'nt exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Enter the name of product :";
                cin>>n;
                cout<<"\n\t\t Enter the price of product :";
                cin>>p;
                cout<<"\n\t\t Enter the discount of product :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\n\t\t\t Record Edited! ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";

            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
    }
}
void shopping:: rem(){
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File does'nt exist";

    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n\tRecord can't found sorry!";
        }

    }
}
void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while (!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;
    }
    data.close();
}
void shopping:: receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float discount=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty Database";
    }
    else{
        data.close();
        list();
        cout<<"\n_________________________________\n";
        cout<<" |                                  |\n";
        cout<<"\n      Please Place the order \n";   
        cout<<" |                                  |\n";
        cout<<"\n_________________________________\n";
        do{
            m:
            cout<<"\n\n Enter the Product Code: ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate Product code. Please try again! ";
                    goto m;
                }
            }
            c++;//counter
            cout<<"\n\n Do you want to buy another product? if yes then press y else n";
            cin>>choice;
        }
        while(choice=='y');
        cout<<"\n\n\t\t\t_____________________RECEIPT________________________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\t Price\t Amount\t Amount with discount\n";
        
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while (!data.eof())
            {
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    discount=amount-(amount*discount/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<discount;
    
                }
                data>>pcode>>pname>>price>>discount;
            }
            
        }
        data.close();
    }
    cout<<"\n\n___________________________________";
    cout<<"\n Total Amount : "<<total;

}
int main(){
    shopping s;//object creation
    s.menu();
}