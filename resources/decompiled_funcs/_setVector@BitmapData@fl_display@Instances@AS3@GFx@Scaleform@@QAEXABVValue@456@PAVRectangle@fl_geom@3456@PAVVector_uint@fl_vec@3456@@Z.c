void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setVector(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *inputVector)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  int y1; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  const Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v9; // ebp
  Scaleform::GFx::AS3::VM *v10; // esi
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  int v12; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v13; // ebx
  Scaleform::GFx::AS3::VM *v14; // esi
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  int v16; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  const Scaleform::Render::Rect<long> *v18; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v19; // edi
  Scaleform::GFx::AS3::VM *v20; // esi
  const Scaleform::GFx::AS3::VM::Error *v21; // eax
  int v22; // eax
  Scaleform::Render::Rect<long> v23; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider pixelProvider; // [esp+14h] [ebp-Ch] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v23, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    y1 = v23.y1;
    --*(_DWORD *)(v23.y1 + 12);
    v8 = (Scaleform::GFx::ASStringNode *)y1;
    if ( *(_DWORD *)(y1 + 12) )
      return;
    goto LABEL_13;
  }
  v9 = rect;
  if ( !rect )
  {
    v10 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v23, eNullPointerError, v10);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v10, v11);
    v12 = v23.y1;
    --*(_DWORD *)(v23.y1 + 12);
    v8 = (Scaleform::GFx::ASStringNode *)v12;
    if ( *(_DWORD *)(v12 + 12) )
      return;
    goto LABEL_13;
  }
  v13 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)inputVector;
  if ( !inputVector )
  {
    v14 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v23, eNullPointerError, v14);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v14, v15);
    v16 = v23.y1;
    --*(_DWORD *)(v23.y1 + 12);
    v8 = (Scaleform::GFx::ASStringNode *)v16;
    if ( *(_DWORD *)(v16 + 12) )
      return;
    goto LABEL_13;
  }
  pixelProvider.__vftable = (Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider_vtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable';
  pixelProvider.Location = 0;
  pixelProvider.PixelVector = inputVector;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v23, v9);
  if ( !Scaleform::Render::DrawableImage::SetPixels(DrawableImageFromBitmapData, v18, &pixelProvider) )
  {
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthGet(v13, (unsigned int *)&rect);
    v19 = rect;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthGet(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)pixelProvider.PixelVector,
      (unsigned int *)&inputVector);
    if ( v19 < (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)inputVector )
    {
      v20 = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v23, eInvalidRangeError, v20);
      Scaleform::GFx::AS3::VM::ThrowError(v20, v21);
      v22 = v23.y1;
      --*(_DWORD *)(v23.y1 + 12);
      v8 = (Scaleform::GFx::ASStringNode *)v22;
      if ( !*(_DWORD *)(v22 + 12) )
LABEL_13:
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
  }
}
