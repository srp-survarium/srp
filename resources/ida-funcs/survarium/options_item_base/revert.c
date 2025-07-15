void __thiscall survarium::options_item_base::revert(survarium::options_item_base *this)
{
  survarium::flash_value *v2; // ecx
  survarium::flash_value *v3; // ecx
  int v4; // edx
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  Scaleform::GFx::Value *v7; // esi
  int i; // edi
  survarium::flash_value v9; // [esp+8h] [ebp-60h] BYREF
  _BYTE v10[24]; // [esp+20h] [ebp-48h] BYREF
  _BYTE v11[24]; // [esp+38h] [ebp-30h] BYREF
  _BYTE v12[24]; // [esp+50h] [ebp-18h] BYREF
  char vars0; // [esp+68h] [ebp+0h] BYREF

  v2 = &v9;
  do
  {
    survarium::flash_value::flash_value(v2);
    v2 = v3 + 1;
  }
  while ( v4 - 1 >= 0 );
  survarium::flash_value::SetUInt(v2, (int)&v9, this->m_parent_tab->m_type);
  survarium::flash_value::SetUInt(v5, (int)v10, this->m_option_item_id);
  this->fill_value(this, (survarium::flash_value *)v11);
  survarium::flash_value::SetUInt(v6, (int)v12, 1u);
  Scaleform::GFx::Movie::Invoke(
    this->m_parent_tab->m_movie->m_object->movie->m_movie,
    "root.set_value",
    0,
    (const Scaleform::GFx::Value *)&v9,
    4u);
  v7 = (Scaleform::GFx::Value *)&vars0;
  for ( i = 3; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v7);
}
