_DWORD *__cdecl sub_648F20(_DWORD *a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // [esp+0h] [ebp-8h]
  _DWORD *i; // [esp+4h] [ebp-4h]

  if ( a1[1] )
  {
    for ( i = (_DWORD *)*a1; i; i = v2 )
    {
      v2 = (_DWORD *)*i;
      *i = a1[1];
      a1[1] = i;
    }
  }
  else
  {
    a1[1] = *a1;
  }
  *a1 = 0;
  result = a1;
  a1[4] = 0;
  a1[3] = 0;
  a1[2] = 0;
  return result;
}
