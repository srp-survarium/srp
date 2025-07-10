bool __userpurge vostok::render::remove_inappropriate_models::operator()@<al>(
        vostok::render::render_surface_instance *in_model@<esi>,
        vostok::render::remove_inappropriate_models *this)
{
  vostok::render::render_surface *m_render_surface; // eax
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects *p_m_material_effects; // ecx
  float v5; // xmm0_4
  int v6; // edi
  vostok::render::material_effects_instance *v7; // ecx
  vostok::render::material_effects *v8; // eax
  vostok::math::cuboid *v9; // eax
  const vostok::math::float4x4 *v11; // [esp+0h] [ebp-20h]
  vostok::math::aabb bbox; // [esp+8h] [ebp-18h] BYREF

  m_render_surface = in_model->m_render_surface;
  m_object = in_model->m_render_surface->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
  else
    p_m_material_effects = &m_object->m_material_effects;
  if ( p_m_material_effects->has_translucency )
    v5 = FLOAT_0_000099999997;
  else
    v5 = 0.00039999999;
  v6 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 32);
  if ( !v6 )
  {
    v7 = m_render_surface->m_materail_effects_instance.m_object;
    if ( !v7 || s_use_one_material_value )
      v8 = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
    else
      v8 = &v7->m_material_effects;
    if ( v8->has_translucency )
      v5 = 0.00039999999;
    else
      v5 = 0.0016;
  }
  if ( v5 > in_model->m_dynamic_screen_factor
    || *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 288)
    && in_model->m_occluded )
  {
    ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_clipped_dips.value;
    return 1;
  }
  else if ( v6 || !s_test_shadow_in_frustum )
  {
    return 0;
  }
  else
  {
    in_model->m_parent->get_aabb(in_model->m_parent, &bbox);
    v9 = (vostok::math::cuboid *)vostok::math::aabb::modify((vostok::math::aabb *)in_model->m_transform, v11);
    return vostok::math::cuboid::test_inexact(v9, (const vostok::math::aabb *)v9) == intersection_outside;
  }
}
