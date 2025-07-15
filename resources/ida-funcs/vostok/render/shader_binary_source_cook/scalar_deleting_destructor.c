vostok::render::shader_binary_source_cook *__thiscall vostok::render::shader_binary_source_cook::`scalar deleting destructor'(
        vostok::render::shader_binary_source_cook *this,
        char a2)
{
  vostok::render::shader_binary_source_cook::~shader_binary_source_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
