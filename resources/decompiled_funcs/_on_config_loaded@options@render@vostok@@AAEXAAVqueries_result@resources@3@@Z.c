void __thiscall vostok::render::options::on_config_loaded(
        vostok::render::options *this,
        vostok::resources::queries_result *data)
{
  int v2; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v3[2]; // [esp-4h] [ebp-20h] BYREF
  vostok::memory::reader F; // [esp+4h] [ebp-18h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> pinned_data; // [esp+10h] [ebp-Ch] BYREF

  if ( data->m_result == 1 )
  {
    v3[0].m_object = (vostok::resources::managed_resource *)&data->m_queries[0].m_managed_resource;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v3[0].m_object);
    v3[0].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      v3,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &pinned_data,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v3[0].m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
    F.m_data = pinned_data.m_data;
    F.m_pointer = pinned_data.m_data;
    F.m_size = pinned_data.m_size;
    vostok::render::options::load_impl(&F, v2, (vostok::render::options *)v3[1].m_object);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_data);
  }
}
