int __usercall _set_new_mode@<eax>(int a1@<ebx>, int a2@<edi>, unsigned int nhm)
{
  int result; // eax

  if ( nhm < 2 )
  {
    result = _newmode;
    _newmode = nhm;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return -1;
  }
  return result;
}
