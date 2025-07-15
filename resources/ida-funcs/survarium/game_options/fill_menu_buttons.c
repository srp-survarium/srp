void __thiscall survarium::game_options::fill_menu_buttons(survarium::game_options *this, int in_game_world, char a3)
{
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
  int v16; // eax
  survarium::flash_movie *v17; // ecx
  vostok::buffer_string *v18; // ebx
  unsigned __int8 v19; // al
  int v20; // eax
  const char *m_max_end; // edi
  survarium::flash_value *v22; // ecx
  survarium::text_translator *v23; // ecx
  survarium::flash_value *v24; // ecx
  char v25[512]; // [esp+10h] [ebp-4B8h] BYREF
  vostok::buffer_string v26[3]; // [esp+210h] [ebp-2B8h] BYREF
  vostok::buffer_string v27[3]; // [esp+23Ch] [ebp-28Ch] BYREF
  vostok::buffer_string v28[3]; // [esp+268h] [ebp-260h] BYREF
  vostok::buffer_string v29[3]; // [esp+294h] [ebp-234h] BYREF
  vostok::buffer_string v30[3]; // [esp+2C0h] [ebp-208h] BYREF
  vostok::buffer_string v31[3]; // [esp+2ECh] [ebp-1DCh] BYREF
  vostok::buffer_string v32[3]; // [esp+318h] [ebp-1B0h] BYREF
  vostok::buffer_string v33[3]; // [esp+344h] [ebp-184h] BYREF
  vostok::buffer_string v34[3]; // [esp+370h] [ebp-158h] BYREF
  vostok::buffer_string v35[3]; // [esp+39Ch] [ebp-12Ch] BYREF
  vostok::buffer_string v36[3]; // [esp+3C8h] [ebp-100h] BYREF
  vostok::buffer_string v37[3]; // [esp+3F4h] [ebp-D4h] BYREF
  vostok::buffer_string v38[3]; // [esp+420h] [ebp-A8h] BYREF
  vostok::buffer_string v39[4]; // [esp+44Ch] [ebp-7Ch] BYREF
  survarium::flash_value value; // [esp+47Ch] [ebp-4Ch] BYREF
  Scaleform::GFx::Value v41; // [esp+494h] [ebp-34h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+4ACh] [ebp-1Ch] BYREF
  int v43; // [esp+4C4h] [ebp-4h]
  unsigned int v44; // [esp+4D4h] [ebp+Ch]

  vostok::fixed_string<32>::fixed_string<32>((vostok::fixed_string<32> *)this, v26, "st_mm_button_back");
  vostok::fixed_string<32>::fixed_string<32>(v3, v27, "back");
  vostok::fixed_string<32>::fixed_string<32>(v4, v28, "st_mm_button_settings");
  vostok::fixed_string<32>::fixed_string<32>(v5, v29, "settings");
  vostok::fixed_string<32>::fixed_string<32>(v6, v30, "st_mm_button_leave_match");
  vostok::fixed_string<32>::fixed_string<32>(v7, v31, "leave_match");
  vostok::fixed_string<32>::fixed_string<32>(v8, v32, "st_mm_button_exit_to_os");
  vostok::fixed_string<32>::fixed_string<32>(v9, v33, "exit_to_os");
  vostok::fixed_string<32>::fixed_string<32>(v10, v34, "st_mm_button_back");
  vostok::fixed_string<32>::fixed_string<32>(v11, v35, "back");
  vostok::fixed_string<32>::fixed_string<32>(v12, v36, "st_mm_button_settings");
  vostok::fixed_string<32>::fixed_string<32>(v13, v37, "settings");
  vostok::fixed_string<32>::fixed_string<32>(v14, v38, "st_mm_button_exit_to_os");
  vostok::fixed_string<32>::fixed_string<32>(v15, v39, "exit_to_os");
  v16 = *(_DWORD *)(in_game_world + 12);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v16 + 264) + 4), &pvalue);
  if ( a3 )
  {
    v18 = v26;
    v19 = 4;
  }
  else
  {
    v18 = v34;
    v19 = 3;
  }
  v44 = 0;
  v43 = v19;
  do
  {
    v20 = *(_DWORD *)(in_game_world + 12);
    v41.pObjectInterface = 0;
    v41.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v17, *(survarium::flash_value **)(v20 + 264), &v41);
    m_max_end = v18[3].m_max_end;
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    survarium::flash_value::SetString(&value, m_max_end);
    survarium::flash_value::SetMember(v22, &v41, "action", &value);
    survarium::text_translator::translate_text(v23, *(_DWORD *)(in_game_world + 52) + 13944, v18->m_begin, v25);
    survarium::flash_value::SetString(&value, v25);
    survarium::flash_value::SetMember(v24, &v41, "label", &value);
    pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v44, &v41);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    Scaleform::GFx::Value::~Value(&v41);
    ++v44;
    v18 = (vostok::buffer_string *)((char *)v18 + 88);
    --v43;
  }
  while ( v43 );
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(in_game_world + 12) + 264) + 4),
    "root.set_options",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value(&pvalue);
}
