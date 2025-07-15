int __cdecl survarium::shared_statistics::kill_event_arg(
        vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *world)
{
  survarium::game_world_core *v1; // ecx
  int v2; // edi
  char v3; // si
  int *v4; // eax
  survarium::damage_model *v5; // ecx
  survarium::body_part_parameters *body_part; // eax
  unsigned __int8 v8; // [esp+8h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  v8 = 0;
  v3 = 0;
  do
  {
    survarium::game_world_core::active_player_ptr(v1, &v9, world, v8);
    if ( v9.m_object )
    {
      if ( LOBYTE(v9.m_object->m_skeleton_model.m_object) )
      {
        v4 = (int *)((int (__thiscall *)(vostok::particle::lod_entry *))v9.m_object->m_lods[0].m_template.m_object->m_flags.m_flags)(v9.m_object->m_lods);
        body_part = survarium::damage_model::get_body_part(v5, *v4, "pain");
        if ( (float)(body_part->m_health / body_part->m_max_health) < 0.5 )
          v2 |= 1 << v3;
      }
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
    ++v8;
    ++v3;
  }
  while ( v8 < 0x14u );
  return v2;
}
