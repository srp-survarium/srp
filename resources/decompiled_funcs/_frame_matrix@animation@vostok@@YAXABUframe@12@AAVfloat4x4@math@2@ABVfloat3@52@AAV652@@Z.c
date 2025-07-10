void __usercall vostok::animation::frame_matrix(
        const vostok::animation::frame *f@<eax>,
        vostok::math::float3 *scale_@<ecx>,
        vostok::math::float4x4 *matrix_)
{
  float z; // edx
  const vostok::math::float4x4 *v4; // eax
  const vostok::math::float4x4 *v5; // eax
  vostok::math::float3_pod v6; // [esp+4h] [ebp-124h]
  vostok::math::float3 angles; // [esp+10h] [ebp-118h] BYREF
  vostok::math::float3 position; // [esp+1Ch] [ebp-10Ch] BYREF
  vostok::math::float4x4 dst; // [esp+28h] [ebp-100h] BYREF
  vostok::math::float4x4 left; // [esp+68h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+A8h] [ebp-80h] BYREF
  vostok::math::float4x4 v12; // [esp+E8h] [ebp-40h] BYREF

  z = f->scale.z;
  *(_QWORD *)&scale_->x = *(_QWORD *)&f->channels[6];
  scale_->z = z;
  position = (vostok::math::float3)f->translation;
  angles = *(vostok::math::float3 *)&f->channels[3];
  v6 = *(vostok::math::float3_pod *)&f->channels[6];
  memset((unsigned __int8 *)&dst, 0, sizeof(dst));
  dst.j.y = v6.y;
  dst.i.x = v6.x;
  dst.k.z = v6.z;
  LODWORD(dst.c.w) = clear_value;
  v4 = vostok::math::create_rotation(&result, &angles);
  vostok::math::mul4x3(&left, &dst, v4);
  v5 = vostok::math::create_translation(&v12, &position);
  vostok::math::mul4x3(&dst, &left, v5);
  qmemcpy((void *)matrix_, &dst, sizeof(vostok::math::float4x4));
}
