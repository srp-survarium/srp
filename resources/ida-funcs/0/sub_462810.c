int __cdecl sub_462810(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-Ch]
  int j; // [esp+8h] [ebp-Ch]
  unsigned int v10; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  result = a1;
  v10 = *(_DWORD *)(a1 + 256);
  v6 = 0;
  for ( i = 24; i >= 0; i -= 8 )
  {
    v5 = (unsigned __int8)(v10 >> i);
    if ( v5 >= 65 && v5 <= 122 && (v5 <= 90 || v5 >= 97) )
    {
      *(_BYTE *)(v6 + a2) = v5;
      result = ++v6;
    }
    else
    {
      *(_BYTE *)(v6 + a2) = 91;
      v7 = v6 + 1;
      *(_BYTE *)(v7 + a2) = byte_6F1F94[(v5 & 0xF0) >> 4];
      *(_BYTE *)(++v7 + a2) = byte_6F1F94[v5 & 0xF];
      *(_BYTE *)(++v7 + a2) = 93;
      result = v7 + 1;
      v6 = v7 + 1;
    }
  }
  if ( a3 )
  {
    v4 = 0;
    *(_BYTE *)(v6 + a2) = 58;
    result = v6 + 1;
    v8 = v6 + 1;
    *(_BYTE *)(v8 + a2) = 32;
    for ( j = v8 + 1; v4 < 63; ++j )
    {
      result = v4 + a3;
      if ( !*(_BYTE *)(v4 + a3) )
        break;
      *(_BYTE *)(j + a2) = *(_BYTE *)(v4 + a3);
      result = ++v4;
    }
    *(_BYTE *)(j + a2) = 0;
  }
  else
  {
    *(_BYTE *)(v6 + a2) = 0;
  }
  return result;
}
