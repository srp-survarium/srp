int __usercall vostok::collision::octant_index@<eax>(const vostok::math::float3 *signs@<eax>)
{
  BOOL v1; // edx
  BOOL v2; // ecx

  v1 = signs->x >= 0.0;
  v2 = signs->y >= 0.0;
  if ( signs->z >= 0.0 )
    return v1 | (2 * (v2 | 2));
  else
    return v1 | (2 * v2);
}
