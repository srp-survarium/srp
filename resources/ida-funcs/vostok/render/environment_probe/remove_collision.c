void __thiscall vostok::render::environment_probe::remove_collision(vostok::render::environment_probe *this, int a2)
{
  if ( *(_DWORD *)(a2 + 584) && *(_DWORD *)(a2 + 592) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 584) + 4))(*(_DWORD *)(a2 + 584), *(_DWORD *)(a2 + 592));
  vostok::collision::delete_object(vostok::render::g_allocator, *(vostok::collision::object **)(a2 + 592));
  vostok::collision::delete_geometry_instance(
    vostok::render::g_allocator,
    *(vostok::collision::geometry_instance **)(a2 + 588));
}
