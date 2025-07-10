void __cdecl stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        int __holeIndex,
        int __len,
        const vostok::ai::sound_item *__val,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  int v5; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int __secondChild; // [esp+Ch] [ebp-8h]
  int __topIndex; // [esp+10h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(__first[__secondChild], __first[__secondChild - 1]) )
      --__secondChild;
    __first[__holeIndex] = __first[__secondChild];
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    __first[__holeIndex] = __first[__secondChild - 1];
    __holeIndex = __secondChild - 1;
  }
  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex && __comp(__first[i], __val); i = (i - 1) / 2 )
  {
    __first[v5] = __first[i];
    v5 = i;
  }
  __first[v5] = __val;
}
