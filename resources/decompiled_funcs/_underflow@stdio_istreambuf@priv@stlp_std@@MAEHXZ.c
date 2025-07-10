int __thiscall stlp_std::priv::stdio_istreambuf::underflow(stlp_std::priv::stdio_istreambuf *this)
{
  int v2; // eax
  int v3; // esi

  v2 = getc(this->_M_file);
  v3 = v2;
  if ( v2 == -1 )
    return -1;
  ungetc(v2, this->_M_file);
  return v3;
}
