void __thiscall survarium::game::load_config_query(
        survarium::game *this,
        const char *cfg_name,
        bool create_renderer,
        unsigned int command_types_to_execute)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  _DWORD v5[6]; // [esp+8h] [ebp-38h] BYREF
  _BYTE v6[32]; // [esp+20h] [ebp-20h] BYREF

  LOBYTE(v5[1]) = create_renderer;
  *(_DWORD *)v6 = survarium::game::on_config_loaded;
  *(_DWORD *)&v6[4] = 0;
  *(_DWORD *)&v6[8] = this;
  *(_DWORD *)&v6[12] = v5[1];
  *(_DWORD *)&v6[16] = command_types_to_execute;
  qmemcpy(v5, v6, sizeof(v5));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    *(_DWORD *)v6 = 0;
  }
  else
  {
    qmemcpy(&v6[8], v5, 0x18u);
    *(_DWORD *)v6 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game,vostok::resources::queries_result &,bool,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::game *>,boost::arg<1>,boost::_bi::value<bool>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
                  + 1;
  }
  vostok::resources::query_resource_and_wait(cfg_name, (const vostok::variant<32> *)3, survarium::g_allocator, 0, 0);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, (int *)v6);
}
