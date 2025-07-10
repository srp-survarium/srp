void __thiscall vostok::render::stage_decals_accumulate::execute(vostok::render::stage_decals_accumulate *this)
{
  void **M_start; // esi
  int v3; // edi
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v5; // esi
  vostok::render::render_target *v6; // eax
  vostok::render::render_target *v7; // eax
  char *m_conflicted_key_name; // ebx
  vostok::render::resource_manager *v9; // ecx
  vostok::render::render_target *v10; // eax
  const vostok::render::render_target *v11; // eax
  int v12; // esi
  int v13; // eax
  vostok::render::backend *v14; // ecx
  unsigned int v15; // ecx
  void **v16; // edi
  char i; // bl
  vostok::render::renderer_context *v18; // edx
  vostok::render::decal_instance *p_size_y; // ecx
  vostok::render::res_effect *v20; // eax
  int *p_value; // esi
  vostok::render::backend *v22; // ecx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v24; // eax
  const vostok::render::renderer_context_targets *v25; // eax
  vostok::render::render_target *v26; // eax
  const vostok::render::renderer_context_targets *v27; // eax
  vostok::render::render_target *v28; // eax
  const char *v29; // esi
  int v30; // eax
  bool v31; // zf
  void **v32; // eax
  vostok::render::grass_render_model *v33; // ecx
  vostok::render::grass_render_model *v34; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v35; // [esp-4h] [ebp-84h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v36; // [esp+0h] [ebp-80h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v37; // [esp+4h] [ebp-7Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v38; // [esp+8h] [ebp-78h]
  BOOL v39; // [esp+Ch] [ebp-74h]
  int v40; // [esp+10h] [ebp-70h]
  float v41; // [esp+14h] [ebp-6Ch]
  float pos_y; // [esp+18h] [ebp-68h]
  float size_x; // [esp+1Ch] [ebp-64h]
  float size_y; // [esp+20h] [ebp-60h] BYREF
  vostok::render::renderer_context *a; // [esp+24h] [ebp-5Ch]
  vostok::render::backend *v46; // [esp+28h] [ebp-58h]
  vostok::render::render_target *rt0; // [esp+3Ch] [ebp-44h]
  vostok::render::stage_decals_accumulate::execute::__l4::sort_by_priority_predicate __comp[4]; // [esp+40h] [ebp-40h] BYREF
  vostok::render::vector<vostok::render::decal_instance *> visible_decals; // [esp+44h] [ebp-3Ch] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+50h] [ebp-30h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+68h] [ebp-18h] BYREF

  if ( this->m_opaque_geometry_mask_effect.m_object && this->m_apply_decal_effect.m_object )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_Impl_vector<void *,vostok::render::std_allocator<void *>>(
      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)this,
      (unsigned __int8 **)&visible_decals,
      (const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&this->m_context->m_scene_view.m_object[4].m_next_in_global_delay_delete_list);
    M_start = visible_decals._M_impl._M_start;
    v3 = visible_decals._M_impl._M_finish - visible_decals._M_impl._M_start;
    if ( v3 )
    {
      __comp[0] = 0;
      ___sort_PAPAUdecal_instance_render_vostok__Usort_by_priority_predicate__3__execute_stage_decals_accumulate_23_UAEXXZ__stlp_std__YAXPAPAUdecal_instance_render_vostok__0Usort_by_priority_predicate__3__execute_stage_decals_accumulate_23_UAEXXZ__Z(
        (vostok::render::decal_instance **)visible_decals._M_impl._M_start,
        (vostok::render::decal_instance **)visible_decals._M_impl._M_finish,
        0);
    }
    if ( this->is_enabled(this) && v3 )
    {
      m_object = this->m_context->m_targets->m_family[25].target.m_object;
      v5 = 0;
      if ( m_object )
      {
        v5 = this->m_context->m_targets->m_family[25].target.m_object;
        ++m_object->m_reference_count;
      }
      v6 = this->m_context->m_targets->m_family[24].target.m_object;
      *(_DWORD *)__comp = 0;
      if ( v6 )
      {
        ++v6->m_reference_count;
        *(_DWORD *)__comp = v6;
      }
      v7 = this->m_context->m_targets->m_family[23].target.m_object;
      rt0 = 0;
      if ( v7 )
      {
        ++v7->m_reference_count;
        rt0 = v7;
      }
      m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::set_render_targets(
        (ID3D11RenderTargetView *)rt0,
        *(const vostok::render::render_target **)__comp,
        v5,
        0,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v10 = rt0;
      if ( rt0 )
      {
        --rt0->m_reference_count;
        if ( !v10->m_reference_count )
        {
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v10);
          m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      v11 = *(const vostok::render::render_target **)__comp;
      if ( *(_DWORD *)__comp )
      {
        --**(_DWORD **)__comp;
        if ( !v11->m_reference_count )
        {
          vostok::render::resource_manager::release(
            v9,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v11);
          m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      if ( v5 )
      {
        if ( !--v5->m_reference_count )
        {
          vostok::render::resource_manager::release(
            v9,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (const char *)v5);
          m_conflicted_key_name = (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        }
      }
      m_conflicted_key_name[167] |= *((_DWORD *)m_conflicted_key_name + 539) != 0;
      *(float *)&a = 0.0;
      *((_DWORD *)m_conflicted_key_name + 539) = 0;
      v12 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, *(float *)&a);
      v13 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 0.0);
      vostok::render::backend::clear_render_targets(
        v14,
        m_conflicted_key_name,
        (vostok::math::color)v12,
        (vostok::math::color)v13,
        (vostok::math::color)v12,
        (vostok::math::color)v12);
      vostok::render::backend::get_viewport(v15, &orig_viewport, v46);
      a = this->m_context;
      tmp_viewport.TopLeftX = 0.0;
      tmp_viewport.TopLeftY = 0.0;
      rt0 = (vostok::render::render_target *)vostok::render::renderer_context::get_rt(
                                               (vostok::render::renderer_context *)0x17,
                                               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__comp,
                                               a,
                                               (vostok::render::enum_render_target_index)v46)->m_object->m_width;
      tmp_viewport.Width = (float)(unsigned int)rt0;
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__comp);
      tmp_viewport.Height = (float)vostok::render::renderer_context::get_rt(
                                     (vostok::render::renderer_context *)0x17,
                                     (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__comp,
                                     this->m_context,
                                     (vostok::render::enum_render_target_index)v46)->m_object->m_height;
      vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__comp);
      tmp_viewport.MinDepth = 0.0;
      LODWORD(tmp_viewport.MaxDepth) = clear_value;
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &tmp_viewport);
      v16 = visible_decals._M_impl._M_start;
      for ( i = 0; v16 != visible_decals._M_impl._M_finish; ++v16 )
      {
        v18 = (vostok::render::renderer_context *)*v16;
        if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
              + 288)
          || !v18->m_family[0].name.m_buffer[60] )
        {
          a = (vostok::render::renderer_context *)1;
          p_size_y = (vostok::render::decal_instance *)&size_y;
          size_y = 0.0;
          v20 = this->m_opaque_geometry_mask_effect.m_object;
          p_value = &vostok::quasi_singleton<vostok::render::statistics>::pinst->deferred_decals_stat_group.num_decal_draw_calls.value;
          if ( v20 )
          {
            size_y = *(float *)&this->m_opaque_geometry_mask_effect.m_object;
            p_size_y = (vostok::render::decal_instance *)_InterlockedExchangeAdd(&v20->m_reference_count, 1u);
          }
          *p_value += vostok::render::decal_instance::draw(
                        p_size_y,
                        v18,
                        (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>)this->m_context,
                        SLODWORD(size_y));
          i = 1;
        }
      }
      (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                        + 176))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        1,
        &orig_viewport);
      if ( i )
      {
        vostok::render::res_effect::apply(0, &this->m_apply_decal_effect.m_object->__vftable);
        *(float *)&a = 1.0;
        size_y = 1.0;
        size_x = 0.0;
        pos_y = 0.0;
        v41 = 0.0;
        v40 = 1;
        v39 = 0;
        v38.m_object = 0;
        v37.m_object = 0;
        v36.m_object = 0;
        m_targets = this->m_context->m_targets;
        v35.m_object = 0;
        v24 = m_targets->m_family[27].target.m_object;
        if ( v24 )
        {
          v35.m_object = v24;
          ++v24->m_reference_count;
        }
        vostok::render::system_renderer::fill_surface(
          (vostok::render::system_renderer *)&v35,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v35,
          v36,
          v37,
          v38,
          v39,
          (D3D11_VIEWPORT *)v40,
          v41,
          pos_y,
          size_x,
          size_y);
        vostok::render::backend::flush_rt_shader_resources(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)1,
          &this->m_apply_decal_effect.m_object->__vftable);
        *(float *)&a = 1.0;
        size_y = 1.0;
        size_x = 0.0;
        pos_y = 0.0;
        v41 = 0.0;
        v40 = 1;
        v39 = 0;
        v38.m_object = 0;
        v37.m_object = 0;
        v36.m_object = 0;
        v25 = this->m_context->m_targets;
        v35.m_object = 0;
        v26 = v25->m_family[10].target.m_object;
        if ( v26 )
        {
          v35.m_object = v26;
          ++v26->m_reference_count;
        }
        vostok::render::system_renderer::fill_surface(
          (vostok::render::system_renderer *)&v35,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v35,
          v36,
          v37,
          v38,
          v39,
          (D3D11_VIEWPORT *)v40,
          v41,
          pos_y,
          size_x,
          size_y);
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)2,
          &this->m_apply_decal_effect.m_object->__vftable);
        *(float *)&a = 1.0;
        size_y = 1.0;
        size_x = 0.0;
        pos_y = 0.0;
        v41 = 0.0;
        v40 = 1;
        v39 = 0;
        v38.m_object = 0;
        v37.m_object = 0;
        v36.m_object = 0;
        v27 = this->m_context->m_targets;
        v35.m_object = 0;
        v28 = v27->m_family[12].target.m_object;
        if ( v28 )
        {
          v35.m_object = v28;
          ++v28->m_reference_count;
        }
        vostok::render::system_renderer::fill_surface(
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          v35,
          v36,
          v37,
          v38,
          v39,
          (D3D11_VIEWPORT *)v40,
          v41,
          pos_y,
          size_x,
          size_y);
      }
      v29 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        v22,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v30 = *((_DWORD *)v29 + 547);
      v31 = *((_DWORD *)v29 + 539) == v30;
      *((_DWORD *)v29 + 539) = v30;
      v32 = visible_decals._M_impl._M_start;
      *((_BYTE *)v29 + 167) |= !v31;
      if ( v32 )
      {
        v33 = vostok::render::g_allocator.m_object;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v33->m_reconstruction_info_actuality_tick), v32);
      }
    }
    else
    {
      this->execute_disabled(this);
      if ( M_start )
      {
        v34 = vostok::render::g_allocator.m_object;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v34->m_reconstruction_info_actuality_tick), M_start);
      }
    }
  }
}
