void __usercall stlp_std::__make_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &),vostok::math::curve_point<vostok::math::float4_pod>,int>(
        vostok::math::curve_point<vostok::math::float4_pod> *__last@<eax>,
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v3; // ebp
  int v4; // ebx
  vostok::math::curve_point<vostok::math::float4_pod> *i; // esi
  vostok::math::curve_point<vostok::math::float4_pod> v6; // [esp-4Ch] [ebp-60h] BYREF
  vostok::math::curve_point<vostok::math::float4_pod> *v7; // [esp+10h] [ebp-4h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v7 = &__first[v4];
  qmemcpy(&v6, v7, sizeof(v6));
  stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
    __first,
    v4,
    v3,
    v6,
    __comp);
  if ( v4 )
  {
    for ( i = v7; ; i = v7 )
    {
      --v4;
      v7 = i - 1;
      qmemcpy(&v6, &i[-1], sizeof(v6));
      stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        v4,
        v3,
        v6,
        __comp);
      if ( !v4 )
        break;
    }
  }
}
