bool __thiscall vostok::engine::engine_world::on_before_editor_tick(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world *v2; // ecx

  if ( vostok::threading::core_count(this) == 1 )
  {
    (*(void (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 100))(&this[-1].m_timer.m_time_factor);
    return 1;
  }
  if ( (_S5_17 & 1) == 0 )
  {
    _S5_17 |= 1u;
    editor_singlethreaded = (*(int (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 104))(&this[-1].m_timer.m_time_factor);
  }
  if ( editor_singlethreaded )
  {
    vostok::engine::engine_world::logic_tick(v2, (vostok::engine::engine_world *)((char *)this - 8));
    return 1;
  }
  return this->m_render_window_handle <= (HWND__ *)(*(_DWORD *)(**((_DWORD **)this->m_on_before_render_window_showed.functor.bound_memfunc_ptr.obj_ptr
                                                                 + 89)
                                                              + 40)
                                                  + 1);
}
