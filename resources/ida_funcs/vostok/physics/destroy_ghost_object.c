void __usercall vostok::physics::destroy_ghost_object(vostok::physics::bt_ghost_object *obj@<eax>)
{
  vostok::memory::base_allocator *v1; // ebx
  vostok::physics::bt_collision_shape *m_object; // edi
  _BYTE *v4; // ebp
  vostok::memory::base_allocator *v5; // edi
  _BYTE *v6; // ebx
  vostok::physics::bt_ghost_object *v7; // ecx

  v1 = vostok::physics::g_ph_allocator;
  m_object = obj->m_shape.m_object;
  if ( m_object )
  {
    v4 = __RTCastToVoid((void **)&m_object->__vftable);
    ((void (__thiscall *)(vostok::physics::bt_collision_shape *, _DWORD))m_object->~vostok::resources::resource_base)(
      m_object,
      0);
    v1->call_free(v1, v4);
  }
  v5 = vostok::physics::g_ph_allocator;
  v6 = __RTCastToVoid((void **)&obj->__vftable);
  vostok::physics::bt_ghost_object::~bt_ghost_object(v7, (int)obj);
  v5->call_free(v5, v6);
}
