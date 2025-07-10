void __cdecl stlp_std::pop_heap<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item *__val; // [esp+0h] [ebp-4h]

  __val = *(__last - 1);
  *(__last - 1) = *__first;
  stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
    __first,
    0,
    __last - 1 - __first,
    __val,
    __comp);
}
