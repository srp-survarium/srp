void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::paletteMap(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // esi
  unsigned int v6; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::ErrorID VInt; // edx
  int v10; // edi
  unsigned int v11; // eax
  Scaleform::GFx::AS3::VM *v12; // edi
  unsigned int v13; // edi
  Scaleform::GFx::AS3::Value::VU *p_value; // eax
  int v15; // ebx
  Scaleform::GFx::AS3::Value *v16; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // esi
  Scaleform::Render::DrawableImage *v18; // edi
  double v19; // st7
  const Scaleform::Render::Rect<long> *v20; // eax
  Scaleform::StringDataPtr v21[3]; // [esp-8h] [ebp-105Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v22; // [esp+10h] [ebp-1044h] BYREF
  char *v23; // [esp+18h] [ebp-103Ch]
  Scaleform::GFx::AS3::CheckResult resulta; // [esp+1Fh] [ebp-1035h] BYREF
  Scaleform::GFx::AS3::Value::VU *v25; // [esp+20h] [ebp-1034h]
  Scaleform::Render::Point<long> v26; // [esp+24h] [ebp-1030h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData; // [esp+2Ch] [ebp-1028h]
  unsigned int v28; // [esp+30h] [ebp-1024h]
  const void *v29[4]; // [esp+34h] [ebp-1020h] BYREF
  Scaleform::Render::Rect<long> v30; // [esp+44h] [ebp-1010h] BYREF
  char v31; // [esp+54h] [ebp-1000h] BYREF

  v5 = 0;
  if ( !this->pImage.pObject )
  {
    v21[0].pStr = "Invalid BitmapData";
    v21[0].Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eArgumentError, this->pTraits.pObject->pVM, v21[0]);
    pVM = this->pTraits.pObject->pVM;
LABEL_3:
    v21[0].Size = v6;
    goto LABEL_4;
  }
  if ( argc < 3 )
    return;
  VInt = argv[1].value.VS._1.VInt;
  v10 = argv[2].value.VS._1.VInt;
  sourceBitmapData = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VInt;
  v22.ID = VInt;
  v26.x = v10;
  if ( !sourceBitmapData )
  {
    v21[0].pStr = "sourceBitmapData";
    v21[0].Size = 16;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eNullPointerError, this->pTraits.pObject->pVM, v21[0]);
    v21[0].Size = v11;
    pVM = this->pTraits.pObject->pVM;
LABEL_4:
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, (const Scaleform::GFx::AS3::VM::Error *)v21[0].Size);
    pNode = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( !VInt )
  {
    v12 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(v21, "sourceRect");
LABEL_11:
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eNullPointerError, v12, v21[0]);
    pVM = v12;
    goto LABEL_3;
  }
  if ( !v10 )
  {
    v12 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(v21, "destPoint");
    goto LABEL_11;
  }
  v13 = 0;
  p_value = &argv[3].value;
  v28 = argc - 3;
  v23 = &v31;
  v25 = &argv[3].value;
  do
  {
    if ( v13 < v28 )
    {
      v15 = p_value->VS._1.VInt;
      *(&v30.x1 + v13) = p_value->VS._1.VInt;
      if ( v15 )
      {
        v29[v13] = v23;
        do
        {
          v16 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                                (Scaleform::GFx::AS3::Impl::SparseArray *)(v15 + 32),
                                                v5);
          Scaleform::GFx::AS3::Value::Convert2UInt32(v16, &resulta, (unsigned int *)v29[v13] + v5++);
        }
        while ( v5 < 0x100 );
        v5 = 0;
      }
      else
      {
        v29[v13] = 0;
      }
    }
    else
    {
      v29[v13] = 0;
    }
    v23 += 1024;
    ++v13;
    p_value = v25 + 2;
    v25 += 2;
  }
  while ( v13 < 4 );
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
  v19 = *(double *)(v26.x + 40);
  v26.x = (int)*(double *)(v26.x + 32);
  v26.y = (int)v19;
  v20 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(
          this,
          &v30,
          (const Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)v22.ID);
  Scaleform::Render::DrawableImage::PaletteMap(DrawableImageFromBitmapData, v18, v20, &v26, v29);
}
