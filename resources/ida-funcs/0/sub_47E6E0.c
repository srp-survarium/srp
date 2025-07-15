char __usercall sub_47E6E0@<al>(_DWORD *a1@<esi>)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // ebx
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v5; // ebx
  int v6; // eax
  unsigned __int8 *v7; // ebp
  int v8; // eax
  unsigned __int8 *v9; // ebx
  unsigned __int8 *v10; // ebp
  bool v11; // zf
  int v12; // edi
  unsigned __int8 *v13; // ebx
  unsigned __int8 *v14; // ebp
  int v15; // ebx
  unsigned __int8 *v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+10h] [ebp-8h]
  unsigned __int8 **v19; // [esp+14h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[6];
  v2 = v1[1];
  v3 = *v1;
  v19 = v1;
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
  v17 = v6;
  if ( !v5 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v5 = v1[1];
    v6 = v17;
  }
  v8 = *v7 + v6 - 2;
  v9 = v5 - 1;
  v10 = v7 + 1;
  v18 = v8;
  v11 = v8 == 0;
  if ( v8 > 0 )
  {
    do
    {
      if ( !v9 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
          return 0;
        v10 = *v1;
        v9 = v1[1];
      }
      v12 = *v10;
      v13 = v9 - 1;
      v14 = v10 + 1;
      if ( !v13 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v19[3])(a1) )
          return 0;
        v14 = *v19;
        v13 = v19[1];
      }
      v18 -= 2;
      v16 = v13 - 1;
      v15 = *v14;
      *(_DWORD *)(*a1 + 20) = 81;
      *(_DWORD *)(*a1 + 24) = v12;
      *(_DWORD *)(*a1 + 28) = v15;
      v10 = v14 + 1;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      if ( v12 >= 32 )
      {
        *(_DWORD *)(*a1 + 20) = 29;
        *(_DWORD *)(*a1 + 24) = v12;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      if ( v12 < 16 )
      {
        *((_BYTE *)a1 + v12 + 203) = v15 & 0xF;
        *((_BYTE *)a1 + v12 + 219) = v15 >> 4;
        if ( (unsigned __int8)(v15 & 0xF) > (unsigned __int8)(v15 >> 4) )
        {
          *(_DWORD *)(*a1 + 20) = 30;
          *(_DWORD *)(*a1 + 24) = v15;
          (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        }
      }
      else
      {
        *((_BYTE *)a1 + v12 + 219) = v15;
      }
      v9 = v16;
      v1 = v19;
    }
    while ( v18 > 0 );
    v11 = v18 == 0;
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
