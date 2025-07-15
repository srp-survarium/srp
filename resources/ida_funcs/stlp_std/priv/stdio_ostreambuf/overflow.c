int __thiscall stlp_std::priv::stdio_ostreambuf::overflow(stlp_std::priv::stdio_ostreambuf *this, int c)
{
  int v3; // edi

  if ( c != -1 )
    return putc(c, this->_M_file);
  v3 = this->_M_pnext - this->_M_pbegin;
  if ( !v3 )
    return 0;
  fflush(this->_M_file);
  return (this->_M_pnext - this->_M_pbegin < v3) - 1;
}
