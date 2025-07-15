unsigned int __thiscall vostok::ai::ai_world::get_node_id_by_name(vostok::ai::ai_world *this, const char *node_name)
{
  return this->m_engine->get_node_by_name(this->m_engine, node_name);
}
