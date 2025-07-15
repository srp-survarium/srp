void __usercall boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context::context(
        boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context *this@<esi>,
        boost::asio::detail::win_iocp_io_service *k@<eax>)
{
  this->key_ = k;
  this->next_ = (boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::context *)TlsGetValue(boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::top_.tss_key_);
  this->value_ = (unsigned __int8 *)this;
  TlsSetValue(
    boost::asio::detail::call_stack<boost::asio::detail::win_iocp_io_service,unsigned char>::top_.tss_key_,
    this);
}
