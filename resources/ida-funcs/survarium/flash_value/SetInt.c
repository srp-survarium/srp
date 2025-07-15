void __userpurge survarium::flash_value::SetInt(survarium::flash_value *this@<ecx>, int a2@<esi>, int value)
{
  if ( (*(_DWORD *)(a2 + 4) & 0x40) != 0 )
    Scaleform::GFx::Value::ReleaseManagedValue((Scaleform::GFx::Value *)a2);
  *(_DWORD *)(a2 + 4) = 3;
  *(_DWORD *)(a2 + 8) = value;
}
