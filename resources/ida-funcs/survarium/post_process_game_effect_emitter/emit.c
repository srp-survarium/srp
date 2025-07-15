vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *__thiscall survarium::post_process_game_effect_emitter::emit(
        survarium::post_process_game_effect_emitter *this,
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *result)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  survarium::pure_game_effect_emitter_base *v6; // ecx
  char *v7; // ebp
  survarium::post_process_game_effect *v8; // ecx
  int v9; // eax
  int v10; // esi
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v11; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v12; // [esp-8h] [ebp-18h] BYREF
  vostok::resources::resource_link *m_animation; // [esp-4h] [ebp-14h]
  const char *v14; // [esp+0h] [ebp-10h]
  const char *v15; // [esp+4h] [ebp-Ch]
  unsigned int v16; // [esp+8h] [ebp-8h]

  v2 = survarium::g_allocator;
  v4 = type_info::raw_name(&survarium::post_process_game_effect `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v2, 0x38u, v4, v14, v15, v16);
  if ( v7 )
  {
    m_animation = (vostok::resources::resource_link *)this->m_animation;
    v12.m_object = v6;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v12,
      this);
    survarium::post_process_game_effect::post_process_game_effect(
      v8,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v7,
      (const survarium::value_animation<vostok::render::environment_properties,survarium::post_process_game_effect_emitter_cook> *)v12.m_object,
      m_animation);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->sun_moon_texture,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v10 + 28));
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->sky_clouds_texture,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v10 + 32));
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->stratosphere_texture,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v10 + 36));
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->sky_shadows_texture,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v10 + 40));
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->lens_flares_mask_texture,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v10 + 44));
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)this->color_grading_textures,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(v10 + 48));
  v11 = result;
  result->m_object = 0;
  if ( v10 )
  {
    ++*(_DWORD *)(v10 + 24);
    result->m_object = (survarium::game_effect *)v10;
  }
  return v11;
}
