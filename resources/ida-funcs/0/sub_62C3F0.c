int __cdecl sub_62C3F0(char *first, unsigned int count)
{
  char *last; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  last = "alpha";
  for ( i = 0; byte_72BC2C[i]; ++i )
  {
    if ( count == (unsigned __int8)byte_72BC2C[i] && !strncmp(first, last, count) )
      return i;
    last += (unsigned __int8)byte_72BC2C[i] + 1;
  }
  return -1;
}
