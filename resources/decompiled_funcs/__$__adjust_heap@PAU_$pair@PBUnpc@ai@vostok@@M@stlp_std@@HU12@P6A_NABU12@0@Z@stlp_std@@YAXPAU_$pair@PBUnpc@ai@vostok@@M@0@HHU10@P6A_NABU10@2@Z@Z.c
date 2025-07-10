void __cdecl stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        int __holeIndex,
        int __len,
        stlp_std::pair<vostok::ai::npc const *,float> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  float second; // eax
  float v6; // eax
  float v7; // edx
  int v8; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::npc const *,float> v9; // [esp+8h] [ebp-1Ch] BYREF
  int i; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *v11; // [esp+14h] [ebp-10h]
  int __secondChild; // [esp+1Ch] [ebp-8h]
  int __topIndex; // [esp+20h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    second = __first[__secondChild].second;
    __first[__holeIndex].first = __first[__secondChild].first;
    __first[__holeIndex].second = second;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v6 = __first[__secondChild - 1].second;
    __first[__holeIndex].first = __first[__secondChild - 1].first;
    __first[__holeIndex].second = v6;
    __holeIndex = __secondChild - 1;
  }
  v11 = &v9;
  v9 = __val;
  v8 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v8 > __topIndex && __comp(&__first[i], &v9); i = (i - 1) / 2 )
  {
    v7 = __first[i].second;
    __first[v8].first = __first[i].first;
    __first[v8].second = v7;
    v8 = i;
  }
  __first[v8] = v9;
}
