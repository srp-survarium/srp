void __thiscall survarium::inventory_cook::inventory_cook(survarium::inventory_cook *this)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v3; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v4; // ecx
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v5; // [esp+0h] [ebp-Ch]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v6; // [esp+0h] [ebp-Ch]

  vostok::resources::translate_query_cook::translate_query_cook(
    (vostok::resources::translate_query_cook *)0x42,
    &s_inventory_cook,
    reuse_false,
    0xFFFFFFFB,
    0,
    v5);
  s_inventory_cook.__vftable = (survarium::inventory_cook_vtbl *)&survarium::inventory_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_inventory_cook, v1);
  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x49,
      &s_items_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v6);
    s_items_cook.__vftable = (survarium::items_cook_vtbl *)&survarium::items_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_items_cook, v2);
    atexit((int (__cdecl *)())survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_items_cook__);
  }
  if ( (_S7 & 2) == 0 )
  {
    _S7 |= 2u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x53,
      &s_damage_model_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v6);
    s_damage_model_cook.__vftable = (survarium::damage_model_cook_vtbl *)&survarium::damage_model_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_damage_model_cook, v3);
    atexit((int (__cdecl *)())survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_damage_model_cook__);
  }
  if ( (_S7 & 4) == 0 )
  {
    _S7 |= 4u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x47,
      &s_weapon_ammunition_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      v6);
    s_weapon_ammunition_cook.__vftable = (survarium::weapon_ammunition_cook_vtbl *)&survarium::weapon_ammunition_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_weapon_ammunition_cook, v4);
    atexit((int (__cdecl *)())survarium::inventory_cook::inventory_cook_::_2_::_dynamic_atexit_destructor_for__s_weapon_ammunition_cook__);
  }
}
