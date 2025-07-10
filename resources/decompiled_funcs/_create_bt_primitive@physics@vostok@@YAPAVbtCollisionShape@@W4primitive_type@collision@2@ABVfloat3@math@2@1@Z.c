void __usercall vostok::physics::create_bt_primitive(
        vostok::collision::primitive_type type@<edx>,
        const vostok::math::float3 *dim@<ecx>,
        float a3@<xmm4>)
{
  btSphereShape *v3; // eax
  btSphereShape *v4; // ecx
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // edx
  btBoxShape *v6; // eax
  void *(__thiscall *v7)(vostok::memory::base_allocator *, unsigned int); // edx
  btCylinderShape *v8; // eax
  btCapsuleShape *v9; // eax
  float x; // [esp+6Ch] [ebp-18h]
  float v11; // [esp+6Ch] [ebp-18h]
  btVector3 boxHalfExtents; // [esp+74h] [ebp-10h] BYREF

  switch ( type )
  {
    case primitive_sphere:
      x = dim->x;
      v3 = (btSphereShape *)vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 64);
      if ( v3 )
        btSphereShape::btSphereShape(v4, v3, x);
      break;
    case primitive_box:
      boxHalfExtents.mVec128.m128_u64[0] = *(_QWORD *)&dim->x;
      call_malloc = vostok::physics::g_ph_allocator->call_malloc;
      boxHalfExtents.mVec128.m128_u64[1] = LODWORD(dim->z);
      v6 = (btBoxShape *)call_malloc(vostok::physics::g_ph_allocator, 80u);
      if ( v6 )
        btBoxShape::btBoxShape(v6, &boxHalfExtents);
      break;
    case primitive_cylinder:
      boxHalfExtents.mVec128.m128_u64[0] = *(_QWORD *)&dim->x;
      v7 = vostok::physics::g_ph_allocator->call_malloc;
      boxHalfExtents.mVec128.m128_u64[1] = LODWORD(dim->z);
      v8 = (btCylinderShape *)v7(vostok::physics::g_ph_allocator, 80u);
      if ( v8 )
        btCylinderShape::btCylinderShape(v8, &boxHalfExtents);
      break;
    case primitive_capsule:
      v11 = dim->x;
      v9 = (btCapsuleShape *)vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, 80);
      if ( v9 )
        btCapsuleShape::btCapsuleShape(v9, v11, a3);
      break;
    default:
      return;
  }
}
