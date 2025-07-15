void __thiscall vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(
        survarium::game_camera *this,
        int change,
        vostok::vfs::lock_type_enum lock_type)
{
  if ( change == -1 )
  {
    if ( lock_type == lock_type_read )
    {
      survarium::weapon_user_dead_state::finalize(this);
      this->__vftable = (survarium::game_camera_vtbl *)(((((((unsigned int)this->__vftable >> 14) & 0x3FF) - 1) & 0x3FF) << 14)
                                                      | (int)this->__vftable & 0xFF003FFF);
    }
    else if ( lock_type == (lock_type_write|lock_type_read) )
    {
      survarium::weapon_user_dead_state::finalize(this);
      this->__vftable = (survarium::game_camera_vtbl *)((((int)this->__vftable & 0x3FFF) - 1) & 0x3FFF
                                                      | (int)this->__vftable & 0xFFFFC000);
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(this);
      if ( lock_type == lock_type_write )
        this->__vftable = (survarium::game_camera_vtbl *)(((((int)this->__vftable & 0x40000000) == 0) << 30)
                                                        | (int)this->__vftable & 0xBFFFFFFF);
      else
        this->__vftable = (survarium::game_camera_vtbl *)(((((((unsigned int)this->__vftable >> 24) & 0x3F) - 1) & 0x3F) << 24)
                                                        | (int)this->__vftable & 0xC0FFFFFF);
    }
  }
  else if ( lock_type == lock_type_read )
  {
    survarium::weapon_user_dead_state::finalize(this);
    this->__vftable = (survarium::game_camera_vtbl *)(((((((unsigned int)this->__vftable >> 14) & 0x3FF) + 1) & 0x3FF) << 14)
                                                    | (int)this->__vftable & 0xFF003FFF);
  }
  else if ( lock_type == (lock_type_write|lock_type_read) )
  {
    survarium::weapon_user_dead_state::finalize(this);
    this->__vftable = (survarium::game_camera_vtbl *)((((int)this->__vftable & 0x3FFF) + 1) & 0x3FFF
                                                    | (int)this->__vftable & 0xFFFFC000);
  }
  else
  {
    survarium::weapon_user_dead_state::finalize(this);
    if ( lock_type == lock_type_write )
      this->__vftable = (survarium::game_camera_vtbl *)(((((((int)this->__vftable & 0x40000000) != 0) + 1) & 1) << 30)
                                                      | (int)this->__vftable & 0xBFFFFFFF);
    else
      this->__vftable = (survarium::game_camera_vtbl *)(((((((unsigned int)this->__vftable >> 24) & 0x3F) + 1) & 0x3F) << 24)
                                                      | (int)this->__vftable & 0xC0FFFFFF);
  }
}
