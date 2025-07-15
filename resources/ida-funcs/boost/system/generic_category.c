const struct boost::system::error_category *__cdecl boost::system::generic_category()
{
  if ( (dword_8E4C18 & 1) == 0 )
  {
    dword_8E4C18 |= 1u;
    dword_8E4C14 = (int)&`anonymous namespace'::generic_error_category::`vftable';
    atexit(sub_69F450);
  }
  return (const struct boost::system::error_category *)&dword_8E4C14;
}
