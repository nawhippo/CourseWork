#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* catalog = "<catalog>\n"
"<book id=\"bk101\">\n"
"<author>Gambardella, Matthew</author>\n"
"<title>XML Developer's Guide</title>\n"
"<genre>Computer</genre>\n"
"<price>44.95</price>\n"
"<publish_date>2000-10-01</publish_date>\n"
"<description>An in-depth look at creating applications\n"
"with XML.</description>\n"
"</book>\n"
"<book id=\"bk102\">\n"
"<author>Cormen, Stein</author>\n"
"<title>Introduction to Algorithm, fourth edition</title>\n"
"<genre>Computer</genre>\n"
"<price>84.49</price>\n"
"<publish_date>2022-04-05</publish_date>\n"
"<description>A comprehensive update of the leading algorithms text, with new material\n"
"on matchings in bipartite graphs, online algorithms, machine learning, and other\n"
"topics.</description>\n"
"</book>\n"
"<book id=\"bk103\">\n"
"<author>Carl Ryan</author>\n"
"<title>Python Programming for Beginners: A Crash Course</title>\n"
"<genre>Computer</genre>\n"
"<price>7.11</price>\n"
"<publish_date>2022-01-19</publish_date>\n"
"<description>The ultimate guide for beginners</description>\n"
"</book>\n"
"</catalog>";

typedef struct {
char* id;
char* author;
char* title;
char* genre;
float price;
char* publish_date;
char* description;
} book;

int main()
{
book* books = NULL;
int num_books = 0;

char* ptr = catalog;
char* start, *end;

while (1) {
start = strstr(ptr, "<book");
if (start == NULL) break;

start = strstr(start, "id=\"");
if (start == NULL) break;
start += 4;

end = strchr(start, '"');
if (end == NULL) break;

num_books++;
books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].id = malloc(len + 1);
strncpy(books[num_books-1].id, start, len);
books[num_books-1].id[len] = '\0';

ptr = end + 1;
}


while (1) {
start = strstr(ptr, "<author");
if (start == NULL) break;
start += 5;
end = strchr(start, '"');
if (end == NULL) break;

books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].author = malloc(len + 1);
strncpy(books[num_books-1].author, start, len);
books[num_books-1].author[len] = '\0';

ptr = end + 1;
}
while (2) {
start = strstr(ptr, "<title");
if (start == NULL) break;
start += 6;
end = strchr(start, '"');
if (end == NULL) break;

books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].title = malloc(len + 1);
strncpy(books[num_books-1].title, start, len);
books[num_books-1].title[len] = '\0';

ptr = end + 1;
}

while (3) {
start = strstr(ptr, "<genre");
if (start == NULL) break;
start += 6;
end = strchr(start, '"');
if (end == NULL) break;

books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].genre = malloc(len + 1);
strncpy(books[num_books-1].genre, start, len);
books[num_books-1].genre[len] = '\0';

ptr = end + 1;
}

while (4) {
start = strstr(ptr, "<genre");
if (start == NULL) break;
start += 5;
end = strchr(start, '"');
if (end == NULL) break;

books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].genre = malloc(len + 1);
strncpy(books[num_books-1].genre, start, len);
books[num_books-1].genre[len] = '\0';

ptr = end + 1;
}



while (5) {
start = strstr(ptr, "<publish_date");
if (start == NULL) break;
start += 12;
end = strchr(start, '"');
if (end == NULL) break;

books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].publish_date = malloc(len + 1);
strncpy(books[num_books-1].publish_date, start, len);
books[num_books-1].publish_date[len] = '\0';

ptr = end + 1;
}


while (6) {
start = strstr(ptr, "<description");
if (start == NULL) break;
start += 11;
end = strchr(start, '"');
if (end == NULL) break;

books = realloc(books, sizeof(book) * num_books);

int len = end - start;
books[num_books-1].description = malloc(len + 1);
strncpy(books[num_books-1].description, start, len);
books[num_books-1].description[len] = '\0';

ptr = end + 1;
}





if (num_books == 0) {
printf("No books found\n");
return 0;
}

int i;
for (i = 0; i < num_books; i++) {
printf("ID: %s\n", books[i].id);
printf("Author: %s\n", books[i].author);
printf("Title: %s\n", books[i].title);
printf("Genre: %s\n", books[i].genre);
printf("Price: %.2f\n", books[i].price);
printf("Publication Date: %s\n", books[i].publish_date);
printf("Description: %s\n", books[i].description);
printf("\n");
}

}


