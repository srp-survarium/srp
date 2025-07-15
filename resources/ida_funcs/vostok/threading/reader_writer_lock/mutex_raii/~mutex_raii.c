void __thiscall vostok::threading::reader_writer_lock::mutex_raii::~mutex_raii(
        vostok::threading::reader_writer_lock::mutex_raii *this)
{
  if ( this->locked )
  {
    vostok::threading::reader_writer_lock::unlock((vostok::threading::reader_writer_lock *)this, this->lock_type);
    this->locked = 0;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
