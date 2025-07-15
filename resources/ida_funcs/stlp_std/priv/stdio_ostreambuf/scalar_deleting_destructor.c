stlp_std::priv::stdio_ostreambuf *__thiscall stlp_std::priv::stdio_ostreambuf::`scalar deleting destructor'(
        stlp_std::priv::stdio_ostreambuf *this,
        char a2)
{
  stlp_std::priv::stdio_ostreambuf::~stdio_ostreambuf(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
