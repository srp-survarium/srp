char __usercall survarium::game_effect_transited_to_zero_predicate::operator()@<al>(
        survarium::game_effect_node *effect@<edi>,
        const char *a2@<ebx>,
        const char *a3@<esi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::memory::doug_lea_allocator *m_object; // ecx
  survarium::game_effect_interval *v6; // esi
  unsigned int i; // ebx
  vostok::intrusive_ptr<survarium::single_game_effect,survarium::single_game_effect,vostok::threading::single_threading_policy> *v8; // eax
  unsigned int v12; // [esp+0h] [ebp-8h]
  int v13; // [esp+4h] [ebp-4h]

  if ( effect->state.current_weight != effect->state.target_weight )
    return 0;
  ((void (__thiscall *)(vostok::animation::base_interpolator *, _DWORD))effect->interpolator->~vostok::animation::base_interpolator)(
    effect->interpolator,
    0);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&effect->time_calculator);
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&effect->effect);
  v12 = 0;
  if ( effect->intervals_count )
  {
    v13 = 0;
    do
    {
      v6 = &effect->intervals[v13];
      for ( i = 0; i < v6->effects_count; ++i )
      {
        v8 = &v6->effects[i];
        m_object = (vostok::memory::doug_lea_allocator *)v8->m_object;
        if ( v8->m_object )
        {
          if ( m_object->m_user_thread_logging_name-- == (const char *)1 )
            v8->m_object->m_emitter.m_object->destroy(v8->m_object->m_emitter.m_object, v8->m_object);
        }
      }
      ++v12;
      ++v13;
    }
    while ( v12 < effect->intervals_count );
  }
  vostok::memory::doug_lea_allocator::free_impl(m_object, (int)survarium::g_allocator, (char *)effect, a3, a2, v12);
  return 1;
}
