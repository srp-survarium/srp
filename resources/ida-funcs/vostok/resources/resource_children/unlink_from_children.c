void __usercall vostok::resources::resource_children::unlink_from_children(
        vostok::resources::resource_children *this@<ecx>,
        vostok::resources::resource_base *a2@<esi>)
{
  vostok::resources::resource_base *resource; // edi
  vostok::resources::resource_link *m_first; // eax

  while ( 1 )
  {
    m_first = a2->m_children_resources.m_first;
    if ( !m_first )
      break;
    resource = m_first->resource;
    vostok::resources::resource_children::unlink_parent_resource(m_first->resource, a2);
    a2->unlink_child_resource(a2, resource);
  }
}
