int __thiscall survarium::damage_zone_cook::calculate_max_requests_count(
        survarium::damage_zone_cook *this,
        const vostok::configs::binary_config_value *cfg)
{
  int v2; // ecx
  const vostok::configs::binary_config_value *v3; // eax
  int v4; // ebx
  int v5; // eax

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)cfg,
         (unsigned int)"sound_zones") )
  {
    v3 = vostok::configs::binary_config_value::operator[](cfg, "sound_zones");
    v2 = 24;
    v4 = 24 * v3->count / 24;
  }
  else
  {
    v4 = 0;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v2,
         (int)cfg,
         (unsigned int)"effect_zones") )
  {
    v5 = 24 * vostok::configs::binary_config_value::operator[](cfg, "effect_zones")->count / 24;
  }
  else
  {
    v5 = 0;
  }
  return 4 * (v4 + v5) + 1;
}
