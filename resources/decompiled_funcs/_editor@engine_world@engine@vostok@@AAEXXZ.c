void __thiscall vostok::engine::engine_world::editor(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world_vtbl *v2; // edi
  int v3; // eax

  CoInitializeEx(0, 2u);
  g_threads.m_begin[2].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(editor);
  this->m_editor->run(this->m_editor);
  if ( !this->m_destruction_started )
  {
    v2 = this->vostok::core::engine::vostok::core::core_debug_engine::vostok::debug::engine::__vftable;
    v3 = this->m_editor->exit_code(this->m_editor);
    v2->exit(this, v3);
  }
  vostok::apc::process(editor);
}
