void __thiscall vostok::engine::engine_world::editor(vostok::engine::engine_world *this)
{
  DWORD CurrentThreadId; // eax
  vostok::command_line::key *m_begin; // ecx
  vostok::command_line::key *v4; // ecx
  vostok::engine::engine_world_vtbl *v5; // ebx
  int v6; // eax

  CoInitializeEx(0, 2u);
  CurrentThreadId = GetCurrentThreadId();
  m_begin = (vostok::command_line::key *)g_threads.m_begin;
  g_threads.m_begin[2].m_thread_id = CurrentThreadId;
  vostok::apc::process(editor, m_begin, 1);
  this->m_editor->run(this->m_editor);
  if ( !this->m_destruction_started )
  {
    v5 = this->vostok::core::engine::vostok::core::core_debug_engine::vostok::debug::engine::__vftable;
    v6 = this->m_editor->exit_code(this->m_editor);
    v5->exit(this, v6);
  }
  vostok::apc::process(editor, v4, 1);
}
