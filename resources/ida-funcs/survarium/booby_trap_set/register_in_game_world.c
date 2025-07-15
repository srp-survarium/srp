void __thiscall survarium::booby_trap_set::register_in_game_world(
        survarium::booby_trap_set *this,
        survarium::game_world_core *w)
{
  survarium::drawable_object *v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // esi
  survarium::booby_trap_core *m_object; // eax
  survarium::drawable_object *v7; // eax

  survarium::booby_trap_set_core::register_in_game_world(this, w);
  if ( this )
    v3 = &this->survarium::drawable_object;
  else
    v3 = 0;
  survarium::base_game_scene::register_drawable_object(this->m_game_world, v3);
  v4 = 0;
  v5 = this->m_traps.m_end - this->m_traps.m_begin;
  if ( v5 )
  {
    do
    {
      m_object = this->m_traps.m_begin[v4].m_object;
      if ( m_object )
        v7 = (survarium::drawable_object *)&m_object[1];
      else
        v7 = 0;
      survarium::base_game_scene::register_drawable_object(this->m_game_world, v7);
      ++v4;
    }
    while ( v4 < v5 );
  }
}
