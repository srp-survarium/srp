vostok::render::debug::draw_lines_command *__thiscall vostok::render::debug::draw_lines_command::`vector deleting destructor'(
        vostok::render::debug::draw_lines_command *this,
        char a2)
{
  vostok::render::debug::draw_lines_command::~draw_lines_command(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
