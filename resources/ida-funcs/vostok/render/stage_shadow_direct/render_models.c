void __userpurge vostok::render::stage_shadow_direct::render_models(
        unsigned int cascade_index@<eax>,
        vostok::render::renderer_context *a2@<ecx>,
        vostok::render::stage_shadow_direct *this,
        vostok::render::res_pass *caster_models,
        const vostok::math::float3 *viewer_pos,
        bool no_wind)
{
  char *v7; // edi
  vostok::render::renderer_context *v8; // ecx
  unsigned int m_reference_count; // eax
  vostok::render::res_state *m_object; // ecx
  int v11; // esi
  int v12; // eax
  vostok::render::res_pass *v13; // ecx
  vostok::render::res_effect *v14; // eax
  vostok::render::res_pass *v15; // eax
  vostok::render::res_pass *v16; // edi
  vostok::render::res_pass *v17; // eax
  vostok::render::effect_manager *v18; // ecx
  bool v19; // zf
  vostok::render::res_geometry *v20; // ecx
  int v21; // edi
  float z; // edi
  vostok::render::base_scene_view *v23; // eax
  unsigned int m_construct_thread_id; // xmm0_4
  unsigned int *v25; // eax
  vostok::render::backend *v26; // ecx
  vostok::render::renderer_context *v27; // ecx
  _DWORD v28[3]; // [esp+Ch] [ebp-28h] BYREF
  unsigned int arg[3]; // [esp+18h] [ebp-1Ch] BYREF
  vostok::render::res_state *v30; // [esp+24h] [ebp-10h]
  vostok::render::material_effects *material_effects; // [esp+28h] [ebp-Ch]
  _DWORD *v32; // [esp+2Ch] [ebp-8h]
  int v33; // [esp+30h] [ebp-4h]
  unsigned int v34; // [esp+3Ch] [ebp+8h]
  vostok::render::res_pass *pass; // [esp+40h] [ebp+Ch]

  v7 = (char *)this + 64 * cascade_index;
  vostok::render::renderer_context::push_set_v(
    a2,
    (int)this->m_context,
    (const vostok::math::float4x4 *)&v7[(_DWORD)&loc_406F3 + 5]);
  vostok::render::renderer_context::push_set_p(
    v8,
    (int)this->m_context,
    (const vostok::math::float4x4 *)&v7[(_DWORD)&loc_407F4 + 4]);
  m_reference_count = caster_models->m_reference_count;
  m_object = caster_models->m_state.m_object;
  v34 = m_reference_count;
  v30 = m_object;
  if ( (vostok::render::res_state *)m_reference_count != m_object )
  {
    while ( 1 )
    {
      v11 = *(_DWORD *)m_reference_count;
      v12 = *(_DWORD *)(*(_DWORD *)m_reference_count + 16);
      v33 = v11;
      v32 = (_DWORD *)v12;
      material_effects = vostok::render::render_surface::get_material_effects(
                           (vostok::render::render_surface *)m_object,
                           v12);
      v14 = material_effects->m_effects[27].m_object;
      v14->m_cur_technique = 0;
      v15 = (vostok::render::res_pass *)v14->m_techniques.m_begin->m_object;
      v16 = 0;
      if ( v15 )
      {
        v16 = v15;
        ++v15->m_reference_count;
      }
      v17 = (vostok::render::res_pass *)v16->m_vs.m_object->m_reference_count;
      pass = 0;
      if ( v17 )
      {
        ++v17->m_reference_count;
        pass = v17;
      }
      vostok::render::res_pass::apply(v13, (int)pass);
      if ( pass )
      {
        v19 = pass->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::effect_manager::delete_pass(
            v18,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            pass);
      }
      v19 = v16->m_reference_count-- == 1;
      if ( v19 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v16);
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v11 + 20) + 68))(*(_DWORD *)(v11 + 20), 1);
      v21 = v32[2];
      if ( !v21 )
        v21 = v32[1];
      vostok::render::res_geometry::apply(v20, v21);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      if ( material_effects->is_wind_swings )
      {
        v23 = this->m_context->m_scene_view.m_object;
        m_construct_thread_id = v23[2].m_construct_thread_id;
        ++v23;
        v28[0] = m_construct_thread_id;
        v28[1] = *((_DWORD *)&v23[1].m_memory_type_data + 1);
        v28[2] = v23[1].m_reference_count;
        if ( (_BYTE)viewer_pos )
        {
          *(float *)arg = s_bm_current_air_resistance;
          *(float *)&arg[1] = s_bm_current_air_resistance;
          arg[2] = 0;
          v25 = arg;
        }
        else
        {
          v25 = v28;
        }
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          *(const vostok::render::shader_constant_host **)((char *)&this->__vftable + (_DWORD)&loc_40163 + 1),
          v25);
        v11 = v33;
      }
      vostok::render::renderer_context::set_w(*(const vostok::math::float4x4 **)(v11 + 40), this->m_context);
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(z),
        3 * v32[6],
        v26,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        0);
      v34 += 8;
      if ( (vostok::render::res_state *)v34 == v30 )
        break;
      m_reference_count = v34;
    }
  }
  vostok::render::renderer_context::pop_v((vostok::render::renderer_context *)m_object, (int)this->m_context);
  vostok::render::renderer_context::pop_p(v27, this->m_context);
}
