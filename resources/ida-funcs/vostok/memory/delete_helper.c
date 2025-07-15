void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::network_core::tcp_packet const>(
        vostok::memory::base_allocator *allocator,
        vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **pointer,
        const char *function,
        const char *file,
        unsigned int line)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v6; // edi
  vostok::network_core::mutable_buffer *v7; // ecx

  v6 = *pointer;
  if ( *pointer )
  {
    vostok::network_core::buffer_writer::~buffer_writer(v5, v6 + 1);
    vostok::network_core::mutable_buffer::~mutable_buffer(v7, v6);
    allocator->call_free(allocator, v6, function, file, line);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::animation::base_interpolator>(
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::animation::base_interpolator **pointer@<esi>,
        const char *function,
        const char *file,
        unsigned int line)
{
  _BYTE *v5; // ebx

  if ( *pointer )
  {
    v5 = __RTCastToVoid((void **)&(*pointer)->__vftable);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::animation::base_interpolator)(*pointer, 0);
    allocator->call_free(allocator, v5, function, file, line);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,Opcode::AABBOptimizedTree>(
        vostok::memory::base_allocator *allocator@<edi>,
        Opcode::AABBOptimizedTree **pointer@<esi>,
        const char *function,
        const char *const file)
{
  _BYTE *v4; // ebx

  if ( *pointer )
  {
    v4 = __RTCastToVoid((void **)&(*pointer)->__vftable);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~Opcode::AABBOptimizedTree)(*pointer, 0);
    allocator->call_free(allocator, v4, function, ".\\OPC_BaseModel.cpp", (const unsigned int)file);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,btCompoundShape>(
        vostok::memory::base_allocator *allocator@<edi>,
        btCompoundShape **pointer@<esi>,
        const char *const function)
{
  _BYTE *v3; // ebx

  if ( *pointer )
  {
    v3 = __RTCastToVoid((void **)&(*pointer)->__vftable);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~btCompoundShape)(*pointer, 0);
    allocator->call_free(
      allocator,
      v3,
      "vostok::physics::destroy_animated_compound_shape",
      ".\\animated_rigid_body.cpp",
      (const unsigned int)function);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::animation::legs_ik_drawer>(
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **pointer@<edi>,
        vostok::memory::base_allocator *allocator)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // esi

  v2 = *pointer;
  if ( *pointer )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v2 + 1);
    allocator->call_free(
      allocator,
      v2,
      "vostok::animation::legs_ik_solver::~legs_ik_solver",
      ".\\legs_ik_solver.cpp",
      63u);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::resources::resource_base **pointer@<esi>,
        const char *function,
        const char *file,
        unsigned int line)
{
  _BYTE *v5; // ebx

  if ( *pointer )
  {
    v5 = __RTCastToVoid((void **)&(*pointer)->__vftable);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::resources::resource_base)(*pointer, 0);
    allocator->call_free(allocator, v5, function, file, line);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> **pointer@<edi>,
        vostok::memory::base_allocator *allocator,
        const char *const function)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v3; // esi

  v3 = *pointer;
  if ( *pointer )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(v3 + 9);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(v3 + 8);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(v3 + 5);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(v3 + 2);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(v3 + 1);
    allocator->call_free(
      allocator,
      v3,
      "vostok::vfs::vfs_intrusive_mount_base::destroy",
      ".\\mount_ptr.cpp",
      (const unsigned int)function);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
        vostok::vectora<unsigned __int64> **pointer@<edi>,
        vostok::memory::base_allocator *allocator,
        const char *const function)
{
  _DWORD **v3; // esi

  v3 = (_DWORD **)*pointer;
  if ( *pointer )
  {
    if ( *v3 )
      (*(void (__thiscall **)(_DWORD *, _DWORD, const char *, const char *, int))(*v3[2] + 24))(
        v3[2],
        *v3,
        "vostok::detail::std_allocator<unsigned __int64>::deallocate",
        "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
        102);
    allocator->call_free(
      allocator,
      v3,
      "vostok::sound::world_user::finalize",
      ".\\world_user.cpp",
      (const unsigned int)function);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::fsm>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::fsm **pointer)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  int v3; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+4h] [ebp-8h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  v3 = (int)*pointer;
  if ( *pointer )
  {
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v2,
      (int *)(v3 + 24));
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)allocator, (char *)v3, v5, v6, v7);
    *pointer = 0;
  }
}
