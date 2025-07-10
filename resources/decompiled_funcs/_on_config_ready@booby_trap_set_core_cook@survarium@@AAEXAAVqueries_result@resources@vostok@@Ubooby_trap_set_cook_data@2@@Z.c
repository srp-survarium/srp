// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::booby_trap_set_core_cook::on_config_ready(
        survarium::booby_trap_set_core_cook *this@<ecx>,
        unsigned int a2@<ebp>,
        int a3@<esi>,
        float a4@<xmm0>,
        vostok::resources::queries_result *data,
        survarium::booby_trap_set_cook_data cook_data)
{
  vostok::resources::query_result *v6; // eax
  vostok::resources::query_result_for_user *v7; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  survarium::game_camera *v9; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  vostok::configs::binary_config *v12; // ecx
  vostok::configs::binary_config_value *root; // eax
  const vostok::configs::binary_config_value *v14; // eax
  survarium::inventory_item *v15; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  void *v17; // esp
  vostok::buffer_vector<vostok::resources::request> *v18; // eax
  void *v19; // esp
  survarium::game_camera *v20; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v21; // eax
  vostok::variant<32> *v22; // ecx
  survarium::game_camera *v23; // ecx
  const char *v24; // eax
  vostok::resources::class_id_enum v25; // edx
  vostok::resources::queries_result *v26; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v27; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v28; // ecx
  const vostok::variant<32> **v29; // eax
  vostok::buffer_vector<vostok::resources::request> *v30; // ecx
  vostok::buffer_vector<vostok::resources::request> *v31; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> v32; // [esp-B8h] [ebp-C4h] BYREF
  const vostok::variant<32> *v33; // [esp-90h] [ebp-9Ch] BYREF
  vostok::resources::request v34; // [esp-8Ch] [ebp-98h] BYREF
  char i; // [esp-81h] [ebp-8Dh]
  vostok::variant<32> v36; // [esp-80h] [ebp-8Ch] BYREF
  vostok::buffer_vector<vostok::variant<32> const *> v37; // [esp-50h] [ebp-5Ch] BYREF
  unsigned int *v38; // [esp-48h] [ebp-54h]
  survarium::vector<vostok::resources::request> v39; // [esp-44h] [ebp-50h] BYREF
  survarium::booby_trap_set_core *v40; // [esp-38h] [ebp-44h]
  char v41; // [esp-31h] [ebp-3Dh]
  _DWORD v42[2]; // [esp-30h] [ebp-3Ch] BYREF
  unsigned __int64 max_storage; // [esp-28h] [ebp-34h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v44; // [esp-20h] [ebp-2Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list5<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_core *>,boost::_bi::value<survarium::booby_trap_set_cook_data>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v45; // [esp-1Ch] [ebp-28h] BYREF
  assert_on_fail_bool v46; // [esp-4h] [ebp-10h]
  unsigned int v47; // [esp+0h] [ebp-Ch] BYREF
  unsigned int live_count; // [esp+4h] [ebp-8h]
  unsigned int retaddr; // [esp+Ch] [ebp+0h]

  v47 = a2;
  live_count = retaddr;
  v46 = (assert_on_fail_bool)this;
  HIBYTE(v45.l_.a5_.t_.m_object) = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v6 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v7,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v6,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v45.l_.a4_);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v45.l_.a3_);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v45.l_.a4_);
  HIBYTE(v45.l_.a1_.t_) = 0;
  survarium::weapon_user_dead_state::finalize(v9);
  v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)&v45.l_.a3_);
  root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v12, (int)v11);
  v14 = vostok::configs::binary_config_value::operator[](root, "data");
  v42[0] = v14->data.pointer;
  v42[1] = HIDWORD(v14->data.max_storage);
  max_storage = v14->id.max_storage;
  v44.m_object = (vostok::configs::binary_config *)v14->id_crc;
  LODWORD(v45.f_.f_) = *(_DWORD *)&v14->type;
  v41 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)HIDWORD(max_storage));
  v40 = (survarium::booby_trap_set_core *)(*(int (__thiscall **)(assert_on_fail_bool, int))(*(_DWORD *)v46 + 36))(
                                            v46,
                                            a3);
  LOWORD(v15) = cook_data.stack_size;
  survarium::inventory_item::set_amount(v15, (int)v40);
  survarium::booby_trap_set_core::load(v40, a4, (vostok::configs::binary_config_value *)v42);
  if ( cook_data.stack_size )
  {
    v17 = alloca(8 * cook_data.stack_size);
    v39._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)&v47;
    v46 = assert_on_fail_false;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)cook_data.stack_size);
    vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
      v18,
      (vostok::buffer_vector<vostok::resources::request> **)&v39,
      v46,
      v47,
      live_count);
    v19 = alloca(4 * cook_data.stack_size);
    v38 = &v47;
    v46 = assert_on_fail_false;
    survarium::weapon_user_dead_state::finalize(v20);
    vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
      v21,
      (vostok::buffer_vector<vostok::variant<32> const *> **)&v37,
      v46,
      v47,
      live_count);
    vostok::variant<32>::variant<32>(&v36);
    vostok::variant<32>::set<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      v22,
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v36,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v45.l_.a3_);
    for ( i = 0; i != cook_data.stack_size; ++i )
    {
      survarium::weapon_user_dead_state::finalize(v23);
      v34.path = v24;
      v34.id = v25;
      vostok::buffer_vector<vostok::resources::request>::push_back(
        (vostok::buffer_vector<vostok::resources::request> *)&v39,
        &v34);
      v33 = &v36;
      vostok::buffer_vector<unsigned int>::push_back(&v37, &v33);
      LOBYTE(v23) = i + 1;
    }
    v46 = assert_on_fail_false;
    v44.m_object = (vostok::configs::binary_config *)v23;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v44,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v45.l_.a3_);
    boost::bind<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::booby_trap_set_core_cook *,boost::arg<1>,survarium::booby_trap_set_core *,survarium::booby_trap_set_cook_data,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v45,
      (void (__thiscall *__ptr64)(survarium::booby_trap_set_core_cook *, vostok::resources::queries_result *, survarium::booby_trap_set_core *, survarium::booby_trap_set_cook_data, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>))(unsigned int)survarium::booby_trap_set_core_cook::on_subresources_loaded,
      (survarium::booby_trap_set_core_cook *)v46,
      1_171,
      v40,
      cook_data,
      v44);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      &v32,
      v45,
      v46);
    v46 = assert_on_fail_true;
    v45.l_.a5_.t_.m_object = (vostok::configs::binary_config *)vostok::resources::queries_result::get_parent_query(
                                                                 v26,
                                                                 (int)data);
    *(_DWORD *)&v45.l_.a4_.t_.is_local_player = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                  v27,
                                                  (int)&v37);
    v45.l_.a3_.t_ = (survarium::booby_trap_set_core *)survarium::g_allocator.f_.f_;
    v45.l_.a1_.t_ = (survarium::booby_trap_set_core_cook *)&v32;
    HIDWORD(v45.f_.f_) = vostok::vectora<vostok::resources::request>::size(&v39);
    v29 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v28, (int)&v39);
    vostok::resources::query_resources(
      (const vostok::resources::request *)v29,
      HIDWORD(v45.f_.f_),
      (boost::function4<void,unsigned int,float,float,char const *> *)v45.l_.a1_.t_,
      (vostok::memory::base_allocator *)v45.l_.a3_.t_,
      *(const vostok::variant<32> ***)&v45.l_.a4_.t_.is_local_player,
      (vostok::resources::query_result_for_cook *)v45.l_.a5_.t_.m_object,
      v46);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v32);
    vostok::variant<32>::~variant<32>(&v36);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v30, &v37);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v31, &v39);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v45.l_.a3_);
  }
  else
  {
    v46 = (assert_on_fail_bool)v40;
    parent_query = vostok::resources::queries_result::get_parent_query(0, (int)data);
    survarium::booby_trap_set_core_cook::finish_query(
      (survarium::booby_trap_set_core_cook *)v46,
      parent_query,
      (vostok::configs::binary_config *)v46);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v45.l_.a3_);
  }
}
