void __thiscall vostok::render::skeleton_render_model_instance::set_constants(
        vostok::render::skeleton_render_model_instance *this,
        bool shadow_stage)
{
  vostok::fixed_vector<vostok::math::float4x4,128> *p_m_shadow_bones_matrices; // eax
  float z; // esi
  vostok::resources::resource_ptr<vostok::render::skeleton_render_model,vostok::resources::unmanaged_intrusive_base> *p_m_original; // edi
  unsigned int v6; // [esp+0h] [ebp-Ch]
  unsigned int v7; // [esp+0h] [ebp-Ch]

  p_m_shadow_bones_matrices = &this->m_shadow_bones_matrices;
  if ( !shadow_stage )
    p_m_shadow_bones_matrices = &this->m_bones_matrices;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  p_m_original = &this->m_original;
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    this->m_original.m_object->m_bones_matrices_shader_constant,
    p_m_shadow_bones_matrices->m_begin,
    v6);
  if ( !shadow_stage )
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(z),
      p_m_original->m_object->m_prev_bones_matrices_shader_constant,
      this->m_prev_bones_matrices.m_begin,
      v7);
}
