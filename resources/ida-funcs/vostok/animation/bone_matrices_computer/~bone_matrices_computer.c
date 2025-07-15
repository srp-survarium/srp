void __usercall vostok::animation::bone_matrices_computer::~bone_matrices_computer(
        vostok::animation::bone_matrices_computer *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ebx
  int v3; // edi
  vostok::resources::pinned_ptr_const<unsigned char> *v4; // ecx
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> v5; // [esp+Ch] [ebp-Ch] BYREF

  v2 = *(_DWORD *)(a2 + 8);
  v3 = v2 + 176 * *(_DWORD *)(a2 + 12);
  while ( v2 != v3 )
  {
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      (vostok::resources::pinned_ptr_mutable<unsigned char> *)this,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v5,
      0);
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::operator=(
      (vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *)(v2 + 80),
      &v5);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
      v4,
      (int)&v5);
    v2 += 176;
  }
}
