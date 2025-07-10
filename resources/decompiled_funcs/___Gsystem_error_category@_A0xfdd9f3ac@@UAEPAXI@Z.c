_DWORD *__thiscall `anonymous namespace'::system_error_category::`scalar deleting destructor'(_DWORD *p, char a2)
{
  *p = &boost::system::error_category::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(p);
  return p;
}
