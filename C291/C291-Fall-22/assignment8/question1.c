#include <stdio.h>

//allocate memory for all structs
//then allocate memory for pointers in function
#define invoiceitemnumber 3
typedef struct Address Address; 
struct Address {
    char * street;
    char * city;
    char * state;
    char * zip;
}; 

typedef struct Product Product; 
struct Product {
    char * name;
    double price;
};

typedef struct Item Item;
struct Item {
    Product prod;
    int quantity;
};

typedef struct Invoice Invoice;
struct Invoice {
     Item * items;
     Address address;
};


void printInvoice(Invoice invoice);
Address createAddress(char * street, char * city, char * state, char * zip);
Product createProduct(char * name, double price);
Item createLineItem(Product prod, int quantity);
Invoice createInvoice(Item * items, Address address);
void printInvoice(Invoice invoice);


Address createAddress(char * street, char * city, char * state, char * zip){
    struct Address outputaddress;
    outputaddress.street = street;
    outputaddress.city = city;
    outputaddress.state = state;
    outputaddress.zip = zip;
    return outputaddress;
    
}

Product createProduct(char * name, double price){
    struct Product outputproduct;
    outputproduct.name = name;
    outputproduct.price = price;
    return outputproduct;
}

Item createLineItem(Product prod, int quantity){
    struct Item outputitem;
    outputitem.prod = prod;
    outputitem.quantity = quantity;
    return outputitem;
}

Invoice createInvoice(Item * items, Address address){
    //creating an invoice structure
    struct Invoice outputinvoice;
    outputinvoice.items = items;
    outputinvoice.address = address;
    return outputinvoice;
}


void main(){
    Address address = createAddress("100 Main Street", "Anytown", "CA", "98765");
    Product toaster = createProduct("Toaster", 29.85);
    Product hairdryer = createProduct("Hair dryer", 24.95);
    Product carvacuum = createProduct("Car vacuum",19.98);
    Item inlinetoaster = createLineItem(toaster,3);
    Item inlinehairdryer = createLineItem(hairdryer,1);
    Item inlinecarvacuum = createLineItem(carvacuum,2);
    Item listofitems[3] = {inlinehairdryer,inlinetoaster,inlinecarvacuum};
    
    Invoice invoice = createInvoice(listofitems, address);
    printInvoice(invoice);
}

//printInvoice invoice - > prints out string. 
void printInvoice(Invoice invoice) {
    double amountdue = 0; 
    double totalprice = 0;
    puts("Sam's Small Appliances");
    printf("%s", invoice.address.street);
    printf("\n%s, %s %s", invoice.address.city, invoice.address.state, invoice.address.zip);
    //figure out how to determine size of invoice list.
    int limit = (sizeof(invoice.items)/(sizeof(invoice.items[0])));
    printf("%d",limit);
    puts("\nDescription                 Price       Qty           Total");
    for(int i = 0; i < invoiceitemnumber; i++){
        totalprice = invoice.items[i].prod.price*invoice.items[i].quantity;
        printf("\n%-10s                  %05.2f         %01d           %05.2f",invoice.items[i].prod.name,invoice.items[i].prod.price,invoice.items[i].quantity,totalprice);
        amountdue+= totalprice;
    }
    printf("\nAMOUNT DUE: %6.2f", amountdue);
}
    
    
    







