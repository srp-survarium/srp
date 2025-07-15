void __thiscall vostok::render::decal_instance::remove_collision(vostok::render::decal_instance *this, int a2)
{
  if ( *(_DWORD *)(a2 + 128) && *(_DWORD *)(a2 + 136) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 128) + 4))(*(_DWORD *)(a2 + 128), *(_DWORD *)(a2 + 136));
  vostok::collision::delete_object(vostok::render::g_allocator, *(vostok::collision::object **)(a2 + 136));
  vostok::collision::delete_geometry_instance(
    vostok::render::g_allocator,
    *(vostok::collision::geometry_instance **)(a2 + 132));
}
