int __thiscall stlp_std::priv::stdio_streambuf_base::sync(stlp_std::priv::stdio_streambuf_base *this)
{
  return -(fflush(this->_M_file) != 0);
}
