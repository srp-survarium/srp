void __usercall vostok::physics::new_bt_primitive(
        const vostok::collision::primitive_type type@<esi>,
        const vostok::math::float3 *dimension@<edx>,
        vostok::memory::base_allocator *allocator@<ecx>,
        float a4@<xmm4>)
{
  btSphereShape *v4; // eax
  btSphereShape *v5; // ecx
  vostok::memory::base_allocator_vtbl *v6; // eax
  float z; // xmm0_4
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // edx
  btBoxShape *v9; // eax
  vostok::memory::base_allocator_vtbl *v10; // eax
  float v11; // xmm0_4
  void *(__thiscall *v12)(vostok::memory::base_allocator *, unsigned int); // edx
  btCylinderShape *v13; // eax
  btCapsuleShape *v14; // eax
  float x; // [esp+6Ch] [ebp-18h]
  float v16; // [esp+6Ch] [ebp-18h]
  btVector3 boxHalfExtents; // [esp+74h] [ebp-10h] BYREF

  switch ( type )
  {
    case primitive_sphere:
      x = dimension->x;
      v4 = (btSphereShape *)allocator->call_malloc(allocator, 64);
      if ( v4 )
        btSphereShape::btSphereShape(v5, v4, x);
      break;
    case primitive_box:
      v6 = allocator->__vftable;
      boxHalfExtents.mVec128.m128_u64[0] = *(_QWORD *)&dimension->x;
      z = dimension->z;
      call_malloc = v6->call_malloc;
      boxHalfExtents.mVec128.m128_u64[1] = LODWORD(z);
      v9 = (btBoxShape *)call_malloc(allocator, 80u);
      if ( v9 )
        btBoxShape::btBoxShape(v9, &boxHalfExtents);
      break;
    case primitive_cylinder:
      v10 = allocator->__vftable;
      boxHalfExtents.mVec128.m128_u64[0] = *(_QWORD *)&dimension->x;
      v11 = dimension->z;
      v12 = v10->call_malloc;
      boxHalfExtents.mVec128.m128_u64[1] = LODWORD(v11);
      v13 = (btCylinderShape *)v12(allocator, 80u);
      if ( v13 )
        btCylinderShape::btCylinderShape(v13, &boxHalfExtents);
      break;
    case primitive_capsule:
      v16 = dimension->x;
      v14 = (btCapsuleShape *)allocator->call_malloc(allocator, 80);
      if ( v14 )
        btCapsuleShape::btCapsuleShape(v14, v16, a4);
      break;
    default:
      return;
  }
}
