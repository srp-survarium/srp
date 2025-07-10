void __thiscall vostok::ai::behaviour::sort_goals(vostok::ai::behaviour *this)
{
  void *v1; // esp
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // eax
  int v4; // [esp+0h] [ebp-4Ch] BYREF
  vostok::ai::behaviour *v5; // [esp+4h] [ebp-48h]
  const void **i; // [esp+8h] [ebp-44h]
  const vostok::ai::sound_item **__last; // [esp+14h] [ebp-38h]
  void *v8; // [esp+24h] [ebp-28h]
  vostok::ai::planning::goal *m_first; // [esp+28h] [ebp-24h]
  survarium::game_camera *v10; // [esp+2Ch] [ebp-20h]
  char v11; // [esp+33h] [ebp-19h]
  const void **m_end; // [esp+34h] [ebp-18h]
  survarium::game_camera **m_begin; // [esp+38h] [ebp-14h]
  void *value; // [esp+3Ch] [ebp-10h] BYREF
  vostok::buffer_vector<void const *> v15; // [esp+40h] [ebp-Ch] BYREF
  const vostok::variant<32> **v16; // [esp+48h] [ebp-4h]

  v5 = this;
  v16 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
          (int)&this->m_goals);
  v1 = alloca(4 * (_DWORD)v16);
  v4 = (int)&v4;
  survarium::weapon_user_dead_state::finalize(v2);
  v10 = v3;
  v15.m_begin = (const void **)&v3->__vftable;
  v15.m_end = (const void **)&v3->__vftable;
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  m_first = v5->m_goals.m_first;
  for ( value = (void *)m_first; value; value = v8 )
  {
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(&v15, (const void **)&value);
    v8 = *(void **)value;
  }
  __last = (const vostok::ai::sound_item **)v15.m_end;
  stlp_std::sort<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
    (const vostok::ai::sound_item **)v15.m_begin,
    (const vostok::ai::sound_item **)v15.m_end,
    (bool (__cdecl *)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))vostok::ai::sort_goals_by_priority);
  vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::clear((vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v5->m_goals);
  m_begin = (survarium::game_camera **)v15.m_begin;
  m_end = v15.m_end;
  while ( m_begin != (survarium::game_camera **)m_end )
    vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v5->m_goals,
      *m_begin++,
      0);
  for ( i = v15.m_begin; i != v15.m_end; ++i )
    ;
}
