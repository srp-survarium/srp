void __userpurge survarium::inventory_cook::translate_query(
        survarium::inventory_cook *this@<ecx>,
        int a2@<ebp>,
        unsigned int a3@<esi>,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *v4; // eax
  survarium::game_camera *v5; // ecx
  void *v6; // esp
  survarium::game_camera *v7; // ecx
  vostok::buffer_vector<vostok::resources::request> *v8; // eax
  void *v9; // esp
  survarium::game_camera *v10; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v11; // eax
  stlp_std::less<unsigned int> *v12; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v13; // ecx
  survarium::game_camera *v14; // ecx
  const char *v15; // eax
  vostok::resources::class_id_enum v16; // edx
  stlp_std::less<unsigned int> *v17; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  survarium::game_camera *v19; // ecx
  const char *v20; // eax
  vostok::resources::class_id_enum v21; // edx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v22; // ecx
  const vostok::variant<32> **v23; // eax
  vostok::configs::binary_config *v24; // ecx
  vostok::configs::binary_config_value *root; // eax
  vostok::configs::binary_config_value *v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v28; // ecx
  stlp_std::less<unsigned int> *v29; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v30; // ecx
  survarium::game_camera *v31; // ecx
  const char *v32; // eax
  vostok::resources::class_id_enum v33; // edx
  const char *v34; // eax
  vostok::resources::class_id_enum v35; // edx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v36; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v37; // ecx
  const vostok::variant<32> **v38; // eax
  vostok::buffer_vector<vostok::resources::request> *v39; // ecx
  vostok::buffer_vector<vostok::resources::request> *v40; // ecx
  unsigned int v41; // [esp-574h] [ebp-580h]
  vostok::memory::base_allocator *f; // [esp-56Ch] [ebp-578h]
  const vostok::variant<32> **v43; // [esp-568h] [ebp-574h]
  unsigned int v44[19]; // [esp-55Ch] [ebp-568h] BYREF
  unsigned int v45[40]; // [esp-510h] [ebp-51Ch] BYREF
  boost::function1<void,vostok::resources::queries_result &> v46; // [esp-470h] [ebp-47Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::items_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::items_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v47; // [esp-450h] [ebp-45Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::items_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::items_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v48; // [esp-440h] [ebp-44Ch] BYREF
  void (__thiscall *v49)(survarium::inventory_cook *, vostok::resources::queries_result *, survarium::inventory_cooker_data *); // [esp-42Ch] [ebp-438h]
  int v50; // [esp-428h] [ebp-434h]
  const vostok::variant<32> *v51; // [esp-424h] [ebp-430h] BYREF
  vostok::resources::request v52; // [esp-420h] [ebp-42Ch] BYREF
  const vostok::variant<32> *v53; // [esp-418h] [ebp-424h] BYREF
  vostok::resources::request v54; // [esp-414h] [ebp-420h] BYREF
  const vostok::variant<32> *v55; // [esp-40Ch] [ebp-418h] BYREF
  survarium::booby_trap_set_cook_data v56; // [esp-408h] [ebp-414h] BYREF
  char v57; // [esp-401h] [ebp-40Dh]
  int v58; // [esp-400h] [ebp-40Ch]
  const vostok::variant<32> **v59; // [esp-3FCh] [ebp-408h]
  const vostok::variant<32> **v60; // [esp-3F8h] [ebp-404h]
  stlp_std::less<unsigned int> *v61; // [esp-3F4h] [ebp-400h]
  survarium::profile_slot_enum v62; // [esp-3F0h] [ebp-3FCh]
  unsigned int k; // [esp-3ECh] [ebp-3F8h]
  const vostok::variant<32> *v64; // [esp-3E8h] [ebp-3F4h] BYREF
  vostok::resources::request v65; // [esp-3E4h] [ebp-3F0h] BYREF
  survarium::profile_slot_enum v66; // [esp-3DCh] [ebp-3E8h]
  unsigned int j; // [esp-3D8h] [ebp-3E4h]
  const vostok::variant<32> *v68; // [esp-3D4h] [ebp-3E0h] BYREF
  vostok::resources::request v69; // [esp-3D0h] [ebp-3DCh] BYREF
  const vostok::variant<32> **v70; // [esp-3C8h] [ebp-3D4h]
  survarium::profile_slot *v71; // [esp-3C4h] [ebp-3D0h]
  survarium::profile_slot_enum v72; // [esp-3C0h] [ebp-3CCh]
  unsigned int i; // [esp-3BCh] [ebp-3C8h]
  _OWORD v74[57]; // [esp-3B8h] [ebp-3C4h] BYREF
  vostok::buffer_vector<vostok::variant<32> const *> v75; // [esp-24h] [ebp-30h] BYREF
  unsigned int *v76; // [esp-1Ch] [ebp-28h]
  survarium::vector<vostok::resources::request> v77; // [esp-18h] [ebp-24h] BYREF
  char v78; // [esp-9h] [ebp-15h]
  survarium::inventory_cooker_data *v79; // [esp-8h] [ebp-14h] BYREF
  survarium::inventory_cook *v80; // [esp-4h] [ebp-10h]
  int v81; // [esp+0h] [ebp-Ch]
  survarium::inventory_cooker_data *cooker_data; // [esp+4h] [ebp-8h]
  survarium::inventory_cooker_data *retaddr; // [esp+Ch] [ebp+0h]

  v81 = a2;
  cooker_data = retaddr;
  v45[38] = a3;
  v80 = this;
  v4 = vostok::resources::query_result_for_cook::user_data(
         (vostok::resources::query_result_for_cook *)this,
         (int)parent);
  vostok::variant<32>::try_get<survarium::inventory_cooker_data *>(v4, &v79);
  v78 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  v6 = alloca(152);
  v77._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)v45;
  survarium::weapon_user_dead_state::finalize(v7);
  vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
    v8,
    (vostok::buffer_vector<vostok::resources::request> **)&v77,
    0,
    v45[0],
    v45[1]);
  v9 = alloca(76);
  v76 = v44;
  survarium::weapon_user_dead_state::finalize(v10);
  vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
    v11,
    (vostok::buffer_vector<vostok::variant<32> const *> **)&v75,
    0,
    v44[0],
    v44[1]);
  `vector constructor iterator'((char *)v74, 0x30u, 19, (void *(__thiscall *)(void *))vostok::variant<32>::variant<32>);
  for ( i = 0; i < 2; ++i )
  {
    v72 = weapon_slots_1[i];
    v71 = &v79->profile->slots[v72];
    if ( v71->item.id )
    {
      v12 = survarium::items_dictionary::item_by_id(v79->dictionary, v71->item.dict_id);
      v70 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v13, (int)&v12[8]);
      survarium::weapon_user_dead_state::finalize(v14);
      v69.path = v15;
      v69.id = v16;
      vostok::buffer_vector<vostok::resources::request>::push_back(
        (vostok::buffer_vector<vostok::resources::request> *)&v77,
        &v69);
      v68 = 0;
      vostok::buffer_vector<unsigned int>::push_back(&v75, &v68);
    }
  }
  for ( j = 0; j < 4; ++j )
  {
    v66 = ammunition_slots_0[j];
    v71 = &v79->profile->slots[v66];
    if ( v71->item.id )
    {
      v17 = survarium::items_dictionary::item_by_id(v79->dictionary, v71->item.dict_id);
      v70 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v18, (int)&v17[8]);
      survarium::weapon_user_dead_state::finalize(v19);
      v65.path = v20;
      v65.id = v21;
      vostok::buffer_vector<vostok::resources::request>::push_back(
        (vostok::buffer_vector<vostok::resources::request> *)&v77,
        &v65);
      v64 = 0;
      vostok::buffer_vector<unsigned int>::push_back(&v75, &v64);
    }
  }
  for ( k = 0; k < 0xD; ++k )
  {
    v62 = item_slots_0[k];
    v71 = &v79->profile->slots[v62];
    if ( v71->item.id )
    {
      v61 = survarium::items_dictionary::item_by_id(v79->dictionary, v71->item.dict_id);
      v23 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v22, (int)&v61[4]);
      root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v24, (int)v23);
      v26 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](root, "data");
      v27 = vostok::configs::binary_config_value::operator[](v26, "type");
      v60 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v28, (int)v27);
      v29 = survarium::items_dictionary::item_by_id(v79->dictionary, v71->item.dict_id);
      v70 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v30, (int)&v29[8]);
      v59 = v60;
      if ( v60 == (const vostok::variant<32> **)2 )
      {
        v58 = 88;
        v57 = 0;
        survarium::weapon_user_dead_state::finalize(v31);
        v56.is_local_player = v79->profile->is_local;
        v56.stack_size = v71->item.condition_or_stack;
        vostok::variant<32>::set<survarium::booby_trap_set_cook_data>((vostok::variant<32> *)&v74[3 * v62], &v56);
        v55 = (const vostok::variant<32> *)&v74[3 * v62];
        vostok::buffer_vector<unsigned int>::push_back(&v75, &v55);
      }
      else if ( v59 == (const vostok::variant<32> **)4 )
      {
        v58 = 0;
      }
      else
      {
        v58 = v59 == (const vostok::variant<32> **)5 ? 90 : 87;
      }
      survarium::weapon_user_dead_state::finalize(v31);
      v54.path = v32;
      v54.id = v33;
      vostok::buffer_vector<vostok::resources::request>::push_back(
        (vostok::buffer_vector<vostok::resources::request> *)&v77,
        &v54);
      if ( v60 != (const vostok::variant<32> **)2 )
      {
        v53 = 0;
        vostok::buffer_vector<unsigned int>::push_back(&v75, &v53);
      }
    }
  }
  if ( v77._M_impl._M_start == v77._M_impl._M_finish )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v77._M_impl._M_start);
    v52.path = v34;
    v52.id = v35;
    vostok::buffer_vector<vostok::resources::request>::push_back(
      (vostok::buffer_vector<vostok::resources::request> *)&v77,
      &v52);
    v51 = 0;
    vostok::buffer_vector<unsigned int>::push_back(&v75, &v51);
  }
  v49 = survarium::inventory_cook::on_subresources_loaded;
  v50 = 0;
  v47 = *boost::bind<void,survarium::inventory_cook,vostok::resources::queries_result &,survarium::inventory_cooker_data *,survarium::inventory_cook *,boost::arg<1>,survarium::inventory_cooker_data *>(
           &v48,
           (void (__thiscall *__ptr64)(survarium::inventory_cook *, vostok::resources::queries_result *, survarium::inventory_cooker_data *))(unsigned int)survarium::inventory_cook::on_subresources_loaded,
           v80,
           1_161,
           v79);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    &v46,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::inventory_cook,vostok::resources::queries_result &,survarium::inventory_cooker_data *>,boost::_bi::list3<boost::_bi::value<survarium::inventory_cook *>,boost::arg<1>,boost::_bi::value<survarium::inventory_cooker_data *> > >)v47,
    0);
  v43 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v36, (int)&v75);
  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v41 = vostok::vectora<vostok::resources::request>::size(&v77);
  v38 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v37, (int)&v77);
  vostok::resources::query_resources(
    (const vostok::resources::request *)v38,
    v41,
    (boost::function4<void,unsigned int,float,float,char const *> *)&v46,
    f,
    v43,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v46);
  `vector destructor iterator'((char *)v74, 0x30u, 19, (void (__thiscall *)(void *))vostok::variant<32>::~variant<32>);
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v39, &v75);
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v40, &v77);
}
