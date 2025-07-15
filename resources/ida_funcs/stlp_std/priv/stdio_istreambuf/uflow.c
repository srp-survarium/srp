int __thiscall stlp_std::priv::stdio_istreambuf::uflow(stlp_std::priv::stdio_istreambuf *this)
{
  return getc(this->_M_file);
}
