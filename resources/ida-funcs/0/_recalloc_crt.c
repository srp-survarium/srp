void __cdecl _recalloc_crt(void *ptr, survarium::game_camera *count)
{
  survarium::weapon_user_dead_state::finalize(count);
  JUMPOUT(0x66A057);
}
