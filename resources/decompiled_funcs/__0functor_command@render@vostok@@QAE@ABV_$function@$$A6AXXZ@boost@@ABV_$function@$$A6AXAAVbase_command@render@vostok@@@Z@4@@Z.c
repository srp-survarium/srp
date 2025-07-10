void __userpurge vostok::render::functor_command::functor_command(
        vostok::render::functor_command *this@<edi>,
        const boost::function<void __cdecl(void)> *on_execute@<edx>,
        boost::function4<void,unsigned int,float,float,char const *> *on_defer_execution)
{
  this->is_deferred_command = on_defer_execution->vtable != 0;
  this->use_depth = 1;
  this->remove_frame_id = 0;
  this->__vftable = (vostok::render::functor_command_vtbl *)&vostok::render::functor_command::`vftable';
  this->m_on_execute.vtable = 0;
  boost::function0<void>::assign_to_own(&this->m_on_execute, on_execute);
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    on_defer_execution,
    (int)&this->m_on_defer_execution);
}
