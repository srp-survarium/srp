void __usercall survarium::lobby_menu::fill_skills_tree(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // ecx
  vostok::configs::binary_config_value *v4; // ebx
  unsigned __int8 pointer; // al
  int v6; // edx
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  const char **v9; // eax
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  const char **v13; // eax
  Scaleform::GFx::Value::ObjectInterface *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  vostok::configs::binary_config_value *v16; // eax
  const void *v17; // edi
  vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  int v20; // ecx
  vostok::configs::binary_config_value *v21; // edi
  Scaleform::GFx::Movie *v22; // ecx
  Scaleform::GFx::Value::ObjectInterface *v23; // ecx
  bool v24; // bl
  vostok::configs::binary_config_value *v25; // ebx
  const vostok::configs::binary_config_value *v26; // eax
  int v27; // ecx
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  const vostok::configs::binary_config_value *v30; // eax
  vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  const char **v33; // eax
  Scaleform::GFx::Value::ObjectInterface *v34; // ecx
  Scaleform::GFx::Value::ObjectInterface *v35; // ecx
  vostok::configs::binary_config_value *v36; // eax
  vostok::configs::binary_config_value *v37; // eax
  void *v38; // edi
  vostok::configs::binary_config_value *v39; // ebx
  const vostok::configs::binary_config_value *v40; // eax
  int v41; // ecx
  const void *v42; // ebx
  vostok::configs::binary_config_value *v43; // eax
  vostok::configs::binary_config_value *v44; // eax
  const char **v45; // eax
  vostok::configs::binary_config_value *v46; // eax
  vostok::configs::binary_config_value *v47; // eax
  const char **v48; // eax
  int v49; // ecx
  int v50; // ecx
  int v51; // edi
  Scaleform::GFx::Value v52; // [esp+1E0h] [ebp-1184h] BYREF
  Scaleform::GFx::Value v53; // [esp+1FCh] [ebp-1168h] BYREF
  unsigned int v54; // [esp+214h] [ebp-1150h]
  unsigned __int8 v55; // [esp+21Bh] [ebp-1149h]
  vostok::configs::binary_config_value *v56; // [esp+21Ch] [ebp-1148h]
  Scaleform::GFx::Value v57; // [esp+220h] [ebp-1144h] BYREF
  unsigned int v58; // [esp+238h] [ebp-112Ch]
  int v59; // [esp+23Ch] [ebp-1128h]
  int v60; // [esp+240h] [ebp-1124h] BYREF
  int v61; // [esp+244h] [ebp-1120h]
  void *v62; // [esp+248h] [ebp-111Ch]
  Scaleform::GFx::Value v63; // [esp+258h] [ebp-110Ch] BYREF
  Scaleform::GFx::Value pvalue; // [esp+270h] [ebp-10F4h] BYREF
  int v65; // [esp+288h] [ebp-10DCh]
  int v66; // [esp+28Ch] [ebp-10D8h]
  Scaleform::GFx::Value v67; // [esp+290h] [ebp-10D4h] BYREF
  float v68; // [esp+2A8h] [ebp-10BCh]
  int v69; // [esp+2ACh] [ebp-10B8h]
  char v70[32]; // [esp+2B0h] [ebp-10B4h] BYREF
  vostok::configs::binary_config_value *v71; // [esp+2D4h] [ebp-1090h]
  unsigned int v72; // [esp+2D8h] [ebp-108Ch]
  vostok::configs::binary_config_value *v73; // [esp+2DCh] [ebp-1088h]
  char v74[32]; // [esp+2E0h] [ebp-1084h] BYREF
  char key[32]; // [esp+300h] [ebp-1064h] BYREF
  char _Dest[32]; // [esp+320h] [ebp-1044h] BYREF
  char v77[32]; // [esp+340h] [ebp-1024h] BYREF
  wchar_t v78[512]; // [esp+360h] [ebp-1004h] BYREF
  wchar_t translated_text[512]; // [esp+760h] [ebp-C04h] BYREF
  wchar_t v80[512]; // [esp+B60h] [ebp-804h] BYREF
  wchar_t v81[514]; // [esp+F60h] [ebp-404h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 168) + 948);
  v71 = *(vostok::configs::binary_config_value **)(*(_DWORD *)(v2 + 2140) + 264);
  v56 = *(vostok::configs::binary_config_value **)(*(_DWORD *)(v3 + 264) + 264);
  v53.pObjectInterface = 0;
  v53.Type = VT_Undefined;
  v65 = 1;
  v69 = 5;
  do
  {
    sprintf_s<32>((char (*)[32])_Dest, "skill_%d", v65);
    v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v71, _Dest);
    v73 = v4;
    pointer = (unsigned __int8)vostok::configs::binary_config_value::operator[](v4, "id")->data.pointer;
    v6 = *(_DWORD *)(a2 + 212);
    pvalue.pObjectInterface = 0;
    pvalue.Type = VT_Undefined;
    v55 = pointer;
    Scaleform::GFx::Movie::CreateObject(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v6 + 264) + 4), &pvalue, 0, 0, 0);
    v59 = v55;
    sprintf_s<32>((char (*)[32])key, "skill_%d", v55);
    v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v56, "skills_dict");
    v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v7, key);
    v9 = (const char **)vostok::configs::binary_config_value::operator[](v8, "skill_name");
    survarium::text_translator::translate_text(
      (survarium::text_translator *)(*(_DWORD *)(a2 + 168) + 988),
      *v9,
      translated_text);
    pObjectInterface = 0;
    v52.pObjectInterface = 0;
    v52.Type = VT_StringW;
    v52.mValue.IValue = (int)translated_text;
    if ( (v53.Type & 0x40) != 0 )
    {
      v53.pObjectInterface->ObjectRelease(v53.pObjectInterface, &v53, (void *)v53.mValue.IValue);
      pObjectInterface = v52.pObjectInterface;
      v53.pObjectInterface = 0;
    }
    v53.Type = VT_StringW;
    v53.mValue.IValue = (int)translated_text;
    if ( (v52.Type & 0x40) != 0 )
      pObjectInterface->ObjectRelease(pObjectInterface, &v52, v52.mValue.pStringManaged);
    pvalue.pObjectInterface->SetMember(
      pvalue.pObjectInterface,
      (void *)pvalue.mValue.IValue,
      "name",
      &v53,
      (pvalue.Type & 0x8F) == 10);
    v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v56, "skills_dict");
    v12 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v11, key);
    v13 = (const char **)vostok::configs::binary_config_value::operator[](v12, "skill_description");
    survarium::text_translator::translate_text((survarium::text_translator *)(*(_DWORD *)(a2 + 168) + 988), *v13, v80);
    v14 = 0;
    v52.pObjectInterface = 0;
    v52.Type = VT_StringW;
    v52.mValue.IValue = (int)v80;
    if ( (v53.Type & 0x40) != 0 )
    {
      v53.pObjectInterface->ObjectRelease(v53.pObjectInterface, &v53, (void *)v53.mValue.IValue);
      v14 = v52.pObjectInterface;
      v53.pObjectInterface = 0;
    }
    v53.Type = VT_StringW;
    v53.mValue.IValue = (int)v80;
    if ( (v52.Type & 0x40) != 0 )
      v14->ObjectRelease(v14, &v52, v52.mValue.pStringManaged);
    pvalue.pObjectInterface->SetMember(
      pvalue.pObjectInterface,
      (void *)pvalue.mValue.IValue,
      "description",
      &v53,
      (pvalue.Type & 0x8F) == 10);
    v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v56, "skills_dict");
    v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v15, key);
    v17 = vostok::configs::binary_config_value::operator[](v16, "skill_icon")->data.pointer;
    if ( (v53.Type & 0x40) != 0 )
    {
      v53.pObjectInterface->ObjectRelease(v53.pObjectInterface, &v53, (void *)v53.mValue.IValue);
      v53.pObjectInterface = 0;
    }
    v53.Type = VT_UInt;
    v53.mValue.IValue = (int)v17;
    pvalue.pObjectInterface->SetMember(
      pvalue.pObjectInterface,
      (void *)pvalue.mValue.IValue,
      (const char *)&stru_9555EC,
      &v53,
      (pvalue.Type & 0x8F) == 10);
    if ( (v53.Type & 0x40) != 0 )
    {
      v53.pObjectInterface->ObjectRelease(v53.pObjectInterface, &v53, (void *)v53.mValue.IValue);
      v53.pObjectInterface = 0;
    }
    v53.mValue.IValue = v59;
    v53.Type = VT_UInt;
    pvalue.pObjectInterface->SetMember(
      pvalue.pObjectInterface,
      (void *)pvalue.mValue.IValue,
      "id",
      &v53,
      (pvalue.Type & 0x8F) == 10);
    if ( (v53.Type & 0x40) != 0 )
    {
      v53.pObjectInterface->ObjectRelease(v53.pObjectInterface, &v53, (void *)v53.mValue.IValue);
      v53.pObjectInterface = 0;
    }
    v53.Type = VT_UInt;
    v53.mValue.IValue = 0;
    pvalue.pObjectInterface->SetMember(
      pvalue.pObjectInterface,
      (void *)pvalue.mValue.IValue,
      "opened",
      &v53,
      (pvalue.Type & 0x8F) == 10);
    Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 212) + 264) + 4), &v53);
    v63.pObjectInterface = 0;
    v63.Type = VT_Undefined;
    v72 = 24 * vostok::configs::binary_config_value::operator[](v4, "levels")->count / 24;
    v59 = 1;
    if ( v72 )
    {
      while ( 1 )
      {
        sprintf_s<32>((char (*)[32])v77, "skill_level_%d", v59);
        v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v4, "levels");
        v19 = vostok::configs::binary_config_value::operator[](v18, v77);
        v20 = *(_DWORD *)(a2 + 212);
        v21 = (vostok::configs::binary_config_value *)v19;
        v67.pObjectInterface = 0;
        v67.Type = VT_Undefined;
        v22 = *(Scaleform::GFx::Movie **)(*(_DWORD *)(v20 + 264) + 4);
        v66 = (int)v19;
        Scaleform::GFx::Movie::CreateObject(v22, &v67, 0, 0, 0);
        v23 = 0;
        v52.pObjectInterface = 0;
        v52.Type = VT_StringW;
        v52.mValue.IValue = (int)translated_text;
        if ( (v63.Type & 0x40) != 0 )
        {
          v63.pObjectInterface->ObjectRelease(v63.pObjectInterface, &v63, (void *)v63.mValue.IValue);
          v23 = v52.pObjectInterface;
          v63.pObjectInterface = 0;
        }
        v63.Type = VT_StringW;
        v63.mValue.IValue = (int)translated_text;
        if ( (v52.Type & 0x40) != 0 )
          v23->ObjectRelease(v23, &v52, v52.mValue.pStringManaged);
        v67.pObjectInterface->SetMember(
          v67.pObjectInterface,
          (void *)v67.mValue.IValue,
          "name",
          &v63,
          (v67.Type & 0x8F) == 10);
        v24 = vostok::configs::binary_config_value::value_exists(v21, "perks");
        if ( (v63.Type & 0x40) != 0 )
        {
          v63.pObjectInterface->ObjectRelease(v63.pObjectInterface, &v63, (void *)v63.mValue.IValue);
          v63.pObjectInterface = 0;
        }
        v63.mValue.IValue = v24;
        v63.Type = VT_UInt;
        v67.pObjectInterface->SetMember(
          v67.pObjectInterface,
          (void *)v67.mValue.IValue,
          "power",
          &v63,
          (v67.Type & 0x8F) == 10);
        Scaleform::GFx::Movie::CreateArray(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 212) + 264) + 4),
          &v63);
        v25 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v21, "boosters")->data.pointer;
        v26 = vostok::configs::binary_config_value::operator[](v21, "boosters");
        v58 = (unsigned int)v26->data.pointer + 24 * v26->count;
        v60 = 0;
        v61 = 0;
        v54 = 0;
        if ( v25 != (vostok::configs::binary_config_value *)v58 )
        {
          do
          {
            v27 = *(_DWORD *)(a2 + 212);
            v57.pObjectInterface = 0;
            v57.Type = VT_Undefined;
            Scaleform::GFx::Movie::CreateObject(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v27 + 264) + 4), &v57, 0, 0, 0);
            v28 = vostok::configs::binary_config_value::operator[](v25, (char *)&stru_955964);
            if ( v28->type == 2 )
              v29 = *(float *)&v28->data.pointer;
            else
              v29 = (float)(int)v28->data.pointer;
            v68 = v29;
            v30 = vostok::configs::binary_config_value::operator[](v25, "id");
            sprintf_s<32>((char (*)[32])v74, "booster_%d", v30->data.pointer);
            v31 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v56,
                                                            "boosters_dict");
            v32 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v31, v74);
            v33 = (const char **)vostok::configs::binary_config_value::operator[](v32, "booster_name");
            survarium::text_translator::translate_text(
              (survarium::text_translator *)(*(_DWORD *)(a2 + 168) + 988),
              *v33,
              v78);
            sprintf_s<32>((char (*)[32])v70, (const char *)&stru_95AF78.m_key_bindings[63].m_keyboard[1], v68);
            v34 = 0;
            v52.pObjectInterface = 0;
            v52.Type = VT_String;
            v52.mValue.IValue = (int)v70;
            if ( (v61 & 0x40) != 0 )
            {
              (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v60 + 8))(v60, &v60, v62);
              v34 = v52.pObjectInterface;
              v60 = 0;
            }
            v61 = 6;
            v62 = v70;
            if ( (v52.Type & 0x40) != 0 )
              v34->ObjectRelease(v34, &v52, v52.mValue.pStringManaged);
            v57.pObjectInterface->SetMember(
              v57.pObjectInterface,
              (void *)v57.mValue.IValue,
              "prop_value",
              (const Scaleform::GFx::Value *)&v60,
              (v57.Type & 0x8F) == 10);
            v35 = 0;
            v52.pObjectInterface = 0;
            v52.Type = VT_StringW;
            v52.mValue.IValue = (int)v78;
            if ( (v61 & 0x40) != 0 )
            {
              (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v60 + 8))(v60, &v60, v62);
              v35 = v52.pObjectInterface;
              v60 = 0;
            }
            v61 = 7;
            v62 = v78;
            if ( (v52.Type & 0x40) != 0 )
              v35->ObjectRelease(v35, &v52, v52.mValue.pStringManaged);
            v57.pObjectInterface->SetMember(
              v57.pObjectInterface,
              (void *)v57.mValue.IValue,
              "prop_name",
              (const Scaleform::GFx::Value *)&v60,
              (v57.Type & 0x8F) == 10);
            v36 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v56,
                                                            "boosters_dict");
            v37 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v36, v74);
            v38 = (void *)vostok::configs::binary_config_value::operator[](v37, "booster_icon")->data.pointer;
            if ( (v61 & 0x40) != 0 )
            {
              (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v60 + 8))(v60, &v60, v62);
              v60 = 0;
            }
            v61 = 4;
            v62 = v38;
            v57.pObjectInterface->SetMember(
              v57.pObjectInterface,
              (void *)v57.mValue.IValue,
              "prop_icon",
              (const Scaleform::GFx::Value *)&v60,
              (v57.Type & 0x8F) == 10);
            v63.pObjectInterface->SetElement(v63.pObjectInterface, (void *)v63.mValue.IValue, v54, &v57);
            if ( (v57.Type & 0x40) != 0 )
              v57.pObjectInterface->ObjectRelease(v57.pObjectInterface, &v57, (void *)v57.mValue.IValue);
            ++v54;
            ++v25;
          }
          while ( v25 != (vostok::configs::binary_config_value *)v58 );
          v21 = (vostok::configs::binary_config_value *)v66;
        }
        v67.pObjectInterface->SetMember(
          v67.pObjectInterface,
          (void *)v67.mValue.IValue,
          "properties",
          &v63,
          (v67.Type & 0x8F) == 10);
        if ( vostok::configs::binary_config_value::value_exists(v21, "perks") )
        {
          Scaleform::GFx::Movie::CreateArray(
            *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 212) + 264) + 4),
            &v63);
          v39 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v21, "perks")->data.pointer;
          v54 = (unsigned int)v39;
          v40 = vostok::configs::binary_config_value::operator[](v21, "perks");
          v66 = (int)v40->data.pointer + 24 * v40->count;
          v57.pObjectInterface = 0;
          v57.Type = VT_Undefined;
          v58 = 0;
          if ( v39 != (vostok::configs::binary_config_value *)v66 )
          {
            while ( 1 )
            {
              v41 = *(_DWORD *)(a2 + 212);
              v52.pObjectInterface = 0;
              v52.Type = VT_Undefined;
              Scaleform::GFx::Movie::CreateObject(
                *(Scaleform::GFx::Movie **)(*(_DWORD *)(v41 + 264) + 4),
                &v52,
                0,
                0,
                0);
              v42 = vostok::configs::binary_config_value::operator[](v39, "id")->data.pointer;
              sprintf_s<32>((char (*)[32])v74, "perk_%d", v42);
              v43 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v56,
                                                              "perks_dict");
              v44 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v43, v74);
              v45 = (const char **)vostok::configs::binary_config_value::operator[](v44, "name");
              survarium::text_translator::translate_text(
                (survarium::text_translator *)(*(_DWORD *)(a2 + 168) + 988),
                *v45,
                v78);
              v46 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v56,
                                                              "perks_dict");
              v47 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v46, v74);
              v48 = (const char **)vostok::configs::binary_config_value::operator[](v47, "description");
              survarium::text_translator::translate_text(
                (survarium::text_translator *)(*(_DWORD *)(a2 + 168) + 988),
                *v48,
                v81);
              v49 = 0;
              *(_DWORD *)v70 = 0;
              *(_DWORD *)&v70[4] = 7;
              *(_DWORD *)&v70[8] = v78;
              if ( (v57.Type & 0x40) != 0 )
              {
                v57.pObjectInterface->ObjectRelease(v57.pObjectInterface, &v57, (void *)v57.mValue.IValue);
                v49 = *(_DWORD *)v70;
                v57.pObjectInterface = 0;
              }
              v57.Type = VT_StringW;
              v57.mValue.IValue = (int)v78;
              if ( (v70[4] & 0x40) != 0 )
                (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v49 + 8))(v49, v70, *(_DWORD *)&v70[8]);
              v52.pObjectInterface->SetMember(
                v52.pObjectInterface,
                (void *)v52.mValue.IValue,
                "name",
                &v57,
                (v52.Type & 0x8F) == 10);
              v50 = 0;
              *(_DWORD *)v70 = 0;
              *(_DWORD *)&v70[4] = 7;
              *(_DWORD *)&v70[8] = v81;
              if ( (v57.Type & 0x40) != 0 )
              {
                v57.pObjectInterface->ObjectRelease(v57.pObjectInterface, &v57, (void *)v57.mValue.IValue);
                v50 = *(_DWORD *)v70;
                v57.pObjectInterface = 0;
              }
              v57.Type = VT_StringW;
              v57.mValue.IValue = (int)v81;
              if ( (v70[4] & 0x40) != 0 )
                (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v50 + 8))(v50, v70, *(_DWORD *)&v70[8]);
              v52.pObjectInterface->SetMember(
                v52.pObjectInterface,
                (void *)v52.mValue.IValue,
                "item_description",
                &v57,
                (v52.Type & 0x8F) == 10);
              if ( (v57.Type & 0x40) != 0 )
              {
                v57.pObjectInterface->ObjectRelease(v57.pObjectInterface, &v57, (void *)v57.mValue.IValue);
                v57.pObjectInterface = 0;
              }
              v57.Type = VT_UInt;
              v57.mValue.IValue = (int)v42;
              v52.pObjectInterface->SetMember(
                v52.pObjectInterface,
                (void *)v52.mValue.IValue,
                "id",
                &v57,
                (v52.Type & 0x8F) == 10);
              v63.pObjectInterface->SetElement(v63.pObjectInterface, (void *)v63.mValue.IValue, v58, &v52);
              if ( (v52.Type & 0x40) != 0 )
                v52.pObjectInterface->ObjectRelease(v52.pObjectInterface, &v52, (void *)v52.mValue.IValue);
              ++v58;
              v54 += 24;
              if ( v54 == v66 )
                break;
              v39 = (vostok::configs::binary_config_value *)v54;
            }
          }
          v67.pObjectInterface->SetMember(
            v67.pObjectInterface,
            (void *)v67.mValue.IValue,
            "perks",
            &v63,
            (v67.Type & 0x8F) == 10);
          if ( (v57.Type & 0x40) != 0 )
            v57.pObjectInterface->ObjectRelease(v57.pObjectInterface, &v57, (void *)v57.mValue.IValue);
        }
        v51 = v59;
        v53.pObjectInterface->SetElement(v53.pObjectInterface, (void *)v53.mValue.IValue, v59 - 1, &v67);
        if ( (v61 & 0x40) != 0 )
        {
          (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v60 + 8))(v60, &v60, v62);
          v60 = 0;
        }
        v61 = 0;
        if ( (v67.Type & 0x40) != 0 )
          v67.pObjectInterface->ObjectRelease(v67.pObjectInterface, &v67, (void *)v67.mValue.IValue);
        v59 = v51 + 1;
        if ( v51 + 1 > v72 )
          break;
        v4 = v73;
      }
    }
    pvalue.pObjectInterface->SetMember(
      pvalue.pObjectInterface,
      (void *)pvalue.mValue.IValue,
      "slots",
      &v53,
      (pvalue.Type & 0x8F) == 10);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 212) + 264) + 4),
      "root.create_perk_tree",
      0,
      &pvalue,
      1u);
    if ( (v63.Type & 0x40) != 0 )
    {
      v63.pObjectInterface->ObjectRelease(v63.pObjectInterface, &v63, (void *)v63.mValue.IValue);
      v63.pObjectInterface = 0;
    }
    v63.Type = VT_Undefined;
    if ( (pvalue.Type & 0x40) != 0 )
      pvalue.pObjectInterface->ObjectRelease(pvalue.pObjectInterface, &pvalue, (void *)pvalue.mValue.IValue);
    ++v65;
    --v69;
  }
  while ( v69 );
  if ( (v53.Type & 0x40) != 0 )
    v53.pObjectInterface->ObjectRelease(v53.pObjectInterface, &v53, (void *)v53.mValue.IValue);
}
