char __thiscall vostok::vfs::virtual_file_system::try_reference_to_pending_mount_unsafe(
        vostok::vfs::virtual_file_system *this,
        vostok::vfs::query_mount_arguments *args,
        bool *out_of_memory)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::memory::base_allocator *v6; // eax
  vostok::vfs::mount_referer *v7; // eax
  vostok::memory::base_allocator *allocator; // ecx
  vostok::threading::value_and_allocator<vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > *ready_referers_list; // eax
  vostok::vfs::mount_referer *v10; // [esp+0h] [ebp-88h]
  vostok::vfs::mount_referer *v11; // [esp+4h] [ebp-84h]
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *other; // [esp+18h] [ebp-70h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> v14; // [esp+3Ch] [ebp-4Ch] BYREF
  vostok::vfs::mount_referer *v15; // [esp+78h] [ebp-10h]
  vostok::vfs::same_mount_predicate pred; // [esp+7Ch] [ebp-Ch] BYREF
  vostok::vfs::mount_referer *referer; // [esp+80h] [ebp-8h]
  vostok::vfs::mounter *mount; // [esp+84h] [ebp-4h]

  *out_of_memory = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  pred.args = args;
  mount = vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::find_if<vostok::vfs::same_mount_predicate>(
            (vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)(&this->mount_history.gap0 + (_DWORD)&loc_2011E + 2),
            &pred);
  survarium::weapon_user_dead_state::finalize(v3);
  if ( !mount )
    return 0;
  survarium::weapon_user_dead_state::finalize(v4);
  referer = (vostok::vfs::mount_referer *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(v6, 0x30u);
  if ( referer )
  {
    v15 = (vostok::vfs::mount_referer *)operator new(0x30u, referer);
    if ( v15 )
    {
      vostok::vfs::mount_referer::mount_referer(v15);
      v10 = v7;
    }
    else
    {
      v10 = 0;
    }
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  referer = v11;
  if ( v11 )
  {
    allocator = args->allocator;
    referer->allocator = allocator;
    other = (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&referer->callback;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)allocator,
      &v14);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      &v14,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&args->callback);
    boost::function1<unsigned int,char const *>::swap(
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v14,
      other);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v14);
    ready_referers_list = vostok::vfs::get_ready_referers_list(args->allocator);
    referer->ready_list = &ready_referers_list->value;
    vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &mount->m_referers,
      referer,
      0);
    return 1;
  }
  else
  {
    *out_of_memory = 1;
    return 0;
  }
}
