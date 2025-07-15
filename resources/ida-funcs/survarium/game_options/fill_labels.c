void __thiscall survarium::game_options::fill_labels(survarium::game_options *this, int a2)
{
  vostok::fixed_string<32> *v2; // ecx
  vostok::fixed_string<32> *v3; // ecx
  vostok::fixed_string<32> *v4; // ecx
  vostok::fixed_string<32> *v5; // ecx
  vostok::fixed_string<32> *v6; // ecx
  vostok::fixed_string<32> *v7; // ecx
  vostok::fixed_string<32> *v8; // ecx
  vostok::fixed_string<32> *v9; // ecx
  vostok::fixed_string<32> *v10; // ecx
  vostok::fixed_string<32> *v11; // ecx
  vostok::fixed_string<32> *v12; // ecx
  vostok::fixed_string<32> *v13; // ecx
  vostok::fixed_string<32> *v14; // ecx
  vostok::fixed_string<32> *v15; // ecx
  vostok::fixed_string<32> *v16; // ecx
  vostok::fixed_string<32> *v17; // ecx
  vostok::fixed_string<32> *v18; // ecx
  vostok::fixed_string<32> *v19; // ecx
  vostok::fixed_string<32> *v20; // ecx
  vostok::fixed_string<32> *v21; // ecx
  vostok::fixed_string<32> *v22; // ecx
  vostok::fixed_string<32> *v23; // ecx
  vostok::fixed_string<32> *v24; // ecx
  vostok::fixed_string<32> *v25; // ecx
  vostok::fixed_string<32> *v26; // ecx
  vostok::fixed_string<32> *v27; // ecx
  vostok::fixed_string<32> *v28; // ecx
  vostok::fixed_string<32> *v29; // ecx
  vostok::fixed_string<32> *v30; // ecx
  vostok::fixed_string<32> *v31; // ecx
  vostok::fixed_string<32> *v32; // ecx
  vostok::fixed_string<32> *v33; // ecx
  vostok::fixed_string<32> *v34; // ecx
  vostok::fixed_string<32> *v35; // ecx
  vostok::fixed_string<32> *v36; // ecx
  vostok::fixed_string<32> *v37; // ecx
  vostok::fixed_string<32> *v38; // ecx
  vostok::fixed_string<32> *v39; // ecx
  vostok::fixed_string<32> *v40; // ecx
  vostok::fixed_string<32> *v41; // ecx
  vostok::fixed_string<32> *v42; // ecx
  vostok::fixed_string<32> *v43; // ecx
  vostok::fixed_string<32> *v44; // ecx
  vostok::fixed_string<32> *v45; // ecx
  vostok::fixed_string<32> *v46; // ecx
  vostok::fixed_string<32> *v47; // ecx
  vostok::fixed_string<32> *v48; // ecx
  vostok::fixed_string<32> *v49; // ecx
  vostok::fixed_string<32> *v50; // ecx
  vostok::fixed_string<32> *v51; // ecx
  vostok::fixed_string<32> *v52; // ecx
  vostok::fixed_string<32> *v53; // ecx
  vostok::fixed_string<32> *v54; // ecx
  vostok::fixed_string<32> *v55; // ecx
  vostok::fixed_string<32> *v56; // ecx
  int v57; // eax
  survarium::flash_movie *v58; // ecx
  vostok::buffer_string *v59; // ebx
  int v60; // eax
  const char *m_end; // edi
  survarium::flash_value *v62; // ecx
  survarium::text_translator *v63; // ecx
  survarium::flash_value *v64; // ecx
  char v65[512]; // [esp+10h] [ebp-BF4h] BYREF
  vostok::buffer_string v66[3]; // [esp+210h] [ebp-9F4h] BYREF
  vostok::buffer_string v67[3]; // [esp+23Ch] [ebp-9C8h] BYREF
  vostok::buffer_string v68[3]; // [esp+268h] [ebp-99Ch] BYREF
  vostok::buffer_string v69[3]; // [esp+294h] [ebp-970h] BYREF
  vostok::buffer_string v70[3]; // [esp+2C0h] [ebp-944h] BYREF
  vostok::buffer_string v71[3]; // [esp+2ECh] [ebp-918h] BYREF
  vostok::buffer_string v72[3]; // [esp+318h] [ebp-8ECh] BYREF
  vostok::buffer_string v73[3]; // [esp+344h] [ebp-8C0h] BYREF
  vostok::buffer_string v74[3]; // [esp+370h] [ebp-894h] BYREF
  vostok::buffer_string v75[3]; // [esp+39Ch] [ebp-868h] BYREF
  vostok::buffer_string v76[3]; // [esp+3C8h] [ebp-83Ch] BYREF
  vostok::buffer_string v77[3]; // [esp+3F4h] [ebp-810h] BYREF
  vostok::buffer_string v78[3]; // [esp+420h] [ebp-7E4h] BYREF
  vostok::buffer_string v79[3]; // [esp+44Ch] [ebp-7B8h] BYREF
  vostok::buffer_string v80[3]; // [esp+478h] [ebp-78Ch] BYREF
  vostok::buffer_string v81[3]; // [esp+4A4h] [ebp-760h] BYREF
  vostok::buffer_string v82[3]; // [esp+4D0h] [ebp-734h] BYREF
  vostok::buffer_string v83[3]; // [esp+4FCh] [ebp-708h] BYREF
  vostok::buffer_string v84[3]; // [esp+528h] [ebp-6DCh] BYREF
  vostok::buffer_string v85[3]; // [esp+554h] [ebp-6B0h] BYREF
  vostok::buffer_string v86[3]; // [esp+580h] [ebp-684h] BYREF
  vostok::buffer_string v87[3]; // [esp+5ACh] [ebp-658h] BYREF
  vostok::buffer_string v88[3]; // [esp+5D8h] [ebp-62Ch] BYREF
  vostok::buffer_string v89[3]; // [esp+604h] [ebp-600h] BYREF
  vostok::buffer_string v90[3]; // [esp+630h] [ebp-5D4h] BYREF
  vostok::buffer_string v91[3]; // [esp+65Ch] [ebp-5A8h] BYREF
  vostok::buffer_string v92[3]; // [esp+688h] [ebp-57Ch] BYREF
  vostok::buffer_string v93[3]; // [esp+6B4h] [ebp-550h] BYREF
  vostok::buffer_string v94[3]; // [esp+6E0h] [ebp-524h] BYREF
  vostok::buffer_string v95[3]; // [esp+70Ch] [ebp-4F8h] BYREF
  vostok::buffer_string v96[3]; // [esp+738h] [ebp-4CCh] BYREF
  vostok::buffer_string v97[3]; // [esp+764h] [ebp-4A0h] BYREF
  vostok::buffer_string v98[3]; // [esp+790h] [ebp-474h] BYREF
  vostok::buffer_string v99[3]; // [esp+7BCh] [ebp-448h] BYREF
  vostok::buffer_string v100[3]; // [esp+7E8h] [ebp-41Ch] BYREF
  vostok::buffer_string v101[3]; // [esp+814h] [ebp-3F0h] BYREF
  vostok::buffer_string v102[3]; // [esp+840h] [ebp-3C4h] BYREF
  vostok::buffer_string v103[3]; // [esp+86Ch] [ebp-398h] BYREF
  vostok::buffer_string v104[3]; // [esp+898h] [ebp-36Ch] BYREF
  vostok::buffer_string v105[3]; // [esp+8C4h] [ebp-340h] BYREF
  vostok::buffer_string v106[3]; // [esp+8F0h] [ebp-314h] BYREF
  vostok::buffer_string v107[3]; // [esp+91Ch] [ebp-2E8h] BYREF
  vostok::buffer_string v108[3]; // [esp+948h] [ebp-2BCh] BYREF
  vostok::buffer_string v109[3]; // [esp+974h] [ebp-290h] BYREF
  vostok::buffer_string v110[3]; // [esp+9A0h] [ebp-264h] BYREF
  vostok::buffer_string v111[3]; // [esp+9CCh] [ebp-238h] BYREF
  vostok::buffer_string v112[3]; // [esp+9F8h] [ebp-20Ch] BYREF
  vostok::buffer_string v113[3]; // [esp+A24h] [ebp-1E0h] BYREF
  vostok::buffer_string v114[3]; // [esp+A50h] [ebp-1B4h] BYREF
  vostok::buffer_string v115[3]; // [esp+A7Ch] [ebp-188h] BYREF
  vostok::buffer_string v116[3]; // [esp+AA8h] [ebp-15Ch] BYREF
  vostok::buffer_string v117[3]; // [esp+AD4h] [ebp-130h] BYREF
  vostok::buffer_string v118[3]; // [esp+B00h] [ebp-104h] BYREF
  vostok::buffer_string v119[3]; // [esp+B2Ch] [ebp-D8h] BYREF
  vostok::buffer_string v120[3]; // [esp+B58h] [ebp-ACh] BYREF
  vostok::buffer_string v121[3]; // [esp+B84h] [ebp-80h] BYREF
  survarium::flash_value value; // [esp+BB0h] [ebp-54h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+BC8h] [ebp-3Ch] BYREF
  Scaleform::GFx::Value v124; // [esp+BE0h] [ebp-24h] BYREF
  int v125; // [esp+BF8h] [ebp-Ch]
  unsigned int v126; // [esp+BFCh] [ebp-8h]

  vostok::fixed_string<32>::fixed_string<32>((vostok::fixed_string<32> *)this, v66, "s_friends");
  vostok::fixed_string<32>::fixed_string<32>(v2, v67, "st_options_friends");
  vostok::fixed_string<32>::fixed_string<32>(v3, v68, "s_cross");
  vostok::fixed_string<32>::fixed_string<32>(v4, v69, "st_options_cross_type");
  vostok::fixed_string<32>::fixed_string<32>(v5, v70, "s_chat");
  vostok::fixed_string<32>::fixed_string<32>(v6, v71, "st_options_chat");
  vostok::fixed_string<32>::fixed_string<32>(v7, v72, "s_lobby");
  vostok::fixed_string<32>::fixed_string<32>(v8, v73, "st_options_lobby");
  vostok::fixed_string<32>::fixed_string<32>(v9, v74, "s_game");
  vostok::fixed_string<32>::fixed_string<32>(v10, v75, "st_options_game");
  vostok::fixed_string<32>::fixed_string<32>(v11, v76, "s_chat_keys");
  vostok::fixed_string<32>::fixed_string<32>(v12, v77, "st_options_chat_keys");
  vostok::fixed_string<32>::fixed_string<32>(v13, v78, "gameplay_options_type");
  vostok::fixed_string<32>::fixed_string<32>(v14, v79, "st_options_gameplay");
  vostok::fixed_string<32>::fixed_string<32>(v15, v80, "controllers_options_type");
  vostok::fixed_string<32>::fixed_string<32>(v16, v81, "st_options_controller");
  vostok::fixed_string<32>::fixed_string<32>(v17, v82, "video_options_type");
  vostok::fixed_string<32>::fixed_string<32>(v18, v83, "st_options_video");
  vostok::fixed_string<32>::fixed_string<32>(v19, v84, "sound_options_type");
  vostok::fixed_string<32>::fixed_string<32>(v20, v85, "st_options_sound");
  vostok::fixed_string<32>::fixed_string<32>(v21, v86, "adjust_gamma");
  vostok::fixed_string<32>::fixed_string<32>(v22, v87, "st_monitor_ajust");
  vostok::fixed_string<32>::fixed_string<32>(v23, v88, "button_default_video");
  vostok::fixed_string<32>::fixed_string<32>(v24, v89, "st_options_default_video");
  vostok::fixed_string<32>::fixed_string<32>(v25, v90, "button_default_controls");
  vostok::fixed_string<32>::fixed_string<32>(v26, v91, "st_options_default_controls");
  vostok::fixed_string<32>::fixed_string<32>(v27, v92, "button_optimal_video");
  vostok::fixed_string<32>::fixed_string<32>(v28, v93, "st_options_optimal_video");
  vostok::fixed_string<32>::fixed_string<32>(v29, v94, "button_ok");
  vostok::fixed_string<32>::fixed_string<32>(v30, v95, "st_options_ok");
  vostok::fixed_string<32>::fixed_string<32>(v31, v96, "button_apply");
  vostok::fixed_string<32>::fixed_string<32>(v32, v97, "st_options_apply");
  vostok::fixed_string<32>::fixed_string<32>(v33, v98, "button_cancel");
  vostok::fixed_string<32>::fixed_string<32>(v34, v99, "st_options_cancel");
  vostok::fixed_string<32>::fixed_string<32>(v35, v100, "apply_changes_msg");
  vostok::fixed_string<32>::fixed_string<32>(v36, v101, "st_apply_changes_msg");
  vostok::fixed_string<32>::fixed_string<32>(v37, v102, "s_voice_chat");
  vostok::fixed_string<32>::fixed_string<32>(v38, v103, "st_options_voice");
  vostok::fixed_string<32>::fixed_string<32>(v39, v104, "s_sound_volume");
  vostok::fixed_string<32>::fixed_string<32>(v40, v105, "st_options_volume");
  vostok::fixed_string<32>::fixed_string<32>(v41, v106, "bind_text");
  vostok::fixed_string<32>::fixed_string<32>(v42, v107, "st_bind_text");
  vostok::fixed_string<32>::fixed_string<32>(v43, v108, "s_minimap");
  vostok::fixed_string<32>::fixed_string<32>(v44, v109, "st_minimap");
  vostok::fixed_string<32>::fixed_string<32>(v45, v110, "exit_game_confirm_text");
  vostok::fixed_string<32>::fixed_string<32>(v46, v111, "st_exit_game_confirm_text");
  vostok::fixed_string<32>::fixed_string<32>(v47, v112, "exit_game_confirm_accept");
  vostok::fixed_string<32>::fixed_string<32>(v48, v113, "st_exit_game_confirm_accept");
  vostok::fixed_string<32>::fixed_string<32>(v49, v114, "exit_game_confirm_cancel");
  vostok::fixed_string<32>::fixed_string<32>(v50, v115, "st_exit_game_confirm_cancel");
  vostok::fixed_string<32>::fixed_string<32>(v51, v116, "exit_match_confirm_text");
  vostok::fixed_string<32>::fixed_string<32>(v52, v117, "st_exit_match_confirm_text");
  vostok::fixed_string<32>::fixed_string<32>(v53, v118, "exit_match_confirm_accept");
  vostok::fixed_string<32>::fixed_string<32>(v54, v119, "st_exit_match_confirm_accept");
  vostok::fixed_string<32>::fixed_string<32>(v55, v120, "exit_match_confirm_cancel");
  vostok::fixed_string<32>::fixed_string<32>(v56, v121, "st_exit_match_confirm_cancel");
  v57 = *(_DWORD *)(a2 + 12);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v57 + 264) + 4), &pvalue);
  v126 = 0;
  v59 = v67;
  v125 = 28;
  do
  {
    v60 = *(_DWORD *)(a2 + 12);
    v124.pObjectInterface = 0;
    v124.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v58, *(survarium::flash_value **)(v60 + 264), &v124);
    m_end = v59[-4].m_end;
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    survarium::flash_value::SetString(&value, m_end);
    survarium::flash_value::SetMember(v62, &v124, "name", &value);
    survarium::text_translator::translate_text(v63, *(_DWORD *)(a2 + 52) + 13944, v59->m_begin, v65);
    survarium::flash_value::SetString(&value, v65);
    survarium::flash_value::SetMember(v64, &v124, "label", &value);
    pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v126, &v124);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    Scaleform::GFx::Value::~Value(&v124);
    ++v126;
    v59 = (vostok::buffer_string *)((char *)v59 + 88);
    --v125;
  }
  while ( v125 );
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
    "root.set_labels",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value(&pvalue);
}
