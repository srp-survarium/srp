void __thiscall survarium::damage_protector::~damage_protector(survarium::damage_protector *this)
{
  this->__vftable = (survarium::damage_protector_vtbl *)&survarium::damage_protector::`vftable';
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->protect_affect_functor);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(&this->reduce_damage_functor);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->reduce_damage_functor);
}
