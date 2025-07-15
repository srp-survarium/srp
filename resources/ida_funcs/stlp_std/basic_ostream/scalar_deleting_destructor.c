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


char *__thiscall stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::`scalar deleting destructor'(
        stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        char a2)
{
  char *v2; // esi

  v2 = &this[-1].gap0[96];
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)&this[-1].gap0[96] + 4) - 8] = &stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  *(_DWORD *)this->gap0 = &stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)this);
  if ( (a2 & 1) != 0 )
    operator delete(v2);
  return v2;
}
