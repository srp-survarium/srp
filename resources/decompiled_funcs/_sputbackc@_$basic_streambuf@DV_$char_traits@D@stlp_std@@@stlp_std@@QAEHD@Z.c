int __thiscall stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::sputbackc(
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *this,
        unsigned __int8 __c)
{
  if ( this->_M_gbegin < this->_M_gnext
    && stlp_std::__char_traits_base<char,int>::eq((const char *)&__c, (const char *)this->_M_gnext - 1) )
  {
    return *(unsigned __int8 *)--this->_M_gnext;
  }
  else
  {
    return this->pbackfail(this, __c);
  }
}
