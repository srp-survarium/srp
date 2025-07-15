void __userpurge survarium::lobby_menu::on_operation_denied_received(
        vostok::lobby_client_message_types_enum op_type@<eax>,
        survarium::lobby_menu *this,
        const char *description)
{
  survarium::lobby_menu *v4; // ecx
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v6; // bl
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-6Ch] BYREF
  survarium::flash_value v[3]; // [esp+30h] [ebp-4Ch] BYREF

  switch ( op_type )
  {
    case set_status_ready_for_match:
    case inventory_action:
    case shop_action:
    case skills_tree_action:
      `vector constructor iterator'(
        v[0].body,
        0x18u,
        3,
        (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
      survarium::flash_value::SetUInt(v, 0x63u);
      survarium::flash_value::SetString(&v[1], "debug");
      survarium::flash_value::SetString(&v[2], description);
      Scaleform::GFx::Movie::Invoke(
        this->m_message_ui.m_object->movie->m_movie,
        "root.showMessage",
        0,
        (const Scaleform::GFx::Value *)v,
        3u);
      survarium::lobby_menu::request_status_from_server(v4, (int)this, 0x1F4u);
      `vector destructor iterator'(
        v[0].body,
        0x18u,
        3,
        (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
      break;
    default:
      if ( vostok::core::g_log_filter_tree
        && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v6 = 0;
      }
      else
      {
        v5 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v5 )
        {
          log_callback.functor.obj_ptr = v5;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v6 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x18Cu,
          "void __thiscall survarium::lobby_menu::on_operation_denied_received(enum vostok::lobby_client_message_types_en"
          "um,const char *)",
          "game:",
          error,
          "Unknown (operation denied) type received %d",
          op_type);
      }
      if ( (v6 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&log_callback.functor, &log_callback.functor, 2);
      }
      break;
  }
}
