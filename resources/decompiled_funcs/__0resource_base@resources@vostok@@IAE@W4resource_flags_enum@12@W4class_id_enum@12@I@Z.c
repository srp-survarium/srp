void __userpurge vostok::resources::resource_base::resource_base(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>,
        vostok::resources::class_id_enum flags,
        unsigned int class_id,
        unsigned int quality_levels_count)
{
  DWORD CurrentThreadId; // eax

  vostok::resources::resource_children::resource_children(
    (vostok::resources::resource_children *)a2,
    (volatile int)this);
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 108) = class_id;
  *(_DWORD *)(a2 + 132) = flags;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 124) = -1;
  *(_DWORD *)(a2 + 128) = -1;
  *(_DWORD *)a2 = &vostok::resources::resource_base::`vftable';
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  *(_DWORD *)(a2 + 156) = 0;
  vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)(a2 + 160));
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 192) = 0;
  CurrentThreadId = GetCurrentThreadId();
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 196) = CurrentThreadId;
}
