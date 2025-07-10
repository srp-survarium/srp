int __cdecl TestDefaultCountry(__int16 lcid)
{
  int v1; // eax

  v1 = 0;
  while ( lcid != __rglangidNotDefault[v1] )
  {
    if ( (unsigned int)++v1 >= 10 )
      return 1;
  }
  return 0;
}
