void __usercall vostok::collision::colliders::sse::construct_aabb_a16(
        const vostok::math::float3 *center@<ecx>,
        const vostok::math::float3 *extents@<eax>,
        vostok::collision::colliders::sse::aabb_a16 *result)
{
  __int64 v3; // [esp+4h] [ebp-8h]

  *(float *)&v3 = center->y - extents->y;
  *((float *)&v3 + 1) = center->z - extents->z;
  result->min.x = center->x - extents->x;
  *(_QWORD *)&result->min.elements[1] = v3;
  result->min.padding = 0.0;
  *(float *)&v3 = center->y + extents->y;
  *((float *)&v3 + 1) = extents->z + center->z;
  result->max.x = center->x + extents->x;
  *(_QWORD *)&result->max.elements[1] = v3;
  result->max.padding = 0.0;
}
