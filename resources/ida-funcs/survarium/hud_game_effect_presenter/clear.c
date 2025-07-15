void __thiscall survarium::hud_game_effect_presenter::clear(survarium::hud_game_effect_presenter *this)
{
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **p_m_old_effects; // edi
  __int64 v3; // rax
  int v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // ebp

  p_m_old_effects = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&this->m_old_effects;
  v3 = (char *)this->m_old_effects.m_end - (char *)this->m_old_effects.m_begin;
  v4 = 12;
  v5 = v3 / 12;
  if ( v5 )
  {
    v6 = 0;
    v7 = v5;
    do
    {
      survarium::game_world_ui::remove_effect(
        (survarium::game_world_ui *)v4,
        (const survarium::hud_effects_enum)this->m_ui,
        (unsigned int)(*p_m_old_effects)[v6 + 1].m_object);
      v6 += 3;
      --v7;
    }
    while ( v7 );
  }
  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::clear(
    (vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *)v4,
    p_m_old_effects);
}
