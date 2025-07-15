void __thiscall vostok::collision::loose_oct_tree::for_each(
        vostok::collision::loose_oct_tree *this,
        const fastdelegate::FastDelegate<void __cdecl(vostok::collision::object const *)> *predicate)
{
  vostok::collision::oct_node *m_root; // eax

  m_root = this->m_root;
  if ( m_root )
    vostok::collision::loose_oct_tree::for_each_iterate<fastdelegate::FastDelegate<void __cdecl (vostok::collision::object const *)>>(
      this,
      predicate,
      m_root,
      &this->m_aabb_center,
      this->m_aabb_extents);
}
