survarium::bullet **__cdecl stlp_std::find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
        survarium::bullet **__first,
        survarium::bullet **__last,
        survarium::redundant_bullet_predicate __pred)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+5Bh] [ebp-1h] BYREF

  return stlp_std::priv::__find_if<survarium::bullet * *,survarium::redundant_bullet_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}
