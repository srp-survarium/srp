void __thiscall survarium::options_graphics_quality_selector::scaleform_call(
        survarium::options_graphics_quality_selector *this,
        survarium::flash_function_handler_params *params)
{
  survarium::graphic_preset *v3; // edi
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  int v6; // edx
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  Scaleform::GFx::Value *v10; // esi
  int i; // edi
  survarium::flash_value v12; // [esp+4h] [ebp-64h] BYREF
  _BYTE v13[24]; // [esp+1Ch] [ebp-4Ch] BYREF
  _BYTE v14[24]; // [esp+34h] [ebp-34h] BYREF
  _BYTE v15[24]; // [esp+4Ch] [ebp-1Ch] BYREF
  int v16; // [esp+64h] [ebp-4h] BYREF
  survarium::flash_function_handler_params *paramsa; // [esp+70h] [ebp+8h]

  survarium::options_item_int::scaleform_call(this, params);
  if ( this->m_current_value != this->m_values_count - 1 )
  {
    paramsa = 0;
    v16 = 10;
    do
    {
      v3 = &survarium::g_graphic_presets[0][(int)paramsa + 10 * this->m_current_value];
      v4 = &v12;
      do
      {
        survarium::flash_value::flash_value(v4);
        v4 = v5 + 1;
      }
      while ( v6 - 1 >= 0 );
      survarium::flash_value::SetUInt(v4, (int)&v12, 2u);
      survarium::flash_value::SetUInt(v7, (int)v13, v3->option_id);
      survarium::flash_value::SetUInt(v8, (int)v14, v3->option_value);
      survarium::flash_value::SetUInt(v9, (int)v15, 0);
      Scaleform::GFx::Movie::Invoke(
        this->m_parent_tab->m_movie->m_object->movie->m_movie,
        "root.set_value",
        0,
        (const Scaleform::GFx::Value *)&v12,
        4u);
      v10 = (Scaleform::GFx::Value *)&v16;
      for ( i = 3; i >= 0; --i )
        Scaleform::GFx::Value::~Value(--v10);
      paramsa = (survarium::flash_function_handler_params *)((char *)paramsa + 1);
      --v16;
    }
    while ( v16 );
  }
}
