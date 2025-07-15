void __usercall vostok::physics::destroy_animated_compound_shape(
        vostok::memory::base_allocator *allocator@<eax>,
        btCompoundShape *shape)
{
  int v3; // ebx
  btCollisionShape *v4; // esi
  btCollisionShape *m_childShape; // ebx
  _BYTE *v6; // esi
  btCollisionShape *inptr; // [esp+Ch] [ebp-10h]
  _BYTE *inptra; // [esp+Ch] [ebp-10h]
  btCompoundShape *pointer; // [esp+10h] [ebp-Ch] BYREF
  int v10; // [esp+14h] [ebp-8h]
  unsigned int v11; // [esp+18h] [ebp-4h]

  v3 = shape->m_children.m_size - 1;
  if ( shape->m_children.m_size != 1 )
  {
    v11 = 0;
    v10 = v3;
    do
    {
      pointer = (btCompoundShape *)shape->m_children.m_data[v11 / 0x50].m_childShape;
      inptr = pointer->m_children.m_data->m_childShape;
      vostok::memory::delete_helper<vostok::memory::base_allocator,btCompoundShape>(
        allocator,
        &pointer,
        (const char *const)0x90);
      v4 = inptr;
      if ( inptr )
      {
        inptra = __RTCastToVoid((void **)&inptr->__vftable);
        ((void (__thiscall *)(btCollisionShape *, _DWORD))v4->~btCollisionShape)(v4, 0);
        allocator->call_free(
          allocator,
          inptra,
          "vostok::physics::destroy_animated_compound_shape",
          ".\\animated_rigid_body.cpp",
          145u);
      }
      v11 += 80;
      --v10;
    }
    while ( v10 );
  }
  m_childShape = shape->m_children.m_data[v3].m_childShape;
  vostok::memory::delete_helper<vostok::memory::base_allocator,btCompoundShape>(
    allocator,
    &shape,
    (const char *const)0x94);
  if ( m_childShape )
  {
    v6 = __RTCastToVoid((void **)&m_childShape->__vftable);
    ((void (__thiscall *)(btCollisionShape *, _DWORD))m_childShape->~btCollisionShape)(m_childShape, 0);
    allocator->call_free(
      allocator,
      v6,
      "vostok::physics::destroy_animated_compound_shape",
      ".\\animated_rigid_body.cpp",
      149u);
  }
}
