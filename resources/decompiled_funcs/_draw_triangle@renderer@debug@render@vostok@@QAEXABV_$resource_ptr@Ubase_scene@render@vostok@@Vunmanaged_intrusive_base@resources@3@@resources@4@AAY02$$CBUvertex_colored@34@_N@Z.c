void __userpurge vostok::render::debug::renderer::draw_triangle(
        vostok::render::debug::renderer *this@<ecx>,
        int a2@<eax>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::render::vertex_colored (*vertices)[3],
        bool use_depth)
{
  int v6; // ecx
  vostok::render::debug::draw_triangles_command *v7; // esi
  __int32 v8; // eax
  int v9; // ecx
  bool v10; // zf
  bool v11; // [esp+0h] [ebp-10h]
  unsigned __int16 indices[3]; // [esp+8h] [ebp-8h] BYREF

  indices[1] = 1;
  v6 = *(_DWORD *)(a2 + 128);
  indices[2] = 2;
  indices[0] = 0;
  v7 = (vostok::render::debug::draw_triangles_command *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 16))(v6, 124);
  if ( v7 )
    vostok::render::debug::draw_triangles_command::draw_triangles_command(
      v7,
      vertices,
      scene,
      *(vostok::render::engine::world **)(a2 + 120),
      *(vostok::memory::base_allocator **)(a2 + 128),
      (const unsigned __int16 (*)[3])indices,
      v11);
  else
    v8 = 0;
  v9 = *(_DWORD *)(a2 + 124);
  v10 = *(_DWORD *)(*(_DWORD *)(v9 + 64) + 4) == 0;
  *(_DWORD *)(v8 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v9 + 4), v8);
  *(_DWORD *)v9 = v8;
  if ( v10 )
    SetEvent(*(HANDLE *)(v9 + 144));
}
