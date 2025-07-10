void __thiscall boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
        boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *this,
        const char *a0,
        const vostok::network_core::udp_match_packet *a1)
{
  const std::exception *v3; // eax
  boost::bad_function_call v5; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v3);
    boost::bad_function_call::~bad_function_call(&v5);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const char *, const vostok::network_core::udp_match_packet *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0,
    a1);
}
