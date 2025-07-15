int __usercall _set_error_mode@<eax>(int a1@<ebx>, int a2@<edi>, int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return -1;
}
