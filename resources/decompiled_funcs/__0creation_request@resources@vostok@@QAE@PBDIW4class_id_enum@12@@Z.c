void __thiscall vostok::resources::creation_request::creation_request(
        vostok::resources::creation_request *this,
        const char *name,
        unsigned int buffer_size,
        vostok::resources::class_id_enum id)
{
  this->m_name = name;
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    (vostok::mutable_buffer *)&this->m_data,
    0,
    buffer_size);
  this->m_id = id;
}
