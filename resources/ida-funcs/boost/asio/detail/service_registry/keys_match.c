bool __usercall boost::asio::detail::service_registry::keys_match@<al>(
        const boost::asio::io_service::service::key *key1@<eax>,
        const boost::asio::io_service::service::key *key2@<esi>)
{
  const boost::asio::io_service::id *id; // ecx
  const boost::asio::io_service::id *v3; // edx
  bool result; // al
  type_info *type_info; // eax

  id = key1->id_;
  result = 1;
  if ( !id || (v3 = key2->id_) == 0 || id != v3 )
  {
    type_info = key1->type_info_;
    if ( !type_info || !key2->type_info_ || !type_info::operator==(type_info, key2->type_info_) )
      return 0;
  }
  return result;
}
