void __cdecl stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        int __holeIndex,
        int __len,
        vostok::sound::propagator_info __val,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info *v5; // edx
  vostok::sound::propagator_info *v6; // eax
  vostok::sound::propagator_info *v7; // ecx
  vostok::sound::propagator_info *v8; // edx
  vostok::sound::propagator_info *v9; // ecx
  vostok::sound::propagator_info *v10; // edx
  vostok::sound::propagator_info v11; // [esp+0h] [ebp-24h] BYREF
  int v12; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int __secondChild; // [esp+1Ch] [ebp-8h]
  int __topIndex; // [esp+20h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    v5 = &__first[__secondChild];
    v6 = &__first[__holeIndex];
    v6->in_graph_position.x = v5->in_graph_position.x;
    v6->in_graph_position.y = v5->in_graph_position.y;
    v6->in_graph_position.z = v5->in_graph_position.z;
    v6->distance_to_listener = v5->distance_to_listener;
    v6->prop = v5->prop;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v7 = &__first[__secondChild - 1];
    v8 = &__first[__holeIndex];
    v8->in_graph_position.x = v7->in_graph_position.x;
    v8->in_graph_position.y = v7->in_graph_position.y;
    v8->in_graph_position.z = v7->in_graph_position.z;
    v8->distance_to_listener = v7->distance_to_listener;
    v8->prop = v7->prop;
    __holeIndex = __secondChild - 1;
  }
  v11 = __val;
  v12 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v12 > __topIndex && __comp(&__first[i], &v11); i = (i - 1) / 2 )
  {
    v9 = &__first[i];
    v10 = &__first[v12];
    v10->in_graph_position.x = v9->in_graph_position.x;
    v10->in_graph_position.y = v9->in_graph_position.y;
    v10->in_graph_position.z = v9->in_graph_position.z;
    v10->distance_to_listener = v9->distance_to_listener;
    v10->prop = v9->prop;
    v12 = i;
  }
  __first[v12] = v11;
}
