vostok::collision::loose_oct_tree *__thiscall vostok::collision::loose_oct_tree::`scalar deleting destructor'(
        vostok::collision::loose_oct_tree *this,
        char a2)
{
  vostok::collision::oct_node *m_root; // eax

  m_root = this->m_root;
  this->__vftable = (vostok::collision::loose_oct_tree_vtbl *)&vostok::collision::loose_oct_tree::`vftable';
  if ( m_root )
    vostok::collision::loose_oct_tree::remove_nodes(this, m_root);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
