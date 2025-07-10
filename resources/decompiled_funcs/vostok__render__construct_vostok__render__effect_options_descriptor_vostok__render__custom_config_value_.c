void __cdecl vostok::render::construct_vostok::render::effect_options_descriptor_vostok::render::custom_config_value_(
        vostok::render::custom_config_value *value,
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> item,
        vostok::mutable_buffer *data_buffer)
{
  vostok::render::custom_config_value *rem; // eax
  vostok::mutable_buffer *v5; // ebx
  char *m_data; // esi
  int v7; // eax
  vostok::render::effect_options_descriptor *id_crc; // ebp
  vostok::render::custom_config_value *v9; // eax
  unsigned int it_4; // [esp+Ch] [ebp-8h]
  vostok::render::custom_config_value *next_item; // [esp+18h] [ebp+4h]

  rem = (vostok::render::custom_config_value *)item.rem_;
  *(_WORD *)(item.rem_ + 12) = value->destroyer;
  rem->id = value->id;
  rem->count = 0;
  rem->data = 0;
  rem->id_crc = 0;
  rem->destroyer = value->data;
  if ( (unsigned int)rem->type - 3 > 1 )
  {
    rem->data = (const void *)value->id_crc;
    rem->count = HIWORD(value->destroyer);
  }
  else
  {
    rem->count = HIWORD(value->destroyer);
    v5 = data_buffer;
    rem->data = data_buffer->m_data;
    m_data = v5->m_data;
    v7 = 20 * HIWORD(value->destroyer);
    v5->m_size -= v7;
    v5->m_data = &m_data[v7];
    id_crc = (vostok::render::effect_options_descriptor *)value->id_crc;
    for ( it_4 = 0; LOWORD(value->destroyer) == 3 && it_4 < HIWORD(value->destroyer); ++it_4 )
    {
      v9 = (vostok::render::custom_config_value *)m_data;
      m_data += 20;
      if ( v9 )
      {
        v9->id = 0;
        v9->data = 0;
        v9->id_crc = 0;
        v9->type = 0;
        v9->count = 0;
        v9->destroyer = 0;
        next_item = v9;
      }
      else
      {
        next_item = 0;
      }
      vostok::render::construct_vostok::render::effect_options_descriptor_vostok::render::custom_config_value_(
        id_crc,
        next_item,
        v5);
      if ( id_crc->id )
      {
        item.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
        boost::detail::crc_table_t<32,79764919,1>::init_table();
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
          &item,
          (unsigned __int8 *)id_crc->id,
          (unsigned __int8 *)&id_crc->id[strlen(id_crc->id)]);
        next_item->id_crc = ~item.rem_;
      }
      id_crc = (vostok::render::effect_options_descriptor *)((char *)id_crc
                                                           + vostok::render::effect_options_descriptor::get_num_used_bytes(id_crc));
    }
  }
}
