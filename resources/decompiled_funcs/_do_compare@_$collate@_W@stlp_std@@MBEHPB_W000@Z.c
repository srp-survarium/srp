int __thiscall stlp_std::collate<wchar_t>::do_compare(
        stlp_std::collate<wchar_t> *this,
        const wchar_t *low1,
        const wchar_t *high1,
        const wchar_t *low2,
        const wchar_t *high2)
{
  return stlp_std::priv::__lexicographical_compare_3way<wchar_t const *,wchar_t const *>(low1, high1, low2, high2);
}
