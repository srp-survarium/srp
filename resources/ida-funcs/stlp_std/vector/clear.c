void __usercall stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::clear(
        stlp_std::vector<char const *,vostok::vectora_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<esi>)
{
  unsigned __int8 *v2; // eax

  v2 = a2[1];
  if ( *a2 != v2 )
    a2[1] = stlp_std::priv::__copy_trivial(v2, v2, *a2);
}
