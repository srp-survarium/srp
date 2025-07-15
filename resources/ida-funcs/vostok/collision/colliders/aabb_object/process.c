void __usercall vostok::collision::colliders::aabb_object::process(
        vostok::collision::colliders::aabb_object *this@<ecx>,
        __int64 a2@<esi:edi>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  unsigned int v4; // eax

  v2 = *(_DWORD **)(a2 + 8);
  if ( v2 )
    HIDWORD(a2) = (v2[1] - *v2) >> 2;
  else
    HIDWORD(a2) = (*(_DWORD *)(*(_DWORD *)(a2 + 12) + 4) - **(_DWORD **)(a2 + 12)) >> 3;
  vostok::collision::colliders::aabb_object::query(
    (vostok::collision::colliders::aabb_object *)a2,
    a2,
    *(vostok::collision::oct_node **)(*(_DWORD *)(a2 + 16) + 4),
    COERCE_FLOAT(*(_DWORD *)(a2 + 16) + 16),
    COERCE_INT(*(float *)(*(_DWORD *)(a2 + 16) + 28)));
  v3 = *(_DWORD **)(a2 + 8);
  if ( v3 )
    v4 = (v3[1] - *v3) >> 2;
  else
    v4 = (*(_DWORD *)(*(_DWORD *)(a2 + 12) + 4) - **(_DWORD **)(a2 + 12)) >> 3;
  *(_BYTE *)(a2 + 4) = v4 > HIDWORD(a2);
}
