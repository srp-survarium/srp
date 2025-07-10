void __thiscall boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(
        boost::function4<float,char const *,char const *,float,float> *this)
{
  void (__cdecl **v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // [esp+8h] [ebp-4h]

  if ( this->vtable )
  {
    if ( !(unsigned __int8)boost::function_base::has_trivial_copy_and_destroy(this, this) )
    {
      v2 = (void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)this->vtable & 0xFFFFFFFE);
      if ( *v2 )
        (*v2)(&this->functor, &this->functor, 2);
    }
    this->vtable = 0;
  }
}
