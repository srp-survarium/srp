int __usercall stlp_std::_get_osfflags@<eax>(int fd@<eax>, void *oshandle@<edi>)
{
  char osfile; // cl
  __int16 v3; // bx
  __int16 v4; // bx
  BOOL v5; // esi
  BOOL v6; // eax
  int result; // eax
  unsigned int dummy; // [esp+0h] [ebp-8h] BYREF
  unsigned int dummy2; // [esp+4h] [ebp-4h] BYREF

  osfile = 0;
  if ( fd >= 0 )
    osfile = __pioinfo[fd >> 5][fd & 0x1F].osfile;
  v3 = 0;
  if ( (osfile & 0x20) != 0 )
    v3 = 8;
  if ( osfile >= 0 )
    v4 = v3 | 0x8000;
  else
    v4 = v3 | 0x4000;
  v5 = WriteFile(oshandle, &dummy2, 0, &dummy, 0);
  v6 = ReadFile(oshandle, &dummy2, 0, &dummy, 0);
  if ( v5 )
  {
    if ( v6 )
    {
      v4 |= 2u;
      goto LABEL_13;
    }
  }
  else if ( v6 )
  {
    goto LABEL_13;
  }
  v4 |= 1u;
LABEL_13:
  result = 0;
  if ( (v4 & 3) != 0 )
  {
    if ( (v4 & 3) == 1 )
    {
      result = 16;
    }
    else if ( (v4 & 3) == 2 )
    {
      result = 24;
    }
  }
  else
  {
    result = 8;
  }
  if ( (v4 & 8) != 0 )
    result |= 1u;
  if ( v4 < 0 )
    return result | 4;
  return result;
}
