void __thiscall vostok::render::stage_shadow_mask::execute(vostok::render::stage_shadow_mask *this)
{
  vostok::render::environment_properties *v2; // ecx
  vostok::render::renderer_context *m_context; // edi
  vostok::render::base_scene_view *m_object; // eax
  float v5; // xmm1_4
  float z; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  vostok::math::float4x4 *v10; // ecx
  bool v11; // zf
  vostok::math::float4x4 *v12; // eax
  int v13; // eax
  float *p_y; // eax
  int v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float *v19; // edi
  vostok::render::res_geometry *v20; // ecx
  vostok::render::res_effect *v21; // eax
  vostok::render::res_effect *v22; // ecx
  float v23; // esi
  int v24; // eax
  int *v25; // edi
  vostok::render::backend *v26; // ecx
  vostok::render::base_scene_view *v27; // eax
  vostok::render::res_effect *v28; // ecx
  vostok::render::res_texture *v29; // eax
  float y; // esi
  BOOL v31; // ecx
  vostok::render::res_effect *v32; // eax
  int v33; // eax
  int z_low; // esi
  vostok::render::backend *v35; // ecx
  const vostok::math::float4x4 *view2shadow; // eax
  vostok::math::float4x4 *v37; // eax
  vostok::render::backend *v38; // ecx
  const vostok::math::float4x4 *v39; // edx
  vostok::math::float4x4 *v40; // eax
  float v41; // esi
  vostok::render::backend *v42; // ecx
  vostok::render::backend *v43; // ecx
  vostok::render::resource_manager *v44; // ecx
  float *v45; // esi
  vostok::render::base_scene_view *v46; // eax
  vostok::render::resource_intrusive_base *v47; // eax
  unsigned int v48; // xmm0_4
  unsigned int v49; // xmm1_4
  float v50; // xmm2_4
  vostok::render::res_texture **sky_shadows_texture; // eax
  vostok::render::backend *v52; // ecx
  vostok::render::resource_intrusive_base *v53; // eax
  vostok::render::system_renderer *v54; // esi
  vostok::render::render_target *v55; // ecx
  vostok::render::res_effect *v56; // eax
  vostok::render::system_renderer *v57; // ecx
  vostok::render::backend *v58; // ecx
  vostok::render::render_target *v59; // [esp-1Ch] [ebp-174h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v60; // [esp-18h] [ebp-170h] BYREF
  vostok::render::render_target *v61; // [esp-14h] [ebp-16Ch]
  vostok::render::render_target *v62; // [esp-10h] [ebp-168h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v63; // [esp-Ch] [ebp-164h]
  vostok::render::shader_constant_host *m_c_sky_shadow_parameters; // [esp-8h] [ebp-160h]
  unsigned int v65; // [esp-4h] [ebp-15Ch]
  float v66; // [esp+0h] [ebp-158h] BYREF
  float v67; // [esp+4h] [ebp-154h]
  float v68; // [esp+8h] [ebp-150h]
  float v69; // [esp+Ch] [ebp-14Ch]
  pix_event_wrapper_dx11 wszName[5]; // [esp+13h] [ebp-145h] BYREF
  vostok::render::backend *v71; // [esp+18h] [ebp-140h]
  vostok::render::res_texture *v72; // [esp+1Ch] [ebp-13Ch] BYREF
  int v73; // [esp+20h] [ebp-138h]
  unsigned int v_offset; // [esp+24h] [ebp-134h] BYREF
  int v75; // [esp+28h] [ebp-130h] BYREF
  vostok::math::float3 v76; // [esp+2Ch] [ebp-12Ch] BYREF
  float v77; // [esp+38h] [ebp-120h] BYREF
  float v78; // [esp+3Ch] [ebp-11Ch]
  float v79; // [esp+40h] [ebp-118h]
  vostok::math::float3 v80; // [esp+44h] [ebp-114h] BYREF
  int v81; // [esp+50h] [ebp-108h]
  vostok::math::float3 v82; // [esp+54h] [ebp-104h] BYREF
  int v83; // [esp+60h] [ebp-F8h]
  int v84; // [esp+64h] [ebp-F4h]
  int v85; // [esp+68h] [ebp-F0h]
  vostok::math::float3 v86; // [esp+6Ch] [ebp-ECh] BYREF
  vostok::math::float4x4 v87; // [esp+78h] [ebp-E0h] BYREF
  float v88; // [esp+B8h] [ebp-A0h]
  float v89; // [esp+BCh] [ebp-9Ch]
  float v90; // [esp+C0h] [ebp-98h]
  float v91; // [esp+C4h] [ebp-94h]
  float v92; // [esp+C8h] [ebp-90h]
  float v93; // [esp+CCh] [ebp-8Ch]
  float v94; // [esp+D0h] [ebp-88h]
  float v95; // [esp+D4h] [ebp-84h]
  vostok::math::float4x4 v96; // [esp+D8h] [ebp-80h] BYREF
  vostok::math::float4x4 v97; // [esp+118h] [ebp-40h] BYREF

  v73 = 0;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_shadow_mask");
  if ( this->is_effects_ready(this) )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_mask_stage && this->is_enabled(this) )
    {
      m_context = this->m_context;
      m_object = m_context->m_scene_view.m_object;
      if ( LOBYTE(m_object[1].m_children_resources.m_last)
        && BYTE1(m_object[1].m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type) )
      {
        vostok::render::environment_properties::get_sun_direction(v2, (int)&m_object[1], &v76.x);
        v5 = m_context->m_v.j.y * v76.y;
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        v86.x = (float)((float)(m_context->m_v.k.x * v76.z) + (float)(m_context->m_v.j.x * v76.y))
              + (float)(m_context->m_v.i.x * v76.x);
        v7 = (float)((float)(m_context->m_v.k.y * v76.z) + v5) + (float)(m_context->m_v.i.y * v76.x);
        v8 = m_context->m_v.j.z * v76.y;
        v86.y = v7;
        v86.z = (float)((float)(m_context->m_v.k.z * v76.z) + v8) + (float)(m_context->m_v.i.z * v76.x);
        vostok::render::backend::set_render_targets(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          0,
          0,
          0,
          0);
        v9 = s_bm_current_air_resistance;
        v10 = *(vostok::math::float4x4 **)(LODWORD(z) + 7440);
        v11 = *(_DWORD *)(LODWORD(z) + 7384) == (_DWORD)v10;
        *(_DWORD *)(LODWORD(z) + 7384) = v10;
        *(_BYTE *)(LODWORD(z) + 117) |= !v11;
        *(_QWORD *)&v87.i.x = __PAIR64__(LODWORD(v9), LODWORD(FLOAT_N1_0));
        *(_QWORD *)&v87.lines[0].elements[2] = __PAIR64__(LODWORD(v9), LODWORD(FLOAT_N1_0));
        v87.j.x = FLOAT_N1_0;
        v87.j.y = FLOAT_N1_0;
        v87.j.z = FLOAT_N1_0;
        v87.j.w = FLOAT_N1_0;
        *(_QWORD *)&v87.lines[2].x = __PAIR64__(LODWORD(v9), LODWORD(FLOAT_N1_0));
        *(_QWORD *)&v87.lines[2].elements[2] = __PAIR64__(LODWORD(FLOAT_N1_0), LODWORD(v9));
        *(_QWORD *)&v87.lines[3].x = __PAIR64__(LODWORD(v9), LODWORD(FLOAT_N1_0));
        v87.c.z = v9;
        v87.c.w = v9;
        v88 = v9;
        v89 = v9;
        v90 = FLOAT_N1_0;
        v91 = FLOAT_N1_0;
        v92 = v9;
        v93 = v9;
        v94 = FLOAT_N1_0;
        v95 = v9;
        v12 = vostok::math::float4x4::identity(v10, &v97);
        vostok::render::renderer_context::set_w(v12, this->m_context);
        v11 = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality == 0;
        LODWORD(v82.z) = 16;
        v83 = 32;
        v84 = 48;
        v85 = 64;
        v13 = 4 - v11 - 1;
        v75 = v13;
        *(_DWORD *)&wszName[1] = v13;
        if ( v13 >= 0 )
        {
          v72 = (vostok::render::res_texture *)(v13 << 6);
          while ( 1 )
          {
            v_offset = 0;
            v71 = (vostok::render::backend *)vostok::render::vertex_buffer::lock(
                                               (vostok::render::vertex_buffer *)(LODWORD(z) + 44),
                                               &v_offset,
                                               8u,
                                               0xCu);
            qmemcpy(&v96, (char *)this->m_context->m_shadow_cascade_transform + (unsigned int)v72, sizeof(v96));
            vostok::math::float4x4::try_invert(&v96, &v96);
            v65 = 8;
            p_y = &v87.i.y;
            v15 = 8;
            do
            {
              v16 = p_y[1];
              v17 = *(p_y - 1);
              v18 = *p_y;
              v19 = (float *)v71;
              v77 = (float)((float)((float)(v96.i.x * v17) + (float)(v96.k.x * v16)) + (float)(v96.j.x * *p_y))
                  + v96.c.x;
              v71 = (vostok::render::backend *)((char *)v71 + 12);
              v78 = (float)((float)((float)(v96.i.y * v17) + (float)(v96.k.y * v16)) + (float)(v96.j.y * v18)) + v96.c.y;
              v79 = (float)((float)((float)(v96.i.z * v17) + (float)(v96.k.z * v16)) + (float)(v96.j.z * v18)) + v96.c.z;
              *v19++ = v77;
              *v19 = v78;
              p_y += 3;
              --v15;
              v19[1] = v79;
            }
            while ( v15 );
            vostok::render::vertex_buffer::unlock(
              0,
              (int *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 44));
            vostok::render::res_geometry::apply(v20, (int)this->m_obb_geometry.m_object);
            v21 = this->m_shadow_mask_effect.m_object;
            v21->m_cur_technique = 0;
            vostok::render::res_effect::apply_pass(v22, (int)v21);
            v65 = v_offset;
            v23 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
            v24 = *((_DWORD *)&v82.z + *(_DWORD *)&wszName[1]) + 1;
            m_c_sky_shadow_parameters = 0;
            v25 = (int *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 340);
            v11 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 340) == v24;
            v63.m_object = (vostok::render::render_target *)4;
            LOBYTE(v26) = !v11;
            *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 95) |= !v11;
            *v25 = v24;
            vostok::render::backend::render_indexed(
              (vostok::render::backend *)LODWORD(v23),
              0x24u,
              v26,
              (D3D_PRIMITIVE_TOPOLOGY)v63.m_object,
              (unsigned int)m_c_sky_shadow_parameters,
              v65);
            --*(_DWORD *)&wszName[1];
            v72 = (vostok::render::res_texture *)((char *)v72 - 64);
            if ( *(int *)&wszName[1] < 0 )
              break;
            z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          }
        }
        v27 = this->m_context->m_scene_view.m_object;
        *(_QWORD *)&v80.x = LODWORD(s_bm_current_air_resistance);
        v80.z = 0.0;
        v_offset = (unsigned int)v27;
        v77 = v76.x * -10000.0;
        v78 = v76.y * -10000.0;
        v79 = v76.z * -10000.0;
        vostok::math::create_camera_direction(&v76, &v80, &v96, &v77);
        v29 = (vostok::render::res_texture *)v75;
        *(_DWORD *)&wszName[1] = v75;
        if ( v75 >= 0 )
        {
          LODWORD(y) = &v66 - 5142;
          v71 = (vostok::render::backend *)(4 * v75 + 20660);
          v82.y = y;
          while ( 1 )
          {
            v31 = *(_BYTE *)(v_offset + 544)
               && *(_DWORD *)(v_offset + 292)
               && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
            v32 = (vostok::render::res_effect *)*((_DWORD *)&this->__vftable + (_DWORD)(&v29->num_mips + v31));
            v32->m_cur_technique = 0;
            vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v31, (int)v32);
            v33 = *(int *)((char *)&v71->vertex_small.m_buffer.m_object + LODWORD(y));
            z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
            ++v33;
            v35 = (vostok::render::backend *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                            + 340);
            v11 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 340) == v33;
            *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 340) = v33;
            *(_BYTE *)(z_low + 95) |= !v11;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v35,
              (vostok::render::constants_handler<1> *)z_low,
              this->m_c_eye_ray_corner,
              this->m_context->m_eye_rays);
            view2shadow = vostok::render::renderer_context::get_view2shadow(
                            this->m_context,
                            *(unsigned int *)&wszName[1]);
            v37 = vostok::math::transpose(view2shadow, &v97);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v38,
              (vostok::render::constants_handler<1> *)z_low,
              this->m_view_to_shadow_parameter,
              (const vostok::math::float3 *)v37);
            vostok::render::backend::set_ps_texture(
              v71,
              z_low,
              "t_cascaded_shadow_map",
              *(vostok::render::res_texture **)((char *)&this->m_context->m_targets + (unsigned int)v71));
            vostok::math::try_invert4x4(&v96, &v97);
            v40 = vostok::math::transpose(v39, &v87);
            v41 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v42,
              (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              this->m_c_sun_fixed_matrix,
              (const vostok::math::float3 *)v40);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              v43,
              (vostok::render::constants_handler<1> *)LODWORD(v41),
              this->m_c_sun_direction_parameter,
              &v86);
            v45 = (float *)v_offset;
            if ( !*(_BYTE *)(v_offset + 544)
              || (v46 = this->m_context->m_scene_view.m_object,
                  v73 |= 1u,
                  !vostok::render::scene_view::get_sky_shadows_texture((vostok::render::scene_view *)&v72, (int)v46)->__vftable)
              || (wszName[0] = (pix_event_wrapper_dx11)1,
                  !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
            {
              wszName[0] = 0;
            }
            if ( (v73 & 1) != 0 )
            {
              v73 &= ~1u;
              if ( v72 )
              {
                v47 = &v72->vostok::render::resource_intrusive_base;
                --v72->m_reference_count;
                if ( !v47->m_reference_count )
                  vostok::render::resource_manager::release(
                    v44,
                    (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    v72);
              }
            }
            if ( wszName[0] )
            {
              v48 = *((_DWORD *)v45 + 137);
              v49 = *((_DWORD *)v45 + 138);
              v50 = v45[139];
              v65 = (unsigned int)&v80;
              m_c_sky_shadow_parameters = this->m_c_sky_shadow_parameters;
              *(_QWORD *)&v80.x = __PAIR64__(v49, v48);
              v80.z = v50;
              v81 = 0;
              vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                (vostok::render::backend *)v44,
                (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                m_c_sky_shadow_parameters,
                &v80);
              sky_shadows_texture = (vostok::render::res_texture **)vostok::render::scene_view::get_sky_shadows_texture(
                                                                      (vostok::render::scene_view *)&v75,
                                                                      (int)this->m_context->m_scene_view.m_object);
              vostok::render::backend::set_ps_texture(
                v52,
                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                "sky_shadows_texture",
                *sky_shadows_texture);
              if ( v75 )
              {
                v53 = (vostok::render::resource_intrusive_base *)(v75 + 4);
                --*(_DWORD *)(v75 + 4);
                if ( !v53->m_reference_count )
                  vostok::render::resource_manager::release(
                    v44,
                    (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    (vostok::render::res_texture *)v75);
              }
            }
            v65 = (unsigned int)&v82;
            m_c_sky_shadow_parameters = this->m_c_cascade_index;
            v82.x = (float)*(int *)&wszName[1];
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              (vostok::render::backend *)v44,
              (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              m_c_sky_shadow_parameters,
              &v82);
            v65 = 1;
            v54 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
            m_c_sky_shadow_parameters = 0;
            v63.m_object = 0;
            v62 = 0;
            v60.m_object = v55;
            v61 = 0;
            v59 = v55;
            vostok::render::renderer_context::get_rt(this->m_context, rt_sun_shadow_and_scattering, &v60);
            vostok::render::system_renderer::fill_surface(
              (vostok::render::system_renderer *)v59,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v54,
              v60.m_object,
              v61,
              v62,
              v63,
              (vostok::render::render_target *)m_c_sky_shadow_parameters,
              (D3D11_VIEWPORT *)v65,
              v66,
              v67,
              v68,
              v69);
            --*(_DWORD *)&wszName[1];
            v71 = (vostok::render::backend *)((char *)v71 - 4);
            if ( *(int *)&wszName[1] < 0 )
              break;
            y = v82.y;
            v29 = *(vostok::render::res_texture **)&wszName[1];
          }
        }
        v56 = this->m_far_plane_mask_effect.m_object;
        v56->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v28, (int)v56);
        vostok::render::system_renderer::fill_surface(
          v57,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          0,
          0,
          0,
          0,
          0,
          (D3D11_VIEWPORT *)1,
          v66,
          v67,
          v68,
          v69);
        vostok::render::backend::reset_render_targets(
          v58,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      }
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
}
