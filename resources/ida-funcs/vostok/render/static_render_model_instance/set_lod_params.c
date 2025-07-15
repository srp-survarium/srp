void __thiscall vostok::render::static_render_model_instance::set_lod_params(
        vostok::render::static_render_model_instance *this,
        unsigned __int8 type,
        bool use_default,
        float p0,
        float p1,
        float p2)
{
  vostok::render::model_lods_descriptor *m_lods_descriptor; // eax

  m_lods_descriptor = this->m_original.m_object->m_lods_descriptor;
  m_lods_descriptor->m_lod_custom_params[0] = p0;
  m_lods_descriptor->m_lod_calc_type = type;
  m_lods_descriptor->m_lod_custom_params[1] = p1;
  m_lods_descriptor->m_lod_params_default = use_default;
  m_lods_descriptor->m_lod_custom_params[2] = p2;
}
