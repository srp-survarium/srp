void __thiscall vostok::fs_new::file_type_pointer::~file_type_pointer(vostok::fs_new::file_type_pointer *this)
{
  survarium::game_camera *v1; // ecx

  vostok::fs_new::file_type_pointer::close(this);
  survarium::weapon_user_dead_state::finalize(v1);
}
