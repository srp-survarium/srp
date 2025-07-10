void __cdecl stlp_std::random_shuffle<survarium::artefact_container_core * *>(
        survarium::artefact_container_core **__first,
        survarium::artefact_container_core **__last)
{
  int v2; // eax
  survarium::artefact_container_core **__i; // [esp+18h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v2 = rand();
      stlp_std::iter_swap<vostok::ai::sound_item const * *,vostok::ai::sound_item const * *>(
        (const vostok::ai::movement_target **)__i,
        (const vostok::ai::movement_target **)&__first[v2 % (__i - __first + 1)]);
    }
  }
}
