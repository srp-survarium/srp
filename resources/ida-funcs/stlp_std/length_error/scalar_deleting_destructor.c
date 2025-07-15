boost::gregorian::bad_day_of_month *__thiscall stlp_std::length_error::`scalar deleting destructor'(
        boost::gregorian::bad_day_of_month *this,
        char a2)
{
  stlp_std::__Named_exception::~__Named_exception(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
