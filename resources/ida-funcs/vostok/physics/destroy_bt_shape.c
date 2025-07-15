void __cdecl vostok::physics::destroy_bt_shape(btCollisionShape *sh)
{
  btCompoundShape *v1; // ecx
  int m_shapeType; // eax
  btCollisionShape_vtbl *v3; // edi
  vostok::memory::base_allocator *v4; // edi
  void (__thiscall *getBoundingSphere)(btCollisionShape *, btVector3 *, float *); // edi
  btCompoundShape *v6; // [esp+0h] [ebp-1Ch]
  vostok::memory::base_allocator *v7; // [esp+14h] [ebp-8h]
  _BYTE *v8; // [esp+18h] [ebp-4h]
  _BYTE *v9; // [esp+18h] [ebp-4h]

  m_shapeType = sh->m_shapeType;
  if ( m_shapeType == 31 )
  {
    while ( sh[1].m_shapeType )
    {
      getBoundingSphere = sh[2].__vftable[1].getBoundingSphere;
      btCompoundShape::removeChildShapeByIndex(v1, sh, 0);
      vostok::physics::destroy_bt_shape((btCollisionShape *)getBoundingSphere);
      v1 = v6;
    }
  }
  else if ( m_shapeType == 21 )
  {
    v3 = sh[4].__vftable;
    v7 = vostok::physics::g_allocator;
    if ( v3 )
    {
      v8 = __RTCastToVoid((void **)&v3->~btCollisionShape);
      (*(void (__thiscall **)(btCollisionShape_vtbl *, _DWORD))v3->~btCollisionShape)(v3, 0);
      v7->call_free(v7, v8, "vostok::physics::destroy_bt_shape", ".\\collision_shapes.cpp", 165u);
    }
  }
  v4 = vostok::physics::g_allocator;
  v9 = __RTCastToVoid((void **)&sh->__vftable);
  ((void (__thiscall *)(btCollisionShape *, _DWORD))sh->~btCollisionShape)(sh, 0);
  v4->call_free(v4, v9, "vostok::physics::destroy_bt_shape", ".\\collision_shapes.cpp", 168u);
}
