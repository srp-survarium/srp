int __usercall vscan_fn@<eax>(
        const char *string@<esi>,
        int a2@<ebx>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  unsigned __int8 *v8; // [esp+0h] [ebp-28h]
  const char *v9; // [esp+8h] [ebp-20h] BYREF
  int v10; // [esp+Ch] [ebp-1Ch]
  const char *v11; // [esp+10h] [ebp-18h]
  int v12; // [esp+14h] [ebp-14h]

  strlen(v8);
  if ( string && format )
  {
    v12 = 73;
    v11 = string;
    v9 = string;
    v10 = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      v10 = v6;
    return inputfn((_iobuf *)&v9, (const unsigned __int8 *)format, plocinfo, arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a2, 0, (int)string);
    return -1;
  }
}
