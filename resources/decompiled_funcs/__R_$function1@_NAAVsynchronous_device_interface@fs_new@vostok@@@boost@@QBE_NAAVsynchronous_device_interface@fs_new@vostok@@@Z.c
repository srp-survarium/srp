int __thiscall boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
        boost::function1<unsigned int,char const *> *this,
        const char *a0)
{
  const std::exception *v2; // eax
  boost::bad_function_call v5; // [esp+24h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v2);
    boost::bad_function_call::~bad_function_call(&v5);
  }
  return (*(int (__cdecl **)(boost::detail::function::function_buffer *, const char *))(((int)this->vtable & 0xFFFFFFFE)
                                                                                      + 4))(
           &this->functor,
           a0);
}
