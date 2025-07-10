int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v5; // eax
  unsigned __int8 *v7; // [esp+0h] [ebp-28h]
  _iobuf str; // [esp+8h] [ebp-20h] BYREF

  strlen(v7);
  if ( string && format )
  {
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v5 <= 0x7FFFFFFF )
      str._cnt = v5;
    return inputfn(&str, (const unsigned __int8 *)format, plocinfo, arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
