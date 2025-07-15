void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::htmlTextSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::TextField *pObject; // ecx

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  pObject->Flags |= 2u;
  Scaleform::GFx::TextField::SetTextValue(pObject, (const __m128i *)value->pNode->pData, 1, 1);
}
