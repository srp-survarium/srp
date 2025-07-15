void __thiscall survarium::ladder_cook::delete_resource(
        survarium::ladder_cook *this,
        survarium::landing_point *resource)
{
  survarium::landing_point *v2; // ebx
  survarium::landing_point *x_low; // eax
  survarium::landing_point *next; // ecx
  vostok::memory::doug_lea_allocator *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  v2 = resource;
  while ( 1 )
  {
    if ( LODWORD(v2[9].m_rotation.x) )
    {
      x_low = (survarium::landing_point *)LODWORD(v2[9].m_rotation.x);
      --LODWORD(v2[9].m_position.y);
      next = x_low->next;
      LODWORD(v2[9].m_rotation.x) = x_low->next;
      if ( !next )
        v2[9].m_rotation.y = 0.0;
      x_low->next = 0;
    }
    else
    {
      x_low = 0;
    }
    resource = x_low;
    if ( !x_low )
      break;
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::landing_point>(
      survarium::g_allocator,
      &resource,
      v7,
      v8,
      v9);
  }
  v5 = survarium::g_allocator;
  if ( v2 )
  {
    resource = (survarium::landing_point *)__RTCastToVoid((void **)&v2->next);
    ((void (__thiscall *)(survarium::landing_point *, _DWORD))v2->next->next)(v2, 0);
    vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)resource, v7, v8, v9);
  }
}
