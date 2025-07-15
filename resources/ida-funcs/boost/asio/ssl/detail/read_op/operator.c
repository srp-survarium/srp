int __userpurge boost::asio::ssl::detail::read_op<boost::asio::mutable_buffers_1>::operator()@<eax>(
        boost::asio::ssl::detail::read_op<boost::asio::mutable_buffers_1> *this@<eax>,
        boost::system::error_code *ec@<ecx>,
        boost::asio::ssl::detail::engine *eng,
        unsigned int *bytes_transferred)
{
  void *data; // ecx
  unsigned int size; // eax
  const boost::system::error_category *v7; // eax

  data = this->buffers_.data_;
  size = this->buffers_.size_;
  if ( size )
    return boost::asio::ssl::detail::engine::perform(
             eng,
             ec,
             (int (__thiscall *)(boost::asio::ssl::detail::engine *, void *, unsigned int))boost::asio::ssl::detail::engine::do_read,
             data,
             size,
             bytes_transferred);
  v7 = boost::system::system_category();
  ec->m_val = 0;
  ec->m_cat = v7;
  return 0;
}
