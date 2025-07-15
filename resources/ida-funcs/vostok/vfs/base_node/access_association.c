void __thiscall vostok::vfs::base_node<1>::access_association(
        vostok::vfs::base_node<1> *this,
        const boost::function<void __cdecl(vostok::vfs::vfs_association * &)> *callback,
        _DWORD *a3)
{
  volatile signed __int32 *v3; // edi
  unsigned int v4; // ecx
  _DWORD *v5; // eax
  const std::exception *v6; // eax
  volatile signed __int32 v7; // ecx
  stlp_std::out_of_range v8; // [esp+Ch] [ebp-114h] BYREF
  void *obj_ptr; // [esp+11Ch] [ebp-4h] BYREF

  v3 = (volatile signed __int32 *)&callback[1].functor.vostok_pointer_size_alignment[2];
  do
    v4 = *v3 & 0xFFFEFFFF;
  while ( _InterlockedCompareExchange(v3, (unsigned int)&_sbh_sizeHeaderList | v4, v4) != v4 );
  obj_ptr = callback[1].functor.obj_ptr;
  v5 = a3;
  if ( !*a3 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)v4, (stlp_std::runtime_error *)&v8);
    boost::throw_exception(v6);
    stlp_std::__Named_exception::~__Named_exception(&v8);
    v5 = a3;
  }
  (*(void (__cdecl **)(_DWORD *, void **))((*v5 & 0xFFFFFFFE) + 4))(v5 + 2, &obj_ptr);
  callback[1].functor.obj_ptr = obj_ptr;
  do
    v7 = *v3;
  while ( _InterlockedCompareExchange(v3, *v3 & 0xFFFEFFFF, *v3) != v7 );
}
