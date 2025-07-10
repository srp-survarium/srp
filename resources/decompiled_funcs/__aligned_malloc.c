void __thiscall _aligned_malloc(survarium::game_camera *size)
{
  survarium::weapon_user_dead_state::finalize(size);
  JUMPOUT(0x66A03A);
}
