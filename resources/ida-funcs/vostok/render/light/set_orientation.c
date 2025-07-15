void __thiscall vostok::render::light::set_orientation(
        vostok::render::light *this,
        vostok::render::light *direction,
        const vostok::math::float3 *right)
{
  vostok::math::float3 *v3; // eax
  const vostok::math::float4x4 *v4; // xmm0_4
  vostok::math::float3_pod result_in_case_of_zero; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 v6; // [esp+Ch] [ebp-Ch] BYREF

  LODWORD(result_in_case_of_zero.x) = clear_value;
  LODWORD(result_in_case_of_zero.y) = clear_value;
  LODWORD(result_in_case_of_zero.z) = clear_value;
  v3 = vostok::math::normalize_safe(
         (const vostok::math::float3_pod *)this,
         &v6,
         (vostok::math::float3 *)&result_in_case_of_zero);
  *(_QWORD *)&direction->direction.x = *(_QWORD *)&v3->x;
  v4 = clear_value;
  direction->direction.z = v3->z;
  LODWORD(result_in_case_of_zero.x) = v4;
  LODWORD(result_in_case_of_zero.y) = v4;
  LODWORD(result_in_case_of_zero.z) = v4;
  direction->right = *vostok::math::normalize_safe(right, &v6, (vostok::math::float3 *)&result_in_case_of_zero);
}
