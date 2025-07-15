void __thiscall vostok::render::grass_patch::sort_instances(
        vostok::render::grass_patch *this,
        vostok::render::grass_patch::sort_info *view_position)
{
  vostok::render::grass_patch::sort_info *v2; // ebx
  vostok::render::grass_patch::sort_info *v4; // ecx
  vostok::render::grass_patch::sort_info *v5; // eax
  int v6; // eax
  int v7; // edx
  char *v8; // eax
  unsigned int v9; // edi
  char *v10; // esi
  int v11; // esi
  vostok::command_line::key *v12; // ecx
  _BYTE v13[20]; // [esp-10h] [ebp-3Ch]
  unsigned int v14; // [esp+4h] [ebp-28h]
  __int64 v15; // [esp+Ch] [ebp-20h]
  __int64 v16; // [esp+14h] [ebp-18h]
  char *v17; // [esp+1Ch] [ebp-10h]
  vostok::render::grass_patch::sort_info *__first; // [esp+20h] [ebp-Ch]
  unsigned int index_offset; // [esp+24h] [ebp-8h]
  int v20; // [esp+24h] [ebp-8h]

  v2 = view_position;
  index_offset = view_position[826].index_offset;
  v4 = (vostok::render::grass_patch::sort_info *)*((_DWORD *)&view_position[3].position.y + index_offset);
  LODWORD(v15) = view_position;
  HIDWORD(v15) = this->m_movement_rt.m_object;
  this = (vostok::render::grass_patch *)((char *)this + 4);
  LODWORD(v16) = this->m_movement_rt.m_object;
  v5 = &v4[view_position->index_offset - 1];
  HIDWORD(v16) = this->m_movement_texture.m_object;
  view_position = v5;
  if ( v4 != v5 )
  {
    v6 = v5 - v4;
    v7 = 0;
    while ( v6 != 1 )
    {
      ++v7;
      v6 >>= 1;
    }
    *(_QWORD *)v13 = v15;
    *(_QWORD *)&v13[8] = v16;
    stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
      v4,
      view_position,
      0,
      2 * v7,
      *(vostok::render::sort_indices_predicate *)v13);
    *(_QWORD *)v13 = v15;
    *(_QWORD *)&v13[8] = v16;
    stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
      view_position,
      *(vostok::render::grass_patch::sort_info *)v13);
  }
  v8 = type_info::raw_name(&unsigned short `RTTI Type Descriptor');
  v9 = index_offset;
  v10 = vostok::memory::pthreads3_allocator::malloc_impl(
          (vostok::memory::pthreads3_allocator *)(2 * *(&v2[827].index_offset + index_offset)),
          (int)&vostok::memory::g_mt_allocator,
          (const char *const)(2 * *(&v2[827].index_offset + index_offset)),
          v8,
          *(const char *const *)&v13[16],
          v14);
  v17 = v10;
  view_position = (vostok::render::grass_patch::sort_info *)v10;
  __first = 0;
  if ( v2->index_offset )
  {
    v20 = 0;
    do
    {
      v11 = v20 + *((_DWORD *)&v2[3].position.y + v9);
      memcpy(
        (unsigned __int8 *)view_position,
        (unsigned __int8 *)(*(&v2[2].index_offset + v9) + 2 * *(_DWORD *)(v11 + 12)),
        2 * *(_DWORD *)(v11 + 16));
      v20 += 20;
      __first = (vostok::render::grass_patch::sort_info *)((char *)__first + 1);
      view_position = (vostok::render::grass_patch::sort_info *)((char *)view_position + 2 * *(_DWORD *)(v11 + 16));
    }
    while ( (unsigned int)__first < v2->index_offset );
    v10 = v17;
  }
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->UpdateSubresource(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    *(ID3D11Resource **)(*(_DWORD *)(*((_DWORD *)&v2[1].position.z + v9) + 8) + 16),
    0,
    0,
    v10,
    0,
    0);
  if ( v10 )
  {
    view_position = (vostok::render::grass_patch::sort_info *)v10;
    if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
      vostok::memory::monitor::on_free((void **)&view_position, v12);
    pt3free((int)v12, (char *)view_position);
  }
}
