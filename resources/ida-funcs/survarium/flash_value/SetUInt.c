void __userpurge survarium::flash_value::SetUInt(survarium::flash_value *this@<ecx>, int a2@<esi>, unsigned int value)
{
  if ( (*(_DWORD *)(a2 + 4) & 0x40) != 0 )
    Scaleform::GFx::Value::ReleaseManagedValue((Scaleform::GFx::Value *)a2);
  *(_DWORD *)(a2 + 4) = 4;
  *(_DWORD *)(a2 + 8) = value;
}
