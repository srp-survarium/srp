void __thiscall vostok::render::stage_forward::execute(vostok::render::stage_forward *this)
{
  vostok::render::res_texture *v2; // esi
  int v3; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *i; // ecx
  int y; // ecx
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v7; // edi
  ID3D11Resource *m_surface; // edx
  vostok::render::res_texture *v9; // eax
  vostok::render::res_texture *v10; // ecx
  unsigned int v11; // ecx
  double v12; // st6
  void **M_finish; // esi
  vostok::render::render_surface_instance **v14; // eax
  vostok::render::stage_forward *v15; // ecx
  vostok::render::render_target *v16; // eax
  vostok::render::render_target *v17; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  bool v20; // zf
  const vostok::math::float4x4 *v21; // eax
  const char *v22; // esi
  vostok::render::backend *v23; // ecx
  int v24; // eax
  void **M_start; // eax
  vostok::render::grass_render_model *v26; // ecx
  vostok::render::stage_forward *v27; // ecx
  vostok::render::scene *m_scene; // esi
  const char *v29; // eax
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *v30; // ecx
  vostok::collision::space_partitioning_tree *m_decals_tree; // ecx
  const void **v32; // eax
  const void **v33; // esi
  vostok::render::render_target *v34; // eax
  ID3D11RenderTargetView *v35; // ecx
  const char *v36; // eax
  const char *v37; // eax
  int v38; // ecx
  const void **v39; // ebx
  vostok::render::statistics *v40; // eax
  vostok::render::renderer_context *v41; // edx
  vostok::render::decal_instance *v42; // ecx
  int *p_value; // edi
  vostok::render::res_effect *v44; // eax
  const vostok::math::float4x4 *v45; // eax
  const char *v46; // esi
  vostok::render::backend *v47; // ecx
  int v48; // eax
  void **v49; // eax
  vostok::render::grass_render_model *v50; // ecx
  vostok::render::res_effect *v51; // [esp+0h] [ebp-B0h] BYREF
  int v52; // [esp+4h] [ebp-ACh]
  vostok::render::vector<vostok::render::render_surface_instance *> *v53; // [esp+8h] [ebp-A8h]
  bool v54; // [esp+Ch] [ebp-A4h]
  vostok::render::remove_model_if_not_forward_predicate __pred[4]; // [esp+18h] [ebp-98h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_dynamic_visuals; // [esp+1Ch] [ebp-94h] BYREF
  vostok::vectora<vostok::collision::object const *> decals_objects; // [esp+28h] [ebp-88h] BYREF
  vostok::math::frustum frustum; // [esp+38h] [ebp-78h] BYREF

  v2 = 0;
  v3 = 0;
  for ( i = this->m_gbuffer_depth_effect; v3 == 12 || i->m_object; ++i )
  {
    if ( (unsigned int)++v3 >= 0xF )
    {
      if ( this->m_opaque_geometry_mask_effect.m_object && this->m_debug_tracer_effect.m_object )
      {
        if ( this->is_enabled(this) )
        {
          memset(&m_dynamic_visuals, 0, sizeof(m_dynamic_visuals));
          y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
          m_object = this->m_context->m_targets->m_family[47].texture.m_object;
          v7 = 0;
          if ( m_object )
          {
            v7 = this->m_context->m_targets->m_family[47].texture.m_object;
            ++m_object->m_reference_count;
          }
          m_surface = v7->m_surface;
          v9 = this->m_context->m_targets->m_family[48].texture.m_object;
          if ( v9 )
          {
            v2 = this->m_context->m_targets->m_family[48].texture.m_object;
            ++v9->m_reference_count;
          }
          (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)y + 188))(
            y,
            v2->m_surface,
            m_surface);
          if ( !--v2->m_reference_count )
            vostok::render::res_texture::destroy_impl(v10, v2);
          if ( !--v7->m_reference_count )
            vostok::render::res_texture::destroy_impl(v10, v7);
          this->m_rain_offset_counter = (float)(this->m_context->m_time_delta * 2.0) + this->m_rain_offset_counter;
          v11 = 134775813 * s_random_0.m_seed + 1;
          *(_DWORD *)__pred = (((unsigned int)&loc_FFFFF + 1) * (unsigned __int64)v11) >> 32;
          s_random_0.m_seed = v11;
          if ( this->m_rain_offset_counter >= (double)*(unsigned int *)__pred * 0.00000095367432 * 0.5
                                            + *(float *)&clear_value )
          {
            s_random_0.m_seed = 134775813 * v11 + 1;
            *(_DWORD *)__pred = (((unsigned int)&loc_FFFFF + 1) * (unsigned __int64)s_random_0.m_seed) >> 32;
            v12 = (double)*(unsigned int *)__pred;
            this->m_rain_offset_counter = 0.0;
            this->m_rain_offset = 0.00000095367432 * v12 * 0.75 + this->m_rain_offset;
          }
          vostok::render::scene::select_models(
            this->m_context->m_scene,
            &this->m_context->m_vp,
            &m_dynamic_visuals,
            (const vostok::math::float3 *)&this->m_context->m_view_pos,
            1u,
            0);
          M_finish = m_dynamic_visuals._M_impl._M_finish;
          __pred[0] = 0;
          v52 = *(_DWORD *)__pred;
          v14 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_forward_predicate>(
                  (vostok::render::render_surface_instance **)m_dynamic_visuals._M_impl._M_start,
                  (vostok::render::render_surface_instance **)m_dynamic_visuals._M_impl._M_finish);
          if ( v14 != (vostok::render::render_surface_instance **)M_finish )
          {
            v52 = *(_DWORD *)__pred;
            v14 = stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_if_not_forward_predicate>(
                    v14 + 1,
                    v14,
                    (vostok::render::render_surface_instance **)M_finish);
          }
          stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
            (void **)v14,
            M_finish,
            (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)&m_dynamic_visuals);
          vostok::render::renderer::sort_models_by_distance((vostok::render::renderer *)&m_dynamic_visuals, v53, v54);
          if ( this->m_type == forward_sky )
            vostok::render::stage_forward::render_forward_models(&m_dynamic_visuals, this, 1u);
          v15 = (vostok::render::stage_forward *)((char *)m_dynamic_visuals._M_impl._M_finish
                                                - (char *)m_dynamic_visuals._M_impl._M_start);
          if ( (((char *)m_dynamic_visuals._M_impl._M_finish - (char *)m_dynamic_visuals._M_impl._M_start) & 0xFFFFFFFC) != 0 )
          {
            v16 = this->m_context->m_targets->m_family[47].target.m_object;
            v17 = 0;
            if ( v16 )
            {
              v17 = this->m_context->m_targets->m_family[47].target.m_object;
              ++v16->m_reference_count;
              m_rt = v16->m_rt;
            }
            else
            {
              m_rt = 0;
            }
            m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                 + 535) != m_rt )
            {
              *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
              *((_BYTE *)m_conflicted_key_name + 163) = 1;
            }
            if ( *((_DWORD *)m_conflicted_key_name + 536) )
            {
              *((_DWORD *)m_conflicted_key_name + 536) = 0;
              *((_BYTE *)m_conflicted_key_name + 164) = 1;
            }
            if ( *((_DWORD *)m_conflicted_key_name + 537) )
            {
              *((_DWORD *)m_conflicted_key_name + 537) = 0;
              *((_BYTE *)m_conflicted_key_name + 165) = 1;
            }
            if ( *((_DWORD *)m_conflicted_key_name + 538) )
            {
              *((_DWORD *)m_conflicted_key_name + 538) = 0;
              *((_BYTE *)m_conflicted_key_name + 166) = 1;
            }
            if ( v17 )
            {
              if ( !--v17->m_reference_count )
              {
                vostok::render::resource_manager::release(
                  (vostok::render::resource_manager *)v17,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (const char *)v17);
                m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              }
            }
            v15 = (vostok::render::stage_forward *)*((_DWORD *)m_conflicted_key_name + 547);
            v20 = *((_DWORD *)m_conflicted_key_name + 539) == (_DWORD)v15;
            *((_DWORD *)m_conflicted_key_name + 539) = v15;
            *((_BYTE *)m_conflicted_key_name + 167) |= !v20;
          }
          if ( this->m_type == forward_sky )
          {
            v21 = vostok::math::float4x4::identity((vostok::math::float4x4 *)&frustum);
            vostok::render::renderer_context::set_w(this->m_context, v21);
            v22 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            vostok::render::backend::reset_render_targets(
              v23,
              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
            v24 = *((_DWORD *)v22 + 547);
            v20 = *((_DWORD *)v22 + 539) == v24;
            *((_DWORD *)v22 + 539) = v24;
            *((_BYTE *)v22 + 167) |= !v20;
            M_start = m_dynamic_visuals._M_impl._M_start;
            if ( m_dynamic_visuals._M_impl._M_start )
            {
              v26 = vostok::render::g_allocator.m_object;
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free((void *)HIDWORD(v26->m_reconstruction_info_actuality_tick), M_start);
            }
          }
          else
          {
            vostok::render::stage_forward::render_opaque_models(v15, this);
            vostok::render::stage_forward::accumulate_local_reflections(v27, (int)this);
            vostok::render::stage_forward::render_forward_models(&m_dynamic_visuals, this, 0);
            m_scene = this->m_context->m_scene;
            v29 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            decals_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
            v30 = (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
            v20 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                  + 539) == (_DWORD)v30;
            decals_objects._M_impl._M_start = 0;
            *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 167) |= !v20;
            decals_objects._M_impl._M_finish = 0;
            decals_objects._M_impl._M_end_of_storage._M_data = 0;
            *((_DWORD *)v29 + 539) = v30;
            stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::reserve(
              v30,
              &decals_objects._M_impl,
              m_scene->m_decals.m_size);
            vostok::math::frustum::frustum(&frustum, &this->m_context->m_vp);
            m_decals_tree = this->m_context->m_scene->m_decals_tree;
            m_decals_tree->cuboid_query(m_decals_tree, -1u, &frustum, &decals_objects);
            v32 = decals_objects._M_impl._M_finish;
            v33 = decals_objects._M_impl._M_start;
            if ( (((char *)decals_objects._M_impl._M_finish - (char *)decals_objects._M_impl._M_start) & 0xFFFFFFFC) != 0 )
            {
              v34 = vostok::render::renderer_context::get_rt(
                      (vostok::render::renderer_context *)0x2F,
                      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__pred,
                      this->m_context,
                      (vostok::render::enum_render_target_index)v53)->m_object;
              if ( v34 )
                v35 = v34->m_rt;
              else
                v35 = 0;
              v36 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                   + 535) != v35 )
              {
                *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 535) = v35;
                *((_BYTE *)v36 + 163) = 1;
              }
              if ( *((_DWORD *)v36 + 536) )
              {
                *((_DWORD *)v36 + 536) = 0;
                *((_BYTE *)v36 + 164) = 1;
              }
              if ( *((_DWORD *)v36 + 537) )
              {
                *((_DWORD *)v36 + 537) = 0;
                *((_BYTE *)v36 + 165) = 1;
              }
              if ( *((_DWORD *)v36 + 538) )
              {
                *((_DWORD *)v36 + 538) = 0;
                *((_BYTE *)v36 + 166) = 1;
              }
              vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__pred);
              v37 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              v38 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                    + 547);
              v20 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                    + 539) == v38;
              *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v38;
              *((_BYTE *)v37 + 167) |= !v20;
              v32 = decals_objects._M_impl._M_finish;
              v33 = decals_objects._M_impl._M_start;
            }
            v39 = v32;
            if ( v33 != v32 )
            {
              v40 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
              do
              {
                v41 = (vostok::render::renderer_context *)*((_DWORD *)*v33 + 9);
                v52 = 17;
                v42 = (vostok::render::decal_instance *)&v51;
                p_value = &v40->forward_decals_stat_group.num_decal_draw_calls.value;
                v51 = 0;
                v44 = this->m_opaque_geometry_mask_effect.m_object;
                if ( v44 )
                {
                  v51 = this->m_opaque_geometry_mask_effect.m_object;
                  v42 = (vostok::render::decal_instance *)_InterlockedExchangeAdd(&v44->m_reference_count, 1u);
                }
                *p_value += vostok::render::decal_instance::draw(
                              v42,
                              v41,
                              (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>)this->m_context,
                              (vostok::render::enum_render_stage_type)v51);
                v40 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
                ++vostok::quasi_singleton<vostok::render::statistics>::pinst->forward_decals_stat_group.num_decals.value;
                ++v33;
              }
              while ( v33 != v39 );
              v33 = decals_objects._M_impl._M_start;
            }
            if ( v33 )
              decals_objects._M_impl._M_end_of_storage.m_allocator->call_free(
                decals_objects._M_impl._M_end_of_storage.m_allocator,
                v33);
            v45 = vostok::math::float4x4::identity((vostok::math::float4x4 *)&frustum);
            vostok::render::renderer_context::set_w(this->m_context, v45);
            v46 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            vostok::render::backend::reset_render_targets(
              v47,
              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
            v48 = *((_DWORD *)v46 + 547);
            v20 = *((_DWORD *)v46 + 539) == v48;
            *((_DWORD *)v46 + 539) = v48;
            *((_BYTE *)v46 + 167) |= !v20;
            v49 = m_dynamic_visuals._M_impl._M_start;
            if ( m_dynamic_visuals._M_impl._M_start )
            {
              v50 = vostok::render::g_allocator.m_object;
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free((void *)HIDWORD(v50->m_reconstruction_info_actuality_tick), v49);
            }
          }
        }
        else
        {
          this->execute_disabled(this);
        }
      }
      return;
    }
  }
}
