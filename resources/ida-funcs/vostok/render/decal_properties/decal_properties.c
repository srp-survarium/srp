void __thiscall vostok::render::decal_properties::decal_properties(
        vostok::render::decal_properties *this,
        vostok::render::decal_properties *__that,
        int a3)
{
  qmemcpy(__that, (const void *)a3, 0x40u);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&__that->material,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 64));
  __that->width_height_far_distance = *(vostok::math::float3 *)(a3 + 68);
  __that->alpha_angle = *(float *)(a3 + 80);
  __that->clip_angle = *(float *)(a3 + 84);
  __that->draw_priority = *(float *)(a3 + 88);
  __that->projection_on_terrain_geometry = *(_BYTE *)(a3 + 92);
  __that->projection_on_static_geometry = *(_BYTE *)(a3 + 93);
  __that->projection_on_skeleton_geometry = *(_BYTE *)(a3 + 94);
  __that->projection_on_particle_geometry = *(_BYTE *)(a3 + 95);
}


void __thiscall vostok::render::decal_properties::decal_properties(vostok::render::decal_properties *this, int a2)
{
  vostok::math::float4x4 v2; // [esp+Ch] [ebp-50h] BYREF
  float v3; // [esp+50h] [ebp-Ch]
  float v4; // [esp+54h] [ebp-8h]

  *(_DWORD *)(a2 + 64) = 0;
  qmemcpy((void *)a2, vostok::math::float4x4::identity(&this->transform, &v2), 0x40u);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 64),
    0);
  v3 = s_bm_current_air_resistance;
  v4 = s_bm_current_air_resistance;
  *(float *)(a2 + 68) = s_bm_current_air_resistance;
  *(float *)(a2 + 72) = v3;
  *(float *)(a2 + 76) = v4;
  *(float *)(a2 + 80) = FLOAT_N1_0;
  *(float *)(a2 + 84) = FLOAT_N1_0;
  *(_BYTE *)(a2 + 92) = 1;
  *(_BYTE *)(a2 + 93) = 1;
  *(_BYTE *)(a2 + 94) = 1;
  *(_BYTE *)(a2 + 95) = 1;
}
