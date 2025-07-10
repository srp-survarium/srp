void __cdecl stlp_std::priv::__partial_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__middle,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        vostok::math::curve_point<vostok::math::float4_pod> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  vostok::math::curve_point<vostok::math::float4_pod> *v5; // esi
  vostok::math::curve_point<vostok::math::float4_pod> *v6; // edi
  vostok::math::curve_point<vostok::math::float4_pod> *i; // ebx
  int v8; // edx
  vostok::math::curve_point<vostok::math::float4_pod> v9; // [esp-4Ch] [ebp-A4h] BYREF
  int __len; // [esp+Ch] [ebp-4Ch]
  _BYTE v11[72]; // [esp+10h] [ebp-48h] BYREF

  v5 = __first;
  v6 = __middle;
  __len = __middle - __first;
  if ( __len >= 2 )
    stlp_std::__make_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &),vostok::math::curve_point<vostok::math::float4_pod>,int>(
      __first,
      __middle,
      __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( __comp(i, v5) )
    {
      v8 = __len;
      qmemcpy(v11, i, sizeof(v11));
      qmemcpy(i, __first, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
      qmemcpy(&v9, v11, sizeof(v9));
      stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        0,
        v8,
        v9,
        __comp);
      v6 = __middle;
      v5 = __first;
    }
  }
  stlp_std::sort_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
    v5,
    v6,
    __comp);
}
