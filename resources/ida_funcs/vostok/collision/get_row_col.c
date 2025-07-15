char __fastcall vostok::collision::get_row_col(
        int *x,
        int *z,
        float cell_size,
        int dimension,
        const vostok::math::float3 *position_local)
{
  float v5; // xmm0_4
  int v6; // eax
  int v7; // esi
  int v8; // eax

  v5 = *(float *)&clear_value / (float)(int)cell_size;
  *x = (int)(float)(position_local->x * v5);
  *z = -(int)(float)(position_local->z * v5);
  v6 = *x;
  v7 = dimension - 1;
  if ( *x > 0 )
  {
    if ( v6 > v7 )
      v6 = dimension - 1;
  }
  else
  {
    v6 = 0;
  }
  *x = v6;
  v8 = *z;
  if ( *z <= 0 )
  {
    v8 = 0;
LABEL_7:
    *z = v8;
    return 1;
  }
  if ( v8 <= v7 )
    goto LABEL_7;
  *z = v7;
  return 1;
}
