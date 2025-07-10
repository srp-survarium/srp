char __cdecl sub_372270(_DWORD *a1)
{
  unsigned __int8 **v2; // ebx
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned __int8 *v6; // edi
  int v7; // eax
  unsigned __int8 *v8; // esi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  unsigned __int8 *v14; // esi
  int v15; // eax
  int v16; // [esp+14h] [ebp+4h]
  int v17; // [esp+14h] [ebp+4h]
  int v18; // [esp+14h] [ebp+4h]

  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  v4 = v2[1];
  if ( !v4 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v3 = *v2;
    v4 = v2[1];
  }
  v6 = v4 - 1;
  v7 = *v3 << 8;
  v8 = v3 + 1;
  v16 = v7;
  if ( !v6 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v8 = *v2;
    v6 = v2[1];
    v7 = v16;
  }
  v9 = *v8 + v7;
  v10 = v6 - 1;
  v11 = v8 + 1;
  if ( v9 != 4 )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( !v10 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v11 = *v2;
    v10 = v2[1];
  }
  v12 = v10 - 1;
  v13 = *v11 << 8;
  v14 = v11 + 1;
  v17 = v13;
  if ( !v12 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v14 = *v2;
    v12 = v2[1];
    v13 = v17;
  }
  v15 = *v14 + v13;
  *(_DWORD *)(*a1 + 20) = 84;
  *(_DWORD *)(*a1 + 24) = v15;
  v18 = v15;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  a1[63] = v18;
  v2[1] = v12 - 1;
  *v2 = v14 + 1;
  return 1;
}
