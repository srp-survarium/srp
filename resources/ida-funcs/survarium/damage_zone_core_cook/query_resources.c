void __thiscall survarium::damage_zone_core_cook::query_resources(
        survarium::damage_zone_core_cook *this,
        vostok::buffer_vector<vostok::resources::request> *requests,
        const vostok::configs::binary_config_value *cfg)
{
  vostok::resources::request v3; // [esp+8h] [ebp-8h] BYREF

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)cfg,
         (unsigned int)"game_effect_on_inside") )
  {
    v3.path = (const char *)vostok::configs::binary_config_value::operator[](cfg, "game_effect_on_inside")->data.pointer;
    v3.id = game_effect_emitter_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v3);
  }
}
