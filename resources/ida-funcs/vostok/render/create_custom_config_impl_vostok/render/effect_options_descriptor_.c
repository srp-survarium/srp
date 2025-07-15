vostok::render::custom_config *__usercall vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor_@<eax>(
        vostok::mutable_buffer *data_buffer@<esi>,
        vostok::render::custom_config_value *value,
        unsigned int *out_data_crc,
        bool is_calc_data_crc)
{
  char *m_data; // eax
  vostok::render::custom_config *v5; // ebp
  vostok::render::custom_config *result; // eax

  m_data = data_buffer->m_data;
  if ( data_buffer->m_data )
  {
    *(_DWORD *)m_data = 0;
    *((_DWORD *)m_data + 1) = 0;
    m_data[8] = 0;
    m_data[9] = 1;
    *((_DWORD *)m_data + 3) = 0;
    *((_DWORD *)m_data + 4) = 0;
    *((_DWORD *)m_data + 5) = 0;
    *((_WORD *)m_data + 12) = 0;
    *((_WORD *)m_data + 13) = 0;
    *((_DWORD *)m_data + 7) = 0;
    v5 = (vostok::render::custom_config *)m_data;
  }
  else
  {
    v5 = 0;
  }
  data_buffer->m_data += 32;
  data_buffer->m_size -= 32;
  vostok::render::construct_vostok::render::effect_options_descriptor_vostok::render::custom_config_value_(
    value,
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&v5->m_root,
    data_buffer);
  vostok::render::sort_by_crc_vostok::render::custom_config_value_(&v5->m_root);
  vostok::render::fill_data_vostok::render::custom_config_value_(&v5->m_root, data_buffer);
  if ( is_calc_data_crc )
  {
    *out_data_crc = vostok::render::calc_data_crc_vostok::render::custom_config_value_(&v5->m_root);
    return v5;
  }
  else
  {
    result = v5;
    *out_data_crc = 0;
  }
  return result;
}
