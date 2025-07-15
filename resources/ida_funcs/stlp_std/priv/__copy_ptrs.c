unsigned __int8 *__usercall stlp_std::priv::__copy_ptrs<unsigned int *,unsigned int *>@<eax>(
        char *__last@<ecx>,
        unsigned __int8 *__result@<eax>,
        unsigned int *__first)
{
  unsigned int v3; // ecx
  unsigned int v4; // esi
  int v5; // eax

  v3 = __last - (char *)__first;
  v4 = v3;
  if ( v3 )
  {
    memmove(__result, (unsigned __int8 *)__first, v3);
    return (unsigned __int8 *)(v4 + v5);
  }
  return __result;
}


void **__cdecl stlp_std::priv::__copy_ptrs<void * *,void * *>(void **__first, void **__last, void **__result)
{
  return (void **)stlp_std::priv::__copy_trivial(
                    (unsigned __int8 *)__first,
                    (unsigned __int8 *)__last,
                    (unsigned __int8 *)__result);
}


vostok::ai::planning::pddl_world_state_property_impl *__cdecl stlp_std::priv::__copy_ptrs<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
        vostok::ai::planning::pddl_world_state_property_impl *__first,
        vostok::ai::planning::pddl_world_state_property_impl *__last,
        vostok::ai::planning::pddl_world_state_property_impl *__result)
{
  stlp_std::random_access_iterator_tag v4; // [esp+1Fh] [ebp-1h] BYREF

  return stlp_std::priv::__copy<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *,int>(
           __first,
           __last,
           __result,
           &v4,
           0);
}
