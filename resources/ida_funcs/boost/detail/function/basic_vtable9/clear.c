void __thiscall boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
        boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *this,
        boost::detail::function::function_buffer *functor)
{
  if ( this->base.manager )
    this->base.manager(functor, functor, 2);
}
