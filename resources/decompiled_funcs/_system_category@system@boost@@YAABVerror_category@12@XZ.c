const struct boost::system::error_category *__cdecl boost::system::system_category()
{
  if ( (dword_A9B0DC & 1) == 0 )
  {
    dword_A9B0DC |= 1u;
    dword_A9B0D8 = (int)&`anonymous namespace'::system_error_category::`vftable';
    atexit(func);
  }
  return (const struct boost::system::error_category *)&dword_A9B0D8;
}
