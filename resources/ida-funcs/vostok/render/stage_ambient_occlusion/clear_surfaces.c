void __thiscall vostok::render::stage_ambient_occlusion::clear_surfaces(vostok::render::stage_ambient_occlusion *this)
{
  vostok::render::base_scene_view *m_object; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::render::render_target *v4; // eax
  unsigned __int8 v5; // al
  vostok::render::backend *v6; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v7; // eax
  vostok::render::render_target *v8; // eax
  unsigned __int8 v9; // al
  vostok::render::backend *v10; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v11; // eax
  vostok::render::render_target *v12; // eax
  vostok::render::backend *v13; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v14; // eax
  vostok::render::render_target *v15; // eax
  vostok::math::color *v16; // ecx
  vostok::render::backend *v17; // ecx
  unsigned __int8 v18; // [esp+8h] [ebp-18h]
  unsigned int m_value; // [esp+8h] [ebp-18h]
  float v20; // [esp+Ch] [ebp-14h]
  vostok::math::color v21; // [esp+14h] [ebp-Ch] BYREF
  vostok::render::render_target *rt; // [esp+18h] [ebp-8h] BYREF
  char v23; // [esp+1Fh] [ebp-1h]

  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ambient_occlusion_quality
    || (m_object = this->m_context->m_scene_view.m_object, v23 = 1, !m_object[2].m_parent_resources.gapC) )
  {
    v23 = 0;
  }
  if ( this->is_enabled(this) && v23 )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality == 3
      && (float)vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ssao_use_temporal_filtering != 0.0 )
    {
      v3 = vostok::render::renderer_context::get_rt(
             this->m_context,
             rt_ssao_temporal_mask,
             (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v3->m_object,
        0,
        0,
        0);
      v4 = rt;
      if ( rt )
      {
        --rt->m_reference_count;
        if ( !v4->m_reference_count )
          vostok::render::resource_manager::release(
            rt,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      v5 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 1.0);
      vostok::render::backend::clear_render_targets(
        v6,
        LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
        v5);
    }
    v7 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_ssao_accumulator,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v7->m_object,
      0,
      0,
      0);
    v8 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v8->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v9 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 1.0);
    vostok::render::backend::clear_render_targets(
      v10,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
      v9);
    v11 = vostok::render::renderer_context::get_rt(
            this->m_context,
            rt_ssao_accumulator_full_x,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v11->m_object,
      0,
      0,
      0);
    v12 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v12->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v18 = vostok::math::color_rgba(s_bm_current_air_resistance, COERCE_VOSTOK_MATH_(1.0), 1.0, 1.0);
    vostok::render::backend::clear_render_targets(
      v13,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
      v18);
  }
  else
  {
    v14 = vostok::render::renderer_context::get_rt(
            this->m_context,
            rt_ssao_accumulator_full_x,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v14->m_object,
      0,
      0,
      0);
    v15 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v15->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    rt = (vostok::render::render_target *)vostok::math::color_rgba(
                                            s_bm_current_air_resistance,
                                            COERCE_VOSTOK_MATH_(1.0),
                                            0.0,
                                            1.0);
    m_value = vostok::math::color::operator*(v16, (unsigned __int8 *)&rt, &v21, v20)->m_value;
    vostok::render::backend::clear_render_targets(
      v17,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
      m_value);
  }
}
