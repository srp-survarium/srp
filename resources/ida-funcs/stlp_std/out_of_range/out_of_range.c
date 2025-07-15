void __thiscall stlp_std::out_of_range::out_of_range(
        stlp_std::out_of_range *this,
        const stlp_std::out_of_range *__that)
{
  stlp_std::__Named_exception::__Named_exception(this, __that);
  this->__vftable = (stlp_std::out_of_range_vtbl *)&stlp_std::out_of_range::`vftable';
}


void __thiscall stlp_std::out_of_range::out_of_range(
        stlp_std::out_of_range *this,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__arg)
{
  stlp_std::logic_error::logic_error(this, __arg);
  this->__vftable = (stlp_std::out_of_range_vtbl *)&stlp_std::out_of_range::`vftable';
}
