void __thiscall vostok::render::ambient_light::remove_collision(vostok::render::ambient_light *this, int a2)
{
  if ( *(_DWORD *)(a2 + 140) && *(_DWORD *)(a2 + 148) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 140) + 4))(*(_DWORD *)(a2 + 140), *(_DWORD *)(a2 + 148));
  vostok::collision::delete_object(vostok::render::g_allocator, *(vostok::collision::object **)(a2 + 148));
  vostok::collision::delete_geometry_instance(
    vostok::render::g_allocator,
    *(vostok::collision::geometry_instance **)(a2 + 144));
}
