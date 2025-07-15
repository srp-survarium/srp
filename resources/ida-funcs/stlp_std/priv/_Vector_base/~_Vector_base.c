void __usercall stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>::~_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>(
        stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int> > *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)a2 )
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, const char *, int))(**(_DWORD **)(a2 + 8) + 24))(
      *(_DWORD *)(a2 + 8),
      *(_DWORD *)a2,
      "vostok::detail::std_allocator<unsigned int>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}


void __thiscall stlp_std::priv::_Vector_base<void *,stlp_std::allocator<void *>>::~_Vector_base<void *,stlp_std::allocator<void *>>(
        stlp_std::priv::_Vector_base<void *,stlp_std::allocator<void *> > *this)
{
  if ( this->_M_start )
    stlp_std::allocator<void *>::deallocate(
      &this->_M_end_of_storage,
      this->_M_start,
      this->_M_end_of_storage._M_data - this->_M_start);
}


void __usercall stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
        stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)a2 )
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, const char *, int))(**(_DWORD **)(a2 + 8) + 24))(
      *(_DWORD *)(a2 + 8),
      *(_DWORD *)a2,
      "vostok::detail::std_allocator<void *>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}


void __usercall stlp_std::priv::_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>::~_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>(
        stlp_std::priv::_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum> > *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)a2 )
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, const char *, int))(**(_DWORD **)(a2 + 8) + 24))(
      *(_DWORD *)(a2 + 8),
      *(_DWORD *)a2,
      "vostok::detail::std_allocator<enum survarium::profile_slot_enum>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}
