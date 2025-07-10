void __cdecl vostok::render::construct_vostok::render::custom_config_value_vostok::render::custom_config_value_(
        const vostok::render::custom_config_value *value,
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> item,
        vostok::mutable_buffer *data_buffer)
{
  vostok::render::custom_config_value *rem; // eax
  const char *id; // edx
  int type; // ecx
  vostok::render::custom_config_value *v7; // ebp
  vostok::mutable_buffer *v8; // esi
  vostok::render::custom_config_value *m_data; // ecx
  int count; // eax
  const vostok::render::custom_config_value *i; // edi
  vostok::render::custom_config_value *items; // [esp+Ch] [ebp+4h]

  rem = (vostok::render::custom_config_value *)item.rem_;
  *(_WORD *)(item.rem_ + 12) = value->type;
  id = value->id;
  rem->count = 0;
  type = rem->type;
  v7 = 0;
  rem->id = id;
  rem->data = 0;
  rem->id_crc = 0;
  rem->destroyer = value->destroyer;
  if ( (unsigned int)(type - 3) > 1 )
  {
    rem->data = value->data;
    rem->count = value->count;
  }
  else
  {
    rem->count = value->count;
    v8 = data_buffer;
    rem->data = data_buffer->m_data;
    m_data = (vostok::render::custom_config_value *)v8->m_data;
    count = value->count;
    v8->m_size -= count * 20;
    v8->m_data = (char *)&m_data[count];
    for ( i = (const vostok::render::custom_config_value *)value->data;
          i != (const vostok::render::custom_config_value *)value->data + value->count;
          ++i )
    {
      items = m_data + 1;
      if ( m_data )
      {
        m_data->id = 0;
        m_data->data = 0;
        m_data->id_crc = 0;
        m_data->destroyer = 0;
        m_data->type = 0;
        m_data->count = 0;
        v7 = m_data;
      }
      vostok::render::construct_vostok::render::custom_config_value_vostok::render::custom_config_value_(i, v7, v8);
      if ( i->id )
      {
        item.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
        boost::detail::crc_table_t<32,79764919,1>::init_table();
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
          &item,
          (unsigned __int8 *)i->id,
          (unsigned __int8 *)&i->id[strlen(i->id)]);
        v8 = data_buffer;
        v7->id_crc = ~item.rem_;
      }
      m_data = items;
      v7 = 0;
    }
  }
}
