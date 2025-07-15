char __usercall vostok::collision::colliders::ray_object::query_triangles@<al>(
        vostok::collision::colliders::ray_object *this@<ecx>,
        const stlp_std::__true_type *a2@<edi>,
        unsigned int a3@<esi>)
{
  _DWORD *v3; // ebx
  int v4; // eax
  double v5; // st7
  int v6; // edx
  const vostok::collision::oct_node *v7; // eax
  vostok::collision::ray_triangle_result **v8; // eax
  vostok::collision::ray_triangle_result *v9; // edi
  vostok::collision::ray_triangle_result *v10; // eax
  vostok::collision::ray_triangle_result **v11; // eax
  vostok::collision::ray_triangle_result *v12; // edi
  vostok::collision::ray_triangle_result *v13; // ecx
  unsigned __int8 *v14; // eax
  int v15; // ebp
  unsigned int v16; // ebx
  int v17; // eax
  int *v18; // eax
  int v19; // edi
  int v20; // ebx
  float aabb_extents; // [esp+0h] [ebp-1Ch]
  vostok::collision::colliders::object::vertical_predicate<1> predicate; // [esp+17h] [ebp-5h] BYREF
  vostok::collision::colliders::object::distance_predicate __comp[4]; // [esp+18h] [ebp-4h]

  v3 = *(_DWORD **)(a3 + 60);
  if ( *v3 != v3[1] )
  {
    a2 = 0;
    v3[1] = *v3;
  }
  *(_DWORD *)__comp = *(_DWORD *)(a3 + 36) & 0x7FFFFFFF;
  v4 = *(_DWORD *)(a3 + 48);
  predicate = 0;
  v5 = *(float *)(v4 + 24);
  v6 = v4;
  v7 = *(const vostok::collision::oct_node **)(v4 + 20);
  aabb_extents = v5;
  if ( *(float *)__comp == *(float *)&clear_value )
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<1>>(
      (vostok::collision::colliders::ray_object *)a3,
      0,
      a2,
      a3,
      v7,
      (const vostok::math::float3 *)(v6 + 4),
      aabb_extents,
      &predicate);
  else
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<0>>(
      (vostok::collision::colliders::ray_object *)a3,
      0,
      a2,
      a3,
      v7,
      (const vostok::math::float3 *)(v6 + 4),
      aabb_extents,
      (const vostok::collision::colliders::object::vertical_predicate<0> *)&predicate);
  v8 = *(vostok::collision::ray_triangle_result ***)(a3 + 60);
  if ( *v8 == v8[1] )
    return 0;
  v9 = v8[1];
  v10 = *v8;
  __comp[0] = 0;
  stlp_std::sort<vostok::collision::ray_triangle_result *,vostok::collision::colliders::object::distance_predicate>(
    v10,
    v9,
    0);
  v11 = *(vostok::collision::ray_triangle_result ***)(a3 + 60);
  v12 = v11[1];
  v13 = *v11;
  __comp[0] = 0;
  v14 = (unsigned __int8 *)stlp_std::remove_if<vostok::collision::ray_triangle_result *,negative_distance_detector>(
                             v13,
                             v12,
                             0);
  v15 = *(_DWORD *)(a3 + 60);
  if ( v14 != (unsigned __int8 *)v12 )
  {
    v16 = *(_DWORD *)(v15 + 4) - (_DWORD)v12;
    if ( v16 )
    {
      memmove(v14, (unsigned __int8 *)v12, v16);
      v14 = (unsigned __int8 *)(v16 + v17);
    }
    *(_DWORD *)(v15 + 4) = v14;
  }
  v18 = *(int **)(a3 + 60);
  v19 = *v18;
  v20 = v18[1];
  if ( *v18 == v20 )
    return 0;
  while ( !(*(unsigned __int8 (__thiscall **)(_DWORD, int))(*(_DWORD *)(a3 + 64) + 4))(**(_DWORD **)(a3 + 64), v19) )
  {
    v19 += 12;
    if ( v19 == v20 )
      return 0;
  }
  return 1;
}
