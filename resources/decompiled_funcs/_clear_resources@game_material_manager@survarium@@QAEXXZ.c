void __thiscall survarium::game_material_manager::clear_resources(survarium::game_material_manager *this)
{
  survarium::game_material_manager::delete_pairs(this);
  survarium::game_material_manager::delete_materials(this);
}
