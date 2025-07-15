// attributes: thunk
char *__cdecl stlp_std::priv::__insert_grouping(
        char *first,
        char *last,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        char separator,
        char Plus,
        char Minus,
        int basechars)
{
  return stlp_std::__insert_grouping_aux_char_(first, last, grouping, separator, Plus, Minus, basechars);
}


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


void __cdecl stlp_std::priv::__insert_grouping(
        stlp_std::priv::__basic_iostring<char> *str,
        char *group_pos,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        char separator,
        char Plus,
        char Minus,
        int basechars)
{
  stlp_std::__insert_grouping_aux_char_stlp_std::priv::__basic_iostring_char___(
    str,
    group_pos,
    separator,
    grouping,
    Plus,
    Minus,
    basechars);
}


void __cdecl stlp_std::priv::__insert_grouping(
        stlp_std::priv::__basic_iostring<wchar_t> *str,
        unsigned int group_pos,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *grouping,
        wchar_t separator,
        wchar_t Plus,
        wchar_t Minus,
        int basechars)
{
  stlp_std::__insert_grouping_aux_wchar_t_stlp_std::priv::__basic_iostring_wchar_t___(
    str,
    group_pos,
    grouping,
    separator,
    Plus,
    Minus,
    basechars);
}
