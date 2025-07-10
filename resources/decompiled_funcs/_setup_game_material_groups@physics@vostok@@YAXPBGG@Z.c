void __usercall vostok::physics::setup_game_material_groups(
        const unsigned __int16 *game_material_groups@<eax>,
        const unsigned __int16 game_materials_count@<cx>)
{
  vostok::physics::g_game_material_groups = game_material_groups;
  vostok::physics::g_game_materials_count = game_materials_count;
}
