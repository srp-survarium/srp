void __thiscall vostok::network_core::http_client::set_on_error(
        vostok::network_core::http_client *this,
        const boost::function<void __cdecl(boost::system::error_code)> *callback)
{
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *other; // [esp+4h] [ebp-4Ch]
  boost::function1<void,enum vostok::handshaking_error_types_enum> v3; // [esp+30h] [ebp-20h] BYREF

  other = (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&this->m_on_error;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    &v3,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)callback);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v3,
    other);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v3);
}
