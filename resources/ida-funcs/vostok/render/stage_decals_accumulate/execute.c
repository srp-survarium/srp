void __thiscall vostok::render::stage_decals_accumulate::execute(vostok::render::stage_decals_accumulate *this)
{
  vostok::render::base_scene_view *m_object; // eax
  char *type; // ecx
  vostok::render::base_scene_view_vtbl *v4; // eax
  vostok::render::decal_instance *v5; // esi
  vostok::render::decal_instance **v6; // edx
  int v7; // ecx
  int v8; // eax
  vostok::render::decal_instance **v9; // edi
  vostok::particle::particle_system_instance_impl *v10; // edi
  vostok::render::render_target *v11; // esi
  vostok::render::render_target *v12; // eax
  float z; // edi
  _DWORD *v14; // eax
  vostok::render::render_target *v15; // eax
  vostok::render::render_target *v16; // eax
  bool v17; // zf
  vostok::render::decal_instance **v18; // eax
  vostok::render::renderer_context *m_context; // ecx
  vostok::render::render_target *v20; // eax
  vostok::render::backend *v21; // ecx
  vostok::render::render_target *v22; // eax
  vostok::particle::particle_system_instance_impl *v23; // ecx
  vostok::render::render_target *p_m_name; // eax
  vostok::render::decal_instance *v25; // ecx
  int v26; // eax
  vostok::render::res_effect *v27; // ecx
  vostok::render::res_effect *v28; // eax
  vostok::render::render_target *v29; // ecx
  vostok::render::renderer_context *v30; // ecx
  vostok::render::render_target *v31; // ecx
  vostok::render::backend *v32; // ecx
  vostok::render::res_effect *v33; // eax
  vostok::render::res_effect *v34; // ecx
  vostok::render::render_target *v35; // ecx
  vostok::render::renderer_context *v36; // ecx
  vostok::render::render_target *v37; // ecx
  vostok::render::res_effect *v38; // eax
  vostok::render::res_effect *v39; // ecx
  vostok::render::render_target *v40; // ecx
  vostok::render::system_renderer *v41; // esi
  float v42; // esi
  int v43; // ecx
  vostok::render::system_renderer *v44; // [esp-1Ch] [ebp-107Ch]
  vostok::render::system_renderer *v45; // [esp-1Ch] [ebp-107Ch]
  vostok::render::system_renderer *v46; // [esp-1Ch] [ebp-107Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v47; // [esp-18h] [ebp-1078h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v48; // [esp-14h] [ebp-1074h] BYREF
  vostok::render::render_target *v49; // [esp-10h] [ebp-1070h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v50; // [esp-Ch] [ebp-106Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v51; // [esp-8h] [ebp-1068h] BYREF
  vostok::render::enum_render_stage_type v52; // [esp-4h] [ebp-1064h]
  const D3D11_VIEWPORT *v53; // [esp+0h] [ebp-1060h]
  float v54; // [esp+4h] [ebp-105Ch]
  float v55; // [esp+8h] [ebp-1058h]
  float v56; // [esp+Ch] [ebp-1054h]
  vostok::render::render_target *v57; // [esp+10h] [ebp-1050h] BYREF
  pix_event_wrapper_dx11 wszName[5]; // [esp+17h] [ebp-1049h] BYREF
  vostok::render::render_target *rt; // [esp+1Ch] [ebp-1044h] BYREF
  D3D11_VIEWPORT v60; // [esp+20h] [ebp-1040h] BYREF
  D3D11_VIEWPORT v61; // [esp+38h] [ebp-1028h] BYREF
  vostok::render::decal_instance **__first; // [esp+50h] [ebp-1010h]
  vostok::render::decal_instance **v63; // [esp+54h] [ebp-100Ch]
  char *v64; // [esp+58h] [ebp-1008h]
  vostok::render::decal_instance *__last[1024]; // [esp+5Ch] [ebp-1004h] BYREF
  char v66; // [esp+105Ch] [ebp-4h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    wszName,
    (int)L"stage_decals_accumulate");
  if ( this->is_effects_ready(this) )
  {
    m_object = this->m_context->m_scene_view.m_object;
    v63 = __last;
    __first = __last;
    m_object = (vostok::render::base_scene_view *)((char *)m_object + 48352);
    v64 = &v66;
    type = (char *)m_object->type;
    v4 = m_object->__vftable;
    v5 = (vostok::render::decal_instance *)&__last[(type - (char *)v4) >> 2];
    v63 = (vostok::render::decal_instance **)v5;
    v6 = __last;
    if ( v4 != (vostok::render::base_scene_view_vtbl *)type )
    {
      do
      {
        if ( v6 )
          *v6 = (vostok::render::decal_instance *)v4->~vostok::render::base_scene_view;
        v4 = (vostok::render::base_scene_view_vtbl *)((char *)v4 + 4);
        ++v6;
      }
      while ( v4 != (vostok::render::base_scene_view_vtbl *)type );
      v5 = (vostok::render::decal_instance *)v63;
    }
    v7 = ((char *)v5 - (char *)__first) >> 2;
    if ( v7 )
    {
      v8 = 0;
      wszName[1] = 0;
      v9 = __first;
      if ( __first != (vostok::render::decal_instance **)v5 )
      {
        while ( v7 != 1 )
        {
          ++v8;
          v7 >>= 1;
        }
        _____introsort_loop_PAPAUdecal_instance_render_vostok__PAU123_HUsort_by_priority_predicate__3__execute_stage_decals_accumulate_23_UAEXXZ__priv_stlp_std__YAXPAPAUdecal_instance_render_vostok__00HUsort_by_priority_predicate__3__execute_stage_decals_accumulate_34_UAEXXZ__Z(
          v5,
          __first,
          (vostok::render::decal_instance **)v5,
          0,
          2 * v8,
          *(vostok::render::decal_instance ***)&wszName[1]);
        _____final_insertion_sort_PAPAUdecal_instance_render_vostok__Usort_by_priority_predicate__3__execute_stage_decals_accumulate_23_UAEXXZ__priv_stlp_std__YAXPAPAUdecal_instance_render_vostok__0Usort_by_priority_predicate__3__execute_stage_decals_accumulate_34_UAEXXZ__Z(
          v9,
          (vostok::render::decal_instance **)v5,
          *(vostok::render::decal_instance **)&wszName[1]);
      }
    }
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_decals_accumulate_stage
      && this->is_enabled(this)
      && __first != v63 )
    {
      v10 = (vostok::particle::particle_system_instance_impl *)vostok::render::renderer_context::get_rt(
                                                                 this->m_context,
                                                                 rt_decals_smoothness,
                                                                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v57)->m_object;
      v11 = vostok::render::renderer_context::get_rt(
              this->m_context,
              rt_decals_normal,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object;
      v12 = vostok::render::renderer_context::get_rt(
              this->m_context,
              rt_decals_diffuse,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1])->m_object;
      v51.m_object = v10;
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v12,
        v11,
        (const vostok::render::render_target *)v51.m_object,
        0);
      v14 = *(_DWORD **)&wszName[1];
      if ( *(_DWORD *)&wszName[1] )
      {
        --**(_DWORD **)&wszName[1];
        if ( !*v14 )
        {
          vostok::render::resource_manager::release(
            *(vostok::render::render_target **)&wszName[1],
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      v15 = rt;
      if ( rt )
      {
        --rt->m_reference_count;
        if ( !v15->m_reference_count )
        {
          vostok::render::resource_manager::release(
            rt,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      v16 = v57;
      if ( v57 )
      {
        --v57->m_reference_count;
        if ( !v16->m_reference_count )
        {
          vostok::render::resource_manager::release(
            v57,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      v17 = *(_DWORD *)(LODWORD(z) + 7384) == 0;
      *(_DWORD *)(LODWORD(z) + 7384) = 0;
      *(_BYTE *)(LODWORD(z) + 117) |= !v17;
      v18 = __first;
      if ( __first == v63 )
        goto LABEL_42;
      v52 = (vostok::render::enum_render_stage_type)&v57;
      qmemcpy((void *)&v61, (const void *)(LODWORD(z) + 120), sizeof(v61));
      m_context = this->m_context;
      v60.TopLeftX = 0.0;
      v60.TopLeftY = 0.0;
      rt = (vostok::render::render_target *)vostok::render::renderer_context::get_rt(
                                              m_context,
                                              rt_decals_diffuse,
                                              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v57)->m_object->m_width;
      v20 = v57;
      v60.Width = (float)(unsigned int)rt;
      if ( v57 )
      {
        --v57->m_reference_count;
        if ( !v20->m_reference_count )
          vostok::render::resource_manager::release(
            v57,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      rt = (vostok::render::render_target *)vostok::render::renderer_context::get_rt(
                                              this->m_context,
                                              rt_decals_diffuse,
                                              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v57)->m_object->m_height;
      v22 = v57;
      v60.Height = (float)(unsigned int)rt;
      if ( v57 )
      {
        --v57->m_reference_count;
        if ( !v22->m_reference_count )
          vostok::render::resource_manager::release(
            v57,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      v60.MinDepth = 0.0;
      v60.MaxDepth = s_bm_current_air_resistance;
      vostok::render::backend::set_viewports(
        v21,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        &v60,
        v53);
      p_m_name = (vostok::render::render_target *)__first;
      wszName[0] = 0;
      while ( 1 )
      {
        v57 = p_m_name;
        if ( p_m_name == (vostok::render::render_target *)v63 )
          break;
        rt = (vostok::render::render_target *)p_m_name->m_reference_count;
        if ( !vostok::render::decal_instance::is_occluded((vostok::render::decal_instance *)v23, (int)rt) )
        {
          v52 = decals_accumulate_render_stage;
          v51.m_object = v23;
          *(_DWORD *)&wszName[1] = &vostok::quasi_singleton<vostok::render::statistics>::pinst->deferred_decals_stat_group.num_decal_draw_calls.value;
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v51,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_opaque_geometry_mask_effect);
          v26 = vostok::render::decal_instance::draw(
                  v25,
                  (vostok::render::renderer_context *)rt,
                  (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>)this->m_context,
                  v51,
                  v52);
          v23 = *(vostok::particle::particle_system_instance_impl **)&wszName[1];
          **(_DWORD **)&wszName[1] += v26;
          wszName[0] = (pix_event_wrapper_dx11)1;
        }
        p_m_name = (vostok::render::render_target *)&v57->m_name;
      }
      vostok::render::backend::set_viewports(
        (vostok::render::backend *)v23,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        &v61,
        v53);
      if ( wszName[0] )
      {
        v28 = this->m_apply_decal_effect.m_object;
        v28->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v27, (int)v28);
        v52 = gbuffer_render_stage;
        v51.m_object = 0;
        v50.m_object = 0;
        v48.m_object = v29;
        v49 = 0;
        v30 = this->m_context;
        v57 = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        vostok::render::renderer_context::get_rt(v30, rt_decals_smoothness_result, &v48);
        v47.m_object = v31;
        v44 = (vostok::render::system_renderer *)v31;
        vostok::render::renderer_context::get_rt(this->m_context, rt_decals_normal_result, &v47);
        vostok::render::system_renderer::fill_surface(
          v44,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v57,
          v47.m_object,
          v48.m_object,
          v49,
          v50,
          (vostok::render::render_target *)v51.m_object,
          (D3D11_VIEWPORT *)v52,
          *(float *)&v53,
          v54,
          v55,
          v56);
        vostok::render::backend::flush_rt_shader_resources(
          v32,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
        v33 = this->m_apply_decal_effect.m_object;
        v33->m_cur_technique = 1;
        vostok::render::res_effect::apply_pass(v34, (int)v33);
        v52 = gbuffer_render_stage;
        v51.m_object = 0;
        v50.m_object = 0;
        v48.m_object = v35;
        v49 = 0;
        v36 = this->m_context;
        v57 = (vostok::render::render_target *)vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        vostok::render::renderer_context::get_rt(v36, rt_surface_parameters, &v48);
        v47.m_object = v37;
        v45 = (vostok::render::system_renderer *)v37;
        vostok::render::renderer_context::get_rt(this->m_context, rt_normal, &v47);
        vostok::render::system_renderer::fill_surface(
          v45,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v57,
          v47.m_object,
          v48.m_object,
          v49,
          v50,
          (vostok::render::render_target *)v51.m_object,
          (D3D11_VIEWPORT *)v52,
          *(float *)&v53,
          v54,
          v55,
          v56);
        v38 = this->m_apply_decal_effect.m_object;
        v38->m_cur_technique = 2;
        vostok::render::res_effect::apply_pass(v39, (int)v38);
        v52 = gbuffer_render_stage;
        v51.m_object = 0;
        v50.m_object = 0;
        v49 = 0;
        v47.m_object = v40;
        v48.m_object = 0;
        v41 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        v46 = (vostok::render::system_renderer *)v40;
        vostok::render::renderer_context::get_rt(this->m_context, rt_albedo, &v47);
        vostok::render::system_renderer::fill_surface(
          v46,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v41,
          v47.m_object,
          v48.m_object,
          v49,
          v50,
          (vostok::render::render_target *)v51.m_object,
          (D3D11_VIEWPORT *)v52,
          *(float *)&v53,
          v54,
          v55,
          v56);
      }
      v42 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::reset_render_targets(
        (vostok::render::backend *)v27,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v43 = *(_DWORD *)(LODWORD(v42) + 7440);
      v17 = *(_DWORD *)(LODWORD(v42) + 7384) == v43;
      *(_DWORD *)(LODWORD(v42) + 7384) = v43;
      *(_BYTE *)(LODWORD(v42) + 117) |= !v17;
    }
    else
    {
      this->execute_disabled(this);
    }
    v18 = __first;
LABEL_42:
    v63 = v18;
  }
  D3DPERF_EndEvent();
}
