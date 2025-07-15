void __thiscall vostok::render::stage_volume_fog::execute(vostok::render::stage_volume_fog *this)
{
  vostok::math::float4x4 *v2; // ecx
  vostok::render::renderer_context *m_context; // ecx
  int *t; // eax
  vostok::render::res_texture *v5; // ecx
  vostok::render::resource_manager *v6; // ecx
  bool v7; // zf
  int *v8; // eax
  vostok::render::res_texture *v9; // ecx
  vostok::render::resource_manager *v10; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v11; // eax
  float z; // esi
  vostok::render::render_target *v13; // eax
  int v14; // edi
  vostok::render::renderer_context *v15; // esi
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  vostok::render::res_effect *v19; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::math::float4x4 *v21; // ecx
  vostok::render::render_target *v22; // edi
  const vostok::math::float4x4 *v23; // esi
  vostok::render::backend *v24; // ecx
  float *v25; // eax
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // esi
  vostok::math::float4x4 *v32; // eax
  vostok::render::renderer_context *v33; // eax
  float y; // xmm2_4
  float v35; // xmm1_4
  float x; // xmm3_4
  vostok::render::shader_constant_host *m_eye_pos_os_parameter; // eax
  vostok::render::shader_constant_host *m_is_inside_volume_parameter; // eax
  vostok::render::backend *m_buffer_index; // ecx
  vostok::render::backend *v40; // ecx
  vostok::render::backend *v41; // ecx
  float v42; // xmm0_4
  vostok::render::backend *v43; // ecx
  vostok::render::res_geometry *v44; // ecx
  vostok::render::backend *v45; // ecx
  vostok::math::float4x4 *v46; // ecx
  vostok::math::float4x4 *v47; // eax
  vostok::render::backend *v48; // ecx
  vostok::math::float4x4 *v49; // eax
  float v50; // esi
  vostok::render::backend *v51; // ecx
  int v52; // ecx
  vostok::render::shader_constant_host *m_fog_parameters0; // [esp-8h] [ebp-FB8h]
  vostok::render::shader_constant_host *m_fog_parameters1; // [esp-8h] [ebp-FB8h]
  vostok::render::shader_constant_host *m_fog_parameters2; // [esp-8h] [ebp-FB8h]
  vostok::render::shader_constant_host *m_fog_parameters3; // [esp-8h] [ebp-FB8h]
  const D3D11_VIEWPORT *v57; // [esp+0h] [ebp-FB0h]
  const D3D11_VIEWPORT *v58; // [esp+0h] [ebp-FB0h]
  vostok::render::render_target *rt; // [esp+Ch] [ebp-FA4h] BYREF
  unsigned int v60; // [esp+10h] [ebp-FA0h] BYREF
  pix_event_wrapper_dx11 wszName[5]; // [esp+17h] [ebp-F99h] BYREF
  const vostok::math::float3 *m_eye_rays; // [esp+1Ch] [ebp-F94h]
  vostok::math::float4x4 v63; // [esp+20h] [ebp-F90h] BYREF
  unsigned int arg[3]; // [esp+64h] [ebp-F4Ch] BYREF
  vostok::math::float3 v65; // [esp+70h] [ebp-F40h] BYREF
  D3D11_USAGE m_memory_usage_type; // [esp+7Ch] [ebp-F34h]
  vostok::math::float3 v67; // [esp+80h] [ebp-F30h] BYREF
  int v68; // [esp+8Ch] [ebp-F24h]
  vostok::math::float3 v69; // [esp+90h] [ebp-F20h] BYREF
  int v70; // [esp+9Ch] [ebp-F14h]
  vostok::math::float3 v71; // [esp+A0h] [ebp-F10h] BYREF
  ID3D11Texture3D *m_surface_3d; // [esp+ACh] [ebp-F04h]
  D3D11_VIEWPORT v73; // [esp+B0h] [ebp-F00h] BYREF
  D3D11_VIEWPORT v74; // [esp+C8h] [ebp-EE8h] BYREF
  vostok::math::float4x4 v75; // [esp+E0h] [ebp-ED0h] BYREF
  vostok::fixed_vector<vostok::render::volume_fog_parameters,32> v76; // [esp+120h] [ebp-E90h] BYREF
  char v77; // [esp+FACh] [ebp-4h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_volume_fog");
  if ( this->is_effects_ready(this) )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_volume_fog_stage && this->is_enabled(this) )
    {
      m_eye_rays = this->m_context->m_eye_rays;
      v76.m_begin = (vostok::render::volume_fog_parameters *)v76.m_buffer;
      v76.m_end = (vostok::render::volume_fog_parameters *)v76.m_buffer;
      v76.m_max_end = (vostok::render::volume_fog_parameters *)&v77;
      vostok::render::scene::select_volume_fog_instances(
        (vostok::render::scene *)&this->m_context->m_vp,
        (int)this->m_context->m_scene,
        &this->m_context->m_vp,
        &v76);
      if ( v76.m_begin != v76.m_end )
      {
        *(_DWORD *)&wszName[1] = v76.m_end;
        qmemcpy(
          (void *)&v74,
          (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
          sizeof(v74));
        m_context = this->m_context;
        v73.TopLeftX = 0.0;
        v73.TopLeftY = 0.0;
        t = (int *)vostok::render::renderer_context::get_t(
                     m_context,
                     rt_generic_0,
                     (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
        v60 = vostok::render::res_texture::width(v5, *t);
        v73.Width = (float)v60;
        if ( rt )
        {
          v7 = rt->m_name.m_pointer.m_object-- == (vostok::strings::shared::profile *)1;
          if ( v7 )
            vostok::render::resource_manager::release(
              v6,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              (vostok::render::res_texture *)rt);
        }
        v8 = (int *)vostok::render::renderer_context::get_t(
                      this->m_context,
                      rt_generic_0,
                      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
        v60 = vostok::render::res_texture::height(v9, *v8);
        v73.Height = (float)v60;
        if ( rt )
        {
          v7 = rt->m_name.m_pointer.m_object-- == (vostok::strings::shared::profile *)1;
          if ( v7 )
            vostok::render::resource_manager::release(
              v10,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              (vostok::render::res_texture *)rt);
        }
        v73.MinDepth = 0.0;
        v73.MaxDepth = s_bm_current_air_resistance;
        vostok::render::backend::set_viewports(
          (vostok::render::backend *)v10,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &v73,
          v57);
        v11 = vostok::render::renderer_context::get_rt(
                this->m_context,
                rt_generic_0,
                (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_render_targets(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          v11->m_object,
          0,
          0,
          0);
        v13 = rt;
        if ( rt )
        {
          --rt->m_reference_count;
          if ( !v13->m_reference_count )
          {
            vostok::render::resource_manager::release(
              rt,
              vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
            z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          }
        }
        v14 = *(_DWORD *)(LODWORD(z) + 7440);
        v7 = *(_DWORD *)(LODWORD(z) + 7384) == v14;
        *(_DWORD *)(LODWORD(z) + 7384) = v14;
        *(_BYTE *)(LODWORD(z) + 117) |= !v7;
        qmemcpy(&v63, &this->m_context->m_p, sizeof(v63));
        v15 = this->m_context;
        v16 = v15->m_near_far_invn_invf.y - 0.000099999997;
        v17 = v15->m_near_far_invn_invf.y / v16;
        v18 = (float)(v16 / v15->m_near_far_invn_invf.y) * -0.000099999997;
        v63.k.z = v17;
        v63.c.z = v18;
        vostok::render::renderer_context::push_set_p(0, (int)v15, &v63);
        if ( v76.m_begin != *(vostok::render::volume_fog_parameters **)&wszName[1] )
        {
          v65.y = 0.0;
          v70 = 0;
          v68 = 0;
          rt = (vostok::render::render_target *)&v76.m_begin->fog_color.elements[2];
          do
          {
            m_object = this->m_exponential_volume_fog_effect.m_object;
            m_object->m_cur_technique = 0;
            vostok::render::res_effect::apply_pass(v19, (int)m_object);
            qmemcpy(&v63, vostok::math::float4x4::identity(v21, &v75), sizeof(v63));
            v22 = rt;
            v23 = (const vostok::math::float4x4 *)&rt[-1];
            vostok::math::float4x4::try_invert((const vostok::math::float4x4 *)&rt[-1], &v63);
            vostok::render::renderer_context::set_w(v23, this->m_context);
            v25 = (float *)this->m_context;
            v26 = v25[5284];
            v27 = v25[5285];
            v25 += 5283;
            v28 = (float)((float)((float)(*v25 * v63.i.x) + (float)(v63.j.x * v26)) + (float)(v63.k.x * v27)) + v63.c.x;
            v29 = (float)((float)((float)(v63.k.y * v27) + (float)(v63.i.y * *v25)) + (float)(v63.j.y * v26)) + v63.c.y;
            v30 = (float)((float)((float)(v63.i.z * *v25) + (float)(v63.j.z * v26)) + (float)(v63.k.z * v27)) + v63.c.z;
            v60 = v28 >= -1.0
               && v29 >= -1.0
               && v30 >= -1.0
               && s_bm_current_air_resistance >= v28
               && s_bm_current_air_resistance >= v29
               && s_bm_current_air_resistance >= v30;
            v31 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v24,
              (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              this->m_eye_ray_corner_parameter,
              m_eye_rays);
            v32 = vostok::math::transpose(&v63, &v75);
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v31),
              this->m_inverted_world_matrix_parameter,
              (const unsigned int *)v32);
            v33 = this->m_context;
            y = v33->m_view_pos.y;
            v35 = v33->m_view_pos.z;
            x = v33->m_view_pos.x;
            *(float *)arg = (float)((float)((float)(x * v63.i.x) + (float)(v63.j.x * y)) + (float)(v63.k.x * v35))
                          + v63.c.x;
            *(float *)&arg[1] = (float)((float)((float)(v63.k.y * v35) + (float)(v63.i.y * x)) + (float)(v63.j.y * y))
                              + v63.c.y;
            m_eye_pos_os_parameter = this->m_eye_pos_os_parameter;
            *(float *)&arg[2] = (float)((float)((float)(v63.i.z * x) + (float)(v63.j.z * y)) + (float)(v63.k.z * v35))
                              + v63.c.z;
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v31),
              m_eye_pos_os_parameter,
              arg);
            vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
              (vostok::render::backend *)LODWORD(v31),
              this->m_eye_pos_ws_parameter,
              (const unsigned int *)&this->m_context->m_view_pos);
            m_is_inside_volume_parameter = this->m_is_inside_volume_parameter;
            m_buffer_index = (vostok::render::backend *)m_is_inside_volume_parameter->m_shader_slots[0].m_buffer_index;
            if ( m_is_inside_volume_parameter->m_update_markers[0] == *(_DWORD *)(LODWORD(v31) + 7540)
              && m_buffer_index != (vostok::render::backend *)0xFFFF )
            {
              vostok::render::shader_constant_buffer::set_memory(
                *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*(_DWORD *)(LODWORD(v31) + 432) + 784)
                                                           + 4 * (_DWORD)m_buffer_index),
                m_is_inside_volume_parameter->m_shader_slots[0].m_slot_index,
                (char *)&v60,
                (unsigned __int8)m_is_inside_volume_parameter->m_shader_slots[0].m_class_id);
              v22 = rt;
            }
            ++*(_DWORD *)(LODWORD(v31) + 7420);
            *(_QWORD *)&v71.x = *(_QWORD *)&v22[-1].m_is_registered;
            m_fog_parameters0 = this->m_fog_parameters0;
            LODWORD(v71.z) = v22->m_reference_count;
            m_surface_3d = v22->m_surface_3d;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              m_buffer_index,
              (vostok::render::constants_handler<1> *)LODWORD(v31),
              m_fog_parameters0,
              &v71);
            LODWORD(v65.x) = v22->m_rt;
            m_fog_parameters1 = this->m_fog_parameters1;
            LODWORD(v65.z) = v22->m_name.m_pointer.m_object;
            m_memory_usage_type = v22->m_memory_usage_type;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v40,
              (vostok::render::constants_handler<1> *)LODWORD(v31),
              m_fog_parameters1,
              &v65);
            v42 = epsilon_3_4;
            if ( *(float *)&v22->m_texture.m_object > 0.001 )
              v42 = *(float *)&v22->m_texture.m_object;
            LODWORD(v69.x) = v22->m_zrt;
            m_fog_parameters2 = this->m_fog_parameters2;
            *(_QWORD *)&v69.elements[1] = __PAIR64__(v22->m_width, s_bm_current_air_resistance / v42);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v41,
              (vostok::render::constants_handler<1> *)LODWORD(v31),
              m_fog_parameters2,
              &v69);
            LODWORD(v67.x) = v22->m_surface;
            m_fog_parameters3 = this->m_fog_parameters3;
            LODWORD(v67.y) = v22->m_format;
            LODWORD(v67.z) = v22->m_height;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v43,
              (vostok::render::constants_handler<1> *)LODWORD(v31),
              m_fog_parameters3,
              &v67);
            vostok::render::res_geometry::apply(v44, (int)this->m_fog_box_geometry.m_geometry.m_object);
            vostok::render::backend::render_indexed(
              (vostok::render::backend *)LODWORD(v31),
              0x24u,
              v45,
              D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
              0,
              0);
            rt = (vostok::render::render_target *)((char *)rt + 116);
          }
          while ( &rt[-1] != *(vostok::render::render_target **)&wszName[1] );
        }
        vostok::render::renderer_context::pop_p((vostok::render::renderer_context *)v19, this->m_context);
        v47 = vostok::math::float4x4::identity(v46, &v75);
        vostok::render::renderer_context::set_w(v47, this->m_context);
        vostok::render::backend::set_viewports(
          v48,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &v74,
          v58);
      }
      v49 = vostok::math::float4x4::identity(v2, &v75);
      vostok::render::renderer_context::set_w(v49, this->m_context);
      v50 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::reset_render_targets(
        v51,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v52 = *(_DWORD *)(LODWORD(v50) + 7440);
      v7 = *(_DWORD *)(LODWORD(v50) + 7384) == v52;
      *(_DWORD *)(LODWORD(v50) + 7384) = v52;
      *(_BYTE *)(LODWORD(v50) + 117) |= !v7;
      v76.m_end = v76.m_begin;
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
}
