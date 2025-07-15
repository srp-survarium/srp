void __thiscall survarium::damage_model::apply_affect(
        survarium::damage_model *this,
        const char *part_name,
        survarium::hit_affects_type_enum affect,
        survarium::affect_event_type_enum event_type)
{
  survarium::game_camera *v4; // ecx
  survarium::body_part_parameters *part; // [esp+8h] [ebp-4h]

  part = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(this, part_name);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::body_part_parameters::apply_affect_by_force(part, affect, event_type, this->m_last_tick_time_in_ms);
}
