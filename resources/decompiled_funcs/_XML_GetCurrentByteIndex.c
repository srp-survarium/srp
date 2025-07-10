int __cdecl XML_GetCurrentByteIndex(_DWORD *a1)
{
  if ( a1[72] )
    return a1[9] - (a1[10] - a1[72]);
  else
    return -1;
}
