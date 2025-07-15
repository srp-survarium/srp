const wchar_t *__thiscall stlp_std::ctype<wchar_t>::do_scan_not(
        stlp_std::ctype<wchar_t> *this,
        stlp_std::ctype_base::mask m,
        const wchar_t *low,
        const wchar_t *high)
{
  stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask> *v4; // eax
  stlp_std::_Ctype_w_is_mask __pred; // [esp+0h] [ebp-10h] BYREF
  stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask> result; // [esp+8h] [ebp-8h] BYREF

  __pred.M = m;
  __pred.table = (const stlp_std::ctype_base::mask *)dword_8167B0;
  v4 = stlp_std::not1<stlp_std::_Ctype_w_is_mask>(&result, &__pred);
  return stlp_std::priv::__find_if<wchar_t const *,stlp_std::unary_negate<stlp_std::_Ctype_w_is_mask>>(low, high, *v4);
}
