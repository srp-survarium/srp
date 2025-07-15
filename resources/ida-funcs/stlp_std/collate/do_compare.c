int __thiscall stlp_std::collate<char>::do_compare(
        stlp_std::collate<char> *this,
        char *low1,
        char *high1,
        char *low2,
        char *high2)
{
  return stlp_std::priv::__lexicographical_compare_3way<char const *,char const *>(low1, high1, low2, high2);
}


int __thiscall stlp_std::collate<wchar_t>::do_compare(
        stlp_std::collate<wchar_t> *this,
        wchar_t *low1,
        wchar_t *high1,
        wchar_t *low2,
        wchar_t *high2)
{
  return stlp_std::priv::__lexicographical_compare_3way<wchar_t const *,wchar_t const *>(low1, high1, low2, high2);
}
