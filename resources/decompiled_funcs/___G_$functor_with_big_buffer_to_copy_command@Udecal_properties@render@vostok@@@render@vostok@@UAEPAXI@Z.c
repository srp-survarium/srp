vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties> *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties>::`scalar deleting destructor'(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties> *this,
        char a2)
{
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties>::~functor_with_big_buffer_to_copy_command<vostok::render::decal_properties>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
