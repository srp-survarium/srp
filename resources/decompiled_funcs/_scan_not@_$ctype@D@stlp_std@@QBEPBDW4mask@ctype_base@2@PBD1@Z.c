const char *__thiscall stlp_std::ctype<char>::scan_not(
        stlp_std::ctype<char> *this,
        stlp_std::ctype_base::mask __m,
        const char *__low,
        const char *__high)
{
  stlp_std::_Ctype_not_mask v5; // [esp-Ch] [ebp-Ch]

  v5._M_table = this->_M_ctype_table;
  v5._Mask = __m;
  return stlp_std::priv::__find_if<char const *,stlp_std::_Ctype_not_mask>(__low, __high, v5);
}
