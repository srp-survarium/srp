void __cdecl vostok::render::fill_data_crc_buffer_vostok::render::custom_config_value_(
        const vostok::render::custom_config_value *value,
        vostok::mutable_buffer *buffer)
{
  unsigned __int8 *id; // ebp
  const char *v3; // eax
  int v4; // edi
  const vostok::render::custom_config_value *i; // edi
  unsigned __int16 type; // ax
  unsigned __int8 *data; // edx
  int count; // eax

  id = (unsigned __int8 *)value->id;
  if ( value->id )
  {
    v3 = &value->id[strlen(value->id) + 1];
    v4 = v3 - (const char *)id;
    memcpy((unsigned __int8 *)buffer->m_data, id, v3 - (const char *)id);
    buffer->m_data += v4;
    buffer->m_size -= v4;
  }
  if ( value->type == 3 )
  {
    for ( i = (const vostok::render::custom_config_value *)value->data;
          i != (const vostok::render::custom_config_value *)value->data + value->count;
          ++i )
    {
      vostok::render::fill_data_crc_buffer_vostok::render::custom_config_value_(i, buffer);
    }
  }
  else
  {
    if ( value->count > 4u
      || (type = vostok::render::static_type::get_type_id<char const *>(),
          data = (unsigned __int8 *)&value->data,
          value->type == type) )
    {
      data = (unsigned __int8 *)value->data;
    }
    memcpy((unsigned __int8 *)buffer->m_data, data, value->count);
    count = value->count;
    buffer->m_data += count;
    buffer->m_size -= count;
  }
}
