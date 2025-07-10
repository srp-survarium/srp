void __userpurge survarium::player::attach_controller(
        survarium::player *this@<esi>,
        survarium::player_input_handler *handler@<edi>,
        survarium::game_world_ui *ui@<eax>,
        survarium::stats_graph *linear_speed,
        survarium::stats_graph *angular_speed)
{
  survarium::interactive_object *m_object; // ecx
  bool v6; // zf
  bool v7; // al
  bool v8; // al

  m_object = this->m_current_active_object.m_object;
  *(int *)((char *)&dword_10F7C + (_DWORD)this) = (int)ui;
  m_object->assign_game_ui(m_object, ui);
  v6 = !this->m_is_alive;
  *(int *)((char *)&dword_10EF4 + (_DWORD)this) = (int)handler;
  *(int *)((char *)&dword_10EF8 + (_DWORD)this) = (int)linear_speed;
  *(int *)((char *)&dword_10EFC + (_DWORD)this) = (int)angular_speed;
  if ( v6 )
  {
    v8 = handler->m_input_mode_changed || handler->m_input_mode != third_person_mode;
    handler->m_input_mode_changed = v8;
    handler->m_input_mode = third_person_mode;
    *(_DWORD *)(*(int *)((char *)&dword_10EF4 + (_DWORD)this) + 416) = 16;
  }
  else
  {
    v7 = handler->m_input_mode_changed || handler->m_input_mode;
    handler->m_input_mode_changed = v7;
    handler->m_input_mode = first_person_mode;
    *(_DWORD *)(*(int *)((char *)&dword_10EF4 + (_DWORD)this) + 416) = 1;
  }
  *(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 568) = *(int *)((char *)&dword_10EF4 + (_DWORD)this);
  survarium::game_world::switch_camera_mode(
    *(survarium::game_world **)((char *)&dword_10F00 + (_DWORD)this),
    *(const survarium::input_mode_type_enum *)(*(int *)((char *)&dword_10EF4 + (_DWORD)this) + 408));
  this->m_force_animation_selection = 1;
}
