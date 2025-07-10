boost::asio::ip::address_v6 *__cdecl boost::asio::ip::address_v6::from_string(
        boost::asio::ip::address_v6 *result,
        const char *str,
        boost::system::error_code *ec)
{
  boost::asio::ip::address_v6 tmp; // [esp+D4h] [ebp-14h] BYREF

  memset(&tmp, 0, sizeof(tmp));
  if ( boost::asio::detail::socket_ops::inet_pton(23, str, &tmp, &tmp.scope_id_, ec) > 0 )
  {
    *result = tmp;
  }
  else
  {
    *(_QWORD *)result->addr_.u.Byte = 0;
    *(_QWORD *)&result->addr_.u.Word[4] = 0;
    result->scope_id_ = 0;
  }
  return result;
}
