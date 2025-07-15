void __usercall boost::gregorian::greg_day::greg_day(
        boost::gregorian::greg_day *this@<esi>,
        unsigned __int16 day_of_month@<ax>)
{
  this->value_ = 1;
  if ( day_of_month + 1 < 2 || day_of_month > 0x1Fu )
    boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month>::on_error();
  else
    this->value_ = day_of_month;
}
