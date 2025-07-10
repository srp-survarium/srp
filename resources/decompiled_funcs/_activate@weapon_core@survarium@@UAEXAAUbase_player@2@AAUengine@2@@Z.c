void __thiscall survarium::weapon_core::activate(
        survarium::weapon_core *this,
        survarium::base_player *user,
        survarium::engine *engine)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  survarium::weapon_core *v7; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v8; // ecx
  survarium::weapon_core *v9; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v10; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  const vostok::variant<32> **v12; // eax
  const vostok::animation::skeleton *v13; // eax
  const vostok::animation::skeleton *v14; // eax
  survarium::game_camera *v15; // ecx
  int v16; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v17; // ecx
  vostok::socket_error_types_enum *v18; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v19; // ecx
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v20; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v21; // ecx
  vostok::resources::unmanaged_resource *v22; // ecx
  const char *v23; // eax
  survarium::inventory_item *v24; // ecx
  survarium::weapon_core *v25; // ecx
  survarium::weapon_core *v26; // ecx
  survarium::base_player *v27; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v28; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v29; // eax
  survarium::weapon_core *v30; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v31; // ecx
  survarium::weapon_core *v32; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v33; // ecx
  survarium::weapon_core *v34; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v35; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v36; // [esp-18h] [ebp-470h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v37; // [esp-18h] [ebp-470h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v38; // [esp-18h] [ebp-470h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v39; // [esp-18h] [ebp-470h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v40; // [esp-18h] [ebp-470h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v41; // [esp-18h] [ebp-470h]
  const vostok::animation::skeleton *v42; // [esp-4h] [ebp-45Ch]
  survarium::base_player *v43; // [esp+8h] [ebp-450h]
  survarium::base_player *v44; // [esp+Ch] [ebp-44Ch]
  survarium::base_player *v45; // [esp+10h] [ebp-448h]
  survarium::base_player *v46; // [esp+14h] [ebp-444h]
  survarium::profile_slot_enum v47; // [esp+18h] [ebp-440h]
  survarium::base_player *v48; // [esp+20h] [ebp-438h]
  survarium::base_player *v49; // [esp+24h] [ebp-434h]
  survarium::hit_receiver *v50; // [esp+28h] [ebp-430h]
  survarium::hit_initiator *v51; // [esp+2Ch] [ebp-42Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v53; // [esp+38h] [ebp-420h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v54; // [esp+4Ch] [ebp-40Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v55; // [esp+5Ch] [ebp-3FCh]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v56; // [esp+6Ch] [ebp-3ECh]
  vostok::sound::encoded_sound_interface *(__thiscall *v57)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+84h] [ebp-3D4h]
  survarium::weapon_user_animations_container *v58; // [esp+88h] [ebp-3D0h]
  survarium::weapon_user_animations_container *object; // [esp+90h] [ebp-3C8h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > v60; // [esp+9Ch] [ebp-3BCh]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > v61; // [esp+ACh] [ebp-3ACh]
  char v62; // [esp+124h] [ebp-334h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v63; // [esp+128h] [ebp-330h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v64; // [esp+138h] [ebp-320h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v65; // [esp+164h] [ebp-2F4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v66; // [esp+168h] [ebp-2F0h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v67; // [esp+178h] [ebp-2E0h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v68; // [esp+1A4h] [ebp-2B4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v69; // [esp+1A8h] [ebp-2B0h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v70; // [esp+1B8h] [ebp-2A0h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v71; // [esp+1E4h] [ebp-274h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v72; // [esp+1E8h] [ebp-270h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v73; // [esp+1F8h] [ebp-260h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v74; // [esp+224h] [ebp-234h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+228h] [ebp-230h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v76; // [esp+24Ch] [ebp-20Ch] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v77; // [esp+250h] [ebp-208h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v78; // [esp+254h] [ebp-204h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > v79; // [esp+258h] [ebp-200h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > v80; // [esp+268h] [ebp-1F0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > v81; // [esp+290h] [ebp-1C8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > v82; // [esp+2A0h] [ebp-1B8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > v83; // [esp+2C8h] [ebp-190h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &,enum survarium::hand_to_weapon_ik_processor::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>,boost::_bi::value<enum survarium::hand_to_weapon_ik_processor::hands_enum> > > v84; // [esp+2D8h] [ebp-180h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v85; // [esp+304h] [ebp-154h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > v86; // [esp+308h] [ebp-150h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &,enum survarium::hand_to_weapon_ik_processor::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>,boost::_bi::value<enum survarium::hand_to_weapon_ik_processor::hands_enum> > > v87; // [esp+318h] [ebp-140h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v88; // [esp+344h] [ebp-114h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v89; // [esp+348h] [ebp-110h] BYREF
  vostok::animation::callback_return_type_enum (__thiscall *v90)(survarium::weapon_core *, vostok::animation::animation_callback_params *); // [esp+358h] [ebp-100h]
  int v91; // [esp+35Ch] [ebp-FCh]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v92; // [esp+360h] [ebp-F8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v93; // [esp+384h] [ebp-D4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v94; // [esp+388h] [ebp-D0h] BYREF
  vostok::animation::callback_return_type_enum (__thiscall *v95)(survarium::weapon_core *, vostok::animation::animation_callback_params *); // [esp+398h] [ebp-C0h]
  int v96; // [esp+39Ch] [ebp-BCh]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v97; // [esp+3A0h] [ebp-B8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v98; // [esp+3C4h] [ebp-94h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v99; // [esp+3C8h] [ebp-90h] BYREF
  vostok::animation::callback_return_type_enum (__thiscall *v100)(survarium::weapon_core *, vostok::animation::animation_callback_params *); // [esp+3D8h] [ebp-80h]
  int v101; // [esp+3DCh] [ebp-7Ch]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v102; // [esp+3E0h] [ebp-78h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v103; // [esp+404h] [ebp-54h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+408h] [ebp-50h] BYREF
  vostok::animation::callback_return_type_enum (__thiscall *f)(survarium::weapon_core *, vostok::animation::animation_callback_params *); // [esp+418h] [ebp-40h]
  int f_4; // [esp+41Ch] [ebp-3Ch]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v107; // [esp+420h] [ebp-38h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v108; // [esp+444h] [ebp-14h] BYREF
  const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *ammo1; // [esp+448h] [ebp-10h]
  const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *ammo2; // [esp+44Ch] [ebp-Ch]
  survarium::profile_slot_enum ammo1_slot; // [esp+450h] [ebp-8h]
  survarium::profile_slot_enum ammo2_slot; // [esp+454h] [ebp-4h]

  v62 = 0;
  survarium::character_dispersion_calculator::set_character_dispersion_params(
    &this->m_dispersion_calculator.m_character_calculator,
    &user->m_dispersion_params);
  survarium::character_recoil_calculator::set_character_recoil_params(
    &this->m_recoil_calculator.m_character_calculator,
    &user->m_recoil_params);
  this->m_breath_vibration_calculator.m_user = user;
  survarium::breath_vibration_calculator::set_breath_holding_params(
    &this->m_breath_vibration_calculator,
    &user->m_breath_holding_params);
  this->m_is_shown = 0;
  this->m_bullet_manager = (survarium::bullet_manager *)engine->get_bullet_manager(engine);
  this->m_ready_for_fire = 0;
  this->m_is_in_sprint_transition = 0;
  if ( user )
    v51 = &user->survarium::hit_initiator;
  else
    v51 = 0;
  this->m_initiator_holder = v51;
  if ( user )
    v50 = &user->survarium::hit_receiver;
  else
    v50 = 0;
  this->m_receiver_holder = v50;
  this->m_is_firing = 0;
  survarium::dispersion_calculator::set_weapon(&this->m_dispersion_calculator, this);
  survarium::recoil_calculator::set_weapon(&this->m_recoil_calculator, this);
  qmemcpy((void *)&this->m_transform, user->get_transform(&user->survarium::collision_user), sizeof(this->m_transform));
  v42 = (const vostok::animation::skeleton *)user->get_transform(&user->survarium::collision_user);
  ((void (__thiscall *)(survarium::weapon_core *))this->set_fire_bullet_transform)(this);
  this->m_user = user;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v108,
    0);
  f = survarium::weapon_core::on_animation_ik_interval;
  f_4 = 0;
  v36 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::on_animation_ik_interval,
           (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    &v107,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v36,
    0);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "Left toe",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v107,
    this,
    &v108,
    255u,
    0);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v3,
    (int *)&v107);
  vostok::animation::mixing::animation_interval::~animation_interval(&v108);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v103,
    0);
  v100 = survarium::weapon_core::on_animation_ik_interval;
  v101 = 0;
  v37 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v99,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::on_animation_ik_interval,
           (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    &v102,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v37,
    0);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "Left heel",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v102,
    this,
    &v103,
    255u,
    0);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (int *)&v102);
  vostok::animation::mixing::animation_interval::~animation_interval(&v103);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v98,
    0);
  v95 = survarium::weapon_core::on_animation_ik_interval;
  v96 = 0;
  v38 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v94,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::on_animation_ik_interval,
           (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    &v97,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v38,
    0);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "Right toe",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v97,
    this,
    &v98,
    255u,
    0);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (int *)&v97);
  vostok::animation::mixing::animation_interval::~animation_interval(&v98);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v93,
    0);
  v90 = survarium::weapon_core::on_animation_ik_interval;
  v91 = 0;
  v39 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v89,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::on_animation_ik_interval,
           (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    &v92,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v39,
    0);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "Right heel",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v92,
    this,
    &v93,
    255u,
    0);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v92);
  vostok::animation::mixing::animation_interval::~animation_interval(&v93);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v88,
    0);
  LODWORD(v87.f_.f_) = survarium::weapon_core::on_hand_ik_event;
  HIDWORD(v87.f_.f_) = 0;
  v40 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&v86,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)survarium::weapon_core::on_hand_ik_event,
           (survarium::game_material_manager_cook *)this,
           1_170,
           0);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    (boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&v87.l_,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &,enum survarium::hand_to_weapon_ik_processor::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>,boost::_bi::value<enum survarium::hand_to_weapon_ik_processor::hands_enum> > >)v40,
    0);
  v49 = survarium::weapon_core::get_user(v7, (int)this);
  v49->subscribe_animation_player(
    v49,
    "left_hand_ik",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v87.l_,
    this,
    &v88,
    255u,
    0);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v8,
    (int *)&v87.l_);
  vostok::animation::mixing::animation_interval::~animation_interval(&v88);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v85,
    0);
  LODWORD(v84.f_.f_) = survarium::weapon_core::on_hand_ik_event;
  HIDWORD(v84.f_.f_) = 0;
  v41 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&v83,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)survarium::weapon_core::on_hand_ik_event,
           (survarium::game_material_manager_cook *)this,
           1_170,
           (vostok::math::float4x4 *)1);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    (boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&v84.l_,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &,enum survarium::hand_to_weapon_ik_processor::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>,boost::_bi::value<enum survarium::hand_to_weapon_ik_processor::hands_enum> > >)v41,
    0);
  v48 = survarium::weapon_core::get_user(v9, (int)this);
  v48->subscribe_animation_player(
    v48,
    "right_hand_ik",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v84.l_,
    this,
    &v85,
    255u,
    0);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v10,
    (int *)&v84.l_);
  vostok::animation::mixing::animation_interval::~animation_interval(&v85);
  v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          v11,
          (int)&this->m_skeleton);
  v13 = (const vostok::animation::skeleton *)((int (__thiscall *)(survarium::base_player *, const vostok::variant<32> **))user->skeleton)(
                                               user,
                                               v12);
  survarium::hand_to_weapon_ik_processor::activate(&this->m_hand_ik_processor, v13, v42);
  v14 = user->skeleton(user);
  survarium::legs_ik_processor::activate(&this->m_legs_ik_processor, v14);
  this->m_legs_ik_processor.m_character_controller = this->m_user->physics_controller(this->m_user);
  LODWORD(v82.f_.f_) =  __thiscall survarium::weapon_core::`vcall'{196,{flat}};
  HIDWORD(v82.f_.f_) = 0;
  v61 = *boost::bind<void,survarium::weapon_core,bool,survarium::weapon_core *,bool>(
           &v81,
           (void (__thiscall *__ptr64)(survarium::weapon_core *, bool))(unsigned int) __thiscall survarium::weapon_core::`vcall'{196,{flat}},
           this,
           0);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v61.l_.a1_.t_,
    &v82.l_.a1_.t_);
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool>>>>(
    (boost::function0<void> *)&v82.l_,
    v61);
  LODWORD(v80.f_.f_) =  __thiscall survarium::weapon_core::`vcall'{196,{flat}};
  HIDWORD(v80.f_.f_) = 0;
  v60 = *boost::bind<void,survarium::weapon_core,bool,survarium::weapon_core *,bool>(
           &v79,
           (void (__thiscall *__ptr64)(survarium::weapon_core *, bool))(unsigned int) __thiscall survarium::weapon_core::`vcall'{196,{flat}},
           this,
           1);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v60.l_.a1_.t_,
    &v80.l_.a1_.t_);
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool>>>>(
    (boost::function0<void> *)&v80.l_,
    v60);
  survarium::weapon_user_animations_selector::activate(
    &this->m_user_animations_selector,
    user,
    (const boost::function<void __cdecl(void)> *)&v80.l_,
    (const boost::function<void __cdecl(void)> *)&v82.l_);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v80.l_);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v82.l_);
  survarium::weapon_user_dead_state::finalize(v15);
  v18 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
          v17,
          v16);
  vostok::ai::fsm::set_initial_state(this->m_logic, (vostok::ai::fsm_state *)v18);
  vostok::ai::fsm::tick(this->m_logic);
  ammo1_slot = survarium::weapon_core::get_ammo_slot(this, first_ammo);
  ammo2_slot = survarium::weapon_core::get_ammo_slot(this, second_ammo);
  ammo1 = survarium::inventory::item_in_slot((survarium::inventory *)ammo1_slot, (int)this->m_inventory);
  ammo2 = survarium::inventory::item_in_slot((survarium::inventory *)ammo2_slot, (int)this->m_inventory);
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v19,
         ammo1) )
  {
    object = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)ammo1);
    v78.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v78,
      object);
    survarium::weapon_core::set_ammunition(this, &v78);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  }
  else if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
              v20,
              ammo2) )
  {
    v58 = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)ammo2);
    v77.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v77,
      v58);
    survarium::weapon_core::set_ammunition(this, &v77);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v77);
  }
  else
  {
    v76.m_object = 0;
    survarium::weapon_core::set_ammunition(this, &v76);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v76);
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "weapon_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v21);
      v62 = 1;
      v23 = vostok::resources::unmanaged_resource::request_path(v22);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\weapon_core.cpp",
        0x355u,
        "void __thiscall survarium::weapon_core::activate(struct survarium::base_player &,struct survarium::engine &)",
        "weapon_core:",
        error,
        "There is no ammo in both slots (%s)",
        v23);
    }
    if ( (v62 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v21,
        (int *)&log_callback);
  }
  if ( this->m_ammunition.m_object )
    v57 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
  else
    v57 = 0;
  if ( v57 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v21);
    v47 = survarium::inventory_item::profile_slot_id(v24, (int)this->m_ammunition.m_object);
  }
  else
  {
    v47 = max_slots_count;
  }
  this->m_ammo_slot = v47;
  if ( this->m_load_ammo_on_next_activate )
  {
    survarium::weapon_core::load_ammo(this);
    this->m_load_ammo_on_next_activate = 0;
  }
  survarium::weapon_core::reset_fire_queue(this);
  survarium::weapon_core::instant_show(this);
  if ( g_is_server )
  {
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v74,
      0);
    LODWORD(v73.f_.f_) = boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter;
    HIDWORD(v73.f_.f_) = 0;
    v56 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v72,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter,
             (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v56.l_.a1_.t_,
      &v73.l_.a1_.t_);
    boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>>>>(
      (boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&v73.l_,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v56);
    v46 = survarium::weapon_core::get_user(v25, (int)this);
    v27 = survarium::weapon_core::get_user(v26, (int)this);
    v46->subscribe_animation_player(
      v46,
      "sound_events",
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v73.l_,
      v27,
      &v74,
      255u,
      0);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v28,
      (int *)&v73.l_);
    vostok::animation::mixing::animation_interval::~animation_interval(&v74);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v71,
      0);
    LODWORD(v70.f_.f_) = boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter;
    HIDWORD(v70.f_.f_) = 0;
    v29 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v69,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v55 = *(boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > *)v29;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v29->f_.f_),
      &v70.l_.a1_.t_);
    boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>>>>(
      (boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&v70.l_,
      v55);
    v45 = survarium::weapon_core::get_user(v30, (int)this);
    v45->subscribe_animation_player(
      v45,
      "shell_extraction",
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v70.l_,
      this,
      &v71,
      255u,
      0);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v31,
      (int *)&v70.l_);
    vostok::animation::mixing::animation_interval::~animation_interval(&v71);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v68,
      0);
    LODWORD(v67.f_.f_) = boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter;
    HIDWORD(v67.f_.f_) = 0;
    v54 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v66,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter,
             (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v54.l_.a1_.t_,
      &v67.l_.a1_.t_);
    boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>>>>(
      (boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&v67.l_,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v54);
    v44 = survarium::weapon_core::get_user(v32, (int)this);
    v44->subscribe_animation_player(
      v44,
      "left_hand_corrector",
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v67.l_,
      this,
      &v68,
      255u,
      0);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v33,
      (int *)&v67.l_);
    vostok::animation::mixing::animation_interval::~animation_interval(&v68);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v65,
      0);
    LODWORD(v64.f_.f_) = boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter;
    HIDWORD(v64.f_.f_) = 0;
    v53 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v63,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)boost::detail::sp_counted_impl_p<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::get_deleter,
             (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v53.l_.a1_.t_,
      &v64.l_.a1_.t_);
    boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1>>>>(
      (boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&v64.l_,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v53);
    v43 = survarium::weapon_core::get_user(v34, (int)this);
    v43->subscribe_animation_player(
      v43,
      "right_hand_corrector",
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v64.l_,
      this,
      &v65,
      255u,
      0);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v35,
      (int *)&v64.l_);
    vostok::animation::mixing::animation_interval::~animation_interval(&v65);
  }
}
