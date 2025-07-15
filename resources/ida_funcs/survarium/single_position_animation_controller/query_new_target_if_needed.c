void __thiscall survarium::single_position_animation_controller::query_new_target_if_needed(
        survarium::single_position_animation_controller *this)
{
  survarium::human_npc *v2; // ecx

  v2 = (survarium::human_npc *)(this->m_navigation_path._M_impl._M_finish - this->m_navigation_path._M_impl._M_start - 1);
  if ( this->m_next_key_point > (unsigned int)v2 )
  {
    survarium::human_npc::on_movement_end(v2, (int)this->m_owner);
    this->m_current_parameters.reset(&this->m_current_parameters);
    this->m_target_parameters.reset(&this->m_target_parameters);
  }
}
