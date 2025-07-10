void __thiscall vostok::sound::composite_sound_cook::on_sub_resources_loaded(
        vostok::sound::composite_sound_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *v3; // ecx
  void *v4; // esp
  const vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  vostok::resources::class_id_enum id; // edx
  vostok::resources::request *v8; // eax
  vostok::memory::base_allocator *v9; // eax
  vostok::resources::query_result_for_cook *v10; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v11; // [esp-24h] [ebp-18Ch] BYREF
  boost::reference_wrapper<vostok::configs::binary_config_value const > v12; // [esp-20h] [ebp-188h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::configs::binary_config_value const &>,boost::_bi::list4<boost::_bi::value<vostok::sound::composite_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::reference_wrapper<vostok::configs::binary_config_value const > > > v13; // [esp-1Ch] [ebp-184h] BYREF
  assert_on_fail_bool v14; // [esp-4h] [ebp-16Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::configs::binary_config_value const &>,boost::_bi::list4<boost::_bi::value<vostok::sound::composite_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::reference_wrapper<vostok::configs::binary_config_value const > > > *v15; // [esp+0h] [ebp-168h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::configs::binary_config_value const &>,boost::_bi::list4<boost::_bi::value<vostok::sound::composite_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::reference_wrapper<vostok::configs::binary_config_value const > > > *result; // [esp+4h] [ebp-164h]
  vostok::resources::request *v17; // [esp+8h] [ebp-160h]
  vostok::sound::composite_sound_cook *thisa; // [esp+Ch] [ebp-15Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_a4; // [esp+18h] [ebp-150h]
  vostok::resources::memory_type *v20; // [esp+34h] [ebp-134h]
  int v21; // [esp+38h] [ebp-130h]
  vostok::resources::request *i; // [esp+3Ch] [ebp-12Ch]
  const vostok::resources::request *m_begin; // [esp+40h] [ebp-128h]
  unsigned int request_count; // [esp+44h] [ebp-124h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *v25; // [esp+50h] [ebp-118h]
  volatile int *value; // [esp+54h] [ebp-114h]
  vostok::resources::request *m_end; // [esp+58h] [ebp-110h]
  vostok::resources::request *v28; // [esp+5Ch] [ebp-10Ch]
  char v29; // [esp+63h] [ebp-105h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v30; // [esp+64h] [ebp-104h]
  const char **v31; // [esp+68h] [ebp-100h]
  const char *v32; // [esp+6Ch] [ebp-FCh]
  const char *v33; // [esp+70h] [ebp-F8h]
  char v34; // [esp+77h] [ebp-F1h]
  char *v35; // [esp+78h] [ebp-F0h]
  char *v36; // [esp+7Ch] [ebp-ECh]
  char v37; // [esp+82h] [ebp-E6h]
  char v38; // [esp+83h] [ebp-E5h]
  vostok::resources::request *v39; // [esp+84h] [ebp-E4h]
  int v40; // [esp+88h] [ebp-E0h]
  _BYTE *v41; // [esp+8Ch] [ebp-DCh]
  _BYTE *v42; // [esp+90h] [ebp-D8h]
  char v43; // [esp+97h] [ebp-D1h]
  int v44; // [esp+98h] [ebp-D0h]
  _BYTE *v45; // [esp+9Ch] [ebp-CCh]
  _BYTE *v46; // [esp+A0h] [ebp-C8h]
  char v47; // [esp+A7h] [ebp-C1h]
  _BYTE *v48; // [esp+A8h] [ebp-C0h]
  _BYTE *v49; // [esp+ACh] [ebp-BCh]
  char v50; // [esp+B3h] [ebp-B5h]
  const vostok::configs::binary_config_value *v51; // [esp+B4h] [ebp-B4h]
  const vostok::configs::binary_config_value *pointer; // [esp+B8h] [ebp-B0h]
  char v53; // [esp+BFh] [ebp-A9h]
  vostok::resources::memory_type *v54; // [esp+C0h] [ebp-A8h]
  int v55; // [esp+C4h] [ebp-A4h]
  vostok::configs::binary_config_value *m_root; // [esp+C8h] [ebp-A0h]
  vostok::configs::binary_config *m_object; // [esp+CCh] [ebp-9Ch]
  char v58; // [esp+D3h] [ebp-95h]
  vostok::configs::binary_config_value *v59; // [esp+D4h] [ebp-94h]
  vostok::configs::binary_config *v60; // [esp+D8h] [ebp-90h]
  char v61; // [esp+DFh] [ebp-89h]
  vostok::configs::binary_config *object; // [esp+E0h] [ebp-88h]
  vostok::resources::query_result_for_user *v63; // [esp+E4h] [ebp-84h]
  void (__thiscall *__ptr64 f)(vostok::sound::composite_sound_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, const vostok::configs::binary_config_value *); // [esp+ECh] [ebp-7Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> a3; // [esp+F8h] [ebp-70h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+100h] [ebp-68h] BYREF
  bool v67; // [esp+126h] [ebp-42h]
  char v68; // [esp+127h] [ebp-41h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v69; // [esp+128h] [ebp-40h] BYREF
  char v70; // [esp+12Fh] [ebp-39h]
  vostok::configs::binary_config *sound; // [esp+130h] [ebp-38h]
  vostok::resources::request request; // [esp+134h] [ebp-34h]
  const vostok::configs::binary_config_value *sound_value; // [esp+13Ch] [ebp-2Ch]
  unsigned int class_id; // [esp+140h] [ebp-28h]
  const vostok::configs::binary_config_value *sounds; // [esp+144h] [ebp-24h]
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+148h] [ebp-20h]
  const vostok::configs::binary_config_value *it; // [esp+150h] [ebp-18h]
  bool do_debug_break; // [esp+15Bh] [ebp-Dh] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+15Ch] [ebp-Ch] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+160h] [ebp-8h]
  const vostok::configs::binary_config_value *composite; // [esp+164h] [ebp-4h]

  thisa = this;
  v70 = 0;
  parent = data->m_parent_query;
  v63 = vostok::resources::queries_result::operator[](data, 0);
  boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &v69,
    &v63->m_unmanaged_resource);
  object = (vostok::configs::binary_config *)v69.m_object;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
    &config_ptr,
    (vostok::configs::binary_config *)v69.m_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v69);
  v68 = 1;
  if ( debug_macro_helper_ignore_always
    || (v61 = 0,
        v60 = config_ptr.m_object,
        v59 = config_ptr.m_object->m_root,
        v67 = vostok::configs::binary_config_value::value_exists(v59, "composite_sound")) )
  {
    v58 = 0;
    m_object = config_ptr.m_object;
    m_root = config_ptr.m_object->m_root;
    composite = vostok::configs::binary_config_value::operator[](m_root, "composite_sound");
    if ( !vostok::configs::binary_config_value::value_exists(
            (vostok::configs::binary_config_value *)composite,
            "sound_items")
      && !vostok::sound::composite_sound_cook::create_sound(thisa, composite) )
    {
      v54 = &vostok::resources::unmanaged_memory;
      v55 = 288;
      v3 = parent;
      parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
      v3->m_out_of_memory.size = 288;
      vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
      return;
    }
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)composite,
           "sound_items") )
    {
      sounds = vostok::configs::binary_config_value::operator[](
                 (vostok::configs::binary_config_value *)composite,
                 "sound_items");
      v53 = 0;
      pointer = (const vostok::configs::binary_config_value *)sounds->data.pointer;
      v51 = pointer;
      it = pointer;
      v50 = 0;
      v49 = sounds->data.pointer;
      v48 = v49;
      v4 = alloca(
             8
           * (((char *)vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)sounds) - v49)
            / 24));
      v39 = (vostok::resources::request *)&v15;
      v47 = 0;
      v46 = sounds->data.pointer;
      v45 = v46;
      v5 = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)sounds);
      v44 = ((char *)v5 - v45) / 24;
      v43 = 0;
      v42 = sounds->data.pointer;
      v41 = v42;
      v6 = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)sounds);
      v40 = ((char *)v6 - v41) / 24;
      requests.m_begin = v39;
      requests.m_end = v39;
      v38 = 0;
      while ( 1 )
      {
        v37 = 0;
        v36 = (char *)sounds->data.pointer;
        v35 = v36;
        if ( it == (const vostok::configs::binary_config_value *)&v36[24 * sounds->count] )
          break;
        sound_value = it;
        v31 = (const char **)vostok::configs::binary_config_value::operator[](
                               (vostok::configs::binary_config_value *)it,
                               "filename");
        v34 = 0;
        v33 = *v31;
        v32 = v33;
        request.path = v33;
        v30 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)sound_value, "resource_type");
        class_id = (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v30);
        request.id = class_id;
        v29 = 0;
        m_end = requests.m_end;
        v28 = requests.m_end;
        if ( requests.m_end )
        {
          id = request.id;
          v8 = v28;
          v28->path = request.path;
          v8->id = id;
          v17 = v28;
        }
        else
        {
          v17 = 0;
        }
        ++requests.m_end;
        ++it;
      }
      LODWORD(f) = vostok::sound::composite_sound_cook::on_sounds_loaded;
      HIDWORD(f) = 0;
      a3.m_object = (vostok::configs::binary_config *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)sounds);
      v14 = assert_on_fail_false;
      result = &v13;
      v12.t_ = (const vostok::configs::binary_config_value *)a3.m_object;
      v25 = (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v11;
      v11.m_object = 0;
      if ( config_ptr.m_object )
      {
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v25);
        v25->m_object = (survarium::game_world_object *)config_ptr.m_object;
        if ( v25->m_object )
        {
          value = &v25->m_object->m_reference_count;
          vostok::threading::multi_threading_policy::increment<long volatile>(value);
        }
      }
      v15 = boost::bind<void,vostok::sound::composite_sound_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::configs::binary_config_value const &,vostok::sound::composite_sound_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,boost::reference_wrapper<vostok::configs::binary_config_value const>>(
              result,
              f,
              thisa,
              1_7,
              v11,
              v12);
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        &callback,
        v13,
        v14);
      request_count = requests.m_end - requests.m_begin;
      m_begin = requests.m_begin;
      v14 = assert_on_fail_true;
      *((_DWORD *)&v13.l_ + 3) = parent;
      v13.l_.a4_.t_ = 0;
      v9 = vostok::resources::unmanaged_allocator();
      vostok::resources::query_resources(
        m_begin,
        request_count,
        &callback,
        v9,
        (const vostok::variant<32> **)v13.l_.a4_.t_,
        *((vostok::resources::query_result_for_cook **)&v13.l_ + 3),
        v14);
      if ( callback.vtable )
      {
        if ( ((int)callback.vtable & 1) == 0 )
          boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
            (boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((int)callback.vtable & 0xFFFFFFFE),
            &callback.functor);
        callback.vtable = 0;
      }
      for ( i = requests.m_begin; i != requests.m_end; ++i )
        ;
      requests.m_end = requests.m_begin;
    }
    else
    {
      sound = (vostok::configs::binary_config *)vostok::sound::composite_sound_cook::create_sound(thisa, composite);
      if ( !sound )
      {
        v20 = &vostok::resources::unmanaged_memory;
        v21 = 288;
        v10 = parent;
        parent->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
        v10->m_out_of_memory.size = 288;
        vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
        return;
      }
      v14 = 288;
      *((_DWORD *)&v13.l_ + 3) = &vostok::resources::nocache_memory;
      p_a4 = (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13.l_.a4_;
      v13.l_.a4_.t_ = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13.l_.a4_,
        sound);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        parent,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v13.l_.a4_.t_,
        *((const vostok::resources::memory_type **)&v13.l_ + 3),
        v14);
      vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    }
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
  }
  else
  {
    if ( occurances_left == -1 )
      occurances_left = 10;
    if ( occurances_left-- )
    {
      if ( !debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "config_ptr->get_root().value_exists( \"composite_sound\" )",
          ".\\composite_sound_cook.cpp",
          "vostok::sound::composite_sound_cook::on_sub_resources_loaded",
          0x30u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
  }
}
