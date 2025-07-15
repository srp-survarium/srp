void __thiscall vostok::animation::single_animation::~single_animation(vostok::animation::single_animation *this)
{
  this->__vftable = (vostok::animation::single_animation_vtbl *)&vostok::animation::single_animation::`vftable';
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::animation::base_interpolator>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &this->m_interpolator,
    "vostok::animation::single_animation::~single_animation",
    ".\\single_animation.cpp",
    0x22u);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_animation);
  this->__vftable = (vostok::animation::single_animation_vtbl *)&vostok::animation::animation_expression_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
