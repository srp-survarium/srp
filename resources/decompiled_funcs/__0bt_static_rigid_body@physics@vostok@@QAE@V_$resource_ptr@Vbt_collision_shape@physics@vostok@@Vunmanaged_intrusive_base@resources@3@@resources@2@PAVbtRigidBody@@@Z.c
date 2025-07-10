void __userpurge vostok::physics::bt_static_rigid_body::bt_static_rigid_body(
        vostok::physics::bt_static_rigid_body *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> shape,
        btRigidBody *body)
{
  _DWORD *v4; // edi
  _DWORD *v5; // eax

  v4 = a2 + 1;
  v5 = pt3malloc(8u);
  if ( v5 )
  {
    *v5 = v4;
    v5[1] = 0;
  }
  else
  {
    v5 = 0;
  }
  *v4 = v5;
  *(_DWORD *)(*v4 + 4) = v5[1] + 1;
  a2[3] = body;
  a2[2] = 0;
  *a2 = &vostok::physics::bt_static_rigid_body::`vftable';
  a2[4] = 0;
  if ( shape.m_object )
  {
    a2[4] = shape.m_object;
    _InterlockedExchangeAdd(&shape.m_object->m_reference_count, 1u);
  }
  *(_DWORD *)(a2[3] + 248) = a2;
  if ( shape.m_object )
  {
    if ( !_InterlockedExchangeAdd(&shape.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &shape.m_object->vostok::resources::unmanaged_intrusive_base,
        shape.m_object);
  }
}
