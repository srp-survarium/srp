void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::applyFilter(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::Render::DrawableImage *destPoint,
        Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *filter)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v10; // ecx
  Scaleform::GFx::AS3::VM *v11; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  const Scaleform::GFx::AS3::Instances::fl_geom::Point *v14; // ebx
  Scaleform::GFx::AS3::VM *v15; // esi
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v18; // edi
  Scaleform::GFx::AS3::VM *v19; // esi
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebp
  Scaleform::GFx::Resource *pObject; // edi
  Scaleform::GFx::AS3::VM *v24; // esi
  const Scaleform::GFx::AS3::VM::Error *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS3::VM *v27; // esi
  const Scaleform::GFx::AS3::VM::Error *v28; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // ecx
  Scaleform::GFx::AS3::VM::Error v30; // [esp+4h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::VM::Error v31; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Render::Point<long> pt; // [esp+14h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> rect; // [esp+1Ch] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v8);
    pNode = v30.Message.pNode;
    --v30.Message.pNode->RefCount;
    v10 = pNode;
    if ( pNode->RefCount )
      return;
LABEL_23:
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    return;
  }
  if ( !sourceBitmapData )
  {
    v11 = this->pTraits.pObject->pVM;
    goto LABEL_6;
  }
  if ( !sourceRect )
  {
    v11 = this->pTraits.pObject->pVM;
LABEL_6:
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eNullPointerError, v11);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v11, v12);
    v13 = v30.Message.pNode;
    --v30.Message.pNode->RefCount;
    v10 = v13;
    if ( v13->RefCount )
      return;
    goto LABEL_23;
  }
  v14 = (const Scaleform::GFx::AS3::Instances::fl_geom::Point *)destPoint;
  if ( !destPoint )
  {
    v15 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eNullPointerError, v15);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v15, v16);
    v17 = v30.Message.pNode;
    --v30.Message.pNode->RefCount;
    v10 = v17;
    if ( v17->RefCount )
      return;
    goto LABEL_23;
  }
  v18 = filter;
  if ( !filter )
  {
    v19 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eNullPointerError, v19);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v19, v20);
    v21 = v30.Message.pNode;
    --v30.Message.pNode->RefCount;
    v10 = v21;
    if ( v21->RefCount )
      return;
    goto LABEL_23;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  destPoint = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                this,
                sourceBitmapData);
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &rect, sourceRect);
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(this, &pt, v14);
  pObject = (Scaleform::GFx::Resource *)v18->FilterData.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(this, (bool *)&sourceRect);
    switch ( (unsigned int)pObject->pLib )
    {
      case 0u:
      case 8u:
        goto $LN3_76;
      case 1u:
      case 2u:
      case 3u:
        if ( (_BYTE)sourceRect )
          goto $LN3_76;
        v24 = this->pTraits.pObject->pVM;
        Scaleform::GFx::AS3::VM::Error::Error(&v30, eIllegalOperationError, v24);
        Scaleform::GFx::AS3::VM::ThrowArgumentError(v24, v25);
        v26 = v30.Message.pNode;
        goto LABEL_22;
      case 0xAu:
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(
          sourceBitmapData,
          (bool *)&sourceBitmapData);
        if ( (_BYTE)sourceBitmapData == (_BYTE)sourceRect )
        {
$LN3_76:
          Scaleform::Render::DrawableImage::ApplyFilter(DrawableImageFromBitmapData, destPoint, &rect, &pt, pObject);
          return;
        }
        v27 = this->pTraits.pObject->pVM;
        Scaleform::GFx::AS3::VM::Error::Error(&v31, eIllegalOperationError, v27);
        Scaleform::GFx::AS3::VM::ThrowArgumentError(v27, v28);
        v26 = v31.Message.pNode;
LABEL_22:
        --v26->RefCount;
        v10 = v26;
        if ( !v26->RefCount )
          goto LABEL_23;
        return;
      default:
        break;
    }
  }
  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method BitmapData::applyFilter (unsupported filter type) is not implemented\n");
}
