void __thiscall vostok::render::scene::add_decal(
        vostok::render::scene *this,
        vostok::render::scene *id,
        const vostok::render::decal_properties *properties,
        vostok::render::decal_properties *a4)
{
  int i; // eax
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::decal_instance *v10; // ecx
  vostok::render::decal_instance *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  vostok::render::decal_instance_node *v16; // ecx
  int v17; // eax
  char *v18; // ecx
  const char *v19; // [esp+0h] [ebp-Ch]
  const char *v20; // [esp+0h] [ebp-Ch]
  bool v21; // [esp+0h] [ebp-Ch]
  const char *v22; // [esp+4h] [ebp-8h]
  const char *v23; // [esp+4h] [ebp-8h]
  unsigned int v24; // [esp+8h] [ebp-4h]
  unsigned int v25; // [esp+8h] [ebp-4h]
  vostok::render::decal_instance *decal; // [esp+14h] [ebp+8h]

  for ( i = *(int *)((char *)&dword_8B654C + (_DWORD)id); i; i = *(_DWORD *)(i + 8) )
    ;
  v6 = vostok::render::g_allocator;
  v7 = type_info::raw_name(&vostok::render::decal_instance `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x9Cu, v7, v19, v22, v24);
  if ( v9 )
  {
    vostok::render::decal_instance::decal_instance(
      v10,
      (int)v9,
      *(vostok::collision::space_partitioning_tree **)((char *)&dword_8B9650 + (_DWORD)id),
      a4,
      (const unsigned int)properties);
    decal = v11;
  }
  else
  {
    decal = 0;
  }
  v12 = vostok::render::g_allocator;
  v13 = type_info::raw_name(&vostok::render::decal_instance_node `RTTI Type Descriptor');
  v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v12, 0xCu, v13, v20, v23, v25);
  if ( v15 )
    vostok::render::decal_instance_node::decal_instance_node(v16, (vostok::render::decal_instance **)v15, decal);
  else
    v17 = 0;
  *(_DWORD *)(v17 + 8) = 0;
  v18 = (char *)&dword_8B6544 + (_DWORD)id;
  ++*(int *)((char *)&dword_8B6544 + (_DWORD)id);
  if ( *(int *)((char *)&dword_8B6544 + (_DWORD)id + 8) )
    *(_DWORD *)(*((_DWORD *)v18 + 3) + 8) = v17;
  else
    *((_DWORD *)v18 + 2) = v17;
  *((_DWORD *)v18 + 3) = v17;
  vostok::render::scene::gather_streamable_textures((vostok::render::scene *)decal, id, v21);
}
