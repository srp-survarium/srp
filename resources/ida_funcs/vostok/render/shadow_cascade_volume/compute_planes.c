void __thiscall vostok::render::shadow_cascade_volume::compute_planes(
        vostok::render::shadow_cascade_volume *this,
        vostok::render::shadow_cascade_volume *thisa)
{
  int *v3; // esi
  int v4; // ebp
  float x; // xmm6_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // edi
  float v11; // xmm5_4
  float v12; // xmm7_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  __int64 v16; // xmm0_8
  float v17; // [esp+18h] [ebp-2Ch]
  float v18; // [esp+1Ch] [ebp-28h]
  float v19; // [esp+20h] [ebp-24h]
  float v20; // [esp+24h] [ebp-20h]
  __int64 v21; // [esp+28h] [ebp-1Ch]
  __int64 v22; // [esp+3Ch] [ebp-8h]
  float thisb; // [esp+48h] [ebp+4h]

  v3 = &thisa->light_cuboid_polys[0].points[2];
  v4 = 4;
  do
  {
    x = thisa->light_cuboid_points[*(v3 - 2)].x;
    y = thisa->light_cuboid_points[*(v3 - 2)].y;
    z = thisa->light_cuboid_points[*(v3 - 2)].z;
    v8 = thisa->light_cuboid_points[*v3].x - x;
    v9 = thisa->light_cuboid_points[*(v3 - 1)].x - x;
    v10 = (int)&thisa->light_cuboid_points[*(v3 - 2)];
    v11 = thisa->light_cuboid_points[*(v3 - 1)].z - z;
    v12 = thisa->light_cuboid_points[*v3].z - z;
    v13 = thisa->light_cuboid_points[*(v3 - 1)].y - y;
    v17 = x;
    v14 = thisa->light_cuboid_points[*v3].y - y;
    v20 = (float)(v8 * v13) - (float)(v9 * v14);
    v18 = (float)(v14 * v11) - (float)(v12 * v13);
    v19 = (float)(v9 * v12) - (float)(v8 * v11);
    thisb = sqrtf((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v18 * v18));
    *(float *)&v21 = (float)(*(float *)&clear_value / thisb) * v18;
    v15 = (float)((float)(v17 * *(float *)&v21)
                + (float)(*(float *)(v10 + 4) * (float)((float)(*(float *)&clear_value / thisb) * v19)))
        + (float)((float)((float)(*(float *)&clear_value / thisb) * v20) * *(float *)(v10 + 8));
    *((float *)&v21 + 1) = (float)(*(float *)&clear_value / thisb) * v19;
    *(float *)&v22 = (float)(*(float *)&clear_value / thisb) * v20;
    *((float *)&v22 + 1) = -v15;
    v16 = v22;
    *((_QWORD *)v3 + 1) = v21;
    *((_QWORD *)v3 + 2) = v16;
    v3 += 8;
    --v4;
  }
  while ( v4 );
}
