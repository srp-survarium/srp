void __thiscall survarium::game_options::~game_options(survarium::game_options *this)
{
  survarium::flash_external_handler *v2; // ebp
  survarium::options_tab **m_options; // ebx
  char *v4; // esi
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-1Ch]
  const char *v7; // [esp+4h] [ebp-18h]
  unsigned int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+14h] [ebp-8h]
  vostok::memory::doug_lea_allocator *v10; // [esp+18h] [ebp-4h]

  v2 = &this->survarium::flash_external_handler;
  this->vostok::input::handler::__vftable = (survarium::game_options_vtbl *)&survarium::game_options::`vftable'{for `vostok::input::handler'};
  this->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::game_options::`vftable'{for `survarium::flash_external_handler'};
  m_options = this->m_options;
  v9 = 4;
  do
  {
    v4 = (char *)*m_options;
    v10 = survarium::g_allocator;
    if ( *m_options )
    {
      survarium::options_tab::~options_tab((survarium::options_tab *)this, (int)v4);
      vostok::memory::doug_lea_allocator::free_impl(v5, (int)v10, v4, v6, v7, v8);
      *m_options = 0;
    }
    ++m_options;
    --v9;
  }
  while ( v9 );
  if ( this->m_conflicted_action_ids._M_impl._M_start )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_conflicted_action_ids._M_impl._M_start,
      v6,
      v7,
      v8);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_cursor_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_options_ui);
  survarium::flash_external_handler::~flash_external_handler(v2);
}
