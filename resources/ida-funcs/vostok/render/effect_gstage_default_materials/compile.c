void __thiscall vostok::render::effect_gstage_default_materials::compile(
        vostok::render::effect_gstage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::custom_config_value *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  bool v5; // al
  bool v6; // al
  const vostok::render::custom_config_value *v7; // eax
  vostok::render::custom_config_value *v8; // ecx
  char data; // al
  vostok::render::custom_config_value *v10; // ecx
  char v11; // al
  vostok::render::custom_config_value *v12; // ecx
  char v13; // al
  vostok::render::custom_config_value *v14; // ecx
  char v15; // al
  vostok::render::custom_config_value *v16; // ecx
  char v17; // al
  vostok::render::custom_config_value *v18; // ecx
  char v19; // al
  const vostok::render::custom_config_value *v20; // eax
  vostok::render::custom_config_value *v21; // ecx
  char v22; // al
  vostok::render::custom_config_value *v23; // ecx
  char v24; // al
  vostok::render::custom_config_value *v25; // ecx
  bool v26; // al
  vostok::render::custom_config_value *v27; // ecx
  bool v28; // al
  vostok::render::custom_config_value *v29; // ecx
  bool v30; // al
  vostok::render::custom_config_value *v31; // ecx
  bool v32; // al
  vostok::render::custom_config_value *v33; // ecx
  bool v34; // al
  vostok::render::custom_config_value *v35; // ecx
  bool v36; // al
  vostok::render::custom_config_value *v37; // ecx
  bool v38; // al
  vostok::render::custom_config_value *v39; // ecx
  char v40; // al
  vostok::render::custom_config_value *v41; // ecx
  char v42; // al
  vostok::render::custom_config_value *v43; // ecx
  char v44; // al
  const vostok::render::custom_config_value *v45; // eax
  vostok::render::custom_config_value *v46; // ecx
  bool v47; // al
  vostok::render::custom_config_value *v48; // ecx
  bool v49; // al
  vostok::render::custom_config_value *v50; // ecx
  char v51; // al
  vostok::render::custom_config_value *v52; // ecx
  bool v53; // al
  vostok::render::custom_config_value *v54; // ecx
  bool v55; // al
  vostok::render::custom_config_value *v56; // ecx
  bool v57; // al
  vostok::render::custom_config_value *v58; // ecx
  vostok::render::custom_config_value *v59; // ecx
  bool v60; // al
  vostok::render::custom_config_value *v61; // ecx
  const vostok::render::custom_config_value *v62; // eax
  vostok::render::custom_config_value *v63; // ecx
  vostok::render::custom_config_value *v64; // ecx
  char v65; // al
  unsigned int v66; // eax
  vostok::render::effect_compiler *v67; // esi
  vostok::render::custom_config_value *v68; // ecx
  const vostok::render::custom_config_value *v69; // eax
  vostok::render::custom_config_value *v70; // ecx
  vostok::render::custom_config_value *v71; // ecx
  const vostok::render::custom_config_value *v72; // eax
  vostok::render::custom_config_value *v73; // ecx
  double v74; // st7
  vostok::strings::shared::profile *v75; // ecx
  vostok::strings::shared::profile *v76; // eax
  vostok::math::float2 *p_source; // ecx
  vostok::strings::shared::profile *v78; // eax
  vostok::render::custom_config_value *v79; // ecx
  const vostok::render::custom_config_value *v80; // eax
  vostok::render::custom_config_value *v81; // ecx
  vostok::strings::shared::profile *v82; // eax
  vostok::render::effect_constant_storage *v83; // ecx
  vostok::render::custom_config_value *v84; // ecx
  const vostok::render::custom_config_value *v85; // eax
  vostok::render::custom_config_value *v86; // ecx
  vostok::render::custom_config_value *v87; // ecx
  const vostok::render::custom_config_value *v88; // eax
  vostok::render::custom_config_value *v89; // ecx
  vostok::render::custom_config_value *v90; // ecx
  const vostok::render::custom_config_value *v91; // eax
  vostok::render::custom_config_value *v92; // ecx
  vostok::strings::shared::profile *v93; // ecx
  vostok::strings::shared::profile *v94; // eax
  vostok::render::custom_config_value *v95; // ecx
  const vostok::render::custom_config_value *v96; // eax
  vostok::strings::shared::manager *v97; // ecx
  vostok::strings::shared::profile *v98; // eax
  vostok::strings::shared::profile *v99; // edi
  const char *v100; // eax
  vostok::render::custom_config_value *v101; // ecx
  const vostok::render::custom_config_value *v102; // eax
  vostok::render::custom_config_value *v103; // ecx
  long double v104; // st7
  long double v105; // st6
  vostok::strings::shared::profile *v106; // eax
  vostok::strings::shared::profile *v107; // ecx
  vostok::strings::shared::profile *v108; // eax
  vostok::strings::shared::profile *v109; // ecx
  vostok::strings::shared::profile *v110; // eax
  vostok::math::float3 *v111; // ecx
  vostok::render::custom_config_value *v112; // ecx
  const vostok::render::custom_config_value *v113; // eax
  vostok::render::custom_config_value *v114; // ecx
  __m128i si128; // xmm0
  vostok::strings::shared::profile *v116; // ecx
  vostok::strings::shared::profile *v117; // eax
  vostok::strings::shared::profile *v118; // eax
  const char *v119; // eax
  vostok::strings::shared::profile *v120; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v121; // edx
  int v122; // ecx
  vostok::render::custom_config_value *v123; // ecx
  const vostok::render::custom_config_value *v124; // eax
  vostok::render::custom_config_value *v125; // ecx
  vostok::render::custom_config_value *v126; // ecx
  const vostok::render::custom_config_value *v127; // eax
  vostok::render::custom_config_value *v128; // ecx
  vostok::render::custom_config_value *v129; // ecx
  const vostok::render::custom_config_value *v130; // eax
  vostok::render::custom_config_value *v131; // ecx
  vostok::strings::shared::profile *v132; // ecx
  vostok::strings::shared::profile *v133; // eax
  vostok::render::effect_constant_storage *v134; // ecx
  vostok::render::custom_config_value *v135; // ecx
  const vostok::render::custom_config_value *v136; // eax
  vostok::strings::shared::profile *v137; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v138; // edx
  int v139; // ecx
  vostok::strings::shared::profile *v140; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v141; // edx
  int v142; // ecx
  vostok::render::custom_config_value *v143; // ecx
  const vostok::render::custom_config_value *v144; // eax
  vostok::render::custom_config_value *v145; // ecx
  vostok::strings::shared::profile *v146; // ecx
  vostok::strings::shared::profile *v147; // eax
  vostok::render::effect_constant_storage *v148; // ecx
  const float *v149; // eax
  vostok::strings::shared::profile *v150; // eax
  vostok::render::custom_config_value *v151; // ecx
  const vostok::render::custom_config_value *v152; // eax
  vostok::render::custom_config_value *v153; // ecx
  double v154; // st7
  vostok::strings::shared::profile *v155; // ecx
  vostok::strings::shared::profile *v156; // eax
  vostok::render::effect_constant_storage *v157; // ecx
  const float *v158; // eax
  vostok::strings::shared::profile *v159; // eax
  vostok::render::custom_config_value *v160; // ecx
  const vostok::render::custom_config_value *v161; // eax
  vostok::render::custom_config_value *v162; // ecx
  __m128i v163; // xmm0
  vostok::strings::shared::profile *v164; // ecx
  vostok::strings::shared::profile *v165; // eax
  vostok::math::float4 *v166; // ecx
  vostok::strings::shared::profile *v167; // eax
  vostok::render::custom_config_value *v168; // ecx
  vostok::render::custom_config_value *v169; // ecx
  const vostok::render::custom_config_value *v170; // eax
  vostok::render::custom_config_value *v171; // ecx
  vostok::render::custom_config_value *v172; // ecx
  const vostok::render::custom_config_value *v173; // eax
  vostok::render::custom_config_value *v174; // ecx
  vostok::render::custom_config_value *v175; // ecx
  const vostok::render::custom_config_value *v176; // eax
  vostok::render::custom_config_value *v177; // ecx
  vostok::strings::shared::profile *v178; // ecx
  vostok::strings::shared::profile *v179; // eax
  vostok::strings::shared::profile *v180; // eax
  vostok::render::effect_constant_storage *v181; // ecx
  vostok::strings::shared::profile *v182; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v183; // edx
  int v184; // ecx
  char v185; // al
  const vostok::render::custom_config_value *v186; // eax
  vostok::render::custom_config_value *v187; // ecx
  vostok::render::custom_config_value *v188; // ecx
  const vostok::render::custom_config_value *v189; // eax
  vostok::render::custom_config_value *v190; // ecx
  vostok::render::custom_config_value *v191; // ecx
  const vostok::render::custom_config_value *v192; // eax
  vostok::render::custom_config_value *v193; // ecx
  vostok::strings::shared::profile *v194; // ecx
  vostok::strings::shared::profile *v195; // eax
  vostok::strings::shared::profile *v196; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v197; // edx
  int v198; // ecx
  vostok::strings::shared::profile *v199; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v200; // edx
  int v201; // ecx
  const vostok::render::custom_config_value *v202; // eax
  vostok::render::custom_config_value *v203; // ecx
  vostok::render::custom_config_value *v204; // ecx
  vostok::strings::shared::profile *v205; // edx
  vostok::render::custom_config_value *v206; // ecx
  const vostok::render::custom_config_value *v207; // eax
  vostok::render::custom_config_value *v208; // ecx
  const vostok::render::custom_config_value *v209; // eax
  vostok::render::custom_config_value *v210; // ecx
  vostok::strings::shared::profile *v211; // ecx
  vostok::strings::shared::profile *v212; // eax
  vostok::render::effect_constant_storage *v213; // ecx
  const float *v214; // eax
  vostok::strings::shared::profile *v215; // eax
  vostok::render::custom_config_value *v216; // ecx
  const vostok::render::custom_config_value *v217; // eax
  vostok::render::custom_config_value *v218; // ecx
  double v219; // st7
  vostok::strings::shared::profile *v220; // ecx
  vostok::strings::shared::profile *v221; // eax
  vostok::render::effect_constant_storage *v222; // ecx
  const float *v223; // eax
  vostok::strings::shared::profile *v224; // eax
  vostok::render::custom_config_value *v225; // ecx
  const vostok::render::custom_config_value *v226; // eax
  vostok::render::custom_config_value *v227; // ecx
  __m128i v228; // xmm0
  vostok::strings::shared::profile *v229; // ecx
  vostok::strings::shared::profile *v230; // eax
  vostok::math::float4 *v231; // ecx
  vostok::strings::shared::profile *v232; // eax
  vostok::strings::shared::profile *v233; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v234; // edx
  int v235; // ecx
  const vostok::render::custom_config_value *v236; // eax
  vostok::render::custom_config_value *v237; // ecx
  vostok::render::custom_config_value *v238; // ecx
  const vostok::render::custom_config_value *v239; // eax
  vostok::render::custom_config_value *v240; // ecx
  vostok::render::custom_config_value *v241; // ecx
  const vostok::render::custom_config_value *v242; // eax
  vostok::render::custom_config_value *v243; // ecx
  vostok::render::custom_config_value *v244; // ecx
  const vostok::render::custom_config_value *v245; // eax
  vostok::render::custom_config_value *v246; // ecx
  vostok::strings::shared::profile *v247; // ecx
  vostok::strings::shared::profile *v248; // eax
  vostok::render::custom_config_value *v249; // ecx
  vostok::strings::shared::profile *v250; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v251; // edx
  int v252; // ecx
  vostok::render::custom_config_value *v253; // ecx
  const vostok::render::custom_config_value *v254; // eax
  vostok::render::custom_config_value *v255; // ecx
  vostok::render::custom_config_value *v256; // ecx
  const vostok::render::custom_config_value *v257; // eax
  vostok::render::custom_config_value *v258; // ecx
  vostok::strings::shared::profile *v259; // eax
  vostok::render::custom_config_value *v260; // ecx
  vostok::strings::shared::profile *v261; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v262; // edx
  int v263; // ecx
  const vostok::render::custom_config_value *v264; // eax
  vostok::render::custom_config_value *v265; // ecx
  vostok::strings::shared::profile *v266; // ecx
  vostok::strings::shared::profile *v267; // eax
  vostok::render::effect_constant_storage *v268; // ecx
  vostok::render::custom_config_value *v269; // ecx
  const vostok::render::custom_config_value *v270; // eax
  vostok::render::custom_config_value *v271; // ecx
  vostok::strings::shared::profile *v272; // ecx
  vostok::strings::shared::profile *v273; // eax
  vostok::render::effect_constant_storage *v274; // ecx
  vostok::strings::shared::profile *v275; // ecx
  vostok::strings::shared::profile *v276; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v277; // edx
  int v278; // ecx
  vostok::strings::shared::profile *v279; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v280; // edx
  int v281; // ecx
  const vostok::render::custom_config_value *v282; // eax
  vostok::render::custom_config_value *v283; // ecx
  vostok::render::custom_config_value *v284; // ecx
  const vostok::render::custom_config_value *v285; // eax
  vostok::render::custom_config_value *v286; // ecx
  double v287; // st7
  vostok::strings::shared::profile *v288; // eax
  vostok::render::custom_config_value *v289; // ecx
  const vostok::render::custom_config_value *v290; // eax
  vostok::render::custom_config_value *v291; // ecx
  vostok::render::custom_config_value *v292; // ecx
  const vostok::render::custom_config_value *v293; // eax
  vostok::render::custom_config_value *v294; // ecx
  vostok::strings::shared::profile *v295; // ecx
  vostok::strings::shared::profile *v296; // eax
  vostok::strings::shared::profile *v297; // eax
  vostok::render::custom_config_value *v298; // ecx
  vostok::strings::shared::profile *v299; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v300; // edx
  int v301; // ecx
  vostok::render::custom_config_value *v302; // ecx
  const vostok::render::custom_config_value *v303; // eax
  vostok::render::custom_config_value *v304; // ecx
  vostok::render::custom_config_value *v305; // ecx
  const vostok::render::custom_config_value *v306; // eax
  vostok::render::custom_config_value *v307; // ecx
  double v308; // st7
  const vostok::render::custom_config_value *v309; // eax
  vostok::render::custom_config_value *v310; // ecx
  vostok::strings::shared::profile *v311; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v312; // edx
  int v313; // ecx
  vostok::render::custom_config_value *v314; // ecx
  const vostok::render::custom_config_value *v315; // eax
  vostok::render::custom_config_value *v316; // ecx
  vostok::render::custom_config_value *v317; // ecx
  const vostok::render::custom_config_value *v318; // eax
  vostok::render::custom_config_value *v319; // ecx
  double v320; // st7
  const vostok::render::custom_config_value *v321; // eax
  vostok::render::custom_config_value *v322; // ecx
  vostok::strings::shared::profile *v323; // eax
  vostok::render::custom_config_value *v324; // ecx
  vostok::strings::shared::profile *v325; // ecx
  vostok::strings::shared::profile *v326; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v327; // edx
  int v328; // ecx
  vostok::render::custom_config_value *v329; // ecx
  const vostok::render::custom_config_value *v330; // eax
  vostok::render::custom_config_value *v331; // ecx
  vostok::render::custom_config_value *v332; // ecx
  const vostok::render::custom_config_value *v333; // eax
  vostok::render::custom_config_value *v334; // ecx
  vostok::render::custom_config_value *v335; // ecx
  const vostok::render::custom_config_value *v336; // eax
  vostok::render::custom_config_value *v337; // ecx
  vostok::render::custom_config_value *v338; // ecx
  const vostok::render::custom_config_value *v339; // eax
  vostok::render::custom_config_value *v340; // ecx
  vostok::render::custom_config_value *v341; // ecx
  const vostok::render::custom_config_value *v342; // eax
  vostok::render::custom_config_value *v343; // ecx
  unsigned int v344; // xmm0_4
  vostok::strings::shared::profile *v345; // eax
  vostok::render::custom_config_value *v346; // ecx
  const vostok::render::custom_config_value *v347; // eax
  vostok::render::custom_config_value *v348; // ecx
  vostok::math::float4 v349; // xmm0
  vostok::strings::shared::profile *v350; // ecx
  vostok::strings::shared::profile *v351; // eax
  vostok::render::custom_config_value *v352; // ecx
  vostok::strings::shared::profile *v353; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v354; // edx
  int v355; // ecx
  vostok::render::custom_config_value *v356; // ecx
  const vostok::render::custom_config_value *v357; // eax
  vostok::render::custom_config_value *v358; // ecx
  vostok::render::custom_config_value *v359; // ecx
  const vostok::render::custom_config_value *v360; // eax
  vostok::render::custom_config_value *v361; // ecx
  vostok::render::custom_config_value *v362; // ecx
  const vostok::render::custom_config_value *v363; // eax
  vostok::render::custom_config_value *v364; // ecx
  vostok::render::custom_config_value *v365; // ecx
  const vostok::render::custom_config_value *v366; // eax
  vostok::render::custom_config_value *v367; // ecx
  vostok::strings::shared::profile *v368; // eax
  vostok::strings::shared::profile *v369; // eax
  vostok::render::effect_compiler *v370; // ecx
  vostok::render::effect_compiler *v371; // ecx
  vostok::render::effect_compiler *v372; // ecx
  vostok::render::effect_compiler *v373; // ecx
  vostok::render::custom_config_value *v374; // ecx
  vostok::render::effect_compiler *v375; // ecx
  vostok::render::custom_config_value *v376; // ecx
  vostok::strings::shared::profile *v377; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v378; // edx
  int v379; // ecx
  vostok::render::custom_config_value *v380; // ecx
  const vostok::render::custom_config_value *v381; // eax
  vostok::render::custom_config_value *v382; // ecx
  vostok::math::float4 v383; // xmm0
  vostok::strings::shared::profile *v384; // ecx
  vostok::strings::shared::profile *v385; // eax
  const vostok::math::float3 *v386; // ecx
  vostok::strings::shared::profile *v387; // eax
  vostok::render::effect_compiler *v388; // ecx
  vostok::render::effect_compiler *v389; // ecx
  vostok::render::custom_config_value *v390; // ecx
  vostok::render::custom_config_value *v391; // ecx
  vostok::strings::shared::profile *v392; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v393; // edx
  int v394; // ecx
  vostok::render::custom_config_value *v395; // ecx
  const vostok::render::custom_config_value *v396; // eax
  vostok::render::custom_config_value *v397; // ecx
  vostok::math::float4 v398; // xmm0
  vostok::strings::shared::profile *v399; // ecx
  const vostok::math::float3 *v400; // esi
  vostok::strings::shared::profile *v401; // eax
  vostok::render::effect_compiler *v402; // ecx
  vostok::render::effect_compiler *v403; // ecx
  vostok::render::custom_config_value *v404; // ecx
  vostok::render::custom_config_value *v405; // ecx
  vostok::render::effect_compiler *v406; // ecx
  vostok::render::custom_config_value *v407; // ecx
  const vostok::render::custom_config_value *v408; // eax
  vostok::render::custom_config_value *v409; // ecx
  vostok::render::custom_config_value *v410; // ecx
  const vostok::render::custom_config_value *v411; // eax
  vostok::render::custom_config_value *v412; // ecx
  __m128i v413; // xmm0
  vostok::strings::shared::profile *v414; // ecx
  vostok::strings::shared::profile *v415; // eax
  vostok::render::custom_config_value *v416; // ecx
  vostok::strings::shared::profile *v417; // ecx
  vostok::strings::shared::profile *v418; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v419; // edx
  int v420; // ecx
  vostok::render::effect_compiler *v421; // ecx
  vostok::render::custom_config_value *v422; // ecx
  char v423; // al
  vostok::render::custom_config_value *v424; // ecx
  char v425; // al
  vostok::render::effect_compiler *v426; // ecx
  vostok::render::custom_config_value *v427; // ecx
  const vostok::render::custom_config_value *v428; // eax
  const vostok::render::custom_config_value *v429; // eax
  vostok::render::custom_config_value *v430; // ecx
  vostok::strings::shared::profile *v431; // eax
  vostok::render::effect_constant_storage *v432; // ecx
  vostok::render::effect_compiler *v433; // ecx
  vostok::render::effect_compiler *v434; // ecx
  vostok::render::custom_config_value *v435; // ecx
  char v436; // al
  vostok::render::custom_config_value *v437; // ecx
  char v438; // al
  vostok::render::custom_config_value *v439; // ecx
  char v440; // al
  vostok::render::custom_config_value *v441; // ecx
  char v442; // al
  vostok::render::effect_compiler *v443; // ecx
  vostok::render::custom_config_value *v444; // ecx
  const vostok::render::custom_config_value *v445; // eax
  const vostok::render::custom_config_value *v446; // eax
  vostok::render::custom_config_value *v447; // ecx
  vostok::strings::shared::profile *v448; // eax
  vostok::render::effect_constant_storage *v449; // ecx
  vostok::render::custom_config_value *v450; // ecx
  const vostok::render::custom_config_value *v451; // eax
  const vostok::render::custom_config_value *v452; // eax
  vostok::render::effect_compiler *v453; // ecx
  vostok::render::effect_compiler *v454; // ecx
  vostok::render::custom_config_value *v455; // ecx
  char v456; // al
  vostok::render::custom_config_value *v457; // ecx
  char v458; // al
  vostok::render::effect_compiler *v459; // ecx
  vostok::render::custom_config_value *v460; // ecx
  const vostok::render::custom_config_value *v461; // eax
  const vostok::render::custom_config_value *v462; // eax
  vostok::render::custom_config_value *v463; // ecx
  vostok::strings::shared::profile *v464; // eax
  vostok::render::effect_constant_storage *v465; // ecx
  vostok::render::effect_compiler *v466; // ecx
  vostok::render::effect_compiler *v467; // ecx
  vostok::render::effect_compiler *v468; // ecx
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> v469; // [esp+383Eh] [ebp-278h] BYREF
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> _X; // [esp+3842h] [ebp-274h] BYREF
  const char *v471; // [esp+3846h] [ebp-270h]
  vostok::render::shader_configuration *v472; // [esp+384Ah] [ebp-26Ch]
  _BYTE v473[5]; // [esp+3855h] [ebp-261h] BYREF
  int v474; // [esp+385Ah] [ebp-25Ch]
  int v475; // [esp+385Eh] [ebp-258h]
  int v476; // [esp+3862h] [ebp-254h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *out_texture; // [esp+386Ah] [ebp-24Ch]
  unsigned int num_last_mips_used; // [esp+386Eh] [ebp-248h]
  float v479; // [esp+3872h] [ebp-244h] BYREF
  char v480; // [esp+3879h] [ebp-23Dh]
  unsigned int v481; // [esp+387Ah] [ebp-23Ch] BYREF
  float v482; // [esp+387Eh] [ebp-238h]
  float v483; // [esp+3882h] [ebp-234h] BYREF
  vostok::math::float4 v484; // [esp+3886h] [ebp-230h] BYREF
  vostok::math::float4 v485; // [esp+3896h] [ebp-220h] BYREF
  int v486; // [esp+38AAh] [ebp-20Ch]
  vostok::math::float3 v487; // [esp+38AEh] [ebp-208h] BYREF
  unsigned int v488; // [esp+38BAh] [ebp-1FCh]
  float v489; // [esp+38BEh] [ebp-1F8h] BYREF
  unsigned int v490; // [esp+38C2h] [ebp-1F4h]
  vostok::math::float4 v491; // [esp+38C6h] [ebp-1F0h] BYREF
  vostok::math::float3 v492; // [esp+38DAh] [ebp-1DCh] BYREF
  vostok::math::float4 v493; // [esp+38E6h] [ebp-1D0h] BYREF
  vostok::math::float4 v494; // [esp+38FAh] [ebp-1BCh] BYREF
  vostok::math::float4 v495; // [esp+390Ah] [ebp-1ACh] BYREF
  float v496; // [esp+391Ah] [ebp-19Ch] BYREF
  vostok::command_line::key_initializator v497[4]; // [esp+391Eh] [ebp-198h]
  const vostok::math::float4x4 *v498; // [esp+3922h] [ebp-194h] BYREF
  vostok::command_line::key_initializator v499[4]; // [esp+3926h] [ebp-190h]
  float v500; // [esp+392Ah] [ebp-18Ch]
  float v501; // [esp+392Eh] [ebp-188h]
  const vostok::math::float4x4 *v502; // [esp+3932h] [ebp-184h] BYREF
  const vostok::math::float4x4 *v503; // [esp+3936h] [ebp-180h] BYREF
  float v504; // [esp+393Ah] [ebp-17Ch] BYREF
  const vostok::math::float4x4 *v505; // [esp+393Eh] [ebp-178h] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+3942h] [ebp-174h]
  vostok::math::float2 source; // [esp+3946h] [ebp-170h] BYREF
  float v508[2]; // [esp+394Eh] [ebp-168h] BYREF
  vostok::math::float4 v509; // [esp+3956h] [ebp-160h] BYREF
  vostok::math::float3 v510; // [esp+396Eh] [ebp-148h] BYREF
  vostok::math::float3 v511; // [esp+397Ah] [ebp-13Ch] BYREF
  vostok::math::float3 v512; // [esp+3986h] [ebp-130h] BYREF
  vostok::math::float3 v513; // [esp+3992h] [ebp-124h] BYREF
  vostok::math::float3 v514; // [esp+399Eh] [ebp-118h] BYREF
  vostok::math::float3 v515; // [esp+39AAh] [ebp-10Ch] BYREF
  vostok::math::float3_pod object; // [esp+39B6h] [ebp-100h] BYREF
  vostok::math::float3_pod result_in_case_of_zero; // [esp+39C2h] [ebp-F4h] BYREF
  __int64 v518; // [esp+39CEh] [ebp-E8h] BYREF
  float x; // [esp+39D6h] [ebp-E0h]
  vostok::math::float3 v520; // [esp+39DAh] [ebp-DCh] BYREF
  vostok::math::float4 v521; // [esp+39E6h] [ebp-D0h] BYREF
  vostok::math::float4 v522; // [esp+39F6h] [ebp-C0h] BYREF
  vostok::math::float4 v523; // [esp+3A06h] [ebp-B0h] BYREF
  vostok::math::float4 v524; // [esp+3A16h] [ebp-A0h] BYREF
  vostok::math::float4 v525; // [esp+3A26h] [ebp-90h] BYREF
  vostok::math::float4 v526; // [esp+3A36h] [ebp-80h] BYREF
  vostok::math::float4 v527; // [esp+3A46h] [ebp-70h] BYREF
  vostok::math::float4 v528; // [esp+3A56h] [ebp-60h] BYREF
  __m128i v529; // [esp+3A66h] [ebp-50h] BYREF
  vostok::math::float4 v530; // [esp+3A76h] [ebp-40h] BYREF
  vostok::math::float4 v531; // [esp+3A86h] [ebp-30h] BYREF
  __m128i v532; // [esp+3A96h] [ebp-20h] BYREF
  __m128i v533; // [esp+3AA6h] [ebp-10h] BYREF

  LOBYTE(out_texture) = 0;
  if ( vostok::render::custom_config_value::value_exists(&key, v471) )
    LOBYTE(out_texture) = vostok::render::custom_config_value::operator[](v3, (const char *)&key)->data != (const void *)11;
  v505 = clear_value;
  num_last_mips_used = (unsigned __int8)out_texture != 0 ? 5 : -1;
  v486 = 0;
  *(_QWORD *)&v484.elements[2] = 0;
  *(_QWORD *)&v491.x = 0;
  v491.w = 0.0;
  do
  {
    v473[4] = 0;
    v474 = 0;
    v475 = 0;
    v476 = 0;
    *(_DWORD *)v473 = v486 == 0;
    v473[1] = (int)vostok::render::custom_config_value::operator[](v3, (const char *)&stru_9667A8)->data & 1;
    v5 = v473[0] && LOBYTE(vostok::render::custom_config_value::operator[](v4, (const char *)&stru_967F04)->data);
    LOBYTE(v4) = (v473[1] ^ (8 * v5)) & 8 ^ v473[1];
    v473[1] = (_BYTE)v4;
    v6 = v473[0] && LOBYTE(vostok::render::custom_config_value::operator[](v4, "use_parallax")->data);
    v473[1] ^= (v473[1] ^ (4 * v6)) & 4;
    LOBYTE(v4) = v473[1];
    v7 = vostok::render::custom_config_value::operator[](v4, (const char *)&stru_960A44);
    v473[1] ^= (v473[1] ^ (2 * LOBYTE(v7->data))) & 2;
    if ( v473[0] && vostok::render::custom_config_value::value_exists(&stru_968758, v471) )
      data = (char)vostok::render::custom_config_value::operator[](v8, (const char *)&stru_968758)->data;
    else
      data = 0;
    v473[1] ^= (v473[1] ^ (16 * data)) & 0x10;
    if ( v473[0]
      && vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_968758.destroyer,
           v471) )
    {
      v11 = (char)vostok::render::custom_config_value::operator[](v10, (const char *)&stru_968758.destroyer)->data;
    }
    else
    {
      v11 = 0;
    }
    LOBYTE(v475) = ((v11 & 1) << 6) | 4;
    if ( vostok::render::custom_config_value::value_exists(&stru_960A30, v471) )
      v13 = (char)vostok::render::custom_config_value::operator[](v12, (const char *)&stru_960A30)->data;
    else
      v13 = 0;
    BYTE2(v474) ^= (BYTE2(v474) ^ (v13 << 6)) & 0x40;
    if ( vostok::render::custom_config_value::value_exists(&stru_968780, v471) )
      v15 = (char)vostok::render::custom_config_value::operator[](v14, (const char *)&stru_968780)->data;
    else
      v15 = 0;
    BYTE2(v474) = BYTE2(v474) & 0x7F | (v15 << 7);
    if ( v473[0] && vostok::render::custom_config_value::value_exists(&stru_96879C, v471) )
      v17 = (char)vostok::render::custom_config_value::operator[](v16, (const char *)&stru_96879C)->data;
    else
      v17 = 0;
    BYTE1(v474) = BYTE1(v474) & 0x7F | (v17 << 7);
    if ( vostok::render::custom_config_value::value_exists(&stru_9687C0, v471) )
      v19 = (char)vostok::render::custom_config_value::operator[](v18, (const char *)&stru_9687C0)->data;
    else
      v19 = 0;
    v473[1] ^= (v473[1] ^ (32 * v19)) & 0x20;
    LOBYTE(v18) = v473[1];
    v20 = vostok::render::custom_config_value::operator[](v18, (const char *)&stru_9687D4);
    LOBYTE(v474) = (v474 ^ (LOBYTE(v20->data) != 0)) & 3 ^ v474;
    if ( vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_9687D4.destroyer,
           v471) )
    {
      v22 = (char)vostok::render::custom_config_value::operator[](v21, (const char *)&stru_9687D4.destroyer)->data;
    }
    else
    {
      v22 = 0;
    }
    v473[3] ^= (v473[3] ^ (4 * v22)) & 4;
    if ( v473[0] && vostok::render::custom_config_value::value_exists(&stru_9687F8, v471) )
      v24 = (char)vostok::render::custom_config_value::operator[](v23, (const char *)&stru_9687F8)->data;
    else
      v24 = 0;
    v473[3] ^= (v473[3] ^ (2 * v24)) & 2;
    v26 = v473[0]
       && vostok::render::custom_config_value::value_exists(
            (vostok::render::custom_config_value *)&stru_9687F8.destroyer,
            v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v25, (const char *)&stru_9687F8.destroyer)->data);
    v473[3] ^= (v473[3] ^ v26) & 1;
    v28 = v473[0]
       && vostok::render::custom_config_value::value_exists(&stru_968820, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v27, (const char *)&stru_968820)->data);
    HIBYTE(v474) ^= (HIBYTE(v474) ^ (2 * v28)) & 2;
    v30 = v473[0]
       && vostok::render::custom_config_value::value_exists(&stru_968838, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v29, (const char *)&stru_968838)->data);
    HIBYTE(v474) ^= (HIBYTE(v474) ^ (8 * v30)) & 8;
    v32 = v473[0]
       && vostok::render::custom_config_value::value_exists(&stru_968850, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v31, (const char *)&stru_968850)->data);
    HIBYTE(v474) ^= (HIBYTE(v474) ^ (4 * v32)) & 4;
    v34 = v473[0]
       && vostok::render::custom_config_value::value_exists(&stru_96886C, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v33, (const char *)&stru_96886C)->data);
    HIBYTE(v474) ^= (HIBYTE(v474) ^ (16 * v34)) & 0x10;
    v36 = v473[0]
       && vostok::render::custom_config_value::value_exists(&stru_968888, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v35, (const char *)&stru_968888)->data);
    HIBYTE(v474) ^= (HIBYTE(v474) ^ (32 * v36)) & 0x20;
    v38 = v473[0]
       && vostok::render::custom_config_value::value_exists(&stru_9688A4, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v37, (const char *)&stru_9688A4)->data);
    v473[3] ^= (v473[3] ^ (8 * v38)) & 8;
    if ( vostok::render::custom_config_value::value_exists(&stru_9688C0, v471) )
      v40 = (char)vostok::render::custom_config_value::operator[](v39, (const char *)&stru_9688C0)->data;
    else
      v40 = 0;
    v473[1] = v473[1] & 0x7F | (v40 << 7);
    if ( vostok::render::custom_config_value::value_exists(&stru_967F28, v471) )
      v42 = (char)vostok::render::custom_config_value::operator[](v41, (const char *)&stru_967F28)->data;
    else
      v42 = 0;
    v473[2] ^= (v473[2] ^ v42) & 1;
    if ( vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_967F28.destroyer,
           v471) )
    {
      v44 = (char)vostok::render::custom_config_value::operator[](v43, (const char *)&stru_967F28.destroyer)->data;
    }
    else
    {
      v44 = 0;
    }
    v473[2] ^= (v473[2] ^ (2 * v44)) & 2;
    LOBYTE(v43) = v473[2];
    v45 = vostok::render::custom_config_value::operator[](v43, "use_ttranslucency");
    v473[1] ^= (v473[1] ^ (LOBYTE(v45->data) << 6)) & 0x40;
    BYTE1(v475) = v486 & 7 | BYTE1(v475) & 0xF8 | 8;
    v47 = vostok::render::custom_config_value::value_exists(&stru_9688D8, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v46, (const char *)&stru_9688D8)->data);
    BYTE2(v475) ^= (BYTE2(v475) ^ (4 * v47)) & 4;
    v49 = vostok::render::custom_config_value::value_exists(&stru_960A90, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v48, (const char *)&stru_960A90)->data);
    HIBYTE(v475) ^= (HIBYTE(v475) ^ (32 * v49)) & 0x20;
    v51 = vostok::render::custom_config_value::value_exists(&stru_9688F4, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v50, (const char *)&stru_9688F4)->data);
    BYTE2(v475) ^= (BYTE2(v475) ^ (v51 << 6)) & 0x40;
    v53 = (v475 & 0x40000) != 0
       && (!vostok::render::custom_config_value::value_exists(
              (vostok::render::custom_config_value *)&stru_9688F4.destroyer,
              v471)
        || !LOBYTE(vostok::render::custom_config_value::operator[](v52, (const char *)&stru_9688F4.destroyer)->data));
    BYTE2(v475) ^= (BYTE2(v475) ^ (8 * v53)) & 8;
    v55 = vostok::render::custom_config_value::value_exists(&stru_96891C, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v54, (const char *)&stru_96891C)->data);
    BYTE2(v475) ^= (BYTE2(v475) ^ (32 * v55)) & 0x20;
    v57 = vostok::render::custom_config_value::value_exists(&stru_968930, v471)
       && LOBYTE(vostok::render::custom_config_value::operator[](v56, (const char *)&stru_968930)->data);
    BYTE2(v475) ^= (BYTE2(v475) ^ (16 * v57)) & 0x10;
    if ( vostok::render::custom_config_value::value_exists(&stru_968944, v471)
      && vostok::render::custom_config_value::value_exists(&stru_968958, v471) )
    {
      v60 = LOBYTE(vostok::render::custom_config_value::operator[](v58, (const char *)&stru_968944)->data)
         && strcmp(
              (const char *)vostok::render::custom_config_value::operator[](v59, (const char *)&stru_968958)->data,
              (const char *)&buf);
      v473[2] ^= (v473[2] ^ (32 * v60)) & 0x20;
    }
    if ( vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_960A44.destroyer,
           v471) )
    {
      v62 = vostok::render::custom_config_value::operator[](v61, (const char *)&stru_960A44.destroyer);
      LOBYTE(v61) = (v474 ^ (16 * (int)v62->data)) & 0x70 ^ v474;
      LOBYTE(v474) = (_BYTE)v61;
    }
    if ( v473[0] )
    {
      if ( LOBYTE(vostok::render::custom_config_value::operator[](v61, (const char *)&stru_9687D4)->data) )
      {
        LOBYTE(v474) = v474 & 0xFC | 1;
        if ( LOBYTE(vostok::render::custom_config_value::operator[](v63, "use_reflection_diffuse")->data) )
          LOBYTE(v474) = v474 & 0xFC | 2;
      }
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_967F48, v471) )
      v65 = (char)vostok::render::custom_config_value::operator[](v64, (const char *)&stru_967F48)->data;
    else
      v65 = 0;
    BYTE2(v474) ^= (BYTE2(v474) ^ v65) & 1;
    vostok::render::effect_material_base::compile_begin(
      (vostok::render::effect_material_base *)&stru_966284,
      "gbuffer_pass",
      &v473[1],
      v471,
      compiler,
      v472,
      custom_config);
    v480 = (v473[1] & 0x40) != 0;
    if ( (v473[1] & 0x40) != 0 )
    {
      v66 = 132;
    }
    else
    {
      switch ( v473[4] >> 2 )
      {
        case 3:
        case 4:
        case 5:
        case 6:
          v66 = 133;
          break;
        case 7:
        case 8:
        case 9:
          v66 = 134;
          break;
        default:
          v66 = 130;
          break;
      }
    }
    v67 = compiler;
    vostok::render::effect_compiler::set_stencil(
      compiler,
      1,
      v66,
      0xFFu,
      0xFFu,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_REPLACE,
      (D3D11_STENCIL_OP)v471,
      D3D11_STENCIL_OP_KEEP);
    if ( s_z_only_0.m_type == type_unset )
    {
      predicate[0] = 0;
      _X.m_object = *(vostok::strings::shared::profile **)predicate;
      s_z_only_0.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_z_only_0.m_type == type_recursive )
    {
      if ( !compiler->m_shaders_cache_mode )
      {
        if ( s_no_effect_result.m_type == type_unset )
        {
          v497[0] = 0;
          _X.m_object = *(vostok::strings::shared::profile **)v497;
          s_no_effect_result.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        }
        if ( s_no_effect_result.m_type == type_recursive )
        {
          compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
          goto LABEL_144;
        }
      }
    }
    else if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        v499[0] = 0;
        _X.m_object = *(vostok::strings::shared::profile **)v499;
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
LABEL_144:
        compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      }
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_967E90, v471)
      && vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_967E90.destroyer,
           v471) )
    {
      v69 = vostok::render::custom_config_value::operator[](v68, (const char *)&stru_967E90);
      v482 = vostok::render::custom_config_value::operator<float> float(v70, (int)v69);
      v72 = vostok::render::custom_config_value::operator[](v71, (const char *)&stru_967E90.destroyer);
      v74 = vostok::render::custom_config_value::operator<float> float(v73, (int)v72);
      _X.m_object = v75;
      v508[0] = v482;
      v508[1] = v74;
      v469.m_object = (vostok::strings::shared::profile *)"constant_tile_uv";
      v76 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
      _X.m_object = 0;
      if ( v76 )
      {
        _X.m_object = v76;
        _InterlockedExchangeAdd(&v76->m_reference_count, 1u);
      }
      p_source = (vostok::math::float2 *)v508;
    }
    else
    {
      _X.m_object = (vostok::strings::shared::profile *)v68;
      v469.m_object = (vostok::strings::shared::profile *)"constant_tile_uv";
      LODWORD(source.x) = clear_value;
      LODWORD(source.y) = clear_value;
      v78 = vostok::strings::shared::manager::string(
              (vostok::strings::shared::manager *)v68,
              (const char *)s_manager.m_variable);
      _X.m_object = 0;
      if ( v78 )
      {
        _X.m_object = v78;
        _InterlockedExchangeAdd(&v78->m_reference_count, 1u);
      }
      p_source = &source;
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float2>(
      (vostok::render::effect_constant_storage *)p_source,
      compiler,
      (vostok::shared_string)_X.m_object);
    v489 = 0.25;
    if ( (v473[1] & 2) != 0 && vostok::render::custom_config_value::value_exists(&stru_9667FC, v471) )
    {
      v80 = vostok::render::custom_config_value::operator[](v79, (const char *)&stru_9667FC);
      v489 = vostok::render::custom_config_value::operator<float> float(v81, (int)v80);
    }
    _X.m_object = (vostok::strings::shared::profile *)v79;
    v469.m_object = (vostok::strings::shared::profile *)&stru_9667FC.type;
    v82 = vostok::strings::shared::manager::string(
            (vostok::strings::shared::manager *)v79,
            (const char *)s_manager.m_variable);
    _X.m_object = 0;
    if ( v82 )
    {
      _X.m_object = v82;
      v83 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v82->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>(&v489, v83, compiler, (vostok::shared_string)_X.m_object);
    if ( (v475 & 0x400000) != 0
      && vostok::render::custom_config_value::value_exists(&stru_968998, v471)
      && vostok::render::custom_config_value::value_exists(&stru_9689B0, v471)
      && vostok::render::custom_config_value::value_exists(&stru_9689C8, v471) )
    {
      v85 = vostok::render::custom_config_value::operator[](v84, (const char *)&stru_9689C8);
      v479 = vostok::render::custom_config_value::operator<float> float(v86, (int)v85);
      v88 = vostok::render::custom_config_value::operator[](v87, (const char *)&stru_9689B0);
      v482 = vostok::render::custom_config_value::operator<float> float(v89, (int)v88);
      v91 = vostok::render::custom_config_value::operator[](v90, (const char *)&stru_968998);
      v514.x = vostok::render::custom_config_value::operator<float> float(v92, (int)v91);
      _X.m_object = v93;
      v514.y = v482;
      v469.m_object = (vostok::strings::shared::profile *)&stru_9689C8.destroyer;
      v514.z = v479;
      v94 = vostok::strings::shared::manager::string(
              (vostok::strings::shared::manager *)v93,
              (const char *)s_manager.m_variable);
      _X.m_object = 0;
      if ( v94 )
      {
        _X.m_object = v94;
        _InterlockedExchangeAdd(&v94->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v514,
        compiler,
        (vostok::shared_string)_X.m_object);
    }
    vostok::render::effect_compiler::set_texture(
      compiler,
      (const char *)&stru_966A14,
      "engine/test_grass_motion_mask",
      0,
      (bool)v471,
      0xFFFFFFFF);
    if ( (v475 & 0x20000000) != 0 && vostok::render::custom_config_value::value_exists(&stru_967E3C, v471) )
    {
      v96 = vostok::render::custom_config_value::operator[](v95, (const char *)&stru_967E3C);
      vostok::render::effect_compiler::set_texture(
        compiler,
        "t_transparency",
        (const char *)v96->data,
        0,
        (bool)v471,
        0xFFFFFFFF);
    }
    if ( (v475 & 0x40000) != 0 )
    {
      _X.m_object = (vostok::strings::shared::profile *)vostok::render::custom_config_value::operator[](
                                                          v95,
                                                          "use_diffuse_color_mask_texture")->data;
      v98 = vostok::strings::shared::manager::string(v97, (const char *)s_manager.m_variable);
      v99 = 0;
      if ( v98
        && (v99 = v98,
            _InterlockedExchangeAdd(&v98->m_reference_count, 1u),
            vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
      {
        v100 = (const char *)&v98[1];
      }
      else
      {
        v100 = 0;
      }
      vostok::render::effect_compiler::set_texture(
        compiler,
        "t_diffuse_color_mask",
        v100,
        out_texture,
        (bool)v471,
        num_last_mips_used);
      if ( v99 )
      {
        v101 = (vostok::render::custom_config_value *)_InterlockedExchangeAdd(&v99->m_reference_count, 0xFFFFFFFF);
        if ( !v101 )
        {
          _X.m_object = v99;
          vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
        }
      }
      if ( (v475 & 0x80000) != 0 )
      {
        v102 = vostok::render::custom_config_value::operator[](v101, "constant_diffuse_masked_hue");
        v479 = vostok::render::custom_config_value::operator<float> float(v103, (int)v102) * 3.1415927;
        v500 = sinf(v479);
        v104 = cosf(v479);
        *(_QWORD *)&result_in_case_of_zero.x = 0;
        v105 = 1.0 - v104;
        LODWORD(result_in_case_of_zero.z) = clear_value;
        v501 = v105;
        object.x = 1.0 - v105;
        object.y = v501 - v500;
        object.z = v500 + v501;
        vostok::math::normalize_safe(&object, &v492, (vostok::math::float3 *)&result_in_case_of_zero);
        v469.m_object = (vostok::strings::shared::profile *)"hue_matrix_component_x";
        v106 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
        _X.m_object = 0;
        if ( v106 )
        {
          _X.m_object = v106;
          _InterlockedExchangeAdd(&v106->m_reference_count, 1u);
        }
        v67 = compiler;
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v492,
          compiler,
          (vostok::shared_string)_X.m_object);
        _X.m_object = v107;
        v510.x = v492.z;
        v469.m_object = (vostok::strings::shared::profile *)"hue_matrix_component_y";
        *(_QWORD *)&v510.elements[1] = *(_QWORD *)&v492.x;
        v108 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v107,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        if ( v108 )
        {
          _X.m_object = v108;
          _InterlockedExchangeAdd(&v108->m_reference_count, 1u);
        }
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v510,
          compiler,
          (vostok::shared_string)_X.m_object);
        _X.m_object = v109;
        v518 = *(_QWORD *)&v492.elements[1];
        v469.m_object = (vostok::strings::shared::profile *)"hue_matrix_component_z";
        x = v492.x;
        v110 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v109,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        if ( v110 )
        {
          _X.m_object = v110;
          _InterlockedExchangeAdd(&v110->m_reference_count, 1u);
        }
        v111 = (vostok::math::float3 *)&v518;
      }
      else if ( vostok::render::custom_config_value::value_exists(&stru_968AAC, v471) )
      {
        v113 = vostok::render::custom_config_value::operator[](v112, (const char *)&stru_968AAC);
        vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v114, &v528, (int)v113);
        si128 = _mm_load_si128((const __m128i *)&v528);
        _X.m_object = v116;
        v469.m_object = (vostok::strings::shared::profile *)"constant_diffuse_mask_color";
        v533 = si128;
        v117 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v116,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        if ( v117 )
        {
          _X.m_object = v117;
          _InterlockedExchangeAdd(&v117->m_reference_count, 1u);
        }
        v111 = (vostok::math::float3 *)&v533;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v112;
        v469.m_object = (vostok::strings::shared::profile *)"constant_diffuse_mask_color";
        memset(&v511, 0, sizeof(v511));
        v118 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v112,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        if ( v118 )
        {
          _X.m_object = v118;
          _InterlockedExchangeAdd(&v118->m_reference_count, 1u);
        }
        v111 = &v511;
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(v111, v67, (vostok::shared_string)_X.m_object);
    }
    if ( (v475 & 0x200000) != 0
      && vostok::render::custom_config_value::value_exists(&stru_968AEC, v471)
      && vostok::render::custom_config_value::value_exists(&stru_968B08, v471)
      && vostok::render::custom_config_value::value_exists(&stru_968B20, v471) )
    {
      v119 = (const char *)vostok::render::custom_config_value::operator[](v95, "normal_waves_texture")->data;
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = v120;
      vostok::shared_string::shared_string((vostok::shared_string *)&v469, v119);
      LOBYTE(v121) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v122,
        v121,
        compiler,
        "t_normal_waves",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
      v124 = vostok::render::custom_config_value::operator[](v123, (const char *)&stru_968B20);
      v482 = vostok::render::custom_config_value::operator<float> float(v125, (int)v124);
      v127 = vostok::render::custom_config_value::operator[](v126, (const char *)&stru_968B08);
      v479 = vostok::render::custom_config_value::operator<float> float(v128, (int)v127);
      v130 = vostok::render::custom_config_value::operator[](v129, (const char *)&stru_968AEC);
      v513.x = vostok::render::custom_config_value::operator<float> float(v131, (int)v130);
      _X.m_object = v132;
      v513.y = v479;
      v513.z = v482;
      vostok::shared_string::shared_string((vostok::shared_string *)&_X, "normal_waves_parameters");
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v513,
        compiler,
        (vostok::shared_string)_X.m_object);
      v67 = compiler;
    }
    _X.m_object = (vostok::strings::shared::profile *)v95;
    v469.m_object = (vostok::strings::shared::profile *)"smoothness_multiplier";
    v133 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v95,
             (const char *)s_manager.m_variable);
    _X.m_object = 0;
    if ( v133 )
    {
      _X.m_object = v133;
      v134 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v133->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>(
      (const float *)&v505,
      v134,
      v67,
      (vostok::shared_string)_X.m_object);
    if ( (v473[1] & 1) != 0 )
    {
      v136 = vostok::render::custom_config_value::operator[](v135, "texture_diffuse");
      vostok::render::effect_compiler::set_texture(
        v67,
        &stru_963F84.m_name.m_string.m_buffer[116],
        (const char *)v136->data,
        out_texture,
        (bool)v471,
        num_last_mips_used);
    }
    if ( v473[2] < 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_968B74, v471) )
      {
        vostok::render::custom_config_value::operator[](v135, (const char *)&stru_968B74);
        _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v137 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)num_last_mips_used,
                 (const char *)s_manager.m_variable);
        v469.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &v469,
          v137);
        LOBYTE(v138) = (_BYTE)out_texture;
        vostok::render::effect_compiler::set_texture(
          v139,
          v138,
          v67,
          "t_alphablended_diffuse",
          (vostok::shared_string)v469.m_object,
          (unsigned int)_X.m_object);
      }
      if ( (v473[3] & 1) != 0 && vostok::render::custom_config_value::value_exists(&stru_968BAC, v471) )
      {
        vostok::render::custom_config_value::operator[](v135, (const char *)&stru_968BAC);
        _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v140 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)num_last_mips_used,
                 (const char *)s_manager.m_variable);
        v469.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &v469,
          v140);
        LOBYTE(v141) = (_BYTE)out_texture;
        vostok::render::effect_compiler::set_texture(
          v142,
          v141,
          v67,
          "t_alphablended_normal",
          (vostok::shared_string)v469.m_object,
          (unsigned int)_X.m_object);
      }
    }
    if ( LOBYTE(vostok::render::custom_config_value::operator[](v135, (const char *)&stru_9687D4)->data) )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_968BE0, v471) )
      {
        v144 = vostok::render::custom_config_value::operator[](v143, (const char *)&stru_968BE0);
        v479 = vostok::render::custom_config_value::operator<float> float(v145, (int)v144);
        _X.m_object = v146;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BE0;
        v147 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v146,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v147);
        v149 = &v479;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v143;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BE0;
        v503 = clear_value;
        v150 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v150);
        v149 = (const float *)&v503;
      }
      vostok::render::effect_compiler::set_constant<float>(v149, v148, v67, (vostok::shared_string)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_968BF4, v471) )
      {
        v152 = vostok::render::custom_config_value::operator[](v151, (const char *)&stru_968BF4);
        v154 = vostok::render::custom_config_value::operator<float> float(v153, (int)v152);
        _X.m_object = v155;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BF4;
        v479 = v154 * 0.0055555557 * 3.1415927;
        v156 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v155,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v156);
        v158 = &v479;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v151;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BF4;
        v496 = 0.0;
        v159 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v151,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v159);
        v158 = &v496;
      }
      vostok::render::effect_compiler::set_constant<float>(v158, v157, v67, (vostok::shared_string)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_968C0C, v471) )
      {
        v161 = vostok::render::custom_config_value::operator[](v160, (const char *)&stru_968C0C);
        vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v162, &v526, (int)v161);
        v163 = _mm_load_si128((const __m128i *)&v526);
        _X.m_object = v164;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968C0C;
        v532 = v163;
        v165 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v165);
        v166 = (vostok::math::float4 *)&v532;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v160;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968C0C;
        LODWORD(v523.x) = clear_value;
        LODWORD(v523.y) = clear_value;
        LODWORD(v523.z) = clear_value;
        LODWORD(v523.w) = clear_value;
        v167 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v160,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v167);
        v166 = &v523;
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)v166,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    if ( vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_960A44.destroyer,
           v471) )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_968C28, v471) )
      {
        v170 = vostok::render::custom_config_value::operator[](v169, "detailed_bend_parameters_branch_amplitude");
        v482 = vostok::render::custom_config_value::operator<float> float(v171, (int)v170);
        v173 = vostok::render::custom_config_value::operator[](v172, "detailed_bend_parameters_leaf_amplitude");
        v479 = vostok::render::custom_config_value::operator<float> float(v174, (int)v173);
        v176 = vostok::render::custom_config_value::operator[](v175, (const char *)&stru_968C28);
        v515.x = vostok::render::custom_config_value::operator<float> float(v177, (int)v176);
        _X.m_object = v178;
        v515.y = v479;
        v469.m_object = (vostok::strings::shared::profile *)"detailed_bending_parameters";
        v515.z = v482;
        v179 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v178,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v179);
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v515,
          v67,
          (vostok::shared_string)_X.m_object);
      }
      _X.m_object = (vostok::strings::shared::profile *)v169;
      v469.m_object = (vostok::strings::shared::profile *)&stru_966874;
      v498 = clear_value;
      v180 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
      _X.m_object = 0;
      if ( v180 )
      {
        _X.m_object = v180;
        _InterlockedExchangeAdd(&v180->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<float>(
        (const float *)&v498,
        v181,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    if ( (v474 & 0x8000000) != 0 && vostok::render::custom_config_value::value_exists(&stru_968CBC, v471) )
    {
      vostok::render::custom_config_value::operator[](v168, (const char *)&stru_968CBC);
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v182 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v182);
      LOBYTE(v183) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v184,
        v183,
        v67,
        "t_vertex_blended_mask",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
    }
    LOBYTE(v168) = HIBYTE(v474);
    v185 = (v474 & 0x4000000) != 0;
    v473[0] = v185;
    if ( (v474 & 0x4000000) != 0 || (v474 & 0x10000000) != 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_968CF0, v471)
        && vostok::render::custom_config_value::value_exists(&stru_968D10, v471)
        && vostok::render::custom_config_value::value_exists(&stru_968D30, v471) )
      {
        v186 = vostok::render::custom_config_value::operator[](v168, (const char *)&stru_968D30);
        v482 = vostok::render::custom_config_value::operator<float> float(v187, (int)v186);
        v189 = vostok::render::custom_config_value::operator[](v188, (const char *)&stru_968D10);
        v479 = vostok::render::custom_config_value::operator<float> float(v190, (int)v189);
        v192 = vostok::render::custom_config_value::operator[](v191, (const char *)&stru_968CF0);
        v520.x = vostok::render::custom_config_value::operator<float> float(v193, (int)v192);
        _X.m_object = v194;
        v520.y = v479;
        v469.m_object = (vostok::strings::shared::profile *)"vertex_blend_parameters";
        v520.z = v482;
        v195 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v194,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v195);
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v520,
          v67,
          (vostok::shared_string)_X.m_object);
      }
      v185 = v473[0];
    }
    if ( v185 && vostok::render::custom_config_value::value_exists(&stru_968D68, v471) )
    {
      vostok::render::custom_config_value::operator[](v168, (const char *)&stru_968D68);
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v196 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v196);
      LOBYTE(v197) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v198,
        v197,
        v67,
        "t_vertex_blended_diffuse",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
    }
    if ( (v474 & 0x10000000) != 0 && vostok::render::custom_config_value::value_exists(&stru_968DA4, v471) )
    {
      vostok::render::custom_config_value::operator[](v168, (const char *)&stru_968DA4);
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v199 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v199);
      LOBYTE(v200) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v201,
        v200,
        v67,
        "t_vertex_blended_normal",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
    }
    v202 = vostok::render::custom_config_value::operator[](v168, (const char *)&stru_967F74);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v203, &v530, (int)v202);
    v509 = (vostok::math::float4)_mm_load_si128((const __m128i *)&v530);
    v509.w = 0.0;
    if ( (v474 & 3) != 0 )
    {
      v205 = (vostok::strings::shared::profile *)vostok::render::custom_config_value::operator[](
                                                   v204,
                                                   "texture_cubemap")->data;
      _X.m_object = 0;
      if ( !strcmp((const char *)v205, (const char *)&buf) )
        v469.m_object = (vostok::strings::shared::profile *)"cubemap/reflect_blue";
      else
        v469.m_object = v205;
      vostok::render::effect_compiler::set_texture(
        v67,
        "t_cubemap",
        (const char *)v469.m_object,
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)_X.m_object,
        (bool)v471,
        0xFFFFFFFF);
      if ( (v473[3] & 4) != 0 )
      {
        v207 = vostok::render::custom_config_value::operator[](v206, "texture_cubemap_mask");
        vostok::render::effect_compiler::set_texture(
          v67,
          "t_cubemap_mask",
          (const char *)v207->data,
          0,
          (bool)v471,
          0xFFFFFFFF);
      }
      vostok::render::effect_compiler::set_texture(
        v67,
        &stru_9656C8.m_name.m_string.m_buffer[208],
        "$user$frame_luminance",
        0,
        (bool)v471,
        0xFFFFFFFF);
      if ( vostok::render::custom_config_value::value_exists(&stru_968BE0, v471) )
      {
        v209 = vostok::render::custom_config_value::operator[](v208, (const char *)&stru_968BE0);
        v479 = vostok::render::custom_config_value::operator<float> float(v210, (int)v209);
        _X.m_object = v211;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BE0;
        v212 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v211,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v212);
        v214 = &v479;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v208;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BE0;
        v502 = clear_value;
        v215 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v215);
        v214 = (const float *)&v502;
      }
      vostok::render::effect_compiler::set_constant<float>(v214, v213, v67, (vostok::shared_string)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_968BF4, v471) )
      {
        v217 = vostok::render::custom_config_value::operator[](v216, (const char *)&stru_968BF4);
        v219 = vostok::render::custom_config_value::operator<float> float(v218, (int)v217);
        _X.m_object = v220;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BF4;
        v479 = v219 * 0.0055555557 * 3.1415927;
        v221 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v220,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v221);
        v223 = &v479;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v216;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968BF4;
        v504 = 0.0;
        v224 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v216,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v224);
        v223 = &v504;
      }
      vostok::render::effect_compiler::set_constant<float>(v223, v222, v67, (vostok::shared_string)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_968C0C, v471) )
      {
        v226 = vostok::render::custom_config_value::operator[](v225, (const char *)&stru_968C0C);
        vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v227, &v527, (int)v226);
        v228 = _mm_load_si128((const __m128i *)&v527);
        _X.m_object = v229;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968C0C;
        v529 = v228;
        v230 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v230);
        v231 = (vostok::math::float4 *)&v529;
      }
      else
      {
        _X.m_object = (vostok::strings::shared::profile *)v225;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968C0C;
        LODWORD(v524.x) = clear_value;
        LODWORD(v524.y) = clear_value;
        LODWORD(v524.z) = clear_value;
        LODWORD(v524.w) = clear_value;
        v232 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v225,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v232);
        v231 = &v524;
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)v231,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    if ( (v473[1] & 8) != 0 )
    {
      vostok::render::custom_config_value::operator[](v204, "texture_normal");
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v233 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v233);
      LOBYTE(v234) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v235,
        v234,
        v67,
        "t_normal",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
    }
    if ( (v473[3] & 2) != 0 )
    {
      v236 = vostok::render::custom_config_value::operator[](v204, "constant_sequence_play_speed");
      v483 = vostok::render::custom_config_value::operator<float> float(v237, (int)v236);
      v239 = vostok::render::custom_config_value::operator[](v238, "constant_sequence_start_frame_index");
      v482 = vostok::render::custom_config_value::operator<float> float(v240, (int)v239);
      v242 = vostok::render::custom_config_value::operator[](v241, "constant_sequence_array_height");
      v479 = vostok::render::custom_config_value::operator<float> float(v243, (int)v242);
      v245 = vostok::render::custom_config_value::operator[](v244, "constant_sequence_array_width");
      v522.x = vostok::render::custom_config_value::operator<float> float(v246, (int)v245);
      v522.y = v479;
      _X.m_object = v247;
      v522.z = v482;
      v469.m_object = (vostok::strings::shared::profile *)"sequence_parameters";
      v522.w = v483;
      v248 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)v247,
               (const char *)s_manager.m_variable);
      _X.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &_X,
        v248);
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&v522,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    if ( (v473[1] & 0x10) != 0 )
    {
      LODWORD(v494.x) = clear_value;
      LODWORD(v494.y) = clear_value;
      LODWORD(v494.z) = clear_value;
      LODWORD(v494.w) = clear_value;
      if ( vostok::render::custom_config_value::value_exists(&stru_968ED0, v471) )
      {
        vostok::render::custom_config_value::operator[](v249, (const char *)&stru_968ED0);
        _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v250 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)num_last_mips_used,
                 (const char *)s_manager.m_variable);
        v469.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &v469,
          v250);
        LOBYTE(v251) = (_BYTE)out_texture;
        vostok::render::effect_compiler::set_texture(
          v252,
          v251,
          v67,
          "t_detail_normal",
          (vostok::shared_string)v469.m_object,
          (unsigned int)_X.m_object);
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_968EF8, v471) )
      {
        v254 = vostok::render::custom_config_value::operator[](v253, (const char *)&stru_968EF8);
        v494.x = vostok::render::custom_config_value::operator<float> float(v255, (int)v254);
        v494.y = v494.x;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_968F0C, v471) )
      {
        v257 = vostok::render::custom_config_value::operator[](v256, (const char *)&stru_968F0C);
        v494.z = vostok::render::custom_config_value::operator<float> float(v258, (int)v257);
        v494.w = v494.z;
      }
      _X.m_object = (vostok::strings::shared::profile *)v256;
      v469.m_object = (vostok::strings::shared::profile *)"detail_normal_parameters";
      v259 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)v256,
               (const char *)s_manager.m_variable);
      _X.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &_X,
        v259);
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&v494,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    if ( (v473[1] & 0x20) != 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_968F3C, v471) )
      {
        vostok::render::custom_config_value::operator[](v260, (const char *)&stru_968F3C);
        _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v261 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)num_last_mips_used,
                 (const char *)s_manager.m_variable);
        v469.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &v469,
          v261);
        LOBYTE(v262) = (_BYTE)out_texture;
        vostok::render::effect_compiler::set_texture(
          v263,
          v262,
          v67,
          "t_detail",
          (vostok::shared_string)v469.m_object,
          (unsigned int)_X.m_object);
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_968F60, v471) )
      {
        v264 = vostok::render::custom_config_value::operator[](v204, (const char *)&stru_968F60);
        v483 = vostok::render::custom_config_value::operator<float> float(v265, (int)v264);
        _X.m_object = v266;
        v469.m_object = (vostok::strings::shared::profile *)"ditail_texture_tile";
        v267 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v266,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v267);
        vostok::render::effect_compiler::set_constant<float>(&v483, v268, v67, (vostok::shared_string)_X.m_object);
      }
    }
    if ( (v473[1] & 4) != 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_968F94, v471) )
      {
        v270 = vostok::render::custom_config_value::operator[](v269, (const char *)&stru_968F94);
        v483 = vostok::render::custom_config_value::operator<float> float(v271, (int)v270);
        _X.m_object = v272;
        v469.m_object = (vostok::strings::shared::profile *)&stru_968F94;
        v273 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v273);
        vostok::render::effect_compiler::set_constant<float>(&v483, v274, v67, (vostok::shared_string)_X.m_object);
      }
      vostok::render::custom_config_value::operator[](v269, "texture_bump");
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = v275;
      v276 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)v275,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v276);
      LOBYTE(v277) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v278,
        v277,
        v67,
        "t_height_map",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
    }
    v484.x = 0.0;
    LODWORD(v484.y) = clear_value;
    if ( v473[1] < 0 )
    {
      vostok::render::custom_config_value::operator[](v204, "texture_specular_intensity");
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v279 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v279);
      LOBYTE(v280) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v281,
        v280,
        v67,
        "t_specular_intensity",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_967FCC, v471) )
      {
        v282 = vostok::render::custom_config_value::operator[](v204, (const char *)&stru_967FCC);
        v484.x = vostok::render::custom_config_value::operator<float> float(v283, (int)v282);
        v285 = vostok::render::custom_config_value::operator[](v284, "constant_specular_intensity_max");
        v287 = vostok::render::custom_config_value::operator<float> float(v286, (int)v285);
        v484.y = v287 - v484.x;
      }
    }
    _X.m_object = (vostok::strings::shared::profile *)v204;
    v469.m_object = (vostok::strings::shared::profile *)"specular_intensity_ranges";
    v288 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v204,
             (const char *)s_manager.m_variable);
    _X.m_object = 0;
    if ( v288 )
    {
      _X.m_object = v288;
      _InterlockedExchangeAdd(&v288->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&v484,
      v67,
      (vostok::shared_string)_X.m_object);
    if ( vostok::render::custom_config_value::value_exists(&stru_968028, v471)
      && vostok::render::custom_config_value::value_exists(&stru_968040, v471) )
    {
      v290 = vostok::render::custom_config_value::operator[](v289, (const char *)&stru_968040);
      vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(v291, &v512, (int)v290);
      v293 = vostok::render::custom_config_value::operator[](v292, (const char *)&stru_968028);
      vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v294, &v525, (int)v293);
      _X.m_object = v295;
      v469.m_object = (vostok::strings::shared::profile *)"specular_color_parameter";
      v487.x = v525.x * v512.x;
      v487.y = v512.y * v525.y;
      v487.z = v512.z * v525.z;
      v296 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)v295,
               (const char *)s_manager.m_variable);
      _X.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &_X,
        v296);
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v487,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    _X.m_object = (vostok::strings::shared::profile *)v289;
    v469.m_object = (vostok::strings::shared::profile *)&stru_961604;
    v297 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v289,
             (const char *)s_manager.m_variable);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      v297);
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&v509,
      v67,
      (vostok::shared_string)_X.m_object);
    v491.z = 0.0;
    memset(&v485, 0, sizeof(v485));
    if ( (v473[2] & 2) != 0 )
    {
      vostok::render::custom_config_value::operator[](v298, "texture_roughness");
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v299 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v299);
      LOBYTE(v300) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v301,
        v300,
        v67,
        "t_roughness",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_9680A0, v471) )
      {
        v303 = vostok::render::custom_config_value::operator[](v302, (const char *)&stru_9680A0);
        v485.z = vostok::render::custom_config_value::operator<float> float(v304, (int)v303);
        v306 = vostok::render::custom_config_value::operator[](v305, "constant_roughness_max");
        v308 = vostok::render::custom_config_value::operator<float> float(v307, (int)v306);
        v485.w = v308 - v485.z;
      }
    }
    else if ( vostok::render::custom_config_value::value_exists(&stru_9680D0, v471) )
    {
      v309 = vostok::render::custom_config_value::operator[](v302, (const char *)&stru_9680D0);
      v485.z = vostok::render::custom_config_value::operator<float> float(v310, (int)v309);
    }
    if ( (v473[2] & 1) != 0 )
    {
      vostok::render::custom_config_value::operator[](v302, "texture_fresnel");
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v311 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)num_last_mips_used,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v311);
      LOBYTE(v312) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v313,
        v312,
        v67,
        "t_fresnel",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_968100, v471) )
      {
        v315 = vostok::render::custom_config_value::operator[](v314, (const char *)&stru_968100);
        v485.x = vostok::render::custom_config_value::operator<float> float(v316, (int)v315);
        v318 = vostok::render::custom_config_value::operator[](v317, "constant_fresnel_max");
        v320 = vostok::render::custom_config_value::operator<float> float(v319, (int)v318);
        v485.y = v320 - v485.x;
      }
    }
    else if ( vostok::render::custom_config_value::value_exists(&stru_968130, v471) )
    {
      v321 = vostok::render::custom_config_value::operator[](v314, (const char *)&stru_968130);
      v485.x = vostok::render::custom_config_value::operator<float> float(v322, (int)v321);
    }
    _X.m_object = (vostok::strings::shared::profile *)v314;
    v469.m_object = (vostok::strings::shared::profile *)"specular_fresnel_roughness_parameters";
    v323 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v314,
             (const char *)s_manager.m_variable);
    _X.m_object = 0;
    if ( v323 )
    {
      _X.m_object = v323;
      _InterlockedExchangeAdd(&v323->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&v485,
      v67,
      (vostok::shared_string)_X.m_object);
    if ( v480 )
    {
      vostok::render::custom_config_value::operator[](v324, "texture_translucency");
      _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
      v469.m_object = v325;
      v326 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)v325,
               (const char *)s_manager.m_variable);
      v469.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &v469,
        v326);
      LOBYTE(v327) = (_BYTE)out_texture;
      vostok::render::effect_compiler::set_texture(
        v328,
        v327,
        v67,
        "t_translucency",
        (vostok::shared_string)v469.m_object,
        (unsigned int)_X.m_object);
      v330 = vostok::render::custom_config_value::operator[](v329, "constant_translucency");
      v491.z = vostok::render::custom_config_value::operator<float> float(v331, (int)v330);
    }
    if ( (v473[2] & 0x20) != 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_96900C, v471) )
      {
        v333 = vostok::render::custom_config_value::operator[](v332, (const char *)&stru_96900C);
        *(float *)&v481 = vostok::render::custom_config_value::operator<float> float(v334, (int)v333);
      }
      else
      {
        v481 = (unsigned int)clear_value;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_969028, v471) )
      {
        v336 = vostok::render::custom_config_value::operator[](v335, (const char *)&stru_969028);
        *(float *)&v490 = vostok::render::custom_config_value::operator<float> float(v337, (int)v336);
      }
      else
      {
        v490 = (unsigned int)clear_value;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_969044, v471) )
      {
        v339 = vostok::render::custom_config_value::operator[](v338, (const char *)&stru_969044);
        *(float *)&v488 = vostok::render::custom_config_value::operator<float> float(v340, (int)v339);
      }
      else
      {
        v488 = (unsigned int)clear_value;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_969060, v471) )
      {
        v342 = vostok::render::custom_config_value::operator[](v341, (const char *)&stru_969060);
        v483 = vostok::render::custom_config_value::operator<float> float(v343, (int)v342);
        v344 = LODWORD(v483);
      }
      else
      {
        v344 = (unsigned int)clear_value;
      }
      _X.m_object = (vostok::strings::shared::profile *)v341;
      *(_QWORD *)&v521.x = __PAIR64__(v488, v344);
      v469.m_object = (vostok::strings::shared::profile *)"packed_variation_mask_parameters";
      *(_QWORD *)&v521.elements[2] = __PAIR64__(v481, v490);
      v345 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
      _X.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &_X,
        v345);
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&v521,
        v67,
        (vostok::shared_string)_X.m_object);
      if ( vostok::render::custom_config_value::value_exists(&stru_9690A8, v471) )
      {
        v347 = vostok::render::custom_config_value::operator[](v346, (const char *)&stru_9690A8);
        vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v348, &v531, (int)v347);
        v349 = (vostok::math::float4)_mm_load_si128((const __m128i *)&v531);
        _X.m_object = v350;
        v469.m_object = (vostok::strings::shared::profile *)"variation_color";
        v493 = v349;
        v351 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)v350,
                 (const char *)s_manager.m_variable);
        _X.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &_X,
          v351);
        vostok::render::effect_compiler::set_constant<vostok::math::float4>(
          (vostok::render::effect_constant_storage *)&v493,
          v67,
          (vostok::shared_string)_X.m_object);
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_968958, v471) )
      {
        vostok::render::custom_config_value::operator[](v352, (const char *)&stru_968958);
        _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
        v353 = vostok::strings::shared::manager::string(
                 (vostok::strings::shared::manager *)num_last_mips_used,
                 (const char *)s_manager.m_variable);
        v469.m_object = 0;
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
          &v469,
          v353);
        LOBYTE(v354) = (_BYTE)out_texture;
        vostok::render::effect_compiler::set_texture(
          v355,
          v354,
          v67,
          "t_variation_mask",
          (vostok::shared_string)v469.m_object,
          (unsigned int)_X.m_object);
      }
      else
      {
        vostok::render::effect_compiler::set_texture(
          v67,
          "t_variation_mask",
          (const char *)&buf,
          0,
          (bool)v471,
          0xFFFFFFFF);
      }
    }
    if ( (v475 & 0x100000) != 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_9690E8, v471) )
      {
        v357 = vostok::render::custom_config_value::operator[](v356, (const char *)&stru_9690E8);
        v495.x = vostok::render::custom_config_value::operator<float> float(v358, (int)v357);
      }
      else
      {
        v495.x = 0.0;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_969108, v471) )
      {
        v360 = vostok::render::custom_config_value::operator[](v359, (const char *)&stru_969108);
        v495.y = vostok::render::custom_config_value::operator<float> float(v361, (int)v360);
      }
      else
      {
        v495.y = 0.0;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_969128, v471) )
      {
        v363 = vostok::render::custom_config_value::operator[](v362, (const char *)&stru_969128);
        v495.z = vostok::render::custom_config_value::operator<float> float(v364, (int)v363);
      }
      else
      {
        v495.z = 0.0;
      }
      if ( vostok::render::custom_config_value::value_exists(&stru_969144, v471) )
      {
        v366 = vostok::render::custom_config_value::operator[](v365, (const char *)&stru_969144);
        v495.w = vostok::render::custom_config_value::operator<float> float(v367, (int)v366);
      }
      else
      {
        v495.w = 0.0;
      }
      _X.m_object = (vostok::strings::shared::profile *)v365;
      v469.m_object = (vostok::strings::shared::profile *)"uv_scrolling_parameters";
      v368 = vostok::strings::shared::manager::string(
               (vostok::strings::shared::manager *)v365,
               (const char *)s_manager.m_variable);
      _X.m_object = 0;
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        &_X,
        v368);
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&v495,
        v67,
        (vostok::shared_string)_X.m_object);
    }
    _X.m_object = (vostok::strings::shared::profile *)v324;
    v469.m_object = (vostok::strings::shared::profile *)"solid_material_params";
    v369 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      v369);
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&v491,
      compiler,
      (vostok::shared_string)_X.m_object);
    _X.m_object = (vostok::strings::shared::profile *)compiler;
    vostok::render::effect_compiler::end_pass(v370);
    vostok::render::effect_compiler::end_technique(v371);
    ++v486;
  }
  while ( v486 < 2 );
  v491.x = 0.0;
  *(_QWORD *)&v491.elements[1] = 0x400000000LL;
  v491.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966A14.m_name.m_string.m_buffer[92],
    "fill_reflective_shadow_map_backed",
    (const char *)&v491,
    v471,
    compiler,
    v472,
    custom_config);
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v372);
  vostok::render::effect_compiler::end_technique(v373);
  v484.x = 0.0;
  *(_QWORD *)&v484.elements[1] = 0x400000000LL;
  v484.w = 0.0;
  LOBYTE(v484.x) = (int)vostok::render::custom_config_value::operator[](v374, (const char *)&stru_9667A8)->data & 1;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_9666F4,
    (const char *)&stru_9666F4,
    (const char *)&v484,
    v471,
    compiler,
    v472,
    custom_config);
  vostok::render::effect_compiler::set_depth(v375, 0, 0, D3D11_COMPARISON_LESS_EQUAL);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    (D3D11_STENCIL_OP)v471,
    D3D11_STENCIL_OP_KEEP);
  if ( (LOBYTE(v484.x) & 1) != 0 )
  {
    vostok::render::custom_config_value::operator[](v376, "texture_diffuse");
    _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
    v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
    v377 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)num_last_mips_used,
             (const char *)s_manager.m_variable);
    v469.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &v469,
      v377);
    LOBYTE(v378) = (_BYTE)out_texture;
    vostok::render::effect_compiler::set_texture(
      v379,
      v378,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (vostok::shared_string)v469.m_object,
      (unsigned int)_X.m_object);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967F74, v471) )
  {
    v381 = vostok::render::custom_config_value::operator[](v380, (const char *)&stru_967F74);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v382, &v493, (int)v381);
    v383 = (vostok::math::float4)_mm_load_si128((const __m128i *)&v493);
    _X.m_object = v384;
    v469.m_object = (vostok::strings::shared::profile *)"diffuse_color_parameter";
    v493 = v383;
    v385 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v384,
             (const char *)s_manager.m_variable);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      v385);
    v386 = (const vostok::math::float3 *)&v493;
  }
  else
  {
    _X.m_object = (vostok::strings::shared::profile *)v380;
    v469.m_object = (vostok::strings::shared::profile *)"diffuse_color_parameter";
    LODWORD(v487.x) = clear_value;
    LODWORD(v487.y) = clear_value;
    LODWORD(v487.z) = clear_value;
    v387 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      v387);
    v386 = &v487;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    v386,
    compiler,
    (vostok::shared_string)_X.m_object);
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v388);
  vostok::render::effect_compiler::end_technique(v389);
  v484.x = 0.0;
  *(_QWORD *)&v484.elements[1] = 0x400000000LL;
  v484.w = 0.0;
  LOBYTE(v484.x) = (int)vostok::render::custom_config_value::operator[](v390, (const char *)&stru_9667A8)->data & 1;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "fill_reflective_shadow_map",
    (const char *)&v484,
    v471,
    compiler,
    v472,
    custom_config);
  if ( (LOBYTE(v484.x) & 1) != 0 )
  {
    vostok::render::custom_config_value::operator[](v391, "texture_diffuse");
    _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
    v469.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
    v392 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)num_last_mips_used,
             (const char *)s_manager.m_variable);
    v469.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &v469,
      v392);
    LOBYTE(v393) = (_BYTE)out_texture;
    vostok::render::effect_compiler::set_texture(
      v394,
      v393,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (vostok::shared_string)v469.m_object,
      (unsigned int)_X.m_object);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967F74, v471) )
  {
    v396 = vostok::render::custom_config_value::operator[](v395, (const char *)&stru_967F74);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v397, &v493, (int)v396);
    v398 = (vostok::math::float4)_mm_load_si128((const __m128i *)&v493);
    _X.m_object = v399;
    v469.m_object = (vostok::strings::shared::profile *)"diffuse_color_parameter";
    v493 = v398;
    v400 = (const vostok::math::float3 *)&v493;
    v401 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  }
  else
  {
    _X.m_object = (vostok::strings::shared::profile *)v395;
    v469.m_object = (vostok::strings::shared::profile *)"diffuse_color_parameter";
    LODWORD(v487.x) = clear_value;
    LODWORD(v487.y) = clear_value;
    LODWORD(v487.z) = clear_value;
    v400 = &v487;
    v401 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v395,
             (const char *)s_manager.m_variable);
  }
  _X.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &_X,
    v401);
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    v400,
    compiler,
    (vostok::shared_string)_X.m_object);
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v402);
  vostok::render::effect_compiler::end_technique(v403);
  v484.x = 0.0;
  *(_QWORD *)&v484.elements[1] = 0x400000000LL;
  v484.w = 0.0;
  if ( LOBYTE(vostok::render::custom_config_value::operator[](v404, (const char *)&stru_960A14.type)->data) )
    LOBYTE(v484.elements[1]) = 4
                             * (((LOBYTE(vostok::render::custom_config_value::operator[](v405, "use_emissive_map")->data) != 0)
                               + 1)
                              & 3);
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "gbuffer_emissive_pass",
    (const char *)&v484,
    v471,
    compiler,
    v472,
    custom_config);
  vostok::render::effect_compiler::set_depth(v406, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    (D3D11_STENCIL_OP)v471,
    D3D11_STENCIL_OP_KEEP);
  v480 = (LOBYTE(v484.elements[1]) >> 2) & 3;
  if ( v480 )
  {
    v408 = vostok::render::custom_config_value::operator[](v407, (const char *)&stru_966754);
    v483 = vostok::render::custom_config_value::operator<float> float(v409, (int)v408);
    v411 = vostok::render::custom_config_value::operator[](v410, (const char *)&stru_966774);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v412, &v509, (int)v411);
    v413 = _mm_load_si128((const __m128i *)&v509);
    LODWORD(v484.w) = v413.m128i_i32[3];
    _X.m_object = v414;
    v484.x = v509.x * v483;
    v469.m_object = (vostok::strings::shared::profile *)"solid_emission_color";
    v484.y = *(float *)&v413.m128i_i32[1] * v483;
    v484.z = v483 * *(float *)&v413.m128i_i32[2];
    v415 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      v415);
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&v484,
      compiler,
      (vostok::shared_string)_X.m_object);
  }
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    (D3D11_BLEND_OP)v471);
  if ( v480 == 2 )
  {
    vostok::render::custom_config_value::operator[](v416, "texture_emissive");
    _X.m_object = (vostok::strings::shared::profile *)num_last_mips_used;
    v469.m_object = v417;
    v418 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v417,
             (const char *)s_manager.m_variable);
    v469.m_object = 0;
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
      &v469,
      v418);
    LOBYTE(v419) = (_BYTE)out_texture;
    vostok::render::effect_compiler::set_texture(
      v420,
      v419,
      compiler,
      "t_emission",
      (vostok::shared_string)v469.m_object,
      (unsigned int)_X.m_object);
  }
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass((vostok::render::effect_compiler *)v416);
  vostok::render::effect_compiler::end_technique(v421);
  v485.x = 0.0;
  *(_QWORD *)&v485.elements[1] = 0x400000000LL;
  v485.w = 0.0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, v471) )
    v423 = (char)vostok::render::custom_config_value::operator[](v422, (const char *)&stru_960A44)->data;
  else
    v423 = 0;
  LOBYTE(v485.x) = 2 * (v423 & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, v471) )
    v425 = (char)vostok::render::custom_config_value::operator[](v424, (const char *)&stru_9667A8)->data;
  else
    v425 = 0;
  LOBYTE(v485.x) ^= (v425 ^ LOBYTE(v485.x)) & 1;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    (const char *)&stru_9667A8.destroyer,
    (const char *)&v485,
    v471,
    compiler,
    v472,
    custom_config);
  vostok::render::effect_compiler::set_depth(v426, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
  v481 = 1048576000;
  if ( (LOBYTE(v485.x) & 1) != 0 )
  {
    v428 = vostok::render::custom_config_value::operator[](v427, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v428->data,
      out_texture,
      (bool)v471,
      num_last_mips_used);
  }
  if ( (LOBYTE(v485.x) & 2) != 0 && vostok::render::custom_config_value::value_exists(&stru_9667FC, v471) )
  {
    v429 = vostok::render::custom_config_value::operator[](v427, (const char *)&stru_9667FC);
    *(float *)&v481 = vostok::render::custom_config_value::operator<float> float(v430, (int)v429);
  }
  _X.m_object = (vostok::strings::shared::profile *)v427;
  v469.m_object = (vostok::strings::shared::profile *)&stru_9667FC.type;
  v431 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v427,
           (const char *)s_manager.m_variable);
  _X.m_object = 0;
  if ( v431 )
  {
    _X.m_object = v431;
    v432 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v431->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(
    (const float *)&v481,
    v432,
    compiler,
    (vostok::shared_string)_X.m_object);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v433);
  vostok::render::effect_compiler::end_technique(v434);
  v475 = 4;
  *(_DWORD *)&v473[1] = 0;
  v474 = 0;
  v476 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, v471) )
    v436 = (char)vostok::render::custom_config_value::operator[](v435, (const char *)&stru_960A44)->data;
  else
    v436 = 0;
  v473[1] = 2 * (v436 & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, v471) )
    v438 = (char)vostok::render::custom_config_value::operator[](v437, (const char *)&stru_9667A8)->data;
  else
    v438 = 0;
  v473[1] ^= (v473[1] ^ v438) & 1;
  if ( vostok::render::custom_config_value::value_exists(&stru_96918C, v471) )
    v440 = (char)vostok::render::custom_config_value::operator[](v439, (const char *)&stru_96918C)->data;
  else
    v440 = 0;
  HIBYTE(v475) ^= (HIBYTE(v475) ^ (8 * v440)) & 8;
  if ( vostok::render::custom_config_value::value_exists(&stru_9691A0, v471) )
    v442 = (char)vostok::render::custom_config_value::operator[](v441, (const char *)&stru_9691A0)->data;
  else
    v442 = 0;
  HIBYTE(v475) ^= (HIBYTE(v475) ^ (16 * v442)) & 0x10;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "subsurface_scattering",
    &v473[1],
    v471,
    compiler,
    v472,
    custom_config);
  vostok::render::effect_compiler::set_depth(v443, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
  v481 = 1048576000;
  if ( (v473[1] & 1) != 0 )
  {
    v445 = vostok::render::custom_config_value::operator[](v444, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v445->data,
      out_texture,
      (bool)v471,
      num_last_mips_used);
  }
  if ( (v473[1] & 2) != 0 && vostok::render::custom_config_value::value_exists(&stru_9667FC, v471) )
  {
    v446 = vostok::render::custom_config_value::operator[](v444, (const char *)&stru_9667FC);
    *(float *)&v481 = vostok::render::custom_config_value::operator<float> float(v447, (int)v446);
  }
  _X.m_object = (vostok::strings::shared::profile *)v444;
  v469.m_object = (vostok::strings::shared::profile *)&stru_9667FC.type;
  v448 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v444,
           (const char *)s_manager.m_variable);
  _X.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &_X,
    v448);
  vostok::render::effect_compiler::set_constant<float>(
    (const float *)&v481,
    v449,
    compiler,
    (vostok::shared_string)_X.m_object);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    (bool)v471,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_specular_lighting",
    "$user$accum_specular",
    0,
    (bool)v471,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    (bool)v471,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, (bool)v471, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, (bool)v471, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_sun_translucensy_help_data",
    "$user$sun_translucensy_help_data",
    0,
    (bool)v471,
    0xFFFFFFFF);
  if ( (v475 & 0x8000000) != 0 )
  {
    v451 = vostok::render::custom_config_value::operator[](v450, "texture_thickness");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_thickness",
      (const char *)v451->data,
      0,
      (bool)v471,
      0xFFFFFFFF);
  }
  if ( (v475 & 0x10000000) != 0 )
  {
    v452 = vostok::render::custom_config_value::operator[](v450, "texture_sss_mask");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_sss_mask",
      (const char *)v452->data,
      0,
      (bool)v471,
      0xFFFFFFFF);
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v453);
  vostok::render::effect_compiler::end_technique(v454);
  v485.x = 0.0;
  *(_QWORD *)&v485.elements[1] = 0x400000000LL;
  v485.w = 0.0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, v471) )
    v456 = (char)vostok::render::custom_config_value::operator[](v455, (const char *)&stru_960A44)->data;
  else
    v456 = 0;
  LOBYTE(v485.x) = 2 * (v456 & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, v471) )
    v458 = (char)vostok::render::custom_config_value::operator[](v457, (const char *)&stru_9667A8)->data;
  else
    v458 = 0;
  LOBYTE(v485.x) ^= (v458 ^ LOBYTE(v485.x)) & 1;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "z_only",
    (const char *)&v485,
    v471,
    compiler,
    v472,
    custom_config);
  vostok::render::effect_compiler::set_depth(v459, 1, 1, D3D11_COMPARISON_LESS_EQUAL);
  v481 = 1048576000;
  if ( (LOBYTE(v485.x) & 1) != 0 )
  {
    v461 = vostok::render::custom_config_value::operator[](v460, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v461->data,
      out_texture,
      (bool)v471,
      num_last_mips_used);
  }
  if ( (LOBYTE(v485.x) & 2) != 0 && vostok::render::custom_config_value::value_exists(&stru_9667FC, v471) )
  {
    v462 = vostok::render::custom_config_value::operator[](v460, (const char *)&stru_9667FC);
    *(float *)&v481 = vostok::render::custom_config_value::operator<float> float(v463, (int)v462);
  }
  _X.m_object = (vostok::strings::shared::profile *)v460;
  v469.m_object = (vostok::strings::shared::profile *)&stru_9667FC.type;
  v464 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v460,
           (const char *)s_manager.m_variable);
  _X.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &_X,
    v464);
  vostok::render::effect_compiler::set_constant<float>(
    (const float *)&v481,
    v465,
    compiler,
    (vostok::shared_string)_X.m_object);
  vostok::render::effect_compiler::color_write_enable(v466, (D3D11_COLOR_WRITE_ENABLE)0);
  _X.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v467);
  vostok::render::effect_compiler::end_technique(v468);
}
