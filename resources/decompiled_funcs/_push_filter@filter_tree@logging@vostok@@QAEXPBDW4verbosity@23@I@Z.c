void __thiscall vostok::logging::filter_tree::push_filter(
        vostok::logging::filter_tree *this,
        vostok::fixed_string<16> *initiator,
        vostok::logging::verbosity verbosity,
        unsigned int thread_id)
{
  vostok::memory::base_allocator *v4; // eax
  vostok::threading::reader_writer_lock *v5; // ecx
  vostok::logging::initiator_filter *v6; // [esp+4h] [ebp-44h]
  void *_Where; // [esp+2Ch] [ebp-1Ch]
  vostok::logging::initiator_filter *v9; // [esp+34h] [ebp-14h]
  vostok::threading::reader_writer_lock::mutex_raii raii; // [esp+38h] [ebp-10h] BYREF
  vostok::logging::initiator_filter *filter; // [esp+44h] [ebp-4h]

  if ( !initiator )
    initiator = (vostok::fixed_string<16> *)&buf;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::base_allocator::malloc_impl(v4, 0x3Cu);
  v9 = (vostok::logging::initiator_filter *)operator new(0x3Cu, _Where);
  if ( v9 )
  {
    vostok::fixed_string<32>::fixed_string<32>(&v9->initiator);
    v6 = v9;
  }
  else
  {
    v6 = 0;
  }
  filter = v6;
  vostok::fixed_string<16>::operator=(initiator, &v6->initiator);
  v6->verbosity = verbosity;
  filter->thread_id = thread_id;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&raii);
  raii.lock = &this->lock;
  raii.lock_type = lock_type_write;
  vostok::threading::reader_writer_lock::lock(v5, lock_type_write);
  raii.locked = 1;
  vostok::intrusive_double_linked_list<vostok::logging::initiator_filter,vostok::logging::initiator_filter *,4,0,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::push_back(
    &this->filter_stack,
    filter,
    0);
  vostok::logging::filter_tree::build_tree(this);
  vostok::threading::reader_writer_lock::mutex_raii::~mutex_raii(&raii);
}
