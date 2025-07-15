void __thiscall vostok::engine::engine_world::initialize_sound_modules(vostok::engine::engine_world *this)
{
  DWORD CurrentThreadId; // eax
  const char *Value; // eax
  vostok::memory::doug_lea_allocator *p_m_editor_allocator; // eax
  vostok::memory::doug_lea_allocator *v5; // eax
  vostok::memory::base_allocator *v6; // [esp-4h] [ebp-Ch]

  CoInitializeEx(0, 2u);
  CurrentThreadId = GetCurrentThreadId();
  if ( this->m_sound_allocator.m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)&this->m_sound_allocator.m_user_thread_id, CurrentThreadId);
    if ( this->m_sound_allocator.m_thread_id_const )
      this->m_sound_allocator.m_user_thread_id_called = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  this->m_sound_allocator.m_user_thread_logging_name = Value;
  vostok::sound::set_memory_allocator((vostok::resources::unmanaged_resource *)&this->m_sound_allocator);
  if ( this->command_line_editor(&this->vostok::engine_user::engine) )
    p_m_editor_allocator = &this->m_editor_allocator;
  else
    p_m_editor_allocator = 0;
  v6 = p_m_editor_allocator;
  v5 = this->m_engine_user_module_proxy->allocator(this->m_engine_user_module_proxy);
  _InterlockedExchange(
    (volatile __int32 *)&this->m_sound_world,
    (__int32)vostok::sound::create_world((vostok::sound::engine *)&this->gapC + 1, v5, v6));
}
