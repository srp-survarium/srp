vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *__thiscall survarium::random_permutation_game_effect_emitter::emit(
        survarium::random_permutation_game_effect_emitter *this,
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *result)
{
  unsigned int m_emitters_count; // esi
  void *v4; // esp
  unsigned int v5; // ecx
  const char *v6; // ecx
  survarium::pure_game_effect_emitter *m_object; // ecx
  vostok::memory::doug_lea_allocator *v8; // ecx
  survarium::pure_game_effect_emitter_base *v9; // ecx
  char *v10; // ebx
  double m_length; // st7
  survarium::composite_game_effect *v12; // ecx
  survarium::game_effect *v13; // eax
  survarium::game_effect **v14; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp+0h] [ebp-28h] BYREF
  float v17; // [esp+4h] [ebp-24h]
  const char *v18[3]; // [esp+8h] [ebp-20h] BYREF
  const char **v19; // [esp+14h] [ebp-14h] BYREF
  const char **v20; // [esp+18h] [ebp-10h]
  const char **v21; // [esp+1Ch] [ebp-Ch]
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> v22; // [esp+20h] [ebp-8h] BYREF
  vostok::buffer_vector<unsigned int> *v23; // [esp+24h] [ebp-4h] BYREF

  m_emitters_count = this->m_emitters_count;
  v4 = alloca(4 * m_emitters_count);
  v23 = 0;
  v19 = v18;
  v20 = v18;
  v21 = &v18[m_emitters_count];
  if ( m_emitters_count )
  {
    do
    {
      if ( ((1 << (char)v23) & this->m_active_emitters_mask) == 0 )
        vostok::buffer_vector<unsigned int>::push_back(v23, (int)&v19, (const unsigned int *)&v23);
      v23 = (vostok::buffer_vector<unsigned int> *)((char *)v23 + 1);
    }
    while ( (unsigned int)v23 < this->m_emitters_count );
  }
  v5 = 134775813 * this->m_random.m_seed + 1;
  this->m_random.m_seed = v5;
  v6 = v19[(v5 * (unsigned __int64)(unsigned int)(v20 - v19)) >> 32];
  v17 = COERCE_FLOAT(&v22);
  this->m_active_emitters_mask |= 1 << (char)v6;
  m_object = this->m_emitters[(_DWORD)v6].m_object;
  ((void (__thiscall *)(survarium::pure_game_effect_emitter *, float))m_object->emit)(
    m_object,
    COERCE_FLOAT(LODWORD(v17)));
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(
          v8,
          (int)survarium::g_allocator,
          0x28u,
          "random_permutation_game_effect",
          v18[0],
          v18[1],
          (const unsigned int)v18[2]);
  if ( v10 )
  {
    m_length = v22.m_object->m_length;
    v16.m_object = v9;
    v17 = m_length;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v16,
      this);
    survarium::composite_game_effect::composite_game_effect(
      v12,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v10,
      *(const float *)&v16.m_object,
      v17);
  }
  else
  {
    v13 = 0;
  }
  v14 = (survarium::game_effect **)(v10 + 36);
  v13[1].m_pointer = (survarium::loose_ptr_data *)1;
  v13[1].__vftable = (survarium::game_effect_vtbl *)(v10 + 36);
  if ( v10 != (char *)-36 )
  {
    *v14 = 0;
    if ( v22.m_object )
    {
      *v14 = v22.m_object;
      if ( v22.m_object )
        ++v22.m_object->m_reference_count;
    }
  }
  ++v13->m_reference_count;
  result->m_object = v13;
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(&v22);
  return result;
}
