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
