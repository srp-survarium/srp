void __cdecl stlp_std::make_heap<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  int __holeIndex; // [esp+0h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}
