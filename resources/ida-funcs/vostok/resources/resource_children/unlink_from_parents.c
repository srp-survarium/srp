void __usercall vostok::resources::resource_children::unlink_from_parents(
        vostok::resources::resource_children *this@<ecx>,
        vostok::resources::resource_base *a2@<esi>)
{
  vostok::resources::resource_base *resource; // edi

  while ( a2->m_parent_resources.m_size )
  {
    resource = a2->m_parent_resources.m_first->resource;
    resource->unlink_child_resource(resource, a2);
    vostok::resources::resource_children::unlink_parent_resource(a2, resource);
  }
}
