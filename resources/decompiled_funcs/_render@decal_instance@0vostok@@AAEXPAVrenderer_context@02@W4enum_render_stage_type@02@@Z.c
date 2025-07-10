void __userpurge vostok::render::decal_instance::render(
        vostok::render::decal_instance *this@<ecx>,
        float a2@<ebx>,
        float a3@<ebp>,
        vostok::render::decal_instance *a4@<esi>,
        vostok::render::renderer_context *context,
        vostok::render::enum_render_stage_type stage_type)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v7; // edi
  int v8; // eax
  _DWORD *v9; // eax
  vostok::render::decal_shader_constants_and_geometry *m_waiting_for_bind_action; // edi
  vostok::math::float4x4 *world_to_decal_matrix; // eax
  vostok::render::decal_instance *v12; // ecx
  const vostok::math::float4x4 *decal_view_matrix; // [esp-4h] [ebp-98h]
  float alpha_angle; // [esp+0h] [ebp-94h]
  float clip_angle; // [esp+4h] [ebp-90h]
  unsigned int v16; // [esp+8h] [ebp-8Ch]
  const vostok::math::float3 *v17; // [esp+8h] [ebp-8Ch]
  const vostok::math::float4x4 *v18; // [esp+Ch] [ebp-88h]
  vostok::math::float4x4 result; // [esp+10h] [ebp-84h] BYREF
  vostok::math::float4x4 v20; // [esp+50h] [ebp-44h] BYREF

  m_object = a4->m_properties.material.m_object;
  if ( m_object )
  {
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    v7 = m_object + 1;
    a2 = COERCE_FLOAT(_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF));
    if ( a2 == 0.0 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v8 = (int)v7;
  }
  else
  {
    v8 = dword_4BB07F4;
  }
  v9 = *(_DWORD **)(v8 + 4 * stage_type + 796);
  if ( (unsigned int)((v9[71] - v9[70]) >> 2) > 1 )
  {
    v9[69] = 1;
    if ( vostok::render::res_effect::apply_pass((vostok::render::res_effect *)stage_type, v16) )
    {
      m_waiting_for_bind_action = (vostok::render::decal_shader_constants_and_geometry *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_waiting_for_bind_action;
      clip_angle = a4->m_properties.clip_angle;
      alpha_angle = a4->m_properties.alpha_angle;
      decal_view_matrix = vostok::render::get_decal_view_matrix(&result, a4);
      world_to_decal_matrix = vostok::render::get_world_to_decal_matrix(
                                a2,
                                a3,
                                *(float *)&m_waiting_for_bind_action,
                                *(float *)&a4,
                                &v20,
                                a4);
      vostok::render::decal_shader_constants_and_geometry::set(
        m_waiting_for_bind_action,
        world_to_decal_matrix,
        context,
        decal_view_matrix,
        alpha_angle,
        clip_angle,
        v17,
        v18);
      vostok::render::decal_instance::render_geometry(v12);
    }
  }
}
