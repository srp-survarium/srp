char __cdecl sub_372680(int *a1)
{
  unsigned __int8 **v1; // esi
  unsigned __int8 *v2; // ebp
  unsigned __int8 *v3; // ebx
  char result; // al
  unsigned __int8 *v5; // ebp
  int v6; // edi
  unsigned __int8 *v7; // ebx
  int v8; // edi
  unsigned __int8 *v9; // ebp
  unsigned __int8 *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  int v13; // edi
  unsigned int i; // [esp+Ch] [ebp-24h]
  int v15; // [esp+14h] [ebp-1Ch]
  _BYTE v16[16]; // [esp+1Ch] [ebp-14h] BYREF

  v1 = (unsigned __int8 **)a1[6];
  v2 = v1[1];
  v3 = *v1;
  if ( !v2 )
  {
    result = ((int (__cdecl *)(int *))v1[3])(a1);
    if ( !result )
      return result;
    v3 = *v1;
    v2 = v1[1];
  }
  v5 = v2 - 1;
  v6 = *v3 << 8;
  v7 = v3 + 1;
  if ( !v5 )
  {
    if ( !((unsigned __int8 (__cdecl *)(int *))v1[3])(a1) )
      return 0;
    v7 = *v1;
    v5 = v1[1];
  }
  v8 = *v7 + v6 - 2;
  v9 = v5 - 1;
  v10 = v7 + 1;
  if ( v8 < 14 )
  {
    v15 = v8 <= 0 ? 0 : v8;
    v11 = v15;
  }
  else
  {
    v11 = 14;
    v15 = 14;
  }
  v12 = 0;
  for ( i = 0; v12 < v11; i = v12 )
  {
    if ( !v9 )
    {
      if ( !((unsigned __int8 (__cdecl *)(int *))v1[3])(a1) )
        return 0;
      v10 = *v1;
      v9 = v1[1];
      v11 = v15;
      v12 = i;
    }
    v16[v12++] = *v10;
    --v9;
    ++v10;
  }
  v13 = v8 - v11;
  if ( a1[99] == 224 )
  {
    sub_372370(v11, v13, v16, a1);
  }
  else if ( a1[99] == 238 )
  {
    sub_3725D0(v16, v11, a1, v13);
  }
  else
  {
    *(_DWORD *)(*a1 + 20) = 70;
    *(_DWORD *)(*a1 + 24) = a1[99];
    (*(void (__cdecl **)(int *))*a1)(a1);
  }
  *v1 = v10;
  v1[1] = v9;
  if ( v13 > 0 )
    (*(void (__cdecl **)(int *, int))(a1[6] + 16))(a1, v13);
  return 1;
}
