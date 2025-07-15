void __thiscall survarium::lobby_menu::add_quest(
        survarium::lobby_menu *this,
        const survarium::quest_instance *quest,
        survarium::flash_value *a3)
{
  const survarium::quest_instance *v3; // edi
  const survarium::quest_descriptor *quest_descriptor; // eax
  const survarium::quest_descriptor *v5; // ebx
  survarium::flash_movie *v6; // ecx
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  vostok::command_line::key *v9; // ecx
  survarium::text_translator *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::text_translator *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  const survarium::quest_instance *v20; // edi
  unsigned int id; // eax
  int v22; // esi
  survarium::flash_movie *v23; // ecx
  int v24; // eax
  int v25; // eax
  bool v26; // zf
  unsigned int v27; // eax
  survarium::flash_value *v28; // ecx
  survarium::flash_value *v29; // ecx
  survarium::flash_value *v30; // ecx
  survarium::flash_value *v31; // ecx
  survarium::flash_value *v32; // ecx
  survarium::flash_value *v33; // ecx
  unsigned int v34; // eax
  survarium::flash_movie *v35; // ecx
  survarium::text_translator *v36; // ecx
  survarium::flash_value *v37; // ecx
  survarium::flash_value *v38; // ecx
  survarium::flash_value *v39; // ecx
  unsigned int v40; // [esp-4h] [ebp-2ACh]
  unsigned int v41; // [esp-4h] [ebp-2ACh]
  char v42[512]; // [esp+10h] [ebp-298h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+210h] [ebp-98h] BYREF
  Scaleform::GFx::Value v44; // [esp+228h] [ebp-80h] BYREF
  Scaleform::GFx::Value v45; // [esp+240h] [ebp-68h] BYREF
  Scaleform::GFx::Value pargs; // [esp+258h] [ebp-50h] BYREF
  survarium::flash_value v47; // [esp+270h] [ebp-38h] BYREF
  survarium::flash_value value; // [esp+288h] [ebp-20h] BYREF
  unsigned int *v49; // [esp+2A0h] [ebp-8h]
  unsigned __int8 i; // [esp+2A7h] [ebp-1h]

  v3 = quest;
  quest_descriptor = survarium::items_dictionary::get_quest_descriptor(
                       *(survarium::items_dictionary **)(quest[8].id + 13908),
                       *(_DWORD *)&a3->body[4]);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  v5 = quest_descriptor;
  survarium::flash_movie::CreateObject(v6, *(survarium::flash_value **)(quest[80].id + 264), &pargs);
  v40 = *(_DWORD *)a3->body;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_value::SetUInt(v7, (int)&value, v40);
  survarium::flash_value::SetMember(v8, &pargs, "id", &value);
  if ( vostok::command_line::key::is_set(v9, (int)&s_debug_quests) )
  {
    sprintf_s<16>((char (*)[16])&v47.body[8], "%d/%d", *(_DWORD *)a3->body, *(_DWORD *)&a3->body[4]);
    survarium::flash_value::SetString(&value, &v47.body[8]);
    survarium::flash_value::SetMember(v11, &pargs, "dict_id", &value);
    v3 = quest;
  }
  survarium::text_translator::translate_text(v10, v3[8].id + 13944, (char *)v5->description, v42);
  survarium::flash_value::SetString(&value, v42);
  survarium::flash_value::SetMember(v12, &pargs, "text", &value);
  survarium::text_translator::translate_text(v13, quest[8].id + 13944, (char *)v5->name, v42);
  survarium::flash_value::SetString(&value, v42);
  survarium::flash_value::SetMember(v14, &pargs, "quest_label", &value);
  survarium::flash_value::SetUInt(v15, (int)&value, v5->faction);
  survarium::flash_value::SetMember(v16, &pargs, "faction_id", &value);
  survarium::flash_value::SetUInt(v17, (int)&value, v5->icon);
  survarium::flash_value::SetMember(v18, &pargs, "quest_icon", &value);
  survarium::flash_value::SetUInt(a3, (int)&value, a3->body[16] != 1);
  survarium::flash_value::SetMember(v19, &pargs, "status", &value);
  v20 = quest;
  id = quest[80].id;
  v22 = 0;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(id + 264) + 4), &pvalue);
  i = 0;
  if ( v5->awards_count )
  {
    v24 = 0;
    do
    {
      v25 = (int)&v5->awards[v24];
      v26 = *(_DWORD *)(v25 + 8) == 4;
      v49 = (unsigned int *)v25;
      if ( !v26 )
      {
        v27 = quest[80].id;
        v45.pObjectInterface = 0;
        v45.Type = VT_Undefined;
        survarium::flash_movie::CreateObject(v23, *(survarium::flash_value **)(v27 + 264), &v45);
        v41 = v49[2];
        *(_DWORD *)v47.body = 0;
        *(_DWORD *)&v47.body[4] = 0;
        survarium::flash_value::SetUInt(v28, (int)&v47, v41);
        survarium::flash_value::SetMember(v29, &v45, "type", &v47);
        survarium::flash_value::SetUInt(v30, (int)&v47, v49[1]);
        survarium::flash_value::SetMember(v31, &v45, "param", &v47);
        survarium::flash_value::SetUInt(v32, (int)&v47, *v49);
        survarium::flash_value::SetMember(v33, &v45, "amount", &v47);
        pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v45);
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v47);
        Scaleform::GFx::Value::~Value(&v45);
        v22 = 0;
      }
      v24 = ++i;
    }
    while ( i < v5->awards_count );
  }
  survarium::flash_value::SetMember((survarium::flash_value *)v23, &pargs, "reward", (survarium::flash_value *)&pvalue);
  v34 = quest[80].id;
  v44.pObjectInterface = 0;
  v44.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v34 + 264) + 4), &v44);
  for ( i = 0; i < v5->task_descriptions_count; v20 = quest )
  {
    v45.pObjectInterface = 0;
    v45.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v35, *(survarium::flash_value **)(v20[80].id + 264), &v45);
    *(_DWORD *)v47.body = 0;
    *(_DWORD *)&v47.body[4] = 0;
    survarium::text_translator::translate_text(v36, v20[8].id + 13944, (char *)v5->task_descriptions[v22], v42);
    survarium::flash_value::SetString(&v47, v42);
    survarium::flash_value::SetMember(v37, &v45, "text", &v47);
    v44.pObjectInterface->PushBack(v44.pObjectInterface, (void *)v44.mValue.IValue, &v45);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v47);
    Scaleform::GFx::Value::~Value(&v45);
    v22 = ++i;
  }
  survarium::flash_value::SetMember((survarium::flash_value *)v35, &pargs, "tasks", (survarium::flash_value *)&v44);
  survarium::flash_value::SetInt(v38, (int)&value, *(_DWORD *)&a3->body[12]);
  survarium::flash_value::SetMember(v39, &pargs, "time_limit", &value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v20[80].id + 264) + 4),
    "root.add_quest",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&v44);
  Scaleform::GFx::Value::~Value(&pvalue);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
}
