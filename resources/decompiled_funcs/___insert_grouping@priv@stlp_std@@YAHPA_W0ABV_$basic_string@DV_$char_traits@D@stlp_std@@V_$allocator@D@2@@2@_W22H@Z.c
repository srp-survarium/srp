int __cdecl stlp_std::priv::__insert_grouping(
        wchar_t *first,
        wchar_t *last,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        wchar_t separator,
        wchar_t Plus,
        wchar_t Minus,
        int basechars)
{
  return stlp_std::__insert_grouping_aux_wchar_t_(last, first, grouping, separator, Plus, Minus, basechars);
}
