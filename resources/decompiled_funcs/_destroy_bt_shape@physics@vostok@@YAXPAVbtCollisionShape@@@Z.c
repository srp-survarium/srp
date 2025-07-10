void __cdecl vostok::physics::destroy_bt_shape(btCollisionShape *sh)
{
  btCompoundShape *v1; // ecx
  int m_shapeType; // eax
  void (__thiscall *getBoundingSphere)(btCollisionShape *, btVector3 *, float *); // edi
  btCollisionShape_vtbl *v4; // edi
  vostok::memory::base_allocator *v5; // ebx
  vostok::memory::base_allocator *v6; // edi
  _BYTE *v7; // ebx
  _BYTE *v8; // [esp+Ch] [ebp-4h]

  m_shapeType = sh->m_shapeType;
  if ( m_shapeType == 31 )
  {
    while ( sh[1].m_shapeType )
    {
      getBoundingSphere = sh[2].__vftable[1].getBoundingSphere;
      btCompoundShape::removeChildShapeByIndex(v1, (int)sh, 0);
      vostok::physics::destroy_bt_shape((btCollisionShape *)getBoundingSphere);
    }
  }
  else if ( m_shapeType == 21 )
  {
    v4 = sh[4].__vftable;
    v5 = vostok::physics::g_ph_allocator;
    if ( v4 )
    {
      v8 = __RTCastToVoid((void **)&sh[4].~btCollisionShape);
      (*(void (__thiscall **)(btCollisionShape_vtbl *, _DWORD))v4->~btCollisionShape)(v4, 0);
      v5->call_free(v5, v8);
    }
  }
  v6 = vostok::physics::g_ph_allocator;
  v7 = __RTCastToVoid((void **)&sh->__vftable);
  ((void (__thiscall *)(btCollisionShape *, _DWORD))sh->~btCollisionShape)(sh, 0);
  v6->call_free(v6, v7);
}
