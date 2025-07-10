char __usercall sub_371ED0@<al>(_DWORD *a1@<ebx>)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // esi
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v5; // esi
  int v6; // eax
  unsigned __int8 *v7; // ebp
  int v8; // eax
  unsigned __int8 *v9; // esi
  unsigned __int8 *v10; // ebp
  bool v11; // zf
  int v12; // esi
  int v13; // edi
  int v14; // esi
  int v15; // edi
  unsigned __int16 *v16; // edx
  int v17; // edi
  int v18; // esi
  __int16 v19; // di
  unsigned __int16 v20; // di
  int v21; // eax
  unsigned __int16 *v22; // esi
  _DWORD *v23; // eax
  unsigned __int8 *v24; // [esp+Ch] [ebp-20h]
  int v25; // [esp+10h] [ebp-1Ch]
  int v26; // [esp+10h] [ebp-1Ch]
  int v27; // [esp+10h] [ebp-1Ch]
  int v28; // [esp+14h] [ebp-18h]
  int *v29; // [esp+18h] [ebp-14h]
  unsigned __int8 **v30; // [esp+1Ch] [ebp-10h]
  int v31; // [esp+20h] [ebp-Ch]
  int v32; // [esp+20h] [ebp-Ch]
  int v33; // [esp+24h] [ebp-8h]
  unsigned __int16 *v34; // [esp+28h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[6];
  v2 = v1[1];
  v3 = *v1;
  v30 = v1;
  if ( !v2 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v3 = *v1;
    v2 = v1[1];
  }
  v5 = v2 - 1;
  v6 = *v3 << 8;
  v7 = v3 + 1;
  v25 = v6;
  if ( !v5 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v5 = v1[1];
    v6 = v25;
  }
  v8 = *v7 + v6 - 2;
  v9 = v5 - 1;
  v10 = v7 + 1;
  v11 = v8 == 0;
  if ( v8 > 0 )
  {
    do
    {
      v26 = v8 - 1;
      if ( !v9 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v10 = *v1;
        v9 = v1[1];
      }
      v24 = v9 - 1;
      v12 = *v10;
      *(_DWORD *)(*a1 + 20) = 83;
      v13 = v12;
      v14 = v12 & 0xF;
      *(_DWORD *)(*a1 + 24) = v14;
      v15 = v13 >> 4;
      *(_DWORD *)(*a1 + 28) = v15;
      ++v10;
      v33 = v15;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      if ( v14 >= 4 )
      {
        *(_DWORD *)(*a1 + 20) = 32;
        *(_DWORD *)(*a1 + 24) = v14;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      if ( !a1[v14 + 36] )
        a1[v14 + 36] = jpeg_alloc_quant_table(a1);
      v16 = (unsigned __int16 *)a1[v14 + 36];
      v34 = v16;
      if ( v15 )
      {
        if ( v26 >= 128 )
        {
          v28 = 64;
          v17 = 64;
        }
        else
        {
          memset32(v16, 65537, 0x20u);
          v17 = v26 >> 1;
          v28 = v26 >> 1;
        }
      }
      else if ( v26 >= 64 )
      {
        v28 = 64;
        v17 = 64;
      }
      else
      {
        memset32(v16, 65537, 0x20u);
        v28 = v26;
        v17 = v26;
      }
      switch ( v17 )
      {
        case 4:
          v29 = (int *)&jpeg_natural_order2;
          break;
        case 9:
          v29 = (int *)&jpeg_natural_order3;
          break;
        case 16:
          v29 = (int *)&jpeg_natural_order4;
          break;
        case 25:
          v29 = (int *)&jpeg_natural_order5;
          break;
        case 36:
          v29 = (int *)&jpeg_natural_order6;
          break;
        case 49:
          v29 = (int *)&jpeg_natural_order7;
          break;
        default:
          v29 = &jpeg_natural_order;
          break;
      }
      v18 = 0;
      v31 = 0;
      if ( v17 > 0 )
      {
        do
        {
          if ( v33 )
          {
            if ( !v24 )
            {
              if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v30[3])(a1) )
                return 0;
              v10 = *v30;
              v24 = v30[1];
            }
            --v24;
            v19 = *v10++ << 8;
            if ( !v24 )
            {
              if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v30[3])(a1) )
                return 0;
              v10 = *v30;
              v18 = v31;
              v24 = v30[1];
            }
            v20 = *v10 + v19;
          }
          else
          {
            if ( !v24 )
            {
              if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v30[3])(a1) )
                return 0;
              v10 = *v30;
              v24 = v30[1];
            }
            v20 = *v10;
          }
          v21 = v29[v18];
          --v24;
          v16 = v34;
          ++v18;
          ++v10;
          v34[v21] = v20;
          v31 = v18;
        }
        while ( v18 < v28 );
        v17 = v28;
      }
      if ( *(int *)(*a1 + 104) >= 2 )
      {
        v22 = v16 + 2;
        v32 = 8;
        do
        {
          v23 = (_DWORD *)(*a1 + 24);
          *v23 = *(v22 - 2);
          v23[1] = *(v22 - 1);
          v23[2] = *v22;
          v23[3] = v22[1];
          v23[4] = v22[2];
          v23[5] = v22[3];
          v23[6] = v22[4];
          v23[7] = v22[5];
          *(_DWORD *)(*a1 + 20) = 95;
          (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 2);
          v22 += 8;
          --v32;
        }
        while ( v32 );
      }
      v27 = v26 - v17;
      if ( v33 )
        v27 -= v17;
      v8 = v27;
      v1 = v30;
      v9 = v24;
    }
    while ( v27 > 0 );
    v11 = v27 == 0;
  }
  if ( !v11 )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  *v1 = v10;
  v1[1] = v9;
  return 1;
}
