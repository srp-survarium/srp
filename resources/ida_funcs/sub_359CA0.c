int __cdecl sub_359CA0(int a1, int a2, int a3)
{
  if ( a2 == -1 || a2 == -100000 )
  {
    *(_DWORD *)(a1 + 112) |= 0x1000u;
    if ( a3 )
      return (int)&loc_35B60;
    else
      return 45455;
  }
  else if ( a2 == -2 || a2 == -50000 )
  {
    if ( a3 )
      return 151724;
    else
      return 65909;
  }
  return a2;
}
