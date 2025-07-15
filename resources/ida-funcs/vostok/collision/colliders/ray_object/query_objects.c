char __usercall vostok::collision::colliders::ray_object::query_objects@<al>(
        vostok::collision::colliders::ray_object *this@<ecx>,
        int a2@<edi>,
        unsigned int a3@<esi>)
{
  _DWORD *v3; // ebx
  int v4; // eax
  double v5; // st7
  int v6; // edx
  const vostok::collision::oct_node *v7; // eax
  _DWORD *v8; // eax
  vostok::collision::ray_object_result *v9; // eax
  vostok::collision::ray_object_result *v10; // esi
  _DWORD *v11; // eax
  int *v13; // eax
  int v14; // esi
  int v15; // ebx
  float aabb_extents; // [esp+0h] [ebp-1Ch]
  vostok::collision::colliders::object::vertical_predicate<1> predicate; // [esp+17h] [ebp-5h] BYREF
  vostok::collision::colliders::object::distance_predicate __comp[4]; // [esp+18h] [ebp-4h]

  v3 = *(_DWORD **)(a2 + 52);
  if ( *v3 != v3[1] )
  {
    a3 = 0;
    v3[1] = *v3;
  }
  *(_DWORD *)__comp = *(_DWORD *)(a2 + 36) & 0x7FFFFFFF;
  v4 = *(_DWORD *)(a2 + 48);
  predicate = 0;
  v5 = *(float *)(v4 + 24);
  v6 = v4;
  v7 = *(const vostok::collision::oct_node **)(v4 + 20);
  aabb_extents = v5;
  if ( *(float *)__comp == *(float *)&clear_value )
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<1>>(
      (vostok::collision::colliders::ray_object *)a2,
      0,
      (const stlp_std::__true_type *)a2,
      a3,
      v7,
      (const vostok::math::float3 *)(v6 + 4),
      aabb_extents,
      &predicate);
  else
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<0>>(
      (vostok::collision::colliders::ray_object *)a2,
      0,
      (const stlp_std::__true_type *)a2,
      a3,
      v7,
      (const vostok::math::float3 *)(v6 + 4),
      aabb_extents,
      (const vostok::collision::colliders::object::vertical_predicate<0> *)&predicate);
  v8 = *(_DWORD **)(a2 + 52);
  if ( *v8 != v8[1] )
  {
    v9 = (vostok::collision::ray_object_result *)v8[1];
    v10 = **(vostok::collision::ray_object_result ***)(a2 + 52);
    __comp[0] = 0;
    stlp_std::sort<vostok::collision::ray_object_result *,vostok::collision::colliders::object::distance_predicate>(
      v10,
      v9,
      0);
    v11 = *(_DWORD **)(a2 + 56);
    if ( !*v11 && !v11[1] )
      return 1;
    v13 = *(int **)(a2 + 52);
    v14 = *v13;
    v15 = v13[1];
    if ( *v13 != v15 )
    {
      while ( !(*(unsigned __int8 (__thiscall **)(_DWORD, int))(*(_DWORD *)(a2 + 56) + 4))(**(_DWORD **)(a2 + 56), v14) )
      {
        v14 += 8;
        if ( v14 == v15 )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}
