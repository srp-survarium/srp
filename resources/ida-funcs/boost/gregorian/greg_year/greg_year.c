void __usercall boost::gregorian::greg_year::greg_year(
        boost::gregorian::greg_year *this@<esi>,
        unsigned __int16 year@<ax>)
{
  this->value_ = 1400;
  if ( year + 1 < 1401 || year > 0x2710u )
    boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year>::on_error();
  else
    this->value_ = year;
}
