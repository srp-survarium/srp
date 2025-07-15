vostok::math::float3 *__usercall mix_translations@<eax>(
        const vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *transforms@<edx>,
        vostok::math::float3 *result@<eax>)
{
  stlp_std::pair<vostok::math::float3,float> *m_begin; // ecx
  stlp_std::pair<vostok::math::float3,float> *m_end; // edx
  float x; // [esp+0h] [ebp-1Ch]
  float v5; // [esp+0h] [ebp-1Ch]
  float y; // [esp+4h] [ebp-18h]
  float v7; // [esp+4h] [ebp-18h]
  float z; // [esp+8h] [ebp-14h]
  float v9; // [esp+8h] [ebp-14h]
  vostok::math::float3 v10; // [esp+Ch] [ebp-10h] BYREF
  float second; // [esp+18h] [ebp-4h]

  m_begin = transforms->m_begin;
  m_end = transforms->m_end;
  memset(&v10, 0, sizeof(v10));
  for ( ; m_begin != m_end; v10.z = v10.z + v9 )
  {
    x = m_begin->first.x;
    y = m_begin->first.y;
    z = m_begin->first.z;
    second = m_begin->second;
    ++m_begin;
    v5 = x * second;
    v7 = y * second;
    v9 = z * second;
    v10.x = v10.x + v5;
    v10.y = v10.y + v7;
  }
  *result = v10;
  return result;
}
