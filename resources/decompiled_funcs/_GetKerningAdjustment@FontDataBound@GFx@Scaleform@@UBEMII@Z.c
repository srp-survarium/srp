void __thiscall Scaleform::GFx::FontDataBound::GetKerningAdjustment(
        Scaleform::GFx::FontDataBound *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  this->pFont.pObject->GetKerningAdjustment(this->pFont.pObject, lastCode, thisCode);
}
