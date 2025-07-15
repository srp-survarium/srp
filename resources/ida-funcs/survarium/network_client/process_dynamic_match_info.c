void __thiscall survarium::network_client::process_dynamic_match_info(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *reader,
        vostok::particle::particle_system_instance_impl *a4)
{
  survarium::game_world *v4; // ecx
  const unsigned __int8 *m_buffer; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-10h] BYREF

  if ( reader->m_pointer != reader[1725].m_buffer )
  {
    v6.m_object = (vostok::particle::particle_system_instance_impl *)this;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v6,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&reader[1725]);
    (*((void (__thiscall **)(vostok::network_core::buffer_reader *, vostok::particle::particle_system_instance_impl *))reader->m_buffer
     + 22))(
      reader,
      v6.m_object);
  }
  survarium::game_world_core::deserialize(
    (survarium::game_world_core *)this,
    *(survarium::game_world_core **)(reader[1724].m_buffer_size + 312),
    (int)a4);
  m_buffer = reader[2].m_buffer;
  if ( reader[1726].m_buffer_size == 3 )
    survarium::game_world::switch_to_player_camera(v4, (int)(m_buffer + 192), 1);
  else
    survarium::game_world::switch_to_warmup_camera(v4, (int)(m_buffer + 192));
}
