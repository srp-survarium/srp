float __usercall survarium::computed_reload_animation_time_scale@<xmm0>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_animation@<eax>,
        float reload_time)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v2; // ecx
  const unsigned __int8 *v3; // eax
  int v4; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+4h] [ebp-14h] BYREF
  float v8; // [esp+8h] [ebp-10h]
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> v9; // [esp+Ch] [ebp-Ch] BYREF

  *(float *)&object.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    reload_animation);
  v6.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v6,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v2,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v6.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v3 = &v9.m_data[*((_DWORD *)v9.m_data + 5)];
  v4 = *((_DWORD *)v3 + 1) + 16 * *(_DWORD *)v3;
  object.m_object = *(vostok::resources::managed_resource **)&v3[20 * *(_DWORD *)v3 - 4 + *((_DWORD *)v3 + 1)];
  v8 = *(float *)&v3[v4];
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(&v9);
  return (float)((float)(*(float *)&object.m_object - v8) * 0.033333335) / reload_time;
}
