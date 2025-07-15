void __thiscall stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *this)
{
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vftable';
  *(_DWORD *)this->gap10 = &stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)this->gap10);
}
