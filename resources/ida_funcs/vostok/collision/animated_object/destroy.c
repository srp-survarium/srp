void __thiscall vostok::collision::animated_object::destroy(
        vostok::collision::animated_object *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::collision::geometry *m_geometry; // ebx
  vostok::collision::bone_collision_data *m_begin; // eax
  vostok::collision::geometry_instance *const *v4; // esi
  unsigned int v5; // edi
  void *v6; // esp
  vostok::collision::geometry_instance *const *v7; // eax
  _BYTE *v8; // edx
  unsigned int i; // ebx
  void **v10; // esi
  _BYTE v11[12]; // [esp+0h] [ebp-14h] BYREF
  _BYTE *v12; // [esp+Ch] [ebp-8h]
  vostok::collision::geometry_instance *const *end; // [esp+10h] [ebp-4h]

  m_geometry = this->m_geometry;
  if ( m_geometry )
  {
    m_begin = this->m_geometries_data.m_begin;
    this->m_geometries_data.m_end = this->m_geometries_data.m_begin;
    if ( m_begin )
      allocator->call_free(allocator, m_begin);
    v4 = (vostok::collision::geometry_instance *const *)m_geometry[1].__vftable;
    end = (vostok::collision::geometry_instance *const *)m_geometry[1].type;
    v5 = end - v4;
    v6 = alloca(4 * v5);
    v12 = v11;
    v7 = v4;
    if ( v4 != end )
    {
      v8 = (_BYTE *)(v11 - (_BYTE *)v4);
      do
      {
        if ( (vostok::collision::geometry_instance *const *)((char *)v7 + (_DWORD)v8) )
          *(vostok::collision::geometry_instance **)((char *)v7 + (_DWORD)v8) = *v7;
        ++v7;
      }
      while ( v7 != end );
    }
    m_geometry->destroy(m_geometry, allocator);
    for ( i = 0; i < v5; ++i )
    {
      v10 = *(void ***)&v12[4 * i];
      if ( v10 )
      {
        (*(void (__thiscall **)(void **, vostok::memory::base_allocator *))*v10)(v10, allocator);
        end = (vostok::collision::geometry_instance *const *)__RTCastToVoid(v10);
        (*((void (__thiscall **)(void **, _DWORD))*v10 + 32))(v10, 0);
        allocator->call_free(allocator, (void *)end);
      }
    }
  }
}
