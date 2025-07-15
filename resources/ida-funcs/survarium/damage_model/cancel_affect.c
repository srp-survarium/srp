void __thiscall survarium::damage_model::cancel_affect(
        survarium::damage_model *this,
        const char *part_name,
        survarium::hit_affects_type_enum affect)
{
  survarium::game_camera *v3; // ecx
  survarium::body_part_parameters *part; // [esp+8h] [ebp-4h]

  part = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(this, part_name);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::body_part_parameters::cancel_affect_by_force(part, affect);
}
