void __usercall vostok::collision::loose_oct_tree::remove_impl<vostok::collision::move_helper>(
        vostok::collision::loose_oct_tree *this@<esi>,
        vostok::collision::object *object@<ecx>,
        const vostok::collision::move_helper *predicate@<eax>)
{
  vostok::collision::oct_node *m_node; // ebx
  vostok::collision::object *objects; // eax
  vostok::collision::object *v6; // edx
  vostok::collision::object *m_next; // eax
  vostok::collision::loose_oct_tree_vtbl *v8; // eax
  bool v9; // zf
  vostok::collision::oct_node *m_root; // ecx
  vostok::collision::object *v11; // eax
  vostok::collision::oct_node *m_head; // edx
  vostok::collision::object *v13; // ebx
  vostok::collision::object *m_object; // [esp-8h] [ebp-10h]
  const vostok::math::float4x4 *m_local_to_world; // [esp-4h] [ebp-Ch]

  --this->m_objects_count;
  m_node = object->m_node;
  objects = m_node->objects;
  v6 = 0;
  while ( objects != object )
  {
    v6 = objects;
    objects = objects->m_next;
  }
  m_next = objects->m_next;
  object->m_node = 0;
  object->m_next = 0;
  if ( v6 )
  {
    v6->m_next = m_next;
    m_local_to_world = predicate->m_local_to_world;
    v8 = predicate->m_tree->__vftable;
    m_object = predicate->m_object;
LABEL_6:
    ((void (__stdcall *)(vostok::collision::object *, const vostok::math::float4x4 *))v8->insert)(
      m_object,
      m_local_to_world);
    predicate->m_object->m_moved = 1;
    return;
  }
  m_node->objects = m_next;
  m_local_to_world = predicate->m_local_to_world;
  m_object = predicate->m_object;
  v9 = m_next == 0;
  v8 = predicate->m_tree->__vftable;
  if ( !v9 )
    goto LABEL_6;
  ((void (__stdcall *)(vostok::collision::object *, const vostok::math::float4x4 *))v8->insert)(
    m_object,
    m_local_to_world);
  predicate->m_object->m_moved = 1;
  vostok::collision::loose_oct_tree::remove_octant(this, m_node, 0);
  if ( this->m_allocated_nodes_count == 1 && this->m_objects_count <= 8 )
  {
    m_root = this->m_root;
    v11 = m_root->objects;
    m_head = this->m_head;
    this->m_objects_count = 0;
    this->m_allocated_nodes_count = 0;
    m_root->parent = m_head;
    this->m_head = m_root;
    this->m_root = 0;
    this->m_initialized = 0;
    if ( v11 )
    {
      do
      {
        v13 = v11->m_next;
        v11->m_node = 0;
        v11->m_next = 0;
        vostok::collision::loose_oct_tree::insert_impl((vostok::collision::loose_oct_tree *)m_root, this, v11);
        v11 = v13;
      }
      while ( v13 );
    }
  }
}


void __usercall vostok::collision::loose_oct_tree::remove_impl<vostok::collision::remove_helper>(
        vostok::collision::loose_oct_tree *this@<esi>,
        vostok::collision::object *object@<edx>)
{
  vostok::collision::oct_node *m_node; // eax
  vostok::collision::object *objects; // ecx
  vostok::collision::object *v4; // edi
  vostok::collision::object *m_next; // ecx
  vostok::collision::oct_node *m_root; // ecx
  vostok::collision::object *v7; // eax
  vostok::collision::oct_node *m_head; // edx
  vostok::collision::object *v9; // edi

  --this->m_objects_count;
  m_node = object->m_node;
  objects = m_node->objects;
  v4 = 0;
  while ( objects != object )
  {
    v4 = objects;
    objects = objects->m_next;
  }
  m_next = objects->m_next;
  object->m_node = 0;
  object->m_next = 0;
  if ( v4 )
  {
    v4->m_next = m_next;
  }
  else
  {
    m_node->objects = m_next;
    if ( !m_next )
    {
      vostok::collision::loose_oct_tree::remove_octant(this, m_node, 0);
      if ( this->m_allocated_nodes_count == 1 && this->m_objects_count <= 8 )
      {
        m_root = this->m_root;
        v7 = m_root->objects;
        m_head = this->m_head;
        this->m_objects_count = 0;
        this->m_allocated_nodes_count = 0;
        m_root->parent = m_head;
        this->m_head = m_root;
        this->m_root = 0;
        this->m_initialized = 0;
        if ( v7 )
        {
          do
          {
            v9 = v7->m_next;
            v7->m_node = 0;
            v7->m_next = 0;
            vostok::collision::loose_oct_tree::insert_impl((vostok::collision::loose_oct_tree *)m_root, this, v7);
            v7 = v9;
          }
          while ( v9 );
        }
      }
    }
  }
}
