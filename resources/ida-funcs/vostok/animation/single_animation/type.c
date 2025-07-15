int __thiscall vostok::animation::single_animation::type(vostok::animation::single_animation *this)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v1; // ecx
  int v2; // eax
  int v3; // edi
  vostok::resources::pinned_ptr_const<unsigned char> *v4; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-18h] BYREF
  _BYTE v7[12]; // [esp+8h] [ebp-Ch] BYREF

  v6.m_object = (vostok::resources::managed_resource *)this;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v6,
    &this->m_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v1,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v7,
    v6);
  v3 = *(_DWORD *)(*(_DWORD *)(v2 + 4) + 24);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v4,
    (int)v7);
  return v3;
}
