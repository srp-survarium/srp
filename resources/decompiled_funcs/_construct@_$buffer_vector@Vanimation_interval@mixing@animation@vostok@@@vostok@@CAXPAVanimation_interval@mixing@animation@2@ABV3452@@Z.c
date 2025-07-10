void __cdecl vostok::buffer_vector<vostok::animation::mixing::animation_interval>::construct(
        vostok::animation::mixing::animation_interval *p,
        const vostok::animation::mixing::animation_interval *value)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // [esp+8h] [ebp-4h]

  v2 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)operator new(0xCu, (void *)p);
  if ( v2 )
  {
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      v2,
      &value->m_animation);
    v2[1].m_object = (vostok::resources::managed_resource *)LODWORD(value->m_start_time);
    v2[2].m_object = (vostok::resources::managed_resource *)LODWORD(value->m_length);
  }
}
