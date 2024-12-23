# > string in C

- string in c is character array and its last character is special character which is `null terminator '\0'`.it siginifies the end of string.
- null terminator is non printable. if u try to print it u will get `""` empty.

### Initialisation of string

```c
char test[5];
test[0] = 't';
test[1] = 'e';
test[2] = 's';
test[3] = 't';
test[4] = '\0'; // null terminator

// or

char test[5] = "test"; // compiler will add null terminator for us

// or

char test[] = "test"; // even you no need to mention the size of it 

```
---

# > `string.h` library
- string.h has functions to handle/manipulate the strings.

## 1. `strcmp()`

  - this function to compare two string literals and return integer value.
  
###  this is how u should not compare 
```c
char s1[] = "This is one string";
char s2[] = "This is one string";

/**
* This is "not the right way" to compare strings becoz here instead of checking each character in string address of both arrays are compared. this will always returns false. becoz, two different arrays locations also different.
*/
if (s1 == s2 )
  printf("strings are equal\n");
else 
  printf("strings are not equal\n");

```

### this is how u should compare

```c

//  s1 = "This is one string"  s2 = "This is one string";
if (strcmp(s1,s2) == 0 )  
{
 printf("strings are equal\n");
}

//  s1 = "Thia is one string"  s2 = "This is one string";
else if (strcmp(s1,s2) < 0)  
{
 printf("s1 < s2\n");
}

//  s1 = "This is one string"  s2 = "Thia is one string";
else if (strcmp(s1,s2) > 0)
{
 printf("s1 > s2\n");
}

```
  - returns ` == 0 ` strings are matched

  - returns ` < 0 ` if the 1st non-matching char has lower ascii value in s1 than s2.

  - returns ` > 0 ` if the 1st non-matching char has higher ascii value in s1 than s2.
  
## 2. `strcpy()` and `strncpy()`

- this function is to copy string char array to destination from the source.

```c

// source char array string (automatically puts 10th element as null terminator)
char src[10] = "123456789";

// 1. dest1 size > src size (strcpy)
char dest1[50];

strcpy(dest1,src);
printf("dest1: %s\n",dest1); // output = 123456789

// 2. dest2 size < src size (strcpy)
char dest2[5];

strcpy(dest2,src);
printf("dest2: %s\n",dest2); // Error 

// 3. dest3 size > src size (strncpy)
char dest3[50];

strncpy(dest3,src,10);
printf("dest3: %s\n",dest3); // output = 123456789

// 4. dest4 size < src size (strncpy)
char dest4[5];

strncpy(dest4,src,10);
printf("dest4: %s\n",dest4); // Error 

// 5. dest5 size > src size (strncpy) && n > src size
char dest5[50];

strncpy(dest5,src,40);
printf("dest5: %s\n",dest5); // output = 123456789

// 6. dest6 size < src size (strncpy) && n < src size
char dest6[5];

strncpy(dest6,src,2);
printf("dest6: %s\n",dest6); // output = 12@ef (because no null terminator)

// add null terminator then its fine
dest6[2] = '\0';
printf("dest6: %s\n",dest6); // output = 12


```

## 3. `strstr()` 

- this function finds the first occurence of one string in another string.

```c

char begin[] = "This is the way.";

char need[] = "the";

// it will search the second string in first string and returns the first occurence substring pointer

char *the = strstr(begin,need);

printf("the: %s\n",the);  // output ->  the: the way.

// if the second string not exist in first string it will return NULL 

char now[] = "now";

char *nowptr = strstr(begin,now);

if(nowptr == NULL)
printf("failed to find string\n");  // output ->  failed to find string

```