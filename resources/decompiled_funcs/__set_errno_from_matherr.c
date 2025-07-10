void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}
