void __thiscall Scaleform::GFx::FontDataCompactedGfx::FontDataCompactedGfx(Scaleform::GFx::FontDataCompactedGfx *this)
{
  Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *p_Container; // ecx

  this->Ascent = 0.0;
  this->__vftable = (Scaleform::GFx::FontDataCompactedGfx_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Descent = 0.0;
  this->__vftable = (Scaleform::GFx::FontDataCompactedGfx_vtbl *)&Scaleform::Render::Font::`vftable';
  this->Leading = 0.0;
  this->RefCount = 1;
  this->Flags = 0;
  this->LowerCaseTop = 0;
  this->UpperCaseTop = 0;
  this->hRef.pManager.Value = 0;
  this->hRef.pFontHandle = 0;
  this->__vftable = (Scaleform::GFx::FontDataCompactedGfx_vtbl *)&Scaleform::GFx::FontDataCompactedGfx::`vftable';
  p_Container = &this->Container;
  p_Container->Data = 0;
  p_Container->Size = 0;
  p_Container->Capacity = 0;
  this->CompactedFontValue.RefCount = 1;
  this->CompactedFontValue.__vftable = (Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> >_vtbl *)&Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::`vftable';
  this->CompactedFontValue.Decoder.Data = p_Container;
  this->CompactedFontValue.Name.Data = 0;
  this->CompactedFontValue.Name.Size = 0;
  this->CompactedFontValue.Name.Capacity = 0;
}
