void __usercall stlp_std::priv::__fill<stlp_std::pair<unsigned int,vostok::math::float4x4> *,stlp_std::pair<unsigned int,vostok::math::float4x4>,int>(
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__last@<eax>,
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__first,
        const stlp_std::pair<unsigned int,vostok::math::float4x4> *__val)
{
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v3; // ebx
  int i; // eax
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(stlp_std::pair<unsigned int,vostok::math::float4x4>));
  }
}
