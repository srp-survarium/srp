void __userpurge vostok::resources::query_result::query_result(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        unsigned __int16 flags,
        vostok::resources::queries_result *parent,
        vostok::memory::base_allocator *allocator,
        unsigned int user_thread_id,
        float target_satisfaction,
        bool disable_cache,
        unsigned int quality_index,
        vostok::resources::query_type_enum query_type,
        vostok::resources::autoselect_quality_bool autoselect_quality)
{
  volatile signed __int32 *v12; // ecx

  vostok::resources::query_result_for_cook::query_result_for_cook(this, a2, parent);
  *(_DWORD *)a2 = &vostok::resources::query_result::`vftable';
  *(_DWORD *)(a2 + 616) = 0;
  *(_DWORD *)(a2 + 620) = 0;
  *(_DWORD *)(a2 + 624) = 0;
  *(_DWORD *)(a2 + 628) = 0;
  *(_DWORD *)(a2 + 632) = 0;
  *(_DWORD *)(a2 + 640) = 0;
  *(_DWORD *)(a2 + 644) = 0;
  *(_DWORD *)(a2 + 648) = 0;
  *(_DWORD *)(a2 + 652) = 0;
  *(_DWORD *)(a2 + 656) = 0;
  *(_DWORD *)(a2 + 660) = 0;
  *(_DWORD *)(a2 + 664) = 0;
  *(_DWORD *)(a2 + 668) = 0;
  *(_DWORD *)(a2 + 672) = 0;
  *(_DWORD *)(a2 + 676) = 0;
  *(_DWORD *)(a2 + 684) = 0;
  *(_DWORD *)(a2 + 696) = quality_index;
  *(_DWORD *)(a2 + 688) = 0;
  *(_DWORD *)(a2 + 692) = 0;
  *(_DWORD *)(a2 + 700) = 1;
  v12 = (volatile signed __int32 *)(a2 + 704);
  *(_DWORD *)(a2 + 704) = flags;
  *(_DWORD *)(a2 + 708) = 0;
  *(_DWORD *)(a2 + 712) = 0;
  *(_DWORD *)(a2 + 716) = user_thread_id;
  *(_DWORD *)(a2 + 720) = 0;
  *(_BYTE *)(a2 + 724) = 1;
  *(_DWORD *)(a2 + 728) = 1;
  if ( disable_cache )
    _InterlockedOr(v12, 0x4000000u);
  if ( query_type == query_type_helper_for_mount )
    _InterlockedOr(v12, 0x8000000u);
  if ( autoselect_quality == autoselect_quality_true )
    _InterlockedOr(v12, 0x10000000u);
  *(_DWORD *)(a2 + 340) = allocator;
  *(_DWORD *)(a2 + 636) = a2;
  *(float *)(a2 + 116) = target_satisfaction;
  _InterlockedOr(v12, (unsigned int)&loc_20000);
}
