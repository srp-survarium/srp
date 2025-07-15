char __cdecl allocate_arenas(
        vostok::memory::platform::region *arenas,
        vostok::buffer_vector<vostok::memory::platform::region> *resource_arenas,
        char *start_address,
        vostok::memory::platform::region *only_resources)
{
  stlp_std::less<vostok::memory::platform::region> v4; // cl
  vostok::memory::platform::region *v5; // ebx
  vostok::memory::platform::region *i; // ecx
  _QWORD *v7; // eax
  unsigned __int64 v8; // rdi
  void *v9; // esp
  void *v10; // esp
  stlp_std::less<vostok::memory::platform::region> v11; // cl
  stlp_std::less<vostok::memory::platform::region> v12; // cl
  vostok::memory::platform::region *m_begin; // ecx
  vostok::memory::platform::region *v14; // eax
  vostok::memory::platform::region *size_high; // eax
  vostok::memory::platform::region *size; // ebx
  vostok::memory::platform::region *v17; // ebx
  unsigned __int64 v18; // rax
  vostok::memory::platform::region *m_end; // esi
  vostok::memory::platform::region *v20; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *v21; // edi
  unsigned int v22; // ecx
  unsigned int v23; // eax
  bool v24; // cf
  vostok::memory::platform::region **v25; // esi
  stlp_std::less<vostok::memory::platform::region> v26; // cl
  vostok::memory::platform::region *v27; // edi
  vostok::memory::platform::region *v28; // esi
  unsigned int v29; // ecx
  vostok::memory::platform::region *v30; // edi
  regions_filler v31; // kr18_8
  vostok::memory::platform::region *v32; // ebx
  unsigned int v33; // eax
  void **p_address; // ebx
  LPVOID region; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *v37; // eax
  int v38; // eax
  unsigned int v39; // kr00_4
  vostok::buffer_vector<vostok::memory::platform::region> *m_regions; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *m_high_memory_regions; // kr04_4
  double v42; // st7
  vostok::buffer_vector<vostok::memory::platform::region> *v43; // eax
  unsigned __int64 v44; // kr08_8
  int v45; // ecx
  LPVOID v46; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *v47; // eax
  LPVOID v48; // eax
  unsigned __int64 v49; // rax
  LPVOID v50; // eax
  unsigned __int64 v51; // rax
  LPVOID v52; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *v53; // eax
  int v54; // eax
  int v55; // eax
  unsigned int v56; // kr10_4
  unsigned __int64 v57; // rax
  unsigned int v58; // ecx
  vostok::memory::platform::region *v59; // ebx
  LPVOID v60; // eax
  unsigned __int64 v61; // [esp-1Ch] [ebp-7Ch]
  void *v62; // [esp-14h] [ebp-74h]
  _BYTE v63[12]; // [esp-10h] [ebp-70h]
  vostok::buffer_vector<vostok::memory::platform::region> *address; // [esp-4h] [ebp-64h]
  _BYTE v65[16]; // [esp+0h] [ebp-60h] BYREF
  vostok::memory::platform::region __val; // [esp+10h] [ebp-50h] BYREF
  vostok::buffer_vector<vostok::memory::platform::region> v67; // [esp+20h] [ebp-40h] BYREF
  vostok::buffer_vector<vostok::memory::platform::region> __first; // [esp+2Ch] [ebp-34h] BYREF
  unsigned __int64 v69; // [esp+38h] [ebp-28h]
  regions_filler v70; // [esp+40h] [ebp-20h] BYREF
  regions_filler v71; // [esp+48h] [ebp-18h] BYREF
  unsigned __int64 v72; // [esp+50h] [ebp-10h]
  vostok::memory::platform::region **p_first; // [esp+58h] [ebp-8h]
  unsigned int allocation_granularity; // [esp+5Ch] [ebp-4h]

  v5 = arenas;
  stlp_std::sort<vostok::memory::platform::region *>(
    (vostok::memory::platform::region *)arenas->size,
    (vostok::memory::platform::region *)HIDWORD(arenas->size),
    v4);
  stlp_std::reverse<vostok::memory::platform::region *>(
    (vostok::memory::platform::region *)v5->size,
    (vostok::memory::platform::region *)HIDWORD(v5->size));
  for ( i = (vostok::memory::platform::region *)v5->size;
        i != (vostok::memory::platform::region *)HIDWORD(v5->size);
        HIDWORD(v5->size) = v7 )
  {
    v7 = (_QWORD *)(HIDWORD(v5->size) - 16);
    if ( *v7 )
      break;
  }
  stlp_std::reverse<vostok::memory::platform::region *>(i, (vostok::memory::platform::region *)HIDWORD(v5->size));
  v8 = *(_QWORD *)LODWORD(v5->size);
  arenas = 0;
  v69 = v8;
  allocation_granularity = ::allocation_granularity();
  iterate_regions<regions_count>(start_address, allocation_granularity, v8, (regions_count *)&arenas);
  HIDWORD(v8) = 16 * ((_DWORD)&arenas->size + 1);
  v9 = alloca(SHIDWORD(v8));
  __first.m_begin = (vostok::memory::platform::region *)v65;
  __first.m_end = (vostok::memory::platform::region *)v65;
  __first.m_max_end = (vostok::memory::platform::region *)&v65[HIDWORD(v8)];
  v10 = alloca(SHIDWORD(v8));
  v67.m_begin = (vostok::memory::platform::region *)v65;
  v67.m_end = (vostok::memory::platform::region *)v65;
  v70.m_regions = &__first;
  v70.m_high_memory_regions = &v67;
  v67.m_max_end = (vostok::memory::platform::region *)&v65[HIDWORD(v8)];
  iterate_regions<regions_filler>(start_address, allocation_granularity, v69, &v70);
  stlp_std::sort<vostok::memory::platform::region *>(__first.m_begin, __first.m_end, v11);
  stlp_std::sort<vostok::memory::platform::region *>(v67.m_begin, v67.m_end, v12);
  if ( vostok::memory::g_use_resources_manager )
  {
    m_begin = resource_arenas->m_begin;
    v14 = resource_arenas->m_end - 1;
    if ( resource_arenas->m_begin->size > v14->size )
    {
      __val = *m_begin;
      LODWORD(m_begin->size) = v14->size;
      HIDWORD(m_begin->size) = HIDWORD(v14->size);
      m_begin->address = v14->address;
      m_begin->data = v14->data;
      *v14 = __val;
    }
  }
  size_high = (vostok::memory::platform::region *)HIDWORD(v5->size);
  size = (vostok::memory::platform::region *)v5->size;
  arenas = size_high;
  v70.m_high_memory_regions = (vostok::buffer_vector<vostok::memory::platform::region> *)size;
  if ( !(_BYTE)only_resources && size_high != size )
  {
    v17 = size_high - 1;
    do
    {
      v18 = (v17->size - 1) / allocation_granularity;
      *(_DWORD *)&v63[8] = allocation_granularity;
      *(_QWORD *)v63 = v18 + 1;
      v17->size = (v18 + 1) * allocation_granularity;
      m_end = v67.m_end;
      HIDWORD(v72) = v67.m_begin;
      v20 = stlp_std::lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region>(
              v67.m_end,
              v17,
              v67.m_begin);
      v21 = &v67;
      only_resources = v20;
      p_first = (vostok::memory::platform::region **)&v67;
      if ( v20 == m_end || v20->size < v17->size )
      {
        m_end = __first.m_end;
        HIDWORD(v72) = __first.m_begin;
        v20 = stlp_std::lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region>(
                __first.m_end,
                v17,
                __first.m_begin);
        only_resources = v20;
        p_first = (vostok::memory::platform::region **)&__first;
        v21 = &__first;
      }
      if ( !vostok::memory::g_use_resources_manager )
      {
        v71.m_high_memory_regions = (vostok::buffer_vector<vostok::memory::platform::region> *)&v20[1];
        if ( &v20[1] != m_end && &v20[2] == m_end )
        {
          if ( v20 == (vostok::memory::platform::region *)HIDWORD(v72) )
          {
            v22 = 0;
            v23 = 0;
          }
          else
          {
            v22 = v20[-1].size;
            v23 = HIDWORD(v20[-1].size);
          }
          address = (vostok::buffer_vector<vostok::memory::platform::region> *)allocation_granularity;
          *(_DWORD *)&v63[8] = resource_arenas;
          v20 = *select_best_region_0(
                   __PAIR64__(v23, v22),
                   &only_resources,
                   (vostok::memory::platform::region **)&v71.m_high_memory_regions,
                   v17->size,
                   resource_arenas,
                   allocation_granularity);
          only_resources = v20;
        }
      }
      v17->address = allocate_region(v17->size, v20->address);
      only_resources->address = (char *)only_resources->address + LODWORD(v17->size);
      v24 = LODWORD(only_resources->size) < LODWORD(v17->size);
      LODWORD(only_resources->size) -= LODWORD(v17->size);
      HIDWORD(only_resources->size) -= v24 + HIDWORD(v17->size);
      if ( only_resources == v21->m_begin )
      {
        if ( only_resources->size < v69 )
          vostok::buffer_vector<vostok::memory::platform::region>::erase(v21, &only_resources);
      }
      else if ( only_resources->size < only_resources[-1].size )
      {
        __val = *only_resources;
        v25 = p_first;
        vostok::buffer_vector<vostok::memory::platform::region>::erase(
          (vostok::buffer_vector<vostok::memory::platform::region> *)p_first,
          &only_resources);
        if ( __val.size >= v69 )
        {
          v71.m_high_memory_regions = (vostok::buffer_vector<vostok::memory::platform::region> *)stlp_std::lower_bound<vostok::memory::platform::region *,vostok::memory::platform::region>(
                                                                                                   v25[1],
                                                                                                   &__val,
                                                                                                   *v25);
          vostok::buffer_vector<vostok::memory::platform::region>::insert(
            address,
            v25,
            &v71.m_high_memory_regions,
            &__val);
        }
      }
      --arenas;
      --v17;
    }
    while ( arenas != (vostok::memory::platform::region *)v70.m_high_memory_regions );
  }
  if ( !vostok::memory::g_use_resources_manager )
    return 1;
  arenas = v67.m_end;
  only_resources = __first.m_end;
  vostok::buffer_vector<vostok::memory::platform::region>::insert<vostok::memory::platform::region *>(
    &arenas,
    &__first,
    &only_resources,
    v67.m_begin);
  stlp_std::sort<vostok::memory::platform::region *>(__first.m_begin, __first.m_end, v26);
  v27 = resource_arenas->m_end;
  v28 = resource_arenas->m_begin;
  v29 = HIDWORD(v27[-1].size);
  v30 = v27 - 1;
  v31 = (regions_filler)(resource_arenas->m_begin->size + __PAIR64__(v29, v30->size));
  v32 = __first.m_end - 1;
  v70 = v31;
  v71 = v31;
  v33 = __first.m_end[-1].size;
  arenas = __first.m_end;
  if ( __PAIR64__(HIDWORD(__first.m_end[-1].size), v33) >= *(_QWORD *)&v31 )
  {
    p_address = &__first.m_end[-1].address;
    region = allocate_region(v28->size, __first.m_end[-1].address);
    v28->address = region;
    if ( !region )
      return 0;
    v37 = (vostok::buffer_vector<vostok::memory::platform::region> *)((char *)*p_address + LODWORD(v28->size));
    goto LABEL_49;
  }
  v38 = v28->size;
  LODWORD(v69) = 0;
  LODWORD(v72) = v38;
  HIDWORD(v69) = HIDWORD(v28->size);
  v39 = HIDWORD(v69);
  HIDWORD(v72) = HIDWORD(v69) & 0x7FFFFFFF;
  m_regions = v70.m_regions;
  v70.m_regions = 0;
  v69 = __PAIR64__((unsigned int)v70.m_high_memory_regions, (unsigned int)m_regions) & 0x7FFFFFFFFFFFFFFFLL;
  m_high_memory_regions = v70.m_high_memory_regions;
  v70.m_high_memory_regions = (vostok::buffer_vector<vostok::memory::platform::region> *)((int)v70.m_high_memory_regions
                                                                                        & 0x80000000);
  v42 = (double)__PAIR64__(v39, v72) / (double)__PAIR64__((unsigned int)m_high_memory_regions, (unsigned int)m_regions);
  if ( (((char *)__first.m_end - (char *)__first.m_begin) & 0xFFFFFFF0) == 0x10 )
    goto LABEL_47;
  v43 = (vostok::buffer_vector<vostok::memory::platform::region> *)__first.m_end[-2].size;
  LODWORD(v72) = 0;
  v70.m_regions = v43;
  v70.m_high_memory_regions = (vostok::buffer_vector<vostok::memory::platform::region> *)HIDWORD(__first.m_end[-2].size);
  v69 = v32->size;
  v44 = v69;
  v72 = *(_QWORD *)&v70 & 0x8000000000000000uLL;
  v69 = __PAIR64__((unsigned int)v70.m_high_memory_regions, (unsigned int)v43) & 0x7FFFFFFFFFFFFFFFLL;
  if ( (double)v44 * v42 >= (double)__PAIR64__((unsigned int)v70.m_high_memory_regions, (unsigned int)v43) )
  {
LABEL_47:
    v54 = v32->size;
    v70.m_regions = 0;
    LODWORD(v69) = v54;
    HIDWORD(v69) = HIDWORD(v32->size);
    v55 = HIDWORD(v69);
    v56 = HIDWORD(v69);
    HIDWORD(v69) &= ~0x80000000;
    v70.m_high_memory_regions = (vostok::buffer_vector<vostok::memory::platform::region> *)(v55 & 0x80000000);
    v57 = vostok::math::align_down<unsigned __int64>(
            (unsigned __int64)(v42 * (double)__PAIR64__(v56, v69)),
            allocation_granularity);
    v28->size = v57;
    LODWORD(v57) = v32->size;
    v58 = HIDWORD(v32->size);
    v59 = arenas;
    v30->size = __PAIR64__(v58, v57) - __PAIR64__(HIDWORD(v57), v28->size);
    v60 = allocate_region(v28->size, v59[-1].address);
    v28->address = v60;
    if ( !v60 )
      return 0;
    v37 = (vostok::buffer_vector<vostok::memory::platform::region> *)((char *)v59[-1].address + LODWORD(v28->size));
LABEL_49:
    address = v37;
    goto LABEL_50;
  }
  if ( v32->size >= v30->size )
  {
    v45 = HIDWORD(v28->size);
    if ( *(_QWORD *)&v70 >= v28->size )
    {
      address = (vostok::buffer_vector<vostok::memory::platform::region> *)__first.m_end[-2].address;
      *(_DWORD *)&v63[8] = v45;
      *(_DWORD *)&v63[4] = v28->size;
      v46 = allocate_region(*(unsigned __int64 *)&v63[4], address);
      v28->address = v46;
      if ( !v46 )
        return 0;
      goto LABEL_37;
    }
  }
  if ( *(_QWORD *)&v70 + v32->size < *(_QWORD *)&v71 )
  {
    LODWORD(v28->size) = v70.m_regions;
    v53 = v70.m_high_memory_regions;
    HIDWORD(v28->size) = v70.m_high_memory_regions;
    address = (vostok::buffer_vector<vostok::memory::platform::region> *)v32[-1].address;
    *(_DWORD *)&v63[8] = v53;
    *(_DWORD *)&v63[4] = v28->size;
    v52 = allocate_region(*(unsigned __int64 *)&v63[4], address);
    goto LABEL_45;
  }
  if ( v32->size <= v30->size )
  {
    v51 = vostok::math::align_down<unsigned __int64>(*(_QWORD *)&v71 - v32->size, allocation_granularity);
    v28->size = v51;
    v52 = allocate_region(v51, v32[-1].address);
LABEL_45:
    v28->address = v52;
    if ( !v52 )
      return 0;
    LODWORD(v30->size) = v32->size;
    HIDWORD(v30->size) = HIDWORD(v32->size);
LABEL_37:
    address = (vostok::buffer_vector<vostok::memory::platform::region> *)arenas[-1].address;
LABEL_50:
    v50 = allocate_region(v30->size, address);
    goto LABEL_51;
  }
  LODWORD(v28->size) = v70.m_regions;
  v47 = v70.m_high_memory_regions;
  HIDWORD(v28->size) = v70.m_high_memory_regions;
  address = (vostok::buffer_vector<vostok::memory::platform::region> *)v32[-1].address;
  *(_DWORD *)&v63[8] = v47;
  *(_DWORD *)&v63[4] = v28->size;
  v48 = allocate_region(*(unsigned __int64 *)&v63[4], address);
  v28->address = v48;
  if ( !v48 )
    return 0;
  v49 = vostok::math::align_down<unsigned __int64>(*(_QWORD *)&v71 - v32[-1].size, allocation_granularity);
  LODWORD(v30->size) = v49;
  LODWORD(v49) = arenas;
  HIDWORD(v30->size) = HIDWORD(v49);
  v62 = *(void **)(v49 - 8);
  HIDWORD(v61) = HIDWORD(v49);
  LODWORD(v61) = v30->size;
  v50 = allocate_region(v61, v62);
LABEL_51:
  v30->address = v50;
  if ( !v50 )
  {
    vostok::memory::platform::free_region(v28->size);
    v28->address = 0;
    return 0;
  }
  return 1;
}
