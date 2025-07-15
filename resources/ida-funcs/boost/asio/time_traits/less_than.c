BOOL __usercall boost::asio::time_traits<boost::posix_time::ptime>::less_than@<eax>(
        const boost::posix_time::ptime *t1@<ecx>,
        const boost::posix_time::ptime *t2@<eax>)
{
  return t1->time_.time_count_.value_ < t2->time_.time_count_.value_;
}
