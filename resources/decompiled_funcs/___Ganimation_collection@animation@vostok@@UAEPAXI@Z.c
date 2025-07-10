vostok::animation::animation_collection *__thiscall vostok::animation::animation_collection::`scalar deleting destructor'(
        vostok::animation::animation_collection *this,
        char a2)
{
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> **p_m_end; // edi

  this->__vftable = (vostok::animation::animation_collection_vtbl *)&vostok::animation::animation_collection::`vftable';
  p_m_end = &this->m_animations.m_end;
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    this->m_animations.m_begin,
    &this->m_animations.m_end);
  *p_m_end = this->m_animations.m_begin;
  this->__vftable = (vostok::animation::animation_collection_vtbl *)&vostok::animation::animation_expression_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
