bool __cdecl allocate_arenas(
        vostok::memory::platform::region *arenas,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas,
        char *start_address,
        vostok::memory::platform::region *only_resources)
{
  stlp_std::less<vostok::memory::platform::region> v4; // cl
  vostok::buffer_vector<vostok::memory::platform::region> *v5; // ebx
  vostok::memory::platform::region *i; // ecx
  vostok::memory::platform::region *m_end; // eax
  int size; // edx
  vostok::memory::platform::region *v9; // eax
  unsigned int v10; // esi
  unsigned int size_high; // edi
  int v12; // edi
  void *v13; // esp
  void *v14; // esp
  stlp_std::less<vostok::memory::platform::region> v15; // cl
  stlp_std::less<vostok::memory::platform::region> v16; // cl
  vostok::memory::platform::region *v17; // eax
  vostok::memory::platform::region *m_begin; // ecx
  unsigned __int64 v19; // xmm0_8
  __int64 v20; // xmm1_8
  vostok::buffer_vector<vostok::memory::platform::region> *v21; // eax
  vostok::memory::platform::region *v22; // ecx
  vostok::memory::platform::region *v23; // ebx
  unsigned __int64 v24; // rax
  __int64 v25; // rax
  vostok::memory::platform::region *v26; // edi
  vostok::memory::platform::region *v27; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *p_high_memory_regions; // esi
  unsigned int v29; // ecx
  unsigned int v30; // eax
  SIZE_T v31; // ecx
  void *address; // eax
  bool v33; // cf
  __int64 v34; // xmm0_8
  vostok::memory::platform::region *v35; // eax
  vostok::memory::platform::region *v36; // eax
  vostok::memory::platform::region *v37; // esi
  vostok::memory::platform::region *v38; // edi
  int v39; // ecx
  int j; // edx
  vostok::memory::platform::region *v41; // edi
  vostok::memory::platform::region *v42; // esi
  __int64 v43; // rcx
  unsigned int v44; // edx
  vostok::memory::platform::region *v45; // edi
  regions_filler v46; // kr18_8
  vostok::memory::platform::region *v47; // ebx
  SIZE_T v48; // ecx
  int v49; // edx
  void **p_address; // ebx
  void *v51; // eax
  LPVOID v52; // eax
  bool result; // al
  SIZE_T v54; // ecx
  char *v55; // eax
  LPVOID v56; // eax
  unsigned __int64 v57; // kr04_8
  double v58; // st7
  SIZE_T v59; // ecx
  unsigned int v60; // edx
  unsigned int v61; // kr14_4
  unsigned int v62; // edx
  SIZE_T v63; // eax
  void *v64; // ebx
  LPVOID v65; // eax
  LPVOID region; // eax
  unsigned int v67; // eax
  int v68; // eax
  LPVOID v69; // eax
  char *v70; // eax
  unsigned __int64 v71; // rax
  LPVOID v72; // eax
  unsigned __int64 v73; // rax
  LPVOID v74; // eax
  unsigned int v75; // ecx
  unsigned int v76; // eax
  void *v77; // eax
  LPVOID v78; // eax
  unsigned __int64 v79; // rax
  unsigned int v80; // ecx
  unsigned __int64 v81; // kr50_8
  vostok::buffer_vector<vostok::memory::platform::region> *v82; // ecx
  vostok::memory::platform::region *v83; // eax
  SIZE_T v84; // ecx
  LPVOID v85; // eax
  char *v86; // eax
  SIZE_T v87; // ecx
  unsigned __int64 v88; // [esp-18h] [ebp-A0h]
  unsigned __int64 v89; // [esp-10h] [ebp-98h]
  unsigned __int64 dwAllocationGranularity; // [esp-8h] [ebp-90h]
  const vostok::memory::platform::region *v91[3]; // [esp+0h] [ebp-88h] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+Ch] [ebp-7Ch] BYREF
  vostok::memory::platform::region temp; // [esp+30h] [ebp-58h] BYREF
  unsigned __int64 min_buffer_size; // [esp+40h] [ebp-48h]
  vostok::buffer_vector<vostok::memory::platform::region> high_memory_regions; // [esp+48h] [ebp-40h] BYREF
  vostok::buffer_vector<vostok::memory::platform::region> regions; // [esp+50h] [ebp-38h] BYREF
  regions_filler filler; // [esp+58h] [ebp-30h] BYREF
  stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region> v98[8]; // [esp+60h] [ebp-28h]
  vostok::memory::platform::region *k; // [esp+6Ch] [ebp-1Ch] BYREF
  unsigned __int64 v100; // [esp+70h] [ebp-18h]
  stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region> __comp1[4]; // [esp+78h] [ebp-10h]
  stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region> __comp2[4]; // [esp+7Ch] [ebp-Ch]
  stlp_std::reverse_iterator<vostok::memory::platform::region *> e; // [esp+80h] [ebp-8h]
  vostok::memory::platform::region *regions_b; // [esp+84h] [ebp-4h]

  v5 = (vostok::buffer_vector<vostok::memory::platform::region> *)arenas;
  stlp_std::sort<vostok::memory::platform::region *>(
    (vostok::memory::platform::region *)arenas->size,
    (vostok::memory::platform::region *)HIDWORD(arenas->size),
    v4);
  stlp_std::priv::__reverse<vostok::memory::platform::region *>(v5->m_begin, v5->m_end);
  for ( i = v5->m_begin; i != v5->m_end; v5->m_end = v9 )
  {
    m_end = v5->m_end;
    size = m_end[-1].size;
    v9 = m_end - 1;
    if ( HIDWORD(v9->size) | size )
      break;
  }
  stlp_std::priv::__reverse<vostok::memory::platform::region *>(i, v5->m_end);
  v10 = v5->m_begin->size;
  size_high = HIDWORD(v5->m_begin->size);
  arenas = 0;
  min_buffer_size = __PAIR64__(size_high, v10);
  GetSystemInfo(&SystemInfo);
  iterate_regions<regions_count>(
    start_address,
    SystemInfo.dwAllocationGranularity,
    __PAIR64__(size_high, v10),
    (regions_count *)&arenas);
  v12 = 16 * ((_DWORD)&arenas->size + 1);
  v13 = alloca(v12);
  regions.m_begin = (vostok::memory::platform::region *)v91;
  regions.m_end = (vostok::memory::platform::region *)v91;
  v14 = alloca(v12);
  high_memory_regions.m_begin = (vostok::memory::platform::region *)v91;
  high_memory_regions.m_end = (vostok::memory::platform::region *)v91;
  filler.m_regions = &regions;
  filler.m_high_memory_regions = &high_memory_regions;
  iterate_regions<regions_filler>(
    (const unsigned int)start_address,
    SystemInfo.dwAllocationGranularity,
    __PAIR64__(HIDWORD(min_buffer_size), v10),
    &filler);
  stlp_std::sort<vostok::memory::platform::region *>(regions.m_begin, regions.m_end, v15);
  stlp_std::sort<vostok::memory::platform::region *>(high_memory_regions.m_begin, high_memory_regions.m_end, v16);
  if ( vostok::memory::g_use_resources_manager )
  {
    v17 = resource_arenas->m_end;
    m_begin = resource_arenas->m_begin;
    if ( resource_arenas->m_begin->size > v17[-1].size )
    {
      v19 = m_begin->size;
      v20 = *(_QWORD *)&m_begin->address;
      m_begin->size = v17[-1].size;
      *(_QWORD *)&m_begin->address = *(_QWORD *)&v17[-1].address;
      v17[-1].size = v19;
      *(_QWORD *)&v17[-1].address = v20;
    }
  }
  v21 = (vostok::buffer_vector<vostok::memory::platform::region> *)v5->m_end;
  v22 = v5->m_begin;
  arenas = (vostok::memory::platform::region *)v21;
  e.current = v22;
  if ( !(_BYTE)only_resources && v21 != (vostok::buffer_vector<vostok::memory::platform::region> *)v22 )
  {
    v23 = (vostok::memory::platform::region *)&v21[-2];
    do
    {
      v24 = (v23->size - 1) / SystemInfo.dwAllocationGranularity;
      LODWORD(v89) = v24 + 1;
      v25 = (v24 + 1) * SystemInfo.dwAllocationGranularity;
      HIDWORD(v23->size) = HIDWORD(v25);
      __comp2[0] = 0;
      HIDWORD(dwAllocationGranularity) = *(_DWORD *)__comp2;
      LODWORD(v23->size) = v25;
      v26 = high_memory_regions.m_end;
      __comp1[0] = 0;
      LODWORD(dwAllocationGranularity) = *(_DWORD *)__comp1;
      regions_b = high_memory_regions.m_begin;
      v27 = stlp_std::priv::__lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region,stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region>,stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region>,int>(
              high_memory_regions.m_begin,
              v23,
              high_memory_regions.m_end);
      only_resources = v27;
      p_high_memory_regions = &high_memory_regions;
      if ( v27 == v26 || v27->size < v23->size )
      {
        v26 = regions.m_end;
        BYTE4(v100) = 0;
        LOBYTE(v100) = 0;
        dwAllocationGranularity = v100;
        regions_b = regions.m_begin;
        v27 = stlp_std::priv::__lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region,stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region>,stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region>,int>(
                regions.m_begin,
                v23,
                regions.m_end);
        only_resources = v27;
        p_high_memory_regions = &regions;
      }
      if ( !vostok::memory::g_use_resources_manager )
      {
        k = v27 + 1;
        if ( &v27[1] != v26 && &v27[2] == v26 )
        {
          if ( v27 == regions_b )
          {
            v29 = 0;
            v30 = 0;
          }
          else
          {
            v29 = v27[-1].size;
            v30 = HIDWORD(v27[-1].size);
          }
          dwAllocationGranularity = __PAIR64__(SystemInfo.dwAllocationGranularity, (unsigned int)resource_arenas);
          v27 = *select_best_region_0(
                   __PAIR64__(v30, v29),
                   &only_resources,
                   &k,
                   v23->size,
                   resource_arenas,
                   SystemInfo.dwAllocationGranularity);
          only_resources = v27;
        }
      }
      v31 = v23->size;
      address = v27->address;
      k = (vostok::memory::platform::region *)HIDWORD(v23->size);
      v23->address = VirtualAlloc(address, v31, 0x3000u, 4u);
      only_resources->address = (char *)only_resources->address + LODWORD(v23->size);
      v33 = LODWORD(only_resources->size) < LODWORD(v23->size);
      LODWORD(only_resources->size) -= LODWORD(v23->size);
      HIDWORD(only_resources->size) -= v33 + HIDWORD(v23->size);
      if ( only_resources == p_high_memory_regions->m_begin )
      {
        if ( only_resources->size < min_buffer_size )
        {
          k = only_resources + 1;
          vostok::buffer_vector<vostok::memory::platform::region>::erase(p_high_memory_regions, &only_resources, &k);
        }
      }
      else if ( only_resources->size < only_resources[-1].size )
      {
        temp.size = only_resources->size;
        v34 = *(_QWORD *)&only_resources->address;
        k = only_resources + 1;
        *(_QWORD *)&temp.address = v34;
        vostok::buffer_vector<vostok::memory::platform::region>::erase(p_high_memory_regions, &only_resources, &k);
        if ( temp.size >= min_buffer_size )
        {
          v35 = p_high_memory_regions->m_end;
          v98[4] = 0;
          LOBYTE(filler.m_high_memory_regions) = 0;
          dwAllocationGranularity = __PAIR64__(*(unsigned int *)&v98[4], (unsigned int)filler.m_high_memory_regions);
          k = stlp_std::priv::__lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region,stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region>,stlp_std::priv::__less_2<vostok::memory::platform::region,vostok::memory::platform::region>,int>(
                p_high_memory_regions->m_begin,
                &temp,
                v35);
          vostok::buffer_vector<vostok::memory::platform::region>::insert(p_high_memory_regions, &k, &temp, v91[0]);
        }
      }
      --v23;
      --arenas;
    }
    while ( arenas != e.current );
  }
  if ( !vostok::memory::g_use_resources_manager )
    return 1;
  arenas = high_memory_regions.m_end;
  only_resources = regions.m_end;
  vostok::buffer_vector<vostok::memory::platform::region>::insert<vostok::memory::platform::region *>(
    high_memory_regions.m_begin,
    &arenas,
    &regions,
    &only_resources);
  v36 = regions.m_end;
  v37 = regions.m_begin;
  v38 = regions.m_end;
  if ( regions.m_begin != regions.m_end )
  {
    v39 = regions.m_end - regions.m_begin;
    for ( j = 0; v39 != 1; ++j )
      v39 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::memory::platform::region *,vostok::memory::platform::region,int,stlp_std::less<vostok::memory::platform::region>>(
      regions.m_begin,
      regions.m_end,
      0,
      2 * j,
      only_resources);
    if ( (int)(((char *)v38 - (char *)v37) & 0xFFFFFFF0) <= 256 )
    {
      stlp_std::priv::__insertion_sort<vostok::memory::platform::region *,vostok::memory::platform::region,stlp_std::less<vostok::memory::platform::region>>(
        v37,
        v38,
        only_resources);
    }
    else
    {
      stlp_std::priv::__insertion_sort<vostok::memory::platform::region *,vostok::memory::platform::region,stlp_std::less<vostok::memory::platform::region>>(
        v37,
        v37 + 16,
        only_resources);
      stlp_std::priv::__unguarded_insertion_sort_aux<vostok::memory::platform::region *,vostok::memory::platform::region,stlp_std::less<vostok::memory::platform::region>>(
        v37 + 16,
        v38,
        only_resources);
    }
    v36 = regions.m_end;
  }
  v41 = resource_arenas->m_end;
  v42 = resource_arenas->m_begin;
  LODWORD(v43) = v41[-1].size;
  v44 = resource_arenas->m_begin->size;
  HIDWORD(v43) = HIDWORD(resource_arenas->m_begin->size);
  v45 = v41 - 1;
  LODWORD(min_buffer_size) = v43;
  HIDWORD(min_buffer_size) = HIDWORD(v45->size);
  v46 = (regions_filler)(__PAIR64__(HIDWORD(min_buffer_size), v44) + v43);
  v47 = v36 - 1;
  arenas = v36;
  *(regions_filler *)v98 = v46;
  filler = v46;
  if ( v36[-1].size < *(_QWORD *)&v46 )
  {
    HIDWORD(v57) = HIDWORD(v42->size);
    LODWORD(min_buffer_size) = v42->size;
    LODWORD(v57) = min_buffer_size;
    min_buffer_size = *(_QWORD *)v98 & 0x8000000000000000uLL;
    v58 = (double)v57 / (double)*(unsigned __int64 *)v98;
    if ( (((char *)v36 - (char *)regions.m_begin) & 0xFFFFFFF0) == 0x10
      || (v59 = v36[-2].size,
          HIDWORD(min_buffer_size) = HIDWORD(v36[-2].size),
          *(_DWORD *)v98 = v47->size,
          v60 = HIDWORD(v47->size),
          v61 = *(_DWORD *)v98,
          *(_QWORD *)v98 = min_buffer_size & 0x8000000000000000uLL,
          (double)__PAIR64__(v60, v61) * v58 >= (double)__PAIR64__(HIDWORD(min_buffer_size), v59)) )
    {
      LODWORD(min_buffer_size) = v47->size;
      v80 = HIDWORD(v47->size);
      dwAllocationGranularity = SystemInfo.dwAllocationGranularity;
      v89 = (unsigned __int64)(v58 * (double)__PAIR64__(v80, min_buffer_size));
      min_buffer_size = v89;
      v81 = v89 - v89 % SystemInfo.dwAllocationGranularity;
      v42->size = v81;
      v82 = (vostok::buffer_vector<vostok::memory::platform::region> *)arenas;
      v45->size = v47->size - __PAIR64__(HIDWORD(v42->size), v81);
      v83 = v82[-1].m_begin;
      v84 = v42->size;
      HIDWORD(min_buffer_size) = HIDWORD(v42->size);
      v85 = VirtualAlloc(v83, v84, 0x3000u, 4u);
      v42->address = v85;
      if ( !v85 )
        return 0;
      v86 = (char *)arenas[-1].address + LODWORD(v42->size);
      v87 = v45->size;
      HIDWORD(min_buffer_size) = HIDWORD(v45->size);
      v56 = VirtualAlloc(v86, v87, 0x3000u, 4u);
      goto LABEL_59;
    }
    if ( v47->size < v45->size )
    {
      v62 = HIDWORD(min_buffer_size);
    }
    else
    {
      v62 = HIDWORD(min_buffer_size);
      if ( __PAIR64__(HIDWORD(min_buffer_size), v59) >= v42->size )
      {
        v63 = v42->size;
        v64 = v47[-1].address;
        HIDWORD(min_buffer_size) = HIDWORD(v42->size);
        v65 = VirtualAlloc(v64, v63, 0x3000u, 4u);
        v42->address = v65;
        if ( !v65 )
          return 0;
        region = allocate_region(v45->size);
        v45->address = region;
        if ( region )
          return 1;
        dwAllocationGranularity = v42->size;
        goto LABEL_61;
      }
    }
    v67 = (__PAIR64__(v62, v59) + v47->size) >> 32;
    *(_DWORD *)v98 = v59 + LODWORD(v47->size);
    if ( __PAIR64__(v67, *(unsigned int *)v98) < *(_QWORD *)&filler )
    {
      dwAllocationGranularity = 0x400003000LL;
      LODWORD(v42->size) = v59;
      HIDWORD(v42->size) = v62;
      v77 = v47[-1].address;
      HIDWORD(min_buffer_size) = v62;
      v78 = VirtualAlloc(v77, v59, dwAllocationGranularity, HIDWORD(dwAllocationGranularity));
      v42->address = v78;
      if ( !v78 )
        return 0;
      LODWORD(v79) = v47->size;
      LODWORD(v45->size) = v47->size;
      HIDWORD(v79) = HIDWORD(v47->size);
      HIDWORD(v45->size) = HIDWORD(v79);
      v72 = allocate_region(v79);
    }
    else
    {
      if ( v47->size <= v45->size )
      {
        v73 = vostok::math::align_down<unsigned __int64>(
                *(_QWORD *)&filler - v47->size,
                SystemInfo.dwAllocationGranularity);
        HIDWORD(v88) = HIDWORD(v73);
        v42->size = v73;
        LODWORD(v88) = v73;
        v74 = allocate_region(v88);
        v42->address = v74;
        if ( !v74 )
          return 0;
        v75 = v47->size;
        LODWORD(v45->size) = v47->size;
        v76 = HIDWORD(v47->size);
        HIDWORD(v45->size) = v76;
        v56 = allocate_region(__PAIR64__(v76, v75));
        goto LABEL_59;
      }
      LODWORD(v42->size) = v59;
      v68 = v42->size;
      HIDWORD(dwAllocationGranularity) = HIDWORD(min_buffer_size);
      HIDWORD(v42->size) = HIDWORD(min_buffer_size);
      LODWORD(dwAllocationGranularity) = v68;
      v69 = allocate_region(dwAllocationGranularity);
      v42->address = v69;
      if ( !v69 )
        return 0;
      v33 = filler.m_regions < (vostok::buffer_vector<vostok::memory::platform::region> *)LODWORD(v47[-1].size);
      v70 = (char *)filler.m_regions - LODWORD(v47[-1].size);
      dwAllocationGranularity = SystemInfo.dwAllocationGranularity;
      HIDWORD(v89) = (char *)filler.m_high_memory_regions - v33 - HIDWORD(v47[-1].size);
      LODWORD(v89) = v70;
      v71 = vostok::math::align_down<unsigned __int64>(v89, SystemInfo.dwAllocationGranularity);
      HIDWORD(v88) = HIDWORD(v71);
      v45->size = v71;
      LODWORD(v88) = v71;
      v72 = allocate_region(v88);
    }
    v45->address = v72;
    if ( v72 )
      return 1;
    dwAllocationGranularity = v42->size;
LABEL_61:
    vostok::memory::platform::free_region(v42->address, dwAllocationGranularity);
    result = 0;
    v42->address = 0;
    return result;
  }
  v48 = v42->size;
  v49 = HIDWORD(v42->size);
  HIDWORD(dwAllocationGranularity) = 4;
  p_address = &v36[-1].address;
  v51 = v36[-1].address;
  HIDWORD(min_buffer_size) = v49;
  v52 = VirtualAlloc(v51, v48, 0x3000u, 4u);
  v42->address = v52;
  if ( !v52 )
    return 0;
  v54 = v45->size;
  v55 = (char *)*p_address + LODWORD(v42->size);
  HIDWORD(min_buffer_size) = HIDWORD(v45->size);
  v56 = VirtualAlloc(v55, v54, 0x3000u, 4u);
LABEL_59:
  v45->address = v56;
  if ( !v56 )
  {
    dwAllocationGranularity = v42->size;
    goto LABEL_61;
  }
  return 1;
}
