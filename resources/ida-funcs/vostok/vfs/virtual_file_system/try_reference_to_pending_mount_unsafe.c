char __userpurge vostok::vfs::virtual_file_system::try_reference_to_pending_mount_unsafe@<al>(
        vostok::vfs::query_mount_arguments *args@<eax>,
        vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *a2@<ecx>,
        vostok::vfs::virtual_file_system *this,
        bool *out_of_memory)
{
  vostok::vfs::mounter *v5; // esi
  vostok::memory::base_allocator *allocator; // ebx
  char *v8; // eax
  int v9; // eax
  vostok::vfs::mount_referer *v10; // ebx
  vostok::threading::mutex *v11; // ecx
  vostok::vfs::same_mount_predicate pred; // [esp+Ch] [ebp-4h] BYREF

  *out_of_memory = 0;
  pred.args = args;
  v5 = vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::find_if<vostok::vfs::same_mount_predicate>(
         a2,
         (int)this + (_DWORD)&loc_2011E + 2,
         &pred);
  if ( !v5 )
    return 0;
  allocator = args->allocator;
  v8 = type_info::raw_name(&vostok::vfs::mount_referer `RTTI Type Descriptor');
  v9 = (int)allocator->call_malloc(
              allocator,
              48u,
              v8,
              "vostok::vfs::virtual_file_system::try_reference_to_pending_mount_unsafe",
              ".\\virtual_file_system.cpp",
              65u);
  v10 = (vostok::vfs::mount_referer *)v9;
  if ( !v9 )
  {
    *out_of_memory = 1;
    return 0;
  }
  *(_DWORD *)(v9 + 4) = 0;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 40) = 0;
  *(_DWORD *)(v9 + 44) = 0;
  *(_DWORD *)(v9 + 40) = args->allocator;
  boost::function<void __cdecl (vostok::vfs::mount_result)>::operator=(
    &args->callback,
    (boost::function1<void,vostok::physics::contact_point const &> *)(v9 + 8));
  v10->ready_list = vostok::threading::get_or_create_tls_value<vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>((unsigned int)args->allocator);
  vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &v5->m_referers,
    v10,
    v11);
  return 1;
}
