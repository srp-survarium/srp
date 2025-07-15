void __usercall qsort(
        int a1@<edi>,
        char *base,
        unsigned int num,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v5; // ebx
  unsigned int v6; // edi
  char *v7; // esi
  unsigned int v8; // eax
  char *v9; // edi
  unsigned int v10; // edx
  char *v11; // eax
  int v12; // ecx
  char *v13; // eax
  unsigned int v14; // edx
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  char *v18; // edx
  char *v19; // eax
  _DWORD v20[60]; // [esp+8h] [ebp-100h]
  unsigned int v21; // [esp+F8h] [ebp-10h]
  int v22; // [esp+FCh] [ebp-Ch]
  char *v23; // [esp+100h] [ebp-8h]
  char *v24; // [esp+104h] [ebp-4h]
  char v25; // [esp+113h] [ebp+Bh]

  v5 = base;
  if ( !base && num )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, num);
    return;
  }
  v6 = width;
  if ( !width || !comp )
  {
    *_errno() = 22;
    _invalid_parameter((int)base, width, num);
    return;
  }
  if ( num >= 2 )
  {
    v7 = &base[width * (num - 1)];
    v22 = 0;
    v24 = base;
    v23 = v7;
    while ( 1 )
    {
      v8 = (v7 - v5) / v6 + 1;
      if ( v8 <= 8 )
      {
        shortsort(v7, v5, v6, comp);
        goto LABEL_49;
      }
      v9 = &v5[v6 * (v8 >> 1)];
      if ( comp(v5, v9) > 0 )
        swap(v5, v9, width);
      if ( comp(v5, v7) > 0 )
        swap(v5, v7, width);
      if ( comp(v9, v7) > 0 )
        swap(v9, v7, width);
      while ( 1 )
      {
        if ( v9 > v5 )
        {
          while ( 1 )
          {
            v5 += width;
            if ( v5 >= v9 )
              break;
            if ( comp(v5, v9) > 0 )
            {
              if ( v9 > v5 )
                goto LABEL_24;
              goto LABEL_22;
            }
          }
        }
        do
LABEL_22:
          v5 += width;
        while ( v5 <= v23 && comp(v5, v9) <= 0 );
        do
LABEL_24:
          v7 -= width;
        while ( v7 > v9 && comp(v7, v9) > 0 );
        if ( v5 > v7 )
          break;
        v10 = width;
        v11 = v7;
        if ( v5 != v7 )
        {
          v12 = v5 - v7;
          do
          {
            v21 = v10 - 1;
            v25 = v11[v12];
            v11[v12] = *v11;
            *v11 = v25;
            v10 = v21;
            ++v11;
          }
          while ( v21 );
        }
        if ( v9 == v7 )
          v9 = v5;
      }
      v7 += width;
      if ( v9 >= v7 )
        goto LABEL_36;
      do
      {
        v7 -= width;
        if ( v7 <= v9 )
          goto LABEL_36;
      }
      while ( !comp(v7, v9) );
      if ( v9 < v7 )
      {
LABEL_38:
        v13 = v24;
      }
      else
      {
LABEL_36:
        while ( 1 )
        {
          v7 -= width;
          v13 = v24;
          if ( v7 <= v24 )
            break;
          if ( comp(v7, v9) )
            goto LABEL_38;
        }
      }
      v14 = (unsigned int)v23;
      if ( v7 - v13 < v23 - v5 )
      {
        if ( v5 < v23 )
        {
          v16 = v22;
          v20[v22 + 30] = v5;
          v20[v16] = v14;
          v22 = v16 + 1;
        }
        if ( v13 >= v7 )
          goto LABEL_48;
        v5 = v24;
        v6 = width;
        v23 = v7;
      }
      else
      {
        if ( v13 < v7 )
        {
          v15 = v22;
          v20[v22 + 30] = v13;
          v20[v15] = v7;
          v22 = v15 + 1;
        }
        if ( (unsigned int)v5 >= v14 )
        {
LABEL_48:
          v6 = width;
LABEL_49:
          v17 = --v22;
          if ( v22 < 0 )
            return;
          v18 = (char *)v20[v17 + 30];
          v19 = (char *)v20[v17];
          v24 = v18;
          v23 = v19;
          v5 = v18;
          v7 = v19;
        }
        else
        {
          v7 = v23;
          v6 = width;
          v24 = v5;
        }
      }
    }
  }
}
