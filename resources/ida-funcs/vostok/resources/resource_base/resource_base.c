void __userpurge vostok::resources::resource_base::resource_base(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<esi>,
        vostok::resources::class_id_enum flags,
        unsigned int class_id,
        unsigned int quality_levels_count)
{
  DWORD CurrentThreadId; // eax

  vostok::resources::resource_quality::resource_quality(
    (vostok::resources::resource_quality *)a2,
    (volatile int)this,
    flags,
    class_id);
  *(_DWORD *)a2 = &vostok::resources::resource_base::`vftable';
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 192) = 0;
  CurrentThreadId = GetCurrentThreadId();
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 196) = CurrentThreadId;
}
