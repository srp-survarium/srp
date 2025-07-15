void __thiscall vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data> *this,
        void *buffer)
{
  int v2; // eax

  v2 = *((_DWORD *)buffer + 1);
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*((_DWORD *)buffer + 1) + 208),
        *((vostok::resources::unmanaged_resource **)buffer + 1));
  }
}


void __thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *buffer)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer + 1);
}


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


void __thiscall vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::destroy(
        vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > *this,
        vostok::resources::unmanaged_resource **buffer)
{
  if ( *buffer )
  {
    if ( !_InterlockedExchangeAdd(&(*buffer)->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*buffer)->vostok::resources::unmanaged_intrusive_base,
        *buffer);
  }
}
