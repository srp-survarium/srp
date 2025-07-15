int __usercall _vsnprintf_s_l@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        unsigned int sizeInBytes,
        unsigned int count,
        char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int *v9; // eax
  int v10; // [esp+4h] [ebp-4h]

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
  if ( count )
  {
    if ( !string )
    {
LABEL_9:
      *_errno() = 22;
LABEL_21:
      _invalid_parameter(0, a1, (int)string);
      return -1;
    }
  }
  else if ( !string )
  {
    if ( !sizeInBytes )
      return 0;
    goto LABEL_9;
  }
  a1 = sizeInBytes;
  if ( !sizeInBytes )
    goto LABEL_9;
  v9 = _errno();
  if ( sizeInBytes > count )
  {
    a1 = *v9;
    result = _vsnprintf_helper(*v9, (int)string, _output_s_l, string, count + 1, format, plocinfo, ap);
    if ( result == -2 )
    {
      if ( *_errno() == 34 )
        *_errno() = a1;
      return -1;
    }
    goto LABEL_18;
  }
  v10 = *v9;
  result = _vsnprintf_helper(sizeInBytes, (int)string, _output_s_l, string, sizeInBytes, format, plocinfo, ap);
  string[sizeInBytes - 1] = 0;
  if ( result != -2 )
  {
LABEL_18:
    if ( result >= 0 )
      return result;
    goto LABEL_19;
  }
  if ( count == -1 )
  {
    if ( *_errno() == 34 )
      *_errno() = v10;
    return -1;
  }
LABEL_19:
  *string = 0;
  if ( result == -2 )
  {
    *_errno() = 34;
    goto LABEL_21;
  }
  return -1;
}
