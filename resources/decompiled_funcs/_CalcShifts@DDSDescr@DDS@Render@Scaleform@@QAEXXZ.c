void __thiscall Scaleform::Render::DDS::DDSDescr::CalcShifts(Scaleform::Render::DDS::DDSDescr *this)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  unsigned int BBitMask; // [esp-Ch] [ebp-10h]
  unsigned int GBitMask; // [esp-8h] [ebp-Ch]

  v2 = Scaleform::Render::DDS::DDSDescr::CalcShiftByMask(this->RBitMask);
  GBitMask = this->GBitMask;
  this->ShiftR = v2;
  v3 = Scaleform::Render::DDS::DDSDescr::CalcShiftByMask(GBitMask);
  BBitMask = this->BBitMask;
  this->ShiftG = v3;
  this->ShiftB = Scaleform::Render::DDS::DDSDescr::CalcShiftByMask(BBitMask);
  this->ShiftA = Scaleform::Render::DDS::DDSDescr::CalcShiftByMask(this->ABitMask);
}
