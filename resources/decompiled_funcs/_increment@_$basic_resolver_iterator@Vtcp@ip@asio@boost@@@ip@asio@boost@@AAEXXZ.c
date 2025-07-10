void __thiscall boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::increment(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *this)
{
  if ( ++this->index_ == this->values_.px->_M_impl._M_finish - this->values_.px->_M_impl._M_start )
  {
    boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::reset(&this->values_);
    this->index_ = 0;
  }
}
