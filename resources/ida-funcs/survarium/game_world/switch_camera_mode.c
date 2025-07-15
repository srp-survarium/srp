void __usercall survarium::game_world::switch_camera_mode(
        survarium::game_world *this@<ecx>,
        const survarium::input_mode_type_enum input_mode@<eax>)
{
  BOOL v3; // ecx
  int v4; // eax
  survarium::player_input_handler *m_player_camera; // eax
  survarium::player_input_handler *v6; // eax
  survarium::game_camera *v7; // eax
  survarium::camera_director *m_camera_director; // edi
  survarium::free_fly_camera *m_free_fly_camera; // [esp-8h] [ebp-14h]

  if ( input_mode )
  {
    v3 = 1;
    v4 = input_mode - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        m_player_camera = this->m_player_camera;
        if ( m_player_camera )
        {
          this->m_input_mode = third_person_mode;
          if ( !m_player_camera->m_input_mode_changed )
            v3 = m_player_camera->m_input_mode != third_person_mode;
          m_player_camera->m_input_mode_changed = v3;
          m_player_camera->m_input_mode = third_person_mode;
          v6 = this->m_player_camera;
          if ( v6 )
            v7 = &v6->survarium::game_camera;
          else
            v7 = 0;
          survarium::camera_director::switch_to_camera(
            (survarium::camera_director *)v3,
            this->m_camera_director,
            v7,
            (const char *)&stru_96A440);
        }
      }
    }
    else
    {
      m_camera_director = this->m_camera_director;
      m_free_fly_camera = this->m_free_fly_camera;
      this->m_input_mode = free_fly_mode;
      survarium::camera_director::switch_to_camera(
        (survarium::camera_director *)1,
        m_camera_director,
        m_free_fly_camera,
        (const char *)&stru_96A440.m_inverted_view.lines[1]);
    }
  }
  else
  {
    survarium::game_world::switch_to_player_camera(this, (int)this, 1);
  }
}
