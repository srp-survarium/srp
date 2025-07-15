vostok::render::environment_probe_properties *__thiscall vostok::render::environment_probe_properties::operator=(
        vostok::render::environment_probe_properties *this,
        const vostok::render::environment_probe_properties *__that,
        int a3)
{
  vostok::math::float4 *face_average_colors; // ecx
  int v5; // edx
  _DWORD *p_w; // edi
  _DWORD *v7; // esi
  bool v8; // zf
  int v10; // [esp+18h] [ebp+Ch]

  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)a3,
    &__that->cooked_render_texture_specular);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 4),
    &__that->cooked_render_texture_diffuse);
  vostok::fixed_string<260>::operator=((vostok::fixed_string<260> *)(a3 + 8), &__that->texture_name);
  qmemcpy(&__that->transform, (const void *)(a3 + 280), sizeof(__that->transform));
  qmemcpy(&__that->inner_box_transform, (const void *)(a3 + 344), sizeof(__that->inner_box_transform));
  face_average_colors = __that->face_average_colors;
  v5 = a3 - (_DWORD)__that;
  v10 = 6;
  do
  {
    face_average_colors->x = *(float *)((char *)&face_average_colors->x + v5);
    face_average_colors->y = *(float *)((char *)&face_average_colors->y + v5);
    face_average_colors->z = *(float *)((char *)&face_average_colors->z + v5);
    v7 = (_DWORD *)((char *)&face_average_colors->w + v5);
    p_w = (_DWORD *)&face_average_colors->w;
    ++face_average_colors;
    v8 = v10-- == 1;
    *p_w = *v7;
  }
  while ( !v8 );
  __that->location = *(vostok::math::float3 *)(a3 + 504);
  __that->outer_radius = *(float *)(a3 + 516);
  __that->inner_radius = *(float *)(a3 + 520);
  __that->diffuse_multiplier = *(float *)(a3 + 524);
  __that->specular_multiplier = *(float *)(a3 + 528);
  __that->preview_mip = *(_DWORD *)(a3 + 532);
  __that->cubemap_resolution = *(_DWORD *)(a3 + 536);
  __that->texture_invalidated = *(_BYTE *)(a3 + 540);
  __that->enabled = *(_BYTE *)(a3 + 541);
  __that->smart_attenuation = *(_BYTE *)(a3 + 542);
  __that->geometry = *(_DWORD *)(a3 + 544);
  return (vostok::render::environment_probe_properties *)__that;
}
