// local variable allocation has failed, the output may be wrong!
void __userpurge survarium::game_material_manager_cook::create_game_material_pairs(
        survarium::game_material_manager_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::query_result_for_cook *parent_query,
        survarium::game_material_manager *const manager,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *pairs_root)
{
  survarium::vector<vostok::resources::request> *v5; // ecx
  survarium::vector<vostok::resources::request> *v6; // ecx
  vostok::variant<32> *v7; // eax
  stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::material_pair *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  survarium::game_camera *v13; // ecx
  vostok::memory::doug_lea_allocator *v14; // eax
  void *v15; // eax
  vostok::resources::unmanaged_resource *v16; // ecx
  vostok::resources::unmanaged_resource *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  survarium::game_camera *v20; // ecx
  vostok::memory::doug_lea_allocator *v21; // eax
  void *v22; // eax
  vostok::resources::unmanaged_resource *v23; // ecx
  vostok::resources::unmanaged_resource *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v26; // ecx
  const vostok::configs::binary_config_value *v27; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v28; // ecx
  survarium::game_camera *v29; // ecx
  const vostok::configs::binary_config_value *v30; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v31; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v32; // ecx
  vostok::resources::request *v33; // eax
  survarium::vector<vostok::resources::request> *v34; // ecx
  survarium::vector<vostok::resources::request> *v35; // ecx
  unsigned int v36; // [esp+1214h] [ebp-1D0h]
  vostok::memory::base_allocator *v37; // [esp+121Ch] [ebp-1C8h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v38; // [esp+1220h] [ebp-1C4h] BYREF
  vostok::resources::query_result_for_cook *v39; // [esp+1224h] [ebp-1C0h]
  survarium::game_material_manager_cook *thisa; // [esp+1228h] [ebp-1BCh]
  vostok::network_core::packet_reader *v41; // [esp+122Ch] [ebp-1B8h]
  boost::function1<void,vostok::resources::queries_result &> v42; // [esp+1234h] [ebp-1B0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v43; // [esp+1254h] [ebp-190h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > result; // [esp+1264h] [ebp-180h] BYREF
  void (__thiscall *f)(survarium::game_material_manager_cook *, vostok::resources::queries_result *, survarium::vector<survarium::game_material_manager_cook::query_ext_data> *); // [esp+1278h] [ebp-16Ch]
  int f_4; // [esp+127Ch] [ebp-168h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > v47; // [esp+1280h] [ebp-164h] BYREF
  stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > v48; // [esp+1290h] [ebp-154h] BYREF
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v49; // [esp+129Ch] [ebp-148h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > v50; // [esp+12A0h] [ebp-144h] BYREF
  stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > v51; // [esp+12B0h] [ebp-134h] BYREF
  unsigned __int8 *a1; // [esp+12BCh] [ebp-128h]
  unsigned __int8 *v53; // [esp+12C0h] [ebp-124h]
  char *string; // [esp+12C4h] [ebp-120h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > v55; // [esp+12C8h] [ebp-11Ch] BYREF
  survarium::game_camera *v56; // [esp+12D4h] [ebp-110h]
  vostok::variant<32> *v57; // [esp+12D8h] [ebp-10Ch]
  char v58; // [esp+12DFh] [ebp-105h]
  vostok::render::material_effects_instance_cook_data *v59; // [esp+12E0h] [ebp-104h]
  vostok::resources::unmanaged_resource *v60; // [esp+12E4h] [ebp-100h]
  vostok::render::material_effects_instance_cook_data *v61; // [esp+12E8h] [ebp-FCh]
  survarium::game_material_manager_cook::query_ext_data v62; // [esp+12ECh] [ebp-F8h] BYREF
  stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > v63; // [esp+12F8h] [ebp-ECh] BYREF
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > v64; // [esp+1304h] [ebp-E0h] BYREF
  survarium::game_camera *v65; // [esp+1310h] [ebp-D4h]
  vostok::variant<32> *v66; // [esp+1314h] [ebp-D0h]
  char v67; // [esp+131Bh] [ebp-C9h]
  vostok::render::material_effects_instance_cook_data *v68; // [esp+131Ch] [ebp-C8h]
  vostok::resources::unmanaged_resource *v69; // [esp+1320h] [ebp-C4h]
  vostok::render::material_effects_instance_cook_data *v70; // [esp+1324h] [ebp-C0h]
  survarium::game_material_manager_cook::query_ext_data v71; // [esp+1328h] [ebp-BCh] BYREF
  stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > v72; // [esp+1334h] [ebp-B0h] BYREF
  char v73; // [esp+1343h] [ebp-A1h]
  survarium::material_pair *v74; // [esp+1344h] [ebp-A0h]
  survarium::material_pair *v75; // [esp+1348h] [ebp-9Ch]
  survarium::material_pair *v76; // [esp+134Ch] [ebp-98h]
  void *v77; // [esp+1350h] [ebp-94h]
  vostok::memory::doug_lea_allocator *v78; // [esp+1354h] [ebp-90h]
  stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *v79; // [esp+1358h] [ebp-8Ch]
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *v80; // [esp+135Ch] [ebp-88h]
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> v81; // [esp+1363h] [ebp-81h] BYREF
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *v82; // [esp+1364h] [ebp-80h]
  void *_Where; // [esp+1368h] [ebp-7Ch]
  vostok::memory::doug_lea_allocator *v84; // [esp+136Ch] [ebp-78h]
  survarium::game_camera *v85; // [esp+1370h] [ebp-74h]
  unsigned int __new_size; // [esp+1374h] [ebp-70h]
  vostok::variant<32> *__x; // [esp+1378h] [ebp-6Ch]
  vostok::variant<32> v88; // [esp+137Ch] [ebp-68h] BYREF
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > v89; // [esp+13B0h] [ebp-34h] BYREF
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> __a; // [esp+13BFh] [ebp-25h] BYREF
  void *v91[3]; // [esp+13C0h] [ebp-24h] BYREF
  survarium::vector<vostok::resources::request> v92; // [esp+13CCh] [ebp-18h] BYREF
  vostok::configs::binary_config_value *v93; // [esp+13D8h] [ebp-Ch]
  vostok::configs::binary_config_value *val; // [esp+13DCh] [ebp-8h]
  vostok::sound::sound_environment_cook *v95; // [esp+13E0h] [ebp-4h]

  v95 = (vostok::sound::sound_environment_cook *)this;
  val = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(pairs_root);
  v93 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)pairs_root);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    v5,
    &v92);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    v6,
    v91);
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
    &v89,
    &__a);
  vostok::variant<32>::variant<32>(&v88);
  __x = v7;
  __new_size = 2 * vostok::configs::binary_config_value::size((vostok::configs::binary_config_value *)pairs_root);
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::resize(
    (stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *)&v89,
    __new_size,
    __x);
  vostok::variant<32>::~variant<32>(&v88);
  v85 = 0;
  v84 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
             0xCu);
  v82 = (stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *)operator new(0xCu, _Where);
  if ( v82 )
  {
    stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
      v82,
      &v81);
    v80 = v82;
  }
  else
  {
    v80 = 0;
  }
  v8 = (stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *)v80;
  v79 = (stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *)v80;
  while ( val != v93 )
  {
    v78 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
    v77 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
            0x30u);
    v76 = (survarium::material_pair *)operator new(0x30u, v77);
    if ( v76 )
    {
      survarium::material_pair::material_pair(v76);
      v75 = v10;
    }
    else
    {
      v75 = 0;
    }
    v74 = v75;
    v73 = 0;
    survarium::weapon_user_dead_state::finalize(v9);
    survarium::material_pair::load_from_config(v74, a2, manager, val);
    if ( !LOBYTE(v95[1].__vftable) )
    {
      v11 = vostok::configs::binary_config_value::operator[](val, "decal1");
      v72._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                              v12,
                                                                              (int)v11);
      if ( vostok::strings::length((const char *)v72._M_impl._M_end_of_storage._M_data) )
      {
        vostok::resources::memory_usage_type::memory_usage_type(
          (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)v72._M_impl._M_end_of_storage._M_data,
          (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **)&v72,
          (vostok::network_core::packet_reader *)0xF,
          v41);
        stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::push_back(
          &v72,
          (int)&v92);
        v71.pair = v74;
        v71.type = render;
        survarium::weapon_user_dead_state::finalize(v13);
        v15 = vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(v14);
        v70 = (vostok::render::material_effects_instance_cook_data *)operator new(0x10u, v15);
        if ( v70 )
        {
          thisa = (survarium::game_material_manager_cook *)2;
          v39 = 0;
          v38.m_object = v16;
          vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v38,
            0);
          vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
            v70,
            decal_vertex_input_type,
            v38,
            (bool)v39,
            (vostok::render::enum_cull_mode)thisa);
          v69 = v17;
          v16 = v17;
          v68 = (vostok::render::material_effects_instance_cook_data *)v17;
        }
        else
        {
          v68 = 0;
        }
        v71.cd = v68;
        v67 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v16);
        v66 = (vostok::variant<32> *)((char *)v89._M_start + 48 * (_DWORD)v85);
        vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(v66, (int)v66, &v71.cd);
        stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::push_back(
          v79,
          &v71);
        v65 = v85;
        HIBYTE(v64._M_impl._M_end_of_storage._M_data) = 0;
        survarium::weapon_user_dead_state::finalize(v85);
        v64._M_impl._M_finish = (const void **)(&v89._M_start->m_preconditions._M_impl._M_start + 12 * (_DWORD)v65);
        v64._M_impl._M_start = v64._M_impl._M_finish;
        v85 = (survarium::game_camera *)((char *)v85 + 1);
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::push_back(
          &v64,
          (const vostok::variant<32> *const *)v41);
      }
      v18 = vostok::configs::binary_config_value::operator[](val, "decal2");
      v63._M_impl._M_end_of_storage._M_data = (vostok::resources::request *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                              v19,
                                                                              (int)v18);
      if ( vostok::strings::length((const char *)v63._M_impl._M_end_of_storage._M_data) )
      {
        vostok::resources::memory_usage_type::memory_usage_type(
          (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)v63._M_impl._M_end_of_storage._M_data,
          (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **)&v63,
          (vostok::network_core::packet_reader *)0xF,
          v41);
        stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::push_back(
          &v63,
          (int)&v92);
        v62.pair = v74;
        v62.type = logic;
        survarium::weapon_user_dead_state::finalize(v20);
        v22 = vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(v21);
        v61 = (vostok::render::material_effects_instance_cook_data *)operator new(0x10u, v22);
        if ( v61 )
        {
          thisa = (survarium::game_material_manager_cook *)2;
          v39 = 0;
          v38.m_object = v23;
          vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v38,
            0);
          vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
            v61,
            decal_vertex_input_type,
            v38,
            (bool)v39,
            (vostok::render::enum_cull_mode)thisa);
          v60 = v24;
          v23 = v24;
          v59 = (vostok::render::material_effects_instance_cook_data *)v24;
        }
        else
        {
          v59 = 0;
        }
        v62.cd = v59;
        v58 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v23);
        v57 = (vostok::variant<32> *)((char *)v89._M_start + 48 * (_DWORD)v85);
        vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(v57, (int)v57, &v62.cd);
        stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::push_back(
          v79,
          &v62);
        v56 = v85;
        HIBYTE(v55._M_impl._M_end_of_storage._M_data) = 0;
        survarium::weapon_user_dead_state::finalize(v85);
        v55._M_impl._M_finish = (const void **)(&v89._M_start->m_preconditions._M_impl._M_start + 12 * (_DWORD)v56);
        v55._M_impl._M_start = v55._M_impl._M_finish;
        v85 = (survarium::game_camera *)((char *)v85 + 1);
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::push_back(
          &v55,
          (const vostok::variant<32> *const *)v41);
      }
      v25 = vostok::configs::binary_config_value::operator[](val, "sound");
      string = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                         v26,
                         (int)v25);
      if ( vostok::strings::length(string) )
      {
        v27 = vostok::configs::binary_config_value::operator[](val, "sound_type");
        v53 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                   v28,
                                   (int)v27);
        a1 = v53;
        HIBYTE(v51._M_impl._M_end_of_storage._M_data) = 0;
        survarium::weapon_user_dead_state::finalize(v29);
        vostok::resources::memory_usage_type::memory_usage_type(
          (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)string,
          (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **)&v51,
          (vostok::network_core::packet_reader *)a1,
          v41);
        stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::push_back(
          &v51,
          (int)&v92);
        v50._M_impl._M_finish = (const void **)v74;
        v50._M_impl._M_end_of_storage._M_data = (const void **)2;
        stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::push_back(
          v79,
          (const survarium::game_material_manager_cook::query_ext_data *)&v50._M_impl._M_finish);
        v50._M_impl._M_start = 0;
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::push_back(
          &v50,
          (const vostok::variant<32> *const *)v41);
      }
      v30 = vostok::configs::binary_config_value::operator[](val, "particle");
      v49 = (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                                          v31,
                                                                                          (int)v30);
      if ( vostok::strings::length((const char *)v49) )
      {
        for ( v48._M_impl._M_end_of_storage._M_data = 0;
              v48._M_impl._M_end_of_storage._M_data < (vostok::resources::request *)8;
              ++v48._M_impl._M_end_of_storage._M_data )
        {
          vostok::resources::memory_usage_type::memory_usage_type(
            v49,
            (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **)&v48,
            (vostok::network_core::packet_reader *)0x48,
            v41);
          stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::push_back(
            &v48,
            (int)&v92);
          v47._M_impl._M_finish = (const void **)v74;
          v47._M_impl._M_end_of_storage._M_data = (const void **)3;
          stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::push_back(
            v79,
            (const survarium::game_material_manager_cook::query_ext_data *)&v47._M_impl._M_finish);
          v47._M_impl._M_start = 0;
          stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::push_back(
            &v47,
            (const vostok::variant<32> *const *)v41);
        }
      }
    }
    survarium::game_material_manager::add_pair(manager, (stlp_std::priv::_Rb_tree_node_base *)v74);
    ++val;
  }
  if ( stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::empty(
         v8,
         &v92) )
  {
    vostok::resources::query_result_for_cook::finish_query(parent_query, result_success, assert_on_fail_true);
  }
  else
  {
    f = survarium::game_material_manager_cook::on_decals_loaded;
    f_4 = 0;
    v43 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
             (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)survarium::game_material_manager_cook::on_decals_loaded,
             (survarium::game_material_manager_cook *)v95,
             1_164,
             (vostok::math::float4x4 *)v79);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v43.l_.a1_.t_,
      &v42);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>>>>(
      &v42,
      v43);
    thisa = (survarium::game_material_manager_cook *)1;
    v39 = parent_query;
    v38.m_object = (vostok::resources::unmanaged_resource *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                              v32,
                                                              (int)v91);
    v37 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
    v36 = vostok::vectora<vostok::resources::request>::size(&v92);
    v33 = survarium::vector<vostok::resources::request>::operator[](&v92, 0);
    vostok::resources::query_resources(
      v33,
      v36,
      (boost::function4<void,unsigned int,float,float,char const *> *)&v42,
      v37,
      (const vostok::variant<32> **)v38.m_object,
      v39,
      (assert_on_fail_bool)thisa);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v42);
  }
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::~_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>((stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *)&v89);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
    v34,
    v91);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
    v35,
    (void **)&v92);
}
