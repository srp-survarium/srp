_DWORD *__cdecl XML_SetUserData(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1[1] == *a1 )
  {
    *a1 = a2;
    result = a2;
    a1[1] = a2;
  }
  else
  {
    *a1 = a2;
  }
  return result;
}
