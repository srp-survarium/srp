void __thiscall survarium::damage_zone_cook::construct_resource(
        survarium::damage_zone_cook *this,
        vostok::memory::base_allocator *allocator)
{
  char *v3; // eax
  _DWORD *v4; // eax
  survarium::damage_zone *v5; // ecx

  v3 = type_info::raw_name(&survarium::damage_zone `RTTI Type Descriptor');
  v4 = allocator->call_malloc(
         allocator,
         632,
         v3,
         "survarium::damage_zone_cook::construct_resource",
         ".\\damage_zone_cook.cpp",
         257);
  if ( v4 )
    survarium::damage_zone::damage_zone(v5, v4, this->m_game_world);
}
