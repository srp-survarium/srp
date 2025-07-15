vostok::math::float3 *__usercall vostok::math::create_camera_at@<eax>(
        const vostok::math::float3 *from@<ecx>,
        const vostok::math::float3 *at@<eax>,
        vostok::math::float3 *up,
        const vostok::math::float3 *upa)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  vostok::math::float3 view; // [esp+Ch] [ebp-Ch] BYREF
  float v10; // [esp+1Ch] [ebp+4h]

  v6 = at->x - from->x;
  v7 = at->y - from->y;
  view.z = at->z - from->z;
  v10 = 1.0 / sqrtf((float)((float)(view.z * view.z) + (float)(v6 * v6)) + (float)(v7 * v7));
  view.x = v10 * v6;
  view.y = v10 * v7;
  view.z = v10 * view.z;
  vostok::math::create_camera_direction(&view, upa, up, from);
  return up;
}
