void __usercall vostok::collision::colliders::cuboid_object::process(
        vostok::collision::colliders::cuboid_object *this@<ecx>,
        __int64 a2@<esi:edi>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  unsigned int v5; // eax
  _DWORD *v6; // ecx

  v2 = *(_DWORD **)(a2 + 8);
  if ( v2 )
  {
    HIDWORD(a2) = (v2[1] - *v2) >> 2;
  }
  else
  {
    v3 = *(_DWORD **)(a2 + 12);
    if ( v3 )
      HIDWORD(a2) = (v3[1] - *v3) >> 3;
    else
      HIDWORD(a2) = 0;
  }
  vostok::collision::colliders::cuboid_object::query(
    (vostok::collision::colliders::cuboid_object *)a2,
    a2,
    *(vostok::collision::oct_node **)(*(_DWORD *)a2 + 4),
    (const vostok::math::float3 *)(*(_DWORD *)a2 + 16),
    *(float *)(*(_DWORD *)a2 + 28));
  v4 = *(_DWORD **)(a2 + 8);
  if ( v4 )
  {
    v5 = (v4[1] - *v4) >> 2;
  }
  else
  {
    v6 = *(_DWORD **)(a2 + 12);
    if ( v6 )
      v5 = (v6[1] - *v6) >> 3;
    else
      v5 = 0;
  }
  *(_BYTE *)(a2 + 24) = v5 > HIDWORD(a2);
}
