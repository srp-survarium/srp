void __userpurge vostok::render::ui::renderer::draw_vertices(
        vostok::render::ui::renderer *this@<ecx>,
        int *a2@<eax>,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view,
        const vostok::render::ui::vertex *begin,
        const vostok::render::ui::vertex *end,
        unsigned int primitives_type,
        unsigned int points_type)
{
  vostok::render::ui::draw_vertices_command *v8; // esi
  __int32 v9; // eax
  int v10; // edi
  bool v11; // zf

  v8 = (vostok::render::ui::draw_vertices_command *)(*(int (__thiscall **)(int, int))(*(_DWORD *)a2[2] + 16))(
                                                      a2[2],
                                                      116);
  if ( v8 )
    vostok::render::ui::draw_vertices_command::draw_vertices_command(
      v8,
      (vostok::render::engine::world *)a2[1],
      scene_view,
      begin,
      end,
      (vostok::memory::base_allocator *)a2[2],
      primitives_type,
      points_type);
  else
    v9 = 0;
  v10 = *a2;
  v11 = *(_DWORD *)(*(_DWORD *)(v10 + 64) + 4) == 0;
  *(_DWORD *)(v9 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v10 + 4), v9);
  *(_DWORD *)v10 = v9;
  if ( v11 )
    SetEvent(*(HANDLE *)(v10 + 144));
}
