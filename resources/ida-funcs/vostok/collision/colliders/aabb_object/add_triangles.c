void __thiscall vostok::collision::colliders::aabb_object::add_triangles(
        vostok::collision::colliders::aabb_object *this,
        const vostok::collision::oct_node *const node)
{
  const vostok::collision::oct_node *v2; // ebx
  vostok::collision::object *i; // esi

  v2 = node;
  do
  {
    if ( v2->octants[0] )
      vostok::collision::colliders::aabb_object::add_triangles(this, v2->octants[0]);
    v2 = (const vostok::collision::oct_node *)((char *)v2 + 4);
  }
  while ( v2 != (const vostok::collision::oct_node *)&node->parent );
  for ( i = node->objects; i; i = i->m_next )
    i->add_triangles(i, this->m_triangles);
}
