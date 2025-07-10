void __thiscall vostok::render::stage_shadow_direct::execute_disabled(vostok::render::stage_shadow_direct *this)
{
  unsigned int m_zrt; // ebx
  vostok::render::lights_db *m_object; // eax
  vostok::render::light *v4; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v6; // ecx
  vostok::render::light *v7; // edi
  vostok::render::grass_render_model *v9; // esi
  const char *m_conflicted_key_name; // eax
  vostok::render::render_target *v11; // ecx
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+8h] [ebp-4h] BYREF

  m_zrt = 0;
  if ( this->m_effect_shadow_direct.m_object )
  {
    m_object = this->m_context->m_scene->m_lights.m_object;
    v4 = m_object->m_sun.m_object;
    p_m_sun = &m_object->m_sun;
    if ( !v4
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      || v4->m_enabled )
    {
      object.m_object = 0;
      vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4,
        &object,
        p_m_sun);
      v7 = object.m_object;
      if ( object.m_object )
      {
        if ( object.m_object->m_reference_count-- == 1 )
        {
          v9 = vostok::render::g_allocator.m_object;
          vostok::render::light::~light(v6, (int)v7);
          BYTE2(v9->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v9->m_reconstruction_info_actuality_tick), v7);
        }
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
        v11 = this->m_rt_shadow_map.m_object;
        if ( v11 )
          m_zrt = (unsigned int)v11->m_zrt;
        LOBYTE(v11) = *((_DWORD *)m_conflicted_key_name + 539) != m_zrt;
        *((_BYTE *)m_conflicted_key_name + 167) |= (unsigned __int8)v11;
        *((_DWORD *)m_conflicted_key_name + 539) = m_zrt;
        vostok::render::backend::clear_depth_stencil((vostok::render::backend *)v11, (int)m_conflicted_key_name);
      }
    }
  }
}
