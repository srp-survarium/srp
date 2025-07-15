vostok::math::aabb *__usercall vostok::physics::bt_animated_rigid_body::get_aabb@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        int a2@<eax>,
        int a3@<esi>)
{
  float v3; // edx
  float v4; // xmm1_4
  __int64 v6; // [esp+50h] [ebp-30h] BYREF
  float v7[3]; // [esp+58h] [ebp-28h]
  __int64 v8; // [esp+64h] [ebp-1Ch]
  __int64 v9; // [esp+70h] [ebp-10h] BYREF
  float v10; // [esp+78h] [ebp-8h]

  (*(void (__thiscall **)(_DWORD, int, __int64 *, __int64 *))(**(_DWORD **)(*(_DWORD *)(a2 + 12) + 204) + 4))(
    *(_DWORD *)(*(_DWORD *)(a2 + 12) + 204),
    *(_DWORD *)(a2 + 12) + 16,
    &v9,
    &v6);
  v8 = v6;
  v3 = -v7[0];
  v4 = -v10;
  *(_QWORD *)a3 = v9;
  *(_QWORD *)(a3 + 12) = v8;
  *(float *)(a3 + 8) = v4;
  *(float *)(a3 + 20) = v3;
  return (vostok::math::aabb *)a3;
}
