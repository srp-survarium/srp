vostok::math::aabb *__usercall vostok::collision::animated_object::get_aabb@<eax>(
        vostok::collision::animated_object *this@<ecx>,
        int a2@<eax>,
        _QWORD *a3@<edi>)
{
  vostok::math::aabb *aabb; // eax
  _BYTE v5[24]; // [esp+8h] [ebp-30h] BYREF
  _BYTE v6[24]; // [esp+20h] [ebp-18h] BYREF

  if ( *(_DWORD *)(a2 + 32) )
    aabb = (vostok::math::aabb *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)(a2 + 32) + 92))(
                                   *(_DWORD *)(a2 + 32),
                                   v5);
  else
    aabb = vostok::physics::bt_animated_rigid_body::get_aabb(
             (vostok::physics::bt_animated_rigid_body *)this,
             *(_DWORD *)(a2 + 36),
             (int)v6);
  *a3 = *(_QWORD *)&aabb->min.x;
  a3[1] = *(_QWORD *)&aabb->min.elements[2];
  a3[2] = *(_QWORD *)&aabb->max.elements[1];
  return (vostok::math::aabb *)a3;
}
