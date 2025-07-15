char __thiscall survarium::game_options::on_mouse_move(
        survarium::game_options *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  void *v6; // eax
  survarium::base_game_scene *m_parent_scene; // eax
  float v8; // xmm0_4
  survarium::swf_input_translator *v9; // ecx
  float v11; // [esp+1Ch] [ebp-8h]
  float v12; // [esp+1Ch] [ebp-8h]
  struct survarium::flash_movie *v13; // [esp+20h] [ebp-4h]
  struct survarium::flash_movie *v14; // [esp+20h] [ebp-4h]
  survarium::swf_input_translator *m_mouse_x; // [esp+30h] [ebp+Ch]
  float v16; // [esp+34h] [ebp+10h]
  float m_mouse_y; // [esp+38h] [ebp+14h]

  if ( this->m_waiting_for_bind_action == kLASTACTION )
  {
    v6 = __RTDynamicCast(
           this->m_parent_scene,
           0,
           &survarium::base_game_scene `RTTI Type Descriptor',
           &vostok::input::handler `RTTI Type Descriptor',
           0);
    (*(void (__thiscall **)(void *, vostok::input::world *, int, int, _DWORD))(*(_DWORD *)v6 + 12))(
      v6,
      input_world,
      x,
      y,
      0);
    m_parent_scene = this->m_parent_scene;
    v8 = (float)z;
    m_mouse_x = (survarium::swf_input_translator *)m_parent_scene->m_mouse_x;
    m_mouse_y = (float)m_parent_scene->m_mouse_y;
    v16 = (float)(int)m_mouse_x;
    survarium::swf_input_translator::process_mouse_move(
      m_mouse_x,
      v8,
      (struct vostok::input::world *)LODWORD(v16),
      m_mouse_y,
      *(float *)&this->m_cursor_ui.m_object->movie,
      v11,
      v13);
    survarium::swf_input_translator::process_mouse_move(
      v9,
      v8,
      (struct vostok::input::world *)LODWORD(v16),
      m_mouse_y,
      *(float *)&this->m_options_ui.m_object->movie,
      v12,
      v14);
  }
  else if ( z && survarium::game_options::process_key_input(this, this, (z <= 0) + 345) )
  {
    Scaleform::GFx::Movie::Invoke(this->m_options_ui.m_object->movie->m_movie, "root.end_keybind", 0, 0, 0);
    survarium::base_game_scene::show_movie(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_cursor_ui,
      this->m_parent_scene);
    this->m_waiting_for_bind_action = kLASTACTION;
  }
  return 1;
}
