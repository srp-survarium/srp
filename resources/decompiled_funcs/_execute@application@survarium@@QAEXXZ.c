void __thiscall survarium::application::execute(survarium::application *this, survarium::application *thisa)
{
  vostok::engine::engine_world::run((vostok::engine::engine_world *)this);
  thisa->m_exit_code = s_world.m_variable->get_exit_code(s_world.m_variable);
}
