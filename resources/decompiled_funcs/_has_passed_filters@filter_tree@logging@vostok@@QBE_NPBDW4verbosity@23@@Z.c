bool __thiscall vostok::logging::filter_tree::has_passed_filters(
        vostok::logging::filter_tree *this,
        const char *initiator,
        vostok::logging::verbosity verbosity)
{
  bool v5; // [esp+Fh] [ebp-31h]
  vostok::logging::path_parts path; // [esp+10h] [ebp-30h] BYREF
  vostok::logging::verbosity allowed_verbosity; // [esp+30h] [ebp-10h]
  vostok::threading::reader_writer_lock::mutex_raii raii; // [esp+34h] [ebp-Ch] BYREF

  vostok::logging::path_parts::path_parts(&path, initiator);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&raii);
  raii.lock = &this->lock;
  raii.lock_type = lock_type_read;
  vostok::threading::reader_writer_lock::lock(&this->lock, lock_type_read);
  raii.locked = 1;
  allowed_verbosity = vostok::logging::node::get_verbosity(this->initiator_tree, &path, silent);
  v5 = allowed_verbosity >= verbosity;
  vostok::threading::reader_writer_lock::mutex_raii::~mutex_raii(&raii);
  vostok::logging::path_parts::~path_parts(&path);
  return v5;
}
