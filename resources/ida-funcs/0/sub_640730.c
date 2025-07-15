char __cdecl sub_640730(int a1)
{
  if ( !*(_DWORD *)(a1 + 496) )
    *(_DWORD *)(a1 + 496) = sub_640780();
  if ( *(_BYTE *)(a1 + 236) )
    return sub_648240(a1, "xml=http://www.w3.org/XML/1998/namespace");
  else
    return 1;
}
