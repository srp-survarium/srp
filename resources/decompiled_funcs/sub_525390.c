char __cdecl sub_525390(int a1)
{
  if ( !*(_DWORD *)(a1 + 496) )
    *(_DWORD *)(a1 + 496) = sub_5253E0();
  if ( *(_BYTE *)(a1 + 236) )
    return sub_52CEA0(a1, "xml=http://www.w3.org/XML/1998/namespace");
  else
    return 1;
}
