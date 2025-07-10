void __thiscall vostok::render::stage_gbuffer::execute(vostok::render::stage_gbuffer *this)
{
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v2; // ecx
  ID3D11RenderTargetView *v3; // ebp
  const char *m_conflicted_key_name; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v5; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v6; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v7; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v9; // eax
  vostok::render::render_target *v10; // ebx
  vostok::render::renderer_context *m_context; // esi
  vostok::render::render_target *v12; // eax
  vostok::render::resource_manager *v13; // ecx
  const char *v14; // eax
  vostok::render::render_surface_instance *const *v15; // edi
  int v16; // esi
  int v17; // eax
  vostok::render::backend *v18; // ecx
  const char *v19; // eax
  int v20; // ecx
  bool v21; // zf
  vostok::render::stage_gbuffer *v22; // ecx
  vostok::render::stage_gbuffer *v23; // ebx
  survarium::game_action_id *M_start; // ecx
  vostok::render::remove_model_if_not_lod_predicate v25; // ebp
  void **M_finish; // esi
  vostok::render::render_surface_instance **v27; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v28; // ecx
  void **v29; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v30; // ecx
  void **v31; // esi
  vostok::render::render_surface_instance **v32; // eax
  void **v33; // eax
  void **v34; // ebx
  vostok::render::render_surface_instance **v35; // eax
  void **v36; // eax
  void **v37; // edi
  vostok::render::render_surface_instance **v38; // eax
  void **v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  void **v42; // esi
  const char *v43; // eax
  void **v44; // esi
  const char *v45; // eax
  vostok::render::renderer_context *v46; // edx
  vostok::render::scene *m_scene; // eax
  vostok::render::renderer_context *v48; // ecx
  _DWORD *v49; // eax
  int v50; // ecx
  const char *v51; // esi
  vostok::render::render_target *v52; // eax
  void **v53; // edx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v55; // edx
  void *v56; // esi
  void **v57; // edx
  void *v58; // esi
  void **v59; // edx
  void *v60; // esi
  vostok::render::renderer_context *v61; // edx
  vostok::render::render_target *v62; // eax
  vostok::render::resource_manager *v63; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  char *v65; // eax
  const char *v66; // ebp
  int v67; // eax
  ID3D11ShaderResourceView *v68; // eax
  vostok::render::render_surface_instance *const *v69; // edx
  vostok::render::render_surface_instance *const *v70; // ebx
  vostok::render::render_surface_instance *v71; // edi
  int v72; // esi
  int v73; // eax
  vostok::render::material_effects *v74; // eax
  vostok::render::res_effect *v75; // ecx
  vostok::render::res_effect *v76; // eax
  vostok::render::backend *v77; // ecx
  const char *v78; // edi
  bool v79; // al
  unsigned int v80; // ebp
  const char *v81; // esi
  __int64 v82; // rax
  int v83; // eax
  void **v84; // [esp-Ch] [ebp-80h]
  void **v85; // [esp-Ch] [ebp-80h]
  void **v86; // [esp-Ch] [ebp-80h]
  float stencil_maska; // [esp+4h] [ebp-70h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> stencil_mask; // [esp+4h] [ebp-70h]
  vostok::render::renderer_context *stencil_mask_4; // [esp+8h] [ebp-6Ch]
  unsigned int v90; // [esp+Ch] [ebp-68h]
  unsigned int v91; // [esp+10h] [ebp-64h]
  unsigned int num_rendered; // [esp+28h] [ebp-4Ch] BYREF
  vostok::render::remove_model_if_not_static_predicate __pred[4]; // [esp+2Ch] [ebp-48h]
  vostok::render::remove_model_if_not_skeletal_predicate v95[4]; // [esp+30h] [ebp-44h]
  vostok::render::remove_model_if_not_translucency_predicate v96[4]; // [esp+34h] [ebp-40h]
  void **v97; // [esp+38h] [ebp-3Ch]
  unsigned int num_shader_lods; // [esp+3Ch] [ebp-38h]
  vostok::render::render_surface_instance *const *end_d; // [esp+40h] [ebp-34h]
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_models; // [esp+44h] [ebp-30h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_translucency_models; // [esp+50h] [ebp-24h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_skeletal_models; // [esp+5Ch] [ebp-18h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_visible_static_models; // [esp+68h] [ebp-Ch] BYREF

  if ( ((unsigned __int8 (__fastcall *)(vostok::render::stage_gbuffer *))this->is_enabled)(this)
    && (v3 = 0, this->m_copy_depth_rt.m_object)
    && this->m_fill_depth_effect.m_object )
  {
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    LOBYTE(v2) = (_BYTE)s_debug_profile_dip;
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 39) = (_BYTE)s_debug_profile_dip;
    *((_BYTE *)m_conflicted_key_name + 38) = 1;
    memset(&m_visible_models, 0, sizeof(m_visible_models));
    memset(&m_visible_static_models, 0, sizeof(m_visible_static_models));
    memset(&m_visible_skeletal_models, 0, sizeof(m_visible_skeletal_models));
    memset(&m_visible_translucency_models, 0, sizeof(m_visible_translucency_models));
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
      v2,
      (int)&m_visible_models,
      0x800u);
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
      v5,
      (int)&m_visible_static_models,
      0x400u);
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
      v6,
      (int)&m_visible_skeletal_models,
      0x400u);
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
      v7,
      (int)&m_visible_translucency_models,
      0x400u);
    m_object = this->m_context->m_targets->m_family[13].target.m_object;
    num_rendered = 0;
    if ( m_object )
    {
      ++m_object->m_reference_count;
      num_rendered = (unsigned int)m_object;
    }
    v9 = this->m_context->m_targets->m_family[12].target.m_object;
    v10 = 0;
    if ( v9 )
    {
      v10 = this->m_context->m_targets->m_family[12].target.m_object;
      ++v9->m_reference_count;
    }
    m_context = this->m_context;
    v12 = m_context->m_targets->m_family[10].target.m_object;
    if ( v12 )
    {
      v3 = (ID3D11RenderTargetView *)m_context->m_targets->m_family[10].target.m_object;
      ++v12->m_reference_count;
    }
    vostok::render::backend::set_render_targets(
      v3,
      v10,
      (const vostok::render::render_target *)num_rendered,
      0,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    if ( v3 )
    {
      if ( !--v3->lpVtbl )
        vostok::render::resource_manager::release(
          v13,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v3);
    }
    if ( v10 )
    {
      if ( !--v10->m_reference_count )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v10);
    }
    v14 = (const char *)num_rendered;
    if ( num_rendered )
    {
      --*(_DWORD *)num_rendered;
      if ( !*(_DWORD *)v14 )
        vostok::render::resource_manager::release(
          v13,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v14);
    }
    v15 = (vostok::render::render_surface_instance *const *)vostok::math::color_rgba(
                                                              0.0,
                                                              COERCE_VOSTOK_MATH_(0.0),
                                                              0.0,
                                                              0.0);
    end_d = v15;
    v16 = vostok::math::color_rgba(*(float *)&clear_value, COERCE_VOSTOK_MATH_(1.0), 1.0, 1.0);
    v17 = vostok::math::color_rgba(*(float *)&clear_value, COERCE_VOSTOK_MATH_(0.5), 0.5, 1.0);
    vostok::render::backend::clear_render_targets(
      v18,
      (_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
      (vostok::math::color)v17,
      (vostok::math::color)v15,
      (vostok::math::color)v16,
      (vostok::math::color)v15);
    v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v20 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
    v21 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v20;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v20;
    *((_BYTE *)v19 + 167) |= !v21;
    v23 = this;
    if ( vostok::command_line::key::is_set(&s_z_only_1) )
      vostok::render::stage_gbuffer::z_only_pass(v22, (unsigned int)this);
    M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
    v25.m_shader_lod_index = 0;
    v21 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 298) == 0;
    num_rendered = 0;
    num_shader_lods = !v21 + 1;
    if ( !v21 != -1 )
    {
      do
      {
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
          (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)M_start,
          (int)&m_visible_models,
          (unsigned int)&this->m_context->m_scene_view.m_object[4].m_sub_fat.m_parent);
        M_finish = m_visible_models._M_impl._M_finish;
        v27 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_lod_predicate>(
                (vostok::render::render_surface_instance **)m_visible_models._M_impl._M_start,
                (vostok::render::render_surface_instance **)m_visible_models._M_impl._M_finish,
                v25);
        if ( v27 != (vostok::render::render_surface_instance **)M_finish )
        {
          v29 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_lod_predicate>(
                           v27 + 1,
                           (vostok::render::render_surface_instance **)M_finish,
                           v27,
                           v25);
          if ( v29 != M_finish )
          {
            v84 = stlp_std::priv::__copy_ptrs<void * *,void * *>(M_finish, M_finish, v29);
            stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
            m_visible_models._M_impl._M_finish = v84;
          }
        }
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
          v28,
          (int)&m_visible_static_models,
          (unsigned int)&m_visible_models);
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
          v30,
          (int)&m_visible_skeletal_models,
          (unsigned int)&m_visible_models);
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
          &m_visible_models._M_impl,
          (int)&m_visible_translucency_models,
          (unsigned int)&m_visible_models);
        v31 = m_visible_static_models._M_impl._M_finish;
        __pred[0] = 0;
        v32 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_static_predicate>(
                (vostok::render::render_surface_instance **)m_visible_static_models._M_impl._M_start,
                (vostok::render::render_surface_instance **)m_visible_static_models._M_impl._M_finish);
        if ( v32 != (vostok::render::render_surface_instance **)v31 )
        {
          v33 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_static_predicate>(
                           v32 + 1,
                           v32,
                           (vostok::render::render_surface_instance **)v31);
          if ( v33 != v31 )
          {
            v85 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v31, v31, v33);
            stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
            v31 = v85;
            m_visible_static_models._M_impl._M_finish = v85;
          }
        }
        v34 = m_visible_skeletal_models._M_impl._M_finish;
        v95[0] = 0;
        v35 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_skeletal_predicate>(
                (vostok::render::render_surface_instance **)m_visible_skeletal_models._M_impl._M_start,
                (vostok::render::render_surface_instance **)m_visible_skeletal_models._M_impl._M_finish);
        if ( v35 != (vostok::render::render_surface_instance **)v34 )
        {
          v36 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_skeletal_predicate>(
                           v35 + 1,
                           v35,
                           (vostok::render::render_surface_instance **)v34);
          if ( v36 != v34 )
          {
            v86 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v34, v34, v36);
            stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
            v34 = v86;
            m_visible_skeletal_models._M_impl._M_finish = v86;
          }
        }
        v37 = m_visible_translucency_models._M_impl._M_finish;
        v96[0] = 0;
        v38 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_translucency_predicate>(
                (vostok::render::render_surface_instance **)m_visible_translucency_models._M_impl._M_start,
                (vostok::render::render_surface_instance **)m_visible_translucency_models._M_impl._M_finish);
        if ( v38 != (vostok::render::render_surface_instance **)v37 )
        {
          v39 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_translucency_predicate>(
                           v38 + 1,
                           v38,
                           (vostok::render::render_surface_instance **)v37);
          if ( v39 != v37 )
          {
            v97 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v37, v37, v39);
            stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
            v37 = v97;
            m_visible_translucency_models._M_impl._M_finish = v97;
          }
        }
        v40 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v21 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) == 130;
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) = 130;
        *((_BYTE *)v40 + 147) |= !v21;
        stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
          (vostok::render::render_surface_instance **)m_visible_static_models._M_impl._M_start,
          (vostok::render::render_surface_instance **)v31,
          0);
        vostok::render::stage_gbuffer::render_models(
          &m_visible_static_models,
          this,
          v25.m_shader_lod_index,
          &num_rendered,
          0);
        v41 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v21 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) == 133;
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) = 133;
        v42 = m_visible_skeletal_models._M_impl._M_start;
        *((_BYTE *)v41 + 147) |= !v21;
        stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
          (vostok::render::render_surface_instance **)v42,
          (vostok::render::render_surface_instance **)v34,
          0);
        v23 = this;
        vostok::render::stage_gbuffer::render_models(
          &m_visible_skeletal_models,
          this,
          v25.m_shader_lod_index,
          &num_rendered,
          0);
        v43 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v21 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) == 132;
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) = 132;
        v44 = m_visible_translucency_models._M_impl._M_start;
        *((_BYTE *)v43 + 147) |= !v21;
        stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
          (vostok::render::render_surface_instance **)v44,
          (vostok::render::render_surface_instance **)v37,
          0);
        vostok::render::stage_gbuffer::render_models(
          &m_visible_translucency_models,
          this,
          v25.m_shader_lod_index++,
          &num_rendered,
          0);
      }
      while ( v25.m_shader_lod_index < num_shader_lods );
      v15 = end_d;
    }
    v45 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v21 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) == 130;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 33) = 130;
    LOBYTE(M_start) = !v21;
    *((_BYTE *)v45 + 147) |= !v21;
    v46 = v23->m_context;
    m_scene = v46->m_scene;
    if ( m_scene->m_grass )
    {
      stencil_maska = 1000000.0;
      vostok::render::grass_world::render(
        (vostok::render::grass_world *)v46,
        (vostok::render::renderer_context *)m_scene->m_grass,
        (const vostok::math::float3 *)v46,
        (vostok::render::enum_render_stage_type)&v46->m_view_pos,
        0,
        0.0,
        SLOBYTE(stencil_maska),
        0,
        v90,
        v91);
    }
    vostok::render::stage_gbuffer::render_particles(
      (vostok::render::stage_gbuffer *)M_start,
      (vostok::particle::render_particle_emitter_instance *const *)v23,
      0);
    v49 = &v23->m_copy_depth_rt.m_object->__vftable;
    if ( v49 )
    {
      v50 = (v49[71] - v49[70]) >> 2;
      if ( v50 )
      {
        v49[69] = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v50, v90);
      }
      v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v51 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                *(vostok::render::textures_handler<0> **)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                          + 540)
                                                                        + 216),
                                (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                              + 1488,
                                (vostok::render::res_texture *)&stru_963F84,
                                *(vostok::render::res_texture **)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                  + 540)
                                                                + 216));
      stencil_mask_4 = v23->m_context;
      stencil_mask.m_object = 0;
      v52 = stencil_mask_4->m_targets->m_family[9].target.m_object;
      if ( v52 )
      {
        stencil_mask.m_object = stencil_mask_4->m_targets->m_family[9].target.m_object;
        ++v52->m_reference_count;
      }
      vostok::render::fill_surface(stencil_mask, stencil_mask_4);
    }
    v53 = m_visible_translucency_models._M_impl._M_start;
    if ( m_visible_translucency_models._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v53);
    }
    v55 = m_visible_skeletal_models._M_impl._M_start;
    if ( m_visible_skeletal_models._M_impl._M_start )
    {
      v56 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v56, v55);
    }
    v57 = m_visible_static_models._M_impl._M_start;
    if ( m_visible_static_models._M_impl._M_start )
    {
      v58 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v58, v57);
    }
    v59 = m_visible_models._M_impl._M_start;
    if ( m_visible_models._M_impl._M_start )
    {
      v60 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v60, v59);
    }
    if ( v23->m_fill_view_space_depth )
    {
      v61 = v23->m_context;
      v62 = v61->m_targets->m_family[9].target.m_object;
      v63 = 0;
      if ( v62 )
      {
        v63 = (vostok::render::resource_manager *)v61->m_targets->m_family[9].target.m_object;
        ++v62->m_reference_count;
        m_rt = v62->m_rt;
      }
      else
      {
        m_rt = 0;
      }
      v65 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != m_rt )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
        v65[163] = 1;
      }
      if ( *((_DWORD *)v65 + 536) )
      {
        *((_DWORD *)v65 + 536) = 0;
        v65[164] = 1;
      }
      if ( *((_DWORD *)v65 + 537) )
      {
        *((_DWORD *)v65 + 537) = 0;
        v65[165] = 1;
      }
      if ( *((_DWORD *)v65 + 538) )
      {
        *((_DWORD *)v65 + 538) = 0;
        v65[166] = 1;
      }
      if ( v63 )
      {
        v21 = v63->sh_created-- == 1;
        if ( v21 )
        {
          vostok::render::resource_manager::release(
            v63,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v63);
          v65 = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      vostok::render::backend::clear_render_targets(
        (vostok::render::backend *)v63,
        v65,
        (vostok::math::color)v15,
        (vostok::math::color)v15,
        (vostok::math::color)v15,
        (vostok::math::color)v15);
      v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v67 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
      v21 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v67;
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v67;
      *((_BYTE *)v66 + 167) |= !v21;
      if ( s_debug_enabled_ds_clearing_value && v67 )
      {
        (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 212))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v67,
          3,
          1.0,
          0);
        v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
      v48 = v23->m_context;
      v68 = (ID3D11ShaderResourceView *)v48->m_scene_view.m_object;
      v69 = (vostok::render::render_surface_instance *const *)v68[336].lpVtbl;
      v70 = (vostok::render::render_surface_instance *const *)v68[335].lpVtbl;
      for ( end_d = v69; v70 != v69; ++v70 )
      {
        v71 = *v70;
        v72 = **(_DWORD **)v70;
        v73 = *(_DWORD *)(v72 + 148);
        LOBYTE(v48) = *(_DWORD *)(v72 + 4) == 1;
        if ( !v73 || s_use_one_material_value )
          v74 = s_nomaterial_material_effects[*(_DWORD *)(v72 + 4)];
        else
          v74 = (vostok::render::material_effects *)(v73 + 264);
        if ( v74->m_effects[0].m_object && *(_DWORD *)(v72 + 4) != 1 && *(_DWORD *)(v72 + 48) )
        {
          vostok::render::renderer_context::set_w(this->m_context, v71->m_transform);
          v76 = this->m_fill_depth_effect.m_object;
          if ( (unsigned int)(v76->m_techniques._M_impl._M_finish - v76->m_techniques._M_impl._M_start) > 2 )
          {
            v76->m_cur_technique = 2;
            vostok::render::res_effect::apply_pass(v75, v90);
          }
          v71->m_parent->set_constants(v71->m_parent);
          vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v72 + 48));
          v78 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          v79 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 529) != 4;
          v80 = 3 * *(_DWORD *)(v72 + 68);
          v81 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v79;
          if ( v79 )
            *((_DWORD *)v78 + 529) = 4;
          vostok::render::backend::flush(v77, (int)v78);
          if ( v81[104] )
          {
            ++*((_DWORD *)v81 + 25);
            v48 = 3 * s_max_triagles_per_dip_value < v80
                ? (vostok::render::renderer_context *)(3 * s_max_triagles_per_dip_value - v80)
                : 0;
            v80 += (unsigned int)v48;
          }
          if ( !v81[37] )
            (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                     + 48))(
              `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
              v80,
              0,
              0);
          v82 = 2863311531LL * v80;
          v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_DWORD *)v81 + 21) += HIDWORD(v82) >> 1;
          v69 = end_d;
        }
      }
    }
    else
    {
      v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
    vostok::render::backend::reset_render_targets((vostok::render::backend *)v48, (int)v66);
    v83 = *((_DWORD *)v66 + 547);
    v21 = *((_DWORD *)v66 + 539) == v83;
    *((_DWORD *)v66 + 539) = v83;
    *((_BYTE *)v66 + 167) |= !v21;
    *((_BYTE *)v66 + 38) = 1;
    *((_BYTE *)v66 + 39) = 0;
    LOBYTE(s_debug_profile_dip) = 0;
  }
  else
  {
    this->execute_disabled(this);
  }
}
