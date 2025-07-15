void __thiscall survarium::game::exit(survarium::game *this, const char *str)
{
  bool v3; // zf
  vostok::engine_user::engine_vtbl *v4; // eax

  this->unload(this, str, 1);
  v3 = !this->m_engine->command_line_editor(this->m_engine);
  v4 = this->m_engine->__vftable;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v4->exit)(0);
  else
    ((void (*)(void))v4->enter_editor_mode)();
}
