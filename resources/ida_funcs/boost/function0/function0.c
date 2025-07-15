void __userpurge boost::function0<void>::function0<void>(
        boost::function0<void> *this@<ecx>,
        int a2@<esi>,
        void (__cdecl *f)(),
        int __formal)
{
  *(_DWORD *)a2 = 0;
  if ( `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable )
    `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable(
      (const boost::detail::function::function_buffer *)(a2 + 8),
      (boost::detail::function::function_buffer *)(a2 + 8),
      destroy_functor_tag);
  if ( f )
  {
    *(_DWORD *)(a2 + 8) = f;
    *(_DWORD *)a2 = (char *)&`boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable + 1;
  }
  else
  {
    *(_DWORD *)a2 = 0;
  }
}
