int __cdecl _vsnprintf_s_l(
        char *string,
        unsigned int sizeInBytes,
        unsigned int count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int *v7; // eax
  int v8; // edi
  int save_errno; // [esp+4h] [ebp-4h]

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  if ( count )
  {
    if ( !string )
    {
LABEL_9:
      *_errno() = 22;
LABEL_21:
      _invalid_parameter(0, 0, 0, 0, 0);
      return -1;
    }
  }
  else if ( !string )
  {
    if ( !sizeInBytes )
      return 0;
    goto LABEL_9;
  }
  if ( !sizeInBytes )
    goto LABEL_9;
  v7 = _errno();
  if ( sizeInBytes > count )
  {
    v8 = *v7;
    result = _vsnprintf_helper(_output_s_l, string, count + 1, format, plocinfo, ap);
    if ( result == -2 )
    {
      if ( *_errno() == 34 )
        *_errno() = v8;
      return -1;
    }
    goto LABEL_18;
  }
  save_errno = *v7;
  result = _vsnprintf_helper(_output_s_l, string, sizeInBytes, format, plocinfo, ap);
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
      *_errno() = save_errno;
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
