void __cdecl vostok::memory::platform::allocate_arenas(
        unsigned __int64 reserved_memory_size,
        const unsigned __int64 reserved_address_space,
        vostok::buffer_vector<vostok::memory::platform::region> *arenas,
        vostok::memory::platform::region *managed_arena,
        vostok::memory::platform::region *unmanaged_arena)
{
  vostok::command_line::key *v5; // ecx
  char is_set_as; // al
  unsigned __int64 ullTotalPhys; // kr00_8
  unsigned __int64 v8; // kr08_8
  unsigned __int64 v9; // rax
  unsigned int v10; // edi
  int v11; // esi
  unsigned int v12; // edx
  vostok::memory::platform::region *m_begin; // eax
  vostok::memory::platform::region *m_end; // ecx
  unsigned int v15; // esi
  unsigned __int64 v16; // kr10_8
  unsigned int v17; // eax
  vostok::command_line::key *v18; // ecx
  unsigned __int64 v19; // kr18_8
  unsigned int v20; // eax
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rax
  unsigned int v23; // esi
  vostok::command_line::key *v24; // ecx
  unsigned __int64 v25; // rax
  int v26; // ecx
  bool v27; // cf
  vostok::buffer_vector<vostok::memory::platform::region> *v28; // ecx
  vostok::command_line::key *v29; // ecx
  unsigned __int64 v30; // rax
  unsigned __int64 v31; // rax
  unsigned int v32; // edi
  unsigned __int64 v33; // rax
  int v34; // ecx
  vostok::buffer_vector<vostok::memory::platform::region> *v35; // ecx
  vostok::command_line::key *v36; // ecx
  unsigned __int64 v37; // rax
  int v38; // eax
  unsigned __int64 v39; // rax
  unsigned __int64 v40; // rax
  unsigned int size; // ecx
  unsigned int v42; // edi
  unsigned int size_high; // eax
  unsigned int v44; // edx
  _BYTE v45[20]; // [esp-8h] [ebp-1120h]
  _BYTE v46[20]; // [esp-8h] [ebp-1120h]
  _BYTE v47[20]; // [esp-8h] [ebp-1120h]
  unsigned __int64 v48; // [esp+8h] [ebp-1110h]
  char buffer[4096]; // [esp+1Ch] [ebp-10FCh] BYREF
  _BYTE v50[28]; // [esp+101Ch] [ebp-FCh] BYREF
  int v51; // [esp+1038h] [ebp-E0h]
  unsigned __int64 align_on; // [esp+1044h] [ebp-D4h]
  _MEMORYSTATUSEX dst; // [esp+1054h] [ebp-C4h] BYREF
  memory_stats v54; // [esp+1094h] [ebp-84h] BYREF
  unsigned __int64 v55; // [esp+10D4h] [ebp-44h]
  unsigned int v56; // [esp+10DCh] [ebp-3Ch]
  unsigned __int64 v57; // [esp+10E4h] [ebp-34h] BYREF
  __int64 v58; // [esp+10ECh] [ebp-2Ch]
  float v59; // [esp+10F8h] [ebp-20h] BYREF
  unsigned int out_value; // [esp+10FCh] [ebp-1Ch] BYREF
  HRESULT v61; // [esp+1100h] [ebp-18h]
  unsigned int v62[2]; // [esp+1104h] [ebp-14h] BYREF
  unsigned __int64 v63; // [esp+110Ch] [ebp-Ch]

  v61 = CoInitializeEx(0, 2u);
  GetPerformanceInfo((int)v50, 56);
  __FUnloadDelayLoadedDLL2("psapi.dll");
  memset((int)&dst, 0, sizeof(dst));
  dst.dwLength = 64;
  GlobalMemoryStatusEx(&dst);
  is_set_as = vostok::command_line::key::is_set_as_number<unsigned int>(v5, (int)&s_extra_memory, &out_value);
  ullTotalPhys = dst.ullTotalPhys;
  if ( is_set_as )
  {
    v8 = (out_value << 20) + dst.ullTotalPhys;
    dst.ullTotalPhys = v8;
    dst.ullAvailPhys += out_value << 20;
    ullTotalPhys = v8;
  }
  if ( reserved_memory_size >= ullTotalPhys )
    vostok::debug::terminate("Too much memory reserved, not enough memory for engine to proceed.");
  v54.physical_memory = ullTotalPhys
                      - vostok::math::align_up<unsigned __int64>(reserved_memory_size, (unsigned int)align_on);
  LODWORD(v9) = get_minimum_kernel_memory();
  v10 = 0;
  v11 = reserved_address_space;
  v54.current_kernel_memory = vostok::math::max((unsigned int)(align_on * v51) + 0x2000000LL, v9);
  v12 = HIDWORD(reserved_address_space);
  if ( !reserved_address_space && vostok::memory::g_use_resources_manager )
  {
    v11 = 469762048;
    v12 = 0;
  }
  if ( __PAIR64__(v12, v11) >= dst.ullAvailVirtual )
    vostok::debug::terminate("Too much virtual address space reserved, not enough address space for engine to proceed.");
  v54.available_address_space = dst.ullAvailVirtual - __PAIR64__(v12, v11);
  m_begin = arenas->m_begin;
  m_end = arenas->m_end;
  v15 = 0;
  while ( m_begin != m_end )
  {
    v16 = m_begin->size + __PAIR64__(v10, v15);
    v10 = HIDWORD(v16);
    v15 = v16;
    ++m_begin;
  }
  v17 = vostok::threading::core_count(m_end);
  v54.total_available_memory = 0x80000000000LL;
  v54.engine_fixed_memory = __PAIR64__(v10, v15) + ((unsigned __int64)(2 * v17 + 8) << 23);
  v54.does_os_use_process_address_space_for_duplicating_video_resources = vostok::memory::g_use_video_memory;
  if ( vostok::memory::g_use_video_memory )
    v56 = 0x10000000;
  else
    v56 = 0;
  v54.video_memory = v56;
  if ( vostok::command_line::key::is_set(
         (vostok::command_line::key *)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)",
         (int)&s_minimum_resources_memory_size)
    && vostok::command_line::key::is_set_as_number<unsigned __int64>(&s_minimum_resources_memory_size, &v57, v18) )
  {
    v19 = v57;
  }
  else
  {
    v19 = 448;
  }
  v55 = v19 * (unsigned int)&loc_100000;
  v20 = allocation_granularity();
  *(_QWORD *)&v45[12] = v20;
  LODWORD(v57) = v20;
  *(_QWORD *)&v45[4] = v55;
  *(_DWORD *)v45 = 0;
  v21 = calculate_desirable_resource_arenas(&v54, v56, *(const unsigned __int64 *)v45, *(unsigned __int64 *)&v45[8]);
  v22 = vostok::math::align_down<unsigned __int64>(v21, *(unsigned __int64 *)&v45[12]);
  v23 = v22;
  v63 = v22;
  if ( !vostok::command_line::key::is_set_as_number(v24, (int)&s_managed_to_unmanaged_share, &v59) )
    v59 = FLOAT_3_5;
  *(_QWORD *)v62 = v63 & 0x8000000000000000uLL;
  HIDWORD(v58) = HIDWORD(v63) & 0x7FFFFFFF;
  LODWORD(v58) = v23;
  *(float *)&out_value = v59 / (v59 + s_bm_current_air_resistance);
  v25 = vostok::math::align_up<unsigned __int64>(
          (unsigned __int64)((double)__PAIR64__(HIDWORD(v63), v23) * *(float *)&out_value),
          (unsigned int)v57);
  v26 = HIDWORD(v63);
  LODWORD(managed_arena->size) = v25;
  v27 = v23 < LODWORD(managed_arena->size);
  LODWORD(v25) = v23 - LODWORD(managed_arena->size);
  HIDWORD(managed_arena->size) = HIDWORD(v25);
  v28 = (vostok::buffer_vector<vostok::memory::platform::region> *)(v26 - (v27 + HIDWORD(v25)));
  LODWORD(unmanaged_arena->size) = v25;
  HIDWORD(unmanaged_arena->size) = v28;
  if ( try_to_allocate_arenas(managed_arena, v28, arenas, unmanaged_arena, 0) )
  {
    v32 = v63;
  }
  else
  {
    GlobalMemoryStatusEx(&dst);
    if ( vostok::command_line::key::is_set_as_number<unsigned int>(v29, (int)&s_extra_memory, &v62[1]) )
    {
      dst.ullTotalPhys += v62[1] << 20;
      dst.ullAvailPhys += v62[1] << 20;
    }
    v54.total_available_memory = dst.ullAvailPhys + dst.ullAvailPageFile;
    *(_QWORD *)&v46[12] = (unsigned int)v57;
    *(_QWORD *)&v46[4] = v55;
    *(_DWORD *)v46 = 0;
    v30 = calculate_desirable_resource_arenas(&v54, v56, *(const unsigned __int64 *)v46, *(unsigned __int64 *)&v46[8]);
    v31 = vostok::math::align_down<unsigned __int64>(v30, *(unsigned __int64 *)&v46[12]);
    *(_QWORD *)v62 = v31 & 0x8000000000000000uLL;
    HIDWORD(v63) = HIDWORD(v31);
    v32 = v31;
    v58 = v31 & 0x7FFFFFFFFFFFFFFFLL;
    v33 = vostok::math::align_up<unsigned __int64>(
            (unsigned __int64)((double)v31 * *(float *)&out_value),
            (unsigned int)v57);
    v34 = HIDWORD(v63);
    LODWORD(managed_arena->size) = v33;
    v27 = v32 < LODWORD(managed_arena->size);
    LODWORD(v33) = v32 - LODWORD(managed_arena->size);
    HIDWORD(managed_arena->size) = HIDWORD(v33);
    v35 = (vostok::buffer_vector<vostok::memory::platform::region> *)(v34 - (v27 + HIDWORD(v33)));
    LODWORD(unmanaged_arena->size) = v33;
    HIDWORD(unmanaged_arena->size) = v35;
    if ( !try_to_allocate_arenas(managed_arena, v35, arenas, unmanaged_arena, (vostok::memory::platform::region *)1) )
      vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                               "Close all programs, increase paging file size or add memory bank and try again.");
    if ( !vostok::command_line::key::is_set(v36, (int)&s_no_warning_on_page_file_size) )
      MessageBoxA(
        0,
        "You may increase engine performance by closing all programs or increasing page file size and then restarting engine.",
        "Vostok Engine v0.20e",
        0x30u);
  }
  while ( 1 )
  {
    if ( vostok::memory::g_use_video_memory )
    {
      LODWORD(v37) = vostok::platform::get_local_video_memory_size();
      v54.video_memory = v37;
    }
    else
    {
      v54.video_memory = 0;
    }
    if ( !vostok::memory::g_use_video_memory )
      break;
    if ( v54.video_memory )
      goto LABEL_38;
    v38 = MessageBoxA(0, "Cannot detect local video memory size", "Vostok Engine v0.20e", 0x32u) - 3;
    if ( !v38 )
      exit(-1);
    if ( v38 != 1 )
    {
      v54.video_memory = v56;
      sprintf_s<4096>((char (*)[4096])buffer, "Assuming minimum local video memory size: %I64d", (unsigned __int64)v56);
      MessageBoxA(0, buffer, "Vostok Engine v0.20e", 0x40u);
LABEL_38:
      if ( vostok::memory::g_use_video_memory && v54.video_memory < v56 )
        vostok::debug::terminate("Not enough video memory to run Vostok Engine v1.0\r\nUpgrade your video card and try again.");
      break;
    }
  }
  s_video_memory_we_may_use = v54.video_memory_we_may_use;
  if ( vostok::memory::g_use_resources_manager )
  {
    HIDWORD(v58) = HIDWORD(v63);
    *(_QWORD *)&v47[12] = (unsigned int)v57;
    *(_QWORD *)&v47[4] = v55;
    *(_DWORD *)v47 = 0;
    v39 = calculate_desirable_resource_arenas(&v54, v56, *(const unsigned __int64 *)v47, *(unsigned __int64 *)&v47[8]);
    v40 = vostok::math::align_down<unsigned __int64>(v39, *(unsigned __int64 *)&v47[12]);
    s_video_memory_we_may_use = v54.video_memory_we_may_use;
    v63 = v40;
    if ( v40 != __PAIR64__(HIDWORD(v58), v32) )
    {
      size = unmanaged_arena->size;
      v42 = managed_arena->size;
      size_high = HIDWORD(unmanaged_arena->size);
      v44 = (managed_arena->size + unmanaged_arena->size) >> 32;
      LODWORD(v58) = LODWORD(managed_arena->size) + LODWORD(unmanaged_arena->size);
      if ( __PAIR64__(v44, v58) > v63 )
      {
        *(float *)&v48 = v59;
        _LN152(
          managed_arena,
          unmanaged_arena,
          __PAIR64__(HIDWORD(managed_arena->size), v42) + __PAIR64__(size_high, size) - v63,
          (unsigned int)v57,
          v48);
      }
    }
  }
  if ( v61 >= 0 )
    CoUninitialize();
}
