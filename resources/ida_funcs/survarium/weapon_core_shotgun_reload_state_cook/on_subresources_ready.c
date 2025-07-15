void __thiscall survarium::weapon_core_shotgun_reload_state_cook::on_subresources_ready(
        survarium::weapon_core_shotgun_reload_state_cook *this,
        vostok::resources::queries_result *data,
        vostok::mutable_buffer buffer,
        survarium::weapon_core *params)
{
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *v4; // ecx
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *v5; // ecx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // eax
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *v8; // ecx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v9; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v10; // eax
  survarium::game_camera *v11; // ecx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v12; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v13; // eax
  vostok::resources::unmanaged_resource *v14; // ecx
  unsigned __int16 magazine_capacity; // ax
  survarium::game_camera *v16; // ecx
  vostok::memory::doug_lea_allocator *v17; // eax
  survarium::game_camera *v18; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  const vostok::variant<32> **v20; // eax
  survarium::weapon_core_shotgun_reload_start_substate *v21; // eax
  vostok::memory::doug_lea_allocator *v22; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v23; // ecx
  const vostok::variant<32> **v24; // eax
  survarium::game_camera *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v27; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v28; // ecx
  const vostok::variant<32> **v29; // eax
  survarium::weapon_core_shotgun_reload_finish_substate *v30; // eax
  const vostok::variant<32> **v31; // eax
  survarium::weapon_core_shotgun_reload_state *v32; // eax
  vostok::resources::memory_usage_type *v33; // eax
  vostok::resources::unmanaged_resource *v34; // ecx
  vostok::resources::queries_result *v35; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  vostok::resources::queries_result *v37; // ecx
  vostok::resources::query_result_for_cook *v38; // eax
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *v39; // ecx
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *v40; // ecx
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *v41; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> reload_time[3]; // [esp+8h] [ebp-174h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+14h] [ebp-168h]
  vostok::resources::unmanaged_resource *object; // [esp+18h] [ebp-164h]
  survarium::weapon_core_shotgun_reload_state *v45; // [esp+1Ch] [ebp-160h]
  survarium::weapon_core_shotgun_reload_finish_substate *v46; // [esp+20h] [ebp-15Ch]
  survarium::game_camera *v47; // [esp+24h] [ebp-158h]
  survarium::weapon_core_shotgun_reload_start_substate *v48; // [esp+28h] [ebp-154h]
  vostok::resources::query_result_for_user *v49; // [esp+2Ch] [ebp-150h]
  unsigned int v50; // [esp+30h] [ebp-14Ch]
  vostok::resources::query_result_for_user *v51; // [esp+34h] [ebp-148h]
  unsigned int v52; // [esp+38h] [ebp-144h]
  vostok::resources::query_result_for_user *v53; // [esp+3Ch] [ebp-140h]
  unsigned int index; // [esp+40h] [ebp-13Ch]
  survarium::weapon_core_shotgun_reload_state_cook *thisa; // [esp+44h] [ebp-138h]
  void *v56; // [esp+4Ch] [ebp-130h]
  vostok::memory::doug_lea_allocator *v57; // [esp+50h] [ebp-12Ch]
  void *v58; // [esp+58h] [ebp-124h]
  vostok::memory::doug_lea_allocator *v59; // [esp+5Ch] [ebp-120h]
  void *_Where; // [esp+64h] [ebp-118h]
  vostok::memory::doug_lea_allocator *v61; // [esp+68h] [ebp-114h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reload_one_round_anim; // [esp+80h] [ebp-FCh]
  char v63; // [esp+86h] [ebp-F6h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v64; // [esp+ACh] [ebp-D0h] BYREF
  survarium::weapon_core_shotgun_reload_state *v65; // [esp+B4h] [ebp-C8h]
  survarium::weapon_core_shotgun_reload_finish_substate *v66; // [esp+B8h] [ebp-C4h]
  survarium::weapon_core_shotgun_reload_one_round_substate *v67; // [esp+BCh] [ebp-C0h]
  survarium::weapon_core_shotgun_reload_start_substate *v68; // [esp+C0h] [ebp-BCh]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v69; // [esp+C4h] [ebp-B8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v70; // [esp+C8h] [ebp-B4h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v71; // [esp+CCh] [ebp-B0h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v72; // [esp+D0h] [ebp-ACh] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v73; // [esp+D4h] [ebp-A8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> result; // [esp+D8h] [ebp-A4h] BYREF
  char v75; // [esp+DFh] [ebp-9Dh]
  int k; // [esp+E0h] [ebp-9Ch]
  int j; // [esp+E4h] [ebp-98h]
  unsigned int i; // [esp+E8h] [ebp-94h]
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> start_animations; // [esp+ECh] [ebp-90h] BYREF
  survarium::weapon_core_shotgun_reload_state *object_to_cook; // [esp+114h] [ebp-68h]
  float animations_timescale; // [esp+118h] [ebp-64h]
  unsigned int resource_index; // [esp+11Ch] [ebp-60h]
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> finish_animations; // [esp+120h] [ebp-5Ch] BYREF
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> reload_one_animations; // [esp+148h] [ebp-34h] BYREF
  survarium::weapon_core_shotgun_reload_start_substate *reload_start; // [esp+170h] [ebp-Ch]
  survarium::weapon_core_shotgun_reload_one_round_substate *reload_one_round; // [esp+174h] [ebp-8h]
  survarium::weapon_core_shotgun_reload_finish_substate *reload_finish; // [esp+178h] [ebp-4h]

  thisa = this;
  v75 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  resource_index = 0;
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
    v4,
    &start_animations);
  for ( i = 0; i != 8; ++i )
  {
    index = resource_index;
    v53 = vostok::resources::queries_result::operator[](data, resource_index++);
    managed_resource = vostok::resources::query_result_for_user::get_managed_resource(v53, &result);
    v7 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
           managed_resource,
           &v73);
    vostok::buffer_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::push_back(
      &start_animations,
      v7);
    vostok::animation::mixing::animation_interval::~animation_interval(&v73);
    vostok::animation::mixing::animation_interval::~animation_interval(&result);
    v5 = (vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *)(i + 1);
  }
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
    v5,
    &reload_one_animations);
  for ( j = 0; j != 8; ++j )
  {
    v52 = resource_index;
    v51 = vostok::resources::queries_result::operator[](data, resource_index++);
    v9 = vostok::resources::query_result_for_user::get_managed_resource(v51, &v72);
    v10 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
            v9,
            &v71);
    vostok::buffer_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::push_back(
      &reload_one_animations,
      v10);
    vostok::animation::mixing::animation_interval::~animation_interval(&v71);
    vostok::animation::mixing::animation_interval::~animation_interval(&v72);
  }
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
    v8,
    &finish_animations);
  for ( k = 0; k != 8; ++k )
  {
    v50 = resource_index;
    v49 = vostok::resources::queries_result::operator[](data, resource_index++);
    v12 = vostok::resources::query_result_for_user::get_managed_resource(v49, &v70);
    v13 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
            v12,
            &v69);
    vostok::buffer_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::push_back(
      &finish_animations,
      v13);
    vostok::animation::mixing::animation_interval::~animation_interval(&v69);
    vostok::animation::mixing::animation_interval::~animation_interval(&v70);
  }
  v63 = 0;
  survarium::weapon_user_dead_state::finalize(v11);
  reload_one_round_anim = reload_one_animations.m_begin;
  reload_time[0].m_object = v14;
  reload_time[0] = *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(&params->vostok::resources::resource_flags + 1);
  magazine_capacity = survarium::weapon_core::get_magazine_capacity(params, params->type);
  animations_timescale = survarium::computed_shotgun_reload_animation_time_scale(
                           reload_one_round_anim,
                           magazine_capacity,
                           *(float *)&reload_time[0].m_object);
  survarium::weapon_user_dead_state::finalize(v16);
  v61 = v17;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v17, 0x170u);
  v68 = (survarium::weapon_core_shotgun_reload_start_substate *)operator new(0x170u, _Where);
  if ( v68 )
  {
    reload_time[0].m_object = (vostok::resources::unmanaged_resource *)stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size((stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)&start_animations);
    v20 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v19,
            (int)&start_animations);
    survarium::weapon_core_shotgun_reload_start_substate::weapon_core_shotgun_reload_start_substate(
      v68,
      (survarium::weapon_core *)params->type,
      1.0,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v20,
      (const unsigned int)reload_time[0].m_object);
    v48 = v21;
  }
  else
  {
    v48 = 0;
  }
  reload_start = v48;
  survarium::weapon_user_dead_state::finalize(v18);
  v59 = v22;
  v58 = vostok::memory::doug_lea_allocator::malloc_impl(v22, 0x168u);
  v67 = (survarium::weapon_core_shotgun_reload_one_round_substate *)operator new(0x168u, v58);
  if ( v67 )
  {
    reload_time[0].m_object = (vostok::resources::unmanaged_resource *)stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size((stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)&reload_one_animations);
    v24 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v23,
            (int)&reload_one_animations);
    survarium::weapon_core_shotgun_reload_one_round_substate::weapon_core_shotgun_reload_one_round_substate(
      v67,
      (survarium::weapon_core *)params->type,
      animations_timescale,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v24,
      (const unsigned int)reload_time[0].m_object);
    v47 = v25;
  }
  else
  {
    v47 = 0;
  }
  reload_one_round = (survarium::weapon_core_shotgun_reload_one_round_substate *)v47;
  survarium::weapon_user_dead_state::finalize(v47);
  v57 = v26;
  v56 = vostok::memory::doug_lea_allocator::malloc_impl(v26, 0x170u);
  v66 = (survarium::weapon_core_shotgun_reload_finish_substate *)operator new(0x170u, v56);
  if ( v66 )
  {
    reload_time[0].m_object = (vostok::resources::unmanaged_resource *)stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size((stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)&finish_animations);
    v29 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v28,
            (int)&finish_animations);
    survarium::weapon_core_shotgun_reload_finish_substate::weapon_core_shotgun_reload_finish_substate(
      v66,
      (survarium::weapon_core *)params->type,
      1.0,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v29,
      (const unsigned int)reload_time[0].m_object);
    v46 = v30;
  }
  else
  {
    v46 = 0;
  }
  reload_finish = v46;
  v31 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v27, (int)&buffer);
  v65 = (survarium::weapon_core_shotgun_reload_state *)operator new(0x140u, v31);
  if ( v65 )
  {
    survarium::weapon_core_shotgun_reload_state::weapon_core_shotgun_reload_state(
      v65,
      (survarium::weapon_core *)params->type,
      reload_start,
      reload_one_round,
      reload_finish);
    v45 = v32;
  }
  else
  {
    v45 = 0;
  }
  object_to_cook = v45;
  if ( v45 )
    object = &object_to_cook->vostok::resources::unmanaged_resource;
  else
    object = 0;
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v64,
    (vostok::network_core::packet_reader *)0x20,
    (vostok::network_core::packet_reader *)reload_time[1].m_object);
  memory_usage = v33;
  reload_time[0].m_object = v34;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    reload_time,
    (vostok::configs::binary_config *)object);
  parent_query = vostok::resources::queries_result::get_parent_query(v35, (int)data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(parent_query, reload_time[0], memory_usage);
  reload_time[0].m_object = (vostok::resources::unmanaged_resource *)1;
  v38 = vostok::resources::queries_result::get_parent_query(v37, (int)data);
  vostok::resources::query_result_for_cook::finish_query(
    v38,
    result_success,
    (assert_on_fail_bool)reload_time[0].m_object);
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::~fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
    v39,
    (int)&finish_animations);
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::~fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
    v40,
    (int)&reload_one_animations);
  vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::~fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
    v41,
    (int)&start_animations);
}
