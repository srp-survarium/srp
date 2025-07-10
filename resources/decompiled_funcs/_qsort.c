void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // ebx
  unsigned int v5; // edi
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // edi
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  char *v12; // eax
  char *v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  char *v17; // edx
  char *v18; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v21; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( !base && num )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return;
  }
  v5 = width;
  if ( !width || !comp )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(v6, v4, v5, comp);
        goto LABEL_49;
      }
      v8 = &v4[v5 * (v7 >> 1)];
      if ( comp(v4, v8) > 0 )
        swap(v4, v8, width);
      if ( comp(v4, v6) > 0 )
        swap(v4, v6, width);
      if ( comp(v8, v6) > 0 )
        swap(v8, v6, width);
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(v4, v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_24;
              goto LABEL_22;
            }
          }
        }
        do
LABEL_22:
          v4 += width;
        while ( v4 <= hi && comp(v4, v8) <= 0 );
        do
LABEL_24:
          v6 -= width;
        while ( v6 > v8 && comp(v6, v8) > 0 );
        if ( v4 > v6 )
          break;
        v9 = width;
        v10 = v6;
        if ( v4 != v6 )
        {
          v11 = v4 - v6;
          do
          {
            v21 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v21;
            ++v10;
          }
          while ( v21 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_36;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_36;
      }
      while ( !comp(v6, v8) );
      if ( v8 < v6 )
      {
LABEL_38:
        v12 = lo;
      }
      else
      {
LABEL_36:
        while ( 1 )
        {
          v6 -= width;
          v12 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(v6, v8) )
            goto LABEL_38;
        }
      }
      v13 = hi;
      if ( v6 - v12 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v15 = stkptr;
          lostk[stkptr] = v4;
          histk[v15] = v13;
          stkptr = v15 + 1;
        }
        if ( v12 >= v6 )
          goto LABEL_48;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v12 < v6 )
        {
          v14 = stkptr;
          lostk[stkptr] = v12;
          histk[v14] = v6;
          stkptr = v14 + 1;
        }
        if ( v4 >= v13 )
        {
LABEL_48:
          v5 = width;
LABEL_49:
          v16 = --stkptr;
          if ( stkptr < 0 )
            return;
          v17 = lostk[v16];
          v18 = histk[v16];
          lo = v17;
          hi = v18;
          v4 = v17;
          v6 = v18;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}
