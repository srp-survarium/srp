void __userpurge vostok::memory::managed_allocator_base::initialize(
        vostok::memory::managed_node *arena@<eax>,
        vostok::memory::managed_node *size@<edx>,
        vostok::memory::managed_node *this)
{
  this->m_next_pinned = arena;
  this->m_next_wait_for_free = size;
  this->m_place_pos = (unsigned __int8 *)size;
  this->m_owner = (vostok::memory::managed_node_owner *)arena;
  if ( arena )
    vostok::memory::managed_node::managed_node(this, (int)arena, managed_node_free, (unsigned int)size);
}
