bool __thiscall vostok::journaling::input_handler::on_mouse_key_action(
        vostok::journaling::input_handler *this,
        vostok::input::world *world,
        vostok::input::mouse_button button,
        vostok::input::enum_mouse_key_action action)
{
  int v4; // esi
  _DWORD *v5; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v6; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v7; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v8; // ecx
  void **v10; // [esp-10h] [ebp-20h]
  vostok::journaling::data_chunk_type_enum v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+8h] [ebp-8h] BYREF
  char v13; // [esp+Fh] [ebp-1h] BYREF

  vostok::journaling::journal::start_writing(
    (vostok::journaling::journal *)this,
    (int)vostok::core::g_journal.m_variable,
    &v12,
    (vostok::journaling::writer_ptr *)5,
    v11);
  v4 = v12;
  v10 = *(void ***)v12;
  v5 = *(_DWORD **)(v12 + 4);
  v13 = -1;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(v6, v5, v10, &v13, 1u);
  HIBYTE(button) = button - 81;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(
    v7,
    *(_DWORD **)(v4 + 4),
    *(void ***)v4,
    (char *)&button + 3,
    1u);
  HIBYTE(button) = action;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(
    v8,
    *(_DWORD **)(v4 + 4),
    *(void ***)v4,
    (char *)&button + 3,
    1u);
  return 0;
}
