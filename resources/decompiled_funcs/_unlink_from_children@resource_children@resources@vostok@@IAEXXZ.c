void __usercall vostok::resources::resource_children::unlink_from_children(
        vostok::resources::resource_children *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::resources::resource_base *a3@<esi>)
{
  vostok::resources::resource_children **i; // eax
  vostok::resources::resource_children *v4; // edi

  for ( i = &a3->m_children_resources.m_first->resource; i; i = &a3->m_children_resources.m_first->resource )
  {
    v4 = *i;
    vostok::resources::resource_children::unlink_parent_resource(*i, a2, a3);
    a3->unlink_child_resource(a3, (vostok::resources::resource_base *)v4);
  }
}
