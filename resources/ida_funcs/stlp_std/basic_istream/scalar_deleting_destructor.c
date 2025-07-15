_BYTE *__thiscall stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`scalar deleting destructor'(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *this,
        char a2)
{
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)this - 16));
  if ( (a2 & 1) != 0 )
    operator delete(&this[-1].gap10[80]);
  return &this[-1].gap10[80];
}


char *__thiscall stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>::`scalar deleting destructor'(
        stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        char a2)
{
  char *v2; // esi

  v2 = &this[-1].gap10[80];
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)&this[-1].gap10[80] + 4) - 16] = &stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  *(_DWORD *)this->gap0 = &stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)this);
  if ( (a2 & 1) != 0 )
    operator delete(v2);
  return v2;
}
