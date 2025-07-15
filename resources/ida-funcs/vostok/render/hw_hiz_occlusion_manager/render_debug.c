void __userpurge vostok::render::hw_hiz_occlusion_manager::render_debug(
        const vostok::math::float3 *in_bounds@<ecx>,
        unsigned int in_num_bounds_and_results@<eax>,
        vostok::render::hw_hiz_occlusion_manager *this,
        vostok::render::renderer_context *in_context,
        const unsigned __int8 *__formal)
{
  vostok::math::float4x4 *v5; // eax
  vostok::render::res_pass *v6; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_shader_technique *v8; // eax
  vostok::render::res_pass *v9; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::res_pass *v11; // edi
  vostok::render::effect_manager *v12; // ecx
  bool v13; // zf
  vostok::render::sphere_occluder_geometry *v14; // ecx
  vostok::render::effect_manager *v15; // [esp-4h] [ebp-FCh]
  const vostok::math::float3 *v16; // [esp+10h] [ebp-E8h]
  unsigned int v17; // [esp+14h] [ebp-E4h]
  vostok::math::float4x4 *v18; // [esp+18h] [ebp-E0h]
  vostok::math::float3 v19; // [esp+1Ch] [ebp-DCh] BYREF
  vostok::math::float3 v20; // [esp+28h] [ebp-D0h] BYREF
  int v21; // [esp+34h] [ebp-C4h]
  vostok::math::float4x4 v22; // [esp+38h] [ebp-C0h] BYREF
  vostok::math::float4x4 v23; // [esp+78h] [ebp-80h] BYREF
  vostok::math::float4x4 v24; // [esp+B8h] [ebp-40h] BYREF

  if ( this->m_hiz_occlusion_effect.m_object && in_num_bounds_and_results )
  {
    v20.x = FLOAT_0_0099999998;
    v20.y = FLOAT_0_0099999998;
    v20.z = FLOAT_0_0099999998;
    v21 = 0;
    v16 = in_bounds;
    v17 = in_num_bounds_and_results;
    while ( 1 )
    {
      v19.x = in_bounds[1].x;
      v19.y = v19.x;
      v19.z = v19.x;
      v18 = vostok::math::create_translation(in_bounds, &v23);
      v5 = vostok::math::create_scale(&v19, &v24);
      vostok::math::mul4x3(v18, v5, &v22);
      vostok::render::renderer_context::set_w(&v22, in_context);
      m_object = this->m_hiz_occlusion_effect.m_object;
      m_object->m_cur_technique = 1;
      v8 = m_object->m_techniques.m_begin[1].m_object;
      v9 = 0;
      if ( v8 )
      {
        v9 = (vostok::render::res_pass *)v8;
        ++v8->m_reference_count;
      }
      m_reference_count = (_DWORD *)v9->m_vs.m_object->m_reference_count;
      v11 = 0;
      if ( m_reference_count )
      {
        v11 = (vostok::render::res_pass *)v9->m_vs.m_object->m_reference_count;
        ++*m_reference_count;
      }
      vostok::render::res_pass::apply(v6, (int)v11);
      if ( v11 )
      {
        v13 = v11->m_reference_count-- == 1;
        if ( v13 )
          vostok::render::effect_manager::delete_pass(
            v12,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            v11);
      }
      v13 = v9->m_reference_count-- == 1;
      if ( v13 )
      {
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v9);
        v12 = v15;
      }
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        (vostok::render::backend *)v12,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        this->m_draw_color_parameter,
        &v20);
      vostok::render::sphere_occluder_geometry::render(v14);
      v16 = (const vostok::math::float3 *)((char *)v16 + 16);
      if ( !--v17 )
        break;
      in_bounds = v16;
    }
  }
}
