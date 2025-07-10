void __usercall stlp_std::priv::__ufill<stlp_std::pair<unsigned int,vostok::math::float4x4> *,stlp_std::pair<unsigned int,vostok::math::float4x4>,int>(
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__last@<eax>,
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__first,
        const stlp_std::pair<unsigned int,vostok::math::float4x4> *__x)
{
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v3; // ebx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    if ( v3 )
    {
      v3->first = __x->first;
      qmemcpy((void *)&v3->second, &__x->second, sizeof(v3->second));
    }
    --i;
  }
}
