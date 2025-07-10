int __thiscall stlp_std::collate<char>::do_compare(
        stlp_std::collate<char> *this,
        const char *low1,
        const char *high1,
        const char *low2,
        const char *high2)
{
  return stlp_std::priv::__lexicographical_compare_3way<char const *,char const *>(low1, high1, low2, high2);
}
