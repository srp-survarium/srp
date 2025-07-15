const struct boost::system::error_category *__cdecl boost::system::system_category()
{
  if ( (dword_8E4C10 & 1) == 0 )
  {
    dword_8E4C10 |= 1u;
    dword_8E4C0C = (int)&`anonymous namespace'::system_error_category::`vftable';
    atexit(sub_69F440);
  }
  return (const struct boost::system::error_category *)&dword_8E4C0C;
}
