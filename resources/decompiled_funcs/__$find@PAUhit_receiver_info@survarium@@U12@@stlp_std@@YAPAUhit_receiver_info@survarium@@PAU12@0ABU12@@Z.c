survarium::hit_receiver_info *__cdecl stlp_std::find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(
        survarium::hit_receiver_info *__first,
        survarium::hit_receiver_info *__last,
        const survarium::hit_receiver_info *__val)
{
  stlp_std::random_access_iterator_tag __formal; // [esp+7h] [ebp-1h] BYREF

  return stlp_std::priv::__find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(
           __first,
           __last,
           __val,
           &__formal);
}
