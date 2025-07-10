void __userpurge vostok::render::debug::renderer::draw_arrow(
        const vostok::math::float3 *start_point@<eax>,
        const vostok::math::color *line_color@<ecx>,
        bool a3@<dil>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::float3 *end_point,
        const vostok::math::color *cone_color,
        bool use_depth)
{
  unsigned int v9; // xmm1_4
  unsigned int v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  vostok::math::float4x4 *v14; // edi
  vostok::math::float4x4 *rotation_x; // eax
  vostok::math::float4x4 *rotation_y; // edi
  vostok::math::float4x4 *v17; // eax
  __int64 v18; // xmm0_8
  float v20; // [esp+448h] [ebp-F0h]
  float v21; // [esp+448h] [ebp-F0h]
  vostok::math::float3 v22; // [esp+44Ch] [ebp-ECh] BYREF
  float v23; // [esp+458h] [ebp-E0h]
  float v24; // [esp+45Ch] [ebp-DCh]
  vostok::math::float3 normal; // [esp+460h] [ebp-D8h] BYREF
  vostok::math::float3 size; // [esp+46Ch] [ebp-CCh] BYREF
  vostok::math::float4x4 v27; // [esp+478h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+4B8h] [ebp-80h] BYREF
  _QWORD v29[8]; // [esp+4F8h] [ebp-40h] BYREF

  *(float *)&v9 = end_point->y - start_point->y;
  *(float *)&v10 = end_point->x - start_point->x;
  v22.z = end_point->z - start_point->z;
  *(_QWORD *)&v22.x = __PAIR64__(v9, v10);
  if ( fabs(
         (float)((float)(v22.z * v22.z) + (float)(*(float *)&v9 * *(float *)&v9))
       + (float)(*(float *)&v10 * *(float *)&v10)) >= 0.001 )
  {
    vostok::render::debug::renderer::draw_line(start_point, end_point, this, scene, line_color, 1);
    v11 = start_point->z - end_point->z;
    v12 = start_point->y - end_point->y;
    v20 = sqrtf(
            (float)((float)(v11 * v11) + (float)(v12 * v12))
          + (float)((float)(start_point->x - end_point->x) * (float)(start_point->x - end_point->x)));
    size.x = (float)(v20 * 0.050000001) * 0.5;
    size.z = size.x;
    size.y = v20 * 0.050000001;
    v13 = (float)(*(float *)&clear_value / v20) * v22.x;
    v22.y = v22.y * (float)(*(float *)&clear_value / v20);
    *(_QWORD *)&normal.elements[1] = (unsigned int)clear_value;
    v22.z = v22.z * (float)(*(float *)&clear_value / v20);
    v23 = v22.z * 0.0;
    v24 = v13 * 0.0;
    v22.x = v13;
    normal.x = 0.0;
    v21 = sqrtf(
            (float)((float)((float)((float)(v22.y * 0.0) - v13) * (float)((float)(v22.y * 0.0) - v13))
                  + (float)((float)((float)(v13 * 0.0) - (float)(v22.z * 0.0))
                          * (float)((float)(v13 * 0.0) - (float)(v22.z * 0.0))))
          + (float)((float)(v22.z - (float)(v22.y * 0.0)) * (float)(v22.z - (float)(v22.y * 0.0))));
    if ( COERCE_FLOAT(LODWORD(v21) & 0x7FFFFFFF) < 0.0000099999997 )
    {
      if ( (float)((float)(v23 + v24) + v22.y) > 0.0 )
      {
        qmemcpy(
          (void *)&v27,
          vostok::math::create_rotation_y(v29, COERCE_VOSTOK_MATH_FLOAT4X4_(1.5707964)),
          sizeof(v27));
LABEL_8:
        v18 = *(_QWORD *)&end_point->x;
        v27.c.z = end_point->z;
        *(_QWORD *)&v27.lines[3].x = v18;
        vostok::render::debug::renderer::draw_cone(&v27, &size, this, scene, cone_color, a3);
        return;
      }
      rotation_y = vostok::math::create_rotation_y(v29, COERCE_VOSTOK_MATH_FLOAT4X4_(-1.5707964));
      v17 = vostok::math::create_rotation_x(&v27, COERCE_VOSTOK_MATH_FLOAT4X4_(-3.1415927));
      vostok::math::mul4x3(&result, v17, rotation_y);
    }
    else
    {
      v14 = vostok::math::create_rotation(&v22, &normal, &v27);
      rotation_x = vostok::math::create_rotation_x(v29, COERCE_VOSTOK_MATH_FLOAT4X4_(-1.5707964));
      vostok::math::mul4x3(&result, rotation_x, v14);
    }
    v27.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&result);
    v27.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&result.lines[1]);
    v27.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&result.lines[2]);
    v27.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&result.lines[3]);
    goto LABEL_8;
  }
}
