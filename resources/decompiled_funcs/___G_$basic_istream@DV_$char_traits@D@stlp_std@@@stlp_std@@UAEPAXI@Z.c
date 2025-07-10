_BYTE *__thiscall stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`scalar deleting destructor'(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *this,
        char a2)
{
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)this - 16));
  if ( (a2 & 1) != 0 )
    operator delete(&this[-1].gap10[80]);
  return &this[-1].gap10[80];
}
