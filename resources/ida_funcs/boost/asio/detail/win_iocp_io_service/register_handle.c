boost::system::error_code *__thiscall boost::asio::detail::win_iocp_io_service::register_handle(
        boost::asio::detail::win_iocp_io_service *this,
        boost::system::error_code *result,
        void *handle,
        boost::system::error_code *ec)
{
  const boost::system::error_category *m_cat; // ecx
  const boost::system::error_category *v6; // [esp+Ch] [ebp-10h]
  boost::system::error_code v7; // [esp+10h] [ebp-Ch]

  if ( CreateIoCompletionPort(handle, this->iocp_.handle, 0, 0) )
  {
    v6 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v6;
  }
  else
  {
    v7.m_val = GetLastError();
    v7.m_cat = boost::system::system_category();
    *ec = v7;
  }
  m_cat = ec->m_cat;
  result->m_val = ec->m_val;
  result->m_cat = m_cat;
  return result;
}
