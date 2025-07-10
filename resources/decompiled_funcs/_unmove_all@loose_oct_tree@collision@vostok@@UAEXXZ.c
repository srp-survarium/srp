void __thiscall vostok::collision::loose_oct_tree::unmove_all(vostok::collision::loose_oct_tree *this)
{
  vostok::collision::oct_node *m_root; // eax
  void (__cdecl *predicate)(const vostok::collision::object *); // [esp+4h] [ebp-4h] BYREF

  predicate = (void (__cdecl *)(const vostok::collision::object *))this;
  m_root = this->m_root;
  predicate = unmove_object;
  if ( m_root )
    vostok::collision::loose_oct_tree::for_each_iterate<void (__cdecl *)(vostok::collision::object const *)>(
      this,
      &predicate,
      m_root,
      &this->m_aabb_center,
      this->m_aabb_extents);
}
