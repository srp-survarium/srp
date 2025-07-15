void __thiscall survarium::artefact_base::get_item_props(
        survarium::artefact_base *this,
        survarium::inventory_item_props *props)
{
  unsigned int m_time_left_to_cool; // eax

  survarium::inventory_item::get_item_props(this, props);
  m_time_left_to_cool = this->m_time_left_to_cool;
  if ( m_time_left_to_cool )
    props->cooldown = 100
                    - (unsigned __int64)((double)m_time_left_to_cool * s_spot_max_distance / (double)this->m_cooldown_ms);
}
