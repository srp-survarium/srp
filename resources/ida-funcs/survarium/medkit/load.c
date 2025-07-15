void __userpurge survarium::medkit::load(
        survarium::medkit *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value config)
{
  vostok::configs::binary_config_value *v3; // ecx
  float v4; // xmm0_4
  vostok::configs::binary_config_value *v5; // ecx
  float v6; // xmm0_4
  unsigned int v7; // esi
  vostok::memory::doug_lea_allocator *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // ecx
  unsigned int v15; // esi
  vostok::memory::doug_lea_allocator *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v22; // ecx
  unsigned int v23; // esi
  vostok::memory::doug_lea_allocator *v24; // eax
  boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::medkit,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::medkit *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *v25; // eax
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *v26; // eax
  vostok::configs::binary_config_value *v27; // eax
  const vostok::configs::binary_config_value *v28; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v29; // ecx
  vostok::configs::binary_config_value *v30; // eax
  const vostok::configs::binary_config_value *v31; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  vostok::configs::binary_config_value *v34; // ecx
  vostok::configs::binary_config_value *v35; // eax
  vostok::configs::binary_config_value *v36; // ecx
  boost::function<float __cdecl(char const *,char const *,float,float)> *value; // [esp+0h] [ebp-130h]
  char *v39; // [esp+10h] [ebp-120h]
  char *v40; // [esp+14h] [ebp-11Ch]
  boost::function<float __cdecl(char const *,char const *,float,float)> v41; // [esp+2Ch] [ebp-104h] BYREF
  char *v42; // [esp+54h] [ebp-DCh]
  char *source; // [esp+6Ch] [ebp-C4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+A8h] [ebp-88h] BYREF
  double (__thiscall *f)(survarium::medkit *, const char *, const char *, float, float); // [esp+BCh] [ebp-74h]
  int f_4; // [esp+C0h] [ebp-70h]
  survarium::damage_protector *v47; // [esp+C4h] [ebp-6Ch]
  survarium::medkit::damage_protection *dmgp; // [esp+C8h] [ebp-68h]
  int j; // [esp+CCh] [ebp-64h]
  survarium::medkit::affect *affct; // [esp+D0h] [ebp-60h]
  int index; // [esp+D4h] [ebp-5Ch]
  survarium::medkit::item_influence *infl; // [esp+D8h] [ebp-58h]
  unsigned int i; // [esp+DCh] [ebp-54h]
  float activation_delay_sec; // [esp+E0h] [ebp-50h]
  float activity_time_sec; // [esp+E4h] [ebp-4Ch]
  vostok::configs::binary_config_value remove_affects; // [esp+E8h] [ebp-48h] BYREF
  vostok::configs::binary_config_value influences; // [esp+100h] [ebp-30h] BYREF
  vostok::configs::binary_config_value damage_protect; // [esp+118h] [ebp-18h] BYREF

  vostok::configs::binary_config_value::operator[](&config, "activity_time_sec");
  vostok::configs::binary_config_value::operator float(v3);
  vostok::math::max();
  activity_time_sec = a2;
  v4 = 1000.0 * a2;
  this->m_config_activity_time_ms = vostok::math::floor(v4);
  vostok::configs::binary_config_value::operator[](&config, "activation_delay_sec");
  vostok::configs::binary_config_value::operator float(v5);
  activation_delay_sec = v4;
  v6 = 1000.0 * v4;
  this->m_config_delay_ms = vostok::math::floor(v6);
  influences = *vostok::configs::binary_config_value::operator[](&config, "influences");
  this->m_influences_count = vostok::configs::binary_config_value::size(&influences);
  v7 = 20 * this->m_influences_count;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_influences = (survarium::medkit::item_influence *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                                                              v8,
                                                              v7);
  vostok::configs::binary_config_value::operator[](&config, "add_stamina_regen");
  vostok::configs::binary_config_value::operator float(v9);
  this->m_add_stamina_regen = v6;
  for ( i = 0; i < this->m_influences_count; ++i )
  {
    infl = &this->m_influences[i];
    v10 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&influences, i);
    v11 = vostok::configs::binary_config_value::operator[](v10, "body_part");
    source = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                       v12,
                       (int)v11);
    vostok::strings::copy(infl->body_part_name, 0x10u, source);
    v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&influences, i);
    vostok::configs::binary_config_value::operator[](v13, "amount");
    vostok::configs::binary_config_value::operator float(v14);
    infl->health_amount = v6;
    v6 = infl->health_amount / activity_time_sec;
    infl->health_amount = v6;
  }
  remove_affects = *vostok::configs::binary_config_value::operator[](&config, "remove_affects");
  this->m_affects_count = vostok::configs::binary_config_value::size(&remove_affects);
  v15 = 20 * this->m_affects_count;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_affects = (survarium::medkit::affect *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                                                   v16,
                                                   v15);
  for ( index = 0; index < (unsigned int)this->m_affects_count; ++index )
  {
    affct = &this->m_affects[index];
    v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &remove_affects,
                                                    index);
    v18 = vostok::configs::binary_config_value::operator[](v17, "body_part");
    v42 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v19, (int)v18);
    vostok::strings::copy(affct->body_part_name, 0x10u, v42);
    v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &remove_affects,
                                                    index);
    v21 = vostok::configs::binary_config_value::operator[](v20, "affect");
    affct->type = (survarium::hit_affects_type_enum)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                      v22,
                                                      (int)v21);
  }
  damage_protect = *vostok::configs::binary_config_value::operator[](&config, "damage_protection");
  this->m_damage_protect_count = vostok::configs::binary_config_value::size(&damage_protect);
  v23 = 120 * this->m_damage_protect_count;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_damage_protect = (survarium::medkit::damage_protection *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                                                                     v24,
                                                                     v23);
  for ( j = 0; j < (unsigned int)this->m_damage_protect_count; ++j )
  {
    dmgp = &this->m_damage_protect[j];
    v47 = (survarium::damage_protector *)operator new(0x50u, dmgp);
    if ( v47 )
      survarium::damage_protector::damage_protector(v47);
    f = survarium::medkit::reduce_damage;
    f_4 = 0;
    v25 = (boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::medkit,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::medkit *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::medkit::reduce_damage, (survarium::weapon_core_animation_end_aware_state *)this);
    value = &dmgp->protector.reduce_damage_functor;
    boost::function<float __cdecl (char const *,char const *,float,float)>::function<float __cdecl (char const *,char const *,float,float)>(
      &v41,
      *v25,
      0);
    boost::function1<unsigned int,char const *>::swap(
      v26,
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)value);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(&v41);
    v27 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&damage_protect, j);
    v28 = vostok::configs::binary_config_value::operator[](v27, "body_part");
    v40 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v29, (int)v28);
    vostok::strings::copy(dmgp->body_part_name, 0x10u, v40);
    v30 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&damage_protect, j);
    v31 = vostok::configs::binary_config_value::operator[](v30, "hit_type");
    v39 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v32, (int)v31);
    vostok::strings::copy(dmgp->hit_type, 0x10u, v39);
    v33 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&damage_protect, j);
    vostok::configs::binary_config_value::operator[](v33, "hit_coeff");
    vostok::configs::binary_config_value::operator float(v34);
    dmgp->hit_coeff = v6;
    v35 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&damage_protect, j);
    vostok::configs::binary_config_value::operator[](v35, "threshold");
    vostok::configs::binary_config_value::operator float(v36);
    dmgp->threshold = v6;
  }
}
