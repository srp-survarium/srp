void __thiscall survarium::game_effect::game_effect(
        survarium::game_effect *this,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> emitter,
        const float length,
        int a4)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  unsigned int *p_type; // edi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+4h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  v4 = survarium::g_allocator;
  p_type = &emitter.m_object->type;
  v6 = type_info::raw_name(&survarium::loose_ptr_data `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v4, 8u, v6, v9, v10, v11);
  if ( v8 )
  {
    *(_DWORD *)v8 = p_type;
    *((_DWORD *)v8 + 1) = 0;
  }
  else
  {
    v8 = 0;
  }
  *p_type = (unsigned int)v8;
  *(_DWORD *)(*p_type + 4) = *((_DWORD *)v8 + 1) + 1;
  emitter.m_object->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&survarium::game_effect::`vftable';
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&emitter.m_object->m_flags,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&length);
  *((_DWORD *)&emitter.m_object->vostok::resources::resource_flags + 3) = a4;
  LODWORD(emitter.m_object->m_reconstruction_info_actuality_tick) = 0;
  HIDWORD(emitter.m_object->m_reconstruction_info_actuality_tick) = 0;
  emitter.m_object->m_reconstruction_size = 0;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&length);
}
