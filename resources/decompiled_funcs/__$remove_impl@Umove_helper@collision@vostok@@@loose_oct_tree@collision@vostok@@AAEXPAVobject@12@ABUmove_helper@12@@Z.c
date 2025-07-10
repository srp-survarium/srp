void __usercall vostok::collision::loose_oct_tree::remove_impl<vostok::collision::move_helper>(
        vostok::collision::loose_oct_tree *this@<esi>,
        vostok::collision::object *object@<ecx>,
        const vostok::collision::move_helper *predicate@<eax>)
{
  vostok::collision::oct_node *m_node; // ebp
  vostok::collision::object *objects; // eax
  vostok::collision::object *i; // edx
  vostok::collision::object *m_next; // eax
  void (__thiscall *insert)(struct vostok::collision::loose_oct_tree *, vostok::collision::object *, const vostok::math::float4x4 *); // edx
  vostok::collision::vertex_allocator *m_allocator; // eax
  vostok::collision::oct_node *m_root; // ecx
  vostok::collision::object *v11; // edi
  vostok::collision::oct_node *m_nodes; // edx
  vostok::collision::object *v13; // ebp
  vostok::collision::object *m_object; // [esp-8h] [ebp-14h]
  const vostok::math::float4x4 *m_local_to_world; // [esp-4h] [ebp-10h]

  --this->m_object_count;
  m_node = object->m_node;
  objects = m_node->objects;
  for ( i = 0; objects != object; objects = objects->m_next )
    i = objects;
  m_next = objects->m_next;
  object->m_node = 0;
  object->m_next = 0;
  if ( i )
  {
    i->m_next = m_next;
    predicate->m_tree->insert(predicate->m_tree, predicate->m_object, predicate->m_local_to_world);
    predicate->m_object->m_moved = 1;
  }
  else
  {
    m_node->objects = m_next;
    insert = predicate->m_tree->insert;
    m_local_to_world = predicate->m_local_to_world;
    m_object = predicate->m_object;
    if ( m_next )
    {
      ((void (__stdcall *)(vostok::collision::object *, const vostok::math::float4x4 *))insert)(
        m_object,
        m_local_to_world);
      predicate->m_object->m_moved = 1;
    }
    else
    {
      ((void (__stdcall *)(vostok::collision::object *, const vostok::math::float4x4 *))insert)(
        m_object,
        m_local_to_world);
      predicate->m_object->m_moved = 1;
      vostok::collision::loose_oct_tree::remove_octant(this, m_node, 0);
      m_allocator = this->m_allocator;
      if ( m_allocator->m_node_count == 1 && this->m_object_count <= 8 )
      {
        m_root = this->m_root;
        v11 = m_root->objects;
        this->m_object_count = 0;
        m_nodes = m_allocator->m_nodes;
        --m_allocator->m_node_count;
        m_root->parent = m_nodes;
        m_allocator->m_nodes = m_root;
        this->m_root = 0;
        this->m_initialized = 0;
        if ( v11 )
        {
          do
          {
            v13 = v11->m_next;
            v11->m_node = 0;
            v11->m_next = 0;
            vostok::collision::loose_oct_tree::insert_impl(this, v11);
            v11 = v13;
          }
          while ( v13 );
        }
      }
    }
  }
}
