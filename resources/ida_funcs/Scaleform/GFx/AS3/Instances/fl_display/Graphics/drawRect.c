void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawRect(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y,
        long double width,
        long double height)
{
  long double v6; // st7
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  long double v11; // st6
  Scaleform::GFx::DrawingContext *pObject; // ecx
  long double v13; // st4
  float x1; // [esp+14h] [ebp+8h]
  float y1; // [esp+1Ch] [ebp+10h]

  v6 = width;
  if ( (HIDWORD(width) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(width) | LODWORD(width) )
  {
    pVM = this->pTraits.pObject->pVM;
  }
  else
  {
    v11 = height;
    width = height;
    if ( (HIDWORD(width) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(width) | LODWORD(width)) )
    {
      pObject = this->pDrawing.pObject;
      v13 = x * 20.0;
      *(float *)&height = v13;
      *(float *)&width = y * 20.0;
      x1 = v13 + v6 * 20.0;
      y1 = y * 20.0 + v11 * 20.0;
      Scaleform::GFx::DrawingContext::MoveTo(pObject, *(float *)&height, *(float *)&width);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, x1, *(float *)&width);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, x1, y1);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, *(float *)&height, y1);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, *(float *)&height, *(float *)&width);
      Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
      return;
    }
    pVM = this->pTraits.pObject->pVM;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&width, eInvalidArgumentError, pVM);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v9);
  v10 = (Scaleform::GFx::ASStringNode *)HIDWORD(width);
  --*(_DWORD *)(HIDWORD(width) + 12);
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}
