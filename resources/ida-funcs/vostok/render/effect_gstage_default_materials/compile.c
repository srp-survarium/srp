void __thiscall vostok::render::effect_gstage_default_materials::compile(
        vostok::render::effect_gstage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  unsigned int vertex_input_type; // ecx
  unsigned int v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  char v8; // al
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  bool v15; // al
  vostok::configs::binary_config_value *v16; // eax
  bool v17; // al
  vostok::configs::binary_config_value *v18; // eax
  char v19; // al
  vostok::configs::binary_config_value *v20; // eax
  bool v21; // al
  vostok::configs::binary_config_value *v22; // eax
  bool v23; // al
  vostok::configs::binary_config_value *v24; // eax
  char v25; // al
  vostok::configs::binary_config_value *v26; // eax
  char v27; // al
  vostok::configs::binary_config_value *v28; // eax
  bool v29; // al
  vostok::configs::binary_config_value *v30; // eax
  bool v31; // al
  vostok::configs::binary_config_value *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  vostok::configs::binary_config_value *v34; // eax
  char v35; // al
  vostok::configs::binary_config_value *v36; // eax
  bool v37; // al
  vostok::configs::binary_config_value *v38; // eax
  char v39; // al
  vostok::configs::binary_config_value *v40; // eax
  bool v41; // al
  vostok::configs::binary_config_value *v42; // eax
  char v43; // al
  vostok::configs::binary_config_value *v44; // ecx
  vostok::configs::binary_config_value *v45; // eax
  bool v46; // al
  vostok::configs::binary_config_value *v47; // ecx
  vostok::configs::binary_config_value *v48; // eax
  bool v49; // al
  vostok::configs::binary_config_value *v50; // eax
  vostok::configs::binary_config_value *v51; // eax
  bool v52; // zf
  vostok::configs::binary_config_value *v53; // ecx
  vostok::configs::binary_config_value *v54; // ecx
  vostok::configs::binary_config_value *v55; // eax
  bool v56; // al
  vostok::configs::binary_config_value *v57; // ecx
  vostok::configs::binary_config_value *v58; // eax
  bool v59; // al
  vostok::configs::binary_config_value *v60; // ecx
  vostok::configs::binary_config_value *v61; // eax
  bool v62; // al
  vostok::configs::binary_config_value *v63; // eax
  bool v64; // al
  vostok::configs::binary_config_value *v65; // ecx
  vostok::configs::binary_config_value *v66; // eax
  bool v67; // al
  vostok::configs::binary_config_value *v68; // ecx
  vostok::configs::binary_config_value *v69; // eax
  bool v70; // al
  vostok::configs::binary_config_value *v71; // ecx
  vostok::configs::binary_config_value *v72; // eax
  bool v73; // al
  vostok::configs::binary_config_value *v74; // ecx
  vostok::configs::binary_config_value *v75; // eax
  vostok::configs::binary_config_value *v76; // eax
  const char **v77; // eax
  bool v78; // al
  vostok::configs::binary_config_value *v79; // ecx
  vostok::configs::binary_config_value *v80; // eax
  const vostok::configs::binary_config_value *v81; // eax
  vostok::configs::binary_config_value *v82; // eax
  vostok::configs::binary_config_value *v83; // eax
  vostok::configs::binary_config_value *v84; // ecx
  vostok::configs::binary_config_value *v85; // eax
  char v86; // al
  vostok::render::effect_compiler *v87; // ecx
  vostok::command_line::key *v88; // ecx
  vostok::render::effect_compiler *v89; // ecx
  vostok::render::effect_compiler *v90; // ecx
  vostok::configs::binary_config_value *v91; // ecx
  float v92; // xmm0_4
  float v93; // xmm1_4
  float v94; // xmm2_4
  vostok::configs::binary_config_value *v95; // eax
  const vostok::configs::binary_config_value *v96; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v98; // eax
  const vostok::configs::binary_config_value *v99; // eax
  float v100; // xmm0_4
  vostok::configs::binary_config_value *v101; // eax
  const vostok::configs::binary_config_value *v102; // eax
  float v103; // xmm0_4
  vostok::configs::binary_config_value *v104; // eax
  const vostok::configs::binary_config_value *v105; // eax
  vostok::render::effect_constant_storage *v106; // ecx
  float v107; // xmm0_4
  unsigned int v108; // esi
  vostok::configs::binary_config_value *v109; // ecx
  BOOL v110; // ecx
  vostok::configs::binary_config_value *v111; // eax
  const vostok::configs::binary_config_value *v112; // eax
  vostok::shared_string *v113; // ecx
  vostok::command_line::key *v114; // ecx
  vostok::configs::binary_config_value *v115; // ecx
  vostok::configs::binary_config_value *v116; // eax
  const vostok::configs::binary_config_value *v117; // eax
  float v118; // xmm0_4
  vostok::configs::binary_config_value *v119; // ecx
  vostok::configs::binary_config_value *v120; // eax
  const vostok::configs::binary_config_value *v121; // eax
  float v122; // xmm0_4
  vostok::configs::binary_config_value *v123; // eax
  vostok::configs::binary_config_value *v124; // ecx
  vostok::configs::binary_config_value *v125; // eax
  const vostok::configs::binary_config_value *v126; // eax
  float v127; // xmm0_4
  vostok::configs::binary_config_value *v128; // ecx
  vostok::configs::binary_config_value *v129; // eax
  const vostok::configs::binary_config_value *v130; // eax
  float v131; // xmm0_4
  vostok::configs::binary_config_value *v132; // ecx
  vostok::configs::binary_config_value *v133; // eax
  const vostok::configs::binary_config_value *v134; // eax
  float v135; // xmm0_4
  vostok::configs::binary_config_value *v136; // ecx
  vostok::configs::binary_config_value *v137; // eax
  const vostok::configs::binary_config_value *v138; // eax
  float v139; // xmm0_4
  vostok::render::effect_constant_storage *v140; // ecx
  vostok::configs::binary_config_value *v141; // eax
  const vostok::configs::binary_config_value *v142; // eax
  float v143; // xmm0_4
  vostok::render::effect_constant_storage *v144; // ecx
  vostok::render::effect_constant_storage *v145; // ecx
  vostok::render::effect_constant_storage *v146; // ecx
  vostok::render::effect_constant_storage *v147; // ecx
  vostok::configs::binary_config_value *v148; // ecx
  vostok::configs::binary_config_value *v149; // eax
  char **v150; // eax
  vostok::render::effect_compiler *v151; // ecx
  vostok::configs::binary_config_value *v152; // ecx
  vostok::configs::binary_config_value *v153; // ecx
  vostok::configs::binary_config_value *v154; // esi
  vostok::configs::binary_config_value *v155; // eax
  const vostok::configs::binary_config_value *v156; // eax
  float v157; // xmm0_4
  vostok::configs::binary_config_value *v158; // eax
  const vostok::configs::binary_config_value *v159; // eax
  float v160; // xmm0_4
  vostok::configs::binary_config_value *v161; // ecx
  __m128i v162; // xmm0
  vostok::configs::binary_config_value *v163; // eax
  const vostok::configs::binary_config_value *v164; // eax
  vostok::configs::binary_config_value *v165; // ecx
  vostok::configs::binary_config_value *v166; // eax
  const vostok::configs::binary_config_value *v167; // eax
  float v168; // xmm0_4
  vostok::configs::binary_config_value *v169; // eax
  const vostok::configs::binary_config_value *v170; // eax
  float v171; // xmm0_4
  vostok::configs::binary_config_value *v172; // eax
  const vostok::configs::binary_config_value *v173; // eax
  vostok::render::effect_constant_storage *v174; // ecx
  float v175; // xmm0_4
  vostok::configs::binary_config_value *v176; // ecx
  vostok::configs::binary_config_value *v177; // eax
  char **v178; // eax
  vostok::render::effect_compiler *v179; // ecx
  vostok::configs::binary_config_value *v180; // eax
  char **v181; // eax
  vostok::render::effect_compiler *v182; // ecx
  vostok::configs::binary_config_value *v183; // ecx
  vostok::configs::binary_config_value *v184; // eax
  const vostok::configs::binary_config_value *v185; // eax
  float v186; // xmm0_4
  double v187; // xmm0_8
  float v188; // xmm1_4
  vostok::render::effect_constant_storage *v189; // ecx
  vostok::render::effect_constant_storage *v190; // ecx
  vostok::render::effect_constant_storage *v191; // ecx
  vostok::render::effect_constant_storage *v192; // ecx
  vostok::configs::binary_config_value *v193; // eax
  const vostok::configs::binary_config_value *v194; // eax
  float *v195; // edi
  double v196; // xmm0_8
  double v197; // xmm0_8
  double v198; // xmm0_8
  const vostok::math::float3 *v199; // eax
  vostok::configs::binary_config_value *v200; // eax
  char **v201; // eax
  vostok::render::effect_compiler *v202; // ecx
  vostok::configs::binary_config_value *v203; // eax
  const vostok::configs::binary_config_value *v204; // eax
  float v205; // xmm0_4
  vostok::configs::binary_config_value *v206; // eax
  const vostok::configs::binary_config_value *v207; // eax
  float v208; // xmm0_4
  vostok::configs::binary_config_value *v209; // eax
  const vostok::configs::binary_config_value *v210; // eax
  vostok::render::effect_constant_storage *v211; // ecx
  float v212; // xmm0_4
  vostok::configs::binary_config_value *v213; // ecx
  vostok::configs::binary_config_value *v214; // eax
  char **v215; // eax
  vostok::configs::binary_config_value *v216; // ecx
  vostok::configs::binary_config_value *v217; // eax
  char **v218; // eax
  vostok::configs::binary_config_value *v219; // eax
  char **v220; // eax
  vostok::render::effect_compiler *v221; // ecx
  vostok::configs::binary_config_value *v222; // eax
  vostok::configs::binary_config_value *v223; // ecx
  vostok::render::effect_constant_storage *v224; // ecx
  vostok::configs::binary_config_value *v225; // eax
  const vostok::configs::binary_config_value *v226; // eax
  vostok::render::effect_constant_storage *v227; // ecx
  float v228; // xmm0_4
  vostok::configs::binary_config_value *v229; // ecx
  vostok::render::effect_constant_storage *v230; // ecx
  vostok::configs::binary_config_value *v231; // eax
  const vostok::configs::binary_config_value *v232; // eax
  vostok::render::effect_constant_storage *v233; // ecx
  float v234; // xmm0_4
  vostok::configs::binary_config_value *v235; // ecx
  vostok::render::effect_constant_storage *v236; // ecx
  vostok::configs::binary_config_value *v237; // eax
  const vostok::configs::binary_config_value *v238; // eax
  float *v239; // edi
  double v240; // xmm0_8
  double v241; // xmm0_8
  double v242; // xmm0_8
  vostok::render::effect_constant_storage *v243; // ecx
  vostok::configs::binary_config_value *v244; // ecx
  vostok::render::effect_constant_storage *v245; // ecx
  vostok::configs::binary_config_value *v246; // eax
  const vostok::configs::binary_config_value *v247; // eax
  float v248; // xmm0_4
  vostok::configs::binary_config_value *v249; // eax
  const vostok::configs::binary_config_value *v250; // eax
  float v251; // xmm0_4
  vostok::configs::binary_config_value *v252; // eax
  const vostok::configs::binary_config_value *v253; // eax
  vostok::render::effect_constant_storage *v254; // ecx
  float v255; // xmm0_4
  vostok::configs::binary_config_value *v256; // eax
  char **v257; // eax
  vostok::render::effect_compiler *v258; // ecx
  vostok::configs::binary_config_value *v259; // eax
  const vostok::configs::binary_config_value *v260; // eax
  float v261; // xmm0_4
  vostok::configs::binary_config_value *v262; // eax
  const vostok::configs::binary_config_value *v263; // eax
  float v264; // xmm0_4
  vostok::configs::binary_config_value *v265; // eax
  const vostok::configs::binary_config_value *v266; // eax
  vostok::render::effect_constant_storage *v267; // ecx
  float v268; // xmm0_4
  vostok::configs::binary_config_value *v269; // eax
  char **v270; // eax
  vostok::render::effect_compiler *v271; // ecx
  vostok::configs::binary_config_value *v272; // eax
  char **v273; // eax
  vostok::render::effect_compiler *v274; // ecx
  vostok::configs::binary_config_value *v275; // eax
  const vostok::configs::binary_config_value *v276; // eax
  float *v277; // esi
  double v278; // xmm0_8
  double v279; // xmm0_8
  double v280; // xmm0_8
  vostok::configs::binary_config_value *v281; // ecx
  vostok::configs::binary_config_value *v282; // esi
  vostok::configs::binary_config_value *v283; // eax
  char *v284; // edi
  vostok::render::effect_compiler *v285; // ecx
  vostok::render::effect_compiler *v286; // ecx
  vostok::configs::binary_config_value *v287; // eax
  char **v288; // eax
  vostok::render::effect_compiler *v289; // ecx
  vostok::configs::binary_config_value *v290; // ecx
  vostok::render::effect_constant_storage *v291; // ecx
  vostok::configs::binary_config_value *v292; // eax
  const vostok::configs::binary_config_value *v293; // eax
  vostok::render::effect_constant_storage *v294; // ecx
  float v295; // xmm0_4
  vostok::configs::binary_config_value *v296; // ecx
  vostok::render::effect_constant_storage *v297; // ecx
  vostok::configs::binary_config_value *v298; // eax
  const vostok::configs::binary_config_value *v299; // eax
  vostok::render::effect_constant_storage *v300; // ecx
  float v301; // xmm0_4
  vostok::configs::binary_config_value *v302; // ecx
  vostok::render::effect_constant_storage *v303; // ecx
  vostok::configs::binary_config_value *v304; // eax
  const vostok::configs::binary_config_value *v305; // eax
  float *v306; // edi
  double v307; // xmm0_8
  double v308; // xmm0_8
  double v309; // xmm0_8
  vostok::render::effect_constant_storage *v310; // ecx
  vostok::configs::binary_config_value *v311; // eax
  char **v312; // eax
  vostok::render::effect_compiler *v313; // ecx
  vostok::configs::binary_config_value *v314; // ecx
  vostok::configs::binary_config_value *v315; // eax
  char **v316; // eax
  vostok::render::effect_compiler *v317; // ecx
  vostok::configs::binary_config_value *v318; // ecx
  vostok::configs::binary_config_value *v319; // eax
  const vostok::configs::binary_config_value *v320; // eax
  float v321; // xmm0_4
  vostok::render::effect_constant_storage *v322; // ecx
  vostok::configs::binary_config_value *v323; // eax
  const vostok::configs::binary_config_value *v324; // eax
  float v325; // xmm0_4
  vostok::configs::binary_config_value *v326; // ecx
  vostok::configs::binary_config_value *v327; // eax
  char **v328; // eax
  vostok::render::effect_compiler *v329; // ecx
  vostok::configs::binary_config_value *v330; // eax
  const vostok::configs::binary_config_value *v331; // eax
  vostok::render::effect_constant_storage *v332; // ecx
  float v333; // xmm0_4
  vostok::configs::binary_config_value *v334; // eax
  const vostok::configs::binary_config_value *v335; // eax
  vostok::render::effect_constant_storage *v336; // ecx
  float v337; // xmm0_4
  vostok::configs::binary_config_value *v338; // eax
  char **v339; // eax
  vostok::render::effect_compiler *v340; // ecx
  vostok::configs::binary_config_value *v341; // eax
  char **v342; // eax
  vostok::render::effect_compiler *v343; // ecx
  vostok::configs::binary_config_value *v344; // ecx
  vostok::configs::binary_config_value *v345; // eax
  const vostok::configs::binary_config_value *v346; // eax
  float v347; // xmm0_4
  vostok::configs::binary_config_value *v348; // eax
  const vostok::configs::binary_config_value *v349; // eax
  float v350; // xmm0_4
  vostok::configs::binary_config_value *v351; // ecx
  vostok::configs::binary_config_value *v352; // ecx
  vostok::configs::binary_config_value *v353; // eax
  const vostok::configs::binary_config_value *v354; // eax
  float *v355; // esi
  vostok::configs::binary_config_value *v356; // eax
  const vostok::math::float4 **v357; // eax
  vostok::math::float4 *v358; // eax
  vostok::render::effect_constant_storage *v359; // ecx
  vostok::configs::binary_config_value *v360; // ecx
  vostok::configs::binary_config_value *v361; // eax
  char **v362; // eax
  vostok::render::effect_compiler *v363; // ecx
  vostok::configs::binary_config_value *v364; // ecx
  vostok::configs::binary_config_value *v365; // ecx
  vostok::configs::binary_config_value *v366; // eax
  const vostok::configs::binary_config_value *v367; // eax
  float v368; // xmm0_4
  vostok::configs::binary_config_value *v369; // eax
  const vostok::configs::binary_config_value *v370; // eax
  float v371; // xmm0_4
  vostok::configs::binary_config_value *v372; // eax
  const vostok::configs::binary_config_value *v373; // eax
  float v374; // xmm0_4
  vostok::configs::binary_config_value *v375; // eax
  char **v376; // eax
  vostok::render::effect_compiler *v377; // ecx
  vostok::configs::binary_config_value *v378; // ecx
  vostok::render::effect_constant_storage *v379; // ecx
  vostok::configs::binary_config_value *v380; // eax
  const vostok::configs::binary_config_value *v381; // eax
  float v382; // xmm0_4
  vostok::configs::binary_config_value *v383; // eax
  const vostok::configs::binary_config_value *v384; // eax
  float v385; // xmm0_4
  vostok::configs::binary_config_value *v386; // eax
  const vostok::configs::binary_config_value *v387; // eax
  float v388; // xmm0_4
  vostok::configs::binary_config_value *v389; // ecx
  vostok::configs::binary_config_value *v390; // eax
  char **v391; // eax
  vostok::render::effect_compiler *v392; // ecx
  vostok::configs::binary_config_value *v393; // eax
  const vostok::configs::binary_config_value *v394; // eax
  float v395; // xmm0_4
  vostok::configs::binary_config_value *v396; // ecx
  vostok::configs::binary_config_value *v397; // eax
  const vostok::configs::binary_config_value *v398; // eax
  float v399; // xmm0_4
  vostok::configs::binary_config_value *v400; // ecx
  vostok::configs::binary_config_value *v401; // eax
  const vostok::configs::binary_config_value *v402; // eax
  float v403; // xmm0_4
  vostok::configs::binary_config_value *v404; // ecx
  vostok::configs::binary_config_value *v405; // eax
  const vostok::configs::binary_config_value *v406; // eax
  float v407; // xmm0_4
  vostok::render::effect_constant_storage *v408; // ecx
  vostok::configs::binary_config_value *v409; // eax
  const vostok::configs::binary_config_value *v410; // eax
  float v411; // xmm0_4
  vostok::configs::binary_config_value *v412; // ecx
  vostok::configs::binary_config_value *v413; // ecx
  vostok::configs::binary_config_value *v414; // eax
  const vostok::math::float4 **v415; // eax
  const vostok::math::float4 *v416; // eax
  vostok::render::effect_constant_storage *v417; // ecx
  vostok::render::effect_compiler *v418; // ecx
  vostok::configs::binary_config_value *v419; // eax
  char **v420; // eax
  vostok::render::effect_compiler *v421; // ecx
  vostok::configs::binary_config_value *v422; // ecx
  vostok::configs::binary_config_value *v423; // eax
  const vostok::configs::binary_config_value *v424; // eax
  float v425; // xmm0_4
  vostok::configs::binary_config_value *v426; // ecx
  vostok::configs::binary_config_value *v427; // eax
  const vostok::configs::binary_config_value *v428; // eax
  float v429; // xmm0_4
  vostok::configs::binary_config_value *v430; // ecx
  vostok::configs::binary_config_value *v431; // eax
  const vostok::configs::binary_config_value *v432; // eax
  float v433; // xmm0_4
  vostok::configs::binary_config_value *v434; // ecx
  vostok::configs::binary_config_value *v435; // eax
  const vostok::configs::binary_config_value *v436; // eax
  float v437; // xmm0_4
  vostok::configs::binary_config_value *v438; // ecx
  vostok::configs::binary_config_value *v439; // eax
  const vostok::configs::binary_config_value *v440; // eax
  float v441; // xmm0_4
  vostok::configs::binary_config_value *v442; // eax
  const vostok::configs::binary_config_value *v443; // eax
  float v444; // xmm0_4
  vostok::render::effect_constant_storage *v445; // ecx
  vostok::render::effect_constant_storage *v446; // ecx
  vostok::render::effect_material_base *v447; // ecx
  vostok::render::shader_configuration *v448; // ecx
  vostok::configs::binary_config_value *v449; // ecx
  vostok::render::effect_material_base *v450; // ecx
  vostok::render::shader_configuration *v451; // ecx
  vostok::configs::binary_config_value *v452; // eax
  const vostok::configs::binary_config_value *v453; // eax
  vostok::configs::binary_config_value *v454; // ecx
  vostok::render::effect_compiler *v455; // ecx
  vostok::render::effect_compiler *v456; // ecx
  vostok::configs::binary_config_value *v457; // ecx
  vostok::configs::binary_config_value *v458; // eax
  char **v459; // eax
  vostok::render::effect_compiler *v460; // ecx
  vostok::render::effect_constant_storage *v461; // ecx
  vostok::configs::binary_config_value *v462; // eax
  const vostok::math::float4 **v463; // eax
  const vostok::math::float3 *v464; // eax
  vostok::render::effect_constant_storage *v465; // ecx
  vostok::render::effect_material_base *v466; // ecx
  vostok::render::shader_configuration *v467; // ecx
  vostok::configs::binary_config_value *v468; // eax
  const vostok::configs::binary_config_value *v469; // eax
  vostok::configs::binary_config_value *v470; // ecx
  vostok::configs::binary_config_value *v471; // ecx
  vostok::configs::binary_config_value *v472; // eax
  char **v473; // eax
  vostok::render::effect_compiler *v474; // ecx
  vostok::render::effect_constant_storage *v475; // ecx
  vostok::configs::binary_config_value *v476; // eax
  const vostok::math::float4 **v477; // eax
  const vostok::math::float3 *v478; // eax
  vostok::render::effect_material_base *v479; // ecx
  vostok::render::shader_configuration *v480; // ecx
  vostok::configs::binary_config_value *v481; // eax
  vostok::configs::binary_config_value *v482; // ecx
  vostok::configs::binary_config_value *v483; // eax
  const vostok::configs::binary_config_value *v484; // eax
  vostok::configs::binary_config_value *v485; // ecx
  vostok::configs::binary_config_value *v486; // eax
  const vostok::configs::binary_config_value *v487; // eax
  vostok::configs::binary_config_value *v488; // ecx
  vostok::configs::binary_config_value *v489; // eax
  bool v490; // al
  vostok::render::effect_compiler *v491; // ecx
  vostok::render::effect_compiler *v492; // ecx
  vostok::configs::binary_config_value *v493; // ecx
  vostok::configs::binary_config_value *v494; // eax
  const vostok::configs::binary_config_value *v495; // eax
  float v496; // xmm0_4
  vostok::configs::binary_config_value *v497; // eax
  const vostok::math::float4 **v498; // eax
  vostok::render::effect_constant_storage *v499; // ecx
  vostok::configs::binary_config_value *v500; // ecx
  vostok::render::effect_constant_storage *v501; // ecx
  vostok::configs::binary_config_value *v502; // eax
  const vostok::configs::binary_config_value *v503; // eax
  float v504; // xmm0_4
  vostok::configs::binary_config_value *v505; // eax
  const vostok::configs::binary_config_value *v506; // eax
  float v507; // xmm0_4
  vostok::configs::binary_config_value *v508; // eax
  const vostok::configs::binary_config_value *v509; // eax
  vostok::render::effect_constant_storage *v510; // ecx
  float v511; // xmm0_4
  vostok::configs::binary_config_value *v512; // ecx
  vostok::configs::binary_config_value *v513; // eax
  const vostok::configs::binary_config_value *v514; // eax
  float v515; // xmm0_4
  vostok::configs::binary_config_value *v516; // ecx
  vostok::configs::binary_config_value *v517; // eax
  const vostok::configs::binary_config_value *v518; // eax
  float v519; // xmm0_4
  vostok::configs::binary_config_value *v520; // ecx
  vostok::configs::binary_config_value *v521; // eax
  const vostok::configs::binary_config_value *v522; // eax
  float v523; // xmm0_4
  vostok::configs::binary_config_value *v524; // ecx
  vostok::configs::binary_config_value *v525; // eax
  const vostok::configs::binary_config_value *v526; // eax
  float v527; // xmm0_4
  vostok::configs::binary_config_value *v528; // ecx
  vostok::configs::binary_config_value *v529; // eax
  const vostok::configs::binary_config_value *v530; // eax
  float v531; // xmm0_4
  vostok::configs::binary_config_value *v532; // eax
  const vostok::configs::binary_config_value *v533; // eax
  float v534; // xmm0_4
  vostok::render::effect_constant_storage *v535; // ecx
  vostok::render::effect_compiler *v536; // ecx
  vostok::render::effect_material_base *v537; // ecx
  vostok::configs::binary_config_value *v538; // eax
  char **v539; // eax
  vostok::render::effect_compiler *v540; // ecx
  vostok::render::shader_configuration *v541; // ecx
  vostok::configs::binary_config_value *v542; // ecx
  vostok::configs::binary_config_value *v543; // ecx
  vostok::configs::binary_config_value *v544; // eax
  bool v545; // al
  vostok::configs::binary_config_value *v546; // ecx
  vostok::configs::binary_config_value *v547; // eax
  bool v548; // al
  vostok::render::effect_compiler *v549; // ecx
  vostok::configs::binary_config_value *v550; // ecx
  vostok::configs::binary_config_value *v551; // eax
  char **v552; // eax
  vostok::render::effect_compiler *v553; // ecx
  vostok::configs::binary_config_value *v554; // eax
  const vostok::configs::binary_config_value *v555; // eax
  float v556; // xmm0_4
  vostok::render::effect_material_base *v557; // ecx
  vostok::render::shader_configuration *v558; // ecx
  vostok::configs::binary_config_value *v559; // ecx
  vostok::configs::binary_config_value *v560; // ecx
  vostok::configs::binary_config_value *v561; // eax
  bool v562; // al
  vostok::configs::binary_config_value *v563; // ecx
  vostok::configs::binary_config_value *v564; // eax
  bool v565; // al
  vostok::configs::binary_config_value *v566; // ecx
  vostok::configs::binary_config_value *v567; // eax
  bool v568; // al
  vostok::configs::binary_config_value *v569; // ecx
  vostok::configs::binary_config_value *v570; // eax
  bool v571; // al
  vostok::render::effect_compiler *v572; // ecx
  vostok::render::effect_compiler *v573; // ecx
  vostok::configs::binary_config_value *v574; // ecx
  vostok::configs::binary_config_value *v575; // eax
  char **v576; // eax
  vostok::render::effect_compiler *v577; // ecx
  vostok::configs::binary_config_value *v578; // eax
  const vostok::configs::binary_config_value *v579; // eax
  float v580; // xmm0_4
  vostok::render::effect_compiler *v581; // ecx
  vostok::render::effect_compiler *v582; // ecx
  vostok::render::effect_compiler *v583; // ecx
  vostok::render::effect_compiler *v584; // ecx
  vostok::render::effect_compiler *v585; // ecx
  vostok::render::effect_compiler *v586; // ecx
  vostok::render::effect_compiler *v587; // ecx
  vostok::render::effect_material_base *v588; // ecx
  vostok::configs::binary_config_value *v589; // eax
  char **v590; // eax
  vostok::render::effect_compiler *v591; // ecx
  vostok::configs::binary_config_value *v592; // eax
  char **v593; // eax
  vostok::render::effect_compiler *v594; // ecx
  vostok::render::shader_configuration *v595; // ecx
  vostok::configs::binary_config_value *v596; // ecx
  vostok::configs::binary_config_value *v597; // ecx
  vostok::configs::binary_config_value *v598; // eax
  bool v599; // al
  vostok::configs::binary_config_value *v600; // ecx
  vostok::configs::binary_config_value *v601; // eax
  bool v602; // al
  vostok::configs::binary_config_value *v603; // ecx
  vostok::configs::binary_config_value *v604; // eax
  const vostok::configs::binary_config_value *v605; // eax
  vostok::configs::binary_config_value *v606; // ecx
  vostok::configs::binary_config_value *v607; // eax
  const vostok::configs::binary_config_value *v608; // eax
  float v609; // xmm0_4
  vostok::render::effect_compiler *v610; // ecx
  vostok::render::effect_compiler *v611; // ecx
  vostok::render::effect_compiler *v612; // ecx
  vostok::render::effect_material_base *v613; // ecx
  vostok::render::shader_configuration *v614; // ecx
  vostok::configs::binary_config_value *v615; // ecx
  vostok::configs::binary_config_value *v616; // ecx
  vostok::configs::binary_config_value *v617; // eax
  bool v618; // al
  vostok::render::effect_compiler *v619; // ecx
  vostok::command_line::key *v620; // ecx
  vostok::render::effect_compiler *v621; // ecx
  vostok::render::effect_material_base *v622; // ecx
  vostok::render::shader_configuration *v623; // ecx
  vostok::configs::binary_config_value *v624; // ecx
  vostok::render::effect_compiler *v625; // ecx
  vostok::command_line::key *v626; // ecx
  vostok::render::effect_compiler *v627; // ecx
  vostok::render::effect_material_base *v628; // ecx
  vostok::render::shader_configuration *v629; // ecx
  vostok::configs::binary_config_value *v630; // ecx
  vostok::configs::binary_config_value *v631; // ecx
  vostok::configs::binary_config_value *v632; // eax
  bool v633; // al
  vostok::configs::binary_config_value *v634; // ecx
  vostok::configs::binary_config_value *v635; // eax
  char v636; // al
  vostok::configs::binary_config_value *v637; // ecx
  vostok::configs::binary_config_value *v638; // eax
  bool v639; // al
  vostok::configs::binary_config_value *v640; // ecx
  vostok::configs::binary_config_value *v641; // eax
  bool v642; // al
  vostok::render::effect_compiler *v643; // ecx
  vostok::command_line::key *v644; // ecx
  vostok::command_line::key *v645; // ecx
  vostok::render::effect_material_base *v646; // ecx
  vostok::configs::binary_config_value *v647; // eax
  char **v648; // eax
  vostok::render::effect_compiler *v649; // ecx
  vostok::configs::binary_config_value *v650; // eax
  char **v651; // eax
  vostok::render::effect_compiler *v652; // ecx
  bool v653; // al
  vostok::configs::binary_config_value *v654; // eax
  char **v655; // eax
  vostok::render::effect_compiler *v656; // ecx
  vostok::configs::binary_config_value *v657; // eax
  char **v658; // eax
  vostok::render::effect_compiler *v659; // ecx
  vostok::configs::binary_config_value *v660; // eax
  char **v661; // eax
  vostok::render::effect_compiler *v662; // ecx
  vostok::render::shader_configuration *v663; // ecx
  vostok::configs::binary_config_value *v664; // ecx
  vostok::render::effect_compiler *v665; // ecx
  vostok::render::effect_compiler *v666; // ecx
  vostok::render::effect_material_base *v667; // ecx
  float v668; // [esp+0h] [ebp-2CCh]
  long double v669; // [esp+4h] [ebp-2C8h]
  long double v670; // [esp+4h] [ebp-2C8h]
  D3D11_STENCIL_OP v671; // [esp+4h] [ebp-2C8h]
  long double v672; // [esp+4h] [ebp-2C8h]
  long double v673; // [esp+4h] [ebp-2C8h]
  long double v674; // [esp+4h] [ebp-2C8h]
  long double v675; // [esp+4h] [ebp-2C8h]
  long double v676; // [esp+4h] [ebp-2C8h]
  long double v677; // [esp+4h] [ebp-2C8h]
  long double v678; // [esp+4h] [ebp-2C8h]
  long double v679; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v680; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v681; // [esp+4h] [ebp-2C8h]
  D3D11_STENCIL_OP v682; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v683; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v684; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v685; // [esp+4h] [ebp-2C8h]
  D3D11_STENCIL_OP v686; // [esp+4h] [ebp-2C8h]
  D3D11_BLEND_OP v687; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v688; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v689; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v690; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v691; // [esp+4h] [ebp-2C8h]
  D3D11_BLEND_OP v692; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v693; // [esp+4h] [ebp-2C8h]
  D3D11_STENCIL_OP v694; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v695; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v696; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v697; // [esp+4h] [ebp-2C8h]
  D3D11_BLEND_OP v698; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v699; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v700; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v701; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v702; // [esp+4h] [ebp-2C8h]
  const vostok::configs::binary_config_value *v703; // [esp+4h] [ebp-2C8h]
  D3D11_COMPARISON_FUNC v704; // [esp+4h] [ebp-2C8h]
  D3D11_STENCIL_OP v705; // [esp+4h] [ebp-2C8h]
  long double v706; // [esp+Ch] [ebp-2C0h]
  long double v707; // [esp+Ch] [ebp-2C0h]
  long double v708; // [esp+Ch] [ebp-2C0h]
  long double v709; // [esp+Ch] [ebp-2C0h]
  long double v710; // [esp+Ch] [ebp-2C0h]
  long double v711; // [esp+Ch] [ebp-2C0h]
  long double v712; // [esp+Ch] [ebp-2C0h]
  long double v713; // [esp+Ch] [ebp-2C0h]
  long double v714; // [esp+Ch] [ebp-2C0h]
  char v715; // [esp+13h] [ebp-2B9h]
  char v716; // [esp+13h] [ebp-2B9h]
  int v717; // [esp+14h] [ebp-2B8h] BYREF
  int v718; // [esp+18h] [ebp-2B4h]
  _BYTE v719[7]; // [esp+1Ch] [ebp-2B0h]
  char v720; // [esp+23h] [ebp-2A9h]
  unsigned __int8 v721; // [esp+2Bh] [ebp-2A1h]
  unsigned int num_last_mips_used; // [esp+2Ch] [ebp-2A0h]
  unsigned int streaming_priority; // [esp+30h] [ebp-29Ch]
  float v724; // [esp+34h] [ebp-298h] BYREF
  float v725; // [esp+38h] [ebp-294h]
  int i; // [esp+3Ch] [ebp-290h]
  float v727; // [esp+40h] [ebp-28Ch] BYREF
  vostok::math::float4 v728; // [esp+44h] [ebp-288h] BYREF
  float v729; // [esp+54h] [ebp-278h]
  vostok::math::float3 v730; // [esp+58h] [ebp-274h] BYREF
  vostok::math::float4 v731; // [esp+64h] [ebp-268h] BYREF
  float v732; // [esp+78h] [ebp-254h]
  vostok::math::float4 v733; // [esp+7Ch] [ebp-250h] BYREF
  vostok::math::float4 v734; // [esp+8Ch] [ebp-240h] BYREF
  __int64 v735; // [esp+9Ch] [ebp-230h]
  float v736; // [esp+A4h] [ebp-228h]
  float v737; // [esp+A8h] [ebp-224h]
  vostok::math::float4 v738; // [esp+ACh] [ebp-220h] BYREF
  float v739; // [esp+BCh] [ebp-210h]
  float v740; // [esp+C0h] [ebp-20Ch] BYREF
  float v741; // [esp+C4h] [ebp-208h]
  float v742; // [esp+C8h] [ebp-204h]
  float v743; // [esp+CCh] [ebp-200h]
  float v744; // [esp+D0h] [ebp-1FCh]
  float v745; // [esp+D4h] [ebp-1F8h]
  float v746; // [esp+D8h] [ebp-1F4h]
  float v747; // [esp+DCh] [ebp-1F0h]
  float v748; // [esp+E0h] [ebp-1ECh]
  float v749; // [esp+E4h] [ebp-1E8h]
  float v750; // [esp+E8h] [ebp-1E4h]
  float v751; // [esp+ECh] [ebp-1E0h]
  float v752; // [esp+F0h] [ebp-1DCh] BYREF
  float v753; // [esp+F4h] [ebp-1D8h]
  float v754; // [esp+F8h] [ebp-1D4h] BYREF
  float v755; // [esp+FCh] [ebp-1D0h]
  float v756; // [esp+100h] [ebp-1CCh] BYREF
  float v757; // [esp+104h] [ebp-1C8h]
  float v758; // [esp+108h] [ebp-1C4h]
  float v759; // [esp+10Ch] [ebp-1C0h] BYREF
  float v760; // [esp+110h] [ebp-1BCh] BYREF
  vostok::math::float3 v761; // [esp+114h] [ebp-1B8h] BYREF
  vostok::math::float3 v762; // [esp+120h] [ebp-1ACh] BYREF
  float v763; // [esp+12Ch] [ebp-1A0h] BYREF
  float v764; // [esp+130h] [ebp-19Ch]
  float v765; // [esp+134h] [ebp-198h] BYREF
  float v766; // [esp+138h] [ebp-194h] BYREF
  float v767; // [esp+13Ch] [ebp-190h] BYREF
  float v768; // [esp+140h] [ebp-18Ch] BYREF
  float v769[3]; // [esp+144h] [ebp-188h] BYREF
  float v770; // [esp+150h] [ebp-17Ch]
  int v771; // [esp+154h] [ebp-178h] BYREF
  int v772; // [esp+158h] [ebp-174h] BYREF
  float v773[3]; // [esp+15Ch] [ebp-170h] BYREF
  float v774; // [esp+168h] [ebp-164h] BYREF
  float v775; // [esp+16Ch] [ebp-160h] BYREF
  float v776; // [esp+170h] [ebp-15Ch] BYREF
  vostok::math::float4 v777; // [esp+174h] [ebp-158h] BYREF
  vostok::math::float4 v778; // [esp+188h] [ebp-144h] BYREF
  _DWORD v779[2]; // [esp+198h] [ebp-134h] BYREF
  _DWORD v780[2]; // [esp+1A0h] [ebp-12Ch] BYREF
  vostok::render::shader_constant_binding binding; // [esp+1A8h] [ebp-124h] BYREF
  float v782; // [esp+1BCh] [ebp-110h]
  float v783; // [esp+1C0h] [ebp-10Ch]
  float v784; // [esp+1C4h] [ebp-108h]
  vostok::math::float3 v785; // [esp+1C8h] [ebp-104h] BYREF
  vostok::math::float3 v786; // [esp+1D4h] [ebp-F8h] BYREF
  _DWORD v787[3]; // [esp+1E0h] [ebp-ECh] BYREF
  vostok::math::float3_pod v788; // [esp+1ECh] [ebp-E0h] BYREF
  vostok::math::float3 v789; // [esp+1F8h] [ebp-D4h] BYREF
  vostok::math::float3 v790; // [esp+204h] [ebp-C8h] BYREF
  vostok::math::float3 v791; // [esp+210h] [ebp-BCh] BYREF
  vostok::math::float3 v792; // [esp+21Ch] [ebp-B0h] BYREF
  vostok::math::float3 v793; // [esp+228h] [ebp-A4h] BYREF
  vostok::math::float4 v794; // [esp+234h] [ebp-98h] BYREF
  _DWORD v795[4]; // [esp+244h] [ebp-88h] BYREF
  vostok::math::float4 v796; // [esp+254h] [ebp-78h] BYREF
  vostok::math::float4 v797; // [esp+264h] [ebp-68h] BYREF
  vostok::math::float4 v798; // [esp+274h] [ebp-58h] BYREF
  vostok::math::float4 v799; // [esp+284h] [ebp-48h] BYREF
  __int64 v800; // [esp+294h] [ebp-38h]
  int v801; // [esp+29Ch] [ebp-30h]
  int v802; // [esp+2A0h] [ebp-2Ch]
  float v803; // [esp+2A4h] [ebp-28h]

  vertex_input_type = parameters->vertex_input_type;
  if ( parameters->vertex_input_type >= 0xF )
  {
    v5 = -1;
LABEL_7:
    LOBYTE(num_last_mips_used) = 1;
    goto LABEL_9;
  }
  v5 = 1 << vertex_input_type;
  if ( 1 << vertex_input_type != 2048 && v5 != 128 && v5 != 512 && v5 != 256 )
    goto LABEL_7;
  LOBYTE(num_last_mips_used) = 0;
LABEL_9:
  if ( v5 < 8 || (v721 = 1, v5 > 0x40) )
    v721 = 0;
  streaming_priority = (_BYTE)num_last_mips_used == 0 ? -1 : 5;
  if ( v5 == 2048 )
    streaming_priority = 0;
  i = 0;
  v776 = s_bm_current_air_resistance;
  *(_QWORD *)&v733.x = 0;
  v733.w = 0.0;
  *(_QWORD *)&v778.elements[2] = 0;
  do
  {
    *(_DWORD *)v719 = 0;
    BYTE6(v706) = i == 1;
    v717 = 0;
    v718 = 0;
    v720 = 0;
    *(_DWORD *)&v719[3] = i & 7 | (unsigned __int8)(16 * (i == 2));
    v6 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    BYTE2(v717) = 8 * (vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0);
    v8 = 0;
    if ( !BYTE6(v706) )
    {
      v7 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
      if ( vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer )
        v8 = 1;
    }
    BYTE2(v717) = BYTE2(v717) & 0x7F | (v8 << 7);
    if ( BYTE6(v706)
      || (v9 = vostok::configs::binary_config_value::operator[](config, "use_parallax"),
          v715 = 1,
          !vostok::configs::binary_config_value::operator[](v9, "value")->data.pointer) )
    {
      v715 = 0;
    }
    v10 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v11 = vostok::configs::binary_config_value::operator[](v10, "value");
    LOBYTE(v12) = BYTE2(v717) & 0xAF;
    BYTE2(v717) = BYTE2(v717) & 0xAF | (16 * ((4 * (v715 & 1)) | (v11->data.pointer != 0)));
    v15 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v12, (int)config, (unsigned int)"use_vertex_alpha_test") )
    {
      v14 = vostok::configs::binary_config_value::operator[](config, "use_vertex_alpha_test");
      if ( vostok::configs::binary_config_value::operator[](v14, "value")->data.pointer )
        v15 = 1;
    }
    BYTE2(v717) ^= (BYTE2(v717) ^ (32 * v15)) & 0x20;
    if ( BYTE6(v706)
      || !vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_detail_nmap") )
    {
      v17 = 0;
    }
    else
    {
      v16 = vostok::configs::binary_config_value::operator[](config, "use_detail_nmap");
      v17 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
    }
    HIBYTE(v717) ^= (HIBYTE(v717) ^ v17) & 1;
    if ( BYTE6(v706)
      || !vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_indirect_specular") )
    {
      v19 = 0;
    }
    else
    {
      v18 = vostok::configs::binary_config_value::operator[](config, "use_indirect_specular");
      v19 = vostok::configs::binary_config_value::operator[](v18, "value")->data.pointer != 0;
    }
    v719[2] = (v19 << 7) | 8;
    if ( BYTE6(v706)
      || !vostok::configs::binary_config_value::value_exists(
            v13,
            (int)config,
            (unsigned int)"use_anisotropic_direction_texture") )
    {
      v21 = 0;
    }
    else
    {
      v20 = vostok::configs::binary_config_value::operator[](config, "use_anisotropic_direction_texture");
      v21 = vostok::configs::binary_config_value::operator[](v20, "value")->data.pointer != 0;
    }
    v719[0] ^= (v719[0] ^ (32 * v21)) & 0x20;
    if ( BYTE6(v706)
      || !vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_tditail_diffuse") )
    {
      v23 = 0;
    }
    else
    {
      v22 = vostok::configs::binary_config_value::operator[](config, "use_tditail_diffuse");
      v23 = vostok::configs::binary_config_value::operator[](v22, "value")->data.pointer != 0;
    }
    HIBYTE(v717) ^= (HIBYTE(v717) ^ (2 * v23)) & 2;
    v25 = 0;
    if ( !BYTE6(v706) )
    {
      v24 = vostok::configs::binary_config_value::operator[](config, "use_reflection");
      if ( vostok::configs::binary_config_value::operator[](v24, "value")->data.pointer )
        v25 = 1;
    }
    LOBYTE(v13) = BYTE2(v718) & 0x3F;
    BYTE2(v718) = BYTE2(v718) & 0x3F | (v25 << 6);
    if ( BYTE6(v706)
      || !vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_reflection_mask") )
    {
      v27 = 0;
    }
    else
    {
      v26 = vostok::configs::binary_config_value::operator[](config, "use_reflection_mask");
      v27 = vostok::configs::binary_config_value::operator[](v26, "value")->data.pointer != 0;
    }
    LOBYTE(v718) = (v718 ^ (v27 << 6)) & 0x40 ^ v718;
    if ( BYTE6(v706)
      || !vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_sequence") )
    {
      v29 = 0;
    }
    else
    {
      v28 = vostok::configs::binary_config_value::operator[](config, "use_sequence");
      v29 = vostok::configs::binary_config_value::operator[](v28, "value")->data.pointer != 0;
    }
    LOBYTE(v718) = (v718 ^ (32 * v29)) & 0x20 ^ v718;
    v31 = 0;
    if ( !BYTE6(v706)
      && vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_alphablended_normal") )
    {
      v30 = vostok::configs::binary_config_value::operator[](config, "use_alphablended_normal");
      if ( vostok::configs::binary_config_value::operator[](v30, "value")->data.pointer )
        v31 = 1;
    }
    LOBYTE(v718) = (v718 ^ (16 * v31)) & 0x10 ^ v718;
    if ( !vostok::configs::binary_config_value::value_exists(
            v13,
            (int)config,
            (unsigned int)"use_vertex_blended_textures")
      || (v33 = vostok::configs::binary_config_value::operator[](config, "use_vertex_blended_textures"),
          !vostok::configs::binary_config_value::operator[](v33, "value")->data.pointer) )
    {
      v716 = 0;
LABEL_65:
      v35 = 0;
      goto LABEL_66;
    }
    v716 = 1;
    if ( !vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"use_vertex_blended_mask") )
      goto LABEL_65;
    v34 = vostok::configs::binary_config_value::operator[](config, "use_vertex_blended_mask");
    if ( !vostok::configs::binary_config_value::operator[](v34, "value")->data.pointer )
      goto LABEL_65;
    v35 = 1;
LABEL_66:
    v719[1] ^= (v719[1] ^ (v35 << 6)) & 0x40;
    v37 = 0;
    if ( v716 )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v32,
             (int)config,
             (unsigned int)"use_vertex_blended_diffuse") )
      {
        v36 = vostok::configs::binary_config_value::operator[](config, "use_vertex_blended_diffuse");
        if ( vostok::configs::binary_config_value::operator[](v36, "value")->data.pointer )
          v37 = 1;
      }
    }
    v719[1] ^= (v719[1] ^ (32 * v37)) & 0x20;
    v39 = 0;
    if ( !BYTE6(v706) )
    {
      if ( v716 )
      {
        if ( vostok::configs::binary_config_value::value_exists(
               v32,
               (int)config,
               (unsigned int)"use_vertex_blended_normal") )
        {
          v38 = vostok::configs::binary_config_value::operator[](config, "use_vertex_blended_normal");
          if ( vostok::configs::binary_config_value::operator[](v38, "value")->data.pointer )
            v39 = 1;
        }
      }
    }
    LOBYTE(v32) = v719[1] & 0x7F;
    v719[1] = v719[1] & 0x7F | (v39 << 7);
    v41 = 0;
    if ( !BYTE6(v706) )
    {
      if ( v716 )
      {
        if ( vostok::configs::binary_config_value::value_exists(
               v32,
               (int)config,
               (unsigned int)"use_vertex_blended_specular") )
        {
          v40 = vostok::configs::binary_config_value::operator[](config, "use_vertex_blended_specular");
          if ( vostok::configs::binary_config_value::operator[](v40, "value")->data.pointer )
            v41 = 1;
        }
      }
    }
    v719[2] ^= (v719[2] ^ v41) & 1;
    v43 = 0;
    if ( !BYTE6(v706)
      && vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"use_grass_fresnel_effect") )
    {
      v42 = vostok::configs::binary_config_value::operator[](config, "use_grass_fresnel_effect");
      if ( vostok::configs::binary_config_value::operator[](v42, "value")->data.pointer )
        v43 = 1;
    }
    LOBYTE(v32) = v718 & 0x7F;
    LOBYTE(v718) = v718 & 0x7F | (v43 << 7);
    if ( vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"use_tspecular_intensity") )
    {
      v45 = vostok::configs::binary_config_value::operator[](config, "use_tspecular_intensity");
      v46 = vostok::configs::binary_config_value::operator[](v45, "value")->data.pointer != 0;
    }
    else
    {
      v46 = 0;
    }
    HIBYTE(v717) ^= (HIBYTE(v717) ^ (8 * v46)) & 8;
    if ( vostok::configs::binary_config_value::value_exists(v44, (int)config, (unsigned int)"use_tfresnel") )
    {
      v48 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
      v49 = vostok::configs::binary_config_value::operator[](v48, "value")->data.pointer != 0;
    }
    else
    {
      v49 = 0;
    }
    HIBYTE(v717) ^= (HIBYTE(v717) ^ (16 * v49)) & 0x10;
    if ( vostok::configs::binary_config_value::value_exists(v47, (int)config, (unsigned int)"use_troughness") )
    {
      v50 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
      HIBYTE(v706) = vostok::configs::binary_config_value::operator[](v50, "value")->data.pointer != 0;
    }
    else
    {
      HIBYTE(v706) = 0;
    }
    v51 = vostok::configs::binary_config_value::operator[](config, "use_ttranslucency");
    v52 = vostok::configs::binary_config_value::operator[](v51, "value")->data.pointer == 0;
    v719[3] |= 8u;
    HIBYTE(v717) = HIBYTE(v717) & 0xDB | (4 * ((8 * (HIBYTE(v706) & 1)) | !v52));
    LOBYTE(v53) = HIBYTE(v717);
    v56 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v53, (int)config, (unsigned int)"use_masked_diffuse_color") )
    {
      v55 = vostok::configs::binary_config_value::operator[](config, "use_masked_diffuse_color");
      if ( vostok::configs::binary_config_value::operator[](v55, "value")->data.pointer )
        v56 = 1;
    }
    v719[4] ^= (v719[4] ^ v56) & 1;
    v59 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v54, (int)config, (unsigned int)"use_olta") )
    {
      v58 = vostok::configs::binary_config_value::operator[](config, "use_olta");
      if ( vostok::configs::binary_config_value::operator[](v58, "value")->data.pointer )
        v59 = 1;
    }
    v719[5] ^= (v719[5] ^ (4 * v59)) & 4;
    v62 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v57, (int)config, (unsigned int)"use_fuzziness") )
    {
      v61 = vostok::configs::binary_config_value::operator[](config, "use_fuzziness");
      if ( vostok::configs::binary_config_value::operator[](v61, "value")->data.pointer )
        v62 = 1;
    }
    v719[4] ^= (v719[4] ^ (16 * v62)) & 0x10;
    v64 = 0;
    if ( (v719[4] & 1) != 0 )
    {
      if ( !vostok::configs::binary_config_value::value_exists(
              v60,
              (int)config,
              (unsigned int)"use_constant_mask_color")
        || (v63 = vostok::configs::binary_config_value::operator[](config, "use_constant_mask_color"),
            !vostok::configs::binary_config_value::operator[](v63, "value")->data.pointer) )
      {
        v64 = 1;
      }
    }
    v719[4] ^= (v719[4] ^ (2 * v64)) & 2;
    v67 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v60, (int)config, (unsigned int)"use_normal_waves") )
    {
      v66 = vostok::configs::binary_config_value::operator[](config, "use_normal_waves");
      if ( vostok::configs::binary_config_value::operator[](v66, "value")->data.pointer )
        v67 = 1;
    }
    v719[4] ^= (v719[4] ^ (8 * v67)) & 8;
    v70 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v65, (int)config, (unsigned int)"use_uv_scrolling") )
    {
      v69 = vostok::configs::binary_config_value::operator[](config, "use_uv_scrolling");
      if ( vostok::configs::binary_config_value::operator[](v69, "value")->data.pointer )
        v70 = 1;
    }
    v719[4] ^= (v719[4] ^ (4 * v70)) & 4;
    v73 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v68, (int)config, (unsigned int)"use_displacement") )
    {
      v72 = vostok::configs::binary_config_value::operator[](config, "use_displacement");
      if ( vostok::configs::binary_config_value::operator[](v72, "value")->data.pointer )
        v73 = 1;
    }
    v719[5] ^= (v719[5] ^ (8 * v73)) & 8;
    if ( vostok::configs::binary_config_value::value_exists(v71, (int)config, (unsigned int)"use_variation_mask")
      && vostok::configs::binary_config_value::value_exists(v74, (int)config, (unsigned int)"texture_variation_mask") )
    {
      v75 = vostok::configs::binary_config_value::operator[](config, "use_variation_mask");
      v78 = 0;
      if ( vostok::configs::binary_config_value::operator[](v75, "value")->data.pointer )
      {
        v76 = vostok::configs::binary_config_value::operator[](config, "texture_variation_mask");
        v77 = (const char **)vostok::configs::binary_config_value::operator[](v76, "value");
        if ( vostok::strings::compare(*v77, uri) )
          v78 = 1;
      }
      LOBYTE(v718) = (v718 ^ (2 * v78)) & 2 ^ v718;
    }
    if ( vostok::configs::binary_config_value::value_exists(v74, (int)config, (unsigned int)"wind_motion") )
    {
      v80 = vostok::configs::binary_config_value::operator[](config, "wind_motion");
      v81 = vostok::configs::binary_config_value::operator[](v80, "value");
      HIBYTE(v718) ^= (HIBYTE(v718) ^ (4 * LOBYTE(v81->data.pointer))) & 0x1C;
    }
    if ( !BYTE6(v706) )
    {
      v82 = vostok::configs::binary_config_value::operator[](config, "use_reflection");
      if ( vostok::configs::binary_config_value::operator[](v82, "value")->data.pointer )
      {
        BYTE2(v718) = BYTE2(v718) & 0x3F | 0x40;
        v83 = vostok::configs::binary_config_value::operator[](config, "use_reflection_diffuse");
        if ( vostok::configs::binary_config_value::operator[](v83, "value")->data.pointer )
          BYTE2(v718) = BYTE2(v718) & 0x3F | 0x80;
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v79, (int)config, (unsigned int)"is_anisotropic_material") )
    {
      v85 = vostok::configs::binary_config_value::operator[](config, "is_anisotropic_material");
      v86 = vostok::configs::binary_config_value::operator[](v85, "value")->data.pointer != 0;
    }
    else
    {
      v86 = 0;
    }
    v719[0] ^= (v719[0] ^ (v86 << 6)) & 0x40;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v84,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "gbuffer_pass",
      compiler,
      (const char *)&v717,
      config,
      (vostok::render::shader_configuration *)LODWORD(v669),
      (const vostok::configs::binary_config_value *)HIDWORD(v669));
    vostok::render::effect_compiler::set_stencil(
      v87,
      (int)compiler,
      1,
      0x81u,
      0xFFu,
      255,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_REPLACE,
      D3D11_STENCIL_OP_KEEP,
      SLODWORD(v670));
    if ( vostok::command_line::key::is_set(v88, (int)&s_z_only_0) )
    {
      vostok::render::effect_compiler::set_depth(v89, (int)compiler, 1, 0, SLODWORD(v670));
      vostok::render::effect_compiler::set_stencil(
        v90,
        (int)compiler,
        0,
        0,
        0,
        0,
        D3D11_COMPARISON_ALWAYS,
        D3D11_STENCIL_OP_KEEP,
        D3D11_STENCIL_OP_KEEP,
        v671);
    }
    else
    {
      vostok::render::effect_compiler::set_depth(v89, (int)compiler, 1, 1, SLODWORD(v670));
    }
    v92 = s_bm_current_air_resistance;
    v93 = s_bm_current_air_resistance;
    v745 = s_bm_current_air_resistance;
    v94 = s_bm_current_air_resistance;
    if ( (v718 & 0x20) != 0 )
    {
      v95 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_height");
      v96 = vostok::configs::binary_config_value::operator[](v95, "value");
      if ( v96->type == 2 )
        pointer = *(float *)&v96->data.pointer;
      else
        pointer = (float)(int)v96->data.pointer;
      v737 = pointer;
      v98 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_width");
      v99 = vostok::configs::binary_config_value::operator[](v98, "value");
      if ( v99->type == 2 )
        v100 = *(float *)&v99->data.pointer;
      else
        v100 = (float)(int)v99->data.pointer;
      v773[1] = v100;
      v755 = v100;
      v773[2] = v737;
      v741 = v100;
      v744 = v100;
      v742 = v737;
      v745 = v737;
      v101 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_play_speed");
      v102 = vostok::configs::binary_config_value::operator[](v101, "value");
      if ( v102->type == 2 )
        v103 = *(float *)&v102->data.pointer;
      else
        v103 = (float)(int)v102->data.pointer;
      v750 = v103;
      v104 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_start_frame_index");
      v105 = vostok::configs::binary_config_value::operator[](v104, "value");
      if ( v105->type == 2 )
        v107 = *(float *)&v105->data.pointer;
      else
        v107 = (float)(int)v105->data.pointer;
      v797.x = v755;
      *(_QWORD *)&v797.elements[1] = __PAIR64__(LODWORD(v107), LODWORD(v737));
      v797.w = v750;
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v797, v106, compiler, "sequence_parameters");
      v108 = 0;
      if ( vostok::configs::binary_config_value::value_exists(
             v109,
             (int)config,
             (unsigned int)"apply_sequence_to_normals_only") )
      {
        v111 = vostok::configs::binary_config_value::operator[](config, "apply_sequence_to_normals_only");
        v112 = vostok::configs::binary_config_value::operator[](v111, "value");
        v110 = v112->data.pointer != 0;
        v108 = v110;
        if ( v112->data.pointer )
        {
          v769[1] = s_bm_current_air_resistance;
          v769[2] = s_bm_current_air_resistance;
          v741 = s_bm_current_air_resistance;
          v742 = s_bm_current_air_resistance;
        }
      }
      binding.m_source.m_pointer = vostok::render::effect_constant_storage::store_constant<unsigned int>(
                                     (vostok::render::effect_constant_storage *)v110,
                                     (vostok::render::data_indexer *)LODWORD(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x),
                                     v108);
      binding.m_source.m_size = 4;
      vostok::shared_string::shared_string(v113, &binding.m_name.m_pointer, "apply_sequence_to_normals_only");
      binding.m_type = rc_int;
      binding.m_class_id = rc_1x1;
      vostok::render::effect_compiler::bind_constant(
        (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&binding,
        v114,
        compiler);
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
      v94 = v742;
      v93 = v744;
      if ( v741 > v742 )
      {
        v725 = v741;
        v92 = s_bm_current_air_resistance;
        goto LABEL_165;
      }
      v92 = s_bm_current_air_resistance;
    }
    v725 = v94;
LABEL_165:
    if ( v93 <= v745 )
      v732 = v745;
    else
      v732 = v93;
    v761.x = v92;
    *(_QWORD *)&v761.elements[1] = LODWORD(v92);
    if ( (v717 & 0x200000) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v91, (int)config, (unsigned int)"dark_border") )
      {
        v116 = vostok::configs::binary_config_value::operator[](config, "dark_border");
        v117 = vostok::configs::binary_config_value::operator[](v116, "value");
        if ( v117->type == 2 )
          v118 = *(float *)&v117->data.pointer;
        else
          v118 = (float)(int)v117->data.pointer;
        v761.x = v118;
      }
      if ( vostok::configs::binary_config_value::value_exists(v115, (int)config, (unsigned int)"light_border") )
      {
        v120 = vostok::configs::binary_config_value::operator[](config, "light_border");
        v121 = vostok::configs::binary_config_value::operator[](v120, "value");
        if ( v121->type == 2 )
          v122 = *(float *)&v121->data.pointer;
        else
          v122 = (float)(int)v121->data.pointer;
        v761.y = v122;
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v119,
             (int)config,
             (unsigned int)"texture_alpha_multiply_vertex_alpha") )
      {
        v123 = vostok::configs::binary_config_value::operator[](config, "texture_alpha_multiply_vertex_alpha");
        if ( vostok::configs::binary_config_value::operator[](v123, "value")->data.pointer )
        {
          v92 = s_bm_current_air_resistance;
          v761.z = s_bm_current_air_resistance;
          goto LABEL_184;
        }
        v761.z = 0.0;
      }
      v92 = s_bm_current_air_resistance;
    }
LABEL_184:
    if ( (v719[5] & 8) != 0 )
    {
      v752 = v92;
      v759 = FLOAT_0_25;
      v740 = v92;
      v754 = v92;
      v756 = v92;
      if ( vostok::configs::binary_config_value::value_exists(v91, (int)config, (unsigned int)"displacement_tile") )
      {
        v125 = vostok::configs::binary_config_value::operator[](config, "displacement_tile");
        v126 = vostok::configs::binary_config_value::operator[](v125, "value");
        if ( v126->type == 2 )
          v127 = *(float *)&v126->data.pointer;
        else
          v127 = (float)(int)v126->data.pointer;
        v752 = v127;
      }
      if ( vostok::configs::binary_config_value::value_exists(v124, (int)config, (unsigned int)"displacement_scale") )
      {
        v129 = vostok::configs::binary_config_value::operator[](config, "displacement_scale");
        v130 = vostok::configs::binary_config_value::operator[](v129, "value");
        if ( v130->type == 2 )
          v131 = *(float *)&v130->data.pointer;
        else
          v131 = (float)(int)v130->data.pointer;
        v759 = v131;
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v128,
             (int)config,
             (unsigned int)"displacement_sequence_array_width") )
      {
        v133 = vostok::configs::binary_config_value::operator[](config, "displacement_sequence_array_width");
        v134 = vostok::configs::binary_config_value::operator[](v133, "value");
        if ( v134->type == 2 )
          v135 = *(float *)&v134->data.pointer;
        else
          v135 = (float)(int)v134->data.pointer;
        v740 = v135;
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v132,
             (int)config,
             (unsigned int)"displacement_sequence_array_height") )
      {
        v137 = vostok::configs::binary_config_value::operator[](config, "displacement_sequence_array_height");
        v138 = vostok::configs::binary_config_value::operator[](v137, "value");
        if ( v138->type == 2 )
          v139 = *(float *)&v138->data.pointer;
        else
          v139 = (float)(int)v138->data.pointer;
        v754 = v139;
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v136,
             (int)config,
             (unsigned int)"displacement_sequence_play_speed") )
      {
        v141 = vostok::configs::binary_config_value::operator[](config, "displacement_sequence_play_speed");
        v142 = vostok::configs::binary_config_value::operator[](v141, "value");
        if ( v142->type == 2 )
          v143 = *(float *)&v142->data.pointer;
        else
          v143 = (float)(int)v142->data.pointer;
        v756 = v143;
      }
      vostok::render::effect_compiler::set_constant<float>(v140, &v752, compiler, "displacement_tile");
      vostok::render::effect_compiler::set_constant<float>(v144, &v759, compiler, "displacement_scale");
      vostok::render::effect_compiler::set_constant<float>(v145, &v740, compiler, "displacement_sequence_array_width");
      vostok::render::effect_compiler::set_constant<float>(v146, &v754, compiler, "displacement_sequence_array_height");
      vostok::render::effect_compiler::set_constant<float>(v147, &v756, compiler, "displacement_sequence_play_speed");
      if ( vostok::configs::binary_config_value::value_exists(v148, (int)config, (unsigned int)"displacement_texture") )
      {
        v149 = vostok::configs::binary_config_value::operator[](config, "displacement_texture");
        v150 = (char **)vostok::configs::binary_config_value::operator[](v149, "value");
        vostok::render::effect_compiler::set_texture(
          v151,
          (const char *)compiler,
          "t_displacement",
          *v150,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      &v761,
      (vostok::render::effect_constant_storage *)v91,
      compiler,
      "vertex_alpha_test_parameters");
    if ( vostok::configs::binary_config_value::value_exists(v152, (int)config, (unsigned int)"constant_tile_u")
      && vostok::configs::binary_config_value::value_exists(v153, (int)config, (unsigned int)"constant_tile_v") )
    {
      v154 = config;
      v155 = vostok::configs::binary_config_value::operator[](config, "constant_tile_v");
      v156 = vostok::configs::binary_config_value::operator[](v155, "value");
      if ( v156->type == 2 )
        v157 = *(float *)&v156->data.pointer;
      else
        v157 = (float)(int)v156->data.pointer;
      v758 = v157;
      v158 = vostok::configs::binary_config_value::operator[](config, "constant_tile_u");
      v159 = vostok::configs::binary_config_value::operator[](v158, "value");
      if ( v159->type == 2 )
        v160 = *(float *)&v159->data.pointer;
      else
        v160 = (float)(int)v159->data.pointer;
      *(float *)v780 = v160;
      *(float *)&v780[1] = v758;
      vostok::render::effect_compiler::set_constant<vostok::math::float2>(
        (vostok::render::effect_constant_storage *)v780,
        compiler,
        "constant_tile_uv");
    }
    else
    {
      *(float *)v779 = s_bm_current_air_resistance;
      *(float *)&v779[1] = s_bm_current_air_resistance;
      vostok::render::effect_compiler::set_constant<vostok::math::float2>(
        (vostok::render::effect_constant_storage *)v779,
        compiler,
        "constant_tile_uv");
      v154 = config;
    }
    v162 = (__m128i)LODWORD(FLOAT_0_25);
    v760 = FLOAT_0_25;
    if ( (v717 & 0x100000) != 0
      && vostok::configs::binary_config_value::value_exists(v161, (int)v154, (unsigned int)"alpha_ref") )
    {
      v163 = vostok::configs::binary_config_value::operator[](v154, "alpha_ref");
      v164 = vostok::configs::binary_config_value::operator[](v163, "value");
      if ( v164->type == 2 )
        v162 = (__m128i)(unsigned int)v164->data.pointer;
      else
        *(float *)v162.m128i_i32 = (float)(int)v164->data.pointer;
      v760 = *(float *)v162.m128i_i32;
    }
    vostok::render::effect_compiler::set_constant<float>(
      (vostok::render::effect_constant_storage *)v161,
      &v760,
      compiler,
      "alpha_ref_parameter");
    if ( (v719[4] & 0x10) != 0
      && vostok::configs::binary_config_value::value_exists(v165, (int)v154, (unsigned int)"fuzziness_saturation")
      && vostok::configs::binary_config_value::value_exists(v165, (int)v154, (unsigned int)"fuzziness_multiplier")
      && vostok::configs::binary_config_value::value_exists(v165, (int)v154, (unsigned int)"fuzziness_power") )
    {
      v166 = vostok::configs::binary_config_value::operator[](v154, "fuzziness_power");
      v167 = vostok::configs::binary_config_value::operator[](v166, "value");
      if ( v167->type == 2 )
        v168 = *(float *)&v167->data.pointer;
      else
        v168 = (float)(int)v167->data.pointer;
      v739 = v168;
      v169 = vostok::configs::binary_config_value::operator[](v154, "fuzziness_multiplier");
      v170 = vostok::configs::binary_config_value::operator[](v169, "value");
      if ( v170->type == 2 )
        v171 = *(float *)&v170->data.pointer;
      else
        v171 = (float)(int)v170->data.pointer;
      v751 = v171;
      v172 = vostok::configs::binary_config_value::operator[](v154, "fuzziness_saturation");
      v173 = vostok::configs::binary_config_value::operator[](v172, "value");
      if ( v173->type == 2 )
        v175 = *(float *)&v173->data.pointer;
      else
        v175 = (float)(int)v173->data.pointer;
      *(_QWORD *)&v791.x = __PAIR64__(LODWORD(v751), LODWORD(v175));
      v162 = (__m128i)LODWORD(v739);
      v791.z = v739;
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(&v791, v174, compiler, "fuzziness_parameters");
    }
    vostok::render::effect_compiler::set_texture(
      (vostok::render::effect_compiler *)v165,
      (const char *)compiler,
      "t_grass_motion_mask",
      "engine/test_grass_motion_mask",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( (v719[5] & 4) != 0
      && vostok::configs::binary_config_value::value_exists(v176, (int)v154, (unsigned int)"texture_transparency") )
    {
      v177 = vostok::configs::binary_config_value::operator[](v154, "texture_transparency");
      v178 = (char **)vostok::configs::binary_config_value::operator[](v177, "value");
      vostok::render::effect_compiler::set_texture(
        v179,
        (const char *)compiler,
        "t_transparency",
        *v178,
        num_last_mips_used,
        streaming_priority,
        0,
        v725);
    }
    if ( (v719[4] & 1) != 0 )
    {
      v180 = vostok::configs::binary_config_value::operator[](v154, "use_diffuse_color_mask_texture");
      v181 = (char **)vostok::configs::binary_config_value::operator[](v180, "value");
      vostok::render::effect_compiler::set_texture(
        v182,
        (const char *)compiler,
        "t_diffuse_color_mask",
        *v181,
        num_last_mips_used,
        streaming_priority,
        1u,
        1.0);
      if ( (v719[4] & 2) != 0 )
      {
        v184 = vostok::configs::binary_config_value::operator[](v154, "constant_diffuse_masked_hue");
        v185 = vostok::configs::binary_config_value::operator[](v184, "value");
        if ( v185->type == 2 )
          v162 = (__m128i)(unsigned int)v185->data.pointer;
        else
          *(float *)v162.m128i_i32 = (float)(int)v185->data.pointer;
        v770 = *(float *)v162.m128i_i32 * 3.1415927;
        *(double *)v162.m128i_i64 = (float)(*(float *)v162.m128i_i32 * 3.1415927);
        __libm_sse2_sin(v162);
        v186 = *(double *)v162.m128i_i64;
        v803 = v186;
        v187 = v770;
        __libm_sse2_cos(v670);
        v188 = v187;
        v790.z = s_bm_current_air_resistance;
        *(_QWORD *)&v790.x = 0;
        v788.x = s_bm_current_air_resistance - (float)(s_bm_current_air_resistance - v188);
        v788.y = (float)(s_bm_current_air_resistance - v188) - v803;
        v788.z = v803 + (float)(s_bm_current_air_resistance - v188);
        vostok::math::normalize_safe(&v788, &v790, &v762);
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v762,
          v189,
          compiler,
          "hue_matrix_component_x");
        *(_QWORD *)&v792.x = __PAIR64__(LODWORD(v762.x), LODWORD(v762.z));
        v792.z = v762.y;
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v792,
          v190,
          compiler,
          "hue_matrix_component_y");
        *(_QWORD *)&v785.x = *(_QWORD *)&v762.elements[1];
        v785.z = v762.x;
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v785,
          v191,
          compiler,
          "hue_matrix_component_z");
        v154 = config;
      }
      else
      {
        if ( vostok::configs::binary_config_value::value_exists(
               v183,
               (int)v154,
               (unsigned int)"constant_diffuse_color_mask_color") )
        {
          v193 = vostok::configs::binary_config_value::operator[](v154, "constant_diffuse_color_mask_color");
          v194 = vostok::configs::binary_config_value::operator[](v193, "value");
          v195 = (float *)v194->data.pointer;
          v196 = *(float *)v194->data.pointer;
          __libm_sse2_pow(v670, v706);
          *(float *)&v196 = v196;
          v795[0] = LODWORD(v196);
          v197 = v195[1];
          __libm_sse2_pow(v672, v707);
          *(float *)&v197 = v197;
          v795[1] = LODWORD(v197);
          v198 = v195[2];
          __libm_sse2_pow(v673, v708);
          *(float *)&v198 = v198;
          v795[2] = LODWORD(v198);
          *(float *)&v795[3] = v195[3];
          v199 = (const vostok::math::float3 *)v795;
        }
        else
        {
          memset(v787, 0, sizeof(v787));
          v199 = (const vostok::math::float3 *)v787;
        }
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          v199,
          v192,
          compiler,
          "constant_diffuse_mask_color");
      }
    }
    if ( (v719[4] & 8) != 0
      && vostok::configs::binary_config_value::value_exists(v176, (int)v154, (unsigned int)"normal_waves_moving_speed")
      && vostok::configs::binary_config_value::value_exists(v176, (int)v154, (unsigned int)"normal_waves_intensity")
      && vostok::configs::binary_config_value::value_exists(v176, (int)v154, (unsigned int)"normal_waves_tile") )
    {
      v200 = vostok::configs::binary_config_value::operator[](v154, "normal_waves_texture");
      v201 = (char **)vostok::configs::binary_config_value::operator[](v200, "value");
      vostok::render::effect_compiler::set_texture(
        v202,
        (const char *)compiler,
        "t_normal_waves",
        *v201,
        num_last_mips_used,
        streaming_priority,
        0,
        v732);
      v203 = vostok::configs::binary_config_value::operator[](v154, "normal_waves_tile");
      v204 = vostok::configs::binary_config_value::operator[](v203, "value");
      if ( v204->type == 2 )
        v205 = *(float *)&v204->data.pointer;
      else
        v205 = (float)(int)v204->data.pointer;
      v743 = v205;
      v206 = vostok::configs::binary_config_value::operator[](v154, "normal_waves_intensity");
      v207 = vostok::configs::binary_config_value::operator[](v206, "value");
      if ( v207->type == 2 )
        v208 = *(float *)&v207->data.pointer;
      else
        v208 = (float)(int)v207->data.pointer;
      v753 = v208;
      v209 = vostok::configs::binary_config_value::operator[](v154, "normal_waves_moving_speed");
      v210 = vostok::configs::binary_config_value::operator[](v209, "value");
      if ( v210->type == 2 )
        v212 = *(float *)&v210->data.pointer;
      else
        v212 = (float)(int)v210->data.pointer;
      *(_QWORD *)&v789.x = __PAIR64__(LODWORD(v753), LODWORD(v212));
      v789.z = v743;
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v789,
        v211,
        compiler,
        "normal_waves_parameters");
    }
    vostok::render::effect_compiler::set_constant<float>(
      (vostok::render::effect_constant_storage *)v176,
      &v776,
      compiler,
      "smoothness_multiplier");
    if ( (v717 & 0x80000) != 0 )
    {
      v214 = vostok::configs::binary_config_value::operator[](v154, "texture_diffuse");
      v215 = (char **)vostok::configs::binary_config_value::operator[](v214, "value");
      vostok::render::effect_compiler::set_texture(
        (vostok::render::effect_compiler *)(v721 + 1),
        (const char *)compiler,
        "t_base",
        *v215,
        num_last_mips_used,
        streaming_priority,
        v721 + 1,
        v725);
    }
    if ( (v718 & 8) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v213,
             (int)v154,
             (unsigned int)"texture_alphablended_diffuse") )
      {
        v217 = vostok::configs::binary_config_value::operator[](v154, "texture_alphablended_diffuse");
        v218 = (char **)vostok::configs::binary_config_value::operator[](v217, "value");
        vostok::render::effect_compiler::set_texture(
          (vostok::render::effect_compiler *)(v721 + 1),
          (const char *)compiler,
          "t_alphablended_diffuse",
          *v218,
          num_last_mips_used,
          streaming_priority,
          v721 + 1,
          v725);
      }
      if ( (v718 & 0x10) != 0
        && vostok::configs::binary_config_value::value_exists(
             v216,
             (int)v154,
             (unsigned int)"texture_alphablended_normal") )
      {
        v219 = vostok::configs::binary_config_value::operator[](v154, "texture_alphablended_normal");
        v220 = (char **)vostok::configs::binary_config_value::operator[](v219, "value");
        vostok::render::effect_compiler::set_texture(
          v221,
          (const char *)compiler,
          "t_alphablended_normal",
          *v220,
          num_last_mips_used,
          streaming_priority,
          0,
          v725);
      }
    }
    v222 = vostok::configs::binary_config_value::operator[](v154, "use_reflection");
    if ( vostok::configs::binary_config_value::operator[](v222, "value")->data.pointer )
    {
      if ( vostok::configs::binary_config_value::value_exists(v223, (int)v154, (unsigned int)"reflection_power") )
      {
        v225 = vostok::configs::binary_config_value::operator[](v154, "reflection_power");
        v226 = vostok::configs::binary_config_value::operator[](v225, "value");
        if ( v226->type == 2 )
          v228 = *(float *)&v226->data.pointer;
        else
          v228 = (float)(int)v226->data.pointer;
        v775 = v228;
        vostok::render::effect_compiler::set_constant<float>(v227, &v775, compiler, "reflection_power");
      }
      else
      {
        v766 = s_bm_current_air_resistance;
        vostok::render::effect_compiler::set_constant<float>(v224, &v766, compiler, "reflection_power");
      }
      if ( vostok::configs::binary_config_value::value_exists(v229, (int)v154, (unsigned int)"min_reflection_angle") )
      {
        v231 = vostok::configs::binary_config_value::operator[](v154, "min_reflection_angle");
        v232 = vostok::configs::binary_config_value::operator[](v231, "value");
        if ( v232->type == 2 )
          v234 = *(float *)&v232->data.pointer;
        else
          v234 = (float)(int)v232->data.pointer;
        v768 = (float)(v234 * 0.0055555557) * 3.1415927;
        vostok::render::effect_compiler::set_constant<float>(v233, &v768, compiler, "min_reflection_angle");
      }
      else
      {
        v772 = 0;
        vostok::render::effect_compiler::set_constant<float>(v230, (float *)&v772, compiler, "min_reflection_angle");
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v235,
             (int)v154,
             (unsigned int)"specular_color_multiplier") )
      {
        v237 = vostok::configs::binary_config_value::operator[](v154, "specular_color_multiplier");
        v238 = vostok::configs::binary_config_value::operator[](v237, "value");
        v239 = (float *)v238->data.pointer;
        v240 = *(float *)v238->data.pointer;
        __libm_sse2_pow(v670, v706);
        *(float *)&v240 = v240;
        v794.x = *(float *)&v240;
        v241 = v239[1];
        __libm_sse2_pow(v674, v709);
        *(float *)&v241 = v241;
        v794.y = *(float *)&v241;
        v242 = v239[2];
        __libm_sse2_pow(v675, v710);
        *(float *)&v242 = v242;
        v794.z = *(float *)&v242;
        v794.w = v239[3];
        vostok::render::effect_compiler::set_constant<vostok::math::float4>(
          &v794,
          v243,
          compiler,
          "specular_color_multiplier");
      }
      else
      {
        v796.x = s_bm_current_air_resistance;
        v796.y = s_bm_current_air_resistance;
        v796.z = s_bm_current_air_resistance;
        v796.w = s_bm_current_air_resistance;
        vostok::render::effect_compiler::set_constant<vostok::math::float4>(
          &v796,
          v236,
          compiler,
          "specular_color_multiplier");
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v223, (int)v154, (unsigned int)"wind_motion") )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v244,
             (int)v154,
             (unsigned int)"detailed_bend_parameters_frequency") )
      {
        v246 = vostok::configs::binary_config_value::operator[](v154, "detailed_bend_parameters_branch_amplitude");
        v247 = vostok::configs::binary_config_value::operator[](v246, "value");
        if ( v247->type == 2 )
          v248 = *(float *)&v247->data.pointer;
        else
          v248 = (float)(int)v247->data.pointer;
        v746 = v248;
        v249 = vostok::configs::binary_config_value::operator[](v154, "detailed_bend_parameters_leaf_amplitude");
        v250 = vostok::configs::binary_config_value::operator[](v249, "value");
        if ( v250->type == 2 )
          v251 = *(float *)&v250->data.pointer;
        else
          v251 = (float)(int)v250->data.pointer;
        v757 = v251;
        v252 = vostok::configs::binary_config_value::operator[](v154, "detailed_bend_parameters_frequency");
        v253 = vostok::configs::binary_config_value::operator[](v252, "value");
        if ( v253->type == 2 )
          v255 = *(float *)&v253->data.pointer;
        else
          v255 = (float)(int)v253->data.pointer;
        *(_QWORD *)&v793.x = __PAIR64__(LODWORD(v757), LODWORD(v255));
        v793.z = v746;
        vostok::render::effect_compiler::set_constant<vostok::math::float3>(
          &v793,
          v254,
          compiler,
          "detailed_bending_parameters");
      }
      v773[0] = s_bm_current_air_resistance;
      vostok::render::effect_compiler::set_constant<float>(v245, v773, compiler, "wind_scale");
    }
    if ( (v719[1] & 0x40) != 0
      && vostok::configs::binary_config_value::value_exists(
           v244,
           (int)v154,
           (unsigned int)"texture_vertex_blended_mask") )
    {
      v256 = vostok::configs::binary_config_value::operator[](v154, "texture_vertex_blended_mask");
      v257 = (char **)vostok::configs::binary_config_value::operator[](v256, "value");
      vostok::render::effect_compiler::set_texture(
        v258,
        (const char *)compiler,
        "t_vertex_blended_mask",
        *v257,
        num_last_mips_used,
        streaming_priority,
        1u,
        v725);
    }
    HIBYTE(v706) = (v719[1] & 0x20) != 0;
    if ( ((v719[1] & 0x20) != 0 || v719[1] < 0)
      && vostok::configs::binary_config_value::value_exists(
           v244,
           (int)v154,
           (unsigned int)"constant_vertex_blended_factor")
      && vostok::configs::binary_config_value::value_exists(
           v244,
           (int)v154,
           (unsigned int)"constant_vertex_blended_falloff")
      && vostok::configs::binary_config_value::value_exists(
           v244,
           (int)v154,
           (unsigned int)"constant_vertex_blended_tiling") )
    {
      v259 = vostok::configs::binary_config_value::operator[](v154, "constant_vertex_blended_tiling");
      v260 = vostok::configs::binary_config_value::operator[](v259, "value");
      if ( v260->type == 2 )
        v261 = *(float *)&v260->data.pointer;
      else
        v261 = (float)(int)v260->data.pointer;
      v748 = v261;
      v262 = vostok::configs::binary_config_value::operator[](v154, "constant_vertex_blended_falloff");
      v263 = vostok::configs::binary_config_value::operator[](v262, "value");
      if ( v263->type == 2 )
        v264 = *(float *)&v263->data.pointer;
      else
        v264 = (float)(int)v263->data.pointer;
      v747 = v264;
      v265 = vostok::configs::binary_config_value::operator[](v154, "constant_vertex_blended_factor");
      v266 = vostok::configs::binary_config_value::operator[](v265, "value");
      if ( v266->type == 2 )
        v268 = *(float *)&v266->data.pointer;
      else
        v268 = (float)(int)v266->data.pointer;
      *(_QWORD *)&v786.x = __PAIR64__(LODWORD(v747), LODWORD(v268));
      v786.z = v748;
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v786,
        v267,
        compiler,
        "vertex_blend_parameters");
    }
    if ( HIBYTE(v706)
      && vostok::configs::binary_config_value::value_exists(
           v244,
           (int)v154,
           (unsigned int)"texture_vertex_blended_diffuse") )
    {
      v269 = vostok::configs::binary_config_value::operator[](v154, "texture_vertex_blended_diffuse");
      v270 = (char **)vostok::configs::binary_config_value::operator[](v269, "value");
      vostok::render::effect_compiler::set_texture(
        v271,
        (const char *)compiler,
        "t_vertex_blended_diffuse",
        *v270,
        num_last_mips_used,
        streaming_priority,
        1u,
        v725);
    }
    if ( v719[1] < 0
      && vostok::configs::binary_config_value::value_exists(
           v244,
           (int)v154,
           (unsigned int)"texture_vertex_blended_normal") )
    {
      v272 = vostok::configs::binary_config_value::operator[](v154, "texture_vertex_blended_normal");
      v273 = (char **)vostok::configs::binary_config_value::operator[](v272, "value");
      vostok::render::effect_compiler::set_texture(
        v274,
        (const char *)compiler,
        "t_vertex_blended_normal",
        *v273,
        num_last_mips_used,
        streaming_priority,
        0,
        v732);
    }
    v275 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
    v276 = vostok::configs::binary_config_value::operator[](v275, "value");
    v277 = (float *)v276->data.pointer;
    v278 = *(float *)v276->data.pointer;
    __libm_sse2_pow(v670, v706);
    *(float *)&v278 = v278;
    LODWORD(v800) = LODWORD(v278);
    v279 = v277[1];
    __libm_sse2_pow(v676, v711);
    *(float *)&v279 = v279;
    HIDWORD(v800) = LODWORD(v279);
    v280 = v277[2];
    __libm_sse2_pow(v677, v712);
    *(float *)&v280 = v280;
    v801 = LODWORD(v280);
    v802 = *((_DWORD *)v277 + 3);
    *(_QWORD *)&v777.x = v800;
    *(_QWORD *)&v777.elements[2] = LODWORD(v280);
    v282 = config;
    if ( (v718 & 0xC00000) != 0 )
    {
      v283 = vostok::configs::binary_config_value::operator[](config, "texture_cubemap");
      v284 = (char *)vostok::configs::binary_config_value::operator[](v283, "value")->data.pointer;
      v668 = 1.0;
      if ( vostok::strings::compare(v284, uri) )
        vostok::render::effect_compiler::set_texture(
          v285,
          (const char *)compiler,
          "t_cubemap",
          v284,
          0,
          0xFFFFFFFF,
          0,
          v668);
      else
        vostok::render::effect_compiler::set_texture(
          v285,
          (const char *)compiler,
          "t_cubemap",
          "cubemap/reflect_blue",
          0,
          0xFFFFFFFF,
          0,
          v668);
      if ( (v718 & 0x40) != 0 )
      {
        v287 = vostok::configs::binary_config_value::operator[](config, "texture_cubemap_mask");
        v288 = (char **)vostok::configs::binary_config_value::operator[](v287, "value");
        vostok::render::effect_compiler::set_texture(
          v289,
          (const char *)compiler,
          "t_cubemap_mask",
          *v288,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      vostok::render::effect_compiler::set_texture(
        v286,
        (const char *)compiler,
        "t_frame_luminance",
        "$user$frame_luminance",
        0,
        0xFFFFFFFF,
        0,
        1.0);
      if ( vostok::configs::binary_config_value::value_exists(v290, (int)config, (unsigned int)"reflection_power") )
      {
        v292 = vostok::configs::binary_config_value::operator[](config, "reflection_power");
        v293 = vostok::configs::binary_config_value::operator[](v292, "value");
        if ( v293->type == 2 )
          v295 = *(float *)&v293->data.pointer;
        else
          v295 = (float)(int)v293->data.pointer;
        v767 = v295;
        vostok::render::effect_compiler::set_constant<float>(v294, &v767, compiler, "reflection_power");
      }
      else
      {
        v769[0] = s_bm_current_air_resistance;
        vostok::render::effect_compiler::set_constant<float>(v291, v769, compiler, "reflection_power");
      }
      if ( vostok::configs::binary_config_value::value_exists(v296, (int)config, (unsigned int)"min_reflection_angle") )
      {
        v298 = vostok::configs::binary_config_value::operator[](config, "min_reflection_angle");
        v299 = vostok::configs::binary_config_value::operator[](v298, "value");
        if ( v299->type == 2 )
          v301 = *(float *)&v299->data.pointer;
        else
          v301 = (float)(int)v299->data.pointer;
        v765 = (float)(v301 * 0.0055555557) * 3.1415927;
        vostok::render::effect_compiler::set_constant<float>(v300, &v765, compiler, "min_reflection_angle");
      }
      else
      {
        v771 = 0;
        vostok::render::effect_compiler::set_constant<float>(v297, (float *)&v771, compiler, "min_reflection_angle");
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v302,
             (int)config,
             (unsigned int)"specular_color_multiplier") )
      {
        v304 = vostok::configs::binary_config_value::operator[](config, "specular_color_multiplier");
        v305 = vostok::configs::binary_config_value::operator[](v304, "value");
        v306 = (float *)v305->data.pointer;
        v307 = *(float *)v305->data.pointer;
        __libm_sse2_pow(v669, v706);
        *(float *)&v307 = v307;
        v798.x = *(float *)&v307;
        v308 = v306[1];
        __libm_sse2_pow(v678, v713);
        *(float *)&v308 = v308;
        v798.y = *(float *)&v308;
        v309 = v306[2];
        __libm_sse2_pow(v679, v714);
        *(float *)&v309 = v309;
        v798.z = *(float *)&v309;
        v798.w = v306[3];
        vostok::render::effect_compiler::set_constant<vostok::math::float4>(
          &v798,
          v310,
          compiler,
          "specular_color_multiplier");
      }
      else
      {
        v799.x = s_bm_current_air_resistance;
        v799.y = s_bm_current_air_resistance;
        v799.z = s_bm_current_air_resistance;
        v799.w = s_bm_current_air_resistance;
        vostok::render::effect_compiler::set_constant<vostok::math::float4>(
          &v799,
          v303,
          compiler,
          "specular_color_multiplier");
      }
    }
    if ( (v717 & 0x800000) != 0 )
    {
      v311 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
      v312 = (char **)vostok::configs::binary_config_value::operator[](v311, "value");
      vostok::render::effect_compiler::set_texture(
        v313,
        (const char *)compiler,
        "t_normal",
        *v312,
        num_last_mips_used,
        streaming_priority,
        0,
        v732);
    }
    if ( (v717 & 0x1000000) != 0 )
    {
      v734.x = s_bm_current_air_resistance;
      v734.y = s_bm_current_air_resistance;
      v734.z = s_bm_current_air_resistance;
      v734.w = s_bm_current_air_resistance;
      if ( vostok::configs::binary_config_value::value_exists(v281, (int)config, (unsigned int)"texture_detail_normal") )
      {
        v315 = vostok::configs::binary_config_value::operator[](config, "texture_detail_normal");
        v316 = (char **)vostok::configs::binary_config_value::operator[](v315, "value");
        vostok::render::effect_compiler::set_texture(
          v317,
          (const char *)compiler,
          "t_detail_normal",
          *v316,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      if ( vostok::configs::binary_config_value::value_exists(v314, (int)config, (unsigned int)"scale_detail_normal") )
      {
        v319 = vostok::configs::binary_config_value::operator[](config, "scale_detail_normal");
        v320 = vostok::configs::binary_config_value::operator[](v319, "value");
        if ( v320->type == 2 )
          v321 = *(float *)&v320->data.pointer;
        else
          v321 = (float)(int)v320->data.pointer;
        v734.x = v321;
        v734.y = v321;
      }
      if ( vostok::configs::binary_config_value::value_exists(v318, (int)config, (unsigned int)"tile_detail_normal") )
      {
        v323 = vostok::configs::binary_config_value::operator[](config, "tile_detail_normal");
        v324 = vostok::configs::binary_config_value::operator[](v323, "value");
        if ( v324->type == 2 )
          v325 = *(float *)&v324->data.pointer;
        else
          v325 = (float)(int)v324->data.pointer;
        v734.z = v325;
        v734.w = v325;
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        &v734,
        v322,
        compiler,
        "detail_normal_parameters");
    }
    if ( (v717 & 0x2000000) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v281, (int)config, (unsigned int)"texture_ditail_diffuse") )
      {
        v327 = vostok::configs::binary_config_value::operator[](config, "texture_ditail_diffuse");
        v328 = (char **)vostok::configs::binary_config_value::operator[](v327, "value");
        vostok::render::effect_compiler::set_texture(
          v329,
          (const char *)compiler,
          "t_detail",
          *v328,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      if ( vostok::configs::binary_config_value::value_exists(
             v326,
             (int)config,
             (unsigned int)"constant_ditail_texture_tile") )
      {
        v330 = vostok::configs::binary_config_value::operator[](config, "constant_ditail_texture_tile");
        v331 = vostok::configs::binary_config_value::operator[](v330, "value");
        if ( v331->type == 2 )
          v333 = *(float *)&v331->data.pointer;
        else
          v333 = (float)(int)v331->data.pointer;
        v774 = v333;
        vostok::render::effect_compiler::set_constant<float>(v332, &v774, compiler, "ditail_texture_tile");
      }
    }
    if ( (v717 & 0x400000) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v281,
             (int)config,
             (unsigned int)"constant_parallax_scale") )
      {
        v334 = vostok::configs::binary_config_value::operator[](config, "constant_parallax_scale");
        v335 = vostok::configs::binary_config_value::operator[](v334, "value");
        if ( v335->type == 2 )
          v337 = *(float *)&v335->data.pointer;
        else
          v337 = (float)(int)v335->data.pointer;
        v727 = v337;
        vostok::render::effect_compiler::set_constant<float>(v336, &v727, compiler, "constant_parallax_scale");
      }
      v338 = vostok::configs::binary_config_value::operator[](config, "texture_bump");
      v339 = (char **)vostok::configs::binary_config_value::operator[](v338, "value");
      vostok::render::effect_compiler::set_texture(
        v340,
        (const char *)compiler,
        "t_height_map",
        *v339,
        num_last_mips_used,
        streaming_priority,
        1u,
        v725);
    }
    v763 = 0.0;
    v764 = s_bm_current_air_resistance;
    if ( (v717 & 0x8000000) != 0 )
    {
      v341 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
      v342 = (char **)vostok::configs::binary_config_value::operator[](v341, "value");
      vostok::render::effect_compiler::set_texture(
        v343,
        (const char *)compiler,
        "t_specular_intensity",
        *v342,
        num_last_mips_used,
        streaming_priority,
        0,
        v725);
      if ( vostok::configs::binary_config_value::value_exists(
             v344,
             (int)config,
             (unsigned int)"constant_specular_intensity_min") )
      {
        v345 = vostok::configs::binary_config_value::operator[](config, "constant_specular_intensity_min");
        v346 = vostok::configs::binary_config_value::operator[](v345, "value");
        if ( v346->type == 2 )
          v347 = *(float *)&v346->data.pointer;
        else
          v347 = (float)(int)v346->data.pointer;
        v749 = v347;
        v763 = v347;
        v348 = vostok::configs::binary_config_value::operator[](config, "constant_specular_intensity_max");
        v349 = vostok::configs::binary_config_value::operator[](v348, "value");
        if ( v349->type == 2 )
          v350 = *(float *)&v349->data.pointer;
        else
          v350 = (float)(int)v349->data.pointer;
        v764 = v350 - v749;
      }
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float2>(
      (vostok::render::effect_constant_storage *)&v763,
      compiler,
      "specular_intensity_ranges");
    if ( vostok::configs::binary_config_value::value_exists(v351, (int)config, (unsigned int)"constant_specular_color")
      && vostok::configs::binary_config_value::value_exists(
           v352,
           (int)config,
           (unsigned int)"constant_specular_color_multiplier") )
    {
      v353 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
      v354 = vostok::configs::binary_config_value::operator[](v353, "value");
      v355 = (float *)v354->data.pointer;
      v782 = *(float *)v354->data.pointer;
      v783 = *++v355;
      v784 = v355[1];
      v356 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
      v357 = (const vostok::math::float4 **)vostok::configs::binary_config_value::operator[](v356, "value");
      v358 = vostok::render::convert_to_linear_space(*v357);
      v730.x = v358->x * v782;
      v730.y = v358->y * v783;
      v730.z = v358->z * v784;
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v730,
        v359,
        compiler,
        "specular_color_parameter");
      v282 = config;
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      &v777,
      (vostok::render::effect_constant_storage *)v352,
      compiler,
      "solid_color_specular");
    v733.z = 0.0;
    memset(&v731, 0, sizeof(v731));
    if ( (v717 & 0x20000000) != 0 )
    {
      v361 = vostok::configs::binary_config_value::operator[](v282, "texture_roughness");
      v362 = (char **)vostok::configs::binary_config_value::operator[](v361, "value");
      vostok::render::effect_compiler::set_texture(
        v363,
        (const char *)compiler,
        "t_roughness",
        *v362,
        num_last_mips_used,
        streaming_priority,
        0,
        v725);
      if ( vostok::configs::binary_config_value::value_exists(v364, (int)v282, (unsigned int)"constant_roughness_min") )
      {
        v366 = vostok::configs::binary_config_value::operator[](v282, "constant_roughness_min");
        v367 = vostok::configs::binary_config_value::operator[](v366, "value");
        if ( v367->type == 2 )
          v368 = *(float *)&v367->data.pointer;
        else
          v368 = (float)(int)v367->data.pointer;
        v729 = v368;
        v731.z = v368;
        v369 = vostok::configs::binary_config_value::operator[](v282, "constant_roughness_max");
        v370 = vostok::configs::binary_config_value::operator[](v369, "value");
        if ( v370->type == 2 )
          v371 = *(float *)&v370->data.pointer;
        else
          v371 = (float)(int)v370->data.pointer;
        v731.w = v371 - v729;
      }
    }
    else if ( vostok::configs::binary_config_value::value_exists(v360, (int)v282, (unsigned int)"constant_roughness") )
    {
      v372 = vostok::configs::binary_config_value::operator[](v282, "constant_roughness");
      v373 = vostok::configs::binary_config_value::operator[](v372, "value");
      if ( v373->type == 2 )
        v374 = *(float *)&v373->data.pointer;
      else
        v374 = (float)(int)v373->data.pointer;
      v731.z = v374;
    }
    if ( (v717 & 0x10000000) != 0 )
    {
      v375 = vostok::configs::binary_config_value::operator[](v282, "texture_fresnel");
      v376 = (char **)vostok::configs::binary_config_value::operator[](v375, "value");
      vostok::render::effect_compiler::set_texture(
        v377,
        (const char *)compiler,
        "t_fresnel",
        *v376,
        num_last_mips_used,
        streaming_priority,
        0,
        v725);
      if ( vostok::configs::binary_config_value::value_exists(v378, (int)v282, (unsigned int)"constant_fresnel_min") )
      {
        v380 = vostok::configs::binary_config_value::operator[](v282, "constant_fresnel_min");
        v381 = vostok::configs::binary_config_value::operator[](v380, "value");
        if ( v381->type == 2 )
          v382 = *(float *)&v381->data.pointer;
        else
          v382 = (float)(int)v381->data.pointer;
        v724 = v382;
        v731.x = v382;
        v383 = vostok::configs::binary_config_value::operator[](v282, "constant_fresnel_max");
        v384 = vostok::configs::binary_config_value::operator[](v383, "value");
        if ( v384->type == 2 )
          v385 = *(float *)&v384->data.pointer;
        else
          v385 = (float)(int)v384->data.pointer;
        v731.y = v385 - v724;
      }
    }
    else if ( vostok::configs::binary_config_value::value_exists(v365, (int)v282, (unsigned int)"constant_fresnel") )
    {
      v386 = vostok::configs::binary_config_value::operator[](v282, "constant_fresnel");
      v387 = vostok::configs::binary_config_value::operator[](v386, "value");
      if ( v387->type == 2 )
        v388 = *(float *)&v387->data.pointer;
      else
        v388 = (float)(int)v387->data.pointer;
      v731.x = v388;
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      &v731,
      v379,
      compiler,
      "specular_fresnel_roughness_parameters");
    if ( (v717 & 0x4000000) != 0 )
    {
      v390 = vostok::configs::binary_config_value::operator[](v282, "texture_translucency");
      v391 = (char **)vostok::configs::binary_config_value::operator[](v390, "value");
      vostok::render::effect_compiler::set_texture(
        v392,
        (const char *)compiler,
        "t_translucency",
        *v391,
        num_last_mips_used,
        streaming_priority,
        0,
        v725);
      v393 = vostok::configs::binary_config_value::operator[](v282, "constant_translucency");
      v394 = vostok::configs::binary_config_value::operator[](v393, "value");
      if ( v394->type == 2 )
        v395 = *(float *)&v394->data.pointer;
      else
        v395 = (float)(int)v394->data.pointer;
      v733.z = v395;
    }
    if ( (v718 & 2) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v389,
             (int)v282,
             (unsigned int)"constant_variation_multiply") )
      {
        v397 = vostok::configs::binary_config_value::operator[](v282, "constant_variation_multiply");
        v398 = vostok::configs::binary_config_value::operator[](v397, "value");
        if ( v398->type == 2 )
          v399 = *(float *)&v398->data.pointer;
        else
          v399 = (float)(int)v398->data.pointer;
      }
      else
      {
        v399 = s_bm_current_air_resistance;
      }
      *((float *)&v735 + 1) = v399;
      if ( vostok::configs::binary_config_value::value_exists(v396, (int)v282, (unsigned int)"constant_variation_scale") )
      {
        v401 = vostok::configs::binary_config_value::operator[](v282, "constant_variation_scale");
        v402 = vostok::configs::binary_config_value::operator[](v401, "value");
        if ( v402->type == 2 )
          v403 = *(float *)&v402->data.pointer;
        else
          v403 = (float)(int)v402->data.pointer;
      }
      else
      {
        v403 = s_bm_current_air_resistance;
      }
      *(float *)&v735 = v403;
      if ( vostok::configs::binary_config_value::value_exists(
             v400,
             (int)v282,
             (unsigned int)"constant_variation_rotate") )
      {
        v405 = vostok::configs::binary_config_value::operator[](v282, "constant_variation_rotate");
        v406 = vostok::configs::binary_config_value::operator[](v405, "value");
        if ( v406->type == 2 )
          v407 = *(float *)&v406->data.pointer;
        else
          v407 = (float)(int)v406->data.pointer;
      }
      else
      {
        v407 = s_bm_current_air_resistance;
      }
      v736 = v407;
      if ( vostok::configs::binary_config_value::value_exists(
             v404,
             (int)v282,
             (unsigned int)"constant_variation_position_devider") )
      {
        v409 = vostok::configs::binary_config_value::operator[](v282, "constant_variation_position_devider");
        v410 = vostok::configs::binary_config_value::operator[](v409, "value");
        if ( v410->type == 2 )
          v411 = *(float *)&v410->data.pointer;
        else
          v411 = (float)(int)v410->data.pointer;
      }
      else
      {
        v411 = s_bm_current_air_resistance;
      }
      *(_QWORD *)&v738.x = __PAIR64__(LODWORD(v736), LODWORD(v411));
      *(_QWORD *)&v738.elements[2] = v735;
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        &v738,
        v408,
        compiler,
        "packed_variation_mask_parameters");
      if ( vostok::configs::binary_config_value::value_exists(v412, (int)v282, (unsigned int)"constant_variation_color") )
      {
        v414 = vostok::configs::binary_config_value::operator[](config, "constant_variation_color");
        v415 = (const vostok::math::float4 **)vostok::configs::binary_config_value::operator[](v414, "value");
        v416 = vostok::render::convert_to_linear_space(*v415);
        vostok::render::effect_compiler::set_constant<vostok::math::float4>(v416, v417, compiler, "variation_color");
        v282 = config;
      }
      if ( vostok::configs::binary_config_value::value_exists(v413, (int)v282, (unsigned int)"texture_variation_mask") )
      {
        v419 = vostok::configs::binary_config_value::operator[](v282, "texture_variation_mask");
        v420 = (char **)vostok::configs::binary_config_value::operator[](v419, "value");
        vostok::render::effect_compiler::set_texture(
          v421,
          (const char *)compiler,
          "t_variation_mask",
          *v420,
          num_last_mips_used,
          streaming_priority,
          0,
          v725);
      }
      else
      {
        vostok::render::effect_compiler::set_texture(
          v418,
          (const char *)compiler,
          "t_variation_mask",
          (char *)uri,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
    }
    memset(&v728, 0, sizeof(v728));
    *(_QWORD *)&v778.x = 0;
    if ( (v719[4] & 4) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v389,
             (int)v282,
             (unsigned int)"normal_map_scroll_u_direction") )
      {
        v423 = vostok::configs::binary_config_value::operator[](v282, "normal_map_scroll_u_direction");
        v424 = vostok::configs::binary_config_value::operator[](v423, "value");
        if ( v424->type == 2 )
          v425 = *(float *)&v424->data.pointer;
        else
          v425 = (float)(int)v424->data.pointer;
      }
      else
      {
        v425 = 0.0;
      }
      v728.x = v425;
      if ( vostok::configs::binary_config_value::value_exists(
             v422,
             (int)v282,
             (unsigned int)"normal_map_scroll_v_direction") )
      {
        v427 = vostok::configs::binary_config_value::operator[](v282, "normal_map_scroll_v_direction");
        v428 = vostok::configs::binary_config_value::operator[](v427, "value");
        if ( v428->type == 2 )
          v429 = *(float *)&v428->data.pointer;
        else
          v429 = (float)(int)v428->data.pointer;
      }
      else
      {
        v429 = 0.0;
      }
      v728.y = v429;
      if ( vostok::configs::binary_config_value::value_exists(
             v426,
             (int)v282,
             (unsigned int)"all_maps_scroll_u_direction") )
      {
        v431 = vostok::configs::binary_config_value::operator[](v282, "all_maps_scroll_u_direction");
        v432 = vostok::configs::binary_config_value::operator[](v431, "value");
        if ( v432->type == 2 )
          v433 = *(float *)&v432->data.pointer;
        else
          v433 = (float)(int)v432->data.pointer;
      }
      else
      {
        v433 = 0.0;
      }
      v728.z = v433;
      if ( vostok::configs::binary_config_value::value_exists(
             v430,
             (int)v282,
             (unsigned int)"all_maps_scroll_v_direction") )
      {
        v435 = vostok::configs::binary_config_value::operator[](v282, "all_maps_scroll_v_direction");
        v436 = vostok::configs::binary_config_value::operator[](v435, "value");
        if ( v436->type == 2 )
          v437 = *(float *)&v436->data.pointer;
        else
          v437 = (float)(int)v436->data.pointer;
      }
      else
      {
        v437 = 0.0;
      }
      v728.w = v437;
      if ( vostok::configs::binary_config_value::value_exists(
             v434,
             (int)v282,
             (unsigned int)"emissive_map_scroll_u_direction") )
      {
        v439 = vostok::configs::binary_config_value::operator[](v282, "emissive_map_scroll_u_direction");
        v440 = vostok::configs::binary_config_value::operator[](v439, "value");
        if ( v440->type == 2 )
          v441 = *(float *)&v440->data.pointer;
        else
          v441 = (float)(int)v440->data.pointer;
      }
      else
      {
        v441 = 0.0;
      }
      v778.x = v441;
      if ( vostok::configs::binary_config_value::value_exists(
             v438,
             (int)v282,
             (unsigned int)"emissive_map_scroll_v_direction") )
      {
        v442 = vostok::configs::binary_config_value::operator[](v282, "emissive_map_scroll_v_direction");
        v443 = vostok::configs::binary_config_value::operator[](v442, "value");
        if ( v443->type == 2 )
          v444 = *(float *)&v443->data.pointer;
        else
          v444 = (float)(int)v443->data.pointer;
      }
      else
      {
        v444 = 0.0;
      }
      v778.y = v444;
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      &v728,
      (vostok::render::effect_constant_storage *)v389,
      compiler,
      "uv_scrolling_parameters0");
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      &v778,
      v445,
      compiler,
      "uv_scrolling_parameters1");
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v733, v446, compiler, "solid_material_params");
    vostok::render::effect_material_base::compile_end(v447, compiler);
    ++i;
  }
  while ( i < 3 );
  vostok::render::shader_configuration::shader_configuration(v448, (int)&v777);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v449,
    (vostok::render::effect_material_base *)"vertex_base_lpv",
    "fill_reflective_shadow_map_backed",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v777,
    config,
    (const vostok::configs::binary_config_value *)LODWORD(v669));
  vostok::render::effect_material_base::compile_end(v450, compiler);
  vostok::render::shader_configuration::shader_configuration(v451, (int)&v733);
  v452 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  v453 = vostok::configs::binary_config_value::operator[](v452, "value");
  BYTE2(v733.elements[0]) ^= (BYTE2(v733.elements[0]) ^ (8 * (v453->data.pointer != 0))) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v454,
    (vostok::render::effect_material_base *)&stru_812848,
    (char *)&stru_812848,
    (char *)compiler,
    (vostok::render::effect_compiler *)&v733,
    config,
    v680);
  vostok::render::effect_compiler::set_depth(v455, (int)compiler, 0, 0, v681);
  vostok::render::effect_compiler::set_stencil(
    v456,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v682);
  if ( (BYTE2(v733.elements[0]) & 8) != 0 )
  {
    v458 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v459 = (char **)vostok::configs::binary_config_value::operator[](v458, "value");
    vostok::render::effect_compiler::set_texture(
      v460,
      (const char *)compiler,
      "t_base",
      *v459,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v457, (int)config, (unsigned int)"constant_diffuse") )
  {
    v462 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
    v463 = (const vostok::math::float4 **)vostok::configs::binary_config_value::operator[](v462, "value");
    v464 = (const vostok::math::float3 *)vostok::render::convert_to_linear_space(*v463);
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(v464, v465, compiler, "diffuse_color_parameter");
  }
  else
  {
    v730.x = s_bm_current_air_resistance;
    v730.y = s_bm_current_air_resistance;
    v730.z = s_bm_current_air_resistance;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      &v730,
      v461,
      compiler,
      "diffuse_color_parameter");
  }
  vostok::render::effect_material_base::compile_end(v466, compiler);
  vostok::render::shader_configuration::shader_configuration(v467, (int)&v733);
  v468 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  v469 = vostok::configs::binary_config_value::operator[](v468, "value");
  BYTE2(v733.elements[0]) ^= (BYTE2(v733.elements[0]) ^ (8 * (v469->data.pointer != 0))) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v470,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "fill_reflective_shadow_map",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v733,
    config,
    v683);
  if ( (BYTE2(v733.elements[0]) & 8) != 0 )
  {
    v472 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v473 = (char **)vostok::configs::binary_config_value::operator[](v472, "value");
    vostok::render::effect_compiler::set_texture(
      v474,
      (const char *)compiler,
      "t_base",
      *v473,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v471, (int)config, (unsigned int)"constant_diffuse") )
  {
    v476 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
    v477 = (const vostok::math::float4 **)vostok::configs::binary_config_value::operator[](v476, "value");
    v478 = (const vostok::math::float3 *)vostok::render::convert_to_linear_space(*v477);
  }
  else
  {
    v730.x = s_bm_current_air_resistance;
    v730.y = s_bm_current_air_resistance;
    v730.z = s_bm_current_air_resistance;
    v478 = &v730;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(v478, v475, compiler, "diffuse_color_parameter");
  vostok::render::effect_material_base::compile_end(v479, compiler);
  vostok::render::shader_configuration::shader_configuration(v480, (int)&v717);
  v481 = vostok::configs::binary_config_value::operator[](config, "use_emissive");
  if ( vostok::configs::binary_config_value::operator[](v481, "value")->data.pointer )
  {
    v483 = vostok::configs::binary_config_value::operator[](config, "use_emissive_map");
    v484 = vostok::configs::binary_config_value::operator[](v483, "value");
    HIBYTE(v718) ^= (HIBYTE(v718) ^ ((v484->data.pointer != 0) + 1)) & 3;
  }
  if ( vostok::configs::binary_config_value::value_exists(v482, (int)config, (unsigned int)"wind_motion") )
  {
    v486 = vostok::configs::binary_config_value::operator[](config, "wind_motion");
    v487 = vostok::configs::binary_config_value::operator[](v486, "value");
    HIBYTE(v718) ^= (HIBYTE(v718) ^ (4 * LOBYTE(v487->data.pointer))) & 0x1C;
  }
  v490 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v485, (int)config, (unsigned int)"use_uv_scrolling") )
  {
    v489 = vostok::configs::binary_config_value::operator[](config, "use_uv_scrolling");
    if ( vostok::configs::binary_config_value::operator[](v489, "value")->data.pointer )
      v490 = 1;
  }
  v719[4] ^= (v719[4] ^ (4 * v490)) & 4;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v488,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "gbuffer_emissive_pass",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v717,
    config,
    v684);
  vostok::render::effect_compiler::set_depth(v491, (int)compiler, 1, 0, v685);
  vostok::render::effect_compiler::set_stencil(
    v492,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v686);
  v721 = HIBYTE(v718) & 3;
  if ( (v718 & 0x3000000) != 0 )
  {
    v494 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
    v495 = vostok::configs::binary_config_value::operator[](v494, "value");
    if ( v495->type == 2 )
      v496 = *(float *)&v495->data.pointer;
    else
      v496 = (float)(int)v495->data.pointer;
    v724 = v496;
    v497 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
    v498 = (const vostok::math::float4 **)vostok::configs::binary_config_value::operator[](v497, "value");
    v728 = *vostok::render::convert_to_linear_space(*v498);
    v728.x = v728.x * v724;
    v728.y = v724 * v728.y;
    v728.z = v724 * v728.z;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v728, v499, compiler, "solid_emission_color");
  }
  if ( vostok::configs::binary_config_value::value_exists(v493, (int)config, (unsigned int)"wind_motion") )
  {
    if ( vostok::configs::binary_config_value::value_exists(
           v500,
           (int)config,
           (unsigned int)"detailed_bend_parameters_frequency") )
    {
      v502 = vostok::configs::binary_config_value::operator[](config, "detailed_bend_parameters_branch_amplitude");
      v503 = vostok::configs::binary_config_value::operator[](v502, "value");
      if ( v503->type == 2 )
        v504 = *(float *)&v503->data.pointer;
      else
        v504 = (float)(int)v503->data.pointer;
      v729 = v504;
      v505 = vostok::configs::binary_config_value::operator[](config, "detailed_bend_parameters_leaf_amplitude");
      v506 = vostok::configs::binary_config_value::operator[](v505, "value");
      if ( v506->type == 2 )
        v507 = *(float *)&v506->data.pointer;
      else
        v507 = (float)(int)v506->data.pointer;
      v724 = v507;
      v508 = vostok::configs::binary_config_value::operator[](config, "detailed_bend_parameters_frequency");
      v509 = vostok::configs::binary_config_value::operator[](v508, "value");
      if ( v509->type == 2 )
        v511 = *(float *)&v509->data.pointer;
      else
        v511 = (float)(int)v509->data.pointer;
      *(_QWORD *)&v730.x = __PAIR64__(LODWORD(v724), LODWORD(v511));
      v730.z = v729;
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v730,
        v510,
        compiler,
        "detailed_bending_parameters");
    }
    v727 = s_bm_current_air_resistance;
    vostok::render::effect_compiler::set_constant<float>(v501, &v727, compiler, "wind_scale");
  }
  memset(&v728, 0, sizeof(v728));
  memset(&v734, 0, sizeof(v734));
  if ( (v719[4] & 4) != 0 )
  {
    if ( vostok::configs::binary_config_value::value_exists(
           v500,
           (int)config,
           (unsigned int)"normal_map_scroll_u_direction") )
    {
      v513 = vostok::configs::binary_config_value::operator[](config, "normal_map_scroll_u_direction");
      v514 = vostok::configs::binary_config_value::operator[](v513, "value");
      if ( v514->type == 2 )
        v515 = *(float *)&v514->data.pointer;
      else
        v515 = (float)(int)v514->data.pointer;
    }
    else
    {
      v515 = 0.0;
    }
    v728.x = v515;
    if ( vostok::configs::binary_config_value::value_exists(
           v512,
           (int)config,
           (unsigned int)"normal_map_scroll_v_direction") )
    {
      v517 = vostok::configs::binary_config_value::operator[](config, "normal_map_scroll_v_direction");
      v518 = vostok::configs::binary_config_value::operator[](v517, "value");
      if ( v518->type == 2 )
        v519 = *(float *)&v518->data.pointer;
      else
        v519 = (float)(int)v518->data.pointer;
    }
    else
    {
      v519 = 0.0;
    }
    v728.y = v519;
    if ( vostok::configs::binary_config_value::value_exists(
           v516,
           (int)config,
           (unsigned int)"all_maps_scroll_u_direction") )
    {
      v521 = vostok::configs::binary_config_value::operator[](config, "all_maps_scroll_u_direction");
      v522 = vostok::configs::binary_config_value::operator[](v521, "value");
      if ( v522->type == 2 )
        v523 = *(float *)&v522->data.pointer;
      else
        v523 = (float)(int)v522->data.pointer;
    }
    else
    {
      v523 = 0.0;
    }
    v728.z = v523;
    if ( vostok::configs::binary_config_value::value_exists(
           v520,
           (int)config,
           (unsigned int)"all_maps_scroll_v_direction") )
    {
      v525 = vostok::configs::binary_config_value::operator[](config, "all_maps_scroll_v_direction");
      v526 = vostok::configs::binary_config_value::operator[](v525, "value");
      if ( v526->type == 2 )
        v527 = *(float *)&v526->data.pointer;
      else
        v527 = (float)(int)v526->data.pointer;
    }
    else
    {
      v527 = 0.0;
    }
    v728.w = v527;
    if ( vostok::configs::binary_config_value::value_exists(
           v524,
           (int)config,
           (unsigned int)"emissive_map_scroll_u_direction") )
    {
      v529 = vostok::configs::binary_config_value::operator[](config, "emissive_map_scroll_u_direction");
      v530 = vostok::configs::binary_config_value::operator[](v529, "value");
      if ( v530->type == 2 )
        v531 = *(float *)&v530->data.pointer;
      else
        v531 = (float)(int)v530->data.pointer;
    }
    else
    {
      v531 = 0.0;
    }
    v734.x = v531;
    if ( vostok::configs::binary_config_value::value_exists(
           v528,
           (int)config,
           (unsigned int)"emissive_map_scroll_v_direction") )
    {
      v532 = vostok::configs::binary_config_value::operator[](config, "emissive_map_scroll_v_direction");
      v533 = vostok::configs::binary_config_value::operator[](v532, "value");
      if ( v533->type == 2 )
        v534 = *(float *)&v533->data.pointer;
      else
        v534 = (float)(int)v533->data.pointer;
    }
    else
    {
      v534 = 0.0;
    }
    *(_QWORD *)&v734.elements[1] = LODWORD(v534);
    v734.w = 0.0;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v728,
    (vostok::render::effect_constant_storage *)v500,
    compiler,
    "uv_scrolling_parameters0");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v734, v535, compiler, "uv_scrolling_parameters1");
  vostok::render::effect_compiler::set_alpha_blend(
    v536,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v687);
  if ( v721 == 2 )
  {
    v538 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v539 = (char **)vostok::configs::binary_config_value::operator[](v538, "value");
    vostok::render::effect_compiler::set_texture(
      v540,
      (const char *)compiler,
      "t_emission",
      *v539,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  vostok::render::effect_material_base::compile_end(v537, compiler);
  vostok::render::shader_configuration::shader_configuration(v541, (int)&v731);
  if ( vostok::configs::binary_config_value::value_exists(v542, (int)config, (unsigned int)"use_alpha_test") )
  {
    v544 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v545 = vostok::configs::binary_config_value::operator[](v544, "value")->data.pointer != 0;
  }
  else
  {
    v545 = 0;
  }
  BYTE2(v731.elements[0]) ^= (BYTE2(v731.elements[0]) ^ (16 * v545)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v543, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v547 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v548 = vostok::configs::binary_config_value::operator[](v547, "value")->data.pointer != 0;
  }
  else
  {
    v548 = 0;
  }
  BYTE2(v731.elements[0]) ^= (BYTE2(v731.elements[0]) ^ (8 * v548)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v546,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "motion_vectors_accumulation",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v731,
    config,
    v688);
  vostok::render::effect_compiler::set_depth(v549, (int)compiler, 1, 0, v689);
  v724 = FLOAT_0_25;
  if ( (BYTE2(v731.elements[0]) & 8) != 0 )
  {
    v551 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v552 = (char **)vostok::configs::binary_config_value::operator[](v551, "value");
    vostok::render::effect_compiler::set_texture(
      v553,
      (const char *)compiler,
      "t_base",
      *v552,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( (BYTE2(v731.elements[0]) & 0x10) != 0
    && vostok::configs::binary_config_value::value_exists(v550, (int)config, (unsigned int)"alpha_ref") )
  {
    v554 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    v555 = vostok::configs::binary_config_value::operator[](v554, "value");
    if ( v555->type == 2 )
      v556 = *(float *)&v555->data.pointer;
    else
      v556 = (float)(int)v555->data.pointer;
    v724 = v556;
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v550,
    &v724,
    compiler,
    "alpha_ref_parameter");
  vostok::render::effect_material_base::compile_end(v557, compiler);
  vostok::render::shader_configuration::shader_configuration(v558, (int)&v717);
  if ( vostok::configs::binary_config_value::value_exists(v559, (int)config, (unsigned int)"use_alpha_test") )
  {
    v561 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v562 = vostok::configs::binary_config_value::operator[](v561, "value")->data.pointer != 0;
  }
  else
  {
    v562 = 0;
  }
  BYTE2(v717) ^= (BYTE2(v717) ^ (16 * v562)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v560, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v564 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v565 = vostok::configs::binary_config_value::operator[](v564, "value")->data.pointer != 0;
  }
  else
  {
    v565 = 0;
  }
  BYTE2(v717) ^= (BYTE2(v717) ^ (8 * v565)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v563, (int)config, (unsigned int)"use_thickness_map") )
  {
    v567 = vostok::configs::binary_config_value::operator[](config, "use_thickness_map");
    v568 = vostok::configs::binary_config_value::operator[](v567, "value")->data.pointer != 0;
  }
  else
  {
    v568 = 0;
  }
  LOBYTE(v566) = (v568 ^ v719[5]) & 1;
  v719[5] ^= (unsigned __int8)v566;
  if ( vostok::configs::binary_config_value::value_exists(
         v566,
         (int)config,
         (unsigned int)"use_subsurface_scattering_mask_map") )
  {
    v570 = vostok::configs::binary_config_value::operator[](config, "use_subsurface_scattering_mask_map");
    v571 = vostok::configs::binary_config_value::operator[](v570, "value")->data.pointer != 0;
  }
  else
  {
    v571 = 0;
  }
  v719[5] ^= (v719[5] ^ (2 * v571)) & 2;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v569,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "subsurface_scattering",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v717,
    config,
    v690);
  vostok::render::effect_compiler::set_depth(v572, (int)compiler, 1, 0, v691);
  vostok::render::effect_compiler::set_alpha_blend(
    v573,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v692);
  v724 = FLOAT_0_25;
  if ( (v717 & 0x80000) != 0 )
  {
    v575 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v576 = (char **)vostok::configs::binary_config_value::operator[](v575, "value");
    vostok::render::effect_compiler::set_texture(
      v577,
      (const char *)compiler,
      "t_base",
      *v576,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( (v717 & 0x100000) != 0
    && vostok::configs::binary_config_value::value_exists(v574, (int)config, (unsigned int)"alpha_ref") )
  {
    v578 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    v579 = vostok::configs::binary_config_value::operator[](v578, "value");
    if ( v579->type == 2 )
      v580 = *(float *)&v579->data.pointer;
    else
      v580 = (float)(int)v579->data.pointer;
    v724 = v580;
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v574,
    &v724,
    compiler,
    "alpha_ref_parameter");
  vostok::render::effect_compiler::set_texture(
    v581,
    (const char *)compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v582,
    (const char *)compiler,
    "t_specular_lighting",
    "$user$accum_specular",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v583,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v584,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v585,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v586,
    (const char *)compiler,
    "t_sun_shadow_and_scattering",
    "$user$sun_shadow_and_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v587,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v719[5] & 1) != 0 )
  {
    v589 = vostok::configs::binary_config_value::operator[](config, "texture_thickness");
    v590 = (char **)vostok::configs::binary_config_value::operator[](v589, "value");
    vostok::render::effect_compiler::set_texture(
      v591,
      (const char *)compiler,
      "t_thickness",
      *v590,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( (v719[5] & 2) != 0 )
  {
    v592 = vostok::configs::binary_config_value::operator[](config, "texture_sss_mask");
    v593 = (char **)vostok::configs::binary_config_value::operator[](v592, "value");
    vostok::render::effect_compiler::set_texture(
      v594,
      (const char *)compiler,
      "t_sss_mask",
      *v593,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  vostok::render::effect_material_base::compile_end(v588, compiler);
  vostok::render::shader_configuration::shader_configuration(v595, (int)&v717);
  if ( vostok::configs::binary_config_value::value_exists(v596, (int)config, (unsigned int)"use_alpha_test") )
  {
    v598 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v599 = vostok::configs::binary_config_value::operator[](v598, "value")->data.pointer != 0;
  }
  else
  {
    v599 = 0;
  }
  BYTE2(v717) ^= (BYTE2(v717) ^ (16 * v599)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v597, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v601 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v602 = vostok::configs::binary_config_value::operator[](v601, "value")->data.pointer != 0;
  }
  else
  {
    v602 = 0;
  }
  BYTE2(v717) ^= (BYTE2(v717) ^ (8 * v602)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v600, (int)config, (unsigned int)"wind_motion") )
  {
    v604 = vostok::configs::binary_config_value::operator[](config, "wind_motion");
    v605 = vostok::configs::binary_config_value::operator[](v604, "value");
    HIBYTE(v718) ^= (HIBYTE(v718) ^ (4 * LOBYTE(v605->data.pointer))) & 0x1C;
  }
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v603,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "z_only",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v717,
    config,
    v693);
  if ( (v718 & 0x1C000000) != 0
    && vostok::configs::binary_config_value::value_exists(v606, (int)config, (unsigned int)"wind_scale") )
  {
    v607 = vostok::configs::binary_config_value::operator[](config, "wind_scale");
    v608 = vostok::configs::binary_config_value::operator[](v607, "value");
    if ( v608->type == 2 )
      v609 = *(float *)&v608->data.pointer;
    else
      v609 = (float)(int)v608->data.pointer;
  }
  else
  {
    v609 = s_bm_current_air_resistance;
  }
  v727 = v609;
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v606,
    &v727,
    compiler,
    "wind_scale");
  vostok::render::effect_compiler::set_stencil(
    v610,
    (int)compiler,
    1,
    0x81u,
    0xFFu,
    255,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    D3D11_STENCIL_OP_KEEP,
    v694);
  vostok::render::effect_compiler::set_depth(v611, (int)compiler, 1, 1, v695);
  vostok::render::effect_compiler::color_write_enable(v612, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_material_base::compile_end(v613, compiler);
  vostok::render::shader_configuration::shader_configuration(v614, (int)&v738);
  if ( vostok::configs::binary_config_value::value_exists(v615, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v617 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v618 = vostok::configs::binary_config_value::operator[](v617, "value")->data.pointer != 0;
  }
  else
  {
    v618 = 0;
  }
  BYTE2(v738.elements[0]) ^= (BYTE2(v738.elements[0]) ^ (8 * v618)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v616,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "bake_decal_accumulate",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v738,
    config,
    v696);
  vostok::render::effect_compiler::set_depth(v619, (int)compiler, 0, 0, v697);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v620);
  vostok::render::effect_compiler::set_alpha_blend(
    v621,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v698);
  vostok::render::effect_material_base::compile_end(v622, compiler);
  vostok::render::shader_configuration::shader_configuration(v623, (int)&v777);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v624,
    (vostok::render::effect_material_base *)&stru_8129E4,
    "bake_decal_occlusion",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v777,
    config,
    v699);
  vostok::render::effect_compiler::set_depth(v625, (int)compiler, 1, 1, v700);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v626);
  vostok::render::effect_compiler::color_write_enable(v627, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_material_base::compile_end(v628, compiler);
  vostok::render::shader_configuration::shader_configuration(v629, (int)&v717);
  if ( vostok::configs::binary_config_value::value_exists(v630, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v632 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v633 = vostok::configs::binary_config_value::operator[](v632, "value")->data.pointer != 0;
  }
  else
  {
    v633 = 0;
  }
  BYTE2(v717) ^= (BYTE2(v717) ^ (8 * v633)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v631, (int)config, (unsigned int)"use_nmap") )
  {
    v635 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
    v636 = vostok::configs::binary_config_value::operator[](v635, "value")->data.pointer != 0;
  }
  else
  {
    v636 = 0;
  }
  LOBYTE(v634) = BYTE2(v717) & 0x7F;
  BYTE2(v717) = BYTE2(v717) & 0x7F | (v636 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v634, (int)config, (unsigned int)"use_tfresnel") )
  {
    v638 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v639 = vostok::configs::binary_config_value::operator[](v638, "value")->data.pointer != 0;
  }
  else
  {
    v639 = 0;
  }
  HIBYTE(v717) ^= (HIBYTE(v717) ^ (16 * v639)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v637, (int)config, (unsigned int)"use_troughness") )
  {
    v641 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v642 = vostok::configs::binary_config_value::operator[](v641, "value")->data.pointer != 0;
  }
  else
  {
    v642 = 0;
  }
  HIBYTE(v717) ^= (HIBYTE(v717) ^ (32 * v642)) & 0x20;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v640,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "bake_decal_composition",
    (char *)compiler,
    (vostok::render::effect_compiler *)&v717,
    config,
    v701);
  vostok::render::effect_compiler::set_depth(v643, (int)compiler, 0, 0, v702);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v644);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v645);
  if ( (v717 & 0x80000) != 0 )
  {
    v647 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v648 = (char **)vostok::configs::binary_config_value::operator[](v647, "value");
    vostok::render::effect_compiler::set_texture(
      v649,
      (const char *)compiler,
      "t_base",
      *v648,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( (v717 & 0x800000) != 0 )
  {
    v650 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v651 = (char **)vostok::configs::binary_config_value::operator[](v650, "value");
    vostok::render::effect_compiler::set_texture(v652, (const char *)compiler, "t_normal", *v651, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v653 = (v717 & 0x10000000) != 0;
  v721 = v653;
  if ( (v717 & 0x10000000) != 0 )
  {
    v654 = vostok::configs::binary_config_value::operator[](config, "texture_fresnel");
    v655 = (char **)vostok::configs::binary_config_value::operator[](v654, "value");
    vostok::render::effect_compiler::set_texture(
      v656,
      (const char *)compiler,
      "t_fresnel",
      *v655,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    v653 = v721;
  }
  if ( v653 )
  {
    v657 = vostok::configs::binary_config_value::operator[](config, "texture_fresnel");
    v658 = (char **)vostok::configs::binary_config_value::operator[](v657, "value");
    vostok::render::effect_compiler::set_texture(
      v659,
      (const char *)compiler,
      "t_fresnel",
      *v658,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v717 & 0x20000000) != 0 )
  {
    v660 = vostok::configs::binary_config_value::operator[](config, "texture_roughness");
    v661 = (char **)vostok::configs::binary_config_value::operator[](v660, "value");
    vostok::render::effect_compiler::set_texture(
      v662,
      (const char *)compiler,
      "t_roughness",
      *v661,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  vostok::render::effect_material_base::compile_end(v646, compiler);
  for ( i = 0; i < 3; ++i )
  {
    vostok::render::shader_configuration::shader_configuration(v663, (int)&v738);
    LOBYTE(v664) = i & 7;
    HIBYTE(v738.elements[2]) = i & 7 | HIBYTE(v738.elements[2]) & 0xE8 | (16 * (i == 2));
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v664,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "editor_accumulate_overdraw",
      (char *)compiler,
      (vostok::render::effect_compiler *)&v738,
      config,
      v703);
    vostok::render::effect_compiler::set_depth(v665, (int)compiler, 1, 1, v704);
    vostok::render::effect_compiler::set_stencil(
      v666,
      (int)compiler,
      1,
      0xFFu,
      0xFFu,
      255,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_INCR,
      D3D11_STENCIL_OP_KEEP,
      v705);
    vostok::render::effect_material_base::compile_end(v667, compiler);
  }
}
