int __fastcall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        const char *__s)
{
  unsigned int v2; // eax
  char *M_data; // edi
  char *M_finish; // esi
  const char *v5; // eax

  v2 = strlen(__s);
  M_data = this->_M_start_of_storage._M_data;
  M_finish = this->_M_finish;
  if ( M_finish == M_data || v2 > M_finish - M_data )
    return -(v2 != 0);
  v5 = stlp_std::search<char const *,char const *,stlp_std::priv::_Eq_traits<stlp_std::char_traits<char>>>(
         M_data,
         M_finish,
         __s,
         &__s[v2]);
  if ( v5 == M_finish )
    return -1;
  else
    return v5 - M_data;
}
