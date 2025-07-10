void __userpurge vostok::render::effect_compile_data::effect_compile_data(
        vostok::render::effect_compile_data *this@<esi>,
        vostok::render::effect_descriptor *in_descriptor@<eax>,
        unsigned int in_crc@<edx>,
        vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> in_config,
        bool in_add_to_array)
{
  vostok::render::custom_config *m_object; // eax

  this->descriptor = in_descriptor;
  m_object = in_config.m_object;
  this->config.m_object = 0;
  if ( in_config.m_object )
  {
    this->config = in_config;
    _InterlockedExchangeAdd(&in_config.m_object->m_reference_count, 1u);
    m_object = in_config.m_object;
  }
  this->crc = in_crc;
  this->add_to_array = in_add_to_array;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::render::custom_config::destroy(in_config.m_object, in_config.m_object);
  }
}
