survarium::post_process_game_effect_presenter *__thiscall survarium::post_process_game_effect_presenter::`scalar deleting destructor'(
        survarium::post_process_game_effect_presenter *this,
        char a2)
{
  vostok::render::environment_properties::~environment_properties(
    (vostok::render::environment_properties *)this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_result);
  this->__vftable = (survarium::post_process_game_effect_presenter_vtbl *)&survarium::base_game_effect_presenter::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
