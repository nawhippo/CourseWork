#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXITEMS 9
typedef struct Item{
    //maximum name of a product is 20 chars
    char * name;
    //maximum name of a label is two chars. 
    char * label;
    double price;
    int quantity; 
} Item;


typedef struct VendingMachine{
    double balance; 
    double sales;
    //3 rows, 3 columns
    Item* items;
} VendingMachine;

void createVendingMachine(); 
void displayvendingmachine(struct VendingMachine *machine);
void insertmoney(struct VendingMachine *machine);
void checkcurrentbalance(struct VendingMachine *machine);
void returnchange(struct VendingMachine *machine);
void checkprice(struct VendingMachine *machine);
void purchase(struct VendingMachine *machine);
void returnchange(struct VendingMachine *machine);
void addnewitemtype(struct VendingMachine *machine);
void restock(struct VendingMachine *machine);
void checkquantity(struct VendingMachine *machine);
void takedownitem(struct VendingMachine *machine);
void checktotalsales(struct VendingMachine *machine);




int main(){
    struct VendingMachine *samplemachine;
    samplemachine = malloc(sizeof(VendingMachine));
    samplemachine->items = calloc(sizeof(Item),MAXITEMS);
    samplemachine->balance = 0;
    samplemachine->sales = 0; 
    struct Item sampleitem;
    sampleitem.name = "Mr Goodbar";
    sampleitem.label = "A1";
    sampleitem.price = 30.0;
    sampleitem.quantity = 15;
    samplemachine->items[0] = sampleitem;
    struct Item sampleitem1;
    struct Item sampleitem2;
    struct Item sampleitem3;
    struct Item sampleitem4;
    struct Item sampleitem5;
    struct Item sampleitem6;
    struct Item sampleitem7;
    struct Item sampleitem8;
    struct Item sampleitem9;
    sampleitem1.label = "A2";
    sampleitem2.label = "A3";
    sampleitem3.label = "B1";
    sampleitem4.label = "B2";
    sampleitem5.label = "B3";
    sampleitem6.label = "C1";
    sampleitem7.label = "C2";
    sampleitem8.label = "C3";
    sampleitem1.name = "";
    sampleitem2.name = "";
    sampleitem3.name = "";
    sampleitem4.name = "";
    sampleitem5.name = "";
    sampleitem6.name = "";
    sampleitem7.name = "";
    sampleitem8.name = "";

    samplemachine->items[1] = sampleitem1;
    samplemachine->items[2] = sampleitem2;
    samplemachine->items[3] = sampleitem3;
    samplemachine->items[4] = sampleitem4;
    samplemachine->items[5] = sampleitem5;
    samplemachine->items[6] = sampleitem6;
    samplemachine->items[7] = sampleitem7;
    samplemachine->items[8] = sampleitem8;
    
    
    int menuchoice = 1;
    while(1){
    while(menuchoice == 1){
    int user_input = 0;
    displayvendingmachine(samplemachine);
    puts("[1] Insert Money");
    puts("[2] Check Balance");
    puts("[3] Check Price");
    puts("[4] Purchase");
    puts("[5] Return Change");
    puts("[6] Owner Menu");
    puts("[7] Quit");
    printf("Choose an Option: ");
    scanf("%d", &user_input);
    if(user_input == 1){
    insertmoney(samplemachine);
    }
    if(user_input == 2){
    checkcurrentbalance(samplemachine);
    }
    if(user_input == 3){
    checkprice(samplemachine);
    }
    if(user_input == 4){
    purchase(samplemachine); 
    }
    if(user_input == 5){
    returnchange(samplemachine);     
    }
    if(user_input == 6){
    menuchoice = 2;
    } if(user_input == 7){
        menuchoice = 0;
    }
    }
    
    while(menuchoice == 2){
    int user_input = 0;
    displayvendingmachine(samplemachine);
    puts("[1] Add a New Type of Item");
    puts("[2] Restock");
    puts("[3] Check quantity");
    puts("[4] Take Down a Type of Item");
    puts("[5] Check Total Sales");
    puts("[6] Exit Owner Menu");
    puts("[7] Quit");
    puts("Choose an Option: ");
    scanf("%d", &user_input);
    if(user_input == 1){
     addnewitemtype(samplemachine);
    }
    if(user_input == 2){
        restock(samplemachine);
    }
    if(user_input == 3){
        checkquantity(samplemachine);
    }
    if(user_input == 4){
        takedownitem(samplemachine);
    }
    if(user_input == 5){
        checktotalsales(samplemachine);
    }
    if(user_input == 6){
        menuchoice = 1;
    }
    if(user_input == 7){
        menuchoice = 0;
    }
}
break;
}
free(samplemachine->items);
free(samplemachine);
}

void displayvendingmachine(struct VendingMachine* machine){
        printf("\n");
        puts("-------------------------------------------------");
        printf("|%15s|%15s|%15s|", machine->items[0].name,machine->items[1].name,machine->items[2].name);
        printf("\n|%15s|%15s|%15s|", machine->items[0].label,machine->items[1].label,machine->items[2].label);
        puts("\n-------------------------------------------------");
        printf("|%15s|%15s|%15s|", machine->items[3].name,machine->items[4].name,machine->items[5].name);
        printf("\n|%15s|%15s|%15s|", machine->items[3].label,machine->items[4].label,machine->items[5].label);
        puts("\n-------------------------------------------------");
        printf("|%15s|%15s|%15s|", machine->items[6].name,machine->items[7].name,machine->items[8].name);
        printf("\n|%15s|%15s|%15s|", machine->items[6].label,machine->items[7].label,machine->items[8].label);
        puts("\n-------------------------------------------------");
    }


void insertmoney(struct VendingMachine* machine){
    double deposit = 0; 
    printf("Amount: ");
    scanf("%lf", &deposit);
    machine->balance+=deposit;
}

void checkcurrentbalance(struct VendingMachine* machine){
    printf("Current balance is %.2f\n", machine->balance);
}

void checkprice(struct VendingMachine* machine){
    int found = 0;
    char label[2];
    printf("\nEnter a label: ");
    scanf("%s", label);
    for(int i = 0; i < 9; i++){
        if((strcmp(machine->items[i].label, label) == 0) & (machine->items[i].price != 0)){
            printf("%.2f",machine->items[i].price);
            found = 1;
            break;
        }
    } if(found == 0){
            puts("Label couldn't be found.");
        }
    }


void purchase(struct VendingMachine* machine){
    int found = 0;
    char itemname[10];
    double itemprice;
    char label[2];
    printf("Enter label: ");
    scanf("%s",label);
    
    
    
    
    
    for(int i = 0; i < 9; i++){
        if(strcmp(machine->items[i].label, label) == 0){
            if(strcmp(machine->items[i].name, "") == 0){
                found = 1;
                puts("There is no item at this location");
            }
            if(machine->balance >= machine->items[i].price){
                printf("\n%s purchased for %.2f", machine->items[i].name, machine->items[i].price);
                machine->balance-=machine->items[i].price;
                machine->sales+=machine->items[i].price;
                found = 1;
                break;
            } else {
                puts("\nbalance is too low.");
            }
        }
    }
    if(found == 0){
        puts("Label cannot be found");
    }
}

void returnchange(struct VendingMachine* machine){
    printf("Returned %.2f",machine->balance);
    machine->balance = 0; 
}




void addnewitemtype(struct VendingMachine* machine){
    int found = 0;
    char itemname[10];
    double itemprice;
    char label[2];
    printf("Enter new item type name: ");
    scanf("%s",itemname);
    printf("Enter the price: ");
    scanf("%lf",&itemprice);
    printf("Enter the label: ");
    scanf("%s",label);
    
    for(int i = 0; i < 9; i++){
        //check to see if the label exists
        if((strcmp(machine->items[i].label, label) == 0)){
            if(strcmp(machine->items[i].name, "") == 0){
                puts("An item exists at this location already and will be overrided.");
            }
            found = 1;
            machine->items[i].name = itemname;
            machine->items[i].price = itemprice;
            printf("%s is added to the machine with price of %lf",itemname,itemprice);
            break;
    }
    }
if (found == 0){
    puts("Label cannot be found.");
}
}




void restock(struct VendingMachine* machine){
    int restockvalue = 0;
    char label[2];
    printf("label: ");
    scanf("%s",label);
    for(int i = 0; i < 9; i++){
        //check to see if the label exists
        if(strcmp(machine->items[i].label, label) == 0){
            if(strcmp(machine->items[i].name,"") == 0){
                puts("An item does not exist at this location");
            }
            printf("Quantity: ");
            scanf("%d", &restockvalue);
            machine->items[i].quantity += restockvalue;
            printf("%d %s is restocked", restockvalue, machine->items[i].name);
            break;
        }
}
}


void checkquantity(struct VendingMachine* machine){
    char label[2];
    printf("label: ");
    scanf("%s",label);
    for(int i = 0; i < 9; i++){
        //check to see if the label exists
        if(strcmp(machine->items[i].label, label) == 0){
        if(strcmp(machine->items[i].label, "") == 0){
            puts("No item exists at this location.");
        } else{
            //if an item exists.
            printf("The stock of %s is %d", machine->items[i].name, machine->items[i].quantity);
            break;
        }
}
}
}

void takedownitem(struct VendingMachine* machine){
    char *label;
    printf("label: ");
    scanf("%s",label);
    for(int i = 0; i < 9; i++){
        //check to see if the label exists
        if(strcmp(machine->items[i].label, label) == 0){
        if(strcmp(machine->items[i].label, "") == 0){
            puts("No item exists at this location.");
        } else{
            //if an item exists.
            printf("%s is taken down \n",machine->items[i].name);
            machine->items[i].price = 0;
            machine->items[i].name = "";
            machine->items[i].quantity = 0;
            break;
        }
}
}
}

void checktotalsales(struct VendingMachine* machine){
    printf("Total sales: %.2f", machine->sales);
}



















