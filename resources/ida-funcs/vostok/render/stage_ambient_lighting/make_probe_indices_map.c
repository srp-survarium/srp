void __userpurge vostok::render::stage_ambient_lighting::make_probe_indices_map(
        vostok::fixed_vector<vostok::render::environment_probe *,1024> *visible_probes@<eax>,
        pix_event_wrapper_dx11 *a2@<ecx>,
        vostok::render::environment_probe **this)
{
  vostok::render::environment_probe **v3; // ebx
  vostok::render::renderer_context *v5; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  float z; // esi
  vostok::render::render_target *v8; // eax
  int v9; // edi
  bool v10; // zf
  vostok::render::environment_probe **v11; // eax
  vostok::render::environment_probe *v12; // eax
  float inner_radius; // xmm0_4
  vostok::math::float4x4 *v14; // eax
  vostok::math::float4x4 *p_inner_box_transform; // esi
  vostok::render::res_pass *v16; // ecx
  vostok::render::environment_probe *v17; // eax
  vostok::render::res_pass *v18; // esi
  vostok::render::res_pass *v19; // eax
  vostok::render::res_pass *v20; // edi
  _DWORD *m_reference_count; // eax
  vostok::render::effect_manager *v22; // ecx
  vostok::render::backend *v23; // ecx
  vostok::render::backend *v24; // ecx
  float v25; // esi
  vostok::render::res_geometry *v26; // ecx
  vostok::render::backend *v27; // ecx
  vostok::render::backend *v28; // ecx
  vostok::render::renderer_context *v29; // [esp-4h] [ebp-138h]
  vostok::render::effect_manager *v30; // [esp-4h] [ebp-138h]
  char v31[64]; // [esp+10h] [ebp-124h] BYREF
  vostok::math::float4x4 v32; // [esp+50h] [ebp-E4h] BYREF
  vostok::math::float4x4 v33; // [esp+90h] [ebp-A4h] BYREF
  vostok::math::float4x4 v34; // [esp+D0h] [ebp-64h] BYREF
  vostok::math::float3 v35; // [esp+114h] [ebp-20h] BYREF
  vostok::render::environment_probe **m_end; // [esp+120h] [ebp-14h]
  vostok::render::environment_probe *v37; // [esp+124h] [ebp-10h]
  vostok::math::float4x4 *i; // [esp+128h] [ebp-Ch]
  vostok::render::render_target *rt[2]; // [esp+12Ch] [ebp-8h] BYREF

  v3 = this;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    a2,
    (pix_event_wrapper_dx11 *)&this + 3,
    (int)L"make_probe_indices_map");
  v5 = (vostok::render::renderer_context *)v3[1];
  this = visible_probes->m_begin;
  m_end = visible_probes->m_end;
  v6 = vostok::render::renderer_context::get_rt(
         v5,
         rt_probe_indices,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)rt);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v6->m_object,
    0,
    0,
    0);
  v8 = rt[0];
  if ( rt[0] )
  {
    --rt[0]->m_reference_count;
    if ( !v8->m_reference_count )
    {
      vostok::render::resource_manager::release(rt[0], vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    }
  }
  v9 = *(_DWORD *)(LODWORD(z) + 7440);
  v10 = *(_DWORD *)(LODWORD(z) + 7384) == v9;
  *(_DWORD *)(LODWORD(z) + 7384) = v9;
  v11 = this;
  *(_BYTE *)(LODWORD(z) + 117) |= !v10;
  rt[0] = 0;
  if ( v11 != m_end )
  {
    while ( 1 )
    {
      v12 = *v11;
      v10 = v12->m_properties.geometry == 0;
      inner_radius = v12->m_properties.inner_radius;
      v37 = v12;
      if ( v10 )
      {
        v35.x = inner_radius;
        v35.y = inner_radius;
        v35.z = inner_radius;
        i = vostok::math::create_translation(&v12->m_properties.location, &v32);
        v14 = vostok::math::create_scale(&v35, (vostok::math::float4x4 *)v31);
        vostok::math::mul4x3(i, v14, &v33);
        p_inner_box_transform = &v33;
      }
      else
      {
        p_inner_box_transform = &v12->m_properties.inner_box_transform;
      }
      v29 = (vostok::render::renderer_context *)v3[1];
      qmemcpy(&v34, p_inner_box_transform, sizeof(v34));
      vostok::render::renderer_context::set_w(&v34, v29);
      v17 = v3[4];
      v18 = 0;
      v17[35].m_properties.inner_box_transform.i.x = 0.0;
      v19 = *(vostok::render::res_pass **)LODWORD(v17[35].m_properties.inner_box_transform.i.y);
      v20 = 0;
      if ( v19 )
      {
        v20 = v19;
        ++v19->m_reference_count;
      }
      m_reference_count = (_DWORD *)v20->m_vs.m_object->m_reference_count;
      if ( m_reference_count )
      {
        v18 = (vostok::render::res_pass *)v20->m_vs.m_object->m_reference_count;
        ++*m_reference_count;
      }
      vostok::render::res_pass::apply(v16, (int)v18);
      if ( v18 )
      {
        v10 = v18->m_reference_count-- == 1;
        if ( v10 )
          vostok::render::effect_manager::delete_pass(
            v22,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            v18);
      }
      v10 = v20->m_reference_count-- == 1;
      if ( v10 )
      {
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v20);
        v22 = v30;
      }
      if ( v37->m_properties.geometry )
      {
        vostok::render::res_geometry::apply((vostok::render::res_geometry *)v22, (int)v3[64]);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          0x24u,
          v24,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
      else
      {
        vostok::render::res_geometry::apply((vostok::render::res_geometry *)v22, (int)v3[61]);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          0x21Cu,
          v23,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
      for ( i = 0; (unsigned int)i < 2; i = (vostok::math::float4x4 *)((char *)i + 1) )
      {
        vostok::render::res_effect::apply((vostok::render::res_effect *)i, (int)v3[9]);
        v25 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<unsigned int>(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v3[58],
          (const int *)rt);
        if ( v37->m_properties.geometry )
        {
          vostok::render::res_geometry::apply(v26, (int)v3[64]);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(v25),
            0x24u,
            v28,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
        }
        else
        {
          vostok::render::res_geometry::apply(v26, (int)v3[61]);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(v25),
            0x21Cu,
            v27,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
        }
      }
      ++this;
      ++rt[0];
      if ( this == m_end )
        break;
      v11 = this;
    }
  }
  D3DPERF_EndEvent();
}
