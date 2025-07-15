vostok::ai::planning::generalized_action *__thiscall vostok::ai::planning::generalized_action::clone(
        vostok::ai::planning::generalized_action *this,
        int a2)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  vostok::ai::planning::generalized_action *v7; // eax
  vostok::ai::planning::generalized_action *v8; // esi
  vostok::buffer_vector<vostok::ai::planning::generalized_action *> *v9; // ecx
  const char *v11; // [esp+0h] [ebp-10h]
  const char *v12; // [esp+4h] [ebp-Ch]
  unsigned int v13; // [esp+8h] [ebp-8h]
  vostok::ai::planning::generalized_action *value; // [esp+Ch] [ebp-4h] BYREF

  while ( *(_DWORD *)(a2 + 132) )
    a2 = *(_DWORD *)(a2 + 132);
  v3 = vostok::ai::g_allocator;
  v4 = type_info::raw_name(&vostok::ai::planning::generalized_action `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0xC0u, v4, v11, v12, v13);
  if ( v6 )
  {
    vostok::ai::planning::generalized_action::generalized_action(
      *(vostok::ai::planning::generalized_action **)(a2 + 136),
      (int)v6,
      *(const vostok::ai::planning::pddl_domain **)(a2 + 188),
      *(_DWORD *)(a2 + 180),
      *(char **)(a2 + 136),
      *(_DWORD *)(a2 + 184));
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  value = v8;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::operator=(
    &v8->m_effects._M_impl,
    (const stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *)(a2 + 16));
  v8->m_parent = (vostok::ai::planning::generalized_action *)a2;
  vostok::buffer_vector<vostok::ai::planning::generalized_action *>::push_back(v9, a2 + 56, &value);
  return value;
}
