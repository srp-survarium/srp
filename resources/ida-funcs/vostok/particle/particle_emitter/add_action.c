void __thiscall vostok::particle::particle_emitter::add_action(
        vostok::particle::particle_emitter *this,
        vostok::particle::particle_action *action)
{
  action->m_next.pointer = 0;
  if ( this->m_actions.pointer )
    this->m_last_action.pointer->m_next.pointer = action;
  else
    this->m_actions.pointer = action;
  this->m_last_action.pointer = action;
}
