int __cdecl sub_52DCF0(_DWORD *a1, _BYTE *a2)
{
  int v4; // [esp+0h] [ebp-4h]
  int v5; // [esp+10h] [ebp+Ch]

  do
  {
    if ( a1[3] != a1[2] || (unsigned __int8)sub_52DE70(a1) )
    {
      *(_BYTE *)a1[3]++ = *a2;
      v4 = 1;
    }
    else
    {
      v4 = 0;
    }
    if ( !v4 )
      return 0;
  }
  while ( *a2++ );
  v5 = a1[4];
  a1[4] = a1[3];
  return v5;
}
