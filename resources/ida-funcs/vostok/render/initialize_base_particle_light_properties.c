void __cdecl vostok::render::initialize_base_particle_light_properties(
        vostok::render::light_props *props,
        bool enable_shadows,
        bool static_shadows,
        float shadow_transparency,
        unsigned int shadow_map_size_index)
{
  float v5; // xmm0_4
  float v6; // xmm0_4
  vostok::math::float4x4 v7; // [esp+0h] [ebp-50h] BYREF
  vostok::math::float3 v8; // [esp+40h] [ebp-10h] BYREF

  v5 = s_spot_max_distance;
  props->color = -1;
  props->range = v5;
  memset(&v8, 0, sizeof(v8));
  qmemcpy(props, vostok::math::create_translation(&v8, &v7), 0x40u);
  props->attenuation_power = retry_to_increase_quality_period_sec;
  props->intensity = FLOAT_5_0;
  props->spot_umbra_angle = 0.0;
  props->spot_penumbra_angle = 0.0;
  props->spot_falloff = 0.0;
  v6 = s_bm_current_air_resistance;
  props->type = light_type_point;
  props->diffuse_influence_factor = v6;
  props->specular_influence_factor = v6;
  props->lighting_model = 3;
  props->shadower = 0;
  props->use_with_lpv = 0;
  props->enabled = 0;
  props->particle_light = 1;
  if ( enable_shadows )
  {
    props->local_light_z_bias = FLOAT_0_000099999997;
    props->shadow_map_size_index = shadow_map_size_index;
    props->does_cast_shadows = 1;
    props->shadow_distribution_sides[0] = 1;
    props->shadow_distribution_sides[1] = 1;
    props->shadow_distribution_sides[2] = 1;
    props->shadow_distribution_sides[3] = 1;
    props->shadow_distribution_sides[4] = 1;
    props->shadow_distribution_sides[5] = 1;
    props->shadow_transparency = shadow_transparency;
  }
  else
  {
    props->does_cast_shadows = 0;
  }
  props->static_shadows = static_shadows;
}
