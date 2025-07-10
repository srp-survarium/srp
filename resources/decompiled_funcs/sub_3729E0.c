char __cdecl sub_3729E0(_DWORD *a1)
{
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v6; // ecx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  int v12; // [esp+14h] [ebp+4h]
  int v13; // [esp+14h] [ebp+4h]

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
  v6 = *v3;
  v7 = v4 - 1;
  v8 = v3 + 1;
  v12 = v6;
  if ( !v7 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v8 = *v2;
    v7 = v2[1];
    v6 = v12;
  }
  v9 = *v8;
  v10 = v7 - 1;
  v11 = v8 + 1;
  v13 = v9;
  if ( v6 != 255 || v9 != 216 )
  {
    *(_DWORD *)(*a1 + 20) = 55;
    *(_DWORD *)(*a1 + 24) = v6;
    *(_DWORD *)(*a1 + 28) = v9;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    v9 = v13;
  }
  a1[99] = v9;
  v2[1] = v10;
  *v2 = v11;
  return 1;
}
