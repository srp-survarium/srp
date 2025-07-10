BOOL __thiscall Scaleform::GFx::AS3::SlotInfo::IsGetter(Scaleform::GFx::AS3::SlotInfo *this)
{
  int v1; // eax

  v1 = (int)(*(_DWORD *)this << 22) >> 27;
  return v1 == 12 || v1 == 14;
}
