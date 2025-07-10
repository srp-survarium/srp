vostok::render::speedtree_instance *__thiscall vostok::render::speedtree_instance::`scalar deleting destructor'(
        vostok::render::speedtree_instance *this,
        char a2)
{
  vostok::render::speedtree_tree_base *m_object; // eax

  m_object = this->m_speedtree_tree_ptr.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_speedtree_tree_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_speedtree_tree_ptr.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
