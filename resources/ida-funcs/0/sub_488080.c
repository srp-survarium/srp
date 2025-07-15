int *__fastcall sub_488080(int a1, int a2)
{
  int v2; // esi
  int *result; // eax
  int *v4; // ecx
  int v5; // edi

  v2 = 0;
  result = 0;
  if ( a2 > 0 )
  {
    v4 = (int *)(a1 + 24);
    v5 = a2;
    do
    {
      if ( *v4 > v2 )
      {
        result = v4 - 6;
        v2 = *v4;
      }
      v4 += 8;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
