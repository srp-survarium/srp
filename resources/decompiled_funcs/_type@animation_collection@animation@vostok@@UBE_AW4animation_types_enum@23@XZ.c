vostok::animation::animation_types_enum __thiscall vostok::animation::animation_collection::type(
        vostok::animation::animation_collection *this)
{
  return this->m_animations.m_begin->m_object->type(this->m_animations.m_begin->m_object);
}
