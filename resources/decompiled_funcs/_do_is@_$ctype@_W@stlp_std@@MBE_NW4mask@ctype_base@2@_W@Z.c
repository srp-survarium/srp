BOOL __thiscall stlp_std::ctype<wchar_t>::do_is(
        stlp_std::ctype<wchar_t> *this,
        stlp_std::ctype_base::mask m,
        wchar_t c)
{
  return c < 0x100u && (m & dword_8167B0[c]) != 0;
}
