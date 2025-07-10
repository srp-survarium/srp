void __thiscall vostok::render::functor_command_with_notify::~functor_command_with_notify(
        vostok::render::functor_command_with_notify *this)
{
  boost::function<void __cdecl(void)> *p_m_on_destroy; // edi
  vostok::render::functor_command *p_functor; // ecx
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  p_m_on_destroy = &this->m_on_destroy;
  this->__vftable = (vostok::render::functor_command_with_notify_vtbl *)&vostok::render::functor_command_with_notify::`vftable';
  boost::function0<void>::operator()(&this->m_on_destroy);
  vtable = p_m_on_destroy->vtable;
  if ( p_m_on_destroy->vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      p_functor = (vostok::render::functor_command *)&p_m_on_destroy->functor;
      if ( v5 )
        v5(&p_m_on_destroy->functor, &p_m_on_destroy->functor, 2);
    }
    p_m_on_destroy->vtable = 0;
  }
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::sky_ambient_occlusion_properties>::~functor_with_big_buffer_to_copy_command<vostok::render::sky_ambient_occlusion_properties>(
    p_functor,
    (int)this);
}
