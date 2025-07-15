void __thiscall vostok::render::light::remove_collision(vostok::render::light *this, int a2)
{
  int v2; // ecx

  if ( *(_DWORD *)(a2 + 696) )
  {
    v2 = *(_DWORD *)(a2 + 688);
    if ( v2 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 4))(v2, *(_DWORD *)(a2 + 696));
    vostok::collision::delete_object(vostok::render::g_allocator, *(vostok::collision::object **)(a2 + 696));
    vostok::collision::delete_geometry_instance(
      vostok::render::g_allocator,
      *(vostok::collision::geometry_instance **)(a2 + 692));
    *(_DWORD *)(a2 + 696) = 0;
    *(_DWORD *)(a2 + 692) = 0;
  }
}
