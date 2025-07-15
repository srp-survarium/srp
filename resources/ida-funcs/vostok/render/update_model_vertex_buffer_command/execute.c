void __thiscall vostok::render::update_model_vertex_buffer_command::execute(
        vostok::render::update_model_vertex_buffer_command *this,
        vostok::render::engine::world *a2)
{
  vostok::render::engine::world::update_model_vertex_buffer(&this->m_object, &this->m_fragments, a2);
}
