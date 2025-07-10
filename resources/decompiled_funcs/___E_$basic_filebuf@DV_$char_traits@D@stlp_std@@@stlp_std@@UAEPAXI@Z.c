stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::`vector deleting destructor'(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        char a2)
{
  stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::~basic_filebuf<char,stlp_std::char_traits<char>>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
