void __usercall survarium::flash_value::SetStringW(survarium::flash_value *this@<esi>, const wchar_t *value@<edi>)
{
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  int v3; // eax
  unsigned int v4; // eax
  Scaleform::GFx::Value vv; // [esp+8h] [ebp-1Ch] BYREF

  pObjectInterface = 0;
  v3 = *(_DWORD *)&this->body[4] >> 6;
  vv.pObjectInterface = 0;
  vv.Type = VT_StringW;
  vv.mValue.IValue = (int)value;
  if ( (v3 & 1) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)this->body + 8))(
      this,
      *(_DWORD *)&this->body[8]);
    pObjectInterface = vv.pObjectInterface;
    *(_DWORD *)this->body = 0;
  }
  v4 = (unsigned int)vv.Type >> 6;
  *(_DWORD *)&this->body[4] = 7;
  *(_DWORD *)&this->body[8] = value;
  if ( (v4 & 1) != 0 )
    pObjectInterface->ObjectRelease(pObjectInterface, &vv, vv.mValue.pStringManaged);
}
