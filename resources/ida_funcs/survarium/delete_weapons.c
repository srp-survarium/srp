void __cdecl survarium::delete_weapons(
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *owner)
{
  survarium::human_npc::npc_game_attributes *p_m_game_attributes; // esi
  survarium::object_weapon *m_first; // edi
  survarium::object_weapon *m_next; // eax
  int f; // ebx
  _BYTE *v5; // esi
  void *v6; // eax
  void *v7; // esi

  while ( 1 )
  {
    p_m_game_attributes = &owner->m_object->m_game_attributes;
    if ( !owner->m_object->m_game_attributes.weapons.m_first )
      break;
    vostok::threading::mutex::lock(&owner->m_object->m_game_attributes.weapons.vostok::threading::mutex);
    if ( !p_m_game_attributes->weapons.m_first )
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)&p_m_game_attributes->weapons.vostok::threading::mutex);
      return;
    }
    m_first = p_m_game_attributes->weapons.m_first;
    --p_m_game_attributes->weapons.m_size;
    m_next = m_first->m_next;
    p_m_game_attributes->weapons.m_first = m_next;
    if ( !m_next )
      p_m_game_attributes->weapons.m_last = 0;
    m_first->m_next = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&p_m_game_attributes->weapons.vostok::threading::mutex);
    f = (int)survarium::g_allocator.f_.f_;
    v5 = __RTCastToVoid((void **)&m_first->vostok::ai::weapon::__vftable);
    ((void (__thiscall *)(survarium::object_weapon *, _DWORD))m_first->~survarium::object_weapon)(m_first, 0);
    if ( v5 )
    {
      v6 = v5;
      v7 = *(void **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v7, v6);
    }
  }
}
