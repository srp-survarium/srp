void __usercall survarium::std_allocator<survarium::base_project::resolve_link_object>::deallocate(
        survarium::base_project::resolve_link_object *p@<eax>,
        survarium::std_allocator<survarium::base_project::resolve_link_object> *this)
{
  void *v2; // esi

  if ( p )
  {
    v2 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v2, p);
  }
}
