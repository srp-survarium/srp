void __fastcall vostok::animation::mixing::n_ary_tree_deserializer::process_translation(
        vostok::animation::mixing::n_ary_tree_deserializer *this,
        vostok::math::float3 *translation)
{
  float *m_end; // eax
  float v3; // xmm0_4
  float *v4; // eax
  float v5; // xmm0_4
  float *v6; // eax
  float v7; // xmm0_4
  vostok::animation::mixing::n_ary_tree_deserializer *v8; // [esp+0h] [ebp-4h] BYREF

  v8 = this;
  m_end = this->m_floats.m_end;
  v3 = *(m_end - 1);
  _InterlockedExchange((volatile __int32 *)&v8, (__int32)m_end);
  v4 = --this->m_floats.m_end;
  translation->x = v3;
  v5 = *(v4 - 1);
  _InterlockedExchange((volatile __int32 *)&v8, (__int32)v4);
  v6 = --this->m_floats.m_end;
  translation->y = v5;
  v7 = *(v6 - 1);
  _InterlockedExchange((volatile __int32 *)&v8, (__int32)v6);
  --this->m_floats.m_end;
  translation->z = v7;
}
