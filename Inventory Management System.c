#include <stdio.h>
#include <stdlib.h>

struct product {
  char name[100];
  int code;
  int quantity;
  float price;
  int stock_level;
};

struct sales {
  int product_code;
  int quantity;
  float total_price;
};

void add_product(struct product *product) {
  printf("Enter product name: ");
  fgets(product->name, 100, stdin);
  product->name[strlen(product->name) - 1] = '\0';

  printf("Enter product code: ");
  scanf("%d", &product->code);

  printf("Enter product quantity: ");
  scanf("%d", &product->quantity);

  printf("Enter product price: ");
  scanf("%f", &product->price);

  printf("Enter product stock level: ");
  scanf("%d", &product->stock_level);
}

void add_sale(struct sales *sale) {
  printf("Enter product code: ");
  scanf("%d", &sale->product_code);

  printf("Enter quantity sold: ");
  scanf("%d", &sale->quantity);
}

void print_product(struct product product) {
  printf("Product Name: %s\n", product.name);
  printf("Product Code: %d\n", product.code);
  printf("Quantity: %d\n", product.quantity);
  printf("Price: %.2f\n", product.price);
  printf("Stock Level: %d\n", product.stock_level);
}

void print_sales(struct sales sale) {
  printf("Product Code: %d\n", sale.product_code);
  printf("Quantity Sold: %d\n", sale.quantity);
  printf("Total Price: %.2f\n", sale.total_price);
}

void print_inventory(struct product *products, int num_products) {
  for (int i = 0; i < num_products; i++) {
    print_product(products[i]);
  }
}

void print_sales_report(struct sales *sales, int num_sales) {
  float total_sales = 0.0f;
  for (int i = 0; i < num_sales; i++) {
    print_sales(sales[i]);
    total_sales += sales[i].total_price;
  }

  printf("Total Sales: %.2f\n", total_sales);
}

void manage_stock(struct product *products, int num_products) {
  int product_code;
  int quantity;

  printf("Enter product code: ");
  scanf("%d", &product_code);

  for (int i = 0; i < num_products; i++) {
    if (products[i].code == product_code) {
      printf("Enter quantity to add to stock: ");
      scanf("%d", &quantity);
      products[i].stock_level += quantity;
      break;
    }
  }
}

int main() {
  struct product products[100];
  int num_products = 0;

  while (1) {
    printf("1. Add product\n2. Add sale\n3. Print inventory\n4. Print sales report\n5. Manage stock\n6. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_product(&products[num_products++]);
        break;
      case 2:
        add_sale(&sales[num_sales++]);
        break;
      case 3:
        print_inventory(products, num_products);
        break;
      case 4:
        print_sales_report(sales, num_sales);
        break;
      case 5:
        manage_stock(products, num_products);
        break;
      case 6:
        return 0;
    }
  }
