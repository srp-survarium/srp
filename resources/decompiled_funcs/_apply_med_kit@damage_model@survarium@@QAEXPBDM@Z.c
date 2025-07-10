void __thiscall survarium::damage_model::apply_med_kit(
        survarium::damage_model *this,
        const char *part_name,
        float amount)
{
  survarium::game_camera *v3; // ecx
  survarium::body_part_parameters *part; // [esp+Ch] [ebp-4h]

  part = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(this, part_name);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::body_part_parameters::increase_health(part, amount);
}
