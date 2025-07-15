void __usercall vostok::physics::create_bt_primitive(
        vostok::collision::primitive_type type@<edx>,
        const vostok::math::float3 *dim@<ecx>,
        vostok::memory::base_allocator *allocator@<esi>)
{
  int v4; // edx
  int v5; // edx
  char *v6; // eax
  btCapsuleShape *v7; // eax
  btConvexInternalShape *v8; // ecx
  char *v9; // eax
  btCylinderShape *v10; // eax
  char *v11; // eax
  btBoxShape *v12; // eax
  char *v13; // eax
  btSphereShape *v14; // ecx
  __int64 radius; // [esp+20h] [ebp-18h]
  float x; // [esp+24h] [ebp-14h]

  if ( type )
  {
    v4 = type - 1;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          radius = *(_QWORD *)&dim->x;
          v6 = type_info::raw_name(&btCapsuleShape `RTTI Type Descriptor');
          v7 = (btCapsuleShape *)allocator->call_malloc(
                                   allocator,
                                   80,
                                   v6,
                                   "vostok::physics::create_bt_primitive",
                                   ".\\collision_shapes.cpp",
                                   210);
          if ( v7 )
            btCapsuleShape::btCapsuleShape(v7, v8, *((float *)&radius + 1), *(float *)&radius);
        }
      }
      else
      {
        v9 = type_info::raw_name(&btCylinderShape `RTTI Type Descriptor');
        v10 = (btCylinderShape *)allocator->call_malloc(
                                   allocator,
                                   80,
                                   v9,
                                   "vostok::physics::create_bt_primitive",
                                   ".\\collision_shapes.cpp",
                                   201);
        if ( v10 )
          btCylinderShape::btCylinderShape(v10);
      }
    }
    else
    {
      v11 = type_info::raw_name(&btBoxShape `RTTI Type Descriptor');
      v12 = (btBoxShape *)allocator->call_malloc(
                            allocator,
                            80,
                            v11,
                            "vostok::physics::create_bt_primitive",
                            ".\\collision_shapes.cpp",
                            193);
      if ( v12 )
        btBoxShape::btBoxShape(v12);
    }
  }
  else
  {
    x = dim->x;
    v13 = type_info::raw_name(&btSphereShape `RTTI Type Descriptor');
    if ( allocator->call_malloc(
           allocator,
           64,
           v13,
           "vostok::physics::create_bt_primitive",
           ".\\collision_shapes.cpp",
           185) )
    {
      btSphereShape::btSphereShape(v14, x);
    }
  }
}
