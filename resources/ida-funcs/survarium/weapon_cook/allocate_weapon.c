survarium::weapon *__thiscall survarium::weapon_cook::allocate_weapon(
        survarium::weapon_cook *this,
        survarium::base_game_scene *game_scene,
        vostok::math::float4x4 *preview_animation_count,
        unsigned __int8 shells_pfx_count,
        unsigned __int8 fire_pfx_count)
{
  char *v5; // eax
  survarium::weapon_core *v6; // ecx
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // edi
  vostok::animation::fingers_to_weapon_corrector *v10; // ecx
  int v11; // eax
  _DWORD *v12; // edx
  vostok::math::float4x4 *v13; // edi
  int v14; // eax
  int v15; // ecx
  _DWORD *v16; // edx
  int v17; // ecx
  _DWORD *v18; // eax
  const char *v20; // [esp+0h] [ebp-10h]
  const char *v21; // [esp+4h] [ebp-Ch]
  int v22; // [esp+8h] [ebp-8h]

  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)((char *)preview_animation_count + shells_pfx_count + fire_pfx_count),
         (int)survarium::g_allocator,
         4 * ((_DWORD)preview_animation_count + shells_pfx_count + fire_pfx_count) + 9472,
         "weapon",
         v20,
         v21,
         fire_pfx_count);
  if ( v5 )
  {
    survarium::weapon::weapon(game_scene, v6, (survarium::weapon *)v5, preview_animation_count);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = (_DWORD *)(v8 + 1696);
  if ( v8 == -1696 )
  {
    v11 = 0;
  }
  else
  {
    survarium::portable_interactive_object::portable_interactive_object(
      (survarium::portable_interactive_object *)v6,
      (int)v9,
      game_scene,
      ik_locator_id_idle);
    *v9 = &survarium::portable_interactive_object_with_finger_correction::`vftable';
    vostok::animation::fingers_to_weapon_corrector::fingers_to_weapon_corrector(v10, v8 + 3544);
    v11 = v8 + 1696;
  }
  *(_DWORD *)(v8 + 304) = v11;
  if ( preview_animation_count )
  {
    v12 = (_DWORD *)(v8 + 9472);
    v13 = preview_animation_count;
    do
    {
      if ( v12 )
        *v12 = 0;
      ++v12;
      v13 = (vostok::math::float4x4 *)((char *)v13 - 1);
    }
    while ( v13 );
  }
  v14 = v8 + 9472 + 4 * (_DWORD)preview_animation_count;
  *(_BYTE *)(v8 + 1505) = shells_pfx_count;
  v15 = 0;
  *(_DWORD *)(v8 + 1500) = v14;
  if ( shells_pfx_count )
  {
    do
    {
      v16 = (_DWORD *)(*(_DWORD *)(v8 + 1500) + 4 * v15);
      if ( v16 )
        *v16 = 0;
      ++v15;
    }
    while ( v15 != *(unsigned __int8 *)(v8 + 1505) );
  }
  *(_DWORD *)(v8 + 1496) = v14 + 4 * shells_pfx_count;
  v17 = 0;
  *(_BYTE *)(v8 + 1504) = fire_pfx_count;
  if ( v22 )
  {
    do
    {
      v18 = (_DWORD *)(*(_DWORD *)(v8 + 1496) + 4 * v17);
      if ( v18 )
        *v18 = 0;
      ++v17;
    }
    while ( v17 != *(unsigned __int8 *)(v8 + 1504) );
  }
  return (survarium::weapon *)v8;
}
