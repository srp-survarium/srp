vostok::animation::frame *__usercall identity_frame@<eax>(vostok::animation::frame *a1@<eax>)
{
  const vostok::math::float4x4 *v1; // xmm0_4
  __int64 v2; // [esp+0h] [ebp-Ch]

  *(_QWORD *)&a1->channels[3] = 0;
  v1 = clear_value;
  *(_QWORD *)&a1->translation.x = 0;
  a1->translation.z = 0.0;
  LODWORD(v2) = v1;
  HIDWORD(v2) = v1;
  *(_QWORD *)&a1->channels[6] = v2;
  a1->rotation.z = 0.0;
  LODWORD(a1->scale.z) = v1;
  return a1;
}
