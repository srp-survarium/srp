void __thiscall vostok::render::stage_shadow_direct::execute(vostok::render::stage_shadow_direct *this)
{
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v3; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v5; // edi
  vostok::render::light *v6; // ecx
  bool v7; // zf
  vostok::render::grass_render_model *v8; // esi
  vostok::render::light *v9; // ecx
  __int64 v10; // xmm0_8
  unsigned int v11; // esi
  const char *m_conflicted_key_name; // eax
  vostok::render::render_target *v13; // ecx
  vostok::render::backend *m_zrt; // ecx
  vostok::render::stage_shadow_direct *v15; // ecx
  unsigned int i; // edi
  const char *v17; // esi
  int v18; // eax
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_effect_shadow_direct.m_object )
  {
    m_object = this->m_context->m_scene->m_lights.m_object;
    v3 = m_object->m_sun.m_object;
    p_m_sun = &m_object->m_sun;
    if ( v3
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && !v3->m_enabled )
    {
      v5 = 0;
    }
    else
    {
      object.m_object = 0;
      vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v3,
        &object,
        p_m_sun);
      v5 = object.m_object;
      if ( object.m_object )
      {
        v7 = object.m_object->m_reference_count-- == 1;
        if ( v7 )
        {
          v8 = vostok::render::g_allocator.m_object;
          vostok::render::light::~light(v6, (int)v5);
          BYTE2(v8->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v8->m_reconstruction_info_actuality_tick), v5);
        }
      }
    }
    if ( !this->is_enabled(this) )
      goto LABEL_28;
    if ( !v5 )
      return;
    if ( vostok::render::light::is_cast_shadows(v9, (int)v5) )
    {
      if ( (_S7_4 & 1) == 0 )
      {
        v10 = *(_QWORD *)&v5->direction.x;
        _S7_4 |= 1u;
        *(_QWORD *)&s_prev_sun_direction.x = v10;
        s_prev_sun_direction.z = v5->direction.z;
      }
      v11 = 4
          - *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
            + 42);
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        &this->m_t_shadow_map,
        &this->m_context->m_t_shadow_cascade.m_object);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = 0;
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
      v13 = this->m_rt_shadow_map.m_object;
      if ( v13 )
        m_zrt = (vostok::render::backend *)v13->m_zrt;
      else
        m_zrt = 0;
      v7 = *((_DWORD *)m_conflicted_key_name + 539) == (_DWORD)m_zrt;
      *((_DWORD *)m_conflicted_key_name + 539) = m_zrt;
      *((_BYTE *)m_conflicted_key_name + 167) |= !v7;
      vostok::render::backend::clear_depth_stencil(m_zrt, (int)m_conflicted_key_name);
      for ( i = 0; v11 < 4; ++i )
        vostok::render::stage_shadow_direct::execute_cascade(v15, this, v11++, i, this->m_cascade_shadow_map_size);
      v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::backend::reset_render_targets(
        (vostok::render::backend *)v15,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      v18 = *((_DWORD *)v17 + 547);
      v7 = *((_DWORD *)v17 + 539) == v18;
      *((_DWORD *)v17 + 539) = v18;
      *((_BYTE *)v17 + 167) |= !v7;
      this->m_invalid_shadow = 0;
    }
    else
    {
LABEL_28:
      this->execute_disabled(this);
    }
  }
}
