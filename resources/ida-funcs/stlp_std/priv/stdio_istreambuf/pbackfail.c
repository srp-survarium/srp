int __thiscall stlp_std::priv::stdio_istreambuf::pbackfail(stlp_std::priv::stdio_istreambuf *this, int c)
{
  int result; // eax
  char *M_gnext; // eax

  if ( c == -1 )
  {
    M_gnext = this->_M_gnext;
    if ( this->_M_gbegin < M_gnext )
    {
      this->_M_gnext = M_gnext - 1;
      return 0;
    }
  }
  else
  {
    result = ungetc(c, this->_M_file);
    if ( result != -1 )
      return result;
  }
  return -1;
}
