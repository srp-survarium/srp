bool __thiscall vostok::journaling::input_handler::on_mouse_move(
        vostok::journaling::input_handler *this,
        vostok::input::world *world,
        int x,
        int y,
        int z)
{
  int v5; // esi
  _DWORD *v6; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v7; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v8; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v9; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v10; // ecx
  void **v12; // [esp-10h] [ebp-24h]
  vostok::journaling::data_chunk_type_enum v13; // [esp+0h] [ebp-14h]
  int v14; // [esp+Ch] [ebp-8h] BYREF
  char v15; // [esp+13h] [ebp-1h] BYREF

  vostok::journaling::journal::start_writing(
    (vostok::journaling::journal *)this,
    (int)vostok::core::g_journal.m_variable,
    &v14,
    (vostok::journaling::writer_ptr *)5,
    v13);
  v5 = v14;
  v12 = *(void ***)v14;
  v6 = *(_DWORD **)(v14 + 4);
  v15 = 0;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v7, v6, v12, &v15, 1u);
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v8, *(_DWORD **)(v5 + 4), *(void ***)v5, &x, 4u);
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v9, *(_DWORD **)(v5 + 4), *(void ***)v5, &y, 4u);
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v10, *(_DWORD **)(v5 + 4), *(void ***)v5, &z, 4u);
  return 0;
}
