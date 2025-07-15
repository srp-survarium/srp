void __thiscall vostok::collision::animated_object_cook::delete_resource(
        vostok::collision::animated_object_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::base_allocator *m_allocator; // esi

  m_allocator = this->m_allocator;
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  m_allocator->call_free(
    m_allocator,
    resource,
    "vostok::physics::destroy_animated_bt_hit_model",
    ".\\animated_rigid_body.cpp",
    245u);
}
