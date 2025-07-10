void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item *__val,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item **__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(__val, *__next); --__next )
  {
    *__last = *__next;
    __last = __next;
  }
  *__last = __val;
}
