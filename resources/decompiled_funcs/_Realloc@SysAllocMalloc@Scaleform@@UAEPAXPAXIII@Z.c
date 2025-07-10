void *__thiscall Scaleform::SysAllocMalloc::Realloc(
        Scaleform::SysAllocMalloc *this,
        void *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        survarium::game_camera *align)
{
  if ( newSize != oldSize )
  {
    survarium::weapon_user_dead_state::finalize(align);
    JUMPOUT(0xAEA3F);
  }
  return oldPtr;
}
