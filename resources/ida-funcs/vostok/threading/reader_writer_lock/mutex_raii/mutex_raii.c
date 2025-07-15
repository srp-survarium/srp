void __thiscall vostok::threading::reader_writer_lock::mutex_raii::mutex_raii(
        vostok::threading::reader_writer_lock::mutex_raii *this,
        const vostok::threading::reader_writer_lock *lock,
        vostok::threading::reader_writer_lock *lock_type)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->lock = lock;
  this->lock_type = (vostok::threading::lock_type_enum)lock_type;
  vostok::threading::reader_writer_lock::lock(lock_type, (vostok::threading::lock_type_enum)lock_type);
  this->locked = 1;
}
