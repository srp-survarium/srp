void __thiscall vostok::render::light::remove_collision(vostok::render::light *this, vostok::render::light *thisa)
{
  vostok::collision::space_partitioning_tree *m_collision_tree; // ecx
  void **v3; // esi
  vostok::render::grass_render_model *m_object; // edi
  _BYTE *v5; // ebp
  void **v6; // esi
  _BYTE *v7; // ebp

  if ( thisa->m_collision_object )
  {
    m_collision_tree = thisa->m_collision_tree;
    if ( m_collision_tree )
      m_collision_tree->erase(m_collision_tree, thisa->m_collision_object);
    v3 = (void **)&thisa->m_collision_object->__vftable;
    m_object = vostok::render::g_allocator.m_object;
    if ( v3 )
    {
      v5 = __RTCastToVoid(v3);
      (*((void (__thiscall **)(void **, _DWORD))*v3 + 11))(v3, 0);
      ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))m_object->is_increasing_quality)(
        m_object,
        v5);
      m_object = vostok::render::g_allocator.m_object;
    }
    v6 = (void **)&thisa->m_collision_geometry->__vftable;
    if ( v6 )
    {
      (*(void (__thiscall **)(void **, vostok::render::grass_render_model *))*v6)(v6, m_object);
      v7 = __RTCastToVoid(v6);
      (*((void (__thiscall **)(void **, _DWORD))*v6 + 32))(v6, 0);
      ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))m_object->is_increasing_quality)(
        m_object,
        v7);
    }
    thisa->m_collision_object = 0;
  }
}
