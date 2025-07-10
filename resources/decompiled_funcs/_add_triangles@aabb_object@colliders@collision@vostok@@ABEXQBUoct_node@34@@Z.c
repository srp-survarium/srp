void __thiscall vostok::collision::colliders::aabb_object::add_triangles(
        vostok::collision::colliders::aabb_object *this,
        const vostok::collision::oct_node *const node)
{
  const vostok::collision::oct_node *v3; // esi
  vostok::collision::object *i; // esi

  v3 = node;
  do
  {
    if ( v3->octants[0] )
      vostok::collision::colliders::aabb_object::add_triangles(this, v3->octants[0]);
    v3 = (const vostok::collision::oct_node *)((char *)v3 + 4);
  }
  while ( v3 != (const vostok::collision::oct_node *)&node->parent );
  for ( i = node->objects; i; i = i->m_next )
    i->add_triangles(i, this->m_triangles);
}
