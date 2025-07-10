bool __thiscall vostok::engine::engine_world::on_before_editor_tick(vostok::engine::engine_world *this)
{
  int (__thiscall *v3)(float *); // edx
  vostok::threading *v4; // [esp+0h] [ebp-4h]

  if ( !s_logical_core_count )
    vostok::threading::initialize_core_count(v4);
  if ( s_logical_core_count == 1 )
  {
    (*(void (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 96))(&this[-1].m_timer.m_time_factor);
    return 1;
  }
  if ( (_S3_15 & 1) == 0 )
  {
    v3 = *(int (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 100);
    _S3_15 |= 1u;
    editor_singlethreaded = v3(&this[-1].m_timer.m_time_factor);
  }
  if ( editor_singlethreaded )
  {
    vostok::engine::engine_world::logic_tick(this);
    return 1;
  }
  else
  {
    return this->m_render_window_handle <= (HWND__ *)(*(_DWORD *)(**(_DWORD **)(this->m_editor_allocator.m_user_thread_id
                                                                              + 372)
                                                                + 4)
                                                    + 1);
  }
}
