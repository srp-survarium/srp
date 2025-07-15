vostok::math::quaternion *__cdecl vostok::math::weighted_blend(
        vostok::math::quaternion *result,
        const stlp_std::pair<vostok::math::quaternion,float> *begin,
        const stlp_std::pair<vostok::math::quaternion,float> *end)
{
  const stlp_std::pair<vostok::math::quaternion,float> *v3; // ebx
  float second; // xmm0_4
  float v5; // xmm0_4
  vostok::math::quaternion resulta; // [esp+10h] [ebp-10h] BYREF
  float v8; // [esp+2Ch] [ebp+Ch]

  v3 = begin;
  *result = begin->first;
  second = begin->second;
LABEL_4:
  v8 = second;
  while ( 1 )
  {
    if ( ++v3 == end )
      return result;
    v5 = v3->second;
    if ( v5 != 0.0 )
    {
      *result = *vostok::math::slerp(&resulta, result, &v3->first, v5 / (float)(v5 + v8));
      second = v3->second + v8;
      goto LABEL_4;
    }
  }
}
