void __thiscall survarium::damage_zone_core_cook::construct_resource(
        survarium::damage_zone_core_cook *this,
        vostok::memory::base_allocator *allocator)
{
  char *v2; // eax
  void *v3; // eax
  survarium::damage_zone_core *v4; // ecx

  v2 = type_info::raw_name(&survarium::damage_zone_core `RTTI Type Descriptor');
  v3 = allocator->call_malloc(
         allocator,
         552,
         v2,
         "survarium::damage_zone_core_cook::construct_resource",
         ".\\damage_zone_core_cook.cpp",
         80);
  if ( v3 )
    survarium::damage_zone_core::damage_zone_core(v4, (int)v3);
}
