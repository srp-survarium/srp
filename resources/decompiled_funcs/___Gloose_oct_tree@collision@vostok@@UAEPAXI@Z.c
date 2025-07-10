vostok::collision::loose_oct_tree *__userpurge vostok::collision::loose_oct_tree::`scalar deleting destructor'@<eax>(
        vostok::collision::loose_oct_tree *this@<ecx>,
        const vostok::memory::detail::call_destructor_predicate *a2@<edi>,
        char a3)
{
  vostok::collision::oct_node *m_root; // eax

  m_root = this->m_root;
  this->__vftable = (vostok::collision::loose_oct_tree_vtbl *)&vostok::collision::loose_oct_tree::`vftable';
  if ( m_root )
    vostok::collision::loose_oct_tree::remove_nodes(this, m_root);
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::collision::vertex_allocator,vostok::memory::detail::call_destructor_predicate>(
    this->m_allocator->m_allocator,
    &this->m_allocator,
    a2);
  if ( (a3 & 1) != 0 )
    operator delete(this);
  return this;
}
