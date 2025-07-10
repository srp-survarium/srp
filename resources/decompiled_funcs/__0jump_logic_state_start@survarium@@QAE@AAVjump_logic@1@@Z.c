void __thiscall survarium::jump_logic_state_start::jump_logic_state_start(
        survarium::jump_logic_state_start *this,
        survarium::jump_logic *owner)
{
  survarium::jump_logic_base_state::jump_logic_base_state(this, owner);
  this->__vftable = (survarium::jump_logic_state_start_vtbl *)&survarium::jump_logic_state_start::`vftable';
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_preface_animation);
  this->m_preface_interval_ended = 0;
  this->m_jump_interval_ended = 0;
}
