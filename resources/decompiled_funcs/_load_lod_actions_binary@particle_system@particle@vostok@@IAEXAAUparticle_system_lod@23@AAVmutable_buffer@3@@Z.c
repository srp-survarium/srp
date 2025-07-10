void __thiscall vostok::particle::particle_system::load_lod_actions_binary(
        vostok::particle::particle_system *this,
        vostok::particle::particle_system_lod *lod,
        vostok::mutable_buffer *buffer)
{
  unsigned __int8 *v3; // eax
  int class_index; // [esp+14h] [ebp-14h] BYREF
  vostok::particle::particle_action *action; // [esp+18h] [ebp-10h]
  unsigned int a; // [esp+1Ch] [ebp-Ch]
  vostok::particle::particle_emitter *emitter; // [esp+20h] [ebp-8h]
  unsigned int e; // [esp+24h] [ebp-4h]

  for ( e = 0; e < lod->m_num_emitters; ++e )
  {
    emitter = &lod->m_emitters_array.pointer[e];
    emitter->m_actions.pointer = 0;
    emitter->m_last_action.pointer = 0;
    emitter->m_particle_system.pointer = this;
    for ( a = 0; a < emitter->m_num_actions; ++a )
    {
      v3 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)emitter,
                                (int)buffer);
      vostok::memory::copy((unsigned __int8 *)&class_index, 4u, v3, 4u);
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)4, buffer);
      action = vostok::particle::create_action_by_index(
                 lod,
                 buffer,
                 emitter,
                 (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)class_index);
      if ( action )
      {
        action->load_binary(action, buffer);
        vostok::particle::particle_emitter::add_action(emitter, action);
      }
    }
  }
}
