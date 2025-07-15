void __thiscall vostok::engine::engine_world::on_before_render_window_shown(
        vostok::engine::engine_world *this,
        boost::function<void __cdecl(void)> on_before_render_window_shown)
{
  vostok::editor::world *m_editor; // ecx
  HWND v4; // eax
  boost::function0<bool> *v5; // ecx
  HWND__ *m_render_window_handle; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx

  m_editor = this->m_editor;
  if ( m_editor )
  {
    v4 = m_editor->main_handle(m_editor);
    SetForegroundWindow(v4);
  }
  else
  {
    ShowWindow(this->m_main_window_handle, 5);
    SetForegroundWindow(this->m_main_window_handle);
    SetActiveWindow(this->m_main_window_handle);
    UpdateWindow(this->m_main_window_handle);
    this->on_application_activate(&this->vostok::editor::engine);
  }
  m_render_window_handle = this->m_render_window_handle;
  if ( m_render_window_handle != this->m_main_window_handle )
  {
    ShowWindow(m_render_window_handle, 5);
    SetForegroundWindow(this->m_render_window_handle);
    SetActiveWindow(this->m_render_window_handle);
    UpdateWindow(this->m_render_window_handle);
  }
  boost::function0<void>::operator()(v5, &on_before_render_window_shown);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&on_before_render_window_shown);
}
