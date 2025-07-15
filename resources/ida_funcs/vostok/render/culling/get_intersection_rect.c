vostok::render::culling::aab_rect *__fastcall vostok::render::culling::get_intersection_rect(
        const vostok::render::culling::aab_rect *right,
        const vostok::render::culling::aab_rect *left,
        int a3)
{
  vostok::render::culling::aab_rect *result; // eax
  const vostok::render::culling::aab_rect *v4; // esi
  double x; // st7
  float *p_y; // esi
  vostok::math::float2 *p_max; // esi
  float *v8; // edx
  float *v9; // ecx

  result = (vostok::render::culling::aab_rect *)a3;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 12) = 0;
  v4 = right;
  if ( right->min.x <= left->min.x )
    v4 = left;
  x = v4->min.x;
  p_y = &right->min.y;
  *(float *)a3 = x;
  if ( right->min.y <= left->min.y )
    p_y = &left->min.y;
  *(float *)(a3 + 4) = *p_y;
  p_max = &right->max;
  if ( left->max.x <= right->max.x )
    p_max = &left->max;
  v8 = &left->max.y;
  *(float *)(a3 + 8) = p_max->x;
  v9 = &right->max.y;
  if ( *v8 <= *v9 )
    v9 = v8;
  *(float *)(a3 + 12) = *v9;
  return result;
}
