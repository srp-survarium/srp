int __usercall _setmode@<eax>(stlp_std::ioinfo **a1@<edi>, int a2@<esi>, int fh, HINSTANCE__ *mode)
{
  int retval; // [esp+14h] [ebp-1Ch]

  if ( mode != (HINSTANCE__ *)0x4000
    && mode != (HINSTANCE__ *)0x8000
    && mode != &_sbh_sizeHeaderList
    && mode != (HINSTANCE__ *)((char *)&loc_3FFFF + 1)
    && mode != (HINSTANCE__ *)&loc_20000 )
  {
    *_errno() = 22;
LABEL_7:
    _invalid_parameter(0, (int)a1, a2);
    return -1;
  }
  if ( fh == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (a1 = &__pioinfo[fh >> 5], a2 = (fh & 0x1F) << 6, (*(&(*a1)->osfile + a2) & 1) == 0) )
  {
    *_errno() = 9;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    retval = _setmode_nolock(fh, (unsigned __int8 *)mode);
  }
  else
  {
    *_errno() = 9;
    retval = -1;
  }
  _unlock_fhandle(fh);
  return retval;
}
