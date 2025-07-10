int __cdecl sub_540670(char *a1, char *a2)
{
  char v3; // [esp+2h] [ebp-2h]
  char v4; // [esp+3h] [ebp-1h]

  do
  {
    v4 = *a1++;
    v3 = *a2++;
    if ( v4 >= 97 && v4 <= 122 )
      v4 -= 32;
    if ( v3 >= 97 && v3 <= 122 )
      v3 -= 32;
    if ( v4 != v3 )
      return 0;
  }
  while ( v4 );
  return 1;
}
