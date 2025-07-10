const stlp_std::pair<vostok::math::quaternion,float> *__usercall extrapolated_slerp@<eax>(
        const stlp_std::pair<vostok::math::quaternion,float> *const begin@<eax>,
        const stlp_std::pair<vostok::math::quaternion,float> *const end,
        const stlp_std::pair<vostok::math::quaternion,float> *weight)
{
  float second; // xmm1_4
  const stlp_std::pair<vostok::math::quaternion,float> *v5; // edi
  float v6; // xmm0_4
  _QWORD v8[2]; // [esp+14h] [ebp-14h] BYREF
  float weighta; // [esp+30h] [ebp+8h]

  second = begin->second;
  *(_QWORD *)&end->first.x = *(_QWORD *)&begin->first.x;
  v5 = begin + 1;
  *(_QWORD *)&end->first.vector.elements[2] = *(_QWORD *)&begin->first.vector.elements[2];
  for ( weighta = second; v5 != weight; ++v5 )
  {
    v6 = v5->second;
    if ( v6 != 0.0 )
    {
      slerp_optimized(&end->first, &v5->first, v8, v6 / (float)(v6 + second));
      *(_QWORD *)&end->first.x = v8[0];
      *(_QWORD *)&end->first.vector.elements[2] = v8[1];
      second = v6 + weighta;
      weighta = v6 + weighta;
    }
  }
  return end;
}
