void __thiscall vostok::ai::fsm::append_transition(
        vostok::ai::fsm *this,
        vostok::ai::fsm_state *from,
        vostok::ai::fsm_state *to,
        boost::function<bool __cdecl(void)> *transition_predicate)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  char *v8; // edi
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]

  v4 = vostok::ai::g_allocator;
  v5 = type_info::raw_name(&vostok::ai::fsm_state_transition `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x28u, v5, v9, v10, v11);
  if ( v7 )
  {
    *(_DWORD *)v7 = 0;
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  boost::function<bool __cdecl (void)>::operator=(
    transition_predicate,
    (boost::function1<void,vostok::physics::contact_point const &> *)v8);
  *((_DWORD *)v8 + 8) = to;
  *((_DWORD *)v8 + 9) = 0;
  ++from->transitions.m_size;
  if ( from->transitions.m_first )
    from->transitions.m_last->next = (vostok::ai::fsm_state_transition *)v8;
  else
    from->transitions.m_first = (vostok::ai::fsm_state_transition *)v8;
  from->transitions.m_last = (vostok::ai::fsm_state_transition *)v8;
}
