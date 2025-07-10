vostok::render::functor_command *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::environment_probe_properties>::`scalar deleting destructor'(
        vostok::render::functor_command *this,
        char a2)
{
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::sky_ambient_occlusion_properties>::~functor_with_big_buffer_to_copy_command<vostok::render::sky_ambient_occlusion_properties>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
