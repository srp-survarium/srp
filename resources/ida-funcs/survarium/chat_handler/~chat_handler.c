void __thiscall survarium::chat_handler::~chat_handler(survarium::chat_handler *this)
{
  survarium::flash_function_handler *v2; // ebx
  survarium::flash_function_handler *v3; // ecx
  const char *v4; // [esp+0h] [ebp-Ch]
  const char *v5; // [esp+4h] [ebp-8h]
  unsigned int v6; // [esp+8h] [ebp-4h]

  v2 = &this->survarium::flash_function_handler;
  this->vostok::input::handler::__vftable = (survarium::chat_handler_vtbl *)&survarium::chat_handler::`vftable'{for `vostok::input::handler'};
  this->survarium::flash_function_handler::__vftable = (survarium::flash_function_handler_vtbl *)&survarium::chat_handler::`vftable'{for `survarium::flash_function_handler'};
  if ( this->m_private_channels._M_impl._M_start )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      this->m_private_channels._M_impl._M_start->name,
      v4,
      v5,
      v6);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_current_chat_ui);
  survarium::flash_function_handler::~flash_function_handler(v3, v2);
}
