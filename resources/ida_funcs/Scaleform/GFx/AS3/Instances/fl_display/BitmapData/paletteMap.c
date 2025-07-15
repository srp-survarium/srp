void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::paletteMap(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::AS3::VM::ErrorID VInt; // edx
  int v10; // esi
  Scaleform::GFx::AS3::VM *v11; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  unsigned int v14; // edi
  Scaleform::GFx::AS3::Value::VU *p_value; // eax
  int v16; // ebx
  unsigned int v17; // esi
  Scaleform::GFx::AS3::Value *v18; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // esi
  Scaleform::Render::DrawableImage *v20; // edi
  double v21; // st7
  const Scaleform::Render::Rect<long> *v22; // eax
  Scaleform::GFx::AS3::VM::Error v23; // [esp+8h] [ebp-1044h] BYREF
  unsigned int *v24; // [esp+10h] [ebp-103Ch]
  Scaleform::GFx::AS3::CheckResult resulta; // [esp+17h] [ebp-1035h] BYREF
  Scaleform::GFx::AS3::Value::VU *v26; // [esp+18h] [ebp-1034h]
  Scaleform::Render::Point<long> destPoint; // [esp+1Ch] [ebp-1030h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData; // [esp+24h] [ebp-1028h]
  unsigned int v29; // [esp+28h] [ebp-1024h]
  unsigned int *channels[4]; // [esp+2Ch] [ebp-1020h] BYREF
  Scaleform::Render::Rect<long> v31; // [esp+3Ch] [ebp-1010h] BYREF
  char v32; // [esp+4Ch] [ebp-1000h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    pNode = v23.Message.pNode;
    --v23.Message.pNode->RefCount;
    v8 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_3;
  }
  if ( argc >= 3 )
  {
    VInt = argv[1].value.VS._1.VInt;
    v10 = argv[2].value.VS._1.VInt;
    sourceBitmapData = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VInt;
    v23.ID = VInt;
    destPoint.x = v10;
    if ( sourceBitmapData )
    {
      if ( VInt )
      {
        if ( v10 )
        {
          v14 = 0;
          p_value = &argv[3].value;
          v29 = argc - 3;
          v24 = (unsigned int *)&v32;
          v26 = &argv[3].value;
          do
          {
            if ( v14 < v29 )
            {
              v16 = p_value->VS._1.VInt;
              v17 = 0;
              *(&v31.x1 + v14) = p_value->VS._1.VInt;
              if ( v16 )
              {
                channels[v14] = v24;
                do
                {
                  v18 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                                        (Scaleform::GFx::AS3::Impl::SparseArray *)(v16 + 32),
                                                        v17);
                  Scaleform::GFx::AS3::Value::Convert2UInt32(v18, &resulta, &channels[v14][v17++]);
                }
                while ( v17 < 0x100 );
              }
              else
              {
                channels[v14] = 0;
              }
            }
            else
            {
              channels[v14] = 0;
            }
            v24 += 256;
            ++v14;
            p_value = v26 + 2;
            v26 += 2;
          }
          while ( v14 < 4 );
          DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                          this,
                                          this);
          v20 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                  this,
                  sourceBitmapData);
          v21 = *(double *)(destPoint.x + 40);
          destPoint.x = (int)*(double *)(destPoint.x + 32);
          destPoint.y = (int)v21;
          v22 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(
                  this,
                  &v31,
                  (const Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)v23.ID);
          Scaleform::Render::DrawableImage::PaletteMap(DrawableImageFromBitmapData, v20, v22, &destPoint, channels);
          return;
        }
        v11 = this->pTraits.pObject->pVM;
      }
      else
      {
        v11 = this->pTraits.pObject->pVM;
      }
    }
    else
    {
      v11 = this->pTraits.pObject->pVM;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eNullPointerError, v11);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v11, v12);
    v13 = v23.Message.pNode;
    --v23.Message.pNode->RefCount;
    v8 = v13;
    if ( !v13->RefCount )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}
