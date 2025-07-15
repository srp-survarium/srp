void __thiscall survarium::booby_trap_core::deserialize(
        survarium::booby_trap_core *this,
        vostok::network_core::buffer_reader *reader,
        survarium::usable_object *time_offset)
{
  survarium::booby_trap_core *v3; // ebx
  vostok::resources::class_id_enum m_class_id; // eax
  bool v5; // zf
  const unsigned __int8 *m_pointer; // eax
  vostok::resources::class_id_enum v7; // eax
  bool v8; // dl
  unsigned __int8 *v9; // esi
  survarium::booby_trap_core *v10; // ecx
  const unsigned __int8 *v11; // esi
  int v12; // edx
  survarium::tickable_object *p_m_owner; // eax
  survarium::game_world_core *v14; // ecx
  unsigned int v15; // [esp+0h] [ebp-58h]
  unsigned __int8 v16; // [esp+12h] [ebp-46h]
  bool v17; // [esp+12h] [ebp-46h]
  bool v18; // [esp+13h] [ebp-45h]
  volatile int v19; // [esp+14h] [ebp-44h]
  unsigned __int8 dst[64]; // [esp+18h] [ebp-40h] BYREF

  v3 = this;
  m_class_id = this->m_class_id;
  LOBYTE(this) = m_class_id == fs_iterator_class;
  v5 = m_class_id == unknown_data_class;
  m_pointer = reader->m_pointer;
  v18 = !v5;
  v16 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  v7 = v16;
  v8 = v16 == 1;
  v17 = v16 != 0;
  v3->m_class_id = v7;
  if ( (_BYTE)this )
  {
    if ( !v8 )
      survarium::booby_trap_core::remove_collision(
        this,
        (survarium::collision_geometry_subscriber *)&v3[-1].m_sub_fat.m_parent,
        1);
  }
  else if ( v8 )
  {
    survarium::booby_trap_core::insert_collision(this, (int)&v3[-1].m_sub_fat.m_parent);
  }
  if ( v3->m_class_id )
  {
    v9 = (unsigned __int8 *)reader->m_pointer;
    memcpy(dst, v9, sizeof(dst));
    reader->m_pointer = v9 + 64;
    survarium::booby_trap_core::set_transform(v10, (const vostok::math::float4x4 *)&v3[-1].m_sub_fat.m_parent, dst);
    v19 = *(_DWORD *)reader->m_pointer;
    reader->m_pointer += 4;
    v3->vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags = v19;
    v11 = reader->m_pointer;
    v12 = *(_DWORD *)v11;
    reader->m_pointer = v11 + 4;
    v5 = v3->m_class_id == fs_iterator_class;
    v3->m_sub_fat.m_object = (vostok::resources::vfs_sub_fat_resource *)((char *)time_offset + v12);
    if ( v5 )
      survarium::usable_object::deserialize_usable_object(time_offset, &v3[-1].m_transform.i.x, reader, v15);
  }
  if ( v18 )
  {
    if ( !v17 )
    {
      if ( v3 == (survarium::booby_trap_core *)132 )
        p_m_owner = 0;
      else
        p_m_owner = (survarium::tickable_object *)&v3[-1].m_owner;
      survarium::game_world_core::unregister_tickable_object(
        (survarium::game_world_core *)v3->grm_satisfaction_tree_hook.parent_,
        p_m_owner);
    }
  }
  else if ( v17 )
  {
    if ( v3 == (survarium::booby_trap_core *)132 )
      v14 = 0;
    else
      v14 = (survarium::game_world_core *)&v3[-1].m_owner;
    survarium::game_world_core::register_tickable_object(v14, (int)v3->grm_satisfaction_tree_hook.parent_);
  }
}
