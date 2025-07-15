void __thiscall vostok::animation::single_animation::~single_animation(vostok::animation::single_animation *this)
{
  vostok::animation::base_interpolator *m_interpolator; // eax
  _BYTE *v3; // edi

  this->__vftable = (vostok::animation::single_animation_vtbl *)&vostok::animation::single_animation::`vftable';
  m_interpolator = this->m_interpolator;
  if ( m_interpolator )
  {
    v3 = __RTCastToVoid((void **)&m_interpolator->__vftable);
    ((void (__thiscall *)(vostok::animation::base_interpolator *, _DWORD))this->m_interpolator->~vostok::animation::base_interpolator)(
      this->m_interpolator,
      0);
    vostok::memory::g_resources_unmanaged_allocator.call_free(&vostok::memory::g_resources_unmanaged_allocator, v3);
    this->m_interpolator = 0;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_animation);
  this->__vftable = (vostok::animation::single_animation_vtbl *)&vostok::animation::animation_expression_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
