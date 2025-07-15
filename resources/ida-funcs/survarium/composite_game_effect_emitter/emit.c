vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *__userpurge survarium::composite_game_effect_emitter::emit@<eax>(
        survarium::composite_game_effect_emitter *this@<ecx>,
        unsigned int a2@<ebx>,
        const char *a3@<edi>,
        const char *a4@<esi>,
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *result)
{
  unsigned int m_emitters_count; // esi
  void *v7; // esp
  unsigned int v8; // ebx
  survarium::pure_game_effect_emitter *m_object; // ecx
  vostok::buffer_vector<vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> > *v10; // ecx
  survarium::pure_game_effect_emitter_base *v11; // ecx
  char *v12; // ebx
  survarium::composite_game_effect *v13; // ecx
  survarium::game_effect *v14; // eax
  unsigned int v15; // esi
  survarium::game_effect **v16; // ecx
  survarium::game_effect *v17; // edx
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v18; // edi
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v20; // [esp+0h] [ebp-28h] BYREF
  float v21; // [esp+4h] [ebp-24h]
  const char *v22; // [esp+8h] [ebp-20h] BYREF
  const char *v23; // [esp+Ch] [ebp-1Ch]
  unsigned int v24; // [esp+10h] [ebp-18h]
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v25; // [esp+14h] [ebp-14h] BYREF
  const char **v26; // [esp+18h] [ebp-10h]
  const char **v27; // [esp+1Ch] [ebp-Ch]
  float m_length; // [esp+20h] [ebp-8h]
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> value; // [esp+24h] [ebp-4h] BYREF

  v24 = a2;
  v23 = a4;
  v22 = a3;
  m_emitters_count = this->m_emitters_count;
  m_length = 0.0;
  v7 = alloca(4 * m_emitters_count);
  v27 = &(&v22)[m_emitters_count];
  v8 = 0;
  v25 = (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&v22;
  v26 = &v22;
  if ( m_emitters_count )
  {
    do
    {
      m_object = this->m_emitters[v8].m_object;
      m_object->emit(m_object, &value);
      vostok::buffer_vector<vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>>::push_back(
        v10,
        (int)&v25,
        &value);
      if ( value.m_object->m_length > m_length )
        m_length = value.m_object->m_length;
      vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(&value);
      ++v8;
    }
    while ( v8 < this->m_emitters_count );
  }
  v12 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)this,
          (int)survarium::g_allocator,
          4 * this->m_emitters_count + 36,
          "composite_game_effect",
          v22,
          v23,
          v24);
  if ( v12 )
  {
    v20.m_object = v11;
    v21 = m_length;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v20,
      this);
    survarium::composite_game_effect::composite_game_effect(
      v13,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v12,
      *(const float *)&v20.m_object,
      v21);
  }
  else
  {
    v14 = 0;
  }
  v15 = 0;
  v14[1].m_pointer = (survarium::loose_ptr_data *)this->m_emitters_count;
  for ( v14[1].__vftable = (survarium::game_effect_vtbl *)(v12 + 36); v15 < this->m_emitters_count; ++v15 )
  {
    v16 = (survarium::game_effect **)(&v14[1].~survarium::game_effect + v15);
    if ( v16 )
    {
      *v16 = 0;
      v17 = v25[v15].m_object;
      if ( v17 )
      {
        *v16 = v17;
        ++v17->m_reference_count;
      }
    }
  }
  ++v14->m_reference_count;
  v18 = v25;
  result->m_object = v14;
  while ( v18 != (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)v26 )
    vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(v18++);
  return result;
}
