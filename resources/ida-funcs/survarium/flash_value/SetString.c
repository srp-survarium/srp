void __usercall survarium::flash_value::SetString(survarium::flash_value *this@<esi>, const char *value@<edi>)
{
  int v2; // eax
  Scaleform::GFx::Value v3; // [esp+8h] [ebp-18h] BYREF

  v2 = *(_DWORD *)&this->body[4];
  v3.pObjectInterface = 0;
  v3.Type = VT_String;
  v3.mValue.IValue = (int)value;
  if ( (v2 & 0x40) != 0 )
    Scaleform::GFx::Value::ReleaseManagedValue((Scaleform::GFx::Value *)this);
  *(_DWORD *)&this->body[4] = 6;
  *(_DWORD *)&this->body[8] = value;
  Scaleform::GFx::Value::~Value(&v3);
}
