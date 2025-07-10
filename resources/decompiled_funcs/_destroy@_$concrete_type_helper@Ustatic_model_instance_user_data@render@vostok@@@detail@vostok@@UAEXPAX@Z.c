void __thiscall vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data> *this,
        void *buffer)
{
  int v2; // eax

  v2 = *((_DWORD *)buffer + 2);
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*((_DWORD *)buffer + 2) + 208),
        *((vostok::resources::unmanaged_resource **)buffer + 2));
  }
}
