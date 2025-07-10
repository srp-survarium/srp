void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::draw(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *source,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *matrix,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *colorTransform,
        Scaleform::GFx::ASString *blendMode,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *clipRect,
        bool smoothing)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  bool v13; // zf
  Scaleform::GFx::AS3::VM *v14; // esi
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  const Scaleform::Render::Matrix2x4<float> *MatrixF; // eax
  Scaleform::Render::Rect<long> *v18; // eax
  int y2; // ecx
  int x2; // edx
  int y1; // edi
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::VM *v25; // edi
  const Scaleform::GFx::AS3::Value *v26; // eax
  Scaleform::Render::DrawableImage *v27; // eax
  Scaleform::GFx::AS3::VM *v28; // edi
  const Scaleform::GFx::AS3::Value *v29; // eax
  Scaleform::GFx::DisplayObjectBase *Height; // ecx
  Scaleform::Render::TreeNode *RenderNode; // edi
  Scaleform::GFx::AS3::VM *v32; // esi
  const Scaleform::GFx::AS3::VM::Error *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *scale; // [esp+1C0h] [ebp-94h]
  Scaleform::GFx::AS3::VMAppDomain *scalea; // [esp+1C0h] [ebp-94h]
  bool v37; // [esp+1D7h] [ebp-7Dh]
  bool v38; // [esp+1D7h] [ebp-7Dh]
  Scaleform::Render::BlendMode v39; // [esp+1D8h] [ebp-7Ch]
  Scaleform::GFx::AS3::VM::Error v40; // [esp+1DCh] [ebp-78h] BYREF
  int x1; // [esp+1E4h] [ebp-70h] BYREF
  int v42; // [esp+1E8h] [ebp-6Ch]
  int v43; // [esp+1ECh] [ebp-68h]
  int v44; // [esp+1F0h] [ebp-64h]
  Scaleform::Render::Matrix2x4<float> v45; // [esp+1F4h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> v46; // [esp+214h] [ebp-40h] BYREF
  Scaleform::Render::Cxform cform; // [esp+234h] [ebp-20h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v40, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v10);
    pNode = v40.Message.pNode;
    --v40.Message.pNode->RefCount;
    v12 = pNode;
    v13 = pNode->RefCount == 0;
    goto LABEL_25;
  }
  if ( !source )
  {
    v14 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v40, eInvalidArgumentError, v14);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v14, v15);
    v16 = v40.Message.pNode;
    --v40.Message.pNode->RefCount;
    v12 = v16;
    v13 = v16->RefCount == 0;
    goto LABEL_25;
  }
  v46.M[0][0] = 1.0;
  v46.M[0][1] = 0.0;
  v46.M[0][2] = 0.0;
  v46.M[0][3] = 0.0;
  v46.M[1][0] = 0.0;
  v46.M[1][2] = 0.0;
  v46.M[1][3] = 0.0;
  v46.M[1][1] = 1.0;
  if ( matrix )
  {
    MatrixF = Scaleform::GFx::AS3::Instances::fl_geom::Matrix::GetMatrixF(matrix, &v45);
    Scaleform::Render::Matrix2x4<float>::Append(&v46, MatrixF);
  }
  Scaleform::Render::Cxform::Cxform(&cform);
  if ( colorTransform )
    qmemcpy(
      &cform,
      Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(
        (Scaleform::Render::Cxform *)&v45,
        colorTransform),
      sizeof(cform));
  v39 = Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(blendMode);
  x1 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  if ( clipRect )
  {
    v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(
            this,
            (Scaleform::Render::Rect<long> *)&v45,
            clipRect);
    y2 = v18->y2;
    x2 = v18->x2;
    y1 = v18->y1;
    x1 = v18->x1;
    v42 = y1;
    v43 = x2;
    v44 = y2;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  pObject = this->pTraits.pObject;
  v40.ID = (Scaleform::GFx::AS3::VM::ErrorID)DrawableImageFromBitmapData;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
  v25 = this->pTraits.pObject->pVM;
  scale = (const Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject;
  Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&v45, source);
  v37 = Scaleform::GFx::AS3::VM::IsOfType(v25, v26, scale);
  if ( (LOBYTE(v45.M[0][0]) & 0x1Fu) > 9 )
  {
    if ( (LOWORD(v45.M[0][0]) & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&v45);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v45);
  }
  if ( v37 )
  {
    v27 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, source);
    Scaleform::Render::DrawableImage::Draw(
      (Scaleform::Render::DrawableImage *)v40.ID,
      v27,
      &v46,
      &cform,
      v39,
      clipRect != 0 ? (Scaleform::Render::Rect<int> *)&x1 : 0,
      smoothing);
    return;
  }
  v28 = this->pTraits.pObject->pVM;
  scalea = v28->CurrentDomain;
  Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&v45, source);
  v38 = Scaleform::GFx::AS3::VM::IsOfType(v28, v29, "flash.display.DisplayObject", scalea);
  if ( (LOBYTE(v45.M[0][0]) & 0x1Fu) > 9 )
  {
    if ( (LOWORD(v45.M[0][0]) & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&v45);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v45);
  }
  if ( !v38 )
  {
    v32 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v40, eInvalidArgumentError, v32);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v32, v33);
    v34 = v40.Message.pNode;
    --v40.Message.pNode->RefCount;
    v12 = v34;
    v13 = v34->RefCount == 0;
LABEL_25:
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    return;
  }
  Scaleform::Render::Matrix2x4<float>::PrependScaling(&v46, 0.050000001);
  Height = (Scaleform::GFx::DisplayObjectBase *)source->Height;
  if ( Height )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(Height);
    Scaleform::GFx::MovieImpl::UpdateAllRenderNodes((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
    Scaleform::Render::DrawableImage::Draw(
      (Scaleform::Render::DrawableImage *)v40.ID,
      RenderNode,
      &v46,
      &cform,
      v39,
      clipRect != 0 ? (Scaleform::Render::Rect<int> *)&x1 : 0);
  }
}
