int __userpurge stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find@<eax>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this@<esi>,
        unsigned int __n@<eax>,
        const char *__s,
        unsigned int __pos)
{
  unsigned int v5; // eax
  char *v6; // edi
  const vostok::animation::mixing::animation_interval *v7; // eax
  char *v8; // edi
  const char *v10; // [esp-8h] [ebp-14h]

  v5 = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::size(this);
  if ( __pos >= v5 || __pos + __n > v5 )
  {
    if ( !__n && __pos <= v5 )
      return __pos;
  }
  else
  {
    v10 = &__s[__n];
    v6 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Finish(this);
    v7 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((vostok::animation::mixing::animation_lexeme_parameters *)this);
    v8 = (char *)stlp_std::search<char const *,char const *,stlp_std::priv::_Eq_traits<stlp_std::char_traits<char>>>(
                   (const char *)v7 + __pos,
                   v6,
                   __s,
                   v10,
                   (stlp_std::priv::_Eq_traits<stlp_std::char_traits<char> >)__pos);
    if ( v8 != stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Finish(this) )
      return v8
           - (char *)stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((vostok::animation::mixing::animation_lexeme_parameters *)this);
  }
  return -1;
}
