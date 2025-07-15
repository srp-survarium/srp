void __userpurge survarium::base_player::set_transform(
        survarium::base_player *this@<ecx>,
        long double a2@<esi:edi>,
        __m128i a3@<xmm0>,
        const vostok::math::float3 *position,
        const vostok::math::float3 *orientation,
        float look_pitch,
        int a6)
{
  vostok::math::float4x4 *v7; // eax
  vostok::math::float4x4 v8; // [esp+14h] [ebp-C0h] BYREF
  vostok::math::float4x4 v9; // [esp+54h] [ebp-80h] BYREF
  vostok::math::float4x4 v10; // [esp+94h] [ebp-40h] BYREF

  HIDWORD(a2) = vostok::math::create_translation(orientation, &v9);
  v7 = vostok::math::create_rotation_y(a2, a3, &v10, look_pitch);
  vostok::math::mul4x3((const vostok::math::float4x4 *)HIDWORD(a2), v7, &v8);
  *(float *)((char *)&dword_10E70 + (_DWORD)position) = look_pitch;
  qmemcpy(&byte_10E2C[(_DWORD)position], &v8, 0x40u);
  *(int *)((char *)&dword_10E6C + (_DWORD)position) = a6;
  *(const vostok::math::float3 *)((char *)position + (_DWORD)&loc_1110F + 1) = *orientation;
}
