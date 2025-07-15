void __thiscall survarium::damage_model::register_body_part_damage_protector(
        survarium::damage_model *this,
        const char *part_name,
        survarium::damage_protector *protector)
{
  survarium::game_camera *v3; // ecx
  survarium::body_part_parameters *part; // [esp+8h] [ebp-4h]

  part = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(this, part_name);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::body_part_parameters::add_damage_protector(part, protector);
}
