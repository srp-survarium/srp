void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawRect(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y,
        long double width,
        long double height)
{
  long double v6; // st7
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  long double v10; // st6
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::DrawingContext *pObject; // ecx
  long double v13; // st4
  Scaleform::StringDataPtr xa; // [esp+0h] [ebp-Ch]
  Scaleform::StringDataPtr xb; // [esp+0h] [ebp-Ch]
  float x1; // [esp+14h] [ebp+8h]
  float y1; // [esp+1Ch] [ebp+10h]

  v6 = width;
  if ( (HIDWORD(width) & 0x7FF00000) == 0x7FF00000 && HIDWORD(width) & 0xFFFFF | LODWORD(width) )
  {
    xa.pStr = "width";
    xa.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&width,
      eInvalidArgumentError,
      this->pTraits.pObject->pVM,
      xa);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v8);
  }
  else
  {
    v10 = height;
    width = height;
    if ( (HIDWORD(width) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(width) & 0xFFFFF | LODWORD(width)) )
    {
      pObject = this->pDrawing.pObject;
      v13 = x * 20.0;
      *(float *)&height = v13;
      *(float *)&width = y * 20.0;
      x1 = v13 + v6 * 20.0;
      y1 = y * 20.0 + v10 * 20.0;
      Scaleform::GFx::DrawingContext::MoveTo(pObject, *(float *)&height, *(float *)&width);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, x1, *(float *)&width);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, x1, y1);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, *(float *)&height, y1);
      Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, *(float *)&height, *(float *)&width);
      Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
      return;
    }
    xb.pStr = "height";
    xb.Size = 6;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&width,
      eInvalidArgumentError,
      this->pTraits.pObject->pVM,
      xb);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v11);
  }
  v9 = (Scaleform::GFx::ASStringNode *)HIDWORD(width);
  --*(_DWORD *)(HIDWORD(width) + 12);
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
