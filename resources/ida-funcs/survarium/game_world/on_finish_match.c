void __usercall survarium::game_world::on_finish_match(
        survarium::game_world *this@<ecx>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2@<eax>)
{
  int v3; // eax
  survarium::game_world *v4; // ecx
  int v5; // eax
  survarium::game *v6; // ecx

  v3 = ((int (__thiscall *)(vostok::vfs::base_node<1> *))a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413]->m_mount_root.pointer->node.pointer)(a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413]);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 36))(v3) )
  {
    v5 = ((int (__thiscall *)(vostok::vfs::base_node<1> *))a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413]->m_mount_root.pointer->node.pointer)(a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413]);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(v5);
  }
  survarium::game_world::unload(v4, a2);
  if ( !*(_BYTE *)(((int (__thiscall *)(vostok::vfs::base_node<1> *))HIDWORD(a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413]->m_mount_root.pointer->mount.max_storage))(a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413])
                 + 436) )
    *(_BYTE *)(((int (__thiscall *)(vostok::vfs::base_node<1> *))HIDWORD(a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413]->m_mount_root.pointer->mount.max_storage))(a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413])
             + 192) = 1;
  survarium::game::switch_to_lobby(v6, (survarium::game *)a2.m_object->m_fat_it.m_hashset);
}
