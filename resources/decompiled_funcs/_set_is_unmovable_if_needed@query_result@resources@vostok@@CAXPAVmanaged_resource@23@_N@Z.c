void __usercall vostok::resources::query_result::set_is_unmovable_if_needed(
        vostok::resources::managed_resource *resource@<eax>,
        vostok::memory::managed_node_owner *is_unmovable@<ecx>)
{
  if ( resource )
  {
    if ( (resource->m_node->m_is_unmovable != 0) != (_BYTE)is_unmovable )
      vostok::memory::managed_node_owner::set_is_unmovable(
        is_unmovable,
        (int)&resource->vostok::memory::managed_node_owner,
        (bool)is_unmovable);
  }
}
