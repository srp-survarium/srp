vostok::math::float4x4 *__cdecl vostok::math::create_translation(
        vostok::math::float4x4 *result,
        const vostok::math::float3 *position)
{
  vostok::math::float4x4 *v2; // eax
  const vostok::math::float4x4 *v3; // xmm1_4
  __int64 v4; // xmm2_8
  __int64 v5; // xmm2_8
  __int64 v6; // xmm0_8
  __int128 v7; // [esp+0h] [ebp-10h]

  v2 = result;
  v3 = clear_value;
  *((_QWORD *)&v7 + 1) = 0;
  LODWORD(v7) = 0;
  *(_QWORD *)&result->i.x = (unsigned int)clear_value;
  v4 = *((_QWORD *)&v7 + 1);
  *((_QWORD *)&v7 + 1) = 0;
  DWORD1(v7) = v3;
  *(_QWORD *)&result->lines[0].elements[2] = v4;
  *(_QWORD *)&result->lines[1].x = v7;
  v5 = *((_QWORD *)&v7 + 1);
  HIDWORD(v7) = 0;
  *(_QWORD *)&result->lines[2].x = 0;
  DWORD2(v7) = v3;
  *(_QWORD *)&result->lines[2].elements[2] = *((_QWORD *)&v7 + 1);
  *(vostok::math::float3 *)&v7 = *position;
  *(_QWORD *)&result->lines[3].x = v7;
  HIDWORD(v7) = v3;
  v6 = *((_QWORD *)&v7 + 1);
  *(_QWORD *)&result->lines[1].elements[2] = v5;
  *(_QWORD *)&result->lines[3].elements[2] = v6;
  return v2;
}
