vostok::render::debug::draw_triangles_command *__thiscall vostok::render::debug::draw_triangles_command::`scalar deleting destructor'(
        vostok::render::debug::draw_triangles_command *this,
        char a2)
{
  vostok::render::debug::draw_triangles_command::~draw_triangles_command(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
