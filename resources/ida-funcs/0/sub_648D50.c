char __cdecl sub_648D50(_BYTE *a1, char *a2)
{
  while ( (char)*a1 == *a2 )
  {
    if ( !*a1 )
      return 1;
    ++a1;
    ++a2;
  }
  return 0;
}
