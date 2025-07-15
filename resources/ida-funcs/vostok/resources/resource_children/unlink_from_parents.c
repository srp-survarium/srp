void __usercall vostok::resources::resource_children::unlink_from_parents(
        vostok::resources::resource_children *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::resources::resource_children *a3@<esi>)
{
  vostok::resources::resource_base *resource; // edi

  while ( a3->m_parent_resources.m_size )
  {
    resource = a3->m_parent_resources.m_first->resource;
    resource->unlink_child_resource(resource, (vostok::resources::resource_base *)a3);
    vostok::resources::resource_children::unlink_parent_resource(a3, a2, resource);
  }
}
