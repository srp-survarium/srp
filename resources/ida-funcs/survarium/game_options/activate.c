void __userpurge survarium::game_options::activate(
        survarium::game_options *this@<ecx>,
        survarium::game_options *a2@<esi>,
        survarium::game_world *parent_scene)
{
  survarium::base_game_scene *v3; // ecx
  survarium::game *m_game; // ecx
  int v5; // eax

  if ( !a2->m_is_active )
  {
    a2->m_parent_scene = parent_scene;
    survarium::base_game_scene::show_movie(&a2->m_options_ui, (survarium::base_game_scene *)this, parent_scene);
    survarium::base_game_scene::show_movie(&a2->m_cursor_ui, v3, a2->m_parent_scene);
    m_game = a2->m_game;
    a2->m_is_active = 1;
    v5 = (int)m_game->input_world(m_game);
    (*(void (__thiscall **)(int, survarium::game_options *))(*(_DWORD *)v5 + 16))(v5, a2);
    survarium::game_options::fill_menu_buttons(
      (survarium::game_options *)&a2->m_game->m_game_world,
      a2,
      parent_scene == &a2->m_game->m_game_world);
  }
}
