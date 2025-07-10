void __userpurge vostok::render::effect_manager::remove_effect(
        vostok::render::effect_manager *this@<ecx>,
        int a2@<edi>,
        vostok::render::res_effect *in_effect)
{
  vostok::render::effect_manager::effect_holder_struct *v3; // ebp
  vostok::render::effect_manager::effect_holder_struct *v4; // ebx
  vostok::render::effect_manager::effect_holder_struct *v5; // eax
  int v6; // eax
  volatile signed __int32 *v7; // ecx
  int v8; // esi
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::effect_manager::effect_holder_struct *end_it; // [esp+4h] [ebp-4h]

  v3 = *(vostok::render::effect_manager::effect_holder_struct **)(a2 + 96);
  end_it = *(vostok::render::effect_manager::effect_holder_struct **)(a2 + 100);
  if ( v3 != end_it )
  {
    v4 = v3 + 1;
    do
    {
      if ( v4[-1].effect == in_effect )
      {
        v5 = *(vostok::render::effect_manager::effect_holder_struct **)(a2 + 100);
        if ( v4 != v5 )
          stlp_std::priv::__copy<vostok::render::effect_manager::effect_holder_struct *,vostok::render::effect_manager::effect_holder_struct *,int>(
            v5,
            v3,
            v4);
        *(_DWORD *)(a2 + 100) -= 12;
        v6 = *(_DWORD *)(a2 + 100);
        v7 = *(volatile signed __int32 **)(v6 + 4);
        if ( v7 && !_InterlockedExchangeAdd(v7, 0xFFFFFFFF) )
        {
          v8 = *(_DWORD *)(v6 + 4);
          if ( *(_BYTE *)(v8 + 9) )
            vostok::render::custom_config_value::call_data_destructor((vostok::render::custom_config_value *)(v8 + 12));
          if ( *(_BYTE *)(v8 + 8) )
          {
            m_object = vostok::render::g_allocator.m_object;
            if ( v8 )
            {
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free((malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), (char *)v8);
            }
          }
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 != end_it );
  }
}
