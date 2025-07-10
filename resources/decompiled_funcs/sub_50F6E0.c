BOOL __cdecl sub_50F6E0(unsigned __int8 *a1)
{
  int v1; // edx
  int v3; // edx
  int v4; // edx
  _BYTE *v5; // [esp+8h] [ebp+8h]
  _BYTE *v6; // [esp+8h] [ebp+8h]
  unsigned __int8 *v7; // [esp+8h] [ebp+8h]

  v1 = byte_888D30[*a1] & 4;
  v5 = a1 + 1;
  if ( !v1 )
    return 0;
  while ( (byte_888D30[(unsigned __int8)*v5] & 4) != 0 )
    ++v5;
  if ( *v5 == 125 )
    return 1;
  v3 = (unsigned __int8)*v5;
  v6 = v5 + 1;
  if ( v3 != 44 )
    return 0;
  if ( *v6 == 125 )
    return 1;
  v4 = byte_888D30[(unsigned __int8)*v6] & 4;
  v7 = v6 + 1;
  if ( !v4 )
    return 0;
  while ( (byte_888D30[*v7] & 4) != 0 )
    ++v7;
  return *v7 == 125;
}
