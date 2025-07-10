void __cdecl vostok::render::fill_data_vostok::render::custom_config_value_(
        const vostok::render::custom_config_value *value,
        vostok::mutable_buffer *data_buffer)
{
  unsigned __int16 type; // ax
  vostok::mutable_buffer *v3; // esi
  unsigned int v4; // ebx
  int count; // eax
  unsigned __int8 *id; // ecx
  const char *v7; // eax
  int v8; // ebx
  const vostok::render::custom_config_value *data; // ebx

  type = value->type;
  if ( type == 3 || type == 4 )
  {
    data = (const vostok::render::custom_config_value *)value->data;
    v3 = data_buffer;
    while ( data != (const vostok::render::custom_config_value *)value->data + value->count )
      vostok::render::fill_data_vostok::render::custom_config_value_(data++, data_buffer);
  }
  else
  {
    v3 = data_buffer;
    v4 = ((int)(data_buffer->m_data + 3) & 0xFFFFFFFC) - (unsigned int)data_buffer->m_data;
    if ( v4 )
    {
      memset((int)data_buffer->m_data, 0, v4);
      data_buffer->m_data += v4;
      data_buffer->m_size -= v4;
    }
    if ( value->count > 4u || value->type == vostok::render::static_type::get_type_id<char const *>() )
    {
      memcpy((unsigned __int8 *)data_buffer->m_data, (unsigned __int8 *)value->data, value->count);
      value->data = data_buffer->m_data;
      count = value->count;
      data_buffer->m_data += count;
      data_buffer->m_size -= count;
    }
  }
  id = (unsigned __int8 *)value->id;
  if ( value->id )
  {
    v7 = &value->id[strlen(value->id) + 1];
    v8 = v7 - (const char *)id;
    memcpy((unsigned __int8 *)v3->m_data, id, v7 - (const char *)id);
    value->id = v3->m_data;
    v3->m_data += v8;
    v3->m_size -= v8;
  }
}
