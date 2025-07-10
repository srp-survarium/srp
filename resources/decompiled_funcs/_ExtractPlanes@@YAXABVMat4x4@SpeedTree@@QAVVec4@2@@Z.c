void __cdecl ExtractPlanes(const struct SpeedTree::Mat4x4 *a1, struct SpeedTree::Vec4 *const a2)
{
  float v2; // [esp+18h] [ebp-28h]
  float v3; // [esp+1Ch] [ebp-24h]
  SpeedTree::Vec3 v4; // [esp+24h] [ebp-1Ch] BYREF
  float v5; // [esp+30h] [ebp-10h]
  int j; // [esp+34h] [ebp-Ch]
  int v7; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    v7 = 4 * i;
    *(&a2[2].x + i) = a1->m_afSingle[4 * i + 3] - a1->m_afSingle[4 * i];
    *(&a2[3].x + i) = a1->m_afSingle[v7 + 3] + a1->m_afSingle[v7];
    *(&a2[4].x + i) = a1->m_afSingle[v7 + 3] + a1->m_afSingle[v7 + 1];
    *(&a2[5].x + i) = a1->m_afSingle[v7 + 3] - a1->m_afSingle[v7 + 1];
    *(&a2[1].x + i) = a1->m_afSingle[v7 + 3] - a1->m_afSingle[v7 + 2];
    *(&a2->x + i) = a1->m_afSingle[v7 + 3] + a1->m_afSingle[v7 + 2];
  }
  for ( j = 0; j < 6; ++j )
  {
    v4.x = a2[j].x;
    v4.y = a2[j].y;
    v4.z = a2[j].z;
    v3 = vostok::math::float3_pod::squared_length(&v4);
    v2 = sqrt(v3);
    v5 = v2;
    a2[j].x = a2[j].x / v2;
    a2[j].y = a2[j].y / v5;
    a2[j].z = a2[j].z / v5;
    a2[j].w = a2[j].w / v5;
  }
}
