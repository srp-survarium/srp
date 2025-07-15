double __usercall survarium::computed_shotgun_reload_animation_time_scale@<st0>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_one_round_anim@<edi>,
        vostok::resources::managed_resource *a2@<ecx>,
        const unsigned int magazine_capacity,
        const float reload_time)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v8; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v10; // [esp-4h] [ebp-1Ch] BYREF
  _BYTE v11[12]; // [esp+4h] [ebp-14h] BYREF
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+14h] [ebp-4h]

  v10.m_object = a2;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v10,
    reload_one_round_anim);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v4,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v11,
    v10);
  v6 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 4) + 20) + *(_DWORD *)(v5 + 4));
  v7 = 16 * *v6;
  v13 = *(float *)((char *)&v6[5 * *v6 - 1] + v6[1]);
  v8 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v6[1] + v7);
  v12 = *(float *)((char *)v6 + (_DWORD)v8);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v8,
    (int)v11);
  return (v13 - v12) * 0.033333335 * (double)magazine_capacity / reload_time;
}
