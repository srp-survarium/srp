void __thiscall vostok::sound::sound_scene::unregister_receiver(
        vostok::sound::sound_scene *this,
        vostok::sound::world_user *user,
        vostok::sound::sound_receiver *receiver)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+1Fh] [ebp-A5h] BYREF
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *allocator; // [esp+20h] [ebp-A4h]
  char v6; // [esp+27h] [ebp-9Dh]
  vostok::collision::object *m_collision; // [esp+28h] [ebp-9Ch]
  char v8; // [esp+2Fh] [ebp-95h]
  vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> v9; // [esp+50h] [ebp-74h] BYREF
  vostok::sound::receiver_collision *v10; // [esp+54h] [ebp-70h]
  int v11; // [esp+58h] [ebp-6Ch]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v12; // [esp+5Ch] [ebp-68h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v13; // [esp+7Ch] [ebp-48h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v14; // [esp+9Ch] [ebp-28h] BYREF
  vostok::sound::compare_receivers_predicate pred; // [esp+BCh] [ebp-8h] BYREF
  vostok::sound::receiver_collision *collision; // [esp+C0h] [ebp-4h] BYREF

  v11 = 0;
  pred.m_receiver = receiver;
  v9.m_predicate_ref = &pred;
  v10 = vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::find_if<vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate>>(
          &this->m_receivers,
          &v9);
  collision = v10;
  if ( v10 )
  {
    vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
      &this->m_receivers,
      collision);
    v8 = 0;
    m_collision = collision->m_collision;
    this->m_spatial_tree->erase(this->m_spatial_tree, m_collision);
    vostok::sound::receiver_collision::delete_position(collision, this);
    v6 = 0;
    allocator = this->m_receiver_collisions_allocator.m_variable;
    call_destructor_predicate = 0;
    vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>,vostok::sound::receiver_collision,vostok::memory::detail::call_destructor_predicate>(
      allocator,
      &collision,
      &call_destructor_predicate);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
    {
      v14.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v14,
        vostok::core::g_log_callback);
      v11 |= 1u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v14,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene.cpp",
        0x360u,
        "void __thiscall vostok::sound::sound_scene::unregister_receiver(class vostok::sound::world_user &,class vostok::"
        "sound::sound_receiver *)",
        "sound:",
        error,
        "attempt to delete not unregistered receiver");
    }
    if ( (v11 & 1) != 0 )
    {
      v11 &= ~1u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v14);
    }
  }
  vostok::sound::world_user::on_receiver_deleted(user, (int)receiver);
  if ( this->m_receivers.m_first )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
    {
      v13.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v13,
        vostok::core::g_log_callback);
      v11 |= 2u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene.cpp",
        0x365u,
        "void __thiscall vostok::sound::sound_scene::unregister_receiver(class vostok::sound::world_user &,class vostok::"
        "sound::sound_receiver *)",
        "sound:",
        info,
        "sound receiver unregistered, but list of registered receivers isn't empty");
    }
    if ( (v11 & 2) != 0 )
    {
      v11 &= ~2u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v13);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
    {
      v12.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v12,
        vostok::core::g_log_callback);
      v11 |= 4u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v12,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene.cpp",
        0x367u,
        "void __thiscall vostok::sound::sound_scene::unregister_receiver(class vostok::sound::world_user &,class vostok::"
        "sound::sound_receiver *)",
        "sound:",
        info,
        "list of registered receivers is empty");
    }
    if ( (v11 & 4) != 0 )
    {
      v11 &= ~4u;
      if ( v12.vtable )
      {
        if ( ((int)v12.vtable & 1) == 0 )
          boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
            (boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((int)v12.vtable & 0xFFFFFFFE),
            &v12.functor);
      }
    }
  }
}
