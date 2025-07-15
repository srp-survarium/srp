void __thiscall survarium::options_item_int::scaleform_call(
        survarium::options_item_int *this,
        survarium::flash_function_handler_params *params)
{
  int v2; // edx
  survarium::options_item_int *v3; // edi
  survarium::options_tab *m_parent_tab; // eax
  unsigned __int8 v5; // al
  survarium::options_item_int_vtbl *m_option_item_id; // esi
  unsigned __int8 v7; // bl
  int v8; // eax
  int v9; // ebx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  int v12; // edx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  Scaleform::GFx::Value *v16; // esi
  unsigned __int8 m_values_count; // al
  survarium::flash_value v18; // [esp+8h] [ebp-60h] BYREF
  _BYTE v19[24]; // [esp+20h] [ebp-48h] BYREF
  _BYTE v20[24]; // [esp+38h] [ebp-30h] BYREF
  _BYTE v21[24]; // [esp+50h] [ebp-18h] BYREF
  char vars0; // [esp+68h] [ebp+0h] BYREF

  v2 = *(_DWORD *)&params->pArgs->body[8];
  v3 = this;
  m_parent_tab = this->m_parent_tab;
  this->m_current_value = v2;
  if ( m_parent_tab->m_type == video_options_type )
  {
    v5 = *(_BYTE *)(*((_DWORD *)m_parent_tab->m_options + 8) + 29);
    if ( v5 < 5u )
    {
      m_option_item_id = (survarium::options_item_int_vtbl *)this->m_option_item_id;
      v7 = 0;
      v8 = v5;
      while ( 1 )
      {
        this = (survarium::options_item_int *)&survarium::g_graphic_presets[v8][v7];
        if ( this->__vftable == m_option_item_id )
        {
          LOBYTE(this) = this->impl;
          if ( v3->m_values_count > (unsigned __int8)this && (_BYTE)v2 != (_BYTE)this )
            break;
        }
        if ( ++v7 >= 0xAu )
          goto LABEL_13;
      }
      v9 = 3;
      v10 = &v18;
      do
      {
        survarium::flash_value::flash_value(v10);
        v10 = v11 + 1;
      }
      while ( v12 - 1 >= 0 );
      survarium::flash_value::SetUInt(v10, (int)&v18, 2u);
      survarium::flash_value::SetUInt(v13, (int)v19, 8u);
      survarium::flash_value::SetUInt(v14, (int)v20, 5u);
      survarium::flash_value::SetUInt(v15, (int)v21, 0);
      Scaleform::GFx::Movie::Invoke(
        v3->m_parent_tab->m_movie->m_object->movie->m_movie,
        "root.set_value",
        0,
        (const Scaleform::GFx::Value *)&v18,
        4u);
      v16 = (Scaleform::GFx::Value *)&vars0;
      do
      {
        Scaleform::GFx::Value::~Value(--v16);
        --v9;
      }
      while ( v9 >= 0 );
    }
  }
LABEL_13:
  m_values_count = v3->m_values_count;
  if ( v3->m_current_value >= m_values_count && m_values_count )
    v3->m_current_value = m_values_count - 1;
  survarium::flash_value::SetUInt((survarium::flash_value *)this, (int)params->pRetVal->body, v3->m_current_value);
}
