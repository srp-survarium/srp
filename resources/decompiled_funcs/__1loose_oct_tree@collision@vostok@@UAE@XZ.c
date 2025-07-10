void __fastcall vostok::collision::loose_oct_tree::~loose_oct_tree(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::loose_oct_tree *a2)
{
  vostok::collision::oct_node *m_root; // eax

  m_root = a2->m_root;
  a2->__vftable = (vostok::collision::loose_oct_tree_vtbl *)&vostok::collision::loose_oct_tree::`vftable';
  if ( m_root )
    vostok::collision::loose_oct_tree::remove_nodes(a2, m_root);
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::collision::vertex_allocator,vostok::memory::detail::call_destructor_predicate>(
    &a2->m_allocator,
    a2->m_allocator->m_allocator);
}
