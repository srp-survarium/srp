void __thiscall vostok::sound::new_sound_propagator::detach_voice(vostok::sound::new_sound_propagator *this, int a2)
{
  int v3; // esi
  int v4; // edi
  int v5; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // edi
  vostok::vfs::vfs_hashset *m_hashset; // esi
  vostok::sound::sound_scene *v8; // [esp+14h] [ebp+8h]

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(v3 + 20);
  *(_BYTE *)(v3 + 8) = 0;
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(v4 + 16) + 80))(*(_DWORD *)(v4 + 16), 0, 0);
  *(_DWORD *)(v4 + 44) = 0;
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 20) + 16) + 88))(*(_DWORD *)(*(_DWORD *)(v3 + 20) + 16));
  v5 = *(_DWORD *)(a2 + 8);
  v6 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 4);
  v8 = *(vostok::sound::sound_scene **)(*(_DWORD *)(v5 + 100) + 280);
  vostok::sound::sound_scene::remove_active_voice(v8, *(_DWORD *)(v5 + 104), *(vostok::sound::sound_voice **)(a2 + 4));
  m_hashset = v8->m_fat_it.m_hashset;
  if ( v6 )
  {
    *((_DWORD *)&v6[5].m_object->vostok::resources::resource_flags + 3) = 0;
    ((void (__thiscall *)(vostok::particle::particle_system_instance_impl *))v6[8].m_object->__vftable[1].link_child_resource)(v6[8].m_object);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v6 + 8);
    v6->m_object = *(vostok::particle::particle_system_instance_impl **)&m_hashset->m_hashlocks[4].m_readers_writers_counter.readers_count;
    *(_DWORD *)&m_hashset->m_hashlocks[4].m_readers_writers_counter.readers_count = v6;
    --m_hashset->m_hashlocks[4].m_readers_writers_counter.writer_thread_id;
  }
  *(_DWORD *)(a2 + 4) = 0;
}
