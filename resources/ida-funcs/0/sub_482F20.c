void __fastcall sub_482F20(unsigned int a1, int (__cdecl ***a2)(_DWORD, _DWORD, _DWORD), char a3, int *a4)
{
  unsigned __int8 *v6; // ebp
  int v7; // edx
  int v8; // edi
  int i; // ebp
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int v13; // ebp
  char *v14; // eax
  int v15; // ecx
  int v16; // ecx
  int j; // eax
  int v18; // ebx
  char v19; // cl
  int v20; // edi
  unsigned __int8 *v21; // esi
  int v22; // eax
  unsigned __int8 *v23; // ebp
  int v24; // edx
  unsigned __int8 *v25; // esi
  int *v26; // edx
  int v27; // ebx
  int m; // edi
  unsigned __int8 *v29; // [esp+Ch] [ebp-528h]
  int v30; // [esp+10h] [ebp-524h]
  int k; // [esp+14h] [ebp-520h]
  int v32; // [esp+18h] [ebp-51Ch]
  _DWORD v34[258]; // [esp+24h] [ebp-510h]
  _BYTE v35[260]; // [esp+42Ch] [ebp-108h] BYREF

  if ( a1 >= 4 )
  {
    (*a2)[5] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))52;
    (*a2)[6] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))a1;
    ((void (__cdecl *)(int (__cdecl ***)(_DWORD, _DWORD, _DWORD)))**a2)(a2);
  }
  if ( a3 )
  {
    v6 = (unsigned __int8 *)a2[a1 + 40];
    v29 = v6;
  }
  else
  {
    v29 = (unsigned __int8 *)a2[a1 + 44];
    v6 = v29;
  }
  if ( !v6 )
  {
    (*a2)[5] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))52;
    (*a2)[6] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))a1;
    ((void (__cdecl *)(int (__cdecl ***)(_DWORD, _DWORD, _DWORD)))**a2)(a2);
  }
  if ( !*a4 )
    *a4 = (*a2[1])(a2, 1, 1424);
  v7 = *a4;
  *(_DWORD *)(v7 + 140) = v6;
  v30 = v7;
  v8 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v10 = v29[i];
    if ( v10 + v8 > 256 )
    {
      (*a2)[5] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))9;
      ((void (__cdecl *)(int (__cdecl ***)(_DWORD, _DWORD, _DWORD)))**a2)(a2);
      v7 = v30;
    }
    if ( v10 )
    {
      memset((int)&v35[v8], i, v10);
      v7 = v30;
      v8 += v10;
    }
  }
  v35[v8] = 0;
  v34[0] = v8;
  v11 = 0;
  v12 = 0;
  v13 = v35[0];
  if ( v35[0] )
  {
    v14 = v35;
    do
    {
      if ( *v14 == v13 )
      {
        do
        {
          v15 = (char)v35[v12 + 1];
          v34[++v12] = v11++;
        }
        while ( v15 == v13 );
      }
      if ( v11 >= 1 << v13 )
      {
        (*a2)[5] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))9;
        ((void (__cdecl *)(int (__cdecl ***)(_DWORD, _DWORD, _DWORD)))**a2)(a2);
        v7 = v30;
      }
      v14 = &v35[v12];
      v11 *= 2;
      ++v13;
    }
    while ( v35[v12] );
  }
  v16 = 0;
  for ( j = 1; j <= 16; ++j )
  {
    if ( v29[j] )
    {
      *(_DWORD *)(v7 + 4 * j + 72) = v16 - v34[v16 + 1];
      v16 += v29[j];
      *(_DWORD *)(v7 + 4 * j) = v34[v16];
    }
    else
    {
      *(_DWORD *)(v7 + 4 * j) = -1;
    }
  }
  *(_DWORD *)(v7 + 68) = 0xFFFFF;
  memset(v7 + 144, 0, 1024);
  v18 = 0;
  v19 = 7;
  v20 = 1;
  for ( k = 7; k >= 0; --k )
  {
    v21 = v29;
    v32 = 1;
    if ( v29[v20] )
    {
      v22 = 1 << v19;
      v23 = &v29[v18 + 17];
      do
      {
        v24 = v34[v18 + 1] << k;
        if ( v22 > 0 )
        {
          v25 = (unsigned __int8 *)(v24 + v30 + 1168);
          v26 = (int *)(v30 + 4 * v24 + 144);
          do
          {
            *v26 = v20;
            *v25 = *v23;
            --v22;
            ++v26;
            ++v25;
          }
          while ( v22 > 0 );
          v21 = v29;
          v22 = 1 << v19;
        }
        ++v18;
        ++v23;
        ++v32;
      }
      while ( v32 <= v21[v20] );
    }
    ++v20;
    v19 = k - 1;
  }
  if ( a3 )
  {
    v27 = v34[0];
    for ( m = 0; m < v27; ++m )
    {
      if ( v21[m + 17] > 0xFu )
      {
        (*a2)[5] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))9;
        ((void (__cdecl *)(int (__cdecl ***)(_DWORD, _DWORD, _DWORD)))**a2)(a2);
      }
    }
  }
}
