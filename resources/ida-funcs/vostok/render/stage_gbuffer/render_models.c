void __userpurge vostok::render::stage_gbuffer::render_models(
        vostok::buffer_vector<vostok::render::render_surface_instance *> *models@<eax>,
        vostok::render::stage_gbuffer *this,
        unsigned int *out_num_rendered,
        bool z_only,
        bool is_foreground)
{
  vostok::render::render_surface_instance *m_begin; // ecx
  bool i; // zf
  int m_object; // ebx
  vostok::render::render_surface_instance *v8; // ecx
  int v9; // edi
  vostok::render::render_surface *v10; // ecx
  vostok::render::stage_gbuffer *v11; // esi
  vostok::render::res_effect *v12; // ecx
  int v13; // eax
  vostok::render::res_geometry *v14; // ecx
  vostok::render::backend *v15; // ecx
  float z; // edi
  vostok::render::base_scene_view *v17; // eax
  unsigned int m_construct_thread_id; // xmm0_4
  unsigned int m_reference_count; // xmm0_4
  vostok::render::shader_constant_host *m_wind_info_parameters; // eax
  const vostok::math::float3 *p_right; // eax
  vostok::render::resource_manager *v22; // ecx
  vostok::render::res_texture *v23; // edi
  vostok::render::backend *v24; // ecx
  vostok::render::resource_manager *v25; // ecx
  vostok::render::resource_manager *v26; // ecx
  vostok::render::res_texture *v27; // edi
  vostok::render::backend *v28; // ecx
  vostok::render::resource_manager *v29; // ecx
  vostok::render::resource_manager *v30; // ecx
  vostok::render::res_texture *v31; // edi
  vostok::render::backend *v32; // ecx
  vostok::render::resource_manager *v33; // ecx
  vostok::render::resource_manager *v34; // ecx
  vostok::render::res_texture *v35; // edi
  vostok::render::backend *v36; // ecx
  int v37; // eax
  float v38; // esi
  bool v39; // [esp+Fh] [ebp-49h]
  bool v40; // [esp+Fh] [ebp-49h]
  bool v41; // [esp+Fh] [ebp-49h]
  bool v42; // [esp+Fh] [ebp-49h]
  vostok::render::material_effects *material_effects; // [esp+10h] [ebp-48h]
  vostok::render::render_surface_instance *v44; // [esp+14h] [ebp-44h]
  int shader_lod_index; // [esp+18h] [ebp-40h]
  boost::intrusive::rbtree_node<void *> *right; // [esp+1Ch] [ebp-3Ch] BYREF
  float v47; // [esp+20h] [ebp-38h] BYREF
  vostok::render::resource_manager *v48; // [esp+24h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v49; // [esp+28h] [ebp-30h] BYREF
  vostok::render::resource_manager *v50; // [esp+2Ch] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v51; // [esp+30h] [ebp-28h] BYREF
  vostok::render::resource_manager *v52; // [esp+34h] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v53; // [esp+38h] [ebp-20h] BYREF
  vostok::render::resource_manager *v54; // [esp+3Ch] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v55; // [esp+40h] [ebp-18h] BYREF
  int v56; // [esp+44h] [ebp-14h]
  vostok::render::render_surface_instance **m_end; // [esp+48h] [ebp-10h]
  unsigned int arg[3]; // [esp+4Ch] [ebp-Ch] BYREF

  m_begin = (vostok::render::render_surface_instance *)models->m_begin;
  m_end = models->m_end;
  for ( i = m_begin == (vostok::render::render_surface_instance *)m_end;
        ;
        i = &v44->m_override_normal_texture == (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_end )
  {
    v44 = m_begin;
    if ( i )
      break;
    m_object = (int)m_begin->m_override_diffuse_texture.m_object;
    if ( vostok::render::render_surface_instance::is_foreground(
           m_begin,
           (int)m_begin->m_override_diffuse_texture.m_object) == is_foreground )
    {
      shader_lod_index = vostok::render::render_surface_instance::get_shader_lod_index(v8, m_object);
      v56 = *(_DWORD *)(m_object + 16);
      v9 = v56;
      v11 = this;
      material_effects = vostok::render::render_surface::get_material_effects(v10, v56);
      vostok::render::renderer_context::set_w(*(const vostok::math::float4x4 **)(m_object + 36), this->m_context);
      v13 = (int)material_effects->m_effects[1].m_object;
      if ( z_only )
      {
        *(_DWORD *)(v13 + 22048) = 9;
        vostok::render::res_effect::apply_pass(v12, v13);
      }
      else
      {
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)(shader_lod_index + this->m_debug_tech_pass_index),
          v13);
      }
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(m_object + 20) + 68))(*(_DWORD *)(m_object + 20), 0);
      vostok::render::res_geometry::apply(v14, *(_DWORD *)(v9 + 4));
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      if ( material_effects->is_wind_swings )
      {
        v17 = this->m_context->m_scene_view.m_object;
        m_construct_thread_id = v17[2].m_construct_thread_id;
        ++v17;
        arg[0] = m_construct_thread_id;
        arg[1] = *((_DWORD *)&v17[1].m_memory_type_data + 1);
        m_reference_count = v17[1].m_reference_count;
        m_wind_info_parameters = this->m_wind_info_parameters;
        arg[2] = m_reference_count;
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          m_wind_info_parameters,
          arg);
        v11 = this;
      }
      if ( !z_only )
      {
        if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shading_quality )
        {
          v47 = s_bm_current_air_resistance;
          p_right = (const vostok::math::float3 *)&v47;
        }
        else
        {
          right = v11->m_context->m_scene_view.m_object[2].grm_satisfaction_tree_hook.right_;
          p_right = (const vostok::math::float3 *)&right;
        }
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v15,
          (vostok::render::constants_handler<1> *)LODWORD(z),
          v11->m_smoothness_multiplier,
          p_right);
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v48,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object);
      v22 = v48;
      v39 = (v48 != 0
           ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
           : 0) != 0;
      if ( v48 )
      {
        i = v48->sh_returned-- == 1;
        if ( i )
          vostok::render::resource_manager::release(
            v22,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::render::res_texture *)v22);
      }
      if ( v39 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v49,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object);
        v23 = v49.m_object;
        vostok::render::backend::set_ps_texture(
          v24,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "t_base",
          v49.m_object);
        if ( v23 )
        {
          i = v23->m_reference_count-- == 1;
          if ( i )
            vostok::render::resource_manager::release(
              v25,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v23);
        }
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v50,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 4));
      v26 = v50;
      v40 = (v50 != 0
           ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
           : 0) != 0;
      if ( v50 )
      {
        i = v50->sh_returned-- == 1;
        if ( i )
          vostok::render::resource_manager::release(
            v26,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::render::res_texture *)v26);
      }
      if ( v40 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v51,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 4));
        v27 = v51.m_object;
        vostok::render::backend::set_ps_texture(
          v28,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "t_normal",
          v51.m_object);
        if ( v27 )
        {
          i = v27->m_reference_count-- == 1;
          if ( i )
            vostok::render::resource_manager::release(
              v29,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v27);
        }
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v52,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 8));
      v30 = v52;
      v41 = (v52 != 0
           ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
           : 0) != 0;
      if ( v52 )
      {
        i = v52->sh_returned-- == 1;
        if ( i )
          vostok::render::resource_manager::release(
            v30,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::render::res_texture *)v30);
      }
      if ( v41 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v53,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 8));
        v31 = v53.m_object;
        vostok::render::backend::set_ps_texture(
          v32,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "t_fresnel",
          v53.m_object);
        if ( v31 )
        {
          i = v31->m_reference_count-- == 1;
          if ( i )
            vostok::render::resource_manager::release(
              v33,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v31);
        }
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v54,
        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 12));
      v34 = v54;
      v42 = (v54 != 0
           ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
           : 0) != 0;
      if ( v54 )
      {
        i = v54->sh_returned-- == 1;
        if ( i )
          vostok::render::resource_manager::release(
            v34,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::render::res_texture *)v34);
      }
      if ( v42 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &v55,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(m_object + 12));
        v35 = v55.m_object;
        vostok::render::backend::set_ps_texture(
          v36,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "t_roughness",
          v55.m_object);
        if ( v35 )
        {
          i = v35->m_reference_count-- == 1;
          if ( i )
            vostok::render::resource_manager::release(
              v34,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v35);
        }
      }
      v37 = v56;
      v38 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      *(_DWORD *)(m_object + 32) = 0;
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)LODWORD(v38),
        3 * *(_DWORD *)(v37 + 24),
        (vostok::render::backend *)v34,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        0);
      ++*out_num_rendered;
    }
    m_begin = (vostok::render::render_surface_instance *)&v44->m_override_normal_texture;
  }
}
