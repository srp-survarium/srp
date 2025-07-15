void __userpurge vostok::render::functor_command::functor_command(
        vostok::render::functor_command *this@<esi>,
        vostok::memory::base_allocator *allocator@<ecx>,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *on_defer_execution@<edi>,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *on_execute)
{
  bool v4; // zf

  v4 = on_defer_execution->vtable == 0;
  this->allocator = allocator;
  this->remove_frame_id = 0;
  this->is_deferred_command = !v4;
  this->use_depth = 1;
  this->__vftable = (vostok::render::functor_command_vtbl *)&vostok::render::functor_command::`vftable';
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    on_execute,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_on_execute);
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    on_defer_execution,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_on_defer_execution);
}
