void __thiscall survarium::artefact_base::tick(
        survarium::artefact_base *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::inventory_item *m_state; // ecx
  int v5; // edx
  bool v6; // zf
  int v7; // ecx
  survarium::artefact_base *v8; // ecx
  survarium::artefact_base *v9; // ecx

  m_state = (survarium::inventory_item *)this->m_state;
  if ( m_state != (survarium::inventory_item *)4 )
    this->m_time_left_to_cool = this->m_time_left_to_cool
                              - (this->m_time_left_to_cool < time_delta_ms
                               ? this->m_time_left_to_cool - time_delta_ms
                               : 0)
                              - time_delta_ms;
  if ( m_state == (survarium::inventory_item *)1 )
  {
    v5 = time_delta_ms + (this->m_time_left_to_spawn < time_delta_ms ? this->m_time_left_to_spawn - time_delta_ms : 0);
    v6 = this->m_time_left_to_spawn == v5;
    this->m_time_left_to_spawn -= v5;
    if ( v6 )
      this->m_state = artefact_state_spawned;
  }
  else if ( survarium::inventory_item::is_holder_assigned(m_state, (int)this) && v7 != 5 )
  {
    if ( this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder)->m_is_alive )
    {
      if ( this->m_state == artefact_state_picked_active )
      {
        this->tick_impl(this, time_delta_ms, current_time_ms);
        if ( this->active_effect_ended(this) )
          survarium::artefact_base::decrement_amount(v9, (int)this);
      }
    }
    else
    {
      if ( this->m_state == artefact_state_picked_active )
        survarium::artefact_base::decrement_amount(v8, (int)this);
      if ( this->m_amount )
      {
        this->disable_passive_effects(this);
        this->m_state = artefact_state_picked_dead;
      }
    }
  }
}
