void __cdecl vostok::render::load_environment_properties_impl<vostok::configs::binary_config_value const>(
        vostok::render::environment_properties *props,
        const vostok::configs::binary_config_value *t)
{
  vostok::configs::binary_config_value *v2; // ecx
  vostok::render::environment_properties *v3; // esi
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v9; // ecx
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  vostok::configs::binary_config_value *v12; // ecx
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  vostok::configs::binary_config_value *v15; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  float *v17; // esi
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  vostok::configs::binary_config_value *v21; // ecx
  const vostok::configs::binary_config_value *v22; // eax
  float *v23; // esi
  double v24; // xmm0_8
  double v25; // xmm0_8
  double v26; // xmm0_8
  vostok::configs::binary_config_value *v27; // ecx
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  vostok::configs::binary_config_value *v30; // ecx
  const vostok::configs::binary_config_value *v31; // eax
  float v32; // xmm0_4
  vostok::configs::binary_config_value *v33; // ecx
  vostok::configs::binary_config_value *v34; // ecx
  vostok::configs::binary_config_value *v35; // ecx
  const vostok::configs::binary_config_value *v36; // eax
  float v37; // xmm0_4
  vostok::configs::binary_config_value *v38; // ecx
  const vostok::configs::binary_config_value *v39; // eax
  float *v40; // esi
  double v41; // xmm0_8
  double v42; // xmm0_8
  double v43; // xmm0_8
  vostok::configs::binary_config_value *v44; // ecx
  vostok::configs::binary_config_value *v45; // ecx
  const vostok::configs::binary_config_value *v46; // eax
  float v47; // xmm0_4
  vostok::configs::binary_config_value *v48; // ecx
  const vostok::configs::binary_config_value *v49; // eax
  float v50; // xmm0_4
  vostok::configs::binary_config_value *v51; // ecx
  vostok::configs::binary_config_value *v52; // ecx
  const vostok::configs::binary_config_value *v53; // eax
  float v54; // xmm0_4
  vostok::configs::binary_config_value *v55; // ecx
  const vostok::configs::binary_config_value *v56; // eax
  float *v57; // esi
  double v58; // xmm0_8
  double v59; // xmm0_8
  double v60; // xmm0_8
  vostok::configs::binary_config_value *v61; // ecx
  const vostok::configs::binary_config_value *v62; // eax
  float *v63; // esi
  double v64; // xmm0_8
  double v65; // xmm0_8
  double v66; // xmm0_8
  vostok::configs::binary_config_value *v67; // ecx
  const vostok::configs::binary_config_value *v68; // eax
  float v69; // xmm0_4
  vostok::configs::binary_config_value *v70; // ecx
  const vostok::configs::binary_config_value *v71; // eax
  float v72; // xmm0_4
  vostok::configs::binary_config_value *v73; // ecx
  const vostok::configs::binary_config_value *v74; // eax
  float v75; // xmm0_4
  vostok::configs::binary_config_value *v76; // ecx
  const vostok::configs::binary_config_value *v77; // eax
  float v78; // xmm0_4
  vostok::configs::binary_config_value *v79; // ecx
  const vostok::configs::binary_config_value *v80; // eax
  float v81; // xmm0_4
  vostok::configs::binary_config_value *v82; // ecx
  const vostok::configs::binary_config_value *v83; // eax
  float v84; // xmm0_4
  vostok::configs::binary_config_value *v85; // ecx
  const vostok::configs::binary_config_value *v86; // eax
  float v87; // xmm0_4
  vostok::configs::binary_config_value *v88; // ecx
  vostok::configs::binary_config_value *v89; // ecx
  vostok::configs::binary_config_value *v90; // ecx
  const vostok::configs::binary_config_value *v91; // eax
  float v92; // xmm0_4
  vostok::configs::binary_config_value *v93; // ecx
  const vostok::configs::binary_config_value *v94; // eax
  float v95; // xmm0_4
  vostok::configs::binary_config_value *v96; // ecx
  vostok::configs::binary_config_value *v97; // ecx
  const vostok::configs::binary_config_value *v98; // eax
  float v99; // xmm0_4
  vostok::configs::binary_config_value *v100; // ecx
  const vostok::configs::binary_config_value *v101; // eax
  float v102; // xmm0_4
  vostok::configs::binary_config_value *v103; // ecx
  vostok::configs::binary_config_value *v104; // ecx
  const vostok::configs::binary_config_value *v105; // eax
  float *v106; // esi
  double v107; // xmm0_8
  double v108; // xmm0_8
  double v109; // xmm0_8
  vostok::configs::binary_config_value *v110; // ecx
  const vostok::configs::binary_config_value *v111; // eax
  float v112; // xmm0_4
  vostok::configs::binary_config_value *v113; // ecx
  const vostok::configs::binary_config_value *v114; // eax
  float *v115; // esi
  double v116; // xmm0_8
  double v117; // xmm0_8
  double v118; // xmm0_8
  vostok::configs::binary_config_value *v119; // ecx
  const vostok::configs::binary_config_value *v120; // eax
  float v121; // xmm0_4
  vostok::configs::binary_config_value *v122; // ecx
  const vostok::configs::binary_config_value *v123; // eax
  float v124; // xmm0_4
  vostok::configs::binary_config_value *v125; // ecx
  vostok::configs::binary_config_value *v126; // ecx
  const vostok::configs::binary_config_value *v127; // eax
  float v128; // xmm0_4
  vostok::configs::binary_config_value *v129; // ecx
  const vostok::configs::binary_config_value *v130; // eax
  float v131; // xmm0_4
  vostok::configs::binary_config_value *v132; // ecx
  const vostok::configs::binary_config_value *v133; // eax
  float v134; // xmm0_4
  vostok::configs::binary_config_value *v135; // ecx
  vostok::configs::binary_config_value *v136; // ecx
  const vostok::configs::binary_config_value *v137; // eax
  float *v138; // esi
  double v139; // xmm0_8
  double v140; // xmm0_8
  double v141; // xmm0_8
  vostok::configs::binary_config_value *v142; // ecx
  const vostok::configs::binary_config_value *v143; // eax
  float v144; // xmm0_4
  vostok::configs::binary_config_value *v145; // ecx
  const vostok::configs::binary_config_value *v146; // eax
  float v147; // xmm0_4
  vostok::configs::binary_config_value *v148; // ecx
  const vostok::configs::binary_config_value *v149; // eax
  float v150; // xmm0_4
  vostok::configs::binary_config_value *v151; // ecx
  const vostok::configs::binary_config_value *v152; // eax
  float *v153; // esi
  double v154; // xmm0_8
  double v155; // xmm0_8
  double v156; // xmm0_8
  vostok::configs::binary_config_value *v157; // ecx
  const vostok::configs::binary_config_value *v158; // eax
  float v159; // xmm0_4
  vostok::configs::binary_config_value *v160; // ecx
  const vostok::configs::binary_config_value *v161; // eax
  float v162; // xmm0_4
  vostok::configs::binary_config_value *v163; // ecx
  const vostok::configs::binary_config_value *v164; // eax
  float v165; // xmm0_4
  vostok::configs::binary_config_value *v166; // ecx
  const vostok::configs::binary_config_value *v167; // eax
  float v168; // xmm0_4
  vostok::configs::binary_config_value *v169; // ecx
  const vostok::configs::binary_config_value *v170; // eax
  float v171; // xmm0_4
  vostok::configs::binary_config_value *v172; // ecx
  const vostok::configs::binary_config_value *v173; // eax
  float v174; // xmm0_4
  vostok::configs::binary_config_value *v175; // ecx
  vostok::configs::binary_config_value *v176; // ecx
  const vostok::configs::binary_config_value *v177; // eax
  float v178; // xmm0_4
  vostok::configs::binary_config_value *v179; // ecx
  const vostok::configs::binary_config_value *v180; // eax
  float v181; // xmm0_4
  vostok::configs::binary_config_value *v182; // ecx
  const vostok::configs::binary_config_value *v183; // eax
  float v184; // xmm0_4
  vostok::configs::binary_config_value *v185; // ecx
  const vostok::configs::binary_config_value *v186; // eax
  float v187; // xmm0_4
  vostok::configs::binary_config_value *v188; // ecx
  vostok::configs::binary_config_value *v189; // ecx
  vostok::configs::binary_config_value *v190; // ecx
  const vostok::configs::binary_config_value *v191; // eax
  float v192; // xmm0_4
  vostok::configs::binary_config_value *v193; // ecx
  const vostok::configs::binary_config_value *v194; // eax
  float v195; // xmm0_4
  vostok::configs::binary_config_value *v196; // ecx
  const vostok::configs::binary_config_value *v197; // eax
  float v198; // xmm0_4
  vostok::configs::binary_config_value *v199; // ecx
  const vostok::configs::binary_config_value *v200; // eax
  float v201; // xmm0_4
  vostok::configs::binary_config_value *v202; // ecx
  const vostok::configs::binary_config_value *v203; // eax
  float v204; // xmm0_4
  vostok::configs::binary_config_value *v205; // ecx
  vostok::configs::binary_config_value *v206; // ecx
  const vostok::configs::binary_config_value *v207; // eax
  float v208; // xmm0_4
  vostok::configs::binary_config_value *v209; // ecx
  vostok::configs::binary_config_value *v210; // ecx
  vostok::configs::binary_config_value *v211; // ecx
  const vostok::configs::binary_config_value *v212; // eax
  float v213; // xmm0_4
  vostok::configs::binary_config_value *v214; // ecx
  const vostok::configs::binary_config_value *v215; // eax
  float v216; // xmm0_4
  vostok::configs::binary_config_value *v217; // ecx
  const vostok::configs::binary_config_value *v218; // eax
  float v219; // xmm0_4
  vostok::configs::binary_config_value *v220; // ecx
  const vostok::configs::binary_config_value *v221; // eax
  float v222; // xmm0_4
  vostok::configs::binary_config_value *v223; // ecx
  vostok::configs::binary_config_value *v224; // ecx
  const vostok::configs::binary_config_value *v225; // eax
  float v226; // xmm0_4
  vostok::configs::binary_config_value *v227; // ecx
  const vostok::configs::binary_config_value *v228; // eax
  float v229; // xmm0_4
  vostok::configs::binary_config_value *v230; // ecx
  const vostok::configs::binary_config_value *v231; // eax
  float v232; // xmm0_4
  vostok::configs::binary_config_value *v233; // ecx
  const vostok::configs::binary_config_value *v234; // eax
  float v235; // xmm0_4
  vostok::configs::binary_config_value *v236; // ecx
  const vostok::configs::binary_config_value *v237; // eax
  float v238; // xmm0_4
  vostok::configs::binary_config_value *v239; // ecx
  const vostok::configs::binary_config_value *v240; // eax
  float v241; // xmm0_4
  vostok::configs::binary_config_value *v242; // ecx
  vostok::configs::binary_config_value *v243; // ecx
  vostok::configs::binary_config_value *v244; // ecx
  const vostok::configs::binary_config_value *v245; // eax
  float v246; // xmm0_4
  vostok::configs::binary_config_value *v247; // ecx
  const vostok::configs::binary_config_value *v248; // eax
  float v249; // xmm0_4
  vostok::configs::binary_config_value *v250; // ecx
  vostok::configs::binary_config_value *v251; // ecx
  const vostok::configs::binary_config_value *v252; // eax
  float v253; // xmm0_4
  vostok::configs::binary_config_value *v254; // ecx
  const vostok::configs::binary_config_value *v255; // eax
  float v256; // xmm0_4
  vostok::configs::binary_config_value *v257; // ecx
  const vostok::configs::binary_config_value *v258; // eax
  float v259; // xmm0_4
  vostok::configs::binary_config_value *v260; // ecx
  vostok::configs::binary_config_value *v261; // ecx
  const vostok::configs::binary_config_value *v262; // eax
  float v263; // xmm0_4
  vostok::configs::binary_config_value *v264; // ecx
  vostok::configs::binary_config_value *v265; // ecx
  const vostok::configs::binary_config_value *v266; // eax
  float v267; // xmm0_4
  vostok::configs::binary_config_value *v268; // ecx
  vostok::configs::binary_config_value *v269; // ecx
  vostok::configs::binary_config_value *v270; // ecx
  const vostok::configs::binary_config_value *v271; // eax
  float v272; // xmm0_4
  vostok::configs::binary_config_value *v273; // ecx
  const vostok::configs::binary_config_value *v274; // eax
  float v275; // xmm0_4
  vostok::configs::binary_config_value *v276; // ecx
  const vostok::configs::binary_config_value *v277; // eax
  float v278; // xmm0_4
  vostok::configs::binary_config_value *v279; // ecx
  vostok::configs::binary_config_value *v280; // ecx
  const vostok::configs::binary_config_value *v281; // eax
  float v282; // xmm0_4
  vostok::configs::binary_config_value *v283; // ecx
  const vostok::configs::binary_config_value *v284; // eax
  float v285; // xmm0_4
  vostok::configs::binary_config_value *v286; // ecx
  const vostok::configs::binary_config_value *v287; // eax
  float v288; // xmm0_4
  vostok::configs::binary_config_value *v289; // ecx
  vostok::configs::binary_config_value *v290; // ecx
  const vostok::math::float4 **v291; // eax
  vostok::configs::binary_config_value *v292; // ecx
  vostok::configs::binary_config_value *v293; // ecx
  const vostok::configs::binary_config_value *v294; // eax
  float v295; // xmm0_4
  vostok::configs::binary_config_value *v296; // ecx
  const vostok::configs::binary_config_value *v297; // eax
  float v298; // xmm0_4
  vostok::configs::binary_config_value *v299; // ecx
  vostok::configs::binary_config_value *v300; // ecx
  const vostok::configs::binary_config_value *v301; // eax
  float v302; // xmm0_4
  vostok::configs::binary_config_value *v303; // ecx
  const vostok::configs::binary_config_value *v304; // eax
  float v305; // xmm0_4
  vostok::configs::binary_config_value *v306; // ecx
  vostok::configs::binary_config_value *v307; // ecx
  const vostok::configs::binary_config_value *v308; // eax
  float v309; // xmm0_4
  const vostok::configs::binary_config_value *v310; // eax
  float v311; // xmm0_4
  long double v312; // [esp+0h] [ebp-20h]
  long double v313; // [esp+0h] [ebp-20h]
  long double v314; // [esp+0h] [ebp-20h]
  long double v315; // [esp+0h] [ebp-20h]
  long double v316; // [esp+0h] [ebp-20h]
  long double v317; // [esp+0h] [ebp-20h]
  long double v318; // [esp+0h] [ebp-20h]
  long double v319; // [esp+0h] [ebp-20h]
  long double v320; // [esp+0h] [ebp-20h]
  long double v321; // [esp+0h] [ebp-20h]
  long double v322; // [esp+0h] [ebp-20h]
  long double v323; // [esp+0h] [ebp-20h]
  long double v324; // [esp+0h] [ebp-20h]
  long double v325; // [esp+0h] [ebp-20h]
  long double v326; // [esp+0h] [ebp-20h]
  long double v327; // [esp+0h] [ebp-20h]
  long double v328; // [esp+0h] [ebp-20h]
  long double v329; // [esp+0h] [ebp-20h]
  long double v330; // [esp+0h] [ebp-20h]
  long double v331; // [esp+8h] [ebp-18h]
  long double v332; // [esp+8h] [ebp-18h]
  long double v333; // [esp+8h] [ebp-18h]
  long double v334; // [esp+8h] [ebp-18h]
  long double v335; // [esp+8h] [ebp-18h]
  long double v336; // [esp+8h] [ebp-18h]
  long double v337; // [esp+8h] [ebp-18h]
  long double v338; // [esp+8h] [ebp-18h]
  long double v339; // [esp+8h] [ebp-18h]
  long double v340; // [esp+8h] [ebp-18h]
  long double v341; // [esp+8h] [ebp-18h]
  long double v342; // [esp+8h] [ebp-18h]
  long double v343; // [esp+8h] [ebp-18h]
  long double v344; // [esp+8h] [ebp-18h]
  long double v345; // [esp+8h] [ebp-18h]
  long double v346; // [esp+8h] [ebp-18h]
  long double v347; // [esp+8h] [ebp-18h]
  long double v348; // [esp+8h] [ebp-18h]
  long double v349; // [esp+8h] [ebp-18h]
  __int64 v350; // [esp+10h] [ebp-10h]
  __int64 v351; // [esp+10h] [ebp-10h]
  __int64 v352; // [esp+10h] [ebp-10h]
  __int64 v353; // [esp+10h] [ebp-10h]
  __int64 v354; // [esp+10h] [ebp-10h]
  __int64 v355; // [esp+10h] [ebp-10h]
  __int64 v356; // [esp+10h] [ebp-10h]
  __int64 v357; // [esp+10h] [ebp-10h]
  __int64 v358; // [esp+10h] [ebp-10h]
  float v359; // [esp+1Ch] [ebp-4h]
  float v360; // [esp+1Ch] [ebp-4h]
  float v361; // [esp+1Ch] [ebp-4h]
  float v362; // [esp+1Ch] [ebp-4h]
  float v363; // [esp+1Ch] [ebp-4h]
  float v364; // [esp+1Ch] [ebp-4h]
  float v365; // [esp+1Ch] [ebp-4h]
  float v366; // [esp+1Ch] [ebp-4h]
  float v367; // [esp+1Ch] [ebp-4h]

  v3 = props;
  if ( vostok::configs::binary_config_value::value_exists(v2, (int)t, (unsigned int)"color_grading_weight")
    || vostok::configs::binary_config_value::value_exists(v4, (int)t, (unsigned int)"color_grading_texture") )
  {
    props->num_color_grading_textures = 1;
  }
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)t, (unsigned int)"use_height_based_ambient") )
    props->use_height_based_ambient = vostok::configs::binary_config_value::operator[](t, "use_height_based_ambient")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)t, (unsigned int)"height_based_ambient_low_limit") )
  {
    v7 = vostok::configs::binary_config_value::operator[](t, "height_based_ambient_low_limit");
    if ( v7->type == 2 )
      pointer = *(float *)&v7->data.pointer;
    else
      pointer = (float)(int)v7->data.pointer;
    props->height_based_ambient_low_limit = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)t, (unsigned int)"height_based_ambient_high_limit") )
  {
    v10 = vostok::configs::binary_config_value::operator[](t, "height_based_ambient_high_limit");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    props->height_based_ambient_high_limit = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)t, (unsigned int)"height_based_ambient_power") )
  {
    v13 = vostok::configs::binary_config_value::operator[](t, "height_based_ambient_power");
    if ( v13->type == 2 )
      v14 = *(float *)&v13->data.pointer;
    else
      v14 = (float)(int)v13->data.pointer;
    props->height_based_ambient_power = v14;
  }
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)t, (unsigned int)"height_based_ambient_low_color") )
  {
    v16 = vostok::configs::binary_config_value::operator[](t, "height_based_ambient_low_color");
    v17 = (float *)v16->data.pointer;
    v18 = *(float *)v16->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v18 = v18;
    LODWORD(v350) = LODWORD(v18);
    v19 = v17[1];
    __libm_sse2_pow(v313, v332);
    *(float *)&v19 = v19;
    HIDWORD(v350) = LODWORD(v19);
    v20 = v17[2];
    __libm_sse2_pow(v314, v333);
    *(float *)&v20 = v20;
    v359 = v17[3];
    *(_QWORD *)&props->height_based_ambient_low_color.x = v350;
    props->height_based_ambient_low_color.z = *(float *)&v20;
    props->height_based_ambient_low_color.w = v359;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)t, (unsigned int)"height_based_ambient_high_color") )
  {
    v22 = vostok::configs::binary_config_value::operator[](t, "height_based_ambient_high_color");
    v23 = (float *)v22->data.pointer;
    v24 = *(float *)v22->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v24 = v24;
    LODWORD(v351) = LODWORD(v24);
    v25 = v23[1];
    __libm_sse2_pow(v315, v334);
    *(float *)&v25 = v25;
    HIDWORD(v351) = LODWORD(v25);
    v26 = v23[2];
    __libm_sse2_pow(v316, v335);
    *(float *)&v26 = v26;
    v360 = v23[3];
    *(_QWORD *)&props->height_based_ambient_high_color.x = v351;
    props->height_based_ambient_high_color.z = *(float *)&v26;
    props->height_based_ambient_high_color.w = v360;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)t, (unsigned int)"sun_position_azimut") )
  {
    v28 = vostok::configs::binary_config_value::operator[](t, "sun_position_azimut");
    if ( v28->type == 2 )
      v29 = *(float *)&v28->data.pointer;
    else
      v29 = (float)(int)v28->data.pointer;
    v3->sun_position_azimut = v29;
  }
  if ( vostok::configs::binary_config_value::value_exists(v27, (int)t, (unsigned int)"sun_angle") )
  {
    v31 = vostok::configs::binary_config_value::operator[](t, "sun_angle");
    if ( v31->type == 2 )
      v32 = *(float *)&v31->data.pointer;
    else
      v32 = (float)(int)v31->data.pointer;
    v3->sun_angle = v32;
  }
  v3->use_sun = !vostok::configs::binary_config_value::value_exists(v30, (int)t, (unsigned int)"use_sun")
             || vostok::configs::binary_config_value::operator[](t, "use_sun")->data.pointer != 0;
  v3->use_sun_shadows = !vostok::configs::binary_config_value::value_exists(
                           v33,
                           (int)t,
                           (unsigned int)"use_sun_shadows")
                     || vostok::configs::binary_config_value::operator[](t, "use_sun_shadows")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v34, (int)t, (unsigned int)"sun_intensity") )
  {
    v36 = vostok::configs::binary_config_value::operator[](t, "sun_intensity");
    if ( v36->type == 2 )
      v37 = *(float *)&v36->data.pointer;
    else
      v37 = (float)(int)v36->data.pointer;
    v3->sun_intensity = v37;
  }
  if ( vostok::configs::binary_config_value::value_exists(v35, (int)t, (unsigned int)"sun_color") )
  {
    v39 = vostok::configs::binary_config_value::operator[](t, "sun_color");
    v40 = (float *)v39->data.pointer;
    v41 = *(float *)v39->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v41 = v41;
    LODWORD(v352) = LODWORD(v41);
    v42 = v40[1];
    __libm_sse2_pow(v317, v336);
    *(float *)&v42 = v42;
    HIDWORD(v352) = LODWORD(v42);
    v43 = v40[2];
    __libm_sse2_pow(v318, v337);
    *(float *)&v43 = v43;
    v361 = v40[3];
    *(_QWORD *)&props->sun_color.x = v352;
    props->sun_color.z = *(float *)&v43;
    props->sun_color.w = v361;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v38, (int)t, (unsigned int)"sun_shadow_rain") )
    v3->sun_shadow_rain = vostok::configs::binary_config_value::operator[](t, "sun_shadow_rain")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v44, (int)t, (unsigned int)"sun_shadow_filter_radius") )
  {
    v46 = vostok::configs::binary_config_value::operator[](t, "sun_shadow_filter_radius");
    if ( v46->type == 2 )
      v47 = *(float *)&v46->data.pointer;
    else
      v47 = (float)(int)v46->data.pointer;
    v3->sun_shadow_filter_radius = v47;
  }
  if ( vostok::configs::binary_config_value::value_exists(v45, (int)t, (unsigned int)"sun_shadow_penumbra") )
  {
    v49 = vostok::configs::binary_config_value::operator[](t, "sun_shadow_penumbra");
    if ( v49->type == 2 )
      v50 = *(float *)&v49->data.pointer;
    else
      v50 = (float)(int)v49->data.pointer;
    v3->sun_shadow_penumbra = v50;
  }
  if ( vostok::configs::binary_config_value::value_exists(v48, (int)t, (unsigned int)"use_sun_moon_texture") )
    v3->use_sun_moon_texture = vostok::configs::binary_config_value::operator[](t, "use_sun_moon_texture")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v51, (int)t, (unsigned int)"sun_moon_billboard_scale") )
  {
    v53 = vostok::configs::binary_config_value::operator[](t, "sun_moon_billboard_scale");
    if ( v53->type == 2 )
      v54 = *(float *)&v53->data.pointer;
    else
      v54 = (float)(int)v53->data.pointer;
    v3->sun_moon_billboard_scale = v54;
  }
  if ( vostok::configs::binary_config_value::value_exists(v52, (int)t, (unsigned int)"god_rays_color_1") )
  {
    v56 = vostok::configs::binary_config_value::operator[](t, "god_rays_color_1");
    v57 = (float *)v56->data.pointer;
    v58 = *(float *)v56->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v58 = v58;
    LODWORD(v353) = LODWORD(v58);
    v59 = v57[1];
    __libm_sse2_pow(v319, v338);
    *(float *)&v59 = v59;
    HIDWORD(v353) = LODWORD(v59);
    v60 = v57[2];
    __libm_sse2_pow(v320, v339);
    *(float *)&v60 = v60;
    v362 = v57[3];
    *(_QWORD *)&props->god_rays_color_1.x = v353;
    props->god_rays_color_1.z = *(float *)&v60;
    props->god_rays_color_1.w = v362;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v55, (int)t, (unsigned int)"god_rays_color_2") )
  {
    v62 = vostok::configs::binary_config_value::operator[](t, "god_rays_color_2");
    v63 = (float *)v62->data.pointer;
    v64 = *(float *)v62->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v64 = v64;
    LODWORD(v354) = LODWORD(v64);
    v65 = v63[1];
    __libm_sse2_pow(v321, v340);
    *(float *)&v65 = v65;
    HIDWORD(v354) = LODWORD(v65);
    v66 = v63[2];
    __libm_sse2_pow(v322, v341);
    *(float *)&v66 = v66;
    v363 = v63[3];
    *(_QWORD *)&props->god_rays_color_2.x = v354;
    props->god_rays_color_2.z = *(float *)&v66;
    props->god_rays_color_2.w = v363;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v61, (int)t, (unsigned int)"god_rays_color_blend_power") )
  {
    v68 = vostok::configs::binary_config_value::operator[](t, "god_rays_color_blend_power");
    if ( v68->type == 2 )
      v69 = *(float *)&v68->data.pointer;
    else
      v69 = (float)(int)v68->data.pointer;
    v3->god_rays_color_blend_power = v69;
  }
  if ( vostok::configs::binary_config_value::value_exists(v67, (int)t, (unsigned int)"god_rays_intensity") )
  {
    v71 = vostok::configs::binary_config_value::operator[](t, "god_rays_intensity");
    if ( v71->type == 2 )
      v72 = *(float *)&v71->data.pointer;
    else
      v72 = (float)(int)v71->data.pointer;
    v3->god_rays_intensity = v72;
  }
  if ( vostok::configs::binary_config_value::value_exists(v70, (int)t, (unsigned int)"god_rays_attenuation") )
  {
    v74 = vostok::configs::binary_config_value::operator[](t, "god_rays_attenuation");
    if ( v74->type == 2 )
      v75 = *(float *)&v74->data.pointer;
    else
      v75 = (float)(int)v74->data.pointer;
    v3->god_rays_attenuation = v75;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v73,
         (int)t,
         (unsigned int)"atmosphere_rayleighSun_multiplier") )
  {
    v77 = vostok::configs::binary_config_value::operator[](t, "atmosphere_rayleighSun_multiplier");
    if ( v77->type == 2 )
      v78 = *(float *)&v77->data.pointer;
    else
      v78 = (float)(int)v77->data.pointer;
    v3->atmosphere_rayleighSun_multiplier = v78;
  }
  if ( vostok::configs::binary_config_value::value_exists(v76, (int)t, (unsigned int)"atmosphere_mieSun_multiplier") )
  {
    v80 = vostok::configs::binary_config_value::operator[](t, "atmosphere_mieSun_multiplier");
    if ( v80->type == 2 )
      v81 = *(float *)&v80->data.pointer;
    else
      v81 = (float)(int)v80->data.pointer;
    v3->atmosphere_mieSun_multiplier = v81;
  }
  if ( vostok::configs::binary_config_value::value_exists(v79, (int)t, (unsigned int)"atmosphere_rayleighPi_multiplier") )
  {
    v83 = vostok::configs::binary_config_value::operator[](t, "atmosphere_rayleighPi_multiplier");
    if ( v83->type == 2 )
      v84 = *(float *)&v83->data.pointer;
    else
      v84 = (float)(int)v83->data.pointer;
    v3->atmosphere_rayleighPi_multiplier = v84;
  }
  if ( vostok::configs::binary_config_value::value_exists(v82, (int)t, (unsigned int)"atmosphere_miePi_multiplier") )
  {
    v86 = vostok::configs::binary_config_value::operator[](t, "atmosphere_miePi_multiplier");
    if ( v86->type == 2 )
      v87 = *(float *)&v86->data.pointer;
    else
      v87 = (float)(int)v86->data.pointer;
    v3->atmosphere_miePi_multiplier = v87;
  }
  if ( vostok::configs::binary_config_value::value_exists(v85, (int)t, (unsigned int)"atmosphere_use_sun_illumination") )
    v3->atmosphere_use_sun_illumination = vostok::configs::binary_config_value::operator[](
                                            t,
                                            "atmosphere_use_sun_illumination")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v88, (int)t, (unsigned int)"use_sky_clouds") )
    v3->use_sky_clouds = vostok::configs::binary_config_value::operator[](t, "use_sky_clouds")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v89, (int)t, (unsigned int)"sky_clouds_rotation") )
  {
    v91 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_rotation");
    if ( v91->type == 2 )
      v92 = *(float *)&v91->data.pointer;
    else
      v92 = (float)(int)v91->data.pointer;
    v3->sky_clouds_rotation = v92;
  }
  if ( vostok::configs::binary_config_value::value_exists(v90, (int)t, (unsigned int)"sky_clouds_rotation_speed") )
  {
    v94 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_rotation_speed");
    if ( v94->type == 2 )
      v95 = *(float *)&v94->data.pointer;
    else
      v95 = (float)(int)v94->data.pointer;
    v3->sky_clouds_rotation_speed = v95;
  }
  if ( vostok::configs::binary_config_value::value_exists(v93, (int)t, (unsigned int)"use_stratosphere") )
    v3->use_stratosphere = vostok::configs::binary_config_value::operator[](t, "use_stratosphere")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v96, (int)t, (unsigned int)"stratosphere_rotation") )
  {
    v98 = vostok::configs::binary_config_value::operator[](t, "stratosphere_rotation");
    if ( v98->type == 2 )
      v99 = *(float *)&v98->data.pointer;
    else
      v99 = (float)(int)v98->data.pointer;
    v3->stratosphere_rotation = v99;
  }
  if ( vostok::configs::binary_config_value::value_exists(v97, (int)t, (unsigned int)"stratosphere_rotation_speed") )
  {
    v101 = vostok::configs::binary_config_value::operator[](t, "stratosphere_rotation_speed");
    if ( v101->type == 2 )
      v102 = *(float *)&v101->data.pointer;
    else
      v102 = (float)(int)v101->data.pointer;
    v3->stratosphere_rotation_speed = v102;
  }
  if ( vostok::configs::binary_config_value::value_exists(v100, (int)t, (unsigned int)"sky_clouds_blend_mode") )
    v3->sky_clouds_blend_mode = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                t,
                                                "sky_clouds_blend_mode")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v103, (int)t, (unsigned int)"sky_clouds_color") )
  {
    v105 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_color");
    v106 = (float *)v105->data.pointer;
    v107 = *(float *)v105->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v107 = v107;
    LODWORD(v355) = LODWORD(v107);
    v108 = v106[1];
    __libm_sse2_pow(v323, v342);
    *(float *)&v108 = v108;
    HIDWORD(v355) = LODWORD(v108);
    v109 = v106[2];
    __libm_sse2_pow(v324, v343);
    *(float *)&v109 = v109;
    v364 = v106[3];
    *(_QWORD *)&props->sky_clouds_color.x = v355;
    props->sky_clouds_color.z = *(float *)&v109;
    props->sky_clouds_color.w = v364;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v104, (int)t, (unsigned int)"sky_clouds_color_multiplier") )
  {
    v111 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_color_multiplier");
    if ( v111->type == 2 )
      v112 = *(float *)&v111->data.pointer;
    else
      v112 = (float)(int)v111->data.pointer;
    v3->sky_clouds_color_multiplier = v112;
  }
  if ( vostok::configs::binary_config_value::value_exists(v110, (int)t, (unsigned int)"sky_clouds_fog_color") )
  {
    v114 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_fog_color");
    v115 = (float *)v114->data.pointer;
    v116 = *(float *)v114->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v116 = v116;
    LODWORD(v356) = LODWORD(v116);
    v117 = v115[1];
    __libm_sse2_pow(v325, v344);
    *(float *)&v117 = v117;
    HIDWORD(v356) = LODWORD(v117);
    v118 = v115[2];
    __libm_sse2_pow(v326, v345);
    *(float *)&v118 = v118;
    v365 = v115[3];
    *(_QWORD *)&props->sky_clouds_fog_color.x = v356;
    props->sky_clouds_fog_color.z = *(float *)&v118;
    props->sky_clouds_fog_color.w = v365;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v113, (int)t, (unsigned int)"sky_clouds_fog_power") )
  {
    v120 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_fog_power");
    if ( v120->type == 2 )
      v121 = *(float *)&v120->data.pointer;
    else
      v121 = (float)(int)v120->data.pointer;
    v3->sky_clouds_fog_power = v121;
  }
  if ( vostok::configs::binary_config_value::value_exists(v119, (int)t, (unsigned int)"sky_clouds_fog_up_limit") )
  {
    v123 = vostok::configs::binary_config_value::operator[](t, "sky_clouds_fog_up_limit");
    if ( v123->type == 2 )
      v124 = *(float *)&v123->data.pointer;
    else
      v124 = (float)(int)v123->data.pointer;
    v3->sky_clouds_fog_up_limit = v124;
  }
  if ( vostok::configs::binary_config_value::value_exists(v122, (int)t, (unsigned int)"use_sky_shadows") )
    v3->use_sky_shadows = vostok::configs::binary_config_value::operator[](t, "use_sky_shadows")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v125, (int)t, (unsigned int)"sky_shadows_moving_x") )
  {
    v127 = vostok::configs::binary_config_value::operator[](t, "sky_shadows_moving_x");
    if ( v127->type == 2 )
      v128 = *(float *)&v127->data.pointer;
    else
      v128 = (float)(int)v127->data.pointer;
    v3->sky_shadows_moving_x = v128;
  }
  if ( vostok::configs::binary_config_value::value_exists(v126, (int)t, (unsigned int)"sky_shadows_moving_y") )
  {
    v130 = vostok::configs::binary_config_value::operator[](t, "sky_shadows_moving_y");
    if ( v130->type == 2 )
      v131 = *(float *)&v130->data.pointer;
    else
      v131 = (float)(int)v130->data.pointer;
    v3->sky_shadows_moving_y = v131;
  }
  if ( vostok::configs::binary_config_value::value_exists(v129, (int)t, (unsigned int)"sky_shadows_tiling") )
  {
    v133 = vostok::configs::binary_config_value::operator[](t, "sky_shadows_tiling");
    if ( v133->type == 2 )
      v134 = *(float *)&v133->data.pointer;
    else
      v134 = (float)(int)v133->data.pointer;
    v3->sky_shadows_tiling = v134;
  }
  if ( vostok::configs::binary_config_value::value_exists(v132, (int)t, (unsigned int)"use_sky_clouds_lighting") )
    v3->use_sky_clouds_lighting = vostok::configs::binary_config_value::operator[](t, "use_sky_clouds_lighting")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v135, (int)t, (unsigned int)"rayleigh_fog_color") )
  {
    v137 = vostok::configs::binary_config_value::operator[](t, "rayleigh_fog_color");
    v138 = (float *)v137->data.pointer;
    v139 = *(float *)v137->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v139 = v139;
    LODWORD(v357) = LODWORD(v139);
    v140 = v138[1];
    __libm_sse2_pow(v327, v346);
    *(float *)&v140 = v140;
    HIDWORD(v357) = LODWORD(v140);
    v141 = v138[2];
    __libm_sse2_pow(v328, v347);
    *(float *)&v141 = v141;
    v366 = v138[3];
    *(_QWORD *)&props->rayleigh_fog_color.x = v357;
    props->rayleigh_fog_color.z = *(float *)&v141;
    props->rayleigh_fog_color.w = v366;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v136, (int)t, (unsigned int)"rayleigh_fog_far_distance") )
  {
    v143 = vostok::configs::binary_config_value::operator[](t, "rayleigh_fog_far_distance");
    if ( v143->type == 2 )
      v144 = *(float *)&v143->data.pointer;
    else
      v144 = (float)(int)v143->data.pointer;
    v3->rayleigh_fog_far_distance = v144;
  }
  if ( vostok::configs::binary_config_value::value_exists(v142, (int)t, (unsigned int)"rayleigh_fog_near_distance") )
  {
    v146 = vostok::configs::binary_config_value::operator[](t, "rayleigh_fog_near_distance");
    if ( v146->type == 2 )
      v147 = *(float *)&v146->data.pointer;
    else
      v147 = (float)(int)v146->data.pointer;
    v3->rayleigh_fog_near_distance = v147;
  }
  if ( vostok::configs::binary_config_value::value_exists(v145, (int)t, (unsigned int)"rayleigh_fog_density") )
  {
    v149 = vostok::configs::binary_config_value::operator[](t, "rayleigh_fog_density");
    if ( v149->type == 2 )
      v150 = *(float *)&v149->data.pointer;
    else
      v150 = (float)(int)v149->data.pointer;
    v3->rayleigh_fog_density = v150;
  }
  if ( vostok::configs::binary_config_value::value_exists(v148, (int)t, (unsigned int)"mie_fog_color") )
  {
    v152 = vostok::configs::binary_config_value::operator[](t, "mie_fog_color");
    v153 = (float *)v152->data.pointer;
    v154 = *(float *)v152->data.pointer;
    __libm_sse2_pow(v312, v331);
    *(float *)&v154 = v154;
    LODWORD(v358) = LODWORD(v154);
    v155 = v153[1];
    __libm_sse2_pow(v329, v348);
    *(float *)&v155 = v155;
    HIDWORD(v358) = LODWORD(v155);
    v156 = v153[2];
    __libm_sse2_pow(v330, v349);
    *(float *)&v156 = v156;
    v367 = v153[3];
    *(_QWORD *)&props->mie_fog_color.x = v358;
    props->mie_fog_color.z = *(float *)&v156;
    props->mie_fog_color.w = v367;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v151, (int)t, (unsigned int)"mie_fog_far_distance") )
  {
    v158 = vostok::configs::binary_config_value::operator[](t, "mie_fog_far_distance");
    if ( v158->type == 2 )
      v159 = *(float *)&v158->data.pointer;
    else
      v159 = (float)(int)v158->data.pointer;
    v3->mie_fog_far_distance = v159;
  }
  if ( vostok::configs::binary_config_value::value_exists(v157, (int)t, (unsigned int)"mie_fog_near_distance") )
  {
    v161 = vostok::configs::binary_config_value::operator[](t, "mie_fog_near_distance");
    if ( v161->type == 2 )
      v162 = *(float *)&v161->data.pointer;
    else
      v162 = (float)(int)v161->data.pointer;
    v3->mie_fog_near_distance = v162;
  }
  if ( vostok::configs::binary_config_value::value_exists(v160, (int)t, (unsigned int)"mie_fog_density") )
  {
    v164 = vostok::configs::binary_config_value::operator[](t, "mie_fog_density");
    if ( v164->type == 2 )
      v165 = *(float *)&v164->data.pointer;
    else
      v165 = (float)(int)v164->data.pointer;
    v3->mie_fog_density = v165;
  }
  if ( vostok::configs::binary_config_value::value_exists(v163, (int)t, (unsigned int)"mie_fog_falloff") )
  {
    v167 = vostok::configs::binary_config_value::operator[](t, "mie_fog_falloff");
    if ( v167->type == 2 )
      v168 = *(float *)&v167->data.pointer;
    else
      v168 = (float)(int)v167->data.pointer;
    v3->mie_fog_falloff = v168;
  }
  if ( vostok::configs::binary_config_value::value_exists(v166, (int)t, (unsigned int)"mie_fog_height_falloff") )
  {
    v170 = vostok::configs::binary_config_value::operator[](t, "mie_fog_height_falloff");
    if ( v170->type == 2 )
      v171 = *(float *)&v170->data.pointer;
    else
      v171 = (float)(int)v170->data.pointer;
    v3->mie_fog_height_falloff = v171;
  }
  if ( vostok::configs::binary_config_value::value_exists(v169, (int)t, (unsigned int)"mie_fog_bias") )
  {
    v173 = vostok::configs::binary_config_value::operator[](t, "mie_fog_bias");
    if ( v173->type == 2 )
      v174 = *(float *)&v173->data.pointer;
    else
      v174 = (float)(int)v173->data.pointer;
    v3->mie_fog_bias = v174;
  }
  if ( vostok::configs::binary_config_value::value_exists(v172, (int)t, (unsigned int)"use_ambient_occlusion") )
    v3->use_ambient_occlusion = vostok::configs::binary_config_value::operator[](t, "use_ambient_occlusion")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v175, (int)t, (unsigned int)"ao_saturation") )
  {
    v177 = vostok::configs::binary_config_value::operator[](t, "ao_saturation");
    if ( v177->type == 2 )
      v178 = *(float *)&v177->data.pointer;
    else
      v178 = (float)(int)v177->data.pointer;
    v3->ao_saturation = v178;
  }
  if ( vostok::configs::binary_config_value::value_exists(v176, (int)t, (unsigned int)"ao_radius") )
  {
    v180 = vostok::configs::binary_config_value::operator[](t, "ao_radius");
    if ( v180->type == 2 )
      v181 = *(float *)&v180->data.pointer;
    else
      v181 = (float)(int)v180->data.pointer;
    v3->ao_radius = v181;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v179,
         (int)t,
         (unsigned int)"environment_probes_diffuse_intensity_multiplier") )
  {
    v183 = vostok::configs::binary_config_value::operator[](t, "environment_probes_diffuse_intensity_multiplier");
    if ( v183->type == 2 )
      v184 = *(float *)&v183->data.pointer;
    else
      v184 = (float)(int)v183->data.pointer;
    v3->environment_probes_diffuse_intensity_multiplier = v184;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v182,
         (int)t,
         (unsigned int)"environment_probes_specular_intensity_multiplier") )
  {
    v186 = vostok::configs::binary_config_value::operator[](t, "environment_probes_specular_intensity_multiplier");
    if ( v186->type == 2 )
      v187 = *(float *)&v186->data.pointer;
    else
      v187 = (float)(int)v186->data.pointer;
    v3->environment_probes_specular_intensity_multiplier = v187;
  }
  if ( vostok::configs::binary_config_value::value_exists(v185, (int)t, (unsigned int)"use_radial_blur") )
    v3->use_radial_blur = vostok::configs::binary_config_value::operator[](t, "use_radial_blur")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v188, (int)t, (unsigned int)"use_channel_blur") )
    v3->use_channel_blur = vostok::configs::binary_config_value::operator[](t, "use_channel_blur")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v189, (int)t, (unsigned int)"channel_blur_amount") )
  {
    v191 = vostok::configs::binary_config_value::operator[](t, "channel_blur_amount");
    if ( v191->type == 2 )
      v192 = *(float *)&v191->data.pointer;
    else
      v192 = (float)(int)v191->data.pointer;
    v3->channel_blur_amount = v192;
  }
  if ( vostok::configs::binary_config_value::value_exists(v190, (int)t, (unsigned int)"channel_blur_power") )
  {
    v194 = vostok::configs::binary_config_value::operator[](t, "channel_blur_power");
    if ( v194->type == 2 )
      v195 = *(float *)&v194->data.pointer;
    else
      v195 = (float)(int)v194->data.pointer;
    v3->channel_blur_power = v195;
  }
  if ( vostok::configs::binary_config_value::value_exists(v193, (int)t, (unsigned int)"radial_blur_intensity") )
  {
    v197 = vostok::configs::binary_config_value::operator[](t, "radial_blur_intensity");
    if ( v197->type == 2 )
      v198 = *(float *)&v197->data.pointer;
    else
      v198 = (float)(int)v197->data.pointer;
    v3->radial_blur_intensity = v198;
  }
  if ( vostok::configs::binary_config_value::value_exists(v196, (int)t, (unsigned int)"radial_blur_amount") )
  {
    v200 = vostok::configs::binary_config_value::operator[](t, "radial_blur_amount");
    if ( v200->type == 2 )
      v201 = *(float *)&v200->data.pointer;
    else
      v201 = (float)(int)v200->data.pointer;
    v3->radial_blur_amount = v201;
  }
  if ( vostok::configs::binary_config_value::value_exists(v199, (int)t, (unsigned int)"radial_blur_power") )
  {
    v203 = vostok::configs::binary_config_value::operator[](t, "radial_blur_power");
    if ( v203->type == 2 )
      v204 = *(float *)&v203->data.pointer;
    else
      v204 = (float)(int)v203->data.pointer;
    v3->radial_blur_power = v204;
  }
  if ( vostok::configs::binary_config_value::value_exists(v202, (int)t, (unsigned int)"use_rain") )
    v3->use_rain = vostok::configs::binary_config_value::operator[](t, "use_rain")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v205, (int)t, (unsigned int)"rain_surface_intensity") )
  {
    v207 = vostok::configs::binary_config_value::operator[](t, "rain_surface_intensity");
    if ( v207->type == 2 )
      v208 = *(float *)&v207->data.pointer;
    else
      v208 = (float)(int)v207->data.pointer;
    v3->rain_surface_intensity = v208;
  }
  if ( vostok::configs::binary_config_value::value_exists(v206, (int)t, (unsigned int)"use_sun") )
    v3->use_sun = vostok::configs::binary_config_value::operator[](t, "use_sun")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v209, (int)t, (unsigned int)"use_sun_shadows") )
    v3->use_sun_shadows = vostok::configs::binary_config_value::operator[](t, "use_sun_shadows")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v210, (int)t, (unsigned int)"rain_angle_x") )
  {
    v212 = vostok::configs::binary_config_value::operator[](t, "rain_angle_x");
    if ( v212->type == 2 )
      v213 = *(float *)&v212->data.pointer;
    else
      v213 = (float)(int)v212->data.pointer;
    v3->rain_angle_x = v213;
  }
  if ( vostok::configs::binary_config_value::value_exists(v211, (int)t, (unsigned int)"rain_angle_y") )
  {
    v215 = vostok::configs::binary_config_value::operator[](t, "rain_angle_y");
    if ( v215->type == 2 )
      v216 = *(float *)&v215->data.pointer;
    else
      v216 = (float)(int)v215->data.pointer;
    v3->rain_angle_y = v216;
  }
  if ( vostok::configs::binary_config_value::value_exists(v214, (int)t, (unsigned int)"rain_speed") )
  {
    v218 = vostok::configs::binary_config_value::operator[](t, "rain_speed");
    if ( v218->type == 2 )
      v219 = *(float *)&v218->data.pointer;
    else
      v219 = (float)(int)v218->data.pointer;
    v3->rain_speed = v219;
  }
  if ( vostok::configs::binary_config_value::value_exists(v217, (int)t, (unsigned int)"rain_density") )
  {
    v221 = vostok::configs::binary_config_value::operator[](t, "rain_density");
    if ( v221->type == 2 )
      v222 = *(float *)&v221->data.pointer;
    else
      v222 = (float)(int)v221->data.pointer;
    v3->rain_density = v222;
  }
  if ( vostok::configs::binary_config_value::value_exists(v220, (int)t, (unsigned int)"rain_num_cones") )
    v3->rain_num_cones = (unsigned int)vostok::configs::binary_config_value::operator[](t, "rain_num_cones")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v223, (int)t, (unsigned int)"rain_u_scale") )
  {
    v225 = vostok::configs::binary_config_value::operator[](t, "rain_u_scale");
    if ( v225->type == 2 )
      v226 = *(float *)&v225->data.pointer;
    else
      v226 = (float)(int)v225->data.pointer;
    v3->rain_u_scale = v226;
  }
  if ( vostok::configs::binary_config_value::value_exists(v224, (int)t, (unsigned int)"rain_v_scale") )
  {
    v228 = vostok::configs::binary_config_value::operator[](t, "rain_v_scale");
    if ( v228->type == 2 )
      v229 = *(float *)&v228->data.pointer;
    else
      v229 = (float)(int)v228->data.pointer;
    v3->rain_v_scale = v229;
  }
  if ( vostok::configs::binary_config_value::value_exists(v227, (int)t, (unsigned int)"rain_random_rotation_speed") )
  {
    v231 = vostok::configs::binary_config_value::operator[](t, "rain_random_rotation_speed");
    if ( v231->type == 2 )
      v232 = *(float *)&v231->data.pointer;
    else
      v232 = (float)(int)v231->data.pointer;
    v3->rain_random_rotation_speed = v232;
  }
  if ( vostok::configs::binary_config_value::value_exists(v230, (int)t, (unsigned int)"rain_random_rotation_radius") )
  {
    v234 = vostok::configs::binary_config_value::operator[](t, "rain_random_rotation_radius");
    if ( v234->type == 2 )
      v235 = *(float *)&v234->data.pointer;
    else
      v235 = (float)(int)v234->data.pointer;
    v3->rain_random_rotation_radius = v235;
  }
  if ( vostok::configs::binary_config_value::value_exists(v233, (int)t, (unsigned int)"rain_random_base_offset") )
  {
    v237 = vostok::configs::binary_config_value::operator[](t, "rain_random_base_offset");
    if ( v237->type == 2 )
      v238 = *(float *)&v237->data.pointer;
    else
      v238 = (float)(int)v237->data.pointer;
    v3->rain_random_base_offset = v238;
  }
  if ( vostok::configs::binary_config_value::value_exists(v236, (int)t, (unsigned int)"rain_radius_scale") )
  {
    v240 = vostok::configs::binary_config_value::operator[](t, "rain_radius_scale");
    if ( v240->type == 2 )
      v241 = *(float *)&v240->data.pointer;
    else
      v241 = (float)(int)v240->data.pointer;
    v3->rain_radius_scale = v241;
  }
  if ( vostok::configs::binary_config_value::value_exists(v239, (int)t, (unsigned int)"rain_start_cone_index") )
    v3->rain_start_cone_index = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                t,
                                                "rain_start_cone_index")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v242, (int)t, (unsigned int)"wind_direction") )
  {
    props->wind_direction = *(vostok::math::float3 *)vostok::configs::binary_config_value::operator[](
                                                       t,
                                                       "wind_direction")->data.pointer;
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v243, (int)t, (unsigned int)"wind_strength") )
  {
    v245 = vostok::configs::binary_config_value::operator[](t, "wind_strength");
    if ( v245->type == 2 )
      v246 = *(float *)&v245->data.pointer;
    else
      v246 = (float)(int)v245->data.pointer;
    v3->wind_strength = v246;
  }
  if ( vostok::configs::binary_config_value::value_exists(v244, (int)t, (unsigned int)"eye_adaptation_speed") )
  {
    v248 = vostok::configs::binary_config_value::operator[](t, "eye_adaptation_speed");
    if ( v248->type == 2 )
      v249 = *(float *)&v248->data.pointer;
    else
      v249 = (float)(int)v248->data.pointer;
    v3->eye_adaptation_speed = v249;
  }
  if ( vostok::configs::binary_config_value::value_exists(v247, (int)t, (unsigned int)"use_color_grading_texture") )
    v3->use_color_grading_texture = vostok::configs::binary_config_value::operator[](t, "use_color_grading_texture")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v250, (int)t, (unsigned int)"color_grading_weight") )
  {
    v252 = vostok::configs::binary_config_value::operator[](t, "color_grading_weight");
    if ( v252->type == 2 )
      v253 = *(float *)&v252->data.pointer;
    else
      v253 = (float)(int)v252->data.pointer;
    v3->color_grading_weights[0] = v253;
  }
  if ( vostok::configs::binary_config_value::value_exists(v251, (int)t, (unsigned int)"blueshift") )
  {
    v255 = vostok::configs::binary_config_value::operator[](t, "blueshift");
    if ( v255->type == 2 )
      v256 = *(float *)&v255->data.pointer;
    else
      v256 = (float)(int)v255->data.pointer;
    v3->blueshift = v256;
  }
  if ( vostok::configs::binary_config_value::value_exists(v254, (int)t, (unsigned int)"vignette_effect_power") )
  {
    v258 = vostok::configs::binary_config_value::operator[](t, "vignette_effect_power");
    if ( v258->type == 2 )
      v259 = *(float *)&v258->data.pointer;
    else
      v259 = (float)(int)v258->data.pointer;
    v3->vignette_effect_power = v259;
  }
  if ( vostok::configs::binary_config_value::value_exists(v257, (int)t, (unsigned int)"use_dynamic_lens_flare") )
    v3->use_dynamic_lens_flare = vostok::configs::binary_config_value::operator[](t, "use_dynamic_lens_flare")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v260, (int)t, (unsigned int)"lens_flares_multiplier") )
  {
    v262 = vostok::configs::binary_config_value::operator[](t, "lens_flares_multiplier");
    if ( v262->type == 2 )
      v263 = *(float *)&v262->data.pointer;
    else
      v263 = (float)(int)v262->data.pointer;
    v3->lens_flares_multiplier = v263;
  }
  if ( vostok::configs::binary_config_value::value_exists(v261, (int)t, (unsigned int)"use_image_grain") )
    v3->use_image_grain = vostok::configs::binary_config_value::operator[](t, "use_image_grain")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v264, (int)t, (unsigned int)"image_grain_intensity") )
  {
    v266 = vostok::configs::binary_config_value::operator[](t, "image_grain_intensity");
    if ( v266->type == 2 )
      v267 = *(float *)&v266->data.pointer;
    else
      v267 = (float)(int)v266->data.pointer;
    v3->image_grain_intensity = v267;
  }
  if ( vostok::configs::binary_config_value::value_exists(v265, (int)t, (unsigned int)"image_grain_update_frequency") )
    v3->image_grain_update_frequency = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                       t,
                                                       "image_grain_update_frequency")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v268, (int)t, (unsigned int)"use_aberration") )
    v3->use_aberration = vostok::configs::binary_config_value::operator[](t, "use_aberration")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v269, (int)t, (unsigned int)"aberration_amount") )
  {
    v271 = vostok::configs::binary_config_value::operator[](t, "aberration_amount");
    if ( v271->type == 2 )
      v272 = *(float *)&v271->data.pointer;
    else
      v272 = (float)(int)v271->data.pointer;
    v3->aberration_amount = v272;
  }
  if ( vostok::configs::binary_config_value::value_exists(v270, (int)t, (unsigned int)"aberration_red") )
  {
    v274 = vostok::configs::binary_config_value::operator[](t, "aberration_red");
    if ( v274->type == 2 )
      v275 = *(float *)&v274->data.pointer;
    else
      v275 = (float)(int)v274->data.pointer;
    v3->aberration_red = v275;
  }
  if ( vostok::configs::binary_config_value::value_exists(v273, (int)t, (unsigned int)"aberration_blue") )
  {
    v277 = vostok::configs::binary_config_value::operator[](t, "aberration_blue");
    if ( v277->type == 2 )
      v278 = *(float *)&v277->data.pointer;
    else
      v278 = (float)(int)v277->data.pointer;
    v3->aberration_blue = v278;
  }
  if ( vostok::configs::binary_config_value::value_exists(v276, (int)t, (unsigned int)"use_sharpen") )
    v3->use_sharpen = vostok::configs::binary_config_value::operator[](t, "use_sharpen")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v279, (int)t, (unsigned int)"sharpen_amount") )
  {
    v281 = vostok::configs::binary_config_value::operator[](t, "sharpen_amount");
    if ( v281->type == 2 )
      v282 = *(float *)&v281->data.pointer;
    else
      v282 = (float)(int)v281->data.pointer;
    v3->sharpen_amount = v282;
  }
  if ( vostok::configs::binary_config_value::value_exists(v280, (int)t, (unsigned int)"bloom_intensity") )
  {
    v284 = vostok::configs::binary_config_value::operator[](t, "bloom_intensity");
    if ( v284->type == 2 )
      v285 = *(float *)&v284->data.pointer;
    else
      v285 = (float)(int)v284->data.pointer;
    v3->bloom_intensity = v285;
  }
  if ( vostok::configs::binary_config_value::value_exists(v283, (int)t, (unsigned int)"bloom_ratio") )
  {
    v287 = vostok::configs::binary_config_value::operator[](t, "bloom_ratio");
    if ( v287->type == 2 )
      v288 = *(float *)&v287->data.pointer;
    else
      v288 = (float)(int)v287->data.pointer;
    v3->bloom_ratio = v288;
  }
  if ( vostok::configs::binary_config_value::value_exists(v286, (int)t, (unsigned int)"blur_kernel") )
    v3->blur_kernel = (unsigned int)vostok::configs::binary_config_value::operator[](t, "blur_kernel")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v289, (int)t, (unsigned int)"bloom_color") )
  {
    v291 = (const vostok::math::float4 **)vostok::configs::binary_config_value::operator[](t, "bloom_color");
    props->bloom_color = *vostok::render::convert_to_linear_space(*v291);
    v3 = props;
  }
  if ( vostok::configs::binary_config_value::value_exists(v290, (int)t, (unsigned int)"use_bokeh_dof") )
    v3->use_bokeh_dof = vostok::configs::binary_config_value::operator[](t, "use_bokeh_dof")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v292, (int)t, (unsigned int)"bokeh_radius") )
  {
    v294 = vostok::configs::binary_config_value::operator[](t, "bokeh_radius");
    if ( v294->type == 2 )
      v295 = *(float *)&v294->data.pointer;
    else
      v295 = (float)(int)v294->data.pointer;
    v3->bokeh_radius = v295;
  }
  if ( vostok::configs::binary_config_value::value_exists(v293, (int)t, (unsigned int)"bokeh_density") )
  {
    v297 = vostok::configs::binary_config_value::operator[](t, "bokeh_density");
    if ( v297->type == 2 )
      v298 = *(float *)&v297->data.pointer;
    else
      v298 = (float)(int)v297->data.pointer;
    v3->bokeh_density = v298;
  }
  if ( vostok::configs::binary_config_value::value_exists(v296, (int)t, (unsigned int)"use_bokeh_template_image") )
    v3->use_bokeh_template_image = vostok::configs::binary_config_value::operator[](t, "use_bokeh_template_image")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v299, (int)t, (unsigned int)"dof_focus_region") )
  {
    v301 = vostok::configs::binary_config_value::operator[](t, "dof_focus_region");
    if ( v301->type == 2 )
      v302 = *(float *)&v301->data.pointer;
    else
      v302 = (float)(int)v301->data.pointer;
    v3->dof_focus_region = v302;
  }
  if ( vostok::configs::binary_config_value::value_exists(v300, (int)t, (unsigned int)"dof_focus_distance") )
  {
    v304 = vostok::configs::binary_config_value::operator[](t, "dof_focus_distance");
    if ( v304->type == 2 )
      v305 = *(float *)&v304->data.pointer;
    else
      v305 = (float)(int)v304->data.pointer;
    v3->dof_focus_distance = v305;
  }
  if ( vostok::configs::binary_config_value::value_exists(v303, (int)t, (unsigned int)"dof_blur_kernel") )
    v3->dof_blur_kernel = (unsigned int)vostok::configs::binary_config_value::operator[](t, "dof_blur_kernel")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v306, (int)t, (unsigned int)"dof_near_blurness_amount") )
  {
    v308 = vostok::configs::binary_config_value::operator[](t, "dof_near_blurness_amount");
    if ( v308->type == 2 )
      v309 = *(float *)&v308->data.pointer;
    else
      v309 = (float)(int)v308->data.pointer;
    v3->dof_near_blurness_amount = v309;
  }
  if ( vostok::configs::binary_config_value::value_exists(v307, (int)t, (unsigned int)"dof_far_blurness_amount") )
  {
    v310 = vostok::configs::binary_config_value::operator[](t, "dof_far_blurness_amount");
    if ( v310->type == 2 )
      v311 = *(float *)&v310->data.pointer;
    else
      v311 = (float)(int)v310->data.pointer;
    v3->dof_far_blurness_amount = v311;
  }
}
