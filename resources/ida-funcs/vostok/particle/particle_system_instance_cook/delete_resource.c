void __thiscall vostok::particle::particle_system_instance_cook::delete_resource(
        vostok::particle::particle_system_instance_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::memory::base_allocator *m_allocator; // esi
  _BYTE *v3; // ebx

  m_allocator = this->m_allocator;
  if ( res )
  {
    v3 = __RTCastToVoid((void **)&res->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
    m_allocator->call_free(
      m_allocator,
      v3,
      "vostok::particle::particle_system_instance_cook::delete_resource",
      ".\\particle_system_instance_cook.cpp",
      154u);
  }
}
