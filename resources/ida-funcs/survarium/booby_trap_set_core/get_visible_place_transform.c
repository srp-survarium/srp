char __thiscall survarium::booby_trap_set_core::get_visible_place_transform(
        survarium::booby_trap_set_core *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *a3)
{
  vostok::math::float4x4 *v3; // ebx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  float z; // ecx
  vostok::math::float4x4 *v6; // esi
  unsigned __int16 v8; // ax
  survarium::game_material_manager *v9; // ecx
  const survarium::game_material *material; // eax
  vostok::math::float4x4 *v11; // eax
  vostok::math::float4x4 *v12; // edi
  char v13; // bl
  vostok::math::float4x4 v14; // [esp+24h] [ebp-110h] BYREF
  vostok::math::float4x4 v15; // [esp+64h] [ebp-D0h] BYREF
  vostok::math::float4x4 v16; // [esp+A4h] [ebp-90h] BYREF
  int v17; // [esp+E8h] [ebp-4Ch] BYREF
  vostok::math::float3 v18; // [esp+ECh] [ebp-48h] BYREF
  float v19[6]; // [esp+F8h] [ebp-3Ch] BYREF
  __int64 v20; // [esp+110h] [ebp-24h] BYREF
  float v21; // [esp+118h] [ebp-1Ch]
  __int64 v22; // [esp+11Ch] [ebp-18h] BYREF
  float v23; // [esp+124h] [ebp-10h]
  vostok::math::float3 v24; // [esp+128h] [ebp-Ch] BYREF

  v3 = result;
  v4 = (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(result[4].j.x) + 376) + 12))(*(_DWORD *)(LODWORD(result[4].j.x) + 376));
  survarium::base_player::computed_head_transform((survarium::base_player *)&v15, v4, &v15);
  z = v3[5].j.z;
  result = (vostok::math::float4x4 *)LODWORD(v3[4].c.w);
  v20 = *(_QWORD *)&v15.lines[3].x;
  v21 = v15.c.z;
  v22 = *(_QWORD *)&v15.lines[2].x;
  v23 = v15.k.z;
  (*(void (__thiscall **)(float, int *, __int64 *, __int64 *, vostok::math::float4x4 *, int, int, _DWORD, int))(*(_DWORD *)LODWORD(z) + 64))(
    COERCE_FLOAT(LODWORD(z)),
    &v17,
    &v20,
    &v22,
    result,
    1028,
    514,
    0,
    1);
  if ( !v17 )
  {
    v24.x = (float)(*(float *)&v22 * *(float *)&result) + *(float *)&v20;
    v24.y = *((float *)&v20 + 1) + (float)(*((float *)&v22 + 1) * *(float *)&result);
    v24.z = v21 + (float)(v23 * *(float *)&result);
    v6 = survarium::create_place_matrix_for_looking_point(&v24, &v15, &v16, &v15.j.x);
LABEL_3:
    qmemcpy(a3, v6, sizeof(vostok::math::float4x4));
    return 0;
  }
  survarium::create_place_matrix_for_looking_point(&v18, &v15, &v16, v19);
  if ( v3[4].c.z > v19[1]
    || ((**(int (__thiscall ***)(int))v17)(v17) & 0x200) != 0
    || (v8 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v17 + 16))(v17, LODWORD(v19[3]), LODWORD(v19[4])),
        material = survarium::game_material_manager::get_material(v9, LODWORD(v3[5].j.w), v8),
        BYTE1(v3[5].lines[1].x))
    && !material->m_mine_can_place
    || BYTE2(v3[5].lines[1].elements[0]) && !material->m_mine_can_stick )
  {
    v6 = &v16;
    goto LABEL_3;
  }
  v24.x = COERCE_FLOAT(v22 ^ _mask__NegFloat_) * 0.0049999999;
  v24.y = COERCE_FLOAT(HIDWORD(v22) ^ _mask__NegFloat_) * 0.0049999999;
  v24.z = COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_) * 0.0049999999;
  v11 = vostok::math::create_translation(&v24, &v15);
  vostok::math::mul4x3(v11, &v16, &v14);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *)&result,
    (const vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *)LODWORD(v3[4].k.x));
  v12 = a3;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD, vostok::math::float4x4 *, vostok::math::float4x4 *, int, int))(*(_DWORD *)LODWORD(v3[5].j.z) + 76))(
         LODWORD(v3[5].j.z),
         *(_DWORD *)(*(_DWORD *)(*(_DWORD *)LODWORD(result->k.y) + 20) + 16),
         &v14,
         a3,
         1028,
         514) )
  {
    v13 = 1;
  }
  else
  {
    qmemcpy(v12, &v16, sizeof(vostok::math::float4x4));
    v13 = 0;
  }
  vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  return v13;
}
