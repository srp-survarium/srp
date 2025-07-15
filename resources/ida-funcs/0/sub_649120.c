int __cdecl sub_649120(_DWORD *a1, _BYTE *a2)
{
  int v3; // [esp+0h] [ebp-4h]

  while ( *a2 )
  {
    if ( a1[3] != a1[2] || (unsigned __int8)sub_649210(a1) )
    {
      *(_BYTE *)a1[3]++ = *a2;
      v3 = 1;
    }
    else
    {
      v3 = 0;
    }
    if ( !v3 )
      return 0;
    ++a2;
  }
  return a1[4];
}
