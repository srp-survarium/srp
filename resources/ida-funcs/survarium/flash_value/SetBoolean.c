void __userpurge survarium::flash_value::SetBoolean(survarium::flash_value *this@<ecx>, int a2@<esi>, bool value)
{
  if ( (*(_DWORD *)(a2 + 4) & 0x40) != 0 )
    Scaleform::GFx::Value::ReleaseManagedValue((Scaleform::GFx::Value *)a2);
  *(_DWORD *)(a2 + 4) = 2;
  *(_BYTE *)(a2 + 8) = value;
}
