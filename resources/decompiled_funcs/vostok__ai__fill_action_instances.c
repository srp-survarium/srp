void __cdecl vostok::ai::fill_action_instances(
        vostok::configs::binary_config_value *action_options,
        survarium::weapon_core_animation_end_aware_state *world,
        const vostok::ai::planning::pddl_domain *domain,
        vostok::ai::planning::pddl_problem *problem)
{
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // eax
  survarium::game_camera *v9; // ecx
  vostok::ai::planning::action_instance *v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // eax
  survarium::game_camera *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // eax
  survarium::game_camera *v15; // ecx
  vostok::ai::planning::action_parameter *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // eax
  vostok::ai::planning::action_parameter *v18; // eax
  survarium::game_camera *v19; // ecx
  vostok::memory::doug_lea_allocator *v20; // eax
  survarium::game_camera *v21; // ecx
  void *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // eax
  survarium::game_camera *v24; // eax
  vostok::memory::doug_lea_allocator *v25; // eax
  vostok::ai::planning::action_parameter *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // eax
  void *v28; // eax
  survarium::game_camera *v29; // ecx
  vostok::memory::doug_lea_allocator *v30; // eax
  survarium::game_camera *v31; // eax
  vostok::memory::doug_lea_allocator *v32; // eax
  vostok::ai::planning::action_parameter *v33; // eax
  survarium::game_camera *v34; // ecx
  vostok::memory::doug_lea_allocator *v35; // eax
  vostok::ai::planning::action_parameter *v36; // eax
  survarium::game_camera *v37; // ecx
  vostok::memory::doug_lea_allocator *v38; // eax
  survarium::game_camera *v39; // eax
  vostok::memory::doug_lea_allocator *v40; // eax
  survarium::game_camera *v41; // ecx
  vostok::ai::planning::action_parameter *v42; // eax
  vostok::memory::doug_lea_allocator *v43; // eax
  vostok::ai::planning::action_parameter *v44; // eax
  vostok::ai::planning::action_parameter **v45; // ecx
  survarium::game_camera *v46; // ecx
  survarium::game_camera *v47; // ecx
  vostok::memory::doug_lea_allocator *v48; // eax
  survarium::game_camera *v49; // ecx
  survarium::game_camera *v50; // eax
  vostok::memory::doug_lea_allocator *v51; // eax
  vostok::ai::planning::action_parameter *v52; // eax
  vostok::ai::planning::action_parameter **v53; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v54; // ecx
  survarium::game_camera *v55; // ecx
  vostok::memory::doug_lea_allocator *v56; // eax
  survarium::game_camera *v57; // ecx
  void *v58; // eax
  vostok::memory::doug_lea_allocator *v59; // eax
  vostok::ai::planning::action_parameter *v60; // eax
  survarium::game_camera *v61; // ecx
  vostok::ai::planning::action_parameter **v62; // ecx
  survarium::game_camera *v63; // ecx
  vostok::memory::doug_lea_allocator *v64; // eax
  survarium::game_camera *v65; // eax
  vostok::memory::doug_lea_allocator *v66; // eax
  survarium::game_camera *v67; // ecx
  vostok::ai::planning::action_parameter *v68; // eax
  vostok::memory::doug_lea_allocator *v69; // eax
  vostok::ai::planning::action_parameter *v70; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v71; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v72; // ecx
  survarium::game_camera *v73; // ecx
  vostok::memory::doug_lea_allocator *v74; // eax
  survarium::game_camera *v75; // ecx
  void *v76; // eax
  vostok::memory::doug_lea_allocator *v77; // eax
  vostok::ai::planning::action_parameter *v78; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v79; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *v80; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v81; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v82; // ecx
  vostok::ai::planning::action_parameter *v83; // [esp+4h] [ebp-AFCh]
  void *v84; // [esp+8h] [ebp-AF8h]
  vostok::ai::planning::action_parameter *v85; // [esp+Ch] [ebp-AF4h]
  vostok::ai::planning::action_parameter *v86; // [esp+10h] [ebp-AF0h]
  survarium::game_camera *v87; // [esp+14h] [ebp-AECh]
  vostok::ai::planning::action_parameter *v88; // [esp+18h] [ebp-AE8h]
  void *v89; // [esp+1Ch] [ebp-AE4h]
  vostok::ai::planning::action_parameter *v90; // [esp+20h] [ebp-AE0h]
  survarium::game_camera *v91; // [esp+24h] [ebp-ADCh]
  vostok::ai::planning::action_parameter *v92; // [esp+28h] [ebp-AD8h]
  vostok::ai::planning::action_parameter *v93; // [esp+2Ch] [ebp-AD4h]
  survarium::game_camera *v94; // [esp+30h] [ebp-AD0h]
  vostok::ai::planning::action_parameter *v95; // [esp+34h] [ebp-ACCh]
  vostok::ai::planning::action_parameter *v96; // [esp+38h] [ebp-AC8h]
  survarium::game_camera *v97; // [esp+3Ch] [ebp-AC4h]
  void *v98; // [esp+40h] [ebp-AC0h]
  vostok::ai::planning::action_parameter *v99; // [esp+44h] [ebp-ABCh]
  survarium::game_camera *v100; // [esp+48h] [ebp-AB8h]
  void *v101; // [esp+4Ch] [ebp-AB4h]
  vostok::ai::planning::action_parameter *v102; // [esp+50h] [ebp-AB0h]
  vostok::ai::planning::action_parameter *v103; // [esp+54h] [ebp-AACh]
  survarium::game_camera *v104; // [esp+58h] [ebp-AA8h]
  vostok::ai::planning::action_instance *v105; // [esp+5Ch] [ebp-AA4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v106; // [esp+A0h] [ebp-A60h]
  void *v107; // [esp+CCh] [ebp-A34h] BYREF
  void *v108; // [esp+DCh] [ebp-A24h] BYREF
  void *v109; // [esp+ECh] [ebp-A14h]
  vostok::memory::doug_lea_allocator *v110; // [esp+F0h] [ebp-A10h]
  void *v111; // [esp+F4h] [ebp-A0Ch]
  vostok::memory::doug_lea_allocator *v112; // [esp+F8h] [ebp-A08h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v113; // [esp+114h] [ebp-9ECh]
  void *v114; // [esp+124h] [ebp-9DCh] BYREF
  void *v115; // [esp+134h] [ebp-9CCh] BYREF
  void *v116; // [esp+144h] [ebp-9BCh] BYREF
  void *v117; // [esp+154h] [ebp-9ACh]
  vostok::memory::doug_lea_allocator *v118; // [esp+158h] [ebp-9A8h]
  void *v119; // [esp+15Ch] [ebp-9A4h]
  vostok::memory::doug_lea_allocator *v120; // [esp+160h] [ebp-9A0h]
  void *v121; // [esp+164h] [ebp-99Ch]
  vostok::memory::doug_lea_allocator *v122; // [esp+168h] [ebp-998h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v123; // [esp+16Ch] [ebp-994h]
  void *v124; // [esp+17Ch] [ebp-984h] BYREF
  char v125; // [esp+183h] [ebp-97Dh]
  void *v126; // [esp+184h] [ebp-97Ch] BYREF
  char v127; // [esp+18Bh] [ebp-975h]
  void *v128; // [esp+18Ch] [ebp-974h]
  vostok::memory::doug_lea_allocator *v129; // [esp+190h] [ebp-970h]
  void *v130; // [esp+194h] [ebp-96Ch]
  vostok::memory::doug_lea_allocator *v131; // [esp+198h] [ebp-968h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v132; // [esp+19Ch] [ebp-964h]
  void *v133; // [esp+1ACh] [ebp-954h] BYREF
  char v134; // [esp+1B3h] [ebp-94Dh]
  void *v135; // [esp+1B4h] [ebp-94Ch] BYREF
  char v136; // [esp+1BBh] [ebp-945h]
  void *v137; // [esp+1BCh] [ebp-944h]
  vostok::memory::doug_lea_allocator *v138; // [esp+1C0h] [ebp-940h]
  void *v139; // [esp+1C4h] [ebp-93Ch]
  vostok::memory::doug_lea_allocator *v140; // [esp+1C8h] [ebp-938h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v141; // [esp+1CCh] [ebp-934h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v142; // [esp+1DCh] [ebp-924h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v143; // [esp+1ECh] [ebp-914h]
  void *v144; // [esp+1FCh] [ebp-904h] BYREF
  char v145; // [esp+203h] [ebp-8FDh]
  void *v146; // [esp+204h] [ebp-8FCh] BYREF
  char v147; // [esp+20Bh] [ebp-8F5h]
  void *v148; // [esp+20Ch] [ebp-8F4h] BYREF
  char v149; // [esp+213h] [ebp-8EDh]
  void *v150; // [esp+214h] [ebp-8ECh]
  vostok::memory::doug_lea_allocator *v151; // [esp+218h] [ebp-8E8h]
  void *v152; // [esp+21Ch] [ebp-8E4h]
  vostok::memory::doug_lea_allocator *v153; // [esp+220h] [ebp-8E0h]
  void *v154; // [esp+224h] [ebp-8DCh]
  vostok::memory::doug_lea_allocator *v155; // [esp+228h] [ebp-8D8h]
  void *v156; // [esp+22Ch] [ebp-8D4h] BYREF
  void *v157; // [esp+230h] [ebp-8D0h]
  vostok::memory::doug_lea_allocator *v158; // [esp+234h] [ebp-8CCh]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v159; // [esp+238h] [ebp-8C8h]
  void *v160; // [esp+248h] [ebp-8B8h] BYREF
  void *v161; // [esp+24Ch] [ebp-8B4h] BYREF
  void *v162; // [esp+250h] [ebp-8B0h]
  vostok::memory::doug_lea_allocator *v163; // [esp+254h] [ebp-8ACh]
  void *v164; // [esp+258h] [ebp-8A8h]
  vostok::memory::doug_lea_allocator *v165; // [esp+25Ch] [ebp-8A4h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v166; // [esp+260h] [ebp-8A0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v167; // [esp+270h] [ebp-890h]
  void *v168; // [esp+280h] [ebp-880h] BYREF
  void *v169; // [esp+284h] [ebp-87Ch]
  vostok::memory::doug_lea_allocator *v170; // [esp+288h] [ebp-878h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v171; // [esp+28Ch] [ebp-874h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v172; // [esp+29Ch] [ebp-864h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v173; // [esp+2ACh] [ebp-854h]
  void *v174; // [esp+2BCh] [ebp-844h] BYREF
  void *v175; // [esp+2C0h] [ebp-840h] BYREF
  void *v176; // [esp+2C4h] [ebp-83Ch] BYREF
  void *v177; // [esp+2C8h] [ebp-838h]
  vostok::memory::doug_lea_allocator *v178; // [esp+2CCh] [ebp-834h]
  void *v179; // [esp+2D0h] [ebp-830h]
  vostok::memory::doug_lea_allocator *v180; // [esp+2D4h] [ebp-82Ch]
  void *v181; // [esp+2D8h] [ebp-828h]
  vostok::memory::doug_lea_allocator *v182; // [esp+2DCh] [ebp-824h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v183; // [esp+2E0h] [ebp-820h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v184; // [esp+2F0h] [ebp-810h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > v185; // [esp+300h] [ebp-800h]
  void *v186; // [esp+310h] [ebp-7F0h] BYREF
  void *v187; // [esp+314h] [ebp-7ECh] BYREF
  void *value; // [esp+318h] [ebp-7E8h] BYREF
  void *v189; // [esp+31Ch] [ebp-7E4h]
  vostok::memory::doug_lea_allocator *v190; // [esp+320h] [ebp-7E0h]
  void *v191; // [esp+324h] [ebp-7DCh]
  vostok::memory::doug_lea_allocator *v192; // [esp+328h] [ebp-7D8h]
  void *v193; // [esp+32Ch] [ebp-7D4h]
  vostok::memory::doug_lea_allocator *v194; // [esp+330h] [ebp-7D0h]
  void *_Where; // [esp+334h] [ebp-7CCh]
  vostok::memory::doug_lea_allocator *v196; // [esp+338h] [ebp-7C8h]
  int v197; // [esp+34Ch] [ebp-7B4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+350h] [ebp-7B0h] BYREF
  boost::function1<void,enum vostok::handshaking_error_types_enum> v199; // [esp+370h] [ebp-790h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v200; // [esp+390h] [ebp-770h] BYREF
  void (__thiscall *v201)(vostok::ai::brain_unit *, const vostok::ai::movement_target *const); // [esp+3A0h] [ebp-760h]
  int v202; // [esp+3A4h] [ebp-75Ch]
  boost::function1<void,enum vostok::handshaking_error_types_enum> v203; // [esp+3A8h] [ebp-758h] BYREF
  vostok::ai::planning::action_parameter *v204; // [esp+3C8h] [ebp-738h]
  vostok::ai::planning::action_parameter *v205; // [esp+3CCh] [ebp-734h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> v206; // [esp+3D0h] [ebp-730h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v207; // [esp+3F0h] [ebp-710h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit,vostok::ai::animation_item const *,vostok::ai::sound_item const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v208; // [esp+400h] [ebp-700h] BYREF
  vostok::ai::planning::action_parameter *v209; // [esp+42Ch] [ebp-6D4h]
  vostok::ai::planning::action_parameter *v210; // [esp+430h] [ebp-6D0h]
  vostok::ai::planning::action_parameter *v211; // [esp+434h] [ebp-6CCh]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v212; // [esp+438h] [ebp-6C8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v213; // [esp+458h] [ebp-6A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit,vostok::ai::sound_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > > v214; // [esp+468h] [ebp-698h] BYREF
  vostok::ai::planning::action_parameter *v215; // [esp+490h] [ebp-670h]
  vostok::ai::planning::action_parameter *v216; // [esp+494h] [ebp-66Ch]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v217; // [esp+498h] [ebp-668h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v218; // [esp+4B8h] [ebp-648h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::ai::brain_unit,vostok::ai::animation_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > > v219; // [esp+4C8h] [ebp-638h] BYREF
  vostok::ai::planning::action_parameter *v220; // [esp+4F0h] [ebp-610h]
  vostok::ai::planning::action_parameter *v221; // [esp+4F4h] [ebp-60Ch]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v222; // [esp+4F8h] [ebp-608h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v223; // [esp+518h] [ebp-5E8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v224; // [esp+528h] [ebp-5D8h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v225; // [esp+550h] [ebp-5B0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v226; // [esp+570h] [ebp-590h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v227; // [esp+580h] [ebp-580h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v228; // [esp+5A8h] [ebp-558h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v229; // [esp+5C8h] [ebp-538h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v230; // [esp+5D8h] [ebp-528h] BYREF
  vostok::ai::planning::action_parameter *v231; // [esp+600h] [ebp-500h]
  vostok::ai::planning::action_parameter *v232; // [esp+604h] [ebp-4FCh]
  vostok::ai::planning::action_parameter *v233; // [esp+608h] [ebp-4F8h]
  vostok::ai::planning::action_parameter *v234; // [esp+60Ch] [ebp-4F4h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v235; // [esp+610h] [ebp-4F0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v236; // [esp+630h] [ebp-4D0h] BYREF
  void (__thiscall *v237)(vostok::ai::brain_unit *, const vostok::ai::weapon *const); // [esp+640h] [ebp-4C0h]
  int v238; // [esp+644h] [ebp-4BCh]
  boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::weapon const *> v239; // [esp+648h] [ebp-4B8h] BYREF
  vostok::ai::planning::action_parameter *v240; // [esp+668h] [ebp-498h]
  vostok::ai::planning::action_parameter *v241; // [esp+66Ch] [ebp-494h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v242; // [esp+670h] [ebp-490h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v243; // [esp+690h] [ebp-470h] BYREF
  void (__thiscall *v244)(vostok::ai::brain_unit *); // [esp+6A0h] [ebp-460h]
  int v245; // [esp+6A4h] [ebp-45Ch]
  boost::function1<void,vostok::ai::brain_unit const *> v246; // [esp+6A8h] [ebp-458h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v247; // [esp+6C8h] [ebp-438h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v248; // [esp+6E8h] [ebp-418h] BYREF
  void (__thiscall *v249)(vostok::ai::brain_unit *); // [esp+6F8h] [ebp-408h]
  int v250; // [esp+6FCh] [ebp-404h]
  boost::function1<void,vostok::ai::brain_unit const *> v251; // [esp+700h] [ebp-400h] BYREF
  vostok::ai::planning::action_parameter *v252; // [esp+724h] [ebp-3DCh]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v253; // [esp+728h] [ebp-3D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v254; // [esp+748h] [ebp-3B8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v255; // [esp+758h] [ebp-3A8h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v256; // [esp+780h] [ebp-380h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v257; // [esp+7A0h] [ebp-360h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v258; // [esp+7B0h] [ebp-350h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v259; // [esp+7D8h] [ebp-328h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v260; // [esp+7F8h] [ebp-308h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v261; // [esp+808h] [ebp-2F8h] BYREF
  vostok::ai::planning::action_parameter *v262; // [esp+834h] [ebp-2CCh]
  vostok::ai::planning::action_parameter *v263; // [esp+838h] [ebp-2C8h]
  vostok::ai::planning::action_parameter *v264; // [esp+83Ch] [ebp-2C4h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v265; // [esp+840h] [ebp-2C0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v266; // [esp+860h] [ebp-2A0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v267; // [esp+870h] [ebp-290h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v268; // [esp+898h] [ebp-268h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v269; // [esp+8B8h] [ebp-248h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v270; // [esp+8C8h] [ebp-238h] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v271; // [esp+8F0h] [ebp-210h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > > v272; // [esp+910h] [ebp-1F0h] BYREF
  void (__thiscall *f)(vostok::ai::brain_unit *, const vostok::ai::npc *const, const vostok::ai::weapon *const); // [esp+920h] [ebp-1E0h]
  int f_4; // [esp+924h] [ebp-1DCh]
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> v275; // [esp+928h] [ebp-1D8h] BYREF
  vostok::ai::planning::action_parameter *v276; // [esp+948h] [ebp-1B8h]
  vostok::ai::planning::action_parameter *v277; // [esp+94Ch] [ebp-1B4h]
  vostok::ai::planning::action_parameter *v278; // [esp+950h] [ebp-1B0h]
  vostok::ai::planning::action_instance *v279; // [esp+954h] [ebp-1ACh]
  char v280; // [esp+95Bh] [ebp-1A5h]
  void *v281; // [esp+95Ch] [ebp-1A4h]
  boost::function<void __cdecl(vostok::ai::brain_unit const *,vostok::ai::weapon const *)> v282; // [esp+960h] [ebp-1A0h] BYREF
  vostok::ai::planning::action_parameter *v283; // [esp+984h] [ebp-17Ch]
  vostok::configs::binary_config_value *v284; // [esp+988h] [ebp-178h]
  vostok::ai::planning::action_parameter *v285; // [esp+98Ch] [ebp-174h]
  vostok::configs::binary_config_value *v286; // [esp+990h] [ebp-170h]
  survarium::game_camera *v287; // [esp+994h] [ebp-16Ch]
  boost::function<void __cdecl(vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *)> v288; // [esp+998h] [ebp-168h] BYREF
  vostok::ai::planning::action_parameter *v289; // [esp+9BCh] [ebp-144h]
  vostok::configs::binary_config_value *v290; // [esp+9C0h] [ebp-140h]
  void *v291; // [esp+9C4h] [ebp-13Ch]
  boost::function<void __cdecl(vostok::ai::brain_unit const *,vostok::ai::weapon const *)> finalizer; // [esp+9C8h] [ebp-138h] BYREF
  vostok::ai::planning::action_parameter *v293; // [esp+9ECh] [ebp-114h]
  vostok::configs::binary_config_value *v294; // [esp+9F0h] [ebp-110h]
  survarium::game_camera *v295; // [esp+9F4h] [ebp-10Ch]
  boost::function<void __cdecl(vostok::ai::brain_unit const *,vostok::ai::weapon const *)> initializer; // [esp+9F8h] [ebp-108h] BYREF
  vostok::ai::planning::action_parameter *v297; // [esp+A1Ch] [ebp-E4h]
  vostok::configs::binary_config_value *v298; // [esp+A20h] [ebp-E0h]
  vostok::ai::planning::action_parameter *v299; // [esp+A24h] [ebp-DCh]
  vostok::configs::binary_config_value *v300; // [esp+A28h] [ebp-D8h]
  survarium::game_camera *v301; // [esp+A2Ch] [ebp-D4h]
  vostok::ai::planning::action_parameter *v302; // [esp+A30h] [ebp-D0h]
  vostok::configs::binary_config_value *v303; // [esp+A34h] [ebp-CCh]
  boost::function<bool __cdecl(void)> v304; // [esp+A38h] [ebp-C8h] BYREF
  vostok::ai::planning::action_parameter *v305; // [esp+A5Ch] [ebp-A4h]
  vostok::configs::binary_config_value *v306; // [esp+A60h] [ebp-A0h]
  survarium::game_camera *v307; // [esp+A64h] [ebp-9Ch]
  boost::function<bool __cdecl(void)> v308; // [esp+A68h] [ebp-98h] BYREF
  vostok::ai::planning::action_parameter *v309; // [esp+A8Ch] [ebp-74h]
  vostok::configs::binary_config_value *v310; // [esp+A90h] [ebp-70h]
  void *v311; // [esp+A94h] [ebp-6Ch]
  boost::function<void __cdecl(vostok::ai::brain_unit const *)> empty_function; // [esp+A98h] [ebp-68h] BYREF
  vostok::ai::planning::action_parameter *v313; // [esp+AB8h] [ebp-48h]
  vostok::configs::binary_config_value *v314; // [esp+ABCh] [ebp-44h]
  void *v315; // [esp+AC0h] [ebp-40h]
  vostok::ai::planning::action_parameter *parameter; // [esp+AC4h] [ebp-3Ch]
  vostok::configs::binary_config_value *options; // [esp+AC8h] [ebp-38h]
  vostok::ai::planning::action_parameter *parameter1; // [esp+ACCh] [ebp-34h]
  const vostok::configs::binary_config_value *param1; // [esp+AD0h] [ebp-30h]
  vostok::ai::planning::action_parameter *parameter_owner; // [esp+AD4h] [ebp-2Ch]
  vostok::ai::planning::action_parameter *parameter0; // [esp+AD8h] [ebp-28h]
  const vostok::configs::binary_config_value *param0; // [esp+ADCh] [ebp-24h]
  vostok::ai::planning::action_instance *result; // [esp+AE0h] [ebp-20h]
  unsigned int action_type; // [esp+AE4h] [ebp-1Ch]
  const vostok::ai::planning::generalized_action *prototype; // [esp+AE8h] [ebp-18h]
  vostok::ai::planning::action_types_enum type; // [esp+AECh] [ebp-14h]
  const vostok::configs::binary_config_value *instance_value; // [esp+AF0h] [ebp-10h]
  const vostok::configs::binary_config_value *actions_value; // [esp+AF4h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+AF8h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+AFCh] [ebp-4h]

  v197 = 0;
  actions_value = vostok::configs::binary_config_value::operator[](action_options, "actions");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)actions_value);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)actions_value);
  while ( it != it_end )
  {
    instance_value = it;
    v4 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it, "id");
    action_type = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                  v5,
                                  (int)v4);
    type = action_type;
    prototype = vostok::ai::planning::pddl_domain::get_action_by_type(domain, action_type);
    v280 = 0;
    survarium::weapon_user_dead_state::finalize(v6);
    survarium::weapon_user_dead_state::finalize(v7);
    v196 = v8;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v8, 0xB8u);
    v279 = (vostok::ai::planning::action_instance *)operator new(0xB8u, _Where);
    if ( v279 )
    {
      vostok::ai::planning::action_instance::action_instance(v279, prototype);
      v105 = v10;
    }
    else
    {
      v105 = 0;
    }
    result = v105;
    if ( action_type )
    {
      switch ( action_type )
      {
        case 2u:
          options = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              (vostok::configs::binary_config_value *)instance_value,
                                                              "parameter0");
          v314 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                           (vostok::configs::binary_config_value *)instance_value,
                                                           "parameter1");
          survarium::weapon_user_dead_state::finalize(v19);
          v182 = v20;
          v181 = vostok::memory::doug_lea_allocator::malloc_impl(v20, 0x34u);
          v264 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v181);
          if ( v264 )
          {
            vostok::ai::planning::action_parameter::action_parameter(v264, 0);
            v101 = v22;
          }
          else
          {
            v101 = 0;
          }
          v315 = v101;
          survarium::weapon_user_dead_state::finalize(v21);
          v180 = v23;
          v179 = vostok::memory::doug_lea_allocator::malloc_impl(v23, 0x34u);
          v263 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v179);
          if ( v263 )
          {
            vostok::ai::planning::action_parameter::action_parameter(v263, 1u);
            v100 = v24;
          }
          else
          {
            v100 = 0;
          }
          parameter = (vostok::ai::planning::action_parameter *)v100;
          survarium::weapon_user_dead_state::finalize(v100);
          v178 = v25;
          v177 = vostok::memory::doug_lea_allocator::malloc_impl(v25, 0x34u);
          v262 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v177);
          if ( v262 )
          {
            vostok::ai::planning::action_parameter::action_parameter(v262, 2u);
            v99 = v26;
          }
          else
          {
            v99 = 0;
          }
          v313 = v99;
          vostok::ai::behaviour::fill_action_parameter(options, parameter);
          vostok::ai::behaviour::fill_action_parameter(v314, v313);
          v176 = v315;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
            (vostok::buffer_vector<void const *> *)result,
            (const void **)&v176);
          v175 = parameter;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
            (vostok::buffer_vector<void const *> *)result,
            (const void **)&v175);
          v174 = v313;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
            (vostok::buffer_vector<void const *> *)result,
            (const void **)&v174);
          LODWORD(v261.f_.f_) = vostok::ai::brain_unit::stop_attack;
          HIDWORD(v261.f_.f_) = 0;
          v173 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v260,
                    (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::stop_attack,
                    *(_BYTE *)&1_255);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v261.l_,
            (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v173,
            0);
          LODWORD(v258.f_.f_) = vostok::ai::brain_unit::attack_melee;
          HIDWORD(v258.f_.f_) = 0;
          v172 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v257,
                    (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::attack_melee,
                    *(_BYTE *)&1_255);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v258.l_,
            (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v172,
            0);
          LODWORD(v255.f_.f_) = vostok::ai::brain_unit::prepare_to_attack;
          HIDWORD(v255.f_.f_) = 0;
          v171 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v254,
                    (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::prepare_to_attack,
                    *(_BYTE *)&1_255);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v255.l_,
            (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v171,
            0);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            &v259,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v261.l_);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            &v256,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v258.l_);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            &v253,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v255.l_);
          vostok::ai::planning::pddl_problem::add_action_instance3<vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
            problem,
            result,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v253,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v256,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v259);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v253);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v256);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v259);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v255.l_);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v258.l_);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v261.l_);
          break;
        case 3u:
          survarium::weapon_user_dead_state::finalize(v9);
          v170 = v27;
          v169 = vostok::memory::doug_lea_allocator::malloc_impl(v27, 0x34u);
          v252 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v169);
          if ( v252 )
          {
            vostok::ai::planning::action_parameter::action_parameter(v252, 0);
            v98 = v28;
          }
          else
          {
            v98 = 0;
          }
          v311 = v98;
          v168 = v98;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
            (vostok::buffer_vector<void const *> *)result,
            (const void **)&v168);
          boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>((boost::function<bool __cdecl(void)> *)&empty_function);
          v249 = vostok::ai::brain_unit::stop_patrolling;
          v250 = 0;
          v167 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v248,
                    (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::stop_patrolling,
                    *(_BYTE *)&1_255);
          boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>(
            &v251,
            (boost::_bi::bind_t<void,boost::_mfi::cmf0<void,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > >)v167,
            0);
          v244 = vostok::ai::brain_unit::survey_area;
          v245 = 0;
          v166 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v243,
                    (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::survey_area,
                    *(_BYTE *)&1_255);
          boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>(
            &v246,
            (boost::_bi::bind_t<void,boost::_mfi::cmf0<void,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > >)v166,
            0);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            &v247,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v251);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            &v242,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v246);
          vostok::ai::planning::pddl_problem::add_action_instance1<vostok::ai::game_object const *,vostok::ai::game_object const *>(
            problem,
            result,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&empty_function,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v242,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v247);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v242);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v247);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v246);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v251);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&empty_function);
          break;
        case 7u:
          v310 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                           (vostok::configs::binary_config_value *)instance_value,
                                                           "parameter0");
          survarium::weapon_user_dead_state::finalize(v29);
          v165 = v30;
          v164 = vostok::memory::doug_lea_allocator::malloc_impl(v30, 0x34u);
          v241 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v164);
          if ( v241 )
          {
            vostok::ai::planning::action_parameter::action_parameter(v241, 0);
            v97 = v31;
          }
          else
          {
            v97 = 0;
          }
          v307 = v97;
          survarium::weapon_user_dead_state::finalize(v97);
          v163 = v32;
          v162 = vostok::memory::doug_lea_allocator::malloc_impl(v32, 0x34u);
          v240 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v162);
          if ( v240 )
          {
            vostok::ai::planning::action_parameter::action_parameter(v240, 2u);
            v96 = v33;
          }
          else
          {
            v96 = 0;
          }
          v309 = v96;
          vostok::ai::behaviour::fill_action_parameter(v310, v96);
          v161 = v307;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
            (vostok::buffer_vector<void const *> *)result,
            (const void **)&v161);
          v160 = v309;
          vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
            (vostok::buffer_vector<void const *> *)result,
            (const void **)&v160);
          boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>(&v308);
          v237 = vostok::ai::brain_unit::reload;
          v238 = 0;
          v159 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v236,
                    (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::reload,
                    *(_BYTE *)&1_255);
          boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::weapon const *>::function2<void,vostok::ai::brain_unit const *,vostok::ai::weapon const *>(
            &v239,
            (boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::ai::brain_unit,vostok::ai::weapon const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v159,
            0);
          boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
            &v235,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v239);
          vostok::ai::planning::pddl_problem::add_action_instance2<vostok::ai::brain_unit const *,vostok::ai::weapon const *,vostok::ai::brain_unit const *,vostok::ai::weapon const *>(
            problem,
            result,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v308,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v235,
            (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v308);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v235);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v239);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v308);
          break;
        default:
          if ( action_type != 5 && action_type != 6 )
          {
            switch ( action_type )
            {
              case 4u:
                v306 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter0");
                survarium::weapon_user_dead_state::finalize(v34);
                v158 = v35;
                v157 = vostok::memory::doug_lea_allocator::malloc_impl(v35, 0x34u);
                v234 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v157);
                if ( v234 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v234, 4u);
                  v95 = v36;
                }
                else
                {
                  v95 = 0;
                }
                v305 = v95;
                vostok::ai::behaviour::fill_action_parameter(v306, v95);
                v156 = v305;
                vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
                  (vostok::buffer_vector<void const *> *)result,
                  (const void **)&v156);
                boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>(&v304);
                vostok::ai::planning::pddl_problem::add_action_instance1<vostok::ai::game_object const *,vostok::ai::game_object const *>(
                  problem,
                  result,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v304,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v304,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v304);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v304);
                break;
              case 1u:
                v303 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter0");
                v300 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter1");
                survarium::weapon_user_dead_state::finalize(v37);
                v155 = v38;
                v154 = vostok::memory::doug_lea_allocator::malloc_impl(v38, 0x34u);
                v233 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v154);
                if ( v233 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v233, 0);
                  v94 = v39;
                }
                else
                {
                  v94 = 0;
                }
                v301 = v94;
                survarium::weapon_user_dead_state::finalize(v94);
                v153 = v40;
                v152 = vostok::memory::doug_lea_allocator::malloc_impl(v40, 0x34u);
                v232 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v152);
                if ( v232 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v232, 1u);
                  v93 = v42;
                }
                else
                {
                  v93 = 0;
                }
                v302 = v93;
                survarium::weapon_user_dead_state::finalize(v41);
                v151 = v43;
                v150 = vostok::memory::doug_lea_allocator::malloc_impl(v43, 0x34u);
                v231 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v150);
                if ( v231 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v231, 2u);
                  v92 = v44;
                }
                else
                {
                  v92 = 0;
                }
                v299 = v92;
                vostok::ai::behaviour::fill_action_parameter(v303, v302);
                vostok::ai::behaviour::fill_action_parameter(v300, v299);
                v148 = v301;
                v149 = 0;
                survarium::weapon_user_dead_state::finalize(v301);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v148);
                v45 = result->m_parameters.m_end + 1;
                result->m_parameters.m_end = v45;
                v146 = v302;
                v147 = 0;
                survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v45);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v146);
                v46 = (survarium::game_camera *)result;
                ++result->m_parameters.m_end;
                v144 = v299;
                v145 = 0;
                survarium::weapon_user_dead_state::finalize(v46);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v144);
                ++result->m_parameters.m_end;
                LODWORD(v230.f_.f_) = vostok::ai::brain_unit::stop_attack;
                HIDWORD(v230.f_.f_) = 0;
                v143 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                          (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v229,
                          (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::stop_attack,
                          *(_BYTE *)&1_255);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v143.l_.boost::_bi::storage1<boost::arg<1> >,
                  &v230.l_);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
                  (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v230.l_,
                  (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v143);
                LODWORD(v227.f_.f_) = vostok::ai::brain_unit::attack_from_cover;
                HIDWORD(v227.f_.f_) = 0;
                v142 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                          (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v226,
                          (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::attack_from_cover,
                          *(_BYTE *)&1_255);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v142.l_.boost::_bi::storage1<boost::arg<1> >,
                  &v227.l_);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
                  (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v227.l_,
                  (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v142);
                LODWORD(v224.f_.f_) = vostok::ai::brain_unit::prepare_to_attack;
                HIDWORD(v224.f_.f_) = 0;
                v141 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                          (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v223,
                          (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::prepare_to_attack,
                          *(_BYTE *)&1_255);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v141.l_.boost::_bi::storage1<boost::arg<1> >,
                  &v224.l_);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
                  (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v224.l_,
                  (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v141);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
                  &v228,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v230.l_);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
                  &v225,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v227.l_);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
                  &v222,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v224.l_);
                vostok::ai::planning::pddl_problem::add_action_instance3<vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
                  problem,
                  result,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v222,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v225,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v228);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v222);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v225);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v228);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v224.l_);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v227.l_);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v230.l_);
                break;
              case 8u:
                v298 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter0");
                survarium::weapon_user_dead_state::finalize(v47);
                v140 = v48;
                v139 = vostok::memory::doug_lea_allocator::malloc_impl(v48, 0x34u);
                v221 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v139);
                if ( v221 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v221, 0);
                  v91 = v50;
                }
                else
                {
                  v91 = 0;
                }
                v295 = v91;
                survarium::weapon_user_dead_state::finalize(v49);
                v138 = v51;
                v137 = vostok::memory::doug_lea_allocator::malloc_impl(v51, 0x34u);
                v220 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v137);
                if ( v220 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v220, 5u);
                  v90 = v52;
                }
                else
                {
                  v90 = 0;
                }
                v297 = v90;
                vostok::ai::behaviour::fill_action_parameter(v298, v90);
                v135 = v295;
                v136 = 0;
                survarium::weapon_user_dead_state::finalize(v295);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v135);
                v53 = result->m_parameters.m_end + 1;
                result->m_parameters.m_end = v53;
                v133 = v297;
                v134 = 0;
                survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v53);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v133);
                v54 = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)result;
                ++result->m_parameters.m_end;
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v54, &initializer);
                LODWORD(v219.f_.f_) = vostok::ai::brain_unit::play_animation;
                HIDWORD(v219.f_.f_) = 0;
                v132 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                          (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v218,
                          (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::play_animation,
                          *(_BYTE *)&1_255);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v132.l_.boost::_bi::storage1<boost::arg<1> >,
                  &v219.l_);
                boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::ai::brain_unit,vostok::ai::animation_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>(
                  (boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *> *)&v219.l_,
                  (boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::ai::brain_unit,vostok::ai::animation_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v132);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
                  &v217,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v219.l_);
                vostok::ai::planning::pddl_problem::add_action_instance2<vostok::ai::brain_unit const *,vostok::ai::weapon const *,vostok::ai::brain_unit const *,vostok::ai::weapon const *>(
                  problem,
                  result,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&initializer,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v217,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&initializer);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v217);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v219.l_);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&initializer);
                break;
              case 9u:
                v294 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter0");
                survarium::weapon_user_dead_state::finalize(v55);
                v131 = v56;
                v130 = vostok::memory::doug_lea_allocator::malloc_impl(v56, 0x34u);
                v216 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v130);
                if ( v216 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v216, 0);
                  v89 = v58;
                }
                else
                {
                  v89 = 0;
                }
                v291 = v89;
                survarium::weapon_user_dead_state::finalize(v57);
                v129 = v59;
                v128 = vostok::memory::doug_lea_allocator::malloc_impl(v59, 0x34u);
                v215 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v128);
                if ( v215 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v215, 6u);
                  v88 = v60;
                }
                else
                {
                  v88 = 0;
                }
                v293 = v88;
                vostok::ai::behaviour::fill_action_parameter(v294, v88);
                v126 = v291;
                v127 = 0;
                survarium::weapon_user_dead_state::finalize(v61);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v126);
                ++result->m_parameters.m_end;
                v124 = v293;
                v125 = 0;
                survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v293);
                vostok::buffer_vector<void const *>::construct(
                  (const void **)result->m_parameters.m_end,
                  (const void **)&v124);
                v62 = result->m_parameters.m_end + 1;
                result->m_parameters.m_end = v62;
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v62,
                  &finalizer);
                LODWORD(v214.f_.f_) = vostok::ai::brain_unit::play_sound;
                HIDWORD(v214.f_.f_) = 0;
                v123 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                          (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v213,
                          (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::play_sound,
                          *(_BYTE *)&1_255);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v123.f_.f_),
                  &v214.l_);
                boost::function2<void,vostok::ai::brain_unit *,vostok::ai::sound_item const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit,vostok::ai::sound_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>(
                  (boost::function2<void,vostok::ai::brain_unit *,vostok::ai::sound_item const *> *)&v214.l_,
                  (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit,vostok::ai::sound_item const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2> > >)v123);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
                  &v212,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v214.l_);
                vostok::ai::planning::pddl_problem::add_action_instance2<vostok::ai::brain_unit const *,vostok::ai::weapon const *,vostok::ai::brain_unit const *,vostok::ai::weapon const *>(
                  problem,
                  result,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&finalizer,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v212,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&finalizer);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v212);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v214.l_);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&finalizer);
                break;
              case 0xAu:
                v290 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter0");
                v286 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter1");
                survarium::weapon_user_dead_state::finalize(v63);
                v122 = v64;
                v121 = vostok::memory::doug_lea_allocator::malloc_impl(v64, 0x34u);
                v211 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v121);
                if ( v211 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v211, 0);
                  v87 = v65;
                }
                else
                {
                  v87 = 0;
                }
                v287 = v87;
                survarium::weapon_user_dead_state::finalize(v87);
                v120 = v66;
                v119 = vostok::memory::doug_lea_allocator::malloc_impl(v66, 0x34u);
                v210 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v119);
                if ( v210 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v210, 5u);
                  v86 = v68;
                }
                else
                {
                  v86 = 0;
                }
                v289 = v86;
                survarium::weapon_user_dead_state::finalize(v67);
                v118 = v69;
                v117 = vostok::memory::doug_lea_allocator::malloc_impl(v69, 0x34u);
                v209 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v117);
                if ( v209 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v209, 6u);
                  v85 = v70;
                }
                else
                {
                  v85 = 0;
                }
                v285 = v85;
                vostok::ai::behaviour::fill_action_parameter(v290, v289);
                vostok::ai::behaviour::fill_action_parameter(v286, v285);
                v116 = v287;
                vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
                  (vostok::buffer_vector<void const *> *)result,
                  (const void **)&v116);
                v115 = v289;
                vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
                  (vostok::buffer_vector<void const *> *)result,
                  (const void **)&v115);
                v114 = v285;
                vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
                  (vostok::buffer_vector<void const *> *)result,
                  (const void **)&v114);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v71, &v288);
                LODWORD(v208.f_.f_) = vostok::ai::brain_unit::play_animation_with_sound;
                HIDWORD(v208.f_.f_) = 0;
                v113 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                          (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v207,
                          (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::play_animation_with_sound,
                          *(_BYTE *)&1_255);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  *(boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> **)&v113.l_.boost::_bi::storage1<boost::arg<1> >,
                  &v208.l_);
                boost::function3<void,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit,vostok::ai::animation_item const *,vostok::ai::sound_item const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
                  (boost::function3<void,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *> *)&v208.l_,
                  (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit,vostok::ai::animation_item const *,vostok::ai::sound_item const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v113);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v72, &v206);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
                  &v206,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v208.l_);
                vostok::ai::planning::pddl_problem::add_action_instance3<vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
                  problem,
                  result,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v288,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v206,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v288);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v206);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v208.l_);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v288);
                break;
              case 0xBu:
                v284 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)instance_value,
                                                                 "parameter0");
                survarium::weapon_user_dead_state::finalize(v73);
                v112 = v74;
                v111 = vostok::memory::doug_lea_allocator::malloc_impl(v74, 0x34u);
                v205 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v111);
                if ( v205 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v205, 0);
                  v84 = v76;
                }
                else
                {
                  v84 = 0;
                }
                v281 = v84;
                survarium::weapon_user_dead_state::finalize(v75);
                v110 = v77;
                v109 = vostok::memory::doug_lea_allocator::malloc_impl(v77, 0x34u);
                v204 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v109);
                if ( v204 )
                {
                  vostok::ai::planning::action_parameter::action_parameter(v204, 7u);
                  v83 = v78;
                }
                else
                {
                  v83 = 0;
                }
                v283 = v83;
                vostok::ai::behaviour::fill_action_parameter(v284, v83);
                v108 = v281;
                vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
                  (vostok::buffer_vector<void const *> *)result,
                  (const void **)&v108);
                v107 = v283;
                vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
                  (vostok::buffer_vector<void const *> *)result,
                  (const void **)&v107);
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v79, &v282);
                v201 = vostok::ai::brain_unit::move_to_point;
                v202 = 0;
                v80 = boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                        (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v200,
                        (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::move_to_point,
                        *(_BYTE *)&1_255);
                v106 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v80;
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
                  (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v80->f_.f_),
                  &v203);
                if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
                       (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function2<void,vostok::ai::brain_unit *,vostok::ai::movement_target const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
                       v106,
                       &v203.functor) )
                {
                  v81 = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)((char *)&`boost::function2<void,vostok::ai::brain_unit *,vostok::ai::movement_target const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager + 1);
                  v203.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,vostok::ai::brain_unit *,vostok::ai::movement_target const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::brain_unit,vostok::ai::movement_target const *>,boost::_bi::list2<boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                                                                       + 1);
                }
                else
                {
                  v203.vtable = 0;
                }
                boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v81, &v199);
                boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
                  &v199,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v203);
                vostok::ai::planning::pddl_problem::add_action_instance2<vostok::ai::brain_unit const *,vostok::ai::weapon const *,vostok::ai::brain_unit const *,vostok::ai::weapon const *>(
                  problem,
                  result,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v282,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v199,
                  (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v282);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v199);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v203);
                boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v282);
                break;
              default:
                if ( !vostok::core::g_log_filter_tree
                  || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error) )
                {
                  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v9);
                  v197 |= 1u;
                  vostok::logging::append(
                    &log_callback,
                    (void *const)vostok::core::g_log_flags,
                    &vostok::core::g_log_format,
                    ".\\behaviour_problem.cpp",
                    0x116u,
                    "void __cdecl vostok::ai::fill_action_instances(const class vostok::configs::binary_config_value &,cl"
                    "ass vostok::ai::ai_world &,const class vostok::ai::planning::pddl_domain &,class vostok::ai::plannin"
                    "g::pddl_problem &)",
                    "ai:",
                    error,
                    "Unknown action type was declared - %d",
                    action_type);
                }
                v82 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v197 & 1);
                if ( (v197 & 1) != 0 )
                {
                  v197 &= ~1u;
                  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
                    v82,
                    (int *)&log_callback);
                }
                break;
            }
          }
          break;
      }
    }
    else
    {
      param0 = vostok::configs::binary_config_value::operator[](
                 (vostok::configs::binary_config_value *)instance_value,
                 "parameter0");
      param1 = vostok::configs::binary_config_value::operator[](
                 (vostok::configs::binary_config_value *)instance_value,
                 "parameter1");
      survarium::weapon_user_dead_state::finalize(v11);
      v194 = v12;
      v193 = vostok::memory::doug_lea_allocator::malloc_impl(v12, 0x34u);
      v278 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v193);
      if ( v278 )
      {
        vostok::ai::planning::action_parameter::action_parameter(v278, 0);
        v104 = v13;
      }
      else
      {
        v104 = 0;
      }
      parameter_owner = (vostok::ai::planning::action_parameter *)v104;
      survarium::weapon_user_dead_state::finalize(v104);
      v192 = v14;
      v191 = vostok::memory::doug_lea_allocator::malloc_impl(v14, 0x34u);
      v277 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v191);
      if ( v277 )
      {
        vostok::ai::planning::action_parameter::action_parameter(v277, 1u);
        v103 = v16;
      }
      else
      {
        v103 = 0;
      }
      parameter0 = v103;
      survarium::weapon_user_dead_state::finalize(v15);
      v190 = v17;
      v189 = vostok::memory::doug_lea_allocator::malloc_impl(v17, 0x34u);
      v276 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v189);
      if ( v276 )
      {
        vostok::ai::planning::action_parameter::action_parameter(v276, 2u);
        v102 = v18;
      }
      else
      {
        v102 = 0;
      }
      parameter1 = v102;
      vostok::ai::behaviour::fill_action_parameter((vostok::configs::binary_config_value *)param0, parameter0);
      vostok::ai::behaviour::fill_action_parameter((vostok::configs::binary_config_value *)param1, parameter1);
      value = parameter_owner;
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        (vostok::buffer_vector<void const *> *)result,
        (const void **)&value);
      v187 = parameter0;
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        (vostok::buffer_vector<void const *> *)result,
        (const void **)&v187);
      v186 = parameter1;
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        (vostok::buffer_vector<void const *> *)result,
        (const void **)&v186);
      f = vostok::ai::brain_unit::stop_attack;
      f_4 = 0;
      v185 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v272,
                (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::stop_attack,
                *(_BYTE *)&1_255);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        &v275,
        (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v185,
        0);
      LODWORD(v270.f_.f_) = vostok::ai::brain_unit::attack;
      HIDWORD(v270.f_.f_) = 0;
      v184 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v269,
                (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::attack,
                *(_BYTE *)&1_255);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v270.l_,
        (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v184,
        0);
      LODWORD(v267.f_.f_) = vostok::ai::brain_unit::prepare_to_attack;
      HIDWORD(v267.f_.f_) = 0;
      v183 = *boost::bind<bool,vostok::ai::brain_unit,vostok::ai::npc const *,boost::arg<1>,boost::arg<2>>(
                (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *)&v266,
                (void (__thiscall *__ptr64)(vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(unsigned int)vostok::ai::brain_unit::prepare_to_attack,
                *(_BYTE *)&1_255);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&v267.l_,
        (boost::_bi::bind_t<void,boost::_mfi::cmf2<void,vostok::ai::brain_unit,vostok::ai::npc const *,vostok::ai::weapon const *>,boost::_bi::list3<boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v183,
        0);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        &v271,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v275);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        &v268,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v270.l_);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        &v265,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v267.l_);
      vostok::ai::planning::pddl_problem::add_action_instance3<vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
        problem,
        result,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v265,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v268,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v271);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v265);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v268);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v271);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v267.l_);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v270.l_);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v275);
    }
    vostok::ai::behaviour::fill_action_filter_sets(
      (vostok::configs::binary_config_value *)instance_value,
      world,
      result);
    ++it;
  }
}
