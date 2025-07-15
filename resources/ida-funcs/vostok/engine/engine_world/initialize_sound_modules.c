void __usercall vostok::engine::engine_world::initialize_sound_modules(
        vostok::engine::engine_world *this@<ecx>,
        unsigned int a2@<ebx>)
{
  vostok::memory::doug_lea_allocator *v3; // ecx
  vostok::sound::engine *v4; // esi
  vostok::memory::doug_lea_allocator *v5; // eax
  vostok::sound::sound_world *v6; // ecx

  CoInitializeEx(0, 2u);
  vostok::memory::doug_lea_allocator::user_current_thread_id(v3, (int)&this->m_sound_allocator);
  vostok::sound::g_allocator = &this->m_sound_allocator;
  if ( this )
    v4 = (vostok::sound::engine *)(&this->gapC + 1);
  else
    v4 = 0;
  this->command_line_editor(&this->vostok::engine_user::engine);
  v5 = this->m_engine_user_module_proxy->allocator(this->m_engine_user_module_proxy);
  vostok::sound::sound_world::sound_world(
    v6,
    a2,
    (unsigned __int8)this,
    (const char *)&s_sound_world_buffer,
    (vostok::sound::sound_world *)&s_sound_world_buffer,
    v4,
    v5);
  _InterlockedExchange((volatile __int32 *)&this->m_sound_world, (__int32)&s_sound_world_buffer);
}
