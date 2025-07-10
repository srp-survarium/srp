void __thiscall boost::function1<unsigned int,char const *>::swap(
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *this,
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *other)
{
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> tmp; // [esp+24h] [ebp-20h] BYREF

  if ( other != this )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(&tmp, this);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(this, other);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(other, &tmp);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&tmp);
  }
}
