vostok::math::float3 *__usercall mix_scales@<eax>(
        const vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *transforms@<eax>,
        float *a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  stlp_std::pair<vostok::math::float3,float> *m_end; // ebx
  stlp_std::pair<vostok::math::float3,float> *m_begin; // edi
  long double v5; // st7
  float _Y; // [esp+14h] [ebp-10h]
  float v8; // [esp+18h] [ebp-Ch]
  float v9; // [esp+1Ch] [ebp-8h]

  v2 = clear_value;
  m_end = transforms->m_end;
  m_begin = transforms->m_begin;
  *(_DWORD *)a2 = clear_value;
  *((_DWORD *)a2 + 1) = v2;
  for ( *((_DWORD *)a2 + 2) = v2; m_begin != m_end; a2[2] = v5 * a2[2] )
  {
    _Y = m_begin->second;
    v8 = powf(m_begin->first.x, _Y);
    v9 = powf(m_begin->first.y, _Y);
    v5 = powf(m_begin->first.z, _Y);
    ++m_begin;
    *a2 = *a2 * v8;
    a2[1] = a2[1] * v9;
  }
  return (vostok::math::float3 *)a2;
}
