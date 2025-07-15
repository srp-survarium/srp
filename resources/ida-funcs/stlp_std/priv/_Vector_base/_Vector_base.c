void __usercall stlp_std::priv::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::priv::_Vector_base<unsigned char,stlp_std::allocator<unsigned char> > *this@<ecx>,
        unsigned __int8 **a2@<esi>)
{
  unsigned __int8 *v2; // eax
  unsigned __int8 *M_data; // ecx
  stlp_std::priv::_STLP_alloc_proxy<unsigned char *,unsigned char,stlp_std::allocator<unsigned char> > v4; // [esp+0h] [ebp-4h] BYREF

  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  v2 = stlp_std::priv::_STLP_alloc_proxy<unsigned char *,unsigned char,stlp_std::allocator<unsigned char>>::allocate(
         0x4400u,
         (unsigned int)&v4,
         &v4,
         (unsigned int *)0x4400);
  M_data = v4._M_data;
  *a2 = v2;
  a2[1] = v2;
  a2[2] = &v2[(_DWORD)M_data];
}
