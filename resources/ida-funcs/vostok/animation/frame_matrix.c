void __usercall vostok::animation::frame_matrix(
        const vostok::animation::frame *f@<eax>,
        vostok::math::float3 *scale_@<ecx>,
        vostok::math::float4x4 *matrix_)
{
  vostok::math::float3 *v3; // edi
  vostok::math::float4x4 *v4; // esi
  vostok::math::float4x4 *v5; // eax
  _BYTE v6[64]; // [esp+0h] [ebp-DCh] BYREF
  vostok::math::float4x4 v7; // [esp+40h] [ebp-9Ch] BYREF
  vostok::math::float4x4 v8; // [esp+80h] [ebp-5Ch] BYREF
  vostok::math::float3 v9; // [esp+C0h] [ebp-1Ch] BYREF
  vostok::math::float3_pod translation; // [esp+CCh] [ebp-10h] BYREF

  translation = *(vostok::math::float3_pod *)&f->channels[6];
  *scale_ = (vostok::math::float3)translation;
  v3 = scale_ + 1;
  translation = f->translation;
  v9 = *(vostok::math::float3 *)&f->channels[3];
  v4 = vostok::math::create_translation((const vostok::math::float3 *)&translation, &v7);
  v5 = vostok::math::create_rotation(&v9, (int)v3, (int)v6);
  vostok::math::mul4x3(v4, v5, &v8);
  qmemcpy(matrix_, &v8, sizeof(vostok::math::float4x4));
}
