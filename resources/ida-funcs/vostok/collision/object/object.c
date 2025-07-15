void __usercall vostok::collision::object::object(vostok::collision::object *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)a2 = &vostok::collision::object::`vftable';
  vostok::math::create_zero_aabb((vostok::math::aabb *)(a2 + 4));
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 40) = -33698355;
  *(_BYTE *)(a2 + 44) = 1;
}
