vostok::math::float4x4 *__userpurge boost::function1<vostok::math::float4x4,void const *>::operator()@<eax>(
        boost::function1<vostok::math::float4x4,void const *> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::float4x4 *result,
        const void *a0)
{
  const std::exception *v5; // eax
  const void *v6; // esi
  vostok::math::float4x4 *v7; // eax
  _BYTE v8[64]; // [esp+8h] [ebp-150h] BYREF
  stlp_std::out_of_range v9; // [esp+48h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v9);
    boost::throw_exception(v5);
    stlp_std::__Named_exception::~__Named_exception(&v9);
  }
  v6 = (const void *)(*(int (__cdecl **)(_BYTE *, _DWORD *, const void *))((*a2 & 0xFFFFFFFE) + 4))(v8, a2 + 2, a0);
  v7 = result;
  qmemcpy(result, v6, sizeof(vostok::math::float4x4));
  return v7;
}


void __userpurge boost::function1<void,vostok::collision::object const &>::operator()(
        boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *a0)
{
  const std::exception *v4; // eax
  stlp_std::out_of_range v5; // [esp+8h] [ebp-114h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  (*(void (__cdecl **)(_DWORD *, const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *))((*a2 & 0xFFFFFFFE) + 4))(
    a2 + 2,
    a0);
}


void __userpurge boost::function1<void,float>::operator()(
        boost::function1<void,float> *this@<ecx>,
        _DWORD *a2@<eax>,
        float a0)
{
  const std::exception *v4; // eax
  stlp_std::out_of_range v5; // [esp+Ch] [ebp-114h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  (*(void (__cdecl **)(_DWORD *, _DWORD))((*a2 & 0xFFFFFFFE) + 4))(a2 + 2, LODWORD(a0));
}


void __thiscall boost::function1<void,vostok::vfs::mount_result>::operator()(
        boost::function1<void,vostok::vfs::mount_result> *this,
        vostok::vfs::mount_result a0,
        boost::function1<void,vostok::vfs::mount_result> *a3)
{
  const std::exception *v3; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v4; // [esp-8h] [ebp-12Ch] BYREF
  boost::function1<void,vostok::vfs::mount_result> *v5; // [esp-4h] [ebp-128h]
  stlp_std::out_of_range v6; // [esp+10h] [ebp-114h] BYREF

  if ( !a0.mount.m_object->m_reference_count )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v6);
    boost::throw_exception(v3);
    stlp_std::__Named_exception::~__Named_exception(&v6);
  }
  v5 = this;
  v4.m_object = (vostok::vfs::vfs_mount *)this;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v4,
    (const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&a0.result);
  v5 = a3;
  (*(void (__cdecl **)(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *))((a0.mount.m_object->m_reference_count & 0xFFFFFFFE) + 4))(&a0.mount.m_object->next_in_children);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&a0.result);
}


void __userpurge boost::function1<void,boost::system::error_code>::operator()(
        boost::function2<void,vostok::math::float4x4 *,unsigned int> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::float4x4 *a0,
        unsigned int a1)
{
  const std::exception *v5; // eax
  stlp_std::out_of_range v6; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v6);
    boost::throw_exception(v5);
    stlp_std::__Named_exception::~__Named_exception(&v6);
  }
  (*(void (__cdecl **)(_DWORD *, vostok::math::float4x4 *, unsigned int))((*a2 & 0xFFFFFFFE) + 4))(a2 + 2, a0, a1);
}


void __userpurge boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
        boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *a0)
{
  const std::exception *v4; // eax
  stlp_std::out_of_range v5; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  (*(void (__cdecl **)(_DWORD *, const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *))((*a2 & 0xFFFFFFFE) + 4))(
    a2 + 2,
    a0);
}
