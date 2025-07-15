void __thiscall stlp_std::auto_ptr<stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>>::~auto_ptr<stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>>(
        stlp_std::auto_ptr<stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > > *this)
{
  void (__thiscall ***M_p)(void *, int); // ecx

  M_p = (void (__thiscall ***)(void *, int))this->_M_p;
  if ( M_p )
    (**M_p)(M_p, 1);
}
