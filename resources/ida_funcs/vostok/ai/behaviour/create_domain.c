void __thiscall vostok::ai::behaviour::create_domain(
        vostok::ai::behaviour *this,
        vostok::configs::binary_config_value *options,
        survarium::weapon_core_animation_end_aware_state *world)
{
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::ai::planning::pddl_domain *v4; // eax
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v10; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v11; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v12; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v13; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v14; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v15; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v16; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v17; // [esp-14h] [ebp-60Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v18; // [esp-14h] [ebp-60Ch]
  vostok::ai::planning::pddl_domain *v19; // [esp+4h] [ebp-5F4h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > > v21; // [esp+3Ch] [ebp-5BCh]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v22; // [esp+54h] [ebp-5A4h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v23; // [esp+6Ch] [ebp-58Ch]
  vostok::ai::planning::pddl_domain *m_domain; // [esp+154h] [ebp-4A4h]
  char *v25; // [esp+158h] [ebp-4A0h] BYREF
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *v26; // [esp+15Ch] [ebp-49Ch]
  char *v27; // [esp+160h] [ebp-498h] BYREF
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *v28; // [esp+164h] [ebp-494h]
  char *v29; // [esp+168h] [ebp-490h] BYREF
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *v30; // [esp+16Ch] [ebp-48Ch]
  char *v31; // [esp+170h] [ebp-488h] BYREF
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *v32; // [esp+174h] [ebp-484h]
  char *v33; // [esp+178h] [ebp-480h] BYREF
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *v34; // [esp+17Ch] [ebp-47Ch]
  char *v35; // [esp+180h] [ebp-478h] BYREF
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *p_m_registered_types; // [esp+184h] [ebp-474h]
  char *__k; // [esp+188h] [ebp-470h] BYREF
  void *_Where; // [esp+18Ch] [ebp-46Ch]
  vostok::memory::doug_lea_allocator *v39; // [esp+190h] [ebp-468h]
  int v40; // [esp+194h] [ebp-464h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+198h] [ebp-460h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v42; // [esp+1B8h] [ebp-440h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v43; // [esp+1D8h] [ebp-420h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > > v44; // [esp+1E8h] [ebp-410h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v45; // [esp+210h] [ebp-3E8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v46; // [esp+230h] [ebp-3C8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf2<bool,vostok::ai::brain_unit,vostok::ai::animation_item const *,vostok::ai::sound_item const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v47; // [esp+240h] [ebp-3B8h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v48; // [esp+268h] [ebp-390h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v49; // [esp+288h] [ebp-370h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::sound_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > > v50; // [esp+298h] [ebp-360h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v51; // [esp+2C0h] [ebp-338h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v52; // [esp+2E0h] [ebp-318h] BYREF
  bool (__thiscall *v53)(vostok::ai::brain_unit *, const vostok::ai::animation_item *const); // [esp+2F0h] [ebp-308h]
  int v54; // [esp+2F4h] [ebp-304h]
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *> v55; // [esp+2F8h] [ebp-300h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v56; // [esp+318h] [ebp-2E0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v57; // [esp+338h] [ebp-2C0h] BYREF
  int (__thiscall *v58)(vostok::ai::brain_unit *, const vostok::ai::game_object *const); // [esp+348h] [ebp-2B0h]
  int v59; // [esp+34Ch] [ebp-2ACh]
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::game_object const *> v60; // [esp+350h] [ebp-2A8h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v61; // [esp+370h] [ebp-288h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v62; // [esp+390h] [ebp-268h] BYREF
  int (__thiscall *v63)(vostok::ai::ai_world *, const vostok::ai::weapon *); // [esp+3A0h] [ebp-258h]
  int v64; // [esp+3A4h] [ebp-254h]
  boost::function1<bool,vostok::ai::weapon const *> v65; // [esp+3A8h] [ebp-250h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v66; // [esp+3C8h] [ebp-230h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v67; // [esp+3E8h] [ebp-210h] BYREF
  int (__thiscall *v68)(vostok::ai::brain_unit *, const vostok::ai::npc *const); // [esp+3F8h] [ebp-200h]
  int v69; // [esp+3FCh] [ebp-1FCh]
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *> v70; // [esp+400h] [ebp-1F8h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v71; // [esp+420h] [ebp-1D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v72; // [esp+440h] [ebp-1B8h] BYREF
  bool (__thiscall *v73)(vostok::ai::ai_world *, const vostok::ai::npc *); // [esp+450h] [ebp-1A8h]
  int v74; // [esp+454h] [ebp-1A4h]
  boost::function1<bool,vostok::ai::npc const *> v75; // [esp+458h] [ebp-1A0h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v76; // [esp+478h] [ebp-180h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v77; // [esp+498h] [ebp-160h] BYREF
  int (__thiscall *v78)(vostok::ai::brain_unit *); // [esp+4A8h] [ebp-150h]
  int v79; // [esp+4ACh] [ebp-14Ch]
  boost::function1<bool,vostok::ai::brain_unit const *> v80; // [esp+4B0h] [ebp-148h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v81; // [esp+4D0h] [ebp-128h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v82; // [esp+4F0h] [ebp-108h] BYREF
  BOOL (__thiscall *v83)(vostok::ai::brain_unit *); // [esp+500h] [ebp-F8h]
  int v84; // [esp+504h] [ebp-F4h]
  boost::function1<bool,vostok::ai::brain_unit const *> v85; // [esp+508h] [ebp-F0h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v86; // [esp+528h] [ebp-D0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v87; // [esp+548h] [ebp-B0h] BYREF
  int (__thiscall *v88)(vostok::ai::brain_unit *); // [esp+558h] [ebp-A0h]
  int v89; // [esp+55Ch] [ebp-9Ch]
  boost::function1<bool,vostok::ai::brain_unit const *> v90; // [esp+560h] [ebp-98h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v91; // [esp+580h] [ebp-78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > result; // [esp+5A0h] [ebp-58h] BYREF
  int (__thiscall *f)(vostok::ai::brain_unit *); // [esp+5B0h] [ebp-48h]
  int f_4; // [esp+5B4h] [ebp-44h]
  boost::function1<bool,vostok::ai::brain_unit const *> v95; // [esp+5B8h] [ebp-40h] BYREF
  vostok::ai::planning::pddl_domain *v96; // [esp+5D8h] [ebp-20h]
  vostok::ai::planning::generalized_action *action; // [esp+5DCh] [ebp-1Ch]
  unsigned int action_type; // [esp+5E0h] [ebp-18h]
  const vostok::configs::binary_config_value *action_type_value; // [esp+5E4h] [ebp-14h]
  vostok::ai::planning::action_types_enum type; // [esp+5E8h] [ebp-10h]
  const vostok::configs::binary_config_value *actions_value; // [esp+5ECh] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+5F0h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+5F4h] [ebp-4h]

  v40 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v39 = v3;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x40u);
  v96 = (vostok::ai::planning::pddl_domain *)operator new(0x40u, _Where);
  if ( v96 )
  {
    vostok::ai::planning::pddl_domain::pddl_domain(v96);
    v19 = v4;
  }
  else
  {
    v19 = 0;
  }
  this->m_domain = v19;
  p_m_registered_types = &this->m_domain->m_registered_types;
  __k = (char *)type_info::name(&vostok::ai::brain_unit const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     p_m_registered_types,
     (const char *const *)&__k) = 0;
  v34 = &this->m_domain->m_registered_types;
  v35 = (char *)type_info::name(&vostok::ai::npc const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     v34,
     (const char *const *)&v35) = (stlp_std::priv::_Rb_tree_node_base *)1;
  v32 = &this->m_domain->m_registered_types;
  v33 = (char *)type_info::name(&vostok::ai::weapon const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     v32,
     (const char *const *)&v33) = (stlp_std::priv::_Rb_tree_node_base *)2;
  v30 = &this->m_domain->m_registered_types;
  v31 = (char *)type_info::name(&vostok::ai::game_object const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     v30,
     (const char *const *)&v31) = (stlp_std::priv::_Rb_tree_node_base *)4;
  v28 = &this->m_domain->m_registered_types;
  v29 = (char *)type_info::name(&vostok::ai::animation_item const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     v28,
     (const char *const *)&v29) = (stlp_std::priv::_Rb_tree_node_base *)5;
  v26 = &this->m_domain->m_registered_types;
  v27 = (char *)type_info::name(&vostok::ai::sound_item const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     v26,
     (const char *const *)&v27) = (stlp_std::priv::_Rb_tree_node_base *)6;
  m_domain = this->m_domain;
  v25 = (char *)type_info::name(&vostok::ai::movement_target const * `RTTI Type Descriptor', &__type_info_root_node);
  *stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::operator[]<char const *>(
     &m_domain->m_registered_types,
     (const char *const *)&v25) = (stlp_std::priv::_Rb_tree_node_base *)7;
  f = vostok::ai::brain_unit::is_patrolling;
  f_4 = 0;
  v10 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&result,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_patrolling,
           *(_BYTE *)&1_254);
  boost::function1<bool,vostok::ai::brain_unit const *>::function1<bool,vostok::ai::brain_unit const *>(&v95, v10, 0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v91,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v95);
  vostok::ai::planning::pddl_domain::add_predicate1<vostok::ai::brain_unit const *,vostok::ai::brain_unit const *>(
    this->m_domain,
    4u,
    off_9BBD80[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v91);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v91);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v95);
  v88 = vostok::ai::brain_unit::is_at_cover;
  v89 = 0;
  v11 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v87,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_at_cover,
           *(_BYTE *)&1_254);
  boost::function1<bool,vostok::ai::brain_unit const *>::function1<bool,vostok::ai::brain_unit const *>(&v90, v11, 0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v86,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v90);
  vostok::ai::planning::pddl_domain::add_predicate1<vostok::ai::brain_unit const *,vostok::ai::brain_unit const *>(
    this->m_domain,
    5u,
    off_9BBD84[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v86);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v86);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v90);
  v83 = vostok::ai::brain_unit::is_feeling_safe;
  v84 = 0;
  v12 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v82,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_feeling_safe,
           *(_BYTE *)&1_254);
  boost::function1<bool,vostok::ai::brain_unit const *>::function1<bool,vostok::ai::brain_unit const *>(&v85, v12, 0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v81,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v85);
  vostok::ai::planning::pddl_domain::add_predicate1<vostok::ai::brain_unit const *,vostok::ai::brain_unit const *>(
    this->m_domain,
    7u,
    off_9BBD8C[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v81);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v81);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v85);
  v78 = vostok::ai::brain_unit::is_invisible;
  v79 = 0;
  v13 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v77,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_invisible,
           *(_BYTE *)&1_254);
  boost::function1<bool,vostok::ai::brain_unit const *>::function1<bool,vostok::ai::brain_unit const *>(&v80, v13, 0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v76,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v80);
  vostok::ai::planning::pddl_domain::add_predicate1<vostok::ai::brain_unit const *,vostok::ai::brain_unit const *>(
    this->m_domain,
    6u,
    off_9BBD88[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v76);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v76);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v80);
  v73 = vostok::ai::ai_world::is_target_dead;
  v74 = 0;
  v14 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v72,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::is_target_dead,
           world);
  boost::function1<bool,vostok::ai::npc const *>::function1<bool,vostok::ai::npc const *>(
    &v75,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::ai_world,vostok::ai::npc const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > >)v14,
    0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v71,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v75);
  vostok::ai::planning::pddl_domain::add_predicate1<vostok::ai::npc const *,vostok::ai::npc const *>(
    this->m_domain,
    0,
    predicates_captions_0[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v71);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v71);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v75);
  v68 = vostok::ai::brain_unit::is_target_in_melee_range;
  v69 = 0;
  v15 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v67,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_target_in_melee_range,
           *(_BYTE *)&1_254);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>(
    &v70,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::npc const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v15,
    0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v66,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v70);
  vostok::ai::planning::pddl_domain::add_predicate2<vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::brain_unit const *,vostok::ai::npc const *>(
    this->m_domain,
    2u,
    off_9BBD78[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v66);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v70);
  v63 = vostok::ai::ai_world::is_weapon_loaded;
  v64 = 0;
  v16 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v62,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::is_weapon_loaded,
           world);
  boost::function1<bool,vostok::ai::weapon const *>::function1<bool,vostok::ai::weapon const *>(
    &v65,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::ai_world,vostok::ai::weapon const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > >)v16,
    0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v61,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v65);
  vostok::ai::planning::pddl_domain::add_predicate1<vostok::ai::weapon const *,vostok::ai::weapon const *>(
    this->m_domain,
    1u,
    off_9BBD74[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v61);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v61);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v65);
  v58 = vostok::ai::brain_unit::is_at_node;
  v59 = 0;
  v17 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v57,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_at_node,
           *(_BYTE *)&1_254);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::game_object const *>::function2<bool,vostok::ai::brain_unit const *,vostok::ai::game_object const *>(
    &v60,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::game_object const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v17,
    0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v56,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v60);
  vostok::ai::planning::pddl_domain::add_predicate2<vostok::ai::brain_unit const *,vostok::ai::game_object const *,vostok::ai::brain_unit const *,vostok::ai::game_object const *>(
    this->m_domain,
    3u,
    off_9BBD7C[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v56);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v56);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v60);
  v53 = vostok::ai::brain_unit::was_animation_played;
  v54 = 0;
  v18 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v52,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::was_animation_played,
           *(_BYTE *)&1_254);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::function2<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>(
    &v55,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::animation_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v18,
    0);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v51,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v55);
  vostok::ai::planning::pddl_domain::add_predicate2<vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>(
    this->m_domain,
    8u,
    off_9BBD90[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v51);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v55);
  LODWORD(v50.f_.f_) = vostok::ai::brain_unit::was_sound_played;
  HIDWORD(v50.f_.f_) = 0;
  v23 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v49,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::was_sound_played,
           *(_BYTE *)&1_254);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v23.l_.boost::_bi::storage1<boost::arg<1> >,
    &v50.l_);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::sound_item const *>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::sound_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>(
    (boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::sound_item const *> *)&v50.l_,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::sound_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v23);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v48,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50.l_);
  vostok::ai::planning::pddl_domain::add_predicate2<vostok::ai::brain_unit const *,vostok::ai::sound_item const *,vostok::ai::brain_unit const *,vostok::ai::sound_item const *>(
    this->m_domain,
    9u,
    off_9BBD94[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v48);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v48);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v50.l_);
  LODWORD(v47.f_.f_) = vostok::ai::brain_unit::was_played_animation_with_sound;
  HIDWORD(v47.f_.f_) = 0;
  v22 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v46,
           (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::was_played_animation_with_sound,
           *(_BYTE *)&1_254);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v22.l_.boost::_bi::storage1<boost::arg<1> >,
    &v47.l_);
  boost::function3<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf2<bool,vostok::ai::brain_unit,vostok::ai::animation_item const *,vostok::ai::sound_item const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
    (boost::function3<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *> *)&v47.l_,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf2<bool,vostok::ai::brain_unit,vostok::ai::animation_item const *,vostok::ai::sound_item const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v22);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v45,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47.l_);
  vostok::ai::planning::pddl_domain::add_predicate3<vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
    this->m_domain,
    0xAu,
    off_9BBD98[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v45);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v45);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v47.l_);
  LODWORD(v44.f_.f_) = vostok::ai::brain_unit::is_at_position;
  HIDWORD(v44.f_.f_) = 0;
  v5 = boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
         (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v43,
         (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::is_at_position,
         *(_BYTE *)&1_254);
  v21 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > > *)v5;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v5->f_.f_),
    &v44.l_);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::movement_target const *>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>(
    (boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::movement_target const *> *)&v44.l_,
    v21);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v42,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v44.l_);
  vostok::ai::planning::pddl_domain::add_predicate2<vostok::ai::brain_unit const *,vostok::ai::movement_target const *,vostok::ai::brain_unit const *,vostok::ai::movement_target const *>(
    this->m_domain,
    0xBu,
    off_9BBD9C[0],
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v42);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v42);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v44.l_);
  actions_value = vostok::configs::binary_config_value::operator[](options, "action_types");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)actions_value);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)actions_value);
  while ( it != it_end )
  {
    action_type_value = it;
    v6 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it, "id");
    action_type = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                  v7,
                                  (int)v6);
    type = action_type;
    action = vostok::ai::create_action_prototype(
               (vostok::ai::planning::action_types_enum)action_type,
               (vostok::configs::binary_config_value *)action_type_value,
               this->m_domain);
    if ( action )
    {
      vostok::ai::planning::pddl_domain::add_action(this->m_domain, (survarium::game_camera *)action);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v8);
        v40 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\behaviour_domain.cpp",
          0xFCu,
          "void __thiscall vostok::ai::behaviour::create_domain(const class vostok::configs::binary_config_value &,class "
          "vostok::ai::ai_world &)",
          "ai:",
          error,
          "Unknown action type was declared - %d",
          action_type);
      }
      v9 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v40 & 1);
      if ( (v40 & 1) != 0 )
      {
        v40 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v9,
          (int *)&log_callback);
      }
    }
    ++it;
  }
}
