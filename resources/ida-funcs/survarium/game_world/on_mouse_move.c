bool __thiscall survarium::game_world::on_mouse_move(
        survarium::game_world *this,
        vostok::input::world *__formal,
        int a3,
        int a4,
        int a5)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi

  v6 = &this[-1].m_third_person_game_effect_presenters[10888];
  v7 = &this[-1].m_third_person_game_effect_presenters[10892];
  survarium::mouse_helper::get_position(
    (survarium::mouse_helper *)&this->m_third_person_game_effect_presenters[10732],
    (int *)&this[-1].m_third_person_game_effect_presenters[10892],
    (int *)&this[-1].m_third_person_game_effect_presenters[10888]);
  (*(void (__thiscall **)(unsigned __int8 *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[10748]
                                                                    + 48))(
    &this[-1].m_third_person_game_effect_presenters[10748],
    *(_DWORD *)v6,
    *(_DWORD *)v7,
    0);
  return 0;
}
