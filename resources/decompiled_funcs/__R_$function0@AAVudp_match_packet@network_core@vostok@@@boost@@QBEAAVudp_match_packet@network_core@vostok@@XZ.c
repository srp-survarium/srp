vostok::network_core::udp_match_packet *__thiscall boost::function0<vostok::network_core::udp_match_packet &>::operator()(
        boost::function0<vostok::network_core::udp_match_packet &> *this)
{
  const std::exception *v1; // eax
  boost::bad_function_call v4; // [esp+24h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v4);
    boost::throw_exception(v1);
    boost::bad_function_call::~bad_function_call(&v4);
  }
  return (vostok::network_core::udp_match_packet *)(*(int (__cdecl **)(boost::detail::function::function_buffer *))(((int)this->vtable & 0xFFFFFFFE) + 4))(&this->functor);
}
