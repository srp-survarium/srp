void __userpurge survarium::damage_model_cook::on_hit_params_received(
        survarium::damage_model_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data)
{
  survarium::game_camera *v3; // ecx
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  vostok::configs::binary_config *v9; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // eax
  survarium::game_camera *v13; // ecx
  vostok::console_commands::cc_token *v14; // eax
  vostok::memory::stack_allocator *v15; // ecx
  vostok::resources::query_result_for_cook *v16; // ecx
  survarium::game_camera *v17; // ecx
  survarium::game_camera *v18; // ecx
  vostok::memory::stack_allocator *v19; // eax
  survarium::game_camera *v20; // eax
  survarium::game_camera *v21; // ecx
  vostok::resources::memory_usage_type *v22; // eax
  vostok::resources::unmanaged_resource *v23; // ecx
  vostok::memory::stack_allocator *v24; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v25[2]; // [esp-4h] [ebp-124h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-11Ch]
  survarium::damage_model *v27; // [esp+8h] [ebp-118h]
  vostok::console_commands::cc_token *v28; // [esp+Ch] [ebp-114h]
  survarium::damage_model_cook *thisa; // [esp+10h] [ebp-110h]
  void *v30; // [esp+18h] [ebp-108h]
  vostok::memory::stack_allocator *v31; // [esp+1Ch] [ebp-104h]
  vostok::memory::doug_lea_allocator *allocator; // [esp+20h] [ebp-100h]
  const vostok::console_commands::command_token *commands; // [esp+24h] [ebp-FCh]
  char v34; // [esp+2Bh] [ebp-F5h]
  unsigned int size; // [esp+2Ch] [ebp-F4h]
  void *_Where; // [esp+30h] [ebp-F0h]
  vostok::memory::doug_lea_allocator *v37; // [esp+34h] [ebp-ECh]
  vostok::fixed_string<24> *v38; // [esp+44h] [ebp-DCh]
  char v39; // [esp+4Bh] [ebp-D5h]
  char *src; // [esp+58h] [ebp-C8h]
  unsigned int max_count[9]; // [esp+5Ch] [ebp-C4h] BYREF
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v42; // [esp+80h] [ebp-A0h] BYREF
  char v43; // [esp+8Bh] [ebp-95h]
  survarium::damage_model *v44; // [esp+8Ch] [ebp-94h]
  char v45; // [esp+93h] [ebp-8Dh]
  void *v46; // [esp+94h] [ebp-8Ch]
  vostok::fixed_string<24> v47; // [esp+98h] [ebp-88h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v48; // [esp+BCh] [ebp-64h] BYREF
  char v49; // [esp+C3h] [ebp-5Dh]
  vostok::console_commands::command_token new_command; // [esp+C4h] [ebp-5Ch] BYREF
  unsigned int i; // [esp+CCh] [ebp-54h]
  const vostok::configs::binary_config_value *hit_types; // [esp+D0h] [ebp-50h]
  const vostok::configs::binary_config_value *it_hit_end; // [esp+D4h] [ebp-4Ch]
  const vostok::configs::binary_config_value *it_hit; // [esp+D8h] [ebp-48h]
  vostok::variant<32> *ud; // [esp+DCh] [ebp-44h]
  const vostok::configs::binary_config_value *params_value; // [esp+E0h] [ebp-40h]
  const char *description; // [esp+E4h] [ebp-3Ch]
  void *model_buffer; // [esp+E8h] [ebp-38h]
  survarium::damage_model *new_model; // [esp+ECh] [ebp-34h]
  vostok::resources::query_result_for_cook *parent; // [esp+F0h] [ebp-30h]
  unsigned int model_buffer_size; // [esp+F4h] [ebp-2Ch]
  survarium::affects_applying_type_enum affects_applying_type; // [esp+F8h] [ebp-28h] BYREF
  const vostok::configs::binary_config_value *config_value; // [esp+FCh] [ebp-24h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+100h] [ebp-20h] BYREF
  vostok::memory::stack_allocator stack_allocator; // [esp+104h] [ebp-1Ch] BYREF
  const vostok::configs::binary_config_value *damage_groups; // [esp+11Ch] [ebp-4h]

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v4 = vostok::resources::queries_result::operator[](data, 0);
    unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                           v5,
                           (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4,
                           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v48);
    vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
      &config);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v48);
    v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&config);
    config_value = vostok::configs::binary_config::get_root(v9, (int)v8);
    params_value = vostok::configs::binary_config_value::operator[](
                     (vostok::configs::binary_config_value *)config_value,
                     "hit_params");
    damage_groups = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)config_value,
                      "damage_groups");
    if ( !hit_types_initialized )
    {
      hit_types = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)config_value,
                    "hit_types_available");
      it_hit = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)hit_types);
      it_hit_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)hit_types);
      i = 0;
      while ( it_hit != it_hit_end )
      {
        src = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                        v10,
                        (int)it_hit);
        max_count[0] = 24;
        vostok::buffer_string::buffer_string(&v47, v47.m_buffer, max_count, src);
        vostok::buffer_vector<vostok::fixed_string<24>>::push_back(
          &survarium::damage_model_cook::m_hit_types_strings,
          &v47);
        new_command.id = i;
        v39 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
        v38 = survarium::damage_model_cook::m_hit_types_strings.m_end - 1;
        new_command.name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                           v11,
                                           (int)&survarium::damage_model_cook::m_hit_types_strings.m_end[-1]);
        vostok::buffer_vector<vostok::console_commands::command_token>::push_back(
          &survarium::damage_model_cook::m_hit_types,
          &new_command);
        ++it_hit;
        v10 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)++i;
      }
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v10);
      v37 = v12;
      _Where = vostok::memory::doug_lea_allocator::malloc_impl(v12, 0x50u);
      v46 = operator new(0x50u, _Where);
      if ( v46 )
      {
        size = survarium::damage_model_cook::m_hit_types.m_end - survarium::damage_model_cook::m_hit_types.m_begin;
        v34 = 0;
        survarium::weapon_user_dead_state::finalize(v13);
        commands = survarium::damage_model_cook::m_hit_types.m_begin;
        vostok::console_commands::cc_token::cc_token(
          (vostok::console_commands::cc_token *)survarium::damage_model_cook::m_hit_types.m_begin,
          (int)v46,
          "hit_type",
          &g_current_hit_type,
          survarium::damage_model_cook::m_hit_types.m_begin,
          size,
          0,
          command_type_user_specific,
          execution_filter_general);
        v28 = v14;
      }
      else
      {
        v28 = 0;
      }
      survarium::damage_model_cook::m_hit_types_commands = v28;
      hit_types_initialized = 1;
    }
    model_buffer_size = survarium::calculate_model_size((vostok::configs::binary_config_value *)params_value);
    description = "damage_model_memory";
    allocator = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
    model_buffer = vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                     (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                     model_buffer_size);
    vostok::memory::stack_allocator::stack_allocator(v15, &stack_allocator);
    vostok::memory::base_allocator::initialize(&stack_allocator, (char *)model_buffer, model_buffer_size, description);
    ud = vostok::resources::query_result_for_cook::user_data(v16, (int)parent);
    v45 = 0;
    survarium::weapon_user_dead_state::finalize(v17);
    vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>(ud, &affects_applying_type);
    survarium::weapon_user_dead_state::finalize(v18);
    v31 = v19;
    v30 = vostok::memory::stack_allocator::malloc_impl(v19, 0x340u);
    v44 = (survarium::damage_model *)operator new(0x340u, v30);
    if ( v44 )
    {
      survarium::damage_model::damage_model(
        v44,
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)affects_applying_type);
      v27 = (survarium::damage_model *)v20;
    }
    else
    {
      v27 = 0;
    }
    new_model = v27;
    survarium::fill_damage_model(
      a2,
      (survarium::game_camera *)v27,
      &stack_allocator,
      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)params_value,
      (vostok::configs::binary_config_value *)damage_groups);
    v43 = 0;
    survarium::weapon_user_dead_state::finalize(v21);
    vostok::resources::memory_usage_type::memory_usage_type(
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
      &v42,
      (vostok::network_core::packet_reader *)0x340,
      (vostok::network_core::packet_reader *)v25[1].m_object);
    memory_usage = v22;
    v25[0].m_object = v23;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v25,
      (vostok::configs::binary_config *)new_model);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v25[0]);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::memory::stack_allocator::~stack_allocator(v24, &stack_allocator);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
  }
  else
  {
    v49 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
