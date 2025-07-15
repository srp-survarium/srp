void __thiscall vostok::render::scene::update_lpv_occluder(
        vostok::render::scene *this,
        vostok::render::scene *id,
        const vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *transforma)
{
  const vostok::math::float4x4 *v4; // esi
  stlp_std::pair<unsigned int,vostok::math::float4x4> *M_finish; // edi
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v6; // eax
  _BYTE v7[8]; // [esp+10h] [ebp-4Ch] BYREF
  stlp_std::pair<unsigned int,vostok::math::float4x4> value; // [esp+18h] [ebp-44h] BYREF

  v4 = transform;
  M_finish = id->m_lpv_occluders._M_impl._M_finish;
  v6 = stlp_std::priv::__lower_bound<stlp_std::pair<unsigned int,vostok::math::float4x4> *,unsigned int,associative_vector_compare_predicate<unsigned int,vostok::math::float4x4,stlp_std::less<unsigned int>>,associative_vector_compare_predicate<unsigned int,vostok::math::float4x4,stlp_std::less<unsigned int>>,int>(
         id->m_lpv_occluders._M_impl._M_start,
         M_finish,
         (unsigned int *)&transform);
  if ( v6 == M_finish || (unsigned int)v4 < v6->first )
    v6 = M_finish;
  if ( v6 == id->m_lpv_occluders._M_impl._M_finish )
  {
    value.first = (unsigned int)v4;
    qmemcpy((void *)&value.second, transforma, sizeof(value.second));
    associative_vector<unsigned int,vostok::math::float4x4,vostok::render::vector,stlp_std::less<unsigned int>>::insert(
      &id->m_lpv_occluders,
      &value,
      (int *)id,
      (int)v7);
  }
  else
  {
    qmemcpy((void *)&v6->second, transforma, sizeof(v6->second));
  }
}
