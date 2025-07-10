void __cdecl stlp_std::sort<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,int,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::ai::sound_item const * *,bool (__cdecl *)(vostok::ai::sound_item const *,vostok::ai::sound_item const *)>(
      __first,
      __last,
      __comp);
  }
}
