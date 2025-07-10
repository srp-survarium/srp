void __thiscall vostok::sound::sound_scene::update_receivers_position(vostok::sound::sound_scene *this)
{
  const vostok::math::float4x4 *v1; // eax
  const vostok::math::float4x4 *v2; // eax
  vostok::collision::object *v4; // [esp+Ch] [ebp-1DCh]
  vostok::math::float3 *v5; // [esp+18h] [ebp-1D0h]
  unsigned __int8 dst[64]; // [esp+1Ch] [ebp-1CCh] BYREF
  vostok::collision::object *m_collision; // [esp+70h] [ebp-178h]
  char v8; // [esp+77h] [ebp-171h]
  vostok::math::half3_pod *p_m_val; // [esp+F8h] [ebp-F0h]
  vostok::math::float3 result; // [esp+FCh] [ebp-ECh] BYREF
  char v11; // [esp+10Bh] [ebp-DDh]
  vostok::math::float4x4 v12; // [esp+10Ch] [ebp-DCh] BYREF
  vostok::math::float4x4 left; // [esp+14Ch] [ebp-9Ch] BYREF
  vostok::math::float3 v14; // [esp+18Ch] [ebp-5Ch] BYREF
  vostok::math::float4x4 v15; // [esp+198h] [ebp-50h] BYREF
  vostok::math::float3 position; // [esp+1D8h] [ebp-10h] BYREF
  vostok::sound::receiver_collision *rc; // [esp+1E4h] [ebp-4h]

  for ( rc = this->m_receivers.m_first; rc; rc = rc->m_next )
  {
    v11 = 0;
    p_m_val = &rc->m_position->m_data.m_val;
    vostok::math::half3_pod::operator vostok::math::float3(p_m_val, &result);
    position = result;
    v8 = 0;
    m_collision = rc->m_collision;
    v5 = vostok::math::aabb::extents(&m_collision->m_aabb, &v14);
    memset(dst, 0, sizeof(dst));
    *(float *)dst = v5->x;
    *(float *)&dst[20] = v5->y;
    *(float *)&dst[40] = v5->z;
    *(float *)&dst[60] = FLOAT_1_0;
    qmemcpy((void *)&left, dst, sizeof(left));
    v4 = rc->m_collision;
    v1 = vostok::math::create_translation(&v15, &position);
    v2 = vostok::math::operator*(&v12, &left, v1);
    this->m_spatial_tree->move(this->m_spatial_tree, v4, v2);
  }
}
