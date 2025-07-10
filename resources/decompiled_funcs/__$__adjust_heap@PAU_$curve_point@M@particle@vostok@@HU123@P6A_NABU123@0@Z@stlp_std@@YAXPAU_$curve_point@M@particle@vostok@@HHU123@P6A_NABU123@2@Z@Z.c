void __cdecl stlp_std::__adjust_heap<vostok::particle::curve_point<float> *,int,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        int __holeIndex,
        int __len,
        vostok::particle::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> *v5; // edx
  vostok::particle::curve_point<float> *v6; // eax
  vostok::particle::curve_point<float> *v7; // ecx
  vostok::particle::curve_point<float> *v8; // edx
  vostok::particle::curve_point<float> *v9; // edx
  vostok::particle::curve_point<float> *v10; // eax
  vostok::particle::curve_point<float> v11; // [esp+0h] [ebp-28h] BYREF
  int v12; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int __secondChild; // [esp+20h] [ebp-8h]
  int __topIndex; // [esp+24h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    v5 = &__first[__secondChild];
    v6 = &__first[__holeIndex];
    v6->upper_value = v5->upper_value;
    v6->lower_value = v5->lower_value;
    v6->tangent_in = v5->tangent_in;
    v6->tangent_out = v5->tangent_out;
    v6->time = v5->time;
    v6->interp_type = v5->interp_type;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v7 = &__first[__secondChild - 1];
    v8 = &__first[__holeIndex];
    v8->upper_value = v7->upper_value;
    v8->lower_value = v7->lower_value;
    v8->tangent_in = v7->tangent_in;
    v8->tangent_out = v7->tangent_out;
    v8->time = v7->time;
    v8->interp_type = v7->interp_type;
    __holeIndex = __secondChild - 1;
  }
  v11 = __val;
  v12 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v12 > __topIndex && __comp(&__first[i], &v11); i = (i - 1) / 2 )
  {
    v9 = &__first[i];
    v10 = &__first[v12];
    v10->upper_value = v9->upper_value;
    v10->lower_value = v9->lower_value;
    v10->tangent_in = v9->tangent_in;
    v10->tangent_out = v9->tangent_out;
    v10->time = v9->time;
    v10->interp_type = v9->interp_type;
    v12 = i;
  }
  __first[v12] = v11;
}
