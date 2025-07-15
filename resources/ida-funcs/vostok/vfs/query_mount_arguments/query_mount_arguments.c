void __userpurge vostok::vfs::query_mount_arguments::query_mount_arguments(
        vostok::vfs::query_mount_arguments *this@<ecx>,
        int a2@<edi>,
        const vostok::vfs::query_mount_arguments *__that)
{
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)a2, &__that->virtual_path.m_string);
  *(_BYTE *)(a2 + 272) = 47;
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)(a2 + 276), &__that->physical_path.m_string);
  *(_BYTE *)(a2 + 548) = 92;
  vostok::fixed_string<260>::fixed_string<260>(
    (vostok::fixed_string<260> *)(a2 + 552),
    &__that->archive_physical_path.m_string);
  *(_BYTE *)(a2 + 824) = 92;
  vostok::fixed_string<260>::fixed_string<260>(
    (vostok::fixed_string<260> *)(a2 + 828),
    &__that->fat_physical_path.m_string);
  *(_BYTE *)(a2 + 1100) = 92;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&__that->callback,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(a2 + 1104));
  *(_DWORD *)(a2 + 1136) = __that->asynchronous_device;
  *(_DWORD *)(a2 + 1140) = __that->synchronous_device;
  *(_DWORD *)(a2 + 1144) = __that->allocator;
  *(_DWORD *)(a2 + 1148) = __that->type;
  *(_DWORD *)(a2 + 1152) = __that->watcher_enabled;
  *(_DWORD *)(a2 + 1156) = __that->recursive;
  *(_DWORD *)(a2 + 1160) = __that->lock_operation;
  vostok::fixed_string<32>::fixed_string<32>((vostok::fixed_string<32> *)(a2 + 1164), &__that->descriptor);
  *(_DWORD *)(a2 + 1208) = __that->mount_id;
  *(_DWORD *)(a2 + 1212) = __that->root_write_lock;
  *(_DWORD *)(a2 + 1216) = __that->submount_node;
  *(_DWORD *)(a2 + 1220) = __that->parent_of_submount_node;
  *(_DWORD *)(a2 + 1224) = __that->mount_ptr;
  *(_DWORD *)(a2 + 1228) = __that->submount_type;
  *(_BYTE *)(a2 + 1232) = __that->unlock_after_mount;
}


void __usercall vostok::vfs::query_mount_arguments::query_mount_arguments(
        vostok::vfs::query_mount_arguments *this@<ecx>,
        int a2@<esi>)
{
  vostok::fs_new::virtual_path_string::virtual_path_string(&this->virtual_path, a2);
  vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)(a2 + 276));
  vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)(a2 + 552));
  vostok::fs_new::native_path_string::native_path_string((vostok::fs_new::native_path_string *)(a2 + 828));
  *(_DWORD *)(a2 + 1104) = 0;
  *(_DWORD *)(a2 + 1136) = 0;
  *(_DWORD *)(a2 + 1140) = 0;
  *(_DWORD *)(a2 + 1144) = 0;
  *(_DWORD *)(a2 + 1148) = 0;
  *(_DWORD *)(a2 + 1152) = 1;
  *(_DWORD *)(a2 + 1164) = a2 + 1176;
  *(_DWORD *)(a2 + 1168) = a2 + 1176;
  *(_BYTE *)(a2 + 1176) = 0;
  *(_DWORD *)(a2 + 1172) = a2 + 1208;
  *(_DWORD *)(a2 + 1208) = 0;
  *(_DWORD *)(a2 + 1212) = 0;
  *(_DWORD *)(a2 + 1216) = 0;
  *(_DWORD *)(a2 + 1220) = 0;
  *(_DWORD *)(a2 + 1224) = 0;
  *(_DWORD *)(a2 + 1228) = 0;
  *(_BYTE *)(a2 + 1232) = 1;
}
