vostok::render::base_scene_view *__thiscall vostok::render::base_scene_view::`scalar deleting destructor'(
        vostok::render::base_scene_view *this,
        char a2)
{
  vostok::render::base_scene_view *m_object; // eax

  m_object = this->next_scene_view.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->next_scene_view.m_object->vostok::resources::unmanaged_intrusive_base,
      this->next_scene_view.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
