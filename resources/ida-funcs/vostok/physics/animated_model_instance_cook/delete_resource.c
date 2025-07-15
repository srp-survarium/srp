void __thiscall vostok::physics::animated_model_instance_cook::delete_resource(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::base_allocator *m_allocator; // esi
  _BYTE *v3; // ebx

  m_allocator = this->m_allocator;
  if ( resource )
  {
    v3 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    m_allocator->call_free(
      m_allocator,
      v3,
      "vostok::physics::animated_model_instance_cook::delete_resource",
      ".\\animated_model_instance_cook.cpp",
      156u);
  }
}
