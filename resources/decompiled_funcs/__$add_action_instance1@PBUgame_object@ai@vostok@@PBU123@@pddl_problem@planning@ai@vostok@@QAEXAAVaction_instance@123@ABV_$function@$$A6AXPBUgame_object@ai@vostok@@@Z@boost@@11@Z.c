void __thiscall vostok::ai::planning::pddl_problem::add_action_instance1<vostok::ai::game_object const *,vostok::ai::game_object const *>(
        vostok::ai::planning::pddl_problem *this,
        vostok::ai::planning::action_instance *result,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *initializer,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *executor,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *finalizer)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v6; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v7; // ecx
  void *value; // [esp+28h] [ebp-14h] BYREF
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v10; // [esp+2Ch] [ebp-10h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v11; // [esp+30h] [ebp-Ch]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v12; // [esp+34h] [ebp-8h]
  char v13; // [esp+3Bh] [ebp-1h]

  v13 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(initializer) )
  {
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&result->m_initialize_storage);
    v12 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)operator new(
                                                                                0x20u,
                                                                                &result->m_initialize_storage);
    if ( v12 )
    {
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, v12);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
        v12,
        initializer);
    }
    result->m_initialize_binder = vostok::ai::planning::initialize_binder<vostok::ai::game_object const *,vostok::ai::game_object const *>;
  }
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(executor) )
  {
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&result->m_execute_storage);
    v11 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)operator new(
                                                                                0x20u,
                                                                                &result->m_execute_storage);
    if ( v11 )
    {
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v6, v11);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
        v11,
        executor);
    }
    result->m_execute_binder = vostok::ai::planning::execute_binder<vostok::ai::game_object const *,vostok::ai::game_object const *>;
  }
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(finalizer) )
  {
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&result->m_finalize_storage);
    v10 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)operator new(
                                                                                0x20u,
                                                                                &result->m_finalize_storage);
    if ( v10 )
    {
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v7, v10);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
        v10,
        finalizer);
    }
    result->m_finalize_binder = vostok::ai::planning::finalize_binder<vostok::ai::game_object const *,vostok::ai::game_object const *>;
  }
  value = result;
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    (vostok::buffer_vector<void const *> *)this,
    (const void **)&value);
}
