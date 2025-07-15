vostok::particle::particle_action *__thiscall vostok::particle::particle_system::index_to_action(
        vostok::particle::particle_system *this,
        vostok::particle::particle_system_lod *lod,
        unsigned int index)
{
  vostok::particle::particle_action *action; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]
  unsigned int action_index; // [esp+Ch] [ebp-4h]

  if ( !index )
    return 0;
  action_index = 0;
  for ( i = 0; i < lod->m_num_emitters; ++i )
  {
    for ( action = lod->m_emitters_array.pointer[i].m_actions.pointer; action; action = action->m_next.pointer )
    {
      if ( action_index == index - 1 )
        return action;
      ++action_index;
    }
  }
  return 0;
}
