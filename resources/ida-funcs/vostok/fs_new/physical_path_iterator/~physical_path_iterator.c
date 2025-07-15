void __thiscall vostok::fs_new::physical_path_iterator::~physical_path_iterator(
        vostok::fs_new::physical_path_iterator *this)
{
  vostok::fs_new::physical_path_iterator *thisa; // [esp+4h] [ebp-4h]

  thisa = this;
  if ( (HIDWORD(this->search_handle) & this->search_handle) != -1 )
  {
    ((void (__thiscall *)(vostok::fs_new::device_file_system_interface *, _DWORD, _DWORD))this->device->find_close)(
      this->device,
      this->search_handle,
      HIDWORD(this->search_handle));
    this = thisa;
    LODWORD(thisa->search_handle) = 0;
    HIDWORD(thisa->search_handle) = 0;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
