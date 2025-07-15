void __thiscall vostok::resources::query_result::free_unmanaged_buffer(vostok::resources::query_result *this, int a2)
{
  int v2; // eax
  survarium::pure_game_effect_emitter_base *v3; // edi
  survarium::pure_game_effect_emitter_base *m_object; // ebx
  vostok::resources::query_result *v5; // ecx
  vostok::vfs::vfs_iterator v6; // [esp+10h] [ebp-24h] BYREF
  unsigned int v7; // [esp+28h] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp+2Ch] [ebp-8h] BYREF

  v2 = a2 + 652;
  if ( !*(_DWORD *)(a2 + 652) )
    v2 = a2 + 660;
  v3 = *(survarium::pure_game_effect_emitter_base **)v2;
  v7 = *(_DWORD *)(v2 + 4);
  if ( v3 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(
      (vostok::resources::unmanaged_resource *)a2,
      v3,
      fs_iterator_class);
    v3->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&vostok::resources::helper_unmanaged_resource::`vftable';
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v8,
      v3);
    m_object = v8.m_object;
    vostok::resources::query_result::set_deleter_object(v5, a2, v8.m_object);
    m_object->m_fat_it = *vostok::resources::query_result::get_fat_it_zero_if_physical_path_it(
                            (vostok::resources::query_result *)a2,
                            &v6);
    m_object->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type = &vostok::resources::nocache_memory;
    m_object->m_memory_usage_self.size = v7;
    m_object->m_creation_source = creation_source_deallocate_buffer_helper;
    *(_DWORD *)(a2 + 652) = 0;
    *(_DWORD *)(a2 + 656) = 0;
    *(_DWORD *)(a2 + 660) = 0;
    *(_DWORD *)(a2 + 664) = 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
  }
}
