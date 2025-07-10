vostok::logging::initiator_filter *__cdecl stlp_std::find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
        vostok::logging::initiator_filter *__first,
        vostok::logging::initiator_filter *__last,
        vostok::logging::filter_name_eq __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+Fh] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
           __first,
           __last,
           __pred,
           &__formal);
}
