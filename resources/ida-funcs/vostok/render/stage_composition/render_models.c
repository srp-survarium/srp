void __userpurge vostok::render::stage_composition::render_models(
        vostok::buffer_vector<vostok::render::render_surface_instance *> *models@<eax>,
        vostok::render::stage_composition *this,
        const vostok::math::float3 *sun_view_dir,
        const vostok::math::float3 *sun_color,
        __int128 sun_intensity)
{
  vostok::render::render_surface_instance **m_begin; // ecx
  vostok::render::base_scene_view *m_object; // eax
  vostok::math::float3 *sun_direction; // eax
  vostok::render::render_surface *v10; // ecx
  float z; // xmm0_4
  vostok::render::render_surface_instance **v12; // eax
  vostok::render::render_surface_instance *v13; // edi
  vostok::render::material_effects *material_effects; // esi
  bool v15; // zf
  vostok::render::res_pass *v16; // ecx
  vostok::render::res_effect *v17; // eax
  vostok::render::res_pass *v18; // eax
  vostok::render::res_pass *v19; // esi
  vostok::render::res_pass *m_reference_count; // eax
  vostok::render::effect_manager *v21; // ecx
  vostok::render::res_pass *v22; // eax
  float v23; // esi
  vostok::render::backend *v24; // ecx
  unsigned int v25; // xmm1_4
  unsigned int v26; // xmm2_4
  vostok::render::backend *v27; // ecx
  vostok::render::backend *v28; // ecx
  vostok::render::backend *v29; // ecx
  vostok::render::backend *v30; // ecx
  const vostok::math::float4x4 *v31; // edx
  vostok::math::float4x4 *v32; // eax
  vostok::render::backend *v33; // ecx
  vostok::render::backend *v34; // ecx
  vostok::render::res_geometry *v35; // ecx
  vostok::render::backend *v36; // ecx
  float v37; // esi
  vostok::render::base_scene_view *v38; // eax
  unsigned int m_construct_thread_id; // xmm0_4
  unsigned int v40; // xmm0_4
  vostok::render::shader_constant_host *m_wind_info_parameters; // eax
  vostok::render::backend *v42; // ecx
  vostok::render::shader_constant_host *m_c_light_direction; // [esp-10h] [ebp-ECh]
  vostok::render::shader_constant_host *m_c_light_color; // [esp-10h] [ebp-ECh]
  vostok::render::shader_constant_host *m_c_diffuse_influence_factor; // [esp-10h] [ebp-ECh]
  vostok::render::shader_constant_host *m_c_specular_influence_factor; // [esp-10h] [ebp-ECh]
  vostok::render::effect_manager *v47; // [esp-Ch] [ebp-E8h]
  vostok::math::float4x4 v48; // [esp+4h] [ebp-D8h] BYREF
  vostok::math::float4x4 v49; // [esp+44h] [ebp-98h] BYREF
  vostok::math::float3 v50; // [esp+84h] [ebp-58h] BYREF
  int v51; // [esp+90h] [ebp-4Ch]
  vostok::math::float3 v52; // [esp+94h] [ebp-48h] BYREF
  float v53; // [esp+A0h] [ebp-3Ch]
  unsigned int arg[3]; // [esp+A4h] [ebp-38h] BYREF
  vostok::math::float3 v55; // [esp+B0h] [ebp-2Ch] BYREF
  vostok::math::float3 v56; // [esp+BCh] [ebp-20h] BYREF
  int v57; // [esp+C8h] [ebp-14h]
  vostok::render::render_surface_instance **m_end; // [esp+CCh] [ebp-10h]
  vostok::render::res_pass *pass; // [esp+D0h] [ebp-Ch]
  volatile int m_thread_id; // [esp+D4h] [ebp-8h]
  vostok::render::render_surface_instance **v61; // [esp+E4h] [ebp+8h]

  m_begin = models->m_begin;
  m_end = models->m_end;
  m_object = this->m_context->m_scene_view.m_object;
  v61 = m_begin;
  m_thread_id = m_object[1].m_parent_resources.m_thread_id;
  sun_direction = vostok::render::environment_properties::get_sun_direction(
                    (vostok::render::environment_properties *)m_begin,
                    (int)&m_object[1],
                    (float *)arg);
  *(_QWORD *)&v56.x = *(_QWORD *)&sun_direction->x;
  z = sun_direction->z;
  v12 = v61;
  v56.z = z;
  v57 = m_thread_id;
  *(_QWORD *)&v50.x = *(_QWORD *)&v56.x;
  v50.z = z;
  v51 = m_thread_id;
  if ( v61 != m_end )
  {
    while ( 1 )
    {
      v13 = *v12;
      m_thread_id = (volatile int)(*v12)->m_render_surface;
      material_effects = vostok::render::render_surface::get_material_effects(v10, m_thread_id);
      v15 = !material_effects->use_subsurface_scattering;
      LODWORD(v55.z) = material_effects;
      if ( !v15 )
      {
        vostok::render::renderer_context::set_w(v13->m_transform, this->m_context);
        v17 = material_effects->m_effects[1].m_object;
        v17->m_cur_technique = 8;
        v18 = (vostok::render::res_pass *)v17->m_techniques.m_begin[8].m_object;
        v19 = 0;
        if ( v18 )
        {
          v19 = v18;
          ++v18->m_reference_count;
        }
        m_reference_count = (vostok::render::res_pass *)v19->m_vs.m_object->m_reference_count;
        pass = 0;
        if ( m_reference_count )
        {
          ++m_reference_count->m_reference_count;
          pass = m_reference_count;
        }
        vostok::render::res_pass::apply(v16, (int)pass);
        v22 = pass;
        if ( pass )
        {
          v15 = pass->m_reference_count-- == 1;
          if ( v15 )
            vostok::render::effect_manager::delete_pass(
              v21,
              (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
              v22);
        }
        v15 = v19->m_reference_count-- == 1;
        if ( v15 )
        {
          vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v19);
          v21 = v47;
        }
        v23 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          (vostok::render::backend *)v21,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          this->m_eye_ray_corner_parameter,
          this->m_context->m_eye_rays);
        *(_QWORD *)&v56.x = *(_QWORD *)&sun_view_dir->x;
        m_c_light_direction = this->m_c_light_direction;
        v56.z = sun_view_dir->z;
        v57 = 0;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v24,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          m_c_light_direction,
          &v56);
        *(float *)&v25 = sun_color->y * *(float *)&sun_intensity;
        *(float *)&v26 = sun_color->z * *(float *)&sun_intensity;
        m_c_light_color = this->m_c_light_color;
        v52.x = sun_color->x * *(float *)&sun_intensity;
        *(_QWORD *)&v52.elements[1] = __PAIR64__(v26, v25);
        v53 = s_bm_current_air_resistance;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v27,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          m_c_light_color,
          &v52);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v28,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          this->m_c_light_intensity,
          (const vostok::math::float3 *)&sun_intensity);
        m_c_diffuse_influence_factor = this->m_c_diffuse_influence_factor;
        v55.x = s_bm_current_air_resistance;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v29,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          m_c_diffuse_influence_factor,
          &v55);
        m_c_specular_influence_factor = this->m_c_specular_influence_factor;
        v55.y = s_bm_current_air_resistance;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v30,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          m_c_specular_influence_factor,
          (vostok::math::float3 *)&v55.elements[1]);
        vostok::math::try_invert4x4(&this->m_context->m_vp, &v49);
        v32 = vostok::math::transpose(v31, &v48);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v33,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          this->m_c_inverted_view_projection_matrix,
          (const vostok::math::float3 *)v32);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v34,
          (vostok::render::constants_handler<1> *)LODWORD(v23),
          this->m_c_shadow_transparency,
          (const vostok::math::float3 *)((char *)&sun_intensity + 4));
        v13->m_parent->set_constants(v13->m_parent, 0);
        vostok::render::res_geometry::apply(v35, *(_DWORD *)(m_thread_id + 4));
        v37 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        if ( *(_BYTE *)(LODWORD(v55.z) + 5) )
        {
          v38 = this->m_context->m_scene_view.m_object;
          m_construct_thread_id = v38[2].m_construct_thread_id;
          ++v38;
          arg[0] = m_construct_thread_id;
          arg[1] = *((_DWORD *)&v38[1].m_memory_type_data + 1);
          v40 = v38[1].m_reference_count;
          m_wind_info_parameters = this->m_wind_info_parameters;
          arg[2] = v40;
          vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            m_wind_info_parameters,
            arg);
        }
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v36,
          (vostok::render::constants_handler<1> *)LODWORD(v37),
          this->m_sun_light_parameters,
          &v50);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(v37),
          3 * *(_DWORD *)(m_thread_id + 24),
          v42,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
      if ( ++v61 == m_end )
        break;
      v12 = v61;
    }
  }
}
