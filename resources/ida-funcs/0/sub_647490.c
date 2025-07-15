_BYTE *__cdecl sub_647490(_BYTE *a1)
{
  _BYTE *result; // eax
  _BYTE *v2; // [esp+0h] [ebp-4h]

  while ( *a1 )
  {
    if ( *a1 == 13 )
    {
      v2 = a1;
      do
      {
        if ( *a1 == 13 )
        {
          *v2++ = 10;
          if ( *++a1 == 10 )
            ++a1;
        }
        else
        {
          *v2++ = *a1++;
        }
      }
      while ( *a1 );
      result = v2;
      *v2 = 0;
      return result;
    }
    result = ++a1;
  }
  return result;
}
