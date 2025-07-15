void __thiscall vostok::render::stage_forward::execute(vostok::render::stage_forward *this)
{
  vostok::render::renderer_context *m_context; // eax
  float v3; // xmm0_4
  vostok::render::renderer_context *v4; // eax
  vostok::render::render_surface_instance **m_reconstruction_info_actuality_tick_high; // ecx
  vostok::render::render_surface_instance **m_reconstruction_info_actuality_tick; // eax
  ID3D11DeviceContext *v7; // esi
  ID3D11Resource *m_surface; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::resource_manager *v10; // ecx
  vostok::shared_string *p_m_name; // eax
  vostok::intrusive_ptr<vostok::render::res_state,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_state; // eax
  vostok::render::res_input_layout *v13; // ecx
  vostok::render::renderer *v14; // ecx
  vostok::render::res_input_layout *v15; // ecx
  vostok::render::renderer *v16; // ecx
  vostok::render::render_surface_instance **m_begin; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v18; // eax
  int z_low; // esi
  vostok::render::render_target *v20; // eax
  vostok::render::stage_forward::stage_type m_type; // eax
  int v22; // edi
  vostok::render::material_effects *material_effects; // eax
  vostok::render::renderer_context *v24; // esi
  vostok::render::render_surface_instance *v25; // eax
  vostok::render::res_effect *v26; // ecx
  vostok::render::res_geometry *v27; // ecx
  float z; // esi
  vostok::render::backend *v29; // ecx
  vostok::math::float4x4 *v30; // eax
  vostok::render::backend *v31; // ecx
  vostok::render::backend *v32; // ecx
  vostok::render::renderer_context *v33; // ecx
  vostok::math::float4x4 *v34; // eax
  vostok::render::backend *v35; // ecx
  int v36; // ecx
  vostok::render::res_input_layout *v37; // ecx
  vostok::render::renderer *v38; // ecx
  vostok::render::res_input_layout *v39; // ecx
  vostok::render::renderer *v40; // ecx
  float v41; // eax
  int v42; // edi
  int v43; // ecx
  int v44; // esi
  void *v45; // esp
  float v46; // eax
  int v47; // edi
  int v48; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v49; // eax
  float v50; // esi
  vostok::render::render_target *v51; // eax
  int v52; // edi
  vostok::render::statistics *v53; // eax
  vostok::particle::particle_system_instance_impl *v54; // ecx
  vostok::render::decal_instance *v55; // ecx
  int v56; // eax
  float v57; // ecx
  char *v58; // eax
  vostok::render::render_surface_instance **v59; // ecx
  bool i; // zf
  char *v61; // esi
  float m_distance_to_viewer; // ecx
  int v63; // edx
  vostok::render::render_target *v64; // eax
  int *v65; // edi
  vostok::render::res_geometry *v66; // ecx
  vostok::render::render_surface *v67; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_pass *v69; // ecx
  vostok::render::res_pass *v70; // edi
  vostok::render::res_pass *v71; // eax
  vostok::render::res_pass *v72; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::effect_manager *v74; // ecx
  float v75; // esi
  vostok::math::float4x4 *v76; // eax
  vostok::render::backend *v77; // ecx
  vostok::render::backend *v78; // ecx
  vostok::render::backend *v79; // ecx
  vostok::render::backend *v80; // ecx
  vostok::render::res_effect *v81; // eax
  vostok::render::res_pass *v82; // eax
  vostok::render::res_pass *v83; // edi
  vostok::render::res_pass *v84; // eax
  vostok::render::effect_manager *v85; // ecx
  vostok::render::res_pass *v86; // eax
  float v87; // xmm1_4
  int v88; // eax
  float v89; // esi
  vostok::render::backend *v90; // ecx
  vostok::math::float4x4 *v91; // ecx
  vostok::math::float4x4 *v92; // eax
  float v93; // esi
  vostok::render::backend *v94; // ecx
  int v95; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v96; // [esp-8h] [ebp-433Ch] BYREF
  vostok::render::enum_render_stage_type p_y; // [esp-4h] [ebp-4338h]
  _DWORD v98[3]; // [esp+0h] [ebp-4334h] BYREF
  _BYTE *v99; // [esp+Ch] [ebp-4328h] BYREF
  _BYTE *v100; // [esp+10h] [ebp-4324h]
  vostok::buffer_vector<vostok::render::render_surface_instance *> *v101; // [esp+14h] [ebp-4320h]
  _BYTE v102[8192]; // [esp+18h] [ebp-431Ch] BYREF
  vostok::buffer_vector<vostok::render::render_surface_instance *> v103; // [esp+2018h] [ebp-231Ch] BYREF
  _BYTE v104[8192]; // [esp+2024h] [ebp-2310h] BYREF
  vostok::math::frustum v105; // [esp+4024h] [ebp-310h] BYREF
  vostok::math::frustum v106; // [esp+409Ch] [ebp-298h] BYREF
  float v107; // [esp+4114h] [ebp-220h] BYREF
  _BYTE *v108; // [esp+4118h] [ebp-21Ch]
  vostok::math::float4x4 *v109; // [esp+411Ch] [ebp-218h]
  _BYTE v110[512]; // [esp+4120h] [ebp-214h] BYREF
  vostok::math::float4x4 v111; // [esp+4320h] [ebp-14h] BYREF
  vostok::math::float3 v112; // [esp+4360h] [ebp+2Ch] BYREF
  float v113; // [esp+436Ch] [ebp+38h]
  vostok::render::renderer_context *m_eye_rays; // [esp+4370h] [ebp+3Ch]
  vostok::render::render_surface_instance **v115; // [esp+4374h] [ebp+40h]
  _BYTE *j; // [esp+4378h] [ebp+44h]
  vostok::math::float3 v117; // [esp+437Ch] [ebp+48h] BYREF
  _DWORD *v118; // [esp+4388h] [ebp+54h]
  _DWORD *v119; // [esp+438Ch] [ebp+58h]
  pix_event_wrapper_dx11 wszName[5]; // [esp+4393h] [ebp+5Fh] BYREF
  vostok::render::ambient_light **m_end; // [esp+4398h] [ebp+64h] BYREF
  vostok::render::res_pass *pass; // [esp+439Ch] [ebp+68h] BYREF
  vostok::render::render_surface_instance **end; // [esp+43A0h] [ebp+6Ch] BYREF
  float v124; // [esp+43A4h] [ebp+70h]
  vostok::render::render_target *rt; // [esp+43A8h] [ebp+74h] BYREF

  if ( this->is_effects_ready(this) )
  {
    if ( this->is_enabled(this)
      && (vostok::quasi_singleton<vostok::render::options>::pinst->current.m_forward_sky_stage
       || this->m_type != forward_sky)
      && (vostok::quasi_singleton<vostok::render::options>::pinst->current.m_forward_stage || this->m_type) )
    {
      m_context = this->m_context;
      i = LOBYTE(m_context->m_scene_view.m_object[2].grm_satisfaction_tree_hook.left_) == 0;
      qmemcpy(&v111, &m_context->m_p, sizeof(v111));
      if ( i )
        v3 = 0.0;
      else
        v3 = s_bm_current_air_resistance;
      v4 = this->m_context;
      m_eye_rays = (vostok::render::renderer_context *)v4->m_eye_rays;
      m_reconstruction_info_actuality_tick_high = (vostok::render::render_surface_instance **)HIDWORD(v4->m_scene_view.m_object[92].m_reconstruction_info_actuality_tick);
      m_reconstruction_info_actuality_tick = (vostok::render::render_surface_instance **)v4->m_scene_view.m_object[92].m_reconstruction_info_actuality_tick;
      end = m_reconstruction_info_actuality_tick_high;
      v103.m_begin = (vostok::render::render_surface_instance **)v104;
      v103.m_end = (vostok::render::render_surface_instance **)v104;
      v103.m_max_end = (vostok::render::render_surface_instance **)&v105;
      v117.x = v3;
      vostok::buffer_vector<vostok::render::render_surface_instance *>::assign<vostok::render::render_surface_instance * *>(
        m_reconstruction_info_actuality_tick,
        &end,
        &v103);
      LOBYTE(end) = 0;
      m_end = (vostok::render::ambient_light **)v103.m_end;
      end = stlp_std::remove_if<vostok::render::render_surface_instance * *,vostok::render::remove_models_with_local_reflections_predicate>(
              v103.m_begin,
              v103.m_end,
              0);
      vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
        (vostok::buffer_vector<vostok::render::ambient_light *> *)&v103,
        (vostok::render::ambient_light ***)&end,
        &m_end);
      v7 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
      m_surface = vostok::render::renderer_context::get_t(
                    this->m_context,
                    rt_generic_0,
                    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&pass)->m_object->m_surface;
      t = vostok::render::renderer_context::get_t(
            this->m_context,
            rt_generic_1,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
      v7->CopyResource(v7, t->m_object->m_surface, m_surface);
      if ( rt )
      {
        p_m_name = &rt->m_name;
        --rt->m_name.m_pointer.m_object;
        if ( !p_m_name->m_pointer.m_object )
          vostok::render::resource_manager::release(
            v10,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::render::res_texture *)rt);
      }
      if ( pass )
      {
        p_m_state = &pass->m_state;
        --pass->m_state.m_object;
        if ( !p_m_state->m_object )
          vostok::render::resource_manager::release(
            v10,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::render::res_texture *)pass);
      }
      pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)v10, wszName, (int)L"stage_forward");
      vostok::render::renderer::sort_models_by_distance(this->m_renderer, &v103);
      if ( this->m_type == forward_sky )
      {
        vostok::render::stage_forward::render_forward_models(&v103, v13, 0.0, this, 1u, 0);
        vostok::render::renderer::foreground_begin(v14, (int)this->m_renderer);
        vostok::render::stage_forward::render_forward_models(&v103, v15, 0.0, this, 1u, 1);
        vostok::render::renderer::foreground_end(v16, (int)this->m_renderer);
      }
      m_begin = v103.m_begin;
      v124 = *(float *)&v103.m_begin;
      pass = (vostok::render::res_pass *)v103.m_end;
      if ( v103.m_begin == v103.m_end )
      {
        z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
      }
      else
      {
        v18 = vostok::render::renderer_context::get_rt(
                this->m_context,
                rt_generic_0,
                (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
        z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        vostok::render::backend::set_render_targets(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          v18->m_object,
          0,
          0,
          0);
        v20 = rt;
        if ( rt )
        {
          --rt->m_reference_count;
          if ( !v20->m_reference_count )
          {
            vostok::render::resource_manager::release(
              rt,
              vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
            z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
          }
        }
        m_begin = *(vostok::render::render_surface_instance ***)(z_low + 7440);
        i = *(_DWORD *)(z_low + 7384) == (_DWORD)m_begin;
        *(_DWORD *)(z_low + 7384) = m_begin;
        *(_BYTE *)(z_low + 117) |= !i;
      }
      m_type = this->m_type;
      if ( m_type == forward_sky )
      {
        if ( (vostok::render::res_pass *)LODWORD(v124) != pass )
        {
          while ( 1 )
          {
            v22 = *(_DWORD *)LODWORD(v124);
            rt = *(vostok::render::render_target **)(*(_DWORD *)LODWORD(v124) + 16);
            material_effects = vostok::render::render_surface::get_material_effects(
                                 (vostok::render::render_surface *)m_begin,
                                 (int)rt);
            i = !material_effects->is_background_sky;
            end = (vostok::render::render_surface_instance **)material_effects;
            if ( !i )
              break;
            LODWORD(v124) += 4;
            if ( (vostok::render::res_pass *)LODWORD(v124) == pass )
              goto LABEL_31;
          }
          v24 = this->m_context;
          v111.k.z = s_bm_current_air_resistance;
          v111.c.z = FLOAT_N0_0099999998;
          vostok::render::renderer_context::push_set_p((vostok::render::renderer_context *)m_begin, (int)v24, &v111);
          vostok::render::renderer_context::set_w(*(const vostok::math::float4x4 **)(v22 + 36), this->m_context);
          v25 = end[26];
          v25[393].m_shadow_transform = 0;
          vostok::render::res_effect::apply_pass(v26, (int)v25);
          vostok::render::res_geometry::apply(v27, (int)rt->m_name.m_pointer.m_object);
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          *(_QWORD *)&v117.elements[1] = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(FLOAT_1000_0));
          p_y = (vostok::render::enum_render_stage_type)&v117.y;
          v96.m_object = (vostok::particle::particle_system_instance_impl *)this->m_c_inscatter_parameters;
          v118 = 0;
          v119 = 0;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v29,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)v96.m_object,
            (vostok::math::float3 *)&v117.elements[1]);
          v30 = vostok::math::transpose(&this->m_renderer->m_view_to_rain_shadow, &v111);
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v31,
            (vostok::render::constants_handler<1> *)LODWORD(z),
            this->m_view_to_shadow_parameter,
            (const vostok::math::float3 *)v30);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(z),
            3 * (int)rt->m_zrt,
            v32,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
          vostok::render::renderer_context::pop_p(v33, this->m_context);
          z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        }
LABEL_31:
        v34 = vostok::math::float4x4::identity((vostok::math::float4x4 *)m_begin, &v111);
        vostok::render::renderer_context::set_w(v34, this->m_context);
        vostok::render::backend::reset_render_targets(v35, z_low);
        v36 = *(_DWORD *)(z_low + 7440);
        i = *(_DWORD *)(z_low + 7384) == v36;
        *(_DWORD *)(z_low + 7384) = v36;
        *(_BYTE *)(z_low + 117) |= !i;
        D3DPERF_EndEvent();
      }
      else
      {
        if ( m_type == forward_base )
        {
          vostok::render::stage_forward::render_opaque_models((vostok::render::stage_forward *)m_begin, (int)this);
          vostok::render::stage_forward::render_forward_models(&v103, v37, *(float *)&z_low, this, 0, 0);
        }
        vostok::render::stage_forward::render_forward_models(
          &v103,
          (vostok::render::res_input_layout *)m_begin,
          *(float *)&z_low,
          this,
          0,
          0);
        vostok::render::renderer::foreground_begin(v38, (int)this->m_renderer);
        vostok::render::stage_forward::render_forward_models(&v103, v39, *(float *)&z_low, this, 0, 1);
        vostok::render::renderer::foreground_end(v40, (int)this->m_renderer);
        v99 = v102;
        v100 = v102;
        v101 = &v103;
        v41 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        v42 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
        i = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v42;
        *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v42;
        *(_BYTE *)(LODWORD(v41) + 117) |= !i;
        vostok::math::frustum::frustum(&v106, &this->m_context->m_vp);
        v43 = *(int *)((char *)&dword_8B9650 + (unsigned int)this->m_context->m_scene);
        (*(void (__thiscall **)(int, int, vostok::math::frustum *, _BYTE **))(*(_DWORD *)v43 + 28))(
          v43,
          -1,
          &v106,
          &v99);
        if ( v99 != v100 )
        {
          v44 = *(int *)((char *)&dword_8B6544 + (unsigned int)this->m_context->m_scene);
          v45 = alloca(4 * v44);
          LODWORD(v117.z) = v98;
          v118 = v98;
          v119 = &v98[v44];
          v46 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          v47 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
          i = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v47;
          *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v47;
          *(_BYTE *)(LODWORD(v46) + 117) |= !i;
          vostok::math::frustum::frustum(&v105, &this->m_context->m_vp);
          v48 = *(int *)((char *)&dword_8B9650 + (unsigned int)this->m_context->m_scene);
          (*(void (__thiscall **)(int, int, vostok::math::frustum *, float *))(*(_DWORD *)v48 + 28))(
            v48,
            -1,
            &v105,
            &v117.z);
          if ( (((unsigned int)v118 - LODWORD(v117.z)) & 0xFFFFFFFC) != 0 )
          {
            v49 = vostok::render::renderer_context::get_rt(
                    this->m_context,
                    rt_generic_0,
                    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
            v50 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
            vostok::render::backend::set_render_targets(
              (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
              v49->m_object,
              0,
              0,
              0);
            v51 = rt;
            if ( rt )
            {
              --rt->m_reference_count;
              if ( !v51->m_reference_count )
              {
                vostok::render::resource_manager::release(
                  rt,
                  vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
                v50 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
              }
            }
            v52 = *(_DWORD *)(LODWORD(v50) + 7440);
            i = *(_DWORD *)(LODWORD(v50) + 7384) == v52;
            *(_DWORD *)(LODWORD(v50) + 7384) = v52;
            *(_BYTE *)(LODWORD(v50) + 117) |= !i;
          }
          v124 = v117.z;
          *(_DWORD *)&wszName[1] = v118;
          if ( (_DWORD *)LODWORD(v117.z) != v118 )
          {
            v53 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
            do
            {
              v54 = *(vostok::particle::particle_system_instance_impl **)(*(_DWORD *)LODWORD(v124) + 36);
              p_y = forward_render_stage;
              v96.m_object = v54;
              end = (vostok::render::render_surface_instance **)v54;
              m_end = (vostok::render::ambient_light **)&v53->forward_decals_stat_group.num_decal_draw_calls.value;
              vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
                &v96,
                (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_opaque_geometry_mask_effect);
              v56 = vostok::render::decal_instance::draw(
                      v55,
                      (vostok::render::renderer_context *)end,
                      (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>)this->m_context,
                      v96,
                      p_y);
              *m_end = (vostok::render::ambient_light *)((char *)*m_end + v56);
              LODWORD(v124) += 4;
              v53 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
              v57 = v124;
              ++vostok::quasi_singleton<vostok::render::statistics>::pinst->forward_decals_stat_group.num_decals.value;
            }
            while ( LODWORD(v57) != *(_DWORD *)&wszName[1] );
          }
          v58 = (char *)&vostok::memory::s_resources.m_buffer[7260] + (unsigned int)this->m_context->m_scene;
          v59 = *(vostok::render::render_surface_instance ***)v58;
          v115 = (vostok::render::render_surface_instance **)*((_DWORD *)v58 + 1);
          for ( i = v59 == v115; ; i = end + 1 == v115 )
          {
            end = v59;
            if ( i )
              break;
            v61 = (char *)*v59;
            m_distance_to_viewer = (*v59)[5].m_distance_to_viewer;
            v107 = COERCE_FLOAT(v110);
            v108 = v110;
            p_y = accumulate_distortion_render_stage;
            v109 = &v111;
            v63 = *(_DWORD *)LODWORD(m_distance_to_viewer);
            m_end = (vostok::render::ambient_light **)v61;
            (*(void (__thiscall **)(float, _DWORD, _DWORD, float *, int, _DWORD, int))(v63 + 76))(
              COERCE_FLOAT(LODWORD(m_distance_to_viewer)),
              0,
              0,
              &v107,
              1,
              0,
              3);
            v124 = v107;
            for ( j = v108; (_BYTE *)LODWORD(v124) != j; LODWORD(v124) += 4 )
            {
              v64 = *(vostok::render::render_target **)LODWORD(v124);
              v65 = *(int **)(*(_DWORD *)LODWORD(v124) + 16);
              p_y = (vostok::render::enum_render_stage_type)this->m_context;
              rt = v64;
              *(_DWORD *)&wszName[1] = ++v65;
              vostok::render::renderer_context::set_w(
                (const vostok::math::float4x4 *)(v61 + 264),
                (vostok::render::renderer_context *)p_y);
              vostok::render::res_geometry::apply(v66, *v65);
              m_object = vostok::render::render_surface::get_material_effects(v67, (int)rt->m_surface_3d)->m_effects[16].m_object;
              v70 = 0;
              if ( m_object )
              {
                v69 = (vostok::render::res_pass *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
                if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
                {
                  m_object->m_cur_technique = 0;
                  v71 = (vostok::render::res_pass *)m_object->m_techniques.m_begin->m_object;
                  v72 = 0;
                  if ( v71 )
                  {
                    v72 = v71;
                    ++v71->m_reference_count;
                  }
                  m_reference_count = (_DWORD *)v72->m_vs.m_object->m_reference_count;
                  if ( m_reference_count )
                  {
                    v70 = (vostok::render::res_pass *)v72->m_vs.m_object->m_reference_count;
                    ++*m_reference_count;
                  }
                  vostok::render::res_pass::apply(
                    (vostok::render::res_pass *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
                    (int)v70);
                  if ( v70 )
                  {
                    i = v70->m_reference_count-- == 1;
                    if ( i )
                      vostok::render::effect_manager::delete_pass(
                        v74,
                        (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
                        v70);
                  }
                  i = v72->m_reference_count-- == 1;
                  if ( i )
                  {
                    vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v72);
                    v74 = (vostok::render::effect_manager *)p_y;
                  }
                  p_y = (vostok::render::enum_render_stage_type)m_eye_rays;
                  v75 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
                  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                    (vostok::render::backend *)v74,
                    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                    this->m_eye_ray_corner_parameter,
                    (const vostok::math::float3 *)m_eye_rays);
                  v76 = vostok::math::transpose(&this->m_renderer->m_view_to_rain_shadow, &v111);
                  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                    v77,
                    (vostok::render::constants_handler<1> *)LODWORD(v75),
                    this->m_view_to_shadow_parameter,
                    (const vostok::math::float3 *)v76);
                  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                    v78,
                    (vostok::render::constants_handler<1> *)LODWORD(v75),
                    this->m_rain_offset_parameter,
                    (const vostok::math::float3 *)&this->m_rain_offset);
                  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                    v79,
                    (vostok::render::constants_handler<1> *)LODWORD(v75),
                    this->m_use_rain_parameter,
                    &v117);
                  rt->m_width = 0;
                  vostok::render::backend::render_indexed(
                    (vostok::render::backend *)LODWORD(v75),
                    3 * *(_DWORD *)(*(_DWORD *)&wszName[1] + 20),
                    v80,
                    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
                    0,
                    0);
                  v61 = (char *)m_end;
                }
              }
              if ( v61[335] )
              {
                v81 = this->m_debug_tracer_effect.m_object;
                v81->m_cur_technique = 0;
                v82 = (vostok::render::res_pass *)v81->m_techniques.m_begin->m_object;
                v83 = 0;
                if ( v82 )
                {
                  v83 = v82;
                  ++v82->m_reference_count;
                }
                v84 = (vostok::render::res_pass *)v83->m_vs.m_object->m_reference_count;
                pass = 0;
                if ( v84 )
                {
                  ++v84->m_reference_count;
                  pass = v84;
                }
                vostok::render::res_pass::apply(v69, (int)pass);
                v86 = pass;
                if ( pass )
                {
                  i = pass->m_reference_count-- == 1;
                  if ( i )
                    vostok::render::effect_manager::delete_pass(
                      v85,
                      (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
                      v86);
                }
                i = v83->m_reference_count-- == 1;
                if ( i )
                {
                  vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v83);
                  v85 = (vostok::render::effect_manager *)p_y;
                }
                pass = (vostok::render::res_pass *)(unsigned __int8)v61[332];
                v87 = (float)(unsigned __int8)v61[333];
                v88 = (unsigned __int8)v61[334];
                v89 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
                v112.x = (double)(int)pass * 0.0039215689;
                v112.y = v87 * 0.0039215689;
                p_y = (vostok::render::enum_render_stage_type)&v112;
                v96.m_object = (vostok::particle::particle_system_instance_impl *)this->m_tracer_debug_color_parameter;
                v112.z = (float)v88 * 0.0039215689;
                v113 = s_bm_current_air_resistance;
                vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
                  (vostok::render::backend *)v85,
                  (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                  (const vostok::render::shader_constant_host *)v96.m_object,
                  &v112);
                rt->m_width = 0;
                vostok::render::backend::render_indexed(
                  (vostok::render::backend *)LODWORD(v89),
                  3 * *(_DWORD *)(*(_DWORD *)&wszName[1] + 20),
                  v90,
                  D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
                  0,
                  0);
                v61 = (char *)m_end;
              }
            }
            v59 = end + 1;
          }
        }
        D3DPERF_EndEvent();
        v92 = vostok::math::float4x4::identity(v91, &v111);
        vostok::render::renderer_context::set_w(v92, this->m_context);
        v93 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::reset_render_targets(
          v94,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
        v95 = *(_DWORD *)(LODWORD(v93) + 7440);
        i = *(_DWORD *)(LODWORD(v93) + 7384) == v95;
        *(_DWORD *)(LODWORD(v93) + 7384) = v95;
        *(_BYTE *)(LODWORD(v93) + 117) |= !i;
      }
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}
