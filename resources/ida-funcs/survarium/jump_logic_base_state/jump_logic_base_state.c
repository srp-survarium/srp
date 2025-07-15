void __thiscall survarium::jump_logic_base_state::jump_logic_base_state(
        survarium::jump_logic_base_state *this,
        survarium::jump_logic *owner)
{
  vostok::ai::fsm_state::fsm_state(this);
  this->__vftable = (survarium::jump_logic_base_state_vtbl *)&survarium::jump_logic_base_state::`vftable';
  this->m_jump_logic = owner;
  this->m_user = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_animation);
  this->m_interval_id_to_wait_for = -1;
  this->m_is_jump_finished = 0;
}
