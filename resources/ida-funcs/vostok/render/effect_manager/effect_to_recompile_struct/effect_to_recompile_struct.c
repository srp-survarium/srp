void __usercall vostok::render::effect_manager::effect_to_recompile_struct::effect_to_recompile_struct(
        vostok::render::effect_manager::effect_to_recompile_struct *this@<eax>,
        const vostok::render::effect_manager::effect_to_recompile_struct *__that@<edx>)
{
  vostok::render::res_effect *m_object; // ecx
  vostok::render::custom_config *v3; // ecx

  this->effect.m_object = 0;
  m_object = __that->effect.m_object;
  if ( __that->effect.m_object )
  {
    this->effect.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  this->descriptor = __that->descriptor;
  this->config.m_object = 0;
  v3 = __that->config.m_object;
  if ( v3 )
  {
    this->config.m_object = v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  this->crc = __that->crc;
}
