char __usercall vostok::collision::colliders::ray_object::query_triangles@<al>(
        vostok::collision::colliders::ray_object *this@<ecx>,
        int a2@<esi>,
        float a3@<ebx>,
        unsigned int a4@<edi>)
{
  int v4; // eax
  vostok::collision::ray_triangle_result **v5; // eax
  vostok::collision::ray_triangle_result *v6; // edi
  vostok::collision::ray_triangle_result *v7; // ebx
  int v8; // eax
  int v9; // ecx
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  vostok::collision::ray_triangle_result v14; // [esp+4h] [ebp-1Ch]
  vostok::collision::ray_triangle_result *v15; // [esp+4h] [ebp-1Ch]
  vostok::collision::ray_triangle_result *v16; // [esp+14h] [ebp-Ch] BYREF
  vostok::collision::colliders::object::distance_predicate __comp[4]; // [esp+18h] [ebp-8h] BYREF
  vostok::collision::colliders::object::vertical_predicate<1> predicate; // [esp+1Fh] [ebp-1h] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  *(_DWORD *)(*(_DWORD *)(a2 + 60) + 4) = **(_DWORD **)(a2 + 60);
  v14.distance = a3;
  v14.triangle_id = a4;
  *(_DWORD *)__comp = *(_DWORD *)(a2 + 36) & 0x7FFFFFFF;
  predicate = 0;
  v4 = *(_DWORD *)(a2 + 48);
  if ( *(float *)__comp == s_bm_current_air_resistance )
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<1>>(
      (vostok::collision::colliders::ray_object *)a2,
      *(const vostok::collision::oct_node *const *)(v4 + 4),
      (const vostok::math::float3 *)(*(_DWORD *)(a2 + 48) + 16),
      *(float *)(v4 + 28),
      &predicate);
  else
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<0>>(
      (vostok::collision::colliders::ray_object *)a2,
      (float *)&savedregs,
      *(const vostok::collision::oct_node *const *)(v4 + 4),
      (const vostok::math::float3 *)(*(_DWORD *)(a2 + 48) + 16),
      *(float *)(v4 + 28),
      (const vostok::collision::colliders::object::vertical_predicate<0> *)&predicate);
  if ( **(_DWORD **)(a2 + 60) != *(_DWORD *)(*(_DWORD *)(a2 + 60) + 4) )
  {
    __comp[0] = 0;
    v5 = *(vostok::collision::ray_triangle_result ***)(a2 + 60);
    v6 = v5[1];
    v7 = *v5;
    if ( *v5 != v6 )
    {
      v8 = v6 - v7;
      v9 = 0;
      while ( v8 != 1 )
      {
        ++v9;
        v8 >>= 1;
      }
      stlp_std::priv::__introsort_loop<vostok::collision::ray_triangle_result *,vostok::collision::ray_triangle_result,int,vostok::collision::colliders::object::distance_predicate>(
        (vostok::collision::colliders::object::distance_predicate)v6,
        v7,
        v6,
        0,
        2 * v9,
        *(vostok::collision::ray_triangle_result **)__comp);
      v14.object = *(const vostok::collision::object **)__comp;
      stlp_std::priv::__final_insertion_sort<vostok::collision::ray_triangle_result *,vostok::collision::colliders::object::distance_predicate>(
        v6,
        v14);
    }
    v16 = *(vostok::collision::ray_triangle_result **)(*(_DWORD *)(a2 + 60) + 4);
    __comp[0] = 0;
    v15 = *(vostok::collision::ray_triangle_result **)__comp;
    *(float *)__comp = COERCE_FLOAT(stlp_std::remove_if<vostok::collision::ray_triangle_result *,negative_distance_detector>(*(vostok::collision::ray_triangle_result **)(*(_DWORD *)(a2 + 60) + 4)));
    vostok::buffer_vector<vostok::collision::ray_triangle_result>::erase(
      (vostok::buffer_vector<vostok::collision::ray_triangle_result> *)v15,
      *(vostok::collision::ray_triangle_result *const **)(a2 + 60),
      (vostok::collision::ray_triangle_result **)__comp,
      &v16);
    v10 = *(int **)(a2 + 60);
    v11 = *v10;
    v12 = v10[1];
    while ( v11 != v12 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int))(*(_DWORD *)(a2 + 64) + 4))(**(_DWORD **)(a2 + 64), v11) )
        return 1;
      v11 += 12;
    }
  }
  return 0;
}
