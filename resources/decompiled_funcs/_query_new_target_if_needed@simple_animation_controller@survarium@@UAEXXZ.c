void __thiscall survarium::simple_animation_controller::query_new_target_if_needed(
        survarium::simple_animation_controller *this)
{
  if ( this->m_last_animation_emitted )
  {
    survarium::human_npc::on_animation_end((survarium::human_npc *)this);
    this->m_current_parameters.reset(&this->m_current_parameters);
    this->m_target_parameters.reset(&this->m_target_parameters);
  }
}
