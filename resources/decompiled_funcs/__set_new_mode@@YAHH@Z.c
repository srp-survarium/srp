int __cdecl _set_new_mode(unsigned int nhm)
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
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  return result;
}
