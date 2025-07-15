void __cdecl vostok::memory::platform::allocate_arenas(
        unsigned __int64 reserved_memory_size,
        const unsigned __int64 reserved_address_space,
        vostok::buffer_vector<vostok::memory::platform::region> *arenas,
        vostok::memory::platform::region *managed_arena,
        vostok::memory::platform::region *unmanaged_arena)
{
  unsigned int v5; // edi
  unsigned __int64 v6; // rax
  unsigned int v7; // esi
  unsigned __int64 minimum_kernel_memory; // rax
  unsigned int v9; // ebx
  unsigned int v10; // esi
  unsigned int ullAvailVirtual; // eax
  vostok::memory::platform::region *m_begin; // eax
  vostok::memory::platform::region *m_end; // ecx
  unsigned __int64 v14; // kr10_8
  __int64 v15; // rax
  __int64 v16; // kr18_8
  unsigned int dwAllocationGranularity; // ebx
  unsigned __int64 v18; // rax
  __int64 v19; // rdi
  unsigned __int64 v20; // kr20_8
  unsigned __int64 v21; // rax
  unsigned int v22; // ebp
  unsigned int v23; // esi
  unsigned __int64 v24; // rax
  unsigned int v25; // edx
  bool v26; // cf
  unsigned int v27; // edx
  int v28; // esi
  unsigned __int64 v29; // rax
  unsigned int v30; // edi
  unsigned int v31; // esi
  unsigned __int64 v32; // rax
  unsigned int v33; // edx
  unsigned int v34; // edx
  int v35; // esi
  int (__stdcall *v36)(HWND, LPCSTR, LPCSTR, UINT); // ebp
  unsigned __int64 local_video_memory_size; // rax
  unsigned __int64 v38; // rdi
  HWND v39; // edx
  int v40; // eax
  unsigned int v41; // ebp
  unsigned __int64 v42; // rax
  __int64 v43; // rdi
  unsigned int size; // eax
  unsigned int size_high; // ecx
  unsigned int v46; // ebp
  __int128 v47; // [esp-Ch] [ebp-111Ch]
  __int128 v48; // [esp-Ch] [ebp-111Ch]
  vostok::command_line::key_initializator predicate[8]; // [esp+10h] [ebp-1100h] BYREF
  unsigned __int64 v50; // [esp+18h] [ebp-10F8h]
  HRESULT v51; // [esp+24h] [ebp-10ECh]
  __int64 v52; // [esp+28h] [ebp-10E8h]
  unsigned int minimum_resources_size_4; // [esp+30h] [ebp-10E0h]
  memory_stats stats; // [esp+38h] [ebp-10D8h] BYREF
  _MEMORYSTATUSEX dst; // [esp+70h] [ebp-10A0h] BYREF
  char v56[28]; // [esp+B4h] [ebp-105Ch] BYREF
  int v57; // [esp+D0h] [ebp-1040h]
  unsigned int v58; // [esp+DCh] [ebp-1034h]
  _SYSTEM_INFO SystemInfo; // [esp+ECh] [ebp-1024h] BYREF
  char buffer[4096]; // [esp+110h] [ebp-1000h] BYREF

  v51 = CoInitializeEx(0, 2u);
  GetPerformanceInfo((int)v56, 56);
  __FUnloadDelayLoadedDLL2("psapi.dll");
  memset((int)&dst, 0, sizeof(dst));
  dst.dwLength = 64;
  GlobalMemoryStatusEx(&dst);
  v5 = HIDWORD(reserved_memory_size);
  if ( reserved_memory_size >= dst.ullTotalPhys )
    vostok::debug::terminate("Too much memory reserved, not enough memory for engine to proceed.");
  v6 = reserved_memory_size % v58;
  if ( v6 )
  {
    v7 = reserved_memory_size + v58 - v6;
    v5 = (reserved_memory_size + v58 - v6) >> 32;
  }
  else
  {
    v7 = reserved_memory_size;
  }
  stats.physical_memory = dst.ullTotalPhys - __PAIR64__(v5, v7);
  minimum_kernel_memory = get_minimum_kernel_memory();
  *(_DWORD *)predicate = (v58 * v57 - minimum_kernel_memory) >> 32;
  v9 = HIDWORD(reserved_address_space);
  v10 = reserved_address_space;
  stats.current_kernel_memory = v58 * v57 - (v58 * v57 < minimum_kernel_memory ? v58 * v57 - minimum_kernel_memory : 0);
  if ( !reserved_address_space && vostok::memory::g_use_resources_manager )
  {
    v10 = 0x8000000;
    v9 = 0;
  }
  if ( v9 < HIDWORD(dst.ullAvailVirtual) )
  {
    ullAvailVirtual = dst.ullAvailVirtual;
  }
  else if ( v9 > HIDWORD(dst.ullAvailVirtual)
         || (ullAvailVirtual = dst.ullAvailVirtual, v10 >= LODWORD(dst.ullAvailVirtual)) )
  {
    vostok::debug::terminate("Too much virtual address space reserved, not enough address space for engine to proceed.");
  }
  stats.available_address_space = __PAIR64__(HIDWORD(dst.ullAvailVirtual), ullAvailVirtual) - __PAIR64__(v9, v10);
  m_begin = arenas->m_begin;
  m_end = arenas->m_end;
  v14 = 0;
  if ( arenas->m_begin != m_end )
  {
    do
    {
      v14 += m_begin->size;
      ++m_begin;
    }
    while ( m_begin != m_end );
  }
  stats.engine_fixed_memory = v14;
  stats.does_os_use_process_address_space_for_duplicating_video_resources = vostok::memory::g_use_video_memory;
  stats.total_available_memory = 0x80000000000LL;
  minimum_resources_size_4 = 0x10000000;
  if ( !vostok::memory::g_use_video_memory )
    minimum_resources_size_4 = 0;
  stats.video_memory = minimum_resources_size_4;
  if ( s_minimum_resources_memory_size.m_type == type_unset )
  {
    predicate[0] = 0;
    s_minimum_resources_memory_size.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_minimum_resources_memory_size.m_type == type_recursive
    || (*(_DWORD *)predicate = 0,
        !vostok::command_line::key::is_set_as_number(&s_minimum_resources_memory_size, (float *)predicate)) )
  {
    v15 = 128;
  }
  else
  {
    v15 = *(_DWORD *)predicate;
  }
  v16 = v15 * ((unsigned int)&loc_FFFFF + 1);
  v52 = v16;
  GetSystemInfo(&SystemInfo);
  dwAllocationGranularity = SystemInfo.dwAllocationGranularity;
  *(_QWORD *)((char *)&v47 + 4) = v16;
  LODWORD(v47) = 0;
  v18 = calculate_desirable_resource_arenas(&stats, minimum_resources_size_4, v47, *((unsigned __int64 *)&v47 + 1));
  v20 = v18 - v18 % dwAllocationGranularity;
  HIBYTE(v19) = HIBYTE(v20);
  *(_QWORD *)predicate = v19 & 0x8000000000000000uLL;
  v50 = v20;
  v21 = (unsigned __int64)((double)v20 * 0.66666669);
  v22 = HIDWORD(v21);
  v23 = v21;
  v24 = v21 % dwAllocationGranularity;
  if ( v24 )
  {
    v22 = (dwAllocationGranularity + __PAIR64__(v22, v23) - v24) >> 32;
    v23 = dwAllocationGranularity + v23 - v24;
  }
  v25 = v50;
  LODWORD(managed_arena->size) = v23;
  v26 = v25 < v23;
  v27 = v25 - v23;
  v28 = HIDWORD(v50);
  HIDWORD(managed_arena->size) = v22;
  LODWORD(unmanaged_arena->size) = v27;
  HIDWORD(unmanaged_arena->size) = v28 - (v26 + v22);
  if ( try_to_allocate_arenas_0(arenas, managed_arena, unmanaged_arena, 0) )
  {
    v36 = MessageBoxA;
  }
  else
  {
    GlobalMemoryStatusEx(&dst);
    stats.total_available_memory = dst.ullAvailPageFile;
    *(_QWORD *)((char *)&v48 + 4) = v52;
    LODWORD(v48) = 0;
    v29 = calculate_desirable_resource_arenas(&stats, minimum_resources_size_4, v48, *((unsigned __int64 *)&v48 + 1));
    *(_QWORD *)predicate = (v29 - v29 % dwAllocationGranularity) & 0x8000000000000000uLL;
    v50 = v29 - v29 % dwAllocationGranularity;
    v30 = (unsigned __int64)((double)v50 * 0.66666669) >> 32;
    v31 = (unsigned __int64)((double)v50 * 0.66666669);
    v32 = (unsigned __int64)((double)v50 * 0.66666669) % dwAllocationGranularity;
    if ( v32 )
    {
      v30 = (dwAllocationGranularity + __PAIR64__(v30, v31) - v32) >> 32;
      v31 = dwAllocationGranularity + v31 - v32;
    }
    v33 = v50;
    LODWORD(managed_arena->size) = v31;
    v26 = v33 < v31;
    v34 = v33 - v31;
    v35 = HIDWORD(v50);
    HIDWORD(managed_arena->size) = v30;
    HIDWORD(unmanaged_arena->size) = v35 - (v26 + v30);
    LODWORD(unmanaged_arena->size) = v34;
    if ( !try_to_allocate_arenas_0(arenas, managed_arena, unmanaged_arena, (vostok::memory::platform::region *)1) )
      vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                               "Close all programs, increase paging file size or add memory bank and try again.");
    if ( s_no_warning_on_page_file_size.m_type == type_unset )
    {
      predicate[0] = 0;
      s_no_warning_on_page_file_size.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    v36 = MessageBoxA;
    if ( s_no_warning_on_page_file_size.m_type == type_recursive )
      MessageBoxA(
        0,
        "You may increase engine performance by closing all programs or increasing page file size and then restarting engine.",
        "Vostok Engine v0.1",
        0x30u);
  }
  while ( 1 )
  {
    if ( !vostok::memory::g_use_video_memory )
    {
      stats.video_memory = 0;
      goto LABEL_45;
    }
    local_video_memory_size = vostok::platform::get_local_video_memory_size();
    v38 = local_video_memory_size;
    stats.video_memory = local_video_memory_size;
    if ( !vostok::memory::g_use_video_memory )
      goto LABEL_45;
    v39 = (HWND)(HIDWORD(local_video_memory_size) | local_video_memory_size);
    if ( v38 )
      break;
    v40 = v36(v39, "Cannot detect local video memory size", "Vostok Engine v0.1", 0x32u) - 3;
    if ( !v40 )
      exit(-1);
    if ( v40 != 1 )
    {
      v38 = minimum_resources_size_4;
      stats.video_memory = minimum_resources_size_4;
      vostok::sprintf<4096>(
        (char (*)[4096])buffer,
        "Assuming minimum local video memory size: %I64d",
        (unsigned __int64)minimum_resources_size_4);
      v36(0, buffer, "Vostok Engine v0.1", 0x40u);
      break;
    }
  }
  if ( vostok::memory::g_use_video_memory && v38 < minimum_resources_size_4 )
    vostok::debug::terminate("Not enough video memory to run Vostok Engine v1.0\r\n"
                             "Upgrade your video card and try again.");
LABEL_45:
  if ( vostok::memory::g_use_resources_manager )
  {
    v41 = v50;
    *(_QWORD *)((char *)&v48 + 4) = v52;
    LODWORD(v48) = 0;
    v42 = calculate_desirable_resource_arenas(&stats, minimum_resources_size_4, v48, *((unsigned __int64 *)&v48 + 1));
    LODWORD(v43) = (v42 - v42 % dwAllocationGranularity) >> 32;
    HIDWORD(v43) = v42 - v42 % dwAllocationGranularity;
    if ( v43 != __PAIR64__(v41, HIDWORD(v50)) )
    {
      size = unmanaged_arena->size;
      size_high = HIDWORD(unmanaged_arena->size);
      v26 = __CFADD__(managed_arena->size, unmanaged_arena->size);
      v46 = HIDWORD(managed_arena->size);
      LODWORD(v52) = LODWORD(managed_arena->size) + LODWORD(unmanaged_arena->size);
      if ( __PAIR64__(v46 + v26 + size_high, v52) > __PAIR64__(v43, HIDWORD(v43)) )
        reduce_resources_arenas(
          managed_arena,
          unmanaged_arena,
          __PAIR64__(v46, managed_arena->size) + __PAIR64__(size_high, size) - __PAIR64__(v43, HIDWORD(v43)),
          dwAllocationGranularity);
    }
  }
  if ( v51 >= 0 )
    CoUninitialize();
}
