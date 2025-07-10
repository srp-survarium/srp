boost::asio::ssl::detail::engine::want __thiscall boost::asio::ssl::detail::engine::write(
        boost::asio::ssl::detail::engine *this,
        const boost::asio::const_buffer *data,
        boost::system::error_code *ec,
        unsigned int *bytes_transferred)
{
  const boost::system::error_category *v5; // [esp+6Ch] [ebp-4h]

  if ( data->size_ )
    return boost::asio::ssl::detail::engine::perform(
             this,
             boost::asio::ssl::detail::engine::do_write,
             (void *)data->data_,
             data->size_,
             ec,
             bytes_transferred);
  v5 = boost::system::system_category();
  ec->m_val = 0;
  ec->m_cat = v5;
  return 0;
}
