void __userpurge survarium::player_cook::on_config_loaded(
        survarium::player_cook *this@<ecx>,
        const vostok::configs::binary_config_value *a2@<ebp>,
        const stlp_std::__true_type *a3@<edi>,
        unsigned int a4@<esi>,
        float a5@<xmm0>,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_parent_query; // ecx
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v8; // edi
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **v9; // esi
  char **v10; // esi
  const char **v11; // eax
  char **v12; // esi
  const char **v13; // eax
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **v14; // esi
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **v15; // esi
  vostok::memory::doug_lea_allocator *v16; // eax
  survarium::base_player_creation_params *v17; // ecx
  _DWORD *v18; // esi
  _DWORD *v19; // edi
  vostok::configs::binary_config_value *v20; // esi
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  vostok::configs::binary_config_value *v23; // esi
  vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // eax
  vostok::configs::binary_config_value *v26; // eax
  bool v27; // zf
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *pointer; // ecx
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **v29; // eax
  char *v30; // eax
  int v31; // eax
  int v32; // esi
  void *v33; // esp
  const stlp_std::__true_type **v34; // eax
  _DWORD *v35; // esi
  _DWORD *v36; // eax
  const vostok::resources::request *v37; // esi
  void (__cdecl *v38)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v39; // eax
  vostok::resources::unmanaged_intrusive_base *v40; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *,survarium::player_parameters_cooker_data *>,boost::_bi::list5<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>,boost::_bi::value<survarium::player_parameters_cooker_data *> > > v41; // [esp-348h] [ebp-354h]
  const stlp_std::__true_type *v42; // [esp-330h] [ebp-33Ch] BYREF
  unsigned int v43; // [esp-32Ch] [ebp-338h]
  vostok::fs_new::path_string_impl v44; // [esp-328h] [ebp-334h] BYREF
  vostok::fs_new::path_string_impl v45; // [esp-210h] [ebp-21Ch] BYREF
  void (__thiscall *v46)(survarium::player_cook *, vostok::resources::queries_result *, survarium::player_creation_params *, survarium::inventory_cooker_data *, survarium::player_parameters_cooker_data *); // [esp-F8h] [ebp-104h]
  int v47; // [esp-F4h] [ebp-100h]
  _DWORD v48[2]; // [esp-E0h] [ebp-ECh] BYREF
  _DWORD *v49; // [esp-D8h] [ebp-E4h] BYREF
  _DWORD *v50; // [esp-B8h] [ebp-C4h]
  int v51; // [esp-B4h] [ebp-C0h]
  _DWORD v52[2]; // [esp-B0h] [ebp-BCh] BYREF
  _DWORD *v53; // [esp-A8h] [ebp-B4h] BYREF
  _DWORD *v54; // [esp-88h] [ebp-94h]
  int v55; // [esp-84h] [ebp-90h]
  _DWORD v56[2]; // [esp-80h] [ebp-8Ch] BYREF
  _DWORD *v57; // [esp-78h] [ebp-84h] BYREF
  _DWORD *v58; // [esp-58h] [ebp-64h]
  int v59; // [esp-54h] [ebp-60h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> v60; // [esp-50h] [ebp-5Ch] BYREF
  survarium::player_cook *v61; // [esp-2Ch] [ebp-38h]
  vostok::resources::query_result_for_cook *v62; // [esp-28h] [ebp-34h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v63; // [esp-24h] [ebp-30h] BYREF
  _DWORD *v64; // [esp-20h] [ebp-2Ch]
  const vostok::resources::request *v65; // [esp-1Ch] [ebp-28h] BYREF
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **v66; // [esp-18h] [ebp-24h]
  int f; // [esp-14h] [ebp-20h]
  _DWORD *v68; // [esp-10h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v69; // [esp-Ch] [ebp-18h] BYREF
  char *m_begin; // [esp-8h] [ebp-14h] BYREF
  unsigned int v71; // [esp-4h] [ebp-10h]
  const vostok::configs::binary_config_value *root; // [esp+0h] [ebp-Ch]
  void *v73; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  root = a2;
  v73 = retaddr;
  v43 = a4;
  v61 = this;
  m_parent_query = data->m_parent_query;
  v42 = a3;
  v62 = m_parent_query;
  v69.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v69,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v69.m_object;
  v63.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v63,
    v69.m_object);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v8 = (vostok::configs::binary_config *)vostok::configs::binary_config_value::operator[](
                                           v63.m_object->m_root,
                                           "player");
  v71 = 98;
  f = (int)survarium::g_allocator.f_.f_;
  v69.m_object = v8;
  v65 = 0;
  v66 = 0;
  v68 = 0;
  m_begin = "combined_skin_123";
  stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
    (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)&m_begin,
    (unsigned __int8 **)&v65,
    0,
    (const vostok::collision::ray_object_result *)&m_begin,
    v42,
    v43,
    (bool)v44.m_string.m_begin);
  v9 = v66;
  m_begin = "character/human/scavengers_01/scavengers_01";
  v71 = 20;
  if ( v66 == v68 )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)0x14,
      (unsigned __int8 **)&v65,
      (int)v66,
      (const vostok::collision::ray_object_result *)&m_begin,
      v42,
      v43,
      (bool)v44.m_string.m_begin);
    v10 = (char **)v66;
  }
  else
  {
    *v66 = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)"character/human/scavengers_01/scavengers_01";
    v9[1] = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)20;
    v10 = (char **)(v9 + 2);
    v66 = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **)v10;
  }
  v45.m_string.m_end = v45.m_string.m_buffer;
  v45.m_string.m_begin = v45.m_string.m_buffer;
  v45.m_string.m_max_end = &v45.m_separator;
  v45.m_string.m_buffer[0] = 0;
  v45.m_separator = 47;
  v11 = (const char **)vostok::configs::binary_config_value::operator[](
                         (vostok::configs::binary_config_value *)v8,
                         "skeleton_model_instance");
  vostok::fs_new::path_string_impl::assignf(&v45, "resources/models/%s.skinned_model/hit_targets", *v11);
  m_begin = v45.m_string.m_begin;
  v71 = 34;
  if ( v10 == v68 )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)0x22,
      (unsigned __int8 **)&v65,
      (int)v10,
      (const vostok::collision::ray_object_result *)&m_begin,
      v42,
      v43,
      (bool)v44.m_string.m_begin);
    v12 = (char **)v66;
  }
  else
  {
    *v10 = v45.m_string.m_begin;
    v10[1] = (char *)34;
    v12 = v10 + 2;
    v66 = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **)v12;
  }
  v44.m_string.m_end = v44.m_string.m_buffer;
  v44.m_string.m_begin = v44.m_string.m_buffer;
  v44.m_string.m_max_end = &v44.m_separator;
  v44.m_string.m_buffer[0] = 0;
  v44.m_separator = 47;
  v13 = (const char **)vostok::configs::binary_config_value::operator[](
                         (vostok::configs::binary_config_value *)v8,
                         "skeleton_model_instance");
  vostok::fs_new::path_string_impl::assignf(&v44, "resources/models/%s.skinned_model/settings", *v13);
  m_begin = v44.m_string.m_begin;
  v71 = 34;
  if ( v12 == v68 )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)0x22,
      (unsigned __int8 **)&v65,
      (int)v12,
      (const vostok::collision::ray_object_result *)&m_begin,
      v42,
      v43,
      (bool)v44.m_string.m_begin);
    v14 = v66;
  }
  else
  {
    *v12 = v44.m_string.m_begin;
    v12[1] = (char *)34;
    v14 = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > **)(v12 + 2);
    v66 = v14;
  }
  m_begin = "inventory";
  v71 = 80;
  if ( v14 == v68 )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)0x50,
      (unsigned __int8 **)&v65,
      (int)v14,
      (const vostok::collision::ray_object_result *)&m_begin,
      v42,
      v43,
      (bool)v44.m_string.m_begin);
    v15 = v66;
  }
  else
  {
    *v14 = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)"inventory";
    v14[1] = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)80;
    v15 = v14 + 2;
    v66 = v15;
  }
  m_begin = "player_parameters";
  v71 = 99;
  if ( v15 == v68 )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)&m_begin,
      (unsigned __int8 **)&v65,
      (int)v15,
      (const vostok::collision::ray_object_result *)&m_begin,
      v42,
      v43,
      (bool)v44.m_string.m_begin);
  }
  else
  {
    *v15 = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)"player_parameters";
    v15[1] = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)99;
    v66 = v15 + 2;
  }
  v16 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v18 = vostok::memory::doug_lea_allocator::malloc_impl(v16, 0x140u);
  if ( v18 )
  {
    survarium::base_player_creation_params::base_player_creation_params(v17, (int)v18);
    v18[74] = 0;
    v18[75] = 0;
    v18[78] = 0;
    v19 = v18;
  }
  else
  {
    v19 = 0;
  }
  vostok::variant<32>::try_get<survarium::player_initial_info>(
    v62->m_user_data,
    (survarium::player_initial_info *)v19,
    (int)v17);
  v20 = (vostok::configs::binary_config_value *)v69.m_object;
  v19[76] = v19[2];
  *((_BYTE *)v19 + 316) = vostok::configs::binary_config_value::operator[](v20, "foot_material_id")->data.pointer;
  *((_BYTE *)v19 + 317) = vostok::configs::binary_config_value::operator[](v20, "foot_1st_view_material_id")->data.pointer;
  v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  v20,
                                                  "character_recoil_params");
  survarium::character_recoil_params::load((survarium::character_recoil_params *)v19 + 1, a5, v21);
  v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  v20,
                                                  "character_breath_holding_params");
  survarium::breath_holding_params::load(v22, (survarium::breath_holding_params *)(v19 + 22));
  v23 = (vostok::configs::binary_config_value *)v69.m_object;
  v24 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)v69.m_object,
                                                  "character_dispersion_params");
  survarium::character_dispersion_params::load((survarium::character_dispersion_params *)(v19 + 8), a5, v24);
  v25 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v23, "stamina_params");
  survarium::player_stamina::load((survarium::player_stamina *)(v19 + 32), a5, v25);
  v26 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v23, "stealth_params");
  survarium::player_stealth::load((survarium::player_stealth *)(v19 + 58), a5, v26);
  v27 = *((_BYTE *)v19 + 12) == 0;
  v19[77] = *(_DWORD *)(*(_DWORD *)(v19[76] + 168) + 948);
  if ( !v27 )
  {
    pointer = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)vostok::configs::binary_config_value::operator[](v23, "empty_hands")->data.pointer;
    v29 = v66;
    m_begin = (char *)pointer;
    v71 = 117;
    if ( v66 != v68 )
    {
      *v66 = pointer;
      v29[1] = (stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *)117;
      v30 = (char *)(v29 + 2);
      goto LABEL_27;
    }
    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
      pointer,
      (unsigned __int8 **)&v65,
      (int)v66,
      (const vostok::collision::ray_object_result *)&m_begin,
      v42,
      v43,
      (bool)v44.m_string.m_begin);
  }
  v30 = (char *)v66;
LABEL_27:
  v31 = (v30 - (char *)v65) >> 3;
  v32 = v31;
  v71 = v31;
  v33 = alloca(4 * v31);
  v34 = &v42;
  for ( v69.m_object = (vostok::configs::binary_config *)&v42; v34 != &(&v42)[v32]; ++v34 )
  {
    if ( v34 )
      *v34 = 0;
  }
  v35 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0xCu);
  *v35 = *v19;
  v35[1] = v19[77];
  v35[2] = 0;
  v54 = 0;
  v55 = 0;
  v64 = (_DWORD *)*v19;
  v55 = vostok::detail::type_to_int<survarium::player_profile const *>::get();
  v53 = v64;
  v52[0] = &vostok::detail::concrete_type_helper<survarium::player_profile const *>::`vftable';
  v54 = v52;
  v69.m_object->__vftable = (vostok::configs::binary_config_vtbl *)v52;
  v50 = 0;
  v51 = 0;
  v51 = vostok::detail::type_to_int<survarium::inventory_cooker_data *>::get();
  v50 = v48;
  v49 = v35;
  v48[0] = &vostok::detail::concrete_type_helper<survarium::inventory_cooker_data *>::`vftable';
  LODWORD(v69.m_object->m_reconstruction_info_actuality_tick) = v48;
  v36 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          8u);
  v36[1] = v19[77];
  *v36 = *v19;
  v64 = v36;
  v58 = 0;
  v59 = 0;
  v59 = vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::get();
  v57 = v64;
  v58 = v56;
  v56[0] = &vostok::detail::concrete_type_helper<survarium::player_parameters_cooker_data *>::`vftable';
  HIDWORD(v69.m_object->m_reconstruction_info_actuality_tick) = v56;
  *((_QWORD *)&v60.functor.data + 1) = __PAIR64__((unsigned int)v19, (unsigned int)v61);
  v46 = survarium::player_cook::on_subresources_loaded;
  v47 = 0;
  v41.f_.f_ = (void (__thiscall *__ptr64)(survarium::player_cook *, vostok::resources::queries_result *, survarium::player_creation_params *, survarium::inventory_cooker_data *, survarium::player_parameters_cooker_data *))(unsigned int)survarium::player_cook::on_subresources_loaded;
  *((_QWORD *)&v60.functor.data + 2) = __PAIR64__((unsigned int)v64, (unsigned int)v35);
  v41.l_.boost::_bi::storage3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > = (boost::_bi::storage3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> >)__PAIR64__((unsigned int)v19, (unsigned int)v61);
  v60.vtable = 0;
  *(_QWORD *)&v41.l_.a4_.t_ = __PAIR64__((unsigned int)v64, (unsigned int)v35);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *,survarium::inventory_cooker_data *,survarium::player_parameters_cooker_data *>,boost::_bi::list5<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *>,boost::_bi::value<survarium::inventory_cooker_data *>,boost::_bi::value<survarium::player_parameters_cooker_data *>>>>(
    0,
    (int)&v60,
    (int)v35,
    v41);
  v37 = v65;
  vostok::resources::query_resources(
    v65,
    v71,
    &v60,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)v69.m_object,
    v62,
    assert_on_fail_true);
  if ( v60.vtable )
  {
    if ( ((int)v60.vtable & 1) == 0 )
    {
      v38 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v60.vtable & 0xFFFFFFFE);
      if ( v38 )
        v38(&v60.functor, &v60.functor, 2);
    }
  }
  if ( v58 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD **))(*v58 + 4))(v58, &v57);
    v58 = 0;
  }
  if ( v50 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD **))(*v50 + 4))(v50, &v49);
    v50 = 0;
  }
  if ( v54 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD **))(*v54 + 4))(v54, &v53);
    v54 = 0;
  }
  if ( v37 )
    (*(void (__thiscall **)(int, const vostok::resources::request *))(*(_DWORD *)f + 24))(f, v37);
  v39 = v63.m_object;
  v40 = &v63.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&v63.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v40, v39);
}
