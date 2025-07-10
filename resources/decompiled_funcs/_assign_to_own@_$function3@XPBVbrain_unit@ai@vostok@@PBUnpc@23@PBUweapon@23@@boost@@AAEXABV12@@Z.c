void __thiscall boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
        boost::function1<void,enum vostok::handshaking_error_types_enum> *this,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *f)
{
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(f) )
  {
    this->vtable = (boost::detail::function::vtable_base *)f->m_object;
    if ( (unsigned __int8)boost::function_base::has_trivial_copy_and_destroy(this, this) )
      this->functor = *(boost::detail::function::function_buffer *)&f[2].m_object;
    else
      (*(void (__cdecl **)(vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, boost::detail::function::function_buffer *, _DWORD))((int)this->vtable & 0xFFFFFFFE))(
        f + 2,
        &this->functor,
        0);
  }
}
