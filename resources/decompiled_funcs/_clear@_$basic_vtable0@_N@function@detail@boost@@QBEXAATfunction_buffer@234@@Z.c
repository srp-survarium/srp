void __usercall boost::detail::function::basic_vtable0<bool>::clear(
        boost::detail::function::basic_vtable0<bool> *this@<ecx>,
        void (__cdecl **a2)(boost::detail::function::basic_vtable0<bool> *, boost::detail::function::basic_vtable0<bool> *, int)@<eax>)
{
  void (__cdecl *v2)(boost::detail::function::basic_vtable0<bool> *, boost::detail::function::basic_vtable0<bool> *, int); // eax

  v2 = *a2;
  if ( v2 )
    v2(this, this, 2);
}
