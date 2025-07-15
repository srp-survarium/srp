int *__fastcall sub_37B390(int a1, int a2)
{
  int v2; // esi
  int *result; // eax
  int *v4; // ecx
  int v5; // edi

  v2 = 0;
  result = 0;
  if ( a2 > 0 )
  {
    v4 = (int *)(a1 + 28);
    v5 = a2;
    do
    {
      if ( *v4 > v2 && *(v4 - 1) > 0 )
      {
        result = v4 - 7;
        v2 = *v4;
      }
      v4 += 8;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
