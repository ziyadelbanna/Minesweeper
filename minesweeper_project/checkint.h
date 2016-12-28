void checkInt ()
{
char ch;
do {
    ch= getchar();
    if (isalpha(ch))
    {printf("Please enter a number.\n");}}
  while (!isdigit(ch));
  ungetc(ch, stdin);
}
