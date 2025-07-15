void __thiscall survarium::game_material_manager_cook::translate_query(
        survarium::game_material_manager_cook *this,
        const vostok::variant<32> **parent)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::resources::request v3; // [esp+8h] [ebp-40h] BYREF
  const char *v4; // [esp+10h] [ebp-38h]
  int v5; // [esp+14h] [ebp-34h]
  int v6[2]; // [esp+18h] [ebp-30h] BYREF
  survarium::game_material_manager_cook *v7; // [esp+20h] [ebp-28h]
  int v8; // [esp+24h] [ebp-24h]
  survarium::game_material_manager_cook *v9; // [esp+28h] [ebp-20h]
  int v10; // [esp+2Ch] [ebp-1Ch]
  void (__thiscall *v11)(survarium::game_material_manager_cook *, survarium::pure_game_effect_emitter_base *); // [esp+38h] [ebp-10h]
  int v12; // [esp+3Ch] [ebp-Ch]
  survarium::game_material_manager_cook *v13; // [esp+40h] [ebp-8h]
  int v14; // [esp+44h] [ebp-4h]

  v3.id = binary_config_class_impl;
  v5 = 32;
  v7 = this;
  v6[0] = (int)survarium::game_material_manager_cook::on_configs_loaded;
  v6[1] = 0;
  v11 = survarium::game_material_manager_cook::on_configs_loaded;
  v12 = 0;
  v13 = this;
  v3.path = "resources/game_materials/game.materials";
  v4 = "resources/game_materials/material.pairs";
  v14 = v8;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v6[0] = 0;
  }
  else
  {
    v7 = (survarium::game_material_manager_cook *)v11;
    v8 = v12;
    v9 = v13;
    v10 = v14;
    v6[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_material_manager_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resources(&v3, 2u, survarium::g_allocator, 0, parent, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v2, v6);
}
