double __usercall survarium::computed_shotgun_reload_animation_time_scale@<st0>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_one_round_anim@<eax>,
        unsigned int magazine_capacity,
        float reload_time)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v3; // ecx
  const unsigned __int8 *v4; // eax
  int v5; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v7; // [esp-4h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+4h] [ebp-14h] BYREF
  float v9; // [esp+8h] [ebp-10h]
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> v10; // [esp+Ch] [ebp-Ch] BYREF

  *(float *)&object.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    reload_one_round_anim);
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v3,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v7.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v4 = &v10.m_data[*((_DWORD *)v10.m_data + 5)];
  v5 = 16 * *(_DWORD *)v4;
  object.m_object = *(vostok::resources::managed_resource **)&v4[20 * *(_DWORD *)v4 - 4 + *((_DWORD *)v4 + 1)];
  v9 = *(float *)&v4[*((_DWORD *)v4 + 1) + v5];
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(&v10);
  return (*(float *)&object.m_object - v9) * 0.033333335 * (double)magazine_capacity / reload_time;
}
