void __thiscall survarium::game::on_configs_loaded(survarium::game *this, vostok::resources::queries_result *result)
{
  vostok::input::engine *v3; // esi
  HWND__ *v4; // eax
  survarium::game *v5; // ecx
  survarium::key_binder *v6; // esi
  survarium::key_binder *v7; // eax
  survarium::game *v8; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // esi
  survarium::game *v10; // ecx
  vostok::engine_user::engine *m_engine; // ecx
  HWND__ *(__thiscall *get_render_window_handle)(vostok::engine_user::engine *); // eax
  boost::detail::function::vtable_base *v13; // eax
  survarium::scaleform_render_command_queue *m_render_thread_queue; // edx
  vostok::engine_user::engine *v15; // ecx
  vostok::engine_user::engine_vtbl *v16; // eax
  bool (__thiscall *command_line_editor)(vostok::engine_user::engine *); // edx
  vostok::console_commands::console_command *v18; // eax
  void (__cdecl *v19)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v20; // [esp+300h] [ebp-C8h] BYREF
  int v21; // [esp+310h] [ebp-B8h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+320h] [ebp-A8h] BYREF
  vostok::variant<32> *user_data; // [esp+344h] [ebp-84h] BYREF
  __int64 v24; // [esp+348h] [ebp-80h] BYREF
  __int64 v25; // [esp+350h] [ebp-78h]
  vostok::console_commands::console_command *v26; // [esp+35Ch] [ebp-6Ch]
  vostok::resources::request v27; // [esp+360h] [ebp-68h] BYREF
  _DWORD v28[2]; // [esp+368h] [ebp-60h] BYREF
  _QWORD v29[2]; // [esp+370h] [ebp-58h] BYREF
  void *v30; // [esp+380h] [ebp-48h]
  _DWORD *v31; // [esp+390h] [ebp-38h]
  int v32; // [esp+394h] [ebp-34h]
  char v33[32]; // [esp+3A0h] [ebp-28h] BYREF
  int v34; // [esp+3C0h] [ebp-8h]
  int v35; // [esp+3C4h] [ebp-4h]

  if ( this )
    v3 = (vostok::input::engine *)&this->gap8;
  else
    v3 = 0;
  v4 = this->m_engine->get_main_window_handle(this->m_engine);
  this->m_input_world = vostok::input::create_world(v3, v4);
  survarium::game::initialize_ui(v5);
  v6 = (survarium::key_binder *)vostok::memory::doug_lea_allocator::malloc_impl(
                                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                  0x304u);
  if ( v6 )
    survarium::key_binder::key_binder(v6, this);
  else
    v7 = 0;
  *((_DWORD *)&v20.l_ + 1) = 0;
  this->m_key_binder = v7;
  v20.l_.a1_.t_ = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v20.l_,
    &result->m_queries[0].m_managed_resource);
  survarium::game::load_cc_script(
    v8,
    (unsigned int)this,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v20.l_.a1_.t_,
    *((const vostok::variant<32> **)&v20.l_ + 1));
  p_m_managed_resource = &result->m_queries[1].m_managed_resource;
  *(_QWORD *)&v20.l_.a1_.t_ = 0x100000000LL;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v20.l_,
    &result->m_queries[1].m_managed_resource);
  survarium::game::load_cc_script(
    v10,
    (unsigned int)this,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v20.l_.a1_.t_,
    *((const vostok::variant<32> **)&v20.l_ + 1));
  *((_DWORD *)&v20.l_ + 1) = &this->m_text_translator;
  survarium::text_translator::load_text_localization(&this->m_text_translator);
  m_engine = this->m_engine;
  get_render_window_handle = m_engine->get_render_window_handle;
  (&callback.vtable)[1] = 0;
  callback.functor.obj_ptr = 0;
  v13 = (boost::detail::function::vtable_base *)get_render_window_handle(m_engine);
  m_render_thread_queue = this->m_flash_factory->m_render_thread_queue;
  v15 = this->m_engine;
  callback.vtable = v13;
  v16 = v15->__vftable;
  callback.functor.vostok_pointer_size_alignment[2] = m_render_thread_queue;
  command_line_editor = v16->command_line_editor;
  WORD2(callback.functor.bound_memfunc_ptr.memfunc_ptr) = 257;
  if ( !command_line_editor(v15) )
  {
    p_m_managed_resource = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)"r_resolution";
    v26 = vostok::console_commands::find("r_fullscreen");
    v18 = vostok::console_commands::find("r_resolution");
    survarium::parse_resolution((char *)v18[1].__vftable, (int *)&v24);
    *(_QWORD *)&(&callback.vtable)[1] = v24;
    callback.functor.type.volatile_qualified = v26[1].~vostok::console_commands::console_command == 0;
  }
  v31 = 0;
  v32 = 0;
  v32 = vostok::detail::type_to_int<vostok::render::output_window_configuration>::get();
  user_data = (vostok::variant<32> *)v28;
  v29[0] = *(_QWORD *)&callback.vtable;
  LODWORD(v24) = survarium::game::on_render_output_window_created;
  v29[1] = *(_QWORD *)&callback.functor.obj_ptr;
  HIDWORD(v24) = 0;
  v20.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, vostok::resources::queries_result *))(unsigned int)survarium::game::on_render_output_window_created;
  LODWORD(v25) = this;
  v30 = callback.functor.vostok_pointer_size_alignment[2];
  v28[0] = &vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::`vftable';
  v31 = v28;
  v34 = 0;
  v35 = 0;
  v27.path = "game_render_output_window";
  v27.id = render_output_window_class;
  *(_QWORD *)&v20.l_.a1_.t_ = v25;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    (boost::function1<void,vostok::resources::queries_result &> *)callback.functor.vostok_pointer_size_alignment[2],
    (int)&callback,
    (int)p_m_managed_resource,
    v20,
    v21);
  vostok::resources::query_resources(
    &v27,
    1u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&user_data,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v19 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v19 )
        v19(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v34 )
  {
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v34 + 4))(v34, v33);
    v34 = 0;
  }
  if ( v31 )
    (*(void (__thiscall **)(_DWORD *, _QWORD *))(*v31 + 4))(v31, v29);
}
