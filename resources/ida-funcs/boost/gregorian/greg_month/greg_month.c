void __usercall boost::gregorian::greg_month::greg_month(
        boost::gregorian::greg_month *this@<esi>,
        unsigned __int16 theMonth@<ax>)
{
  this->value_ = 1;
  if ( theMonth + 1 < 2 || theMonth > 0xCu )
    boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month>::on_error();
  else
    this->value_ = theMonth;
}
