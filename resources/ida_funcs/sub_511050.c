int __cdecl sub_511050(char *first, unsigned int count)
{
  char *last; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  last = "alpha";
  for ( i = 0; byte_8881B4[i]; ++i )
  {
    if ( count == (unsigned __int8)byte_8881B4[i] && !strncmp(first, last, count) )
      return i;
    last += (unsigned __int8)byte_8881B4[i] + 1;
  }
  return -1;
}
