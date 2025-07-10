const vostok::fixed_string<16> *__cdecl stlp_std::find_if<vostok::fixed_string<16> const *,survarium::compare_body_parts_predicate>(
        const vostok::fixed_string<16> *__first,
        const vostok::fixed_string<16> *__last,
        survarium::compare_body_parts_predicate __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+17h] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<vostok::fixed_string<16> const *,survarium::compare_body_parts_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}
