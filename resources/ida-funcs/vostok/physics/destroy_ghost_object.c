void __cdecl vostok::physics::destroy_ghost_object(vostok::physics::bt_ghost_object *obj)
{
  vostok::physics::bt_collision_shape *m_object; // esi
  vostok::memory::base_allocator *v2; // edi
  vostok::memory::base_allocator *v3; // esi
  _BYTE *v4; // edi
  vostok::memory::detail::call_destructor_predicate *v5; // [esp+0h] [ebp-14h]
  _BYTE *v6; // [esp+10h] [ebp-4h]

  m_object = obj->m_shape.m_object;
  v2 = vostok::physics::g_allocator;
  if ( m_object )
  {
    v6 = __RTCastToVoid((void **)&obj->m_shape.m_object->__vftable);
    ((void (__thiscall *)(vostok::physics::bt_collision_shape *, _DWORD))m_object->~vostok::physics::bt_collision_shape)(
      m_object,
      0);
    v2->call_free(v2, v6, "vostok::physics::destroy_ghost_object", ".\\ghost_object.cpp", 67u);
  }
  v3 = vostok::physics::g_allocator;
  v4 = __RTCastToVoid((void **)&obj->__vftable);
  vostok::memory::detail::call_destructor_predicate::operator()<vostok::physics::bt_ghost_object>(obj, v5);
  v3->call_free(v3, v4, "vostok::physics::destroy_ghost_object", ".\\ghost_object.cpp", 68u);
}
