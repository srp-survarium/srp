BOOL __thiscall Scaleform::GFx::AS3::SlotInfo::IsClass(Scaleform::GFx::AS3::SlotInfo *this)
{
  const Scaleform::GFx::AS3::Abc::TraitInfo *TI; // eax
  BOOL result; // eax

  result = 1;
  if ( (*(_DWORD *)this & 0x3E0) != 0x20 )
  {
    TI = this->TI;
    if ( !TI || (TI->kind & 0xF) != 4 )
      return 0;
  }
  return result;
}
