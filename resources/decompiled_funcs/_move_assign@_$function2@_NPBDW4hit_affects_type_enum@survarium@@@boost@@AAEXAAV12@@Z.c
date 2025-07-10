void __thiscall boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *this,
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *f)
{
  if ( f != this )
  {
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)f) )
    {
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)this);
    }
    else
    {
      this->vtable = f->vtable;
      if ( (unsigned __int8)boost::function_base::has_trivial_copy_and_destroy(f, this) )
        this->functor = f->functor;
      else
        (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)this->vtable & 0xFFFFFFFE))(
          &f->functor,
          &this->functor,
          1);
      f->vtable = 0;
    }
  }
}
