int __cdecl Camellia_set_key(unsigned int *a1, int a2, int *a3)
{
  int result; // eax
  int v4; // eax
  int *v5; // edx

  result = -1;
  if ( a1 )
  {
    if ( a3 )
    {
      result = -2;
      if ( a2 == 256 || a2 == 192 || a2 == 128 )
      {
        v4 = Camellia_Ekeygen(a2, a1, a3);
        *v5 = v4;
        return 0;
      }
    }
  }
  return result;
}
