vostok::ai::planning::generalized_action *__cdecl vostok::ai::create_action_prototype(
        vostok::ai::planning::action_types_enum action_type,
        vostok::configs::binary_config_value *action_options,
        const vostok::ai::planning::pddl_domain *domain)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  vostok::ai::planning::generalized_action *v6; // eax
  vostok::ai::planning::base_lexeme *v7; // eax
  vostok::ai::planning::base_lexeme *v8; // eax
  vostok::ai::planning::base_lexeme *v9; // eax
  vostok::ai::planning::base_lexeme *v10; // eax
  vostok::ai::planning::base_lexeme *v11; // eax
  vostok::ai::planning::base_lexeme *v12; // eax
  vostok::ai::planning::base_lexeme *v13; // eax
  vostok::ai::planning::base_lexeme *v14; // eax
  vostok::ai::planning::base_lexeme *v15; // eax
  vostok::ai::planning::generalized_action *v17; // [esp+0h] [ebp-69Ch]
  vostok::ai::planning::base_lexeme *v18; // [esp+4h] [ebp-698h]
  vostok::variant<32> *v19; // [esp+8h] [ebp-694h] BYREF
  vostok::variant<32> *v20; // [esp+Ch] [ebp-690h] BYREF
  vostok::ai::planning::base_lexeme *v21; // [esp+10h] [ebp-68Ch]
  vostok::variant<32> *v22; // [esp+14h] [ebp-688h] BYREF
  vostok::variant<32> *v23; // [esp+18h] [ebp-684h] BYREF
  vostok::variant<32> *v24; // [esp+1Ch] [ebp-680h] BYREF
  vostok::ai::planning::base_lexeme *v25; // [esp+20h] [ebp-67Ch]
  vostok::variant<32> *v26; // [esp+24h] [ebp-678h] BYREF
  vostok::variant<32> *v27; // [esp+28h] [ebp-674h] BYREF
  vostok::fixed_vector<vostok::ai::planning::expression_parameter,4> *v28; // [esp+2Ch] [ebp-670h]
  vostok::ai::planning::expression_parameter *i6; // [esp+30h] [ebp-66Ch]
  vostok::ai::planning::base_lexeme *v30; // [esp+34h] [ebp-668h]
  vostok::variant<32> *v31; // [esp+40h] [ebp-65Ch] BYREF
  vostok::variant<32> *v32; // [esp+44h] [ebp-658h] BYREF
  vostok::fixed_vector<void const *,4> *v33; // [esp+48h] [ebp-654h]
  const void **i5; // [esp+4Ch] [ebp-650h]
  vostok::ai::planning::expression_parameter v35; // [esp+50h] [ebp-64Ch] BYREF
  vostok::fixed_vector<void const *,4> *v36; // [esp+54h] [ebp-648h]
  const void **i4; // [esp+58h] [ebp-644h]
  vostok::fixed_vector<void const *,4> *v38; // [esp+5Ch] [ebp-640h]
  const void **i3; // [esp+60h] [ebp-63Ch]
  vostok::ai::planning::expression_parameter v40; // [esp+64h] [ebp-638h] BYREF
  vostok::ai::planning::expression_parameter v41; // [esp+68h] [ebp-634h] BYREF
  vostok::variant<32> *v42; // [esp+6Ch] [ebp-630h] BYREF
  vostok::variant<32> *v43; // [esp+70h] [ebp-62Ch] BYREF
  vostok::variant<32> *v44; // [esp+74h] [ebp-628h] BYREF
  vostok::fixed_vector<void const *,4> *v45; // [esp+78h] [ebp-624h]
  const void **i2; // [esp+7Ch] [ebp-620h]
  vostok::ai::planning::expression_parameter v47; // [esp+80h] [ebp-61Ch] BYREF
  vostok::fixed_vector<void const *,4> *v48; // [esp+84h] [ebp-618h]
  const void **i1; // [esp+88h] [ebp-614h]
  vostok::ai::planning::expression_parameter v50; // [esp+8Ch] [ebp-610h] BYREF
  vostok::variant<32> *v51; // [esp+90h] [ebp-60Ch] BYREF
  vostok::variant<32> *v52; // [esp+94h] [ebp-608h] BYREF
  vostok::fixed_vector<void const *,4> *v53; // [esp+98h] [ebp-604h]
  const void **nn; // [esp+9Ch] [ebp-600h]
  vostok::ai::planning::expression_parameter v55; // [esp+A0h] [ebp-5FCh] BYREF
  vostok::fixed_vector<void const *,4> *v56; // [esp+A4h] [ebp-5F8h]
  const void **mm; // [esp+A8h] [ebp-5F4h]
  vostok::ai::planning::expression_parameter v58; // [esp+ACh] [ebp-5F0h] BYREF
  vostok::variant<32> *v59; // [esp+B0h] [ebp-5ECh] BYREF
  vostok::fixed_vector<void const *,4> *v60; // [esp+B4h] [ebp-5E8h]
  const void **kk; // [esp+B8h] [ebp-5E4h]
  vostok::ai::planning::expression_parameter v62; // [esp+BCh] [ebp-5E0h] BYREF
  vostok::fixed_vector<void const *,4> *v63; // [esp+C0h] [ebp-5DCh]
  const void **jj; // [esp+C4h] [ebp-5D8h]
  vostok::ai::planning::expression_parameter v65; // [esp+C8h] [ebp-5D4h] BYREF
  vostok::variant<32> *v66; // [esp+CCh] [ebp-5D0h] BYREF
  vostok::fixed_vector<void const *,4> *v67; // [esp+D0h] [ebp-5CCh]
  const void **ii; // [esp+D4h] [ebp-5C8h]
  vostok::ai::planning::expression_parameter v69; // [esp+D8h] [ebp-5C4h] BYREF
  vostok::fixed_vector<void const *,4> *v70; // [esp+DCh] [ebp-5C0h]
  const void **n; // [esp+E0h] [ebp-5BCh]
  vostok::ai::planning::expression_parameter v72; // [esp+E4h] [ebp-5B8h] BYREF
  vostok::variant<32> *v73; // [esp+E8h] [ebp-5B4h] BYREF
  vostok::variant<32> *v74; // [esp+ECh] [ebp-5B0h] BYREF
  vostok::fixed_vector<void const *,4> *v75; // [esp+F0h] [ebp-5ACh]
  const void **m; // [esp+F4h] [ebp-5A8h]
  vostok::ai::planning::expression_parameter v77; // [esp+F8h] [ebp-5A4h] BYREF
  vostok::fixed_vector<void const *,4> *v78; // [esp+FCh] [ebp-5A0h]
  const void **k; // [esp+100h] [ebp-59Ch]
  vostok::ai::planning::expression_parameter v80; // [esp+104h] [ebp-598h] BYREF
  vostok::variant<32> *v81; // [esp+108h] [ebp-594h] BYREF
  vostok::fixed_vector<void const *,4> *v82; // [esp+10Ch] [ebp-590h]
  const void **j; // [esp+110h] [ebp-58Ch]
  vostok::ai::planning::expression_parameter v84; // [esp+114h] [ebp-588h] BYREF
  vostok::fixed_vector<vostok::ai::planning::expression_parameter,4> *p_m_parameters; // [esp+118h] [ebp-584h]
  vostok::ai::planning::expression_parameter *i; // [esp+11Ch] [ebp-580h]
  vostok::variant<32> *v87; // [esp+128h] [ebp-574h] BYREF
  vostok::variant<32> *v88; // [esp+12Ch] [ebp-570h] BYREF
  vostok::variant<32> *v89; // [esp+130h] [ebp-56Ch] BYREF
  vostok::fixed_vector<void const *,4> *v90; // [esp+134h] [ebp-568h]
  const void **i8; // [esp+138h] [ebp-564h]
  vostok::ai::planning::expression_parameter v92; // [esp+13Ch] [ebp-560h] BYREF
  vostok::fixed_vector<void const *,4> *v93; // [esp+140h] [ebp-55Ch]
  const void **i7; // [esp+144h] [ebp-558h]
  vostok::ai::planning::expression_parameter v95; // [esp+148h] [ebp-554h] BYREF
  vostok::variant<32> *v96; // [esp+14Ch] [ebp-550h] BYREF
  vostok::variant<32> *v97; // [esp+150h] [ebp-54Ch] BYREF
  vostok::variant<32> *value; // [esp+154h] [ebp-548h] BYREF
  void *_Where; // [esp+158h] [ebp-544h]
  vostok::memory::doug_lea_allocator *v100; // [esp+15Ch] [ebp-540h]
  vostok::ai::planning::predicate v101; // [esp+160h] [ebp-53Ch] BYREF
  vostok::ai::planning::predicate v102; // [esp+194h] [ebp-508h] BYREF
  vostok::ai::planning::predicate v103; // [esp+1C8h] [ebp-4D4h] BYREF
  vostok::ai::planning::predicate v104; // [esp+1FCh] [ebp-4A0h] BYREF
  vostok::ai::planning::predicate v105; // [esp+230h] [ebp-46Ch] BYREF
  vostok::ai::planning::predicate v106; // [esp+264h] [ebp-438h] BYREF
  vostok::ai::planning::predicate v107; // [esp+298h] [ebp-404h] BYREF
  vostok::ai::planning::predicate v108; // [esp+2CCh] [ebp-3D0h] BYREF
  vostok::ai::planning::base_lexeme v109; // [esp+300h] [ebp-39Ch] BYREF
  vostok::fixed_vector<void const *,4> v110; // [esp+318h] [ebp-384h] BYREF
  int v111; // [esp+330h] [ebp-36Ch]
  vostok::ai::planning::base_lexeme v112; // [esp+334h] [ebp-368h] BYREF
  vostok::ai::planning::base_lexeme left; // [esp+34Ch] [ebp-350h] BYREF
  vostok::fixed_vector<void const *,4> v114; // [esp+364h] [ebp-338h] BYREF
  int v115; // [esp+37Ch] [ebp-320h]
  vostok::ai::planning::base_lexeme right; // [esp+380h] [ebp-31Ch] BYREF
  vostok::fixed_vector<void const *,4> v117; // [esp+398h] [ebp-304h] BYREF
  int v118; // [esp+3B0h] [ebp-2ECh]
  vostok::ai::planning::base_lexeme v119; // [esp+3B4h] [ebp-2E8h] BYREF
  vostok::fixed_vector<void const *,4> v120; // [esp+3CCh] [ebp-2D0h] BYREF
  int v121; // [esp+3E4h] [ebp-2B8h]
  vostok::ai::planning::base_lexeme v122; // [esp+3E8h] [ebp-2B4h] BYREF
  vostok::fixed_vector<void const *,4> v123; // [esp+400h] [ebp-29Ch] BYREF
  int v124; // [esp+418h] [ebp-284h]
  vostok::ai::planning::base_lexeme v125; // [esp+41Ch] [ebp-280h] BYREF
  vostok::fixed_vector<void const *,4> v126; // [esp+434h] [ebp-268h] BYREF
  int v127; // [esp+44Ch] [ebp-250h]
  vostok::ai::planning::base_lexeme v128; // [esp+450h] [ebp-24Ch] BYREF
  vostok::fixed_vector<void const *,4> v129; // [esp+468h] [ebp-234h] BYREF
  int v130; // [esp+480h] [ebp-21Ch]
  vostok::ai::planning::base_lexeme v131; // [esp+484h] [ebp-218h] BYREF
  vostok::fixed_vector<void const *,4> v132; // [esp+49Ch] [ebp-200h] BYREF
  int v133; // [esp+4B4h] [ebp-1E8h]
  vostok::ai::planning::base_lexeme v134; // [esp+4B8h] [ebp-1E4h] BYREF
  vostok::fixed_vector<void const *,4> v135; // [esp+4D0h] [ebp-1CCh] BYREF
  int v136; // [esp+4E8h] [ebp-1B4h]
  vostok::ai::planning::base_lexeme v137; // [esp+4ECh] [ebp-1B0h] BYREF
  vostok::fixed_vector<void const *,4> v138; // [esp+504h] [ebp-198h] BYREF
  int v139; // [esp+51Ch] [ebp-180h]
  vostok::ai::planning::base_lexeme v140; // [esp+520h] [ebp-17Ch] BYREF
  vostok::fixed_vector<void const *,4> v141; // [esp+538h] [ebp-164h] BYREF
  int v142; // [esp+550h] [ebp-14Ch]
  vostok::ai::planning::base_lexeme v143; // [esp+554h] [ebp-148h] BYREF
  vostok::fixed_vector<void const *,4> v144; // [esp+56Ch] [ebp-130h] BYREF
  int v145; // [esp+584h] [ebp-118h]
  vostok::ai::planning::base_lexeme v146; // [esp+588h] [ebp-114h] BYREF
  vostok::fixed_vector<void const *,4> v147; // [esp+5A0h] [ebp-FCh] BYREF
  int v148; // [esp+5B8h] [ebp-E4h]
  vostok::ai::planning::base_lexeme v149; // [esp+5BCh] [ebp-E0h] BYREF
  vostok::fixed_vector<void const *,4> v150; // [esp+5D4h] [ebp-C8h] BYREF
  int v151; // [esp+5ECh] [ebp-B0h]
  vostok::ai::planning::predicate v152; // [esp+5F0h] [ebp-ACh] BYREF
  vostok::ai::planning::base_lexeme v153; // [esp+624h] [ebp-78h] BYREF
  vostok::fixed_vector<void const *,4> v154; // [esp+63Ch] [ebp-60h] BYREF
  int v155; // [esp+654h] [ebp-48h]
  vostok::ai::planning::base_lexeme target_expression; // [esp+658h] [ebp-44h] BYREF
  vostok::fixed_vector<void const *,4> v157; // [esp+670h] [ebp-2Ch] BYREF
  int v158; // [esp+688h] [ebp-14h]
  vostok::ai::planning::generalized_action *v159; // [esp+68Ch] [ebp-10h]
  vostok::ai::planning::generalized_action *result; // [esp+690h] [ebp-Ch]
  unsigned int action_cost; // [esp+694h] [ebp-8h]
  const char *caption; // [esp+698h] [ebp-4h]

  v3 = vostok::configs::binary_config_value::operator[](action_options, "cost");
  action_cost = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                v4,
                                (int)v3);
  caption = actions_captions_0[action_type];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)caption);
  v100 = v5;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0xB8u);
  v159 = (vostok::ai::planning::generalized_action *)operator new(0xB8u, _Where);
  if ( v159 )
  {
    vostok::ai::planning::generalized_action::generalized_action(v159, domain, action_type, caption, action_cost);
    v17 = v6;
  }
  else
  {
    v17 = 0;
  }
  result = v17;
  if ( action_type )
  {
    switch ( action_type )
    {
      case action_type_attack_melee:
        v89 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v89);
        v88 = (vostok::variant<32> *)1;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v88);
        v87 = (vostok::variant<32> *)2;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v87);
        vostok::ai::planning::predicate::predicate(&v152, 2u, _0, _1);
        vostok::ai::planning::generalized_action::set_preconditions(result, v7);
        p_m_parameters = &v152.m_parameters;
        for ( i = v152.m_parameters.m_begin; i != p_m_parameters->m_end; ++i )
          ;
        p_m_parameters->m_end = p_m_parameters->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v152);
        vostok::ai::planning::base_lexeme::base_lexeme(&v149, 0);
        v149.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v150);
        v151 = 0;
        v84.instance = (const void *)1;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v150,
          &v84);
        vostok::ai::planning::generalized_action::set_effects(result, &v149);
        v82 = &v150;
        for ( j = v150.m_begin; j != v82->m_end; ++j )
          ;
        v82->m_end = v82->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v149);
        break;
      case action_type_survey_area:
        v81 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v81);
        vostok::ai::planning::base_lexeme::base_lexeme(&v146, 0);
        v146.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v147);
        v148 = 4;
        v80.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v147,
          &v80);
        vostok::ai::planning::base_lexeme::invert_value(&v146);
        vostok::ai::planning::generalized_action::set_preconditions(result, &v146);
        v78 = &v147;
        for ( k = v147.m_begin; k != v78->m_end; ++k )
          ;
        v78->m_end = v78->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v146);
        vostok::ai::planning::base_lexeme::base_lexeme(&v143, 0);
        v143.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v144);
        v145 = 4;
        v77.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v144,
          &v77);
        vostok::ai::planning::generalized_action::set_effects(result, &v143);
        v75 = &v144;
        for ( m = v144.m_begin; m != v75->m_end; ++m )
          ;
        v75->m_end = v75->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v143);
        break;
      case action_type_reload_weapon:
        v74 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v74);
        v73 = (vostok::variant<32> *)2;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v73);
        vostok::ai::planning::base_lexeme::base_lexeme(&v140, 0);
        v140.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v141);
        v142 = 1;
        v72.instance = (const void *)1;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v141,
          &v72);
        vostok::ai::planning::base_lexeme::invert_value(&v140);
        vostok::ai::planning::generalized_action::set_preconditions(result, &v140);
        v70 = &v141;
        for ( n = v141.m_begin; n != v70->m_end; ++n )
          ;
        v70->m_end = v70->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v140);
        vostok::ai::planning::base_lexeme::base_lexeme(&v137, 0);
        v137.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v138);
        v139 = 1;
        v69.instance = (const void *)1;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v138,
          &v69);
        vostok::ai::planning::generalized_action::set_effects(result, &v137);
        v67 = &v138;
        for ( ii = v138.m_begin; ii != v67->m_end; ++ii )
          ;
        v67->m_end = v67->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v137);
        break;
      case action_type_uncover:
        v66 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v66);
        vostok::ai::planning::base_lexeme::base_lexeme(&v134, 0);
        v134.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v135);
        v136 = 5;
        v65.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v135,
          &v65);
        vostok::ai::planning::generalized_action::set_preconditions(result, &v134);
        v63 = &v135;
        for ( jj = v135.m_begin; jj != v63->m_end; ++jj )
          ;
        v63->m_end = v63->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v134);
        vostok::ai::planning::base_lexeme::base_lexeme(&v131, 0);
        v131.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v132);
        v133 = 5;
        v62.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v132,
          &v62);
        vostok::ai::planning::base_lexeme::invert_value(&v131);
        vostok::ai::planning::generalized_action::set_effects(result, &v131);
        v60 = &v132;
        for ( kk = v132.m_begin; kk != v60->m_end; ++kk )
          ;
        v60->m_end = v60->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v131);
        break;
      case action_type_cloak:
        v59 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v59);
        vostok::ai::planning::base_lexeme::base_lexeme(&v128, 0);
        v128.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v129);
        v130 = 6;
        v58.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v129,
          &v58);
        vostok::ai::planning::base_lexeme::invert_value(&v128);
        vostok::ai::planning::generalized_action::set_preconditions(result, &v128);
        v56 = &v129;
        for ( mm = v129.m_begin; mm != v56->m_end; ++mm )
          ;
        v56->m_end = v56->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v128);
        vostok::ai::planning::base_lexeme::base_lexeme(&v125, 0);
        v125.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v126);
        v127 = 6;
        v55.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v126,
          &v55);
        vostok::ai::planning::generalized_action::set_effects(result, &v125);
        v53 = &v126;
        for ( nn = v126.m_begin; nn != v53->m_end; ++nn )
          ;
        v53->m_end = v53->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v125);
        break;
      case action_type_take_cover:
        v52 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v52);
        v51 = (vostok::variant<32> *)4;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v51);
        vostok::ai::planning::base_lexeme::base_lexeme(&v122, 0);
        v122.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v123);
        v124 = 5;
        v50.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v123,
          &v50);
        vostok::ai::planning::base_lexeme::invert_value(&v122);
        vostok::ai::planning::generalized_action::set_preconditions(result, &v122);
        v48 = &v123;
        for ( i1 = v123.m_begin; i1 != v48->m_end; ++i1 )
          ;
        v48->m_end = v48->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v122);
        vostok::ai::planning::base_lexeme::base_lexeme(&v119, 0);
        v119.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v120);
        v121 = 5;
        v47.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v120,
          &v47);
        vostok::ai::planning::generalized_action::set_effects(result, &v119);
        v45 = &v120;
        for ( i2 = v120.m_begin; i2 != v45->m_end; ++i2 )
          ;
        v45->m_end = v45->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v119);
        break;
      case action_type_attack_from_cover:
        v44 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v44);
        v43 = (vostok::variant<32> *)1;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v43);
        v42 = (vostok::variant<32> *)2;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v42);
        vostok::ai::planning::base_lexeme::base_lexeme(&right, 0);
        right.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v117);
        v118 = 1;
        v41.instance = (const void *)2;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v117,
          &v41);
        vostok::ai::planning::base_lexeme::base_lexeme(&left, 0);
        left.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v114);
        v115 = 5;
        v40.instance = 0;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v114,
          &v40);
        vostok::ai::planning::base_lexeme::base_lexeme(&v112, operation_type_and, &left, &right, 0);
        vostok::ai::planning::generalized_action::set_preconditions(result, &v112);
        vostok::ai::planning::base_lexeme::~base_lexeme(&v112);
        v38 = &v114;
        for ( i3 = v114.m_begin; i3 != v38->m_end; ++i3 )
          ;
        v38->m_end = v38->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&left);
        v36 = &v117;
        for ( i4 = v117.m_begin; i4 != v36->m_end; ++i4 )
          ;
        v36->m_end = v36->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&right);
        vostok::ai::planning::base_lexeme::base_lexeme(&v109, 0);
        v109.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
        vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v110);
        v111 = 0;
        v35.instance = (const void *)1;
        vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
          (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v110,
          &v35);
        vostok::ai::planning::generalized_action::set_effects(result, &v109);
        v33 = &v110;
        for ( i5 = v110.m_begin; i5 != v33->m_end; ++i5 )
          ;
        v33->m_end = v33->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v109);
        break;
      case action_type_play_animation:
        v32 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v32);
        v31 = (vostok::variant<32> *)5;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v31);
        vostok::ai::planning::predicate::predicate(&v108, 8u, _0, _1);
        v30 = v8;
        vostok::ai::planning::base_lexeme::invert_value(v8);
        vostok::ai::planning::generalized_action::set_preconditions(result, v30);
        v28 = &v108.m_parameters;
        for ( i6 = v108.m_parameters.m_begin; i6 != v28->m_end; ++i6 )
          ;
        v28->m_end = v28->m_begin;
        vostok::ai::planning::base_lexeme::~base_lexeme(&v108);
        vostok::ai::planning::predicate::predicate(&v107, 8u, _0, _1);
        vostok::ai::planning::generalized_action::set_effects(result, v9);
        vostok::ai::planning::predicate::~predicate(&v107);
        break;
      case action_type_play_sound:
        v27 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v27);
        v26 = (vostok::variant<32> *)6;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v26);
        vostok::ai::planning::predicate::predicate(&v106, 9u, _0, _1);
        v25 = v10;
        vostok::ai::planning::base_lexeme::invert_value(v10);
        vostok::ai::planning::generalized_action::set_preconditions(result, v25);
        vostok::ai::planning::predicate::~predicate(&v106);
        vostok::ai::planning::predicate::predicate(&v105, 9u, _0, _1);
        vostok::ai::planning::generalized_action::set_effects(result, v11);
        vostok::ai::planning::predicate::~predicate(&v105);
        break;
      case action_type_play_animation_with_sound:
        v24 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v24);
        v23 = (vostok::variant<32> *)5;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v23);
        v22 = (vostok::variant<32> *)6;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v22);
        vostok::ai::planning::predicate::predicate(&v104, 0xAu, _0, _1, _2);
        v21 = v12;
        vostok::ai::planning::base_lexeme::invert_value(v12);
        vostok::ai::planning::generalized_action::set_preconditions(result, v21);
        vostok::ai::planning::predicate::~predicate(&v104);
        vostok::ai::planning::predicate::predicate(&v103, 0xAu, _0, _1, _2);
        vostok::ai::planning::generalized_action::set_effects(result, v13);
        vostok::ai::planning::predicate::~predicate(&v103);
        break;
      case action_type_move_to_point:
        v20 = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v20);
        v19 = (vostok::variant<32> *)7;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
          (const vostok::variant<32> **)&v19);
        vostok::ai::planning::predicate::predicate(&v102, 0xBu, _0, _1);
        v18 = v14;
        vostok::ai::planning::base_lexeme::invert_value(v14);
        vostok::ai::planning::generalized_action::set_preconditions(result, v18);
        vostok::ai::planning::predicate::~predicate(&v102);
        vostok::ai::planning::predicate::predicate(&v101, 0xBu, _0, _1);
        vostok::ai::planning::generalized_action::set_effects(result, v15);
        vostok::ai::planning::predicate::~predicate(&v101);
        break;
    }
  }
  else
  {
    value = 0;
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
      (const vostok::variant<32> **)&value);
    v97 = (vostok::variant<32> *)1;
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
      (const vostok::variant<32> **)&v97);
    v96 = (vostok::variant<32> *)2;
    vostok::buffer_vector<unsigned int>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)&result->m_parameter_types,
      (const vostok::variant<32> **)&v96);
    vostok::ai::planning::base_lexeme::base_lexeme(&target_expression, 0);
    target_expression.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
    vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v157);
    v158 = 1;
    v95.instance = (const void *)2;
    vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
      (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v157,
      &v95);
    vostok::ai::planning::generalized_action::set_preconditions(result, &target_expression);
    v93 = &v157;
    for ( i7 = v157.m_begin; i7 != v93->m_end; ++i7 )
      ;
    v93->m_end = v93->m_begin;
    vostok::ai::planning::base_lexeme::~base_lexeme(&target_expression);
    vostok::ai::planning::base_lexeme::base_lexeme(&v153, 0);
    v153.__vftable = (vostok::ai::planning::base_lexeme_vtbl *)&vostok::ai::planning::predicate::`vftable';
    vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(&v154);
    v155 = 0;
    v92.instance = (const void *)1;
    vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
      (vostok::buffer_vector<vostok::ai::planning::expression_parameter> *)&v154,
      &v92);
    vostok::ai::planning::generalized_action::set_effects(result, &v153);
    v90 = &v154;
    for ( i8 = v154.m_begin; i8 != v90->m_end; ++i8 )
      ;
    v90->m_end = v90->m_begin;
    vostok::ai::planning::base_lexeme::~base_lexeme(&v153);
  }
  return result;
}
