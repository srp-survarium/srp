float __usercall survarium::computed_chamber_a_round_animation_time_scale@<xmm0>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_animation@<edi>,
        vostok::resources::managed_resource *a2@<ecx>,
        const float reload_time)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v3; // ecx
  int v4; // eax
  _DWORD *v5; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v6; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp-4h] [ebp-20h] BYREF
  _BYTE v9[12]; // [esp+8h] [ebp-14h] BYREF
  float v10; // [esp+14h] [ebp-8h]
  float v11; // [esp+18h] [ebp-4h]

  v8.m_object = a2;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v8,
    reload_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v3,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v9,
    v8);
  v5 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 4) + 20) + *(_DWORD *)(v4 + 4));
  v6 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v5[1] + 16 * *v5);
  v11 = *(float *)((char *)&v5[5 * *v5 - 1] + v5[1]);
  v10 = *(float *)((char *)v5 + (_DWORD)v6);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v6,
    (int)v9);
  return (float)((float)(v11 - v10) * 0.033333335) / reload_time;
}
