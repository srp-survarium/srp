void __thiscall vostok::logging::filter_tree::~filter_tree(vostok::logging::filter_tree *this)
{
  vostok::memory::base_allocator *v1; // eax
  vostok::threading::mutex *v2; // ecx

  vostok::logging::node::clean(this->initiator_tree, this->allocator);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::node>(v1, &this->initiator_tree);
  vostok::threading::mutex::~mutex(v2, (_RTL_CRITICAL_SECTION *)&this->filter_stack.m_policy);
  vostok::threading::reader_writer_lock::~reader_writer_lock(&this->lock);
}
