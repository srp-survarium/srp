int __cdecl sub_5403B0(int a1, unsigned __int8 **a2, unsigned __int8 *a3, _DWORD *a4, int a5)
{
  int result; // eax
  int v6; // [esp+0h] [ebp-14h]
  char *v7; // [esp+4h] [ebp-10h]
  int v8; // [esp+8h] [ebp-Ch]
  char v9[4]; // [esp+10h] [ebp-4h] BYREF

  result = a1;
  while ( *a2 != a3 )
  {
    result = *(char *)(a1 + 4 * **a2 + 888);
    v8 = result;
    v7 = (char *)(a1 + 4 * **a2 + 889);
    if ( result )
    {
      if ( result > a5 - *a4 )
        return result;
      ++*a2;
    }
    else
    {
      v6 = (*(int (__cdecl **)(_DWORD, unsigned __int8 *))(a1 + 368))(*(_DWORD *)(a1 + 372), *a2);
      result = XmlUtf8Encode(v6, v9);
      v8 = result;
      if ( result > a5 - *a4 )
        return result;
      v7 = v9;
      *a2 = &(*a2)[*(unsigned __int8 *)(a1 + **a2 + 76) - 3];
    }
    do
    {
      *(_BYTE *)*a4 = *v7;
      result = (int)a4;
      ++*a4;
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  return result;
}
