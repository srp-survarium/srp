void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(v7, v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          --v9;
          *v10++ = v12;
        }
        while ( v9 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}
