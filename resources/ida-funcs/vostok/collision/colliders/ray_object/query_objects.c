char __usercall vostok::collision::colliders::ray_object::query_objects@<al>(
        vostok::collision::colliders::ray_object *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  vostok::collision::ray_object_result **v3; // eax
  vostok::collision::ray_object_result *v4; // edi
  vostok::collision::ray_object_result *v5; // ebx
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // eax
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  vostok::collision::ray_object_result *__comp; // [esp+10h] [ebp-8h]
  vostok::collision::colliders::object::vertical_predicate<1> predicate; // [esp+17h] [ebp-1h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  *(_DWORD *)(*(_DWORD *)(a2 + 52) + 4) = **(_DWORD **)(a2 + 52);
  __comp = (vostok::collision::ray_object_result *)(*(_DWORD *)(a2 + 36) & 0x7FFFFFFF);
  predicate = 0;
  v2 = *(_DWORD *)(a2 + 48);
  if ( *(float *)&__comp == s_bm_current_air_resistance )
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<1>>(
      (vostok::collision::colliders::ray_object *)a2,
      *(const vostok::collision::oct_node *const *)(v2 + 4),
      (const vostok::math::float3 *)(*(_DWORD *)(a2 + 48) + 16),
      *(float *)(v2 + 28),
      &predicate);
  else
    vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<0>>(
      (vostok::collision::colliders::ray_object *)a2,
      (float *)&savedregs,
      *(const vostok::collision::oct_node *const *)(v2 + 4),
      (const vostok::math::float3 *)(*(_DWORD *)(a2 + 48) + 16),
      *(float *)(v2 + 28),
      (const vostok::collision::colliders::object::vertical_predicate<0> *)&predicate);
  if ( **(_DWORD **)(a2 + 52) != *(_DWORD *)(*(_DWORD *)(a2 + 52) + 4) )
  {
    LOBYTE(__comp) = 0;
    v3 = *(vostok::collision::ray_object_result ***)(a2 + 52);
    v4 = v3[1];
    v5 = *v3;
    if ( *v3 != v4 )
    {
      v6 = v4 - v5;
      v7 = 0;
      while ( v6 != 1 )
      {
        ++v7;
        v6 >>= 1;
      }
      stlp_std::priv::__introsort_loop<vostok::collision::ray_object_result *,vostok::collision::ray_object_result,int,vostok::collision::colliders::object::distance_predicate>(
        v5,
        v4,
        0,
        2 * v7,
        __comp);
      stlp_std::priv::__final_insertion_sort<vostok::collision::ray_object_result *,vostok::collision::colliders::object::distance_predicate>(
        v5,
        v4,
        0);
    }
    v8 = *(_DWORD **)(a2 + 56);
    if ( !*v8 && !v8[1] )
      return 1;
    v10 = *(int **)(a2 + 52);
    v11 = *v10;
    v12 = v10[1];
    while ( v11 != v12 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int))(*(_DWORD *)(a2 + 56) + 4))(**(_DWORD **)(a2 + 56), v11) )
        return 1;
      v11 += 8;
    }
  }
  return 0;
}
