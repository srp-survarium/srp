stlp_std::priv::stdio_streambuf_base *__thiscall stlp_std::priv::stdio_streambuf_base::setbuf(
        stlp_std::priv::stdio_streambuf_base *this,
        char *s,
        __int64 n)
{
  unsigned int *p_n; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _DWORD v8[2]; // [esp+Ch] [ebp-8h] BYREF

  v8[0] = -1;
  v8[1] = 0;
  if ( n >= 0xFFFFFFFFLL )
    p_n = v8;
  else
    p_n = (unsigned int *)&n;
  v5 = *p_n;
  if ( s || n )
    v6 = 0;
  else
    v6 = 4;
  setvbuf(this->_M_file, s, v6, v5);
  return this;
}
