void __thiscall survarium::project_cooker_simple::delete_resource(
        survarium::project_cooker_simple *this,
        survarium::game_effect *resource)
{
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *p_m_emitter; // ebx
  survarium::collision_geometry *m_object; // edi
  void **p_cast_to_hit_receiver; // esi
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  void ***p_m_inlined_in_fat; // edi
  char *v9; // esi
  vostok::memory::doug_lea_allocator *v10; // ecx
  const char *v11; // [esp+0h] [ebp-18h]
  const char *v12; // [esp+4h] [ebp-14h]
  unsigned int v13; // [esp+8h] [ebp-10h]
  survarium::collision_geometry *pointer; // [esp+Ch] [ebp-Ch] BYREF
  vostok::memory::doug_lea_allocator *v15; // [esp+10h] [ebp-8h]
  char *v16; // [esp+14h] [ebp-4h]

  if ( resource )
    p_m_emitter = &resource[-2].m_emitter;
  else
    p_m_emitter = 0;
  m_object = (survarium::collision_geometry *)p_m_emitter[93].m_object;
  for ( pointer = (survarium::collision_geometry *)p_m_emitter[94].m_object;
        m_object != pointer;
        m_object = (survarium::collision_geometry *)((char *)m_object + 4) )
  {
    p_cast_to_hit_receiver = (void **)&m_object->cast_to_hit_receiver;
    v15 = survarium::g_allocator;
    if ( p_cast_to_hit_receiver )
    {
      v16 = __RTCastToVoid(p_cast_to_hit_receiver);
      (*(void (__thiscall **)(void **, _DWORD))*p_cast_to_hit_receiver)(p_cast_to_hit_receiver, 0);
      vostok::memory::doug_lea_allocator::free_impl(v5, (int)v15, v16, v11, v12, v13);
    }
  }
  v6 = (vostok::memory::doug_lea_allocator *)p_m_emitter[96].m_object;
  v7 = (char *)p_m_emitter[97].m_object;
  v15 = v6;
  v16 = v7;
  while ( p_m_emitter[105].m_object != p_m_emitter[106].m_object )
  {
    p_m_inlined_in_fat = (void ***)&p_m_emitter[106].m_object[-1].m_inlined_in_fat;
    pointer = (survarium::collision_geometry *)survarium::g_allocator;
    if ( *p_m_inlined_in_fat )
    {
      v9 = __RTCastToVoid(*p_m_inlined_in_fat);
      (*(void (__thiscall **)(void **, _DWORD))**p_m_inlined_in_fat)(*p_m_inlined_in_fat, 0);
      vostok::memory::doug_lea_allocator::free_impl(v10, (int)pointer, v9, v11, v12, v13);
      *p_m_inlined_in_fat = 0;
      v6 = v15;
    }
    p_m_emitter[106].m_object = (survarium::pure_game_effect_emitter_base *)((char *)p_m_emitter[106].m_object - 4);
  }
  while ( v6 != (vostok::memory::doug_lea_allocator *)v16 )
  {
    pointer = (survarium::collision_geometry *)v6->__vftable;
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
      survarium::g_allocator,
      &pointer,
      v11,
      v12,
      v13);
    v6 = (vostok::memory::doug_lea_allocator *)((char *)v6 + 4);
  }
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::base_network_client>(
    survarium::g_allocator,
    &resource,
    v11,
    v12,
    v13);
}
