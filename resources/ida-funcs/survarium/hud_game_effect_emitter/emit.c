vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *__thiscall survarium::hud_game_effect_emitter::emit(
        survarium::hud_game_effect_emitter *this,
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *result)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  survarium::pure_game_effect_emitter_base *v6; // ecx
  char *v7; // ebx
  survarium::hud_game_effect *v8; // ecx
  survarium::game_effect *v9; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-10h] [ebp-1Ch] BYREF
  survarium::hud_effects_enum m_type; // [esp-Ch] [ebp-18h]
  const survarium::value_animation<float,survarium::hud_game_effect_emitter_cook> *m_priority; // [esp-8h] [ebp-14h]
  survarium::pure_game_effect_emitter_base **m_animation; // [esp-4h] [ebp-10h]
  const char *v15; // [esp+0h] [ebp-Ch]
  const char *v16; // [esp+4h] [ebp-8h]
  unsigned int v17; // [esp+8h] [ebp-4h]

  v2 = survarium::g_allocator;
  v4 = type_info::raw_name(&survarium::hud_game_effect `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v2, 0x28u, v4, v15, v16, v17);
  if ( v7 )
  {
    m_animation = (survarium::pure_game_effect_emitter_base **)this->m_animation;
    m_priority = (const survarium::value_animation<float,survarium::hud_game_effect_emitter_cook> *)this->m_priority;
    m_type = this->m_type;
    v11.m_object = v6;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v11,
      this);
    survarium::hud_game_effect::hud_game_effect(
      v8,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v7,
      v11,
      m_type,
      m_priority,
      m_animation);
  }
  else
  {
    v9 = 0;
  }
  result->m_object = 0;
  if ( v9 )
  {
    ++v9->m_reference_count;
    result->m_object = v9;
  }
  return result;
}
