const wchar_t *__thiscall stlp_std::ctype<wchar_t>::do_scan_is(
        stlp_std::ctype<wchar_t> *this,
        stlp_std::ctype_base::mask m,
        const wchar_t *low,
        const wchar_t *high)
{
  return stlp_std::priv::__find_if<wchar_t const *,stlp_std::_Ctype_w_is_mask>(
           low,
           high,
           (stlp_std::_Ctype_w_is_mask)__PAIR64__(dword_8167B0, m));
}
