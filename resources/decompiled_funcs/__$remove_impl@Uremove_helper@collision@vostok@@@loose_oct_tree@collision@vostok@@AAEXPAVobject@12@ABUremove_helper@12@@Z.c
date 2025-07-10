void __usercall vostok::collision::loose_oct_tree::remove_impl<vostok::collision::remove_helper>(
        vostok::collision::loose_oct_tree *this@<esi>,
        vostok::collision::object *object@<edx>)
{
  vostok::collision::oct_node *m_node; // eax
  vostok::collision::object *objects; // ecx
  vostok::collision::object *i; // edi
  vostok::collision::object *m_next; // ecx
  vostok::collision::vertex_allocator *m_allocator; // eax
  vostok::collision::oct_node *m_root; // ecx
  vostok::collision::object *v8; // edi
  vostok::collision::oct_node *m_nodes; // edx
  vostok::collision::object *v10; // ebp

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
  }
  else
  {
    m_node->objects = m_next;
    if ( !m_next )
    {
      vostok::collision::loose_oct_tree::remove_octant(this, m_node, 0);
      m_allocator = this->m_allocator;
      if ( m_allocator->m_node_count == 1 && this->m_object_count <= 8 )
      {
        m_root = this->m_root;
        v8 = m_root->objects;
        this->m_object_count = 0;
        m_nodes = m_allocator->m_nodes;
        --m_allocator->m_node_count;
        m_root->parent = m_nodes;
        m_allocator->m_nodes = m_root;
        this->m_root = 0;
        this->m_initialized = 0;
        if ( v8 )
        {
          do
          {
            v10 = v8->m_next;
            v8->m_node = 0;
            v8->m_next = 0;
            vostok::collision::loose_oct_tree::insert_impl(this, v8);
            v8 = v10;
          }
          while ( v10 );
        }
      }
    }
  }
}
