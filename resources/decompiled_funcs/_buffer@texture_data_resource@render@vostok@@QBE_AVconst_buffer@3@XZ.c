vostok::mutable_buffer *__usercall vostok::render::texture_data_resource::buffer@<eax>(
        vostok::render::texture_data_resource *this@<ecx>,
        int a2@<eax>,
        vostok::mutable_buffer *a3@<esi>)
{
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    a3,
    (unsigned __int8 *)(a2 + 4),
    *(_DWORD *)a2);
  return a3;
}
