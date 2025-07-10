void __thiscall vostok::collision::animated_object::~animated_object(
        vostok::collision::animated_object *this,
        vostok::collision::animated_object *thisa)
{
  void **v2; // esi
  vostok::memory::stack_allocator *p_m_allocator; // edi
  _BYTE *v4; // ebp
  vostok::collision::bone_collision_data *m_begin; // eax

  v2 = (void **)&thisa->m_body->__vftable;
  p_m_allocator = &thisa->m_allocator;
  if ( v2 )
  {
    v4 = __RTCastToVoid(v2);
    (*((void (__thiscall **)(void **, _DWORD))*v2 + 2))(v2, 0);
    p_m_allocator->call_free(p_m_allocator, v4);
  }
  m_begin = thisa->m_geometries_data.m_begin;
  p_m_allocator->__vftable = (vostok::memory::stack_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  thisa->m_geometries_data.m_end = m_begin;
}
