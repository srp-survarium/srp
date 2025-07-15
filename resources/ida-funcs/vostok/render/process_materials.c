void __usercall vostok::render::process_materials(
        const vostok::fixed_string<260> *name_it@<eax>,
        volatile int *waiting_for,
        const vostok::fixed_string<260> *name_end)
{
  vostok::command_line::key *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::fs_new::virtual_path_string material_name; // [esp+Ch] [ebp-114h] BYREF

  while ( name_it != name_end )
  {
    vostok::fixed_string<260>::fixed_string<260>(&material_name.m_string, name_it);
    material_name.m_separator = 47;
    vostok::render::query_material_per_vertex_type(&material_name);
    while ( (unsigned int)s_pending_materials_count >= 0x32 )
    {
      vostok::threading::yield(0xAu);
      vostok::resources::dispatch_callbacks(v5);
    }
    name_it = (const vostok::fixed_string<260> *)((char *)name_it + 140);
  }
  while ( s_pending_materials_count )
  {
    vostok::threading::yield(0xAu);
    vostok::resources::dispatch_callbacks(v6);
  }
  if ( waiting_for )
    _InterlockedExchange(waiting_for, s_pending_materials_count);
}
