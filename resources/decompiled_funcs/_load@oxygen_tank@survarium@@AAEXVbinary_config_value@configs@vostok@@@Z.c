void __userpurge survarium::oxygen_tank::load(
        survarium::oxygen_tank *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value config)
{
  vostok::configs::binary_config_value *v3; // ecx
  float value; // xmm0_4
  unsigned int v5; // esi
  vostok::memory::doug_lea_allocator *v6; // eax
  boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::oxygen_tank,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // ecx
  char *v19; // [esp+20h] [ebp-B0h]
  char *source; // [esp+30h] [ebp-A0h]
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *other; // [esp+50h] [ebp-80h]
  boost::function4<float,char const *,char const *,float,float> v22; // [esp+54h] [ebp-7Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+90h] [ebp-40h] BYREF
  double (__thiscall *f)(survarium::oxygen_tank *, const char *, const char *, float, float); // [esp+A4h] [ebp-2Ch]
  int f_4; // [esp+A8h] [ebp-28h]
  survarium::damage_protector *v26; // [esp+ACh] [ebp-24h]
  survarium::oxygen_tank::item_influence *infl; // [esp+B0h] [ebp-20h]
  unsigned int i; // [esp+B4h] [ebp-1Ch]
  vostok::configs::binary_config_value influences; // [esp+B8h] [ebp-18h] BYREF

  vostok::configs::binary_config_value::operator[](&config, "amount_time_sec");
  vostok::configs::binary_config_value::operator float(v3);
  value = a2 * 1000.0;
  this->m_amount_ms = vostok::math::floor(value);
  this->m_max_amount = this->m_amount_ms;
  influences = *vostok::configs::binary_config_value::operator[](&config, "influences");
  this->m_influences_count = vostok::configs::binary_config_value::size(&influences);
  v5 = 120 * this->m_influences_count;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_influences = (survarium::oxygen_tank::item_influence *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                                                                   v6,
                                                                   v5);
  for ( i = 0; i < this->m_influences_count; ++i )
  {
    infl = &this->m_influences[i];
    v26 = (survarium::damage_protector *)operator new(0x50u, infl);
    if ( v26 )
      survarium::damage_protector::damage_protector(v26);
    f = survarium::oxygen_tank::reduce_damage;
    f_4 = 0;
    v7 = (boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::oxygen_tank,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::oxygen_tank::reduce_damage, (survarium::weapon_core_animation_end_aware_state *)this);
    other = (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&infl->protector.reduce_damage_functor;
    boost::function4<float,char const *,char const *,float,float>::function4<float,char const *,char const *,float,float>(
      &v22,
      *v7,
      0);
    boost::function1<unsigned int,char const *>::swap(
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v22,
      other);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(&v22);
    v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&influences, i);
    v9 = vostok::configs::binary_config_value::operator[](v8, "body_part");
    source = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)v9);
    vostok::strings::copy(infl->body_part_name, 0x10u, source);
    v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&influences, i);
    v12 = vostok::configs::binary_config_value::operator[](v11, "hit_type");
    v19 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v13, (int)v12);
    vostok::strings::copy(infl->hit_type, 0x10u, v19);
    v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&influences, i);
    vostok::configs::binary_config_value::operator[](v14, "hit_coeff");
    vostok::configs::binary_config_value::operator float(v15);
    infl->hit_coeff = value;
    v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&influences, i);
    vostok::configs::binary_config_value::operator[](v16, "threshold");
    vostok::configs::binary_config_value::operator float(v17);
    infl->threshold = value;
  }
}
