void __thiscall survarium::game_options::fill_labels(survarium::game_options *this, survarium::game_options *thisa)
{
  char *m_buffer; // eax
  const char *v3; // ecx
  char *v4; // eax
  const char *v5; // ecx
  char *v6; // eax
  const char *v7; // ecx
  char *v8; // eax
  const char *v9; // ecx
  char *v10; // eax
  const char *v11; // ecx
  char *v12; // eax
  const char *v13; // ecx
  char *v14; // eax
  const char *v15; // ecx
  char *v16; // eax
  const char *v17; // ecx
  char *v18; // eax
  const char *v19; // ecx
  char *v20; // eax
  const char *v21; // ecx
  char *v22; // eax
  const char *v23; // ecx
  char *v24; // eax
  const char *v25; // ecx
  char *v26; // eax
  const char *v27; // ecx
  char *v28; // eax
  const char *v29; // ecx
  char *v30; // eax
  const char *v31; // ecx
  char *v32; // eax
  const char *v33; // ecx
  char *v34; // eax
  const char *v35; // ecx
  char *v36; // eax
  const char *v37; // ecx
  char *v38; // eax
  const char *v39; // ecx
  char *v40; // eax
  const char *v41; // ecx
  char *v42; // eax
  const char *v43; // ecx
  char *v44; // eax
  const char *v45; // ecx
  char *v46; // eax
  const char *v47; // ecx
  char *v48; // eax
  const char *v49; // ecx
  char *v50; // eax
  const char *v51; // ecx
  char *v52; // eax
  const char *v53; // ecx
  char *v54; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **p_m_movie; // ecx
  char *v56; // eax
  const char *v57; // ecx
  char *v58; // eax
  const char *v59; // ecx
  char *v60; // eax
  const char *v61; // ecx
  char *v62; // eax
  const char *v63; // ecx
  char *v64; // eax
  const char *v65; // ecx
  char *v66; // eax
  const char *v67; // ecx
  char *v68; // eax
  const char *v69; // ecx
  char *v70; // eax
  const char *v71; // ecx
  char *v72; // eax
  const char *v73; // ecx
  char *v74; // eax
  const char *v75; // ecx
  char *v76; // eax
  const char *v77; // ecx
  char *v78; // eax
  const char *v79; // ecx
  char *v80; // eax
  const char *v81; // ecx
  char *v82; // eax
  const char *v83; // ecx
  char *v84; // eax
  const char *v85; // ecx
  char *v86; // eax
  const char *v87; // ecx
  char *v88; // eax
  const char *v89; // ecx
  survarium::flash_movie_resource *m_object; // edx
  int v91; // ebp
  vostok::fixed_string<32> *p_label; // esi
  survarium::flash_movie_resource *v93; // edx
  int v94; // ecx
  survarium::flash_value label_member; // [esp+44h] [ebp-BF4h] BYREF
  int v96; // [esp+5Ch] [ebp-BDCh]
  survarium::flash_value label; // [esp+60h] [ebp-BD8h] BYREF
  survarium::flash_value labels_array; // [esp+78h] [ebp-BC0h] BYREF
  int v99; // [esp+90h] [ebp-BA8h] BYREF
  int v100; // [esp+94h] [ebp-BA4h]
  wchar_t *v101; // [esp+98h] [ebp-BA0h]
  survarium::options_name_to_label names_to_label[22]; // [esp+A8h] [ebp-B90h] BYREF
  wchar_t label_txt[512]; // [esp+838h] [ebp-400h] BYREF

  m_buffer = names_to_label[0].name.m_buffer;
  names_to_label[0].name.m_max_end = (char *)&names_to_label[0].label;
  names_to_label[0].name.m_begin = names_to_label[0].name.m_buffer;
  names_to_label[0].name.m_end = names_to_label[0].name.m_buffer;
  names_to_label[0].name.m_buffer[0] = 0;
  v3 = "s_friends";
  do
  {
    if ( m_buffer >= names_to_label[0].name.m_max_end )
      break;
    *m_buffer = *v3;
    m_buffer = names_to_label[0].name.m_end + 1;
    ++v3;
    ++names_to_label[0].name.m_end;
  }
  while ( *v3 );
  *m_buffer = 0;
  v4 = names_to_label[0].label.m_buffer;
  names_to_label[0].label.m_max_end = (char *)&names_to_label[1];
  names_to_label[0].label.m_begin = names_to_label[0].label.m_buffer;
  names_to_label[0].label.m_end = names_to_label[0].label.m_buffer;
  names_to_label[0].label.m_buffer[0] = 0;
  v5 = "st_options_friends";
  do
  {
    if ( v4 >= names_to_label[0].label.m_max_end )
      break;
    *v4 = *v5;
    v4 = names_to_label[0].label.m_end + 1;
    ++v5;
    ++names_to_label[0].label.m_end;
  }
  while ( *v5 );
  *v4 = 0;
  v6 = names_to_label[1].name.m_buffer;
  names_to_label[1].name.m_max_end = (char *)&names_to_label[1].label;
  names_to_label[1].name.m_begin = names_to_label[1].name.m_buffer;
  names_to_label[1].name.m_end = names_to_label[1].name.m_buffer;
  names_to_label[1].name.m_buffer[0] = 0;
  v7 = "s_cross";
  do
  {
    if ( v6 >= names_to_label[1].name.m_max_end )
      break;
    *v6 = *v7;
    v6 = names_to_label[1].name.m_end + 1;
    ++v7;
    ++names_to_label[1].name.m_end;
  }
  while ( *v7 );
  *v6 = 0;
  v8 = names_to_label[1].label.m_buffer;
  names_to_label[1].label.m_max_end = (char *)&names_to_label[2];
  names_to_label[1].label.m_begin = names_to_label[1].label.m_buffer;
  names_to_label[1].label.m_end = names_to_label[1].label.m_buffer;
  names_to_label[1].label.m_buffer[0] = 0;
  v9 = "st_options_cross_type";
  do
  {
    if ( v8 >= names_to_label[1].label.m_max_end )
      break;
    *v8 = *v9;
    v8 = names_to_label[1].label.m_end + 1;
    ++v9;
    ++names_to_label[1].label.m_end;
  }
  while ( *v9 );
  *v8 = 0;
  v10 = names_to_label[2].name.m_buffer;
  names_to_label[2].name.m_max_end = (char *)&names_to_label[2].label;
  names_to_label[2].name.m_begin = names_to_label[2].name.m_buffer;
  names_to_label[2].name.m_end = names_to_label[2].name.m_buffer;
  names_to_label[2].name.m_buffer[0] = 0;
  v11 = "s_chat";
  do
  {
    if ( v10 >= names_to_label[2].name.m_max_end )
      break;
    *v10 = *v11;
    v10 = names_to_label[2].name.m_end + 1;
    ++v11;
    ++names_to_label[2].name.m_end;
  }
  while ( *v11 );
  *v10 = 0;
  v12 = names_to_label[2].label.m_buffer;
  names_to_label[2].label.m_max_end = (char *)&names_to_label[3];
  names_to_label[2].label.m_begin = names_to_label[2].label.m_buffer;
  names_to_label[2].label.m_end = names_to_label[2].label.m_buffer;
  names_to_label[2].label.m_buffer[0] = 0;
  v13 = "st_options_chat";
  do
  {
    if ( v12 >= names_to_label[2].label.m_max_end )
      break;
    *v12 = *v13;
    v12 = names_to_label[2].label.m_end + 1;
    ++v13;
    ++names_to_label[2].label.m_end;
  }
  while ( *v13 );
  *v12 = 0;
  v14 = names_to_label[3].name.m_buffer;
  names_to_label[3].name.m_max_end = (char *)&names_to_label[3].label;
  names_to_label[3].name.m_begin = names_to_label[3].name.m_buffer;
  names_to_label[3].name.m_end = names_to_label[3].name.m_buffer;
  names_to_label[3].name.m_buffer[0] = 0;
  v15 = "s_lobby";
  do
  {
    if ( v14 >= names_to_label[3].name.m_max_end )
      break;
    *v14 = *v15;
    v14 = names_to_label[3].name.m_end + 1;
    ++v15;
    ++names_to_label[3].name.m_end;
  }
  while ( *v15 );
  *v14 = 0;
  v16 = names_to_label[3].label.m_buffer;
  names_to_label[3].label.m_max_end = (char *)&names_to_label[4];
  names_to_label[3].label.m_begin = names_to_label[3].label.m_buffer;
  names_to_label[3].label.m_end = names_to_label[3].label.m_buffer;
  names_to_label[3].label.m_buffer[0] = 0;
  v17 = "st_options_lobby";
  do
  {
    if ( v16 >= names_to_label[3].label.m_max_end )
      break;
    *v16 = *v17;
    v16 = names_to_label[3].label.m_end + 1;
    ++v17;
    ++names_to_label[3].label.m_end;
  }
  while ( *v17 );
  *v16 = 0;
  v18 = names_to_label[4].name.m_buffer;
  names_to_label[4].name.m_max_end = (char *)&names_to_label[4].label;
  names_to_label[4].name.m_begin = names_to_label[4].name.m_buffer;
  names_to_label[4].name.m_end = names_to_label[4].name.m_buffer;
  names_to_label[4].name.m_buffer[0] = 0;
  v19 = "s_game";
  do
  {
    if ( v18 >= names_to_label[4].name.m_max_end )
      break;
    *v18 = *v19;
    v18 = names_to_label[4].name.m_end + 1;
    ++v19;
    ++names_to_label[4].name.m_end;
  }
  while ( *v19 );
  *v18 = 0;
  v20 = names_to_label[4].label.m_buffer;
  names_to_label[4].label.m_max_end = (char *)&names_to_label[5];
  names_to_label[4].label.m_begin = names_to_label[4].label.m_buffer;
  names_to_label[4].label.m_end = names_to_label[4].label.m_buffer;
  names_to_label[4].label.m_buffer[0] = 0;
  v21 = "st_options_game";
  do
  {
    if ( v20 >= names_to_label[4].label.m_max_end )
      break;
    *v20 = *v21;
    v20 = names_to_label[4].label.m_end + 1;
    ++v21;
    ++names_to_label[4].label.m_end;
  }
  while ( *v21 );
  *v20 = 0;
  v22 = names_to_label[5].name.m_buffer;
  names_to_label[5].name.m_max_end = (char *)&names_to_label[5].label;
  names_to_label[5].name.m_begin = names_to_label[5].name.m_buffer;
  names_to_label[5].name.m_end = names_to_label[5].name.m_buffer;
  names_to_label[5].name.m_buffer[0] = 0;
  v23 = "s_chat_keys";
  do
  {
    if ( v22 >= names_to_label[5].name.m_max_end )
      break;
    *v22 = *v23;
    v22 = names_to_label[5].name.m_end + 1;
    ++v23;
    ++names_to_label[5].name.m_end;
  }
  while ( *v23 );
  *v22 = 0;
  v24 = names_to_label[5].label.m_buffer;
  names_to_label[5].label.m_max_end = (char *)&names_to_label[6];
  names_to_label[5].label.m_begin = names_to_label[5].label.m_buffer;
  names_to_label[5].label.m_end = names_to_label[5].label.m_buffer;
  names_to_label[5].label.m_buffer[0] = 0;
  v25 = "st_options_chat_keys";
  do
  {
    if ( v24 >= names_to_label[5].label.m_max_end )
      break;
    *v24 = *v25;
    v24 = names_to_label[5].label.m_end + 1;
    ++v25;
    ++names_to_label[5].label.m_end;
  }
  while ( *v25 );
  *v24 = 0;
  v26 = names_to_label[6].name.m_buffer;
  names_to_label[6].name.m_max_end = (char *)&names_to_label[6].label;
  names_to_label[6].name.m_begin = names_to_label[6].name.m_buffer;
  names_to_label[6].name.m_end = names_to_label[6].name.m_buffer;
  names_to_label[6].name.m_buffer[0] = 0;
  v27 = "gameplay_options_type";
  do
  {
    if ( v26 >= names_to_label[6].name.m_max_end )
      break;
    *v26 = *v27;
    v26 = names_to_label[6].name.m_end + 1;
    ++v27;
    ++names_to_label[6].name.m_end;
  }
  while ( *v27 );
  *v26 = 0;
  v28 = names_to_label[6].label.m_buffer;
  names_to_label[6].label.m_max_end = (char *)&names_to_label[7];
  names_to_label[6].label.m_begin = names_to_label[6].label.m_buffer;
  names_to_label[6].label.m_end = names_to_label[6].label.m_buffer;
  names_to_label[6].label.m_buffer[0] = 0;
  v29 = "st_options_gameplay";
  do
  {
    if ( v28 >= names_to_label[6].label.m_max_end )
      break;
    *v28 = *v29;
    v28 = names_to_label[6].label.m_end + 1;
    ++v29;
    ++names_to_label[6].label.m_end;
  }
  while ( *v29 );
  *v28 = 0;
  v30 = names_to_label[7].name.m_buffer;
  names_to_label[7].name.m_max_end = (char *)&names_to_label[7].label;
  names_to_label[7].name.m_begin = names_to_label[7].name.m_buffer;
  names_to_label[7].name.m_end = names_to_label[7].name.m_buffer;
  names_to_label[7].name.m_buffer[0] = 0;
  v31 = "controllers_options_type";
  do
  {
    if ( v30 >= names_to_label[7].name.m_max_end )
      break;
    *v30 = *v31;
    v30 = names_to_label[7].name.m_end + 1;
    ++v31;
    ++names_to_label[7].name.m_end;
  }
  while ( *v31 );
  *v30 = 0;
  v32 = names_to_label[7].label.m_buffer;
  names_to_label[7].label.m_max_end = (char *)&names_to_label[8];
  names_to_label[7].label.m_begin = names_to_label[7].label.m_buffer;
  names_to_label[7].label.m_end = names_to_label[7].label.m_buffer;
  names_to_label[7].label.m_buffer[0] = 0;
  v33 = "st_options_controller";
  do
  {
    if ( v32 >= names_to_label[7].label.m_max_end )
      break;
    *v32 = *v33;
    v32 = names_to_label[7].label.m_end + 1;
    ++v33;
    ++names_to_label[7].label.m_end;
  }
  while ( *v33 );
  *v32 = 0;
  v34 = names_to_label[8].name.m_buffer;
  names_to_label[8].name.m_max_end = (char *)&names_to_label[8].label;
  names_to_label[8].name.m_begin = names_to_label[8].name.m_buffer;
  names_to_label[8].name.m_end = names_to_label[8].name.m_buffer;
  names_to_label[8].name.m_buffer[0] = 0;
  v35 = "video_options_type";
  do
  {
    if ( v34 >= names_to_label[8].name.m_max_end )
      break;
    *v34 = *v35;
    v34 = names_to_label[8].name.m_end + 1;
    ++v35;
    ++names_to_label[8].name.m_end;
  }
  while ( *v35 );
  *v34 = 0;
  v36 = names_to_label[8].label.m_buffer;
  names_to_label[8].label.m_max_end = (char *)&names_to_label[9];
  names_to_label[8].label.m_begin = names_to_label[8].label.m_buffer;
  names_to_label[8].label.m_end = names_to_label[8].label.m_buffer;
  names_to_label[8].label.m_buffer[0] = 0;
  v37 = "st_options_video";
  do
  {
    if ( v36 >= names_to_label[8].label.m_max_end )
      break;
    *v36 = *v37;
    v36 = names_to_label[8].label.m_end + 1;
    ++v37;
    ++names_to_label[8].label.m_end;
  }
  while ( *v37 );
  *v36 = 0;
  v38 = names_to_label[9].name.m_buffer;
  names_to_label[9].name.m_max_end = (char *)&names_to_label[9].label;
  names_to_label[9].name.m_begin = names_to_label[9].name.m_buffer;
  names_to_label[9].name.m_end = names_to_label[9].name.m_buffer;
  names_to_label[9].name.m_buffer[0] = 0;
  v39 = "sound_options_type";
  do
  {
    if ( v38 >= names_to_label[9].name.m_max_end )
      break;
    *v38 = *v39;
    v38 = names_to_label[9].name.m_end + 1;
    ++v39;
    ++names_to_label[9].name.m_end;
  }
  while ( *v39 );
  *v38 = 0;
  v40 = names_to_label[9].label.m_buffer;
  names_to_label[9].label.m_max_end = (char *)&names_to_label[10];
  names_to_label[9].label.m_begin = names_to_label[9].label.m_buffer;
  names_to_label[9].label.m_end = names_to_label[9].label.m_buffer;
  names_to_label[9].label.m_buffer[0] = 0;
  v41 = "st_options_sound";
  do
  {
    if ( v40 >= names_to_label[9].label.m_max_end )
      break;
    *v40 = *v41;
    v40 = names_to_label[9].label.m_end + 1;
    ++v41;
    ++names_to_label[9].label.m_end;
  }
  while ( *v41 );
  *v40 = 0;
  v42 = names_to_label[10].name.m_buffer;
  names_to_label[10].name.m_max_end = (char *)&names_to_label[10].label;
  names_to_label[10].name.m_begin = names_to_label[10].name.m_buffer;
  names_to_label[10].name.m_end = names_to_label[10].name.m_buffer;
  names_to_label[10].name.m_buffer[0] = 0;
  v43 = "adjust_gamma";
  do
  {
    if ( v42 >= names_to_label[10].name.m_max_end )
      break;
    *v42 = *v43;
    v42 = names_to_label[10].name.m_end + 1;
    ++v43;
    ++names_to_label[10].name.m_end;
  }
  while ( *v43 );
  *v42 = 0;
  v44 = names_to_label[10].label.m_buffer;
  names_to_label[10].label.m_max_end = (char *)&names_to_label[11];
  names_to_label[10].label.m_begin = names_to_label[10].label.m_buffer;
  names_to_label[10].label.m_end = names_to_label[10].label.m_buffer;
  names_to_label[10].label.m_buffer[0] = 0;
  v45 = "st_monitor_ajust";
  do
  {
    if ( v44 >= names_to_label[10].label.m_max_end )
      break;
    *v44 = *v45;
    v44 = names_to_label[10].label.m_end + 1;
    ++v45;
    ++names_to_label[10].label.m_end;
  }
  while ( *v45 );
  *v44 = 0;
  v46 = names_to_label[11].name.m_buffer;
  names_to_label[11].name.m_max_end = (char *)&names_to_label[11].label;
  names_to_label[11].name.m_begin = names_to_label[11].name.m_buffer;
  names_to_label[11].name.m_end = names_to_label[11].name.m_buffer;
  names_to_label[11].name.m_buffer[0] = 0;
  v47 = "button_default_video";
  do
  {
    if ( v46 >= names_to_label[11].name.m_max_end )
      break;
    *v46 = *v47;
    v46 = names_to_label[11].name.m_end + 1;
    ++v47;
    ++names_to_label[11].name.m_end;
  }
  while ( *v47 );
  *v46 = 0;
  v48 = names_to_label[11].label.m_buffer;
  names_to_label[11].label.m_max_end = (char *)&names_to_label[12];
  names_to_label[11].label.m_begin = names_to_label[11].label.m_buffer;
  names_to_label[11].label.m_end = names_to_label[11].label.m_buffer;
  names_to_label[11].label.m_buffer[0] = 0;
  v49 = "st_options_default_video";
  do
  {
    if ( v48 >= names_to_label[11].label.m_max_end )
      break;
    *v48 = *v49;
    v48 = names_to_label[11].label.m_end + 1;
    ++v49;
    ++names_to_label[11].label.m_end;
  }
  while ( *v49 );
  *v48 = 0;
  v50 = names_to_label[12].name.m_buffer;
  names_to_label[12].name.m_max_end = (char *)&names_to_label[12].label;
  names_to_label[12].name.m_begin = names_to_label[12].name.m_buffer;
  names_to_label[12].name.m_end = names_to_label[12].name.m_buffer;
  names_to_label[12].name.m_buffer[0] = 0;
  v51 = "button_default_controls";
  do
  {
    if ( v50 >= names_to_label[12].name.m_max_end )
      break;
    *v50 = *v51;
    v50 = names_to_label[12].name.m_end + 1;
    ++v51;
    ++names_to_label[12].name.m_end;
  }
  while ( *v51 );
  *v50 = 0;
  v52 = names_to_label[12].label.m_buffer;
  names_to_label[12].label.m_max_end = (char *)&names_to_label[13];
  names_to_label[12].label.m_begin = names_to_label[12].label.m_buffer;
  names_to_label[12].label.m_end = names_to_label[12].label.m_buffer;
  names_to_label[12].label.m_buffer[0] = 0;
  v53 = "st_options_default_controls";
  do
  {
    if ( v52 >= names_to_label[12].label.m_max_end )
      break;
    *v52 = *v53;
    v52 = names_to_label[12].label.m_end + 1;
    ++v53;
    ++names_to_label[12].label.m_end;
  }
  while ( *v53 );
  *v52 = 0;
  v54 = names_to_label[13].name.m_buffer;
  names_to_label[13].name.m_max_end = (char *)&names_to_label[13].label;
  names_to_label[13].name.m_begin = names_to_label[13].name.m_buffer;
  names_to_label[13].name.m_end = names_to_label[13].name.m_buffer;
  names_to_label[13].name.m_buffer[0] = 0;
  p_m_movie = &stru_96AC08.m_movie;
  do
  {
    if ( v54 >= names_to_label[13].name.m_max_end )
      break;
    *v54 = *(_BYTE *)p_m_movie;
    v54 = names_to_label[13].name.m_end + 1;
    p_m_movie = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)((char *)p_m_movie + 1);
    ++names_to_label[13].name.m_end;
  }
  while ( *(_BYTE *)p_m_movie );
  *v54 = 0;
  v56 = names_to_label[13].label.m_buffer;
  names_to_label[13].label.m_max_end = (char *)&names_to_label[14];
  names_to_label[13].label.m_begin = names_to_label[13].label.m_buffer;
  names_to_label[13].label.m_end = names_to_label[13].label.m_buffer;
  names_to_label[13].label.m_buffer[0] = 0;
  v57 = "st_options_optimal_video";
  do
  {
    if ( v56 >= names_to_label[13].label.m_max_end )
      break;
    *v56 = *v57;
    v56 = names_to_label[13].label.m_end + 1;
    ++v57;
    ++names_to_label[13].label.m_end;
  }
  while ( *v57 );
  *v56 = 0;
  v58 = names_to_label[14].name.m_buffer;
  names_to_label[14].name.m_max_end = (char *)&names_to_label[14].label;
  names_to_label[14].name.m_begin = names_to_label[14].name.m_buffer;
  names_to_label[14].name.m_end = names_to_label[14].name.m_buffer;
  names_to_label[14].name.m_buffer[0] = 0;
  v59 = "button_ok";
  do
  {
    if ( v58 >= names_to_label[14].name.m_max_end )
      break;
    *v58 = *v59;
    v58 = names_to_label[14].name.m_end + 1;
    ++v59;
    ++names_to_label[14].name.m_end;
  }
  while ( *v59 );
  *v58 = 0;
  v60 = names_to_label[14].label.m_buffer;
  names_to_label[14].label.m_max_end = (char *)&names_to_label[15];
  names_to_label[14].label.m_begin = names_to_label[14].label.m_buffer;
  names_to_label[14].label.m_end = names_to_label[14].label.m_buffer;
  names_to_label[14].label.m_buffer[0] = 0;
  v61 = "st_options_ok";
  do
  {
    if ( v60 >= names_to_label[14].label.m_max_end )
      break;
    *v60 = *v61;
    v60 = names_to_label[14].label.m_end + 1;
    ++v61;
    ++names_to_label[14].label.m_end;
  }
  while ( *v61 );
  *v60 = 0;
  v62 = names_to_label[15].name.m_buffer;
  names_to_label[15].name.m_max_end = (char *)&names_to_label[15].label;
  names_to_label[15].name.m_begin = names_to_label[15].name.m_buffer;
  names_to_label[15].name.m_end = names_to_label[15].name.m_buffer;
  names_to_label[15].name.m_buffer[0] = 0;
  v63 = "button_apply";
  do
  {
    if ( v62 >= names_to_label[15].name.m_max_end )
      break;
    *v62 = *v63;
    v62 = names_to_label[15].name.m_end + 1;
    ++v63;
    ++names_to_label[15].name.m_end;
  }
  while ( *v63 );
  *v62 = 0;
  v64 = names_to_label[15].label.m_buffer;
  names_to_label[15].label.m_max_end = (char *)&names_to_label[16];
  names_to_label[15].label.m_begin = names_to_label[15].label.m_buffer;
  names_to_label[15].label.m_end = names_to_label[15].label.m_buffer;
  names_to_label[15].label.m_buffer[0] = 0;
  v65 = "st_options_apply";
  do
  {
    if ( v64 >= names_to_label[15].label.m_max_end )
      break;
    *v64 = *v65;
    v64 = names_to_label[15].label.m_end + 1;
    ++v65;
    ++names_to_label[15].label.m_end;
  }
  while ( *v65 );
  *v64 = 0;
  v66 = names_to_label[16].name.m_buffer;
  names_to_label[16].name.m_max_end = (char *)&names_to_label[16].label;
  names_to_label[16].name.m_begin = names_to_label[16].name.m_buffer;
  names_to_label[16].name.m_end = names_to_label[16].name.m_buffer;
  names_to_label[16].name.m_buffer[0] = 0;
  v67 = "button_cancel";
  do
  {
    if ( v66 >= names_to_label[16].name.m_max_end )
      break;
    *v66 = *v67;
    v66 = names_to_label[16].name.m_end + 1;
    ++v67;
    ++names_to_label[16].name.m_end;
  }
  while ( *v67 );
  *v66 = 0;
  v68 = names_to_label[16].label.m_buffer;
  names_to_label[16].label.m_max_end = (char *)&names_to_label[17];
  names_to_label[16].label.m_begin = names_to_label[16].label.m_buffer;
  names_to_label[16].label.m_end = names_to_label[16].label.m_buffer;
  names_to_label[16].label.m_buffer[0] = 0;
  v69 = "st_options_cancel";
  do
  {
    if ( v68 >= names_to_label[16].label.m_max_end )
      break;
    *v68 = *v69;
    v68 = names_to_label[16].label.m_end + 1;
    ++v69;
    ++names_to_label[16].label.m_end;
  }
  while ( *v69 );
  *v68 = 0;
  v70 = names_to_label[17].name.m_buffer;
  names_to_label[17].name.m_max_end = (char *)&names_to_label[17].label;
  names_to_label[17].name.m_begin = names_to_label[17].name.m_buffer;
  names_to_label[17].name.m_end = names_to_label[17].name.m_buffer;
  names_to_label[17].name.m_buffer[0] = 0;
  v71 = "apply_changes_msg";
  do
  {
    if ( v70 >= names_to_label[17].name.m_max_end )
      break;
    *v70 = *v71;
    v70 = names_to_label[17].name.m_end + 1;
    ++v71;
    ++names_to_label[17].name.m_end;
  }
  while ( *v71 );
  *v70 = 0;
  v72 = names_to_label[17].label.m_buffer;
  names_to_label[17].label.m_max_end = (char *)&names_to_label[18];
  names_to_label[17].label.m_begin = names_to_label[17].label.m_buffer;
  names_to_label[17].label.m_end = names_to_label[17].label.m_buffer;
  names_to_label[17].label.m_buffer[0] = 0;
  v73 = "st_apply_changes_msg";
  do
  {
    if ( v72 >= names_to_label[17].label.m_max_end )
      break;
    *v72 = *v73;
    v72 = names_to_label[17].label.m_end + 1;
    ++v73;
    ++names_to_label[17].label.m_end;
  }
  while ( *v73 );
  *v72 = 0;
  v74 = names_to_label[18].name.m_buffer;
  names_to_label[18].name.m_max_end = (char *)&names_to_label[18].label;
  names_to_label[18].name.m_begin = names_to_label[18].name.m_buffer;
  names_to_label[18].name.m_end = names_to_label[18].name.m_buffer;
  names_to_label[18].name.m_buffer[0] = 0;
  v75 = "s_voice_chat";
  do
  {
    if ( v74 >= names_to_label[18].name.m_max_end )
      break;
    *v74 = *v75;
    v74 = names_to_label[18].name.m_end + 1;
    ++v75;
    ++names_to_label[18].name.m_end;
  }
  while ( *v75 );
  *v74 = 0;
  v76 = names_to_label[18].label.m_buffer;
  names_to_label[18].label.m_max_end = (char *)&names_to_label[19];
  names_to_label[18].label.m_begin = names_to_label[18].label.m_buffer;
  names_to_label[18].label.m_end = names_to_label[18].label.m_buffer;
  names_to_label[18].label.m_buffer[0] = 0;
  v77 = "st_options_voice";
  do
  {
    if ( v76 >= names_to_label[18].label.m_max_end )
      break;
    *v76 = *v77;
    v76 = names_to_label[18].label.m_end + 1;
    ++v77;
    ++names_to_label[18].label.m_end;
  }
  while ( *v77 );
  *v76 = 0;
  v78 = names_to_label[19].name.m_buffer;
  names_to_label[19].name.m_max_end = (char *)&names_to_label[19].label;
  names_to_label[19].name.m_begin = names_to_label[19].name.m_buffer;
  names_to_label[19].name.m_end = names_to_label[19].name.m_buffer;
  names_to_label[19].name.m_buffer[0] = 0;
  v79 = "s_sound_volume";
  do
  {
    if ( v78 >= names_to_label[19].name.m_max_end )
      break;
    *v78 = *v79;
    v78 = names_to_label[19].name.m_end + 1;
    ++v79;
    ++names_to_label[19].name.m_end;
  }
  while ( *v79 );
  *v78 = 0;
  v80 = names_to_label[19].label.m_buffer;
  names_to_label[19].label.m_max_end = (char *)&names_to_label[20];
  names_to_label[19].label.m_begin = names_to_label[19].label.m_buffer;
  names_to_label[19].label.m_end = names_to_label[19].label.m_buffer;
  names_to_label[19].label.m_buffer[0] = 0;
  v81 = "st_options_volume";
  do
  {
    if ( v80 >= names_to_label[19].label.m_max_end )
      break;
    *v80 = *v81;
    v80 = names_to_label[19].label.m_end + 1;
    ++v81;
    ++names_to_label[19].label.m_end;
  }
  while ( *v81 );
  *v80 = 0;
  v82 = names_to_label[20].name.m_buffer;
  names_to_label[20].name.m_max_end = (char *)&names_to_label[20].label;
  names_to_label[20].name.m_begin = names_to_label[20].name.m_buffer;
  names_to_label[20].name.m_end = names_to_label[20].name.m_buffer;
  names_to_label[20].name.m_buffer[0] = 0;
  v83 = "bind_text";
  do
  {
    if ( v82 >= names_to_label[20].name.m_max_end )
      break;
    *v82 = *v83;
    v82 = names_to_label[20].name.m_end + 1;
    ++v83;
    ++names_to_label[20].name.m_end;
  }
  while ( *v83 );
  *v82 = 0;
  v84 = names_to_label[20].label.m_buffer;
  names_to_label[20].label.m_max_end = (char *)&names_to_label[21];
  names_to_label[20].label.m_begin = names_to_label[20].label.m_buffer;
  names_to_label[20].label.m_end = names_to_label[20].label.m_buffer;
  names_to_label[20].label.m_buffer[0] = 0;
  v85 = "st_bind_text";
  do
  {
    if ( v84 >= names_to_label[20].label.m_max_end )
      break;
    *v84 = *v85;
    v84 = names_to_label[20].label.m_end + 1;
    ++v85;
    ++names_to_label[20].label.m_end;
  }
  while ( *v85 );
  *v84 = 0;
  v86 = names_to_label[21].name.m_buffer;
  names_to_label[21].name.m_max_end = (char *)&names_to_label[21].label;
  names_to_label[21].name.m_begin = names_to_label[21].name.m_buffer;
  names_to_label[21].name.m_end = names_to_label[21].name.m_buffer;
  names_to_label[21].name.m_buffer[0] = 0;
  v87 = "s_minimap";
  do
  {
    if ( v86 >= names_to_label[21].name.m_max_end )
      break;
    *v86 = *v87;
    v86 = names_to_label[21].name.m_end + 1;
    ++v87;
    ++names_to_label[21].name.m_end;
  }
  while ( *v87 );
  *v86 = 0;
  v88 = names_to_label[21].label.m_buffer;
  names_to_label[21].label.m_max_end = (char *)label_txt;
  names_to_label[21].label.m_begin = names_to_label[21].label.m_buffer;
  names_to_label[21].label.m_end = names_to_label[21].label.m_buffer;
  names_to_label[21].label.m_buffer[0] = 0;
  v89 = "st_minimap";
  do
  {
    if ( v88 >= names_to_label[21].label.m_max_end )
      break;
    *v88 = *v89;
    v88 = names_to_label[21].label.m_end + 1;
    ++v89;
    ++names_to_label[21].label.m_end;
  }
  while ( *v89 );
  *v88 = 0;
  m_object = thisa->m_options_ui.m_object;
  *(_DWORD *)labels_array.body = 0;
  *(_DWORD *)&labels_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&labels_array);
  v91 = 0;
  p_label = &names_to_label[0].label;
  v96 = 22;
  do
  {
    v93 = thisa->m_options_ui.m_object;
    *(_DWORD *)label.body = 0;
    *(_DWORD *)&label.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v93->movie->m_movie, (Scaleform::GFx::Value *)&label, 0, 0, 0);
    *(_DWORD *)&label_member.body[8] = p_label[-1].m_begin;
    *(_DWORD *)label_member.body = 0;
    *(_DWORD *)&label_member.body[4] = 6;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)label.body + 20))(
      *(_DWORD *)label.body,
      *(_DWORD *)&label.body[8],
      "name",
      &label_member,
      (label.body[4] & 0x8F) == 10);
    survarium::text_translator::translate_text(&thisa->m_game->m_text_translator, p_label->m_begin, label_txt);
    v94 = 0;
    v99 = 0;
    v100 = 7;
    v101 = label_txt;
    if ( (label_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label_member.body + 8))(
        *(_DWORD *)label_member.body,
        &label_member,
        *(_DWORD *)&label_member.body[8]);
      v94 = v99;
      *(_DWORD *)label_member.body = 0;
    }
    *(_DWORD *)&label_member.body[4] = 7;
    *(_DWORD *)&label_member.body[8] = label_txt;
    if ( (v100 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v94 + 8))(v94, &v99, v101);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)label.body + 20))(
      *(_DWORD *)label.body,
      *(_DWORD *)&label.body[8],
      "label",
      &label_member,
      (label.body[4] & 0x8F) == 10);
    (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)labels_array.body + 52))(
      *(_DWORD *)labels_array.body,
      *(_DWORD *)&labels_array.body[8],
      v91,
      &label);
    if ( (label_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label_member.body + 8))(
        *(_DWORD *)label_member.body,
        &label_member,
        *(_DWORD *)&label_member.body[8]);
      *(_DWORD *)label_member.body = 0;
    }
    *(_DWORD *)&label_member.body[4] = 0;
    if ( (label.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)label.body + 8))(
        *(_DWORD *)label.body,
        &label,
        *(_DWORD *)&label.body[8]);
    ++v91;
    p_label += 2;
    --v96;
  }
  while ( v96 );
  Scaleform::GFx::Movie::Invoke(
    thisa->m_options_ui.m_object->movie->m_movie,
    "root.set_labels",
    0,
    (const Scaleform::GFx::Value *)&labels_array,
    1u);
  if ( (labels_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)labels_array.body + 8))(
      *(_DWORD *)labels_array.body,
      &labels_array,
      *(_DWORD *)&labels_array.body[8]);
}
