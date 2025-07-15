void __usercall boost::asio::detail::socket_holder::~socket_holder(
        boost::asio::detail::socket_holder *this@<ecx>,
        unsigned int *a2@<esi>)
{
  unsigned int v2; // [esp-Ch] [ebp-1Ch]
  boost::system::error_code v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int8 v4; // [esp+Fh] [ebp-1h] BYREF

  if ( *a2 != -1 )
  {
    v3.m_val = 0;
    v3.m_cat = boost::system::system_category();
    v2 = *a2;
    v4 = 0;
    boost::asio::detail::socket_ops::close(&v3, v2, &v4, 1);
  }
}
