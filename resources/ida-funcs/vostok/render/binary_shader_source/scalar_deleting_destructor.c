vostok::render::binary_shader_source *__thiscall vostok::render::binary_shader_source::`scalar deleting destructor'(
        vostok::render::binary_shader_source *this,
        char a2)
{
  vostok::render::binary_shader_source::~binary_shader_source(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
