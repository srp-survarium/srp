vostok::network::functor_response *__thiscall vostok::network::functor_response::`scalar deleting destructor'(
        vostok::network::functor_response *this,
        char a2)
{
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_functor);
  this->__vftable = (vostok::network::functor_response_vtbl *)&vostok::network::response::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
