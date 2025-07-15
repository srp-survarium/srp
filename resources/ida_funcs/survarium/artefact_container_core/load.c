void __userpurge survarium::artefact_container_core::load(
        survarium::artefact_container_core *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *cfg)
{
  vostok::configs::binary_config_value *v3; // ecx

  survarium::usable_object::load(this, cfg);
  vostok::configs::binary_config_value::operator[](cfg, "artefacts_search_time_sec");
  vostok::configs::binary_config_value::operator float(v3);
  this->m_artefact_search_time_ms = vostok::math::floor(a2 * 1000.0);
}
