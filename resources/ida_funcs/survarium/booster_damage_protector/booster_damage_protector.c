void __thiscall survarium::booster_damage_protector::booster_damage_protector(
        survarium::booster_damage_protector *this,
        const char *damage_type,
        float reduce,
        float absorb)
{
  boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::booster_damage_protector,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::booster_damage_protector *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > v5; // [esp+10h] [ebp-7Ch]
  boost::function4<float,char const *,char const *,float,float> v6; // [esp+4Ch] [ebp-40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+74h] [ebp-18h] BYREF
  float (__thiscall *f)(survarium::booster_damage_protector *, const char *, const char *, const float, const float); // [esp+84h] [ebp-8h]
  int f_4; // [esp+88h] [ebp-4h]

  survarium::damage_protector::damage_protector(this);
  this->__vftable = (survarium::booster_damage_protector_vtbl *)&survarium::booster_damage_protector::`vftable';
  this->m_reduce = reduce;
  this->m_absorb = absorb;
  f = survarium::booster_damage_protector::reduce_damage;
  f_4 = 0;
  v5 = *(boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::booster_damage_protector,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::booster_damage_protector *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::booster_damage_protector::reduce_damage, (vostok::sound::sound_environment_cook *)this, 1_169);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->reduce_damage_functor,
    &v6);
  boost::function4<float,char const *,char const *,float,float>::assign_to<boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::booster_damage_protector,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::booster_damage_protector *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>(
    &v6,
    v5);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v6,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&this->reduce_damage_functor);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(&v6);
  vostok::strings::copy(this->m_hit_type, 0x10u, damage_type);
}
