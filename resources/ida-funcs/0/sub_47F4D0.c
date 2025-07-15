char __cdecl sub_47F4D0(_DWORD *a1)
{
  unsigned __int8 **v2; // edi
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v4; // ebx
  unsigned __int8 *v6; // ebp
  int v7; // eax
  unsigned __int8 *v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // [esp+14h] [ebp+4h]
  int v12; // [esp+14h] [ebp+4h]

  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  if ( !v3 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v4 = *v2;
    v3 = v2[1];
  }
  v6 = v3 - 1;
  v7 = *v4 << 8;
  v8 = v4 + 1;
  v11 = v7;
  if ( !v6 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v8 = *v2;
    v6 = v2[1];
    v7 = v11;
  }
  v9 = *v8;
  *(_DWORD *)(*a1 + 20) = 93;
  v10 = v7 + v9 - 2;
  *(_DWORD *)(*a1 + 24) = a1[99];
  *(_DWORD *)(*a1 + 28) = v10;
  v12 = v10;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  *v2 = v8 + 1;
  v2[1] = v6 - 1;
  if ( v12 > 0 )
    (*(void (__cdecl **)(_DWORD *, int))(a1[6] + 16))(a1, v12);
  return 1;
}
