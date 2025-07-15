void __thiscall vostok::render::shader_binary_source_cook::~shader_binary_source_cook(
        vostok::render::shader_binary_source_cook *this)
{
  this->__vftable = (vostok::render::shader_binary_source_cook_vtbl *)&vostok::render::shader_binary_source_cook::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_parent_task.m_function);
  this->__vftable = (vostok::render::shader_binary_source_cook_vtbl *)&vostok::resources::cook_base::`vftable';
}
