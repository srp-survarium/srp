void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pHAL; // eax
  Scaleform::GFx::AS3::Value *v7; // edi
  Scaleform::Render::DrawableImageContext *DrawableImageContext; // eax
  Scaleform::GFx::Resource *v9; // edi
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // ecx
  void (__thiscall *GetRenderInterfaces)(Scaleform::Render::ThreadCommandQueue *, Scaleform::Render::Interfaces *); // edx
  Scaleform::Render::TextureManager *pTextureManager; // ebp
  Scaleform::Render::DrawableImage *v13; // ebx
  Scaleform::Render::ImageFormat v14; // eax
  Scaleform::Render::ImageBase *v15; // eax
  Scaleform::Render::ImageBase *v16; // edi
  Scaleform::Render::ImageBase *v17; // ecx
  Scaleform::Render::DrawableImage *v18; // eax
  Scaleform::Render::ImageBase *v19; // eax
  Scaleform::Render::ImageBase *pObject; // ecx
  Scaleform::StringDataPtr v21; // [esp-14h] [ebp-38h]
  Scaleform::Render::Size<unsigned long> v22; // [esp-14h] [ebp-38h]
  bool Transparent; // [esp-Ch] [ebp-30h]
  unsigned int v24; // [esp-8h] [ebp-2Ch]
  unsigned int clearColor; // [esp+10h] [ebp-14h] BYREF
  Scaleform::Render::Interfaces interfaces; // [esp+14h] [ebp-10h] BYREF

  v3 = argc;
  if ( argc >= 2 )
  {
    v7 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv)->Result )
    {
      this->Width = (unsigned int)argv;
      if ( Scaleform::GFx::AS3::Value::Convert2Int32(v7 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv)->Result )
      {
        this->Height = (unsigned int)argv;
        clearColor = -1;
        if ( v3 >= 3 )
          this->Transparent = Scaleform::GFx::AS3::Value::Convert2Boolean(v7 + 2);
        if ( v3 >= 4 )
          Scaleform::GFx::AS3::Value::Convert2UInt32(v7 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &clearColor);
        DrawableImageContext = Scaleform::GFx::MovieImpl::GetDrawableImageContext((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
        v9 = (Scaleform::GFx::Resource *)DrawableImageContext;
        if ( DrawableImageContext )
        {
          pRTCommandQueue = DrawableImageContext->pRTCommandQueue;
          if ( pRTCommandQueue )
          {
            GetRenderInterfaces = pRTCommandQueue->GetRenderInterfaces;
            memset(&interfaces, 0, sizeof(interfaces));
            GetRenderInterfaces(pRTCommandQueue, &interfaces);
            pTextureManager = interfaces.pTextureManager;
            if ( this->pImageResource.pObject )
            {
              v18 = (Scaleform::Render::DrawableImage *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x78u);
              if ( v18 )
              {
                Scaleform::Render::DrawableImage::DrawableImage(v18, 1, this->pImageResource.pObject->pImage, v9);
                v16 = v19;
              }
              else
              {
                v16 = 0;
              }
              pObject = this->pImage.pObject;
              if ( pObject )
                pObject->Release(pObject);
            }
            else
            {
              v13 = (Scaleform::Render::DrawableImage *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x78u);
              if ( v13 )
              {
                v24 = clearColor;
                Transparent = this->Transparent;
                v22 = *(Scaleform::Render::Size<unsigned long> *)&this->Width;
                v14 = pTextureManager->GetDrawableImageFormat(pTextureManager);
                Scaleform::Render::DrawableImage::DrawableImage(
                  v13,
                  v14,
                  v22,
                  Transparent,
                  (Scaleform::Render::Color)v24,
                  v9);
                v16 = v15;
              }
              else
              {
                v16 = 0;
              }
              v17 = this->pImage.pObject;
              if ( v17 )
              {
                v17->Release(v17);
                this->pImage.pObject = v16;
                return;
              }
            }
            this->pImage.pObject = v16;
          }
        }
      }
    }
  }
  else
  {
    v21.pStr = "BitmapData::AS3Constructor";
    v21.Size = 26;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&interfaces,
      eWrongArgumentCountError,
      this->pTraits.pObject->pVM,
      v21,
      2,
      2,
      argc);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    pHAL = (Scaleform::GFx::ASStringNode *)interfaces.pHAL;
    --interfaces.pHAL->CurrentPass;
    if ( !pHAL->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pHAL);
  }
}
