void __thiscall vostok::engine::engine_world::unload_editor(vostok::engine::engine_world *this)
{
  s_destroy_world(&this->m_editor);
  FreeLibrary(s_editor_module);
  s_editor_module = 0;
  s_destroy_world = 0;
  s_create_world = 0;
}
