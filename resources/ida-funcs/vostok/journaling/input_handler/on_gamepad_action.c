bool __thiscall vostok::journaling::input_handler::on_gamepad_action(
        vostok::journaling::input_handler *this,
        vostok::input::world *world,
        vostok::input::gamepad_button button,
        vostok::input::enum_gamepad_action action)
{
  int v4; // esi
  vostok::fs_new::device_file_system_no_watcher_proxy *v5; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v6; // ecx
  vostok::journaling::data_chunk_type_enum v8; // [esp+0h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-4h] BYREF

  vostok::journaling::journal::start_writing(
    (vostok::journaling::journal *)this,
    (int)vostok::core::g_journal.m_variable,
    &v9,
    (vostok::journaling::writer_ptr *)4,
    v8);
  v4 = v9;
  HIBYTE(button) = button;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(
    v5,
    *(_DWORD **)(v9 + 4),
    *(void ***)v9,
    (char *)&button + 3,
    1u);
  HIBYTE(button) = action;
  vostok::fs_new::device_file_system_no_watcher_proxy::write(
    v6,
    *(_DWORD **)(v4 + 4),
    *(void ***)v4,
    (char *)&button + 3,
    1u);
  return 0;
}
