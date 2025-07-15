void __thiscall survarium::artefact_container_core::load(
        survarium::artefact_container_core *this,
        const vostok::configs::binary_config_value *cfg)
{
  const vostok::configs::binary_config_value *v3; // eax
  float pointer; // xmm0_4

  survarium::usable_object::load(this, cfg);
  v3 = vostok::configs::binary_config_value::operator[](cfg, "artefacts_search_time_sec");
  if ( v3->type == 2 )
    pointer = *(float *)&v3->data.pointer;
  else
    pointer = (float)(int)v3->data.pointer;
  this->m_artefact_search_time_ms = vostok::math::floor(pointer * 1000.0);
}
