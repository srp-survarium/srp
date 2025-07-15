vostok::render::update_model_vertex_buffer_command *__thiscall vostok::render::update_model_vertex_buffer_command::`vector deleting destructor'(
        vostok::render::update_model_vertex_buffer_command *this,
        char a2)
{
  vostok::render::update_model_vertex_buffer_command::~update_model_vertex_buffer_command(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
