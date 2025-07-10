boost::function<void __cdecl(boost::system::error_code)> *__thiscall boost::function<void __cdecl (boost::system::error_code)>::operator=(
        boost::function<void __cdecl(boost::system::error_code)> *this,
        const boost::function<void __cdecl(boost::system::error_code)> *f)
{
  boost::function1<void,enum vostok::handshaking_error_types_enum> v4; // [esp+2Ch] [ebp-20h] BYREF

  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    &v4,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)f);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v4,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)this);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v4);
  return this;
}
