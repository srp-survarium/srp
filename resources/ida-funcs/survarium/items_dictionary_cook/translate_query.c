void __thiscall survarium::items_dictionary_cook::translate_query(
        survarium::items_dictionary_cook *this,
        const vostok::variant<32> **parent)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::resources::request v4; // [esp+10h] [ebp-40h] BYREF
  const char *v5; // [esp+18h] [ebp-38h]
  int v6; // [esp+1Ch] [ebp-34h]
  int v7[2]; // [esp+20h] [ebp-30h] BYREF
  survarium::items_dictionary_cook *v8; // [esp+28h] [ebp-28h]
  int v9; // [esp+2Ch] [ebp-24h]
  survarium::items_dictionary_cook *v10; // [esp+30h] [ebp-20h]
  int v11; // [esp+34h] [ebp-1Ch]
  void (__thiscall *v12)(survarium::items_dictionary_cook *, vostok::resources::request *); // [esp+40h] [ebp-10h]
  int v13; // [esp+44h] [ebp-Ch]
  survarium::items_dictionary_cook *v14; // [esp+48h] [ebp-8h]
  int v15; // [esp+4Ch] [ebp-4h]

  v4.id = binary_config_class_impl;
  v6 = 32;
  v7[0] = (int)survarium::items_dictionary_cook::on_configs_loaded;
  v7[1] = 0;
  v8 = this;
  v12 = survarium::items_dictionary_cook::on_configs_loaded;
  v13 = 0;
  v14 = this;
  v4.path = "resources/gameplay/db_static_dictionaries";
  v5 = "resources/gameplay/quests/quests.options";
  v15 = v9;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v7[0] = 0;
  }
  else
  {
    v8 = (survarium::items_dictionary_cook *)v12;
    v9 = v13;
    v10 = v14;
    v11 = v15;
    v7[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::items_dictionary_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::items_dictionary_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resources(&v4, 2u, this->m_allocator, 0, parent, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, v7);
}
