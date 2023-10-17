#include <stdio.h>
#include <string.h>

int count_words(char *s) 
{
    int count = 0;
    for (int i = 1; s[i] != '\0'; ++i) 
    {
        if (s[i] == ' ' && s[i + 1] != ' ' && s[i-1] != ' ')
            count++;
    }
    if (s[strlen(s)-1] == ' ')
    {
        count--;
    }
    printf("\nNumber of words in given string are: %d\n", count+1);
    return 0;
}

int palindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return 0; 
        }
        left++;
        right--;
    }
    return 1; 
}

int count_vowels(char *s) 
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; ++i) 
    {
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
        {
            count++;
        }

    }
    printf("Number of vowels in given string are: %d\n", count);
    return 0;
}

int count_punctuation(char *s) 
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; ++i) 
    {
        if (s[i]==',' || s[i]=='!' || s[i]=='-' || s[i]=='.' || s[i]==':' || s[i]==';' || s[i]=='\"' || s[i]=='\'' || s[i]=='?' || s[i]=='@' 
        || s[i]=='_' || s[i]=='(' || s[i]==')' || s[i]=='[' || s[i]==']' || s[i]=='{' || s[i]=='}' || s[i]=='#'|| s[i]=='$' || s[i]=='%' || s[i]=='^'
        || s[i]=='&' || s[i]=='*' || s[i]=='+' || s[i]=='=' || s[i]=='|' || s[i]=='>' || s[i]=='<'|| s[i]=='\\')
        {
            count++;
        }

    }
    printf("Number of punctuation in given string are: %d\n", count);
    return 0;
}

void return_uppercase(char *s) 
{
    for (int i=0; s[i] != '\0'; ++i) 
    {
        switch (s[i]) 
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                s[i] = s[i] - 32;
                break;
            default:
                break;
        }
    }
}

int main()
{
    char buffer[1000001];
    printf("Enter a string: ");
    scanf(" %10000000[^\n]", buffer);
    char* string=(char *) malloc(strlen(buffer)+1);
    strcpy(string, buffer);

    count_words(string);
    
    int result;
    result = palindrome(string);
    if (result==0)
    {
        printf("The string is not palindrome\n");
    }
    else if (result==1)
    {
        printf("The string is palindrome\n");
    }
    
    count_vowels(string);
    count_punctuation(string);

    return_uppercase(string);
    printf("Lowercase to uppercase string: %s", string);

    free(string);
    return 0;
}