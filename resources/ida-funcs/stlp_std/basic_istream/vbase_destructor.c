void __thiscall stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *this)
{
  int v1; // eax
  stlp_std::ios_base *v2; // ecx

  v1 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
  v2 = (stlp_std::ios_base *)this->gap10;
  *(_DWORD *)((char *)v2 + v1 - 16) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vftable';
  v2->__vftable = (stlp_std::ios_base_vtbl *)&stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::ios_base::~ios_base(v2);
}
