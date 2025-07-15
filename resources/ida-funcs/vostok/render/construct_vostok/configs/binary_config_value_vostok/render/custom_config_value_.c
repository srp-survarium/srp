void __cdecl vostok::render::construct_vostok::configs::binary_config_value_vostok::render::custom_config_value_(
        const vostok::configs::binary_config_value *value,
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> item,
        vostok::mutable_buffer *data_buffer)
{
  const vostok::configs::binary_config_value *v3; // ebp
  vostok::render::custom_config_value *rem; // esi
  unsigned int v5; // eax
  vostok::mutable_buffer *v6; // ebx
  vostok::render::custom_config_value *m_data; // ecx
  int count; // eax
  const vostok::configs::binary_config_value *pointer; // esi
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v10; // edi
  vostok::render::custom_config_value *v11; // ebp
  unsigned int v12; // kr00_4
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // [esp-Ch] [ebp-1Ch]
  vostok::render::custom_config_value *items; // [esp+Ch] [ebp-4h]

  v3 = value;
  rem = (vostok::render::custom_config_value *)item.rem_;
  rem->type = vostok::render::convert_type_vostok::configs::binary_config_value_(value->type);
  rem->id = (const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->id);
  rem->count = 0;
  v5 = rem->type - 3;
  rem->data = 0;
  rem->id_crc = 0;
  if ( v5 > 1 )
  {
    rem->data = value->data.pointer;
    rem->count = value->count;
  }
  else
  {
    rem->count = value->count;
    v6 = data_buffer;
    rem->data = data_buffer->m_data;
    m_data = (vostok::render::custom_config_value *)v6->m_data;
    count = value->count;
    v6->m_size -= count * 20;
    v6->m_data = (char *)&m_data[count];
    pointer = (const vostok::configs::binary_config_value *)value->data.pointer;
    v10 = (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)value->data.pointer + 8);
    while ( pointer != (const vostok::configs::binary_config_value *)v3->data.pointer + v3->count )
    {
      items = m_data + 1;
      if ( m_data )
      {
        m_data->id = 0;
        m_data->data = 0;
        m_data->id_crc = 0;
        m_data->type = 0;
        m_data->count = 0;
        m_data->destroyer = 0;
        v11 = m_data;
      }
      else
      {
        v11 = 0;
      }
      vostok::render::construct_vostok::configs::binary_config_value_vostok::render::custom_config_value_(
        pointer,
        v11,
        v6);
      if ( vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(v10) )
      {
        item.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
        boost::detail::crc_table_t<32,79764919,1>::init_table();
        v12 = strlen((const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(v10));
        v14 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(v10)
            + v12;
        v13 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(v10);
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(&item, v13, v14);
        v11->id_crc = ~item.rem_;
      }
      v3 = value;
      m_data = items;
      ++pointer;
      v10 += 6;
    }
  }
}
