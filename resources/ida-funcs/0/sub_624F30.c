_BYTE *__cdecl sub_624F30(_BYTE *a1, _BYTE *a2, unsigned int a3)
{
  _BYTE *v4; // [esp+0h] [ebp-Ch]
  _BYTE *v5; // [esp+0h] [ebp-Ch]
  _BYTE *v6; // [esp+4h] [ebp-8h]
  _BYTE *v7; // [esp+4h] [ebp-8h]
  unsigned int j; // [esp+8h] [ebp-4h]
  unsigned int i; // [esp+8h] [ebp-4h]

  v6 = a1;
  v4 = a2;
  if ( a1 <= a2 )
  {
    for ( i = 0; i < a3; ++i )
      *v6++ = *v4++;
    return &v6[-a3];
  }
  else
  {
    v7 = &a1[a3];
    v5 = &a2[a3];
    for ( j = 0; j < a3; ++j )
      *--v7 = *--v5;
    return v7;
  }
}
