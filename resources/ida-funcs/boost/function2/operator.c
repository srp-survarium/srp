int __userpurge boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()@<eax>(
        boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a0,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a1)
{
  const std::exception *v5; // eax
  stlp_std::out_of_range v7; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v7);
    boost::throw_exception(v5);
    stlp_std::__Named_exception::~__Named_exception(&v7);
  }
  return (*(int (__cdecl **)(_DWORD *, const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *, const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *))((*a2 & 0xFFFFFFFE) + 4))(
           a2 + 2,
           a0,
           a1);
}
