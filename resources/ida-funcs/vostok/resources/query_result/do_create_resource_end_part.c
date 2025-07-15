void __thiscall vostok::resources::query_result::do_create_resource_end_part(
        vostok::resources::query_result *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2)
{
  if ( a2[65].m_object == (vostok::resources::managed_resource *)4 )
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      a2 + 162,
      0);
  if ( a2[65].m_object == (vostok::resources::managed_resource *)4 )
    a2[64].m_object = 0;
}
