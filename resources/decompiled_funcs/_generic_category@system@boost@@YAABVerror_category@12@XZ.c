const struct boost::system::error_category *__cdecl boost::system::generic_category()
{
  if ( (dword_A9B0E4 & 1) == 0 )
  {
    dword_A9B0E4 |= 1u;
    dword_A9B0E0 = (int)&`anonymous namespace'::generic_error_category::`vftable';
    atexit(sub_7F34E0);
  }
  return (const struct boost::system::error_category *)&dword_A9B0E0;
}
