int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  char *v6; // eax
  char *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = (char *)_calloc_crt(v5, 2u);
      *pFloatStr = v6;
      if ( !v6 )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy((unsigned __int8 *)*pFloatStr, (unsigned __int8 *)floatstring, *pnFloatStrSz);
    }
    else
    {
      v8 = (char *)_recalloc_crt(*pFloatStr, v5, 2u);
      if ( !v8 )
        return 0;
      *pFloatStr = v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}
