_BYTE *__thiscall stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::`scalar deleting destructor'(
        stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *this,
        char a2)
{
  char *v4; // [esp+4h] [ebp-8h]

  v4 = &this[-1].gap0[96];
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::~basic_ostream<char,stlp_std::char_traits<char>>(this);
  *((_DWORD *)v4 + 2) = &stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)(v4 + 8));
  if ( (a2 & 1) != 0 )
    operator delete(&this[-1].gap0[96]);
  return &this[-1].gap0[96];
}
