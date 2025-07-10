vostok::sound::unique_propagator_info *__cdecl stlp_std::find_if<vostok::sound::unique_propagator_info *,vostok::sound::compare_by_propagator>(
        vostok::sound::unique_propagator_info *__first,
        vostok::sound::unique_propagator_info *__last,
        vostok::sound::compare_by_propagator __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::sound::unique_propagator_info *,vostok::sound::compare_by_propagator>(
           __first,
           __last,
           __pred,
           &__formal);
}
