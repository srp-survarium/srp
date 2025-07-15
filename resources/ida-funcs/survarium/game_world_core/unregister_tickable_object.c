void __usercall survarium::game_world_core::unregister_tickable_object(
        survarium::game_world_core *this@<esi>,
        survarium::tickable_object *object@<eax>)
{
  survarium::tickable_object *i; // ecx
  unsigned int v3; // eax
  survarium::tickable_object *m_next_tickable_object; // edx
  survarium::tickable_object *prev; // edx
  survarium::tickable_object *next; // ecx
  bool v7; // [esp+7h] [ebp-1h] BYREF

  for ( i = this->m_tickable_objects.m_first; i; i = i->next )
  {
    if ( i == object )
      goto LABEL_6;
  }
  i = 0;
LABEL_6:
  if ( debug_macro_helper_ignore_always_43 || i )
  {
    m_next_tickable_object = this->m_next_tickable_object;
    if ( m_next_tickable_object == object )
      this->m_next_tickable_object = m_next_tickable_object->next;
    if ( this->m_tickable_objects.m_first )
    {
      prev = object->prev;
      next = object->next;
      object->prev = 0;
      object->next = 0;
      if ( prev )
        prev->next = next;
      else
        this->m_tickable_objects.m_first = next;
      if ( next )
        next->prev = prev;
      else
        this->m_tickable_objects.m_last = prev;
      object->prev = 0;
      object->next = 0;
    }
  }
  else
  {
    v3 = occurances_left_25;
    if ( occurances_left_25 == -1 )
      v3 = 10;
    occurances_left_25 = v3 - 1;
    if ( v3 )
    {
      v7 = 0;
      vostok::debug::on_error(
        &v7,
        process_error_false,
        (bool *)"found",
        ".\\game_world_core.cpp",
        "survarium::game_world_core::unregister_tickable_object",
        (const char *)0x4E4);
      if ( vostok::debug::is_debugger_present() || v7 )
        __debugbreak();
    }
  }
}
