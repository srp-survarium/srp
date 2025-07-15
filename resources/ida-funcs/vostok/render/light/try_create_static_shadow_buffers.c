void __thiscall vostok::render::light::try_create_static_shadow_buffers(
        vostok::render::light *this,
        int force_create_new,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object)
{
  int v3; // edi
  int v4; // eax
  vostok::render::res_texture *v5; // ebx
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **v6; // ebx
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  vostok::render::resource_manager *v8; // ecx
  vostok::render::res_texture *v9; // eax
  unsigned int v11; // [esp+0h] [ebp-10h]
  vostok::render::res_texture *m_object; // [esp+Ch] [ebp-4h]
  vostok::render::res_texture *v13; // [esp+Ch] [ebp-4h]

  v3 = force_create_new;
  if ( *(_BYTE *)(force_create_new + 625) )
  {
    v4 = *(_DWORD *)(force_create_new + 860) & 0xF;
    if ( v4 != 4 && (LOBYTE(object.m_object) || !*(_DWORD *)(force_create_new + 700)) )
    {
      if ( v4 == 1 )
        object.m_object = (vostok::render::res_texture *)1;
      else
        object.m_object = v4 != 0 ? 0 : (vostok::render::res_texture *)6;
      if ( object.m_object )
      {
        v5 = (vostok::render::res_texture *)(force_create_new + 724);
        m_object = object.m_object;
        do
        {
          vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v5[-1].m_name.m_separator,
            0);
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            0,
            v5);
          v5 = (vostok::render::res_texture *)((char *)v5 + 4);
          m_object = (vostok::render::res_texture *)((char *)m_object - 1);
        }
        while ( m_object );
      }
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
      if ( object.m_object )
      {
        v6 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(force_create_new + 700);
        v13 = object.m_object;
        while ( 1 )
        {
          render_target = vostok::render::resource_manager::create_render_target(
                            *(vostok::render::resource_manager **)(v3 + 900),
                            (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                            0,
                            1024 >> *(_DWORD *)(v3 + 900),
                            1024 >> *(_DWORD *)(v3 + 900),
                            (char *)0x35,
                            DXGI_FORMAT_UNKNOWN,
                            0,
                            0,
                            0,
                            v11);
          vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v6,
            (vostok::render::render_target *)render_target);
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            &object,
            *v6 + 7);
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            &object,
            (vostok::render::res_texture *)(v6 + 6));
          v9 = object.m_object;
          if ( object.m_object )
          {
            if ( object.m_object->m_reference_count-- == 1 )
              vostok::render::resource_manager::release(
                v8,
                (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                v9);
          }
          ++v6;
          v13 = (vostok::render::res_texture *)((char *)v13 - 1);
          if ( !v13 )
            break;
          v3 = force_create_new;
        }
      }
    }
  }
}
