stlp_std::runtime_error *__thiscall boost::bad_function_call::`vector deleting destructor'(
        stlp_std::runtime_error *this,
        char a2)
{
  stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
