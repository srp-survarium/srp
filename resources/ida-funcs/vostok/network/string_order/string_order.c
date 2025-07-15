void __userpurge vostok::network::string_order::string_order(
        const boost::function<void __cdecl(char const *,char const *,char const *)> *functor@<ecx>,
        vostok::network::string_order *this,
        vostok::memory::base_allocator *allocator,
        char *string0,
        char *string1,
        const char *const string2)
{
  boost::detail::function::vtable_base *vtable; // eax

  this->allocator = allocator;
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::string_order::`vftable';
  this->m_functor0.vtable = 0;
  this->m_functor1.vtable = 0;
  this->m_functor2.vtable = 0;
  vtable = functor->vtable;
  if ( functor->vtable )
  {
    this->m_functor2.vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      qmemcpy((void *)&this->m_functor2.functor, &functor->functor, sizeof(this->m_functor2.functor));
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &functor->functor,
        &this->m_functor2.functor,
        0);
  }
  this->m_string0 = vostok::strings::duplicate<vostok::memory::base_allocator>(string0);
  this->m_string1 = vostok::strings::duplicate<vostok::memory::base_allocator>(s_net_client_account_name);
  this->m_string2 = vostok::strings::duplicate<vostok::memory::base_allocator>(string1);
}


void __thiscall vostok::network::string_order::string_order(
        const boost::function<void __cdecl(char const *,char const *)> *functor,
        vostok::network::string_order *this,
        vostok::memory::base_allocator *allocator,
        char *string0,
        char *string1)
{
  boost::detail::function::vtable_base *vtable; // eax
  char *v6; // eax

  this->allocator = allocator;
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::string_order::`vftable';
  this->m_functor0.vtable = 0;
  this->m_functor1.vtable = 0;
  vtable = functor->vtable;
  if ( functor->vtable )
  {
    this->m_functor1.vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      qmemcpy((void *)&this->m_functor1.functor, &functor->functor, sizeof(this->m_functor1.functor));
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &functor->functor,
        &this->m_functor1.functor,
        0);
  }
  this->m_functor2.vtable = 0;
  this->m_string0 = vostok::strings::duplicate<vostok::memory::base_allocator>(string0);
  v6 = vostok::strings::duplicate<vostok::memory::base_allocator>(string1);
  this->m_string2 = 0;
  this->m_string1 = v6;
}


void __userpurge vostok::network::string_order::string_order(
        vostok::network::string_order *this@<esi>,
        vostok::memory::base_allocator *allocator@<edi>,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *functor@<ecx>,
        char *string0)
{
  char *v4; // eax

  this->allocator = allocator;
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::string_order::`vftable';
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    functor,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_functor0);
  this->m_functor1.vtable = 0;
  this->m_functor2.vtable = 0;
  v4 = vostok::strings::duplicate<vostok::memory::base_allocator>(string0);
  this->m_string1 = 0;
  this->m_string2 = 0;
  this->m_string0 = v4;
}
