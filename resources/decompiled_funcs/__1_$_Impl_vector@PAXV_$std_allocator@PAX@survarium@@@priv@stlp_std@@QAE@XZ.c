void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
        survarium::vector<vostok::resources::request> *this@<ecx>,
        void **a2@<eax>)
{
  void *v2; // eax
  void *v3; // esi

  v2 = *a2;
  if ( v2 )
  {
    v3 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v3, v2);
  }
}
