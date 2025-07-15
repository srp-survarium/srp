vostok::render::custom_config *__usercall vostok::render::create_custom_config_impl_vostok::configs::binary_config_value_@<eax>(
        vostok::mutable_buffer *data_buffer@<esi>,
        const vostok::configs::binary_config_value *value,
        unsigned int *out_data_crc)
{
  char *m_data; // eax
  vostok::render::custom_config *v4; // ebp
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
    v4 = (vostok::render::custom_config *)m_data;
  }
  else
  {
    v4 = 0;
  }
  data_buffer->m_data += 32;
  data_buffer->m_size -= 32;
  vostok::render::construct_vostok::configs::binary_config_value_vostok::render::custom_config_value_(
    value,
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&v4->m_root,
    data_buffer);
  vostok::render::sort_by_crc_vostok::render::custom_config_value_(&v4->m_root);
  vostok::render::fill_data_vostok::render::custom_config_value_(&v4->m_root, data_buffer);
  result = v4;
  *out_data_crc = 0;
  return result;
}
