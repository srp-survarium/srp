void __thiscall vostok::network::http_client::get_impl(vostok::network::http_client *this, char *server, char *path)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::http_client>,boost::_bi::list1<boost::_bi::value<vostok::network::http_client *> > > v5; // [esp-8h] [ebp-30h]
  int v6; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(void)> callback; // [esp+8h] [ebp-20h] BYREF

  v5.l_.a1_.t_ = this;
  v5.f_.f_ = vostok::network::http_client::on_content_downloaded;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function<void __cdecl(void)> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::http_client>,boost::_bi::list1<boost::_bi::value<vostok::network::http_client *> > > *)&callback,
    v5,
    v6);
  vostok::network_core::http_client::get(server, this->m_client, path, &callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&callback);
}
