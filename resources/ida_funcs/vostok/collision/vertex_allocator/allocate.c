vostok::collision::oct_node *__thiscall vostok::collision::vertex_allocator::allocate(
        vostok::collision::vertex_allocator *this)
{
  vostok::collision::oct_node *result; // eax

  result = this->m_nodes;
  ++this->m_node_count;
  if ( result )
    this->m_nodes = result->parent;
  else
    result = (vostok::collision::oct_node *)this->m_allocator->call_malloc(this->m_allocator, 40);
  result->objects = 0;
  result->parent = 0;
  *(_QWORD *)result->octants = 0;
  *(_QWORD *)&result->octants[2] = 0;
  *(_QWORD *)&result->octants[4] = 0;
  *(_QWORD *)&result->octants[6] = 0;
  return result;
}
