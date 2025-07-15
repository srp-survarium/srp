vostok::render::render_cc_bool *__thiscall vostok::render::render_cc_float::`scalar deleting destructor'(
        vostok::render::render_cc_bool *this,
        char a2)
{
  vostok::console_commands::console_command::~console_command(&this->vostok::console_commands::cc_bool);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
