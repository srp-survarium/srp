void __userpurge survarium::player_parameters_modifyer_cook::translate_query(
        survarium::player_parameters_modifyer_cook *this@<ecx>,
        float health_regeneration@<xmm0>,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  survarium::player_parameters_modifyer *v6; // eax
  double booster_value; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  stlp_std::less<unsigned int> *v18; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  const vostok::variant<32> **v20; // eax
  vostok::configs::binary_config *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // ecx
  unsigned __int8 v25; // al
  vostok::configs::binary_config_value *v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  vostok::configs::binary_config_value *v28; // ecx
  unsigned __int8 v29; // al
  survarium::game_camera *v30; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  vostok::sound::encoded_sound_interface *v33; // eax
  vostok::configs::binary_config_value *v34; // ecx
  vostok::configs::binary_config_value *v35; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v36; // eax
  vostok::configs::binary_config_value *v37; // eax
  vostok::sound::encoded_sound_interface *v38; // eax
  vostok::configs::binary_config_value *v39; // ecx
  vostok::configs::binary_config_value *v40; // ecx
  vostok::configs::binary_config_value *v41; // ecx
  stlp_std::priv::_Rb_tree_node_base **v42; // eax
  vostok::resources::memory_usage_type *v43; // eax
  vostok::resources::unmanaged_resource *v44; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v45[3]; // [esp-4h] [ebp-4B0h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+8h] [ebp-4A4h]
  float *v47; // [esp+Ch] [ebp-4A0h]
  float *v48; // [esp+10h] [ebp-49Ch]
  stlp_std::priv::_Rb_tree_node_base **v49; // [esp+14h] [ebp-498h]
  bool v50; // [esp+1Bh] [ebp-491h]
  float *v51; // [esp+1Ch] [ebp-490h]
  stlp_std::priv::_Rb_tree_node_base **v52; // [esp+20h] [ebp-48Ch]
  bool v53; // [esp+27h] [ebp-485h]
  float v54; // [esp+28h] [ebp-484h]
  float v55; // [esp+2Ch] [ebp-480h]
  __int64 v56; // [esp+30h] [ebp-47Ch]
  unsigned int condition_or_stack; // [esp+38h] [ebp-474h]
  survarium::player_parameters_modifyer *v58; // [esp+3Ch] [ebp-470h]
  survarium::player_parameters_modifyer_cook *thisa; // [esp+40h] [ebp-46Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v60; // [esp+44h] [ebp-468h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v61; // [esp+48h] [ebp-464h]
  boost::_bi::list1<vostok::network_core::packet_reader &> **v62; // [esp+4Ch] [ebp-460h]
  stlp_std::priv::_Rb_tree_node_base **v63; // [esp+F0h] [ebp-3BCh]
  int v64; // [esp+204h] [ebp-2A8h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v65; // [esp+280h] [ebp-22Ch] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v66; // [esp+284h] [ebp-228h]
  boost::_bi::list1<vostok::network_core::packet_reader &> **v67; // [esp+288h] [ebp-224h]
  stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *p_hit_type_modifyers; // [esp+29Ch] [ebp-210h]
  void *_Where; // [esp+2BCh] [ebp-1F0h]
  vostok::memory::doug_lea_allocator *v70; // [esp+2C0h] [ebp-1ECh]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v71; // [esp+2C8h] [ebp-1E4h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v72; // [esp+2D0h] [ebp-1DCh] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v73; // [esp+2D8h] [ebp-1D4h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v74; // [esp+2DCh] [ebp-1D0h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v75; // [esp+2E4h] [ebp-1C8h] BYREF
  char v76; // [esp+2EBh] [ebp-1C1h]
  survarium::player_parameters_modifyer *v77; // [esp+2ECh] [ebp-1C0h]
  vostok::fixed_string<16> hit_type_name; // [esp+2F0h] [ebp-1BCh] BYREF
  survarium::hit_type_parameters_modifyer hit_type_modifyer_from_cfg; // [esp+30Ch] [ebp-1A0h]
  const vostok::configs::binary_config_value *current_hit_type_cfg; // [esp+318h] [ebp-194h]
  const vostok::configs::binary_config_value *hit_type_it; // [esp+31Ch] [ebp-190h]
  const vostok::configs::binary_config_value *hit_type_it_end; // [esp+320h] [ebp-18Ch]
  vostok::fixed_string<16> body_part_name; // [esp+324h] [ebp-188h] BYREF
  survarium::body_part_parameters_modifyer body_part_modifyer_from_cfg; // [esp+340h] [ebp-16Ch] BYREF
  const vostok::configs::binary_config_value *current_body_part_cfg; // [esp+360h] [ebp-14Ch]
  survarium::body_part_parameters_modifyer *current_body_part_modifyer; // [esp+364h] [ebp-148h]
  const vostok::configs::binary_config_value *body_it_end; // [esp+368h] [ebp-144h]
  const vostok::configs::binary_config_value *body_it; // [esp+36Ch] [ebp-140h]
  unsigned int count; // [esp+370h] [ebp-13Ch]
  survarium::dictionary_item curr_item; // [esp+374h] [ebp-138h] BYREF
  const vostok::configs::binary_config_value *current_item_config; // [esp+494h] [ebp-18h]
  survarium::profile_slot_enum current_slot; // [esp+498h] [ebp-14h]
  unsigned int i; // [esp+49Ch] [ebp-10h]
  survarium::player_parameters_cooker_data *cooker_data; // [esp+4A0h] [ebp-Ch] BYREF
  const survarium::profile_slot *slot; // [esp+4A4h] [ebp-8h]
  survarium::player_parameters_modifyer *cooked_resource; // [esp+4A8h] [ebp-4h]

  thisa = this;
  v64 = 0;
  cooker_data = 0;
  v3 = vostok::resources::query_result_for_cook::user_data(
         (vostok::resources::query_result_for_cook *)this,
         (int)parent);
  vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>(v3, &cooker_data);
  survarium::weapon_user_dead_state::finalize(v4);
  v70 = v5;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x158u);
  v77 = (survarium::player_parameters_modifyer *)operator new(0x158u, _Where);
  if ( v77 )
  {
    survarium::player_parameters_modifyer::player_parameters_modifyer(v77);
    v58 = v6;
  }
  else
  {
    v58 = 0;
  }
  cooked_resource = v58;
  booster_value = survarium::get_booster_value(dispersion_correction_perc_id, cooker_data->profile);
  cooked_resource->dispersion_correction_perc = booster_value;
  v8 = survarium::get_booster_value(aiming_speed_correction_perc_id, cooker_data->profile);
  cooked_resource->aiming_speed_correction_perc = v8;
  v9 = survarium::get_booster_value(health_regen_correction_perc_id, cooker_data->profile);
  cooked_resource->health_regen_correction_perc = v9;
  v10 = survarium::get_booster_value(stamina_regen_correction_perc_id, cooker_data->profile);
  cooked_resource->stamina_regen_correction_perc = v10;
  v11 = survarium::get_booster_value(movement_speed_correction_perc_id, cooker_data->profile);
  cooked_resource->movement_speed_correction_perc = v11;
  v12 = survarium::get_booster_value(additional_max_weight_id, cooker_data->profile);
  cooked_resource->additional_max_weight = v12;
  v13 = survarium::get_booster_value(pain_healt_correction_perc_id, cooker_data->profile);
  cooked_resource->pain_healt_correction_perc = v13;
  v14 = survarium::get_booster_value(artcontainer_time_corr_perc_id, cooker_data->profile);
  cooked_resource->artcontainer_time_corr_perc = v14;
  v15 = survarium::get_booster_value(anomaly_damage_corr_perc_id, cooker_data->profile);
  cooked_resource->anomaly_damage_corr_perc = v15;
  v16 = survarium::get_booster_value(engineer_use_time_corr_perc_id, cooker_data->profile);
  cooked_resource->engineer_use_time_corr_perc = v16;
  v17 = survarium::get_booster_value(engineer_succ_chance_corr_perc_id, cooker_data->profile);
  cooked_resource->engineer_succ_chance_corr_perc = v17;
  for ( i = 0; i < 0x13; ++i )
  {
    current_slot = i;
    slot = &cooker_data->profile->slots[i];
    if ( slot->item.id )
    {
      v18 = survarium::items_dictionary::item_by_id(cooker_data->dictionary, slot->item.dict_id);
      survarium::dictionary_item::dictionary_item(&curr_item, (const survarium::dictionary_item *)v18);
      v20 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v19,
              (int)&curr_item.item_cfg);
      current_item_config = vostok::configs::binary_config::get_root(v21, (int)v20);
      if ( vostok::configs::binary_config_value::value_exists(
             (vostok::configs::binary_config_value *)current_item_config,
             "parameters") )
      {
        if ( curr_item.is_stack )
          condition_or_stack = slot->item.condition_or_stack;
        else
          condition_or_stack = 1;
        count = condition_or_stack;
        v56 = condition_or_stack;
        cooked_resource->total_items_weight = (double)condition_or_stack * curr_item.weight
                                            + cooked_resource->total_items_weight;
      }
      if ( vostok::configs::binary_config_value::value_exists(
             (vostok::configs::binary_config_value *)current_item_config,
             "additional_slots") )
      {
        v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        (vostok::configs::binary_config_value *)current_item_config,
                                                        "additional_slots");
        v23 = vostok::configs::binary_config_value::operator[](v22, "artefact_slots");
        v25 = vostok::configs::binary_config_value::operator unsigned char(v24, (int)v23);
        cooked_resource->additional_artefact_slots += v25;
        v26 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        (vostok::configs::binary_config_value *)current_item_config,
                                                        "additional_slots");
        v27 = vostok::configs::binary_config_value::operator[](v26, "device_slots");
        v29 = vostok::configs::binary_config_value::operator unsigned char(v28, (int)v27);
        v30 = (survarium::game_camera *)cooked_resource;
        cooked_resource->additional_devices_slots += v29;
        v76 = 0;
        survarium::weapon_user_dead_state::finalize(v30);
      }
      if ( vostok::configs::binary_config_value::value_exists(
             (vostok::configs::binary_config_value *)current_item_config,
             "hit_params") )
      {
        v31 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)current_item_config, "hit_params");
        body_it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v31);
        v32 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        (vostok::configs::binary_config_value *)current_item_config,
                                                        "hit_params");
        body_it_end = vostok::configs::binary_config_value::end(v32);
        while ( body_it != body_it_end )
        {
          p_hit_type_modifyers = (stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)&body_part_modifyer_from_cfg.hit_type_modifyers;
          stlp_std::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>((stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)&body_part_modifyer_from_cfg.hit_type_modifyers);
          current_body_part_cfg = body_it;
          v33 = vostok::configs::binary_config_value::key((vostok::configs::binary_config_value *)body_it);
          vostok::fixed_string<16>::fixed_string<16>(&body_part_name, (const char *)v33);
          if ( vostok::configs::binary_config_value::value_exists(
                 (vostok::configs::binary_config_value *)current_body_part_cfg,
                 "health") )
          {
            vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)current_body_part_cfg,
              "health");
            vostok::configs::binary_config_value::operator float(v34);
            v55 = health_regeneration;
          }
          else
          {
            v55 = *(float *)&FLOAT_0_0;
          }
          body_part_modifyer_from_cfg.health = v55;
          if ( vostok::configs::binary_config_value::value_exists(
                 (vostok::configs::binary_config_value *)current_body_part_cfg,
                 "regeneration_speed") )
          {
            vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)current_body_part_cfg,
              "regeneration_speed");
            vostok::configs::binary_config_value::operator float(v35);
            v54 = v55;
          }
          else
          {
            v54 = *(float *)&FLOAT_0_0;
          }
          body_part_modifyer_from_cfg.health_regeneration = v54;
          stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
            (boost::_bi::list1<vostok::network_core::packet_reader &> *)&cooked_resource->body_part_parameters_modifyers,
            &v74);
          v67 = &v65;
          stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
            v74,
            &v65);
          v66 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::_M_find<vostok::fixed_string<16>>(
                                                                              &cooked_resource->body_part_parameters_modifyers._M_t,
                                                                              &body_part_name);
          stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
            v66,
            &v75);
          v53 = v75 != v65;
          if ( v75 == v65 )
          {
            v63 = stlp_std::map<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                    &cooked_resource->body_part_parameters_modifyers,
                    &body_part_name);
            *v63 = (stlp_std::priv::_Rb_tree_node_base *)LODWORD(body_part_modifyer_from_cfg.health);
            health_regeneration = body_part_modifyer_from_cfg.health_regeneration;
            v63[1] = (stlp_std::priv::_Rb_tree_node_base *)LODWORD(body_part_modifyer_from_cfg.health_regeneration);
            survarium::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>>::operator=(
              (survarium::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16> > > *)(v63 + 2),
              &body_part_modifyer_from_cfg.hit_type_modifyers);
          }
          else
          {
            v52 = stlp_std::map<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                    &cooked_resource->body_part_parameters_modifyers,
                    &body_part_name);
            *(float *)v52 = *(float *)v52 + body_part_modifyer_from_cfg.health;
            v51 = (float *)(stlp_std::map<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                              &cooked_resource->body_part_parameters_modifyers,
                              &body_part_name)
                          + 1);
            health_regeneration = *v51 + body_part_modifyer_from_cfg.health_regeneration;
            *v51 = health_regeneration;
          }
          current_body_part_modifyer = (survarium::body_part_parameters_modifyer *)stlp_std::map<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                                                                                     &cooked_resource->body_part_parameters_modifyers,
                                                                                     &body_part_name);
          if ( vostok::configs::binary_config_value::value_exists(
                 (vostok::configs::binary_config_value *)current_body_part_cfg,
                 "hit_types") )
          {
            v36 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)current_body_part_cfg, "hit_types");
            hit_type_it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v36);
            v37 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            (vostok::configs::binary_config_value *)current_body_part_cfg,
                                                            "hit_types");
            hit_type_it_end = vostok::configs::binary_config_value::end(v37);
            while ( hit_type_it != hit_type_it_end )
            {
              current_hit_type_cfg = hit_type_it;
              v38 = vostok::configs::binary_config_value::key((vostok::configs::binary_config_value *)hit_type_it);
              vostok::fixed_string<16>::fixed_string<16>(&hit_type_name, (const char *)v38);
              vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)current_hit_type_cfg,
                "armor");
              vostok::configs::binary_config_value::operator float(v39);
              hit_type_modifyer_from_cfg.armor = health_regeneration;
              vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)current_hit_type_cfg,
                "absorption");
              vostok::configs::binary_config_value::operator float(v40);
              hit_type_modifyer_from_cfg.absorption = health_regeneration;
              vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)current_hit_type_cfg,
                "reduce");
              vostok::configs::binary_config_value::operator float(v41);
              hit_type_modifyer_from_cfg.reduce = health_regeneration;
              stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
                (boost::_bi::list1<vostok::network_core::packet_reader &> *)&cooked_resource->body_part_parameters_modifyers,
                &v72);
              v62 = &v60;
              stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
                v72,
                &v60);
              v61 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::_M_find<vostok::fixed_string<16>>(
                                                                                  &cooked_resource->body_part_parameters_modifyers._M_t,
                                                                                  &body_part_name);
              stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
                v61,
                &v73);
              v50 = v73 != v60;
              if ( v73 == v60 )
              {
                v42 = stlp_std::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                        &current_body_part_modifyer->hit_type_modifyers,
                        &hit_type_name);
                *(survarium::hit_type_parameters_modifyer *)v42 = hit_type_modifyer_from_cfg;
              }
              else
              {
                v49 = stlp_std::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                        &current_body_part_modifyer->hit_type_modifyers,
                        &hit_type_name);
                *(float *)v49 = *(float *)v49 + hit_type_modifyer_from_cfg.armor;
                v48 = (float *)(stlp_std::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                                  &current_body_part_modifyer->hit_type_modifyers,
                                  &hit_type_name)
                              + 2);
                *v48 = *v48 + hit_type_modifyer_from_cfg.absorption;
                v47 = (float *)(stlp_std::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                                  &current_body_part_modifyer->hit_type_modifyers,
                                  &hit_type_name)
                              + 1);
                health_regeneration = *v47 + hit_type_modifyer_from_cfg.reduce;
                *v47 = health_regeneration;
              }
              ++hit_type_it;
            }
          }
          stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::material_pair const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::material_pair const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::material_pair const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *>>>::clear((stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *> > > *)&body_part_modifyer_from_cfg.hit_type_modifyers);
          ++body_it;
        }
      }
      survarium::dictionary_item::~dictionary_item(&curr_item);
    }
  }
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v71,
    (vostok::network_core::packet_reader *)0x158,
    (vostok::network_core::packet_reader *)v45[1].m_object);
  memory_usage = v43;
  v45[0].m_object = v44;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v45,
    (vostok::configs::binary_config *)cooked_resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(parent, v45[0], memory_usage);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
}
