void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pHAL; // eax
  Scaleform::GFx::AS3::Value *v8; // edi
  Scaleform::Render::DrawableImageContext *DrawableImageContext; // eax
  Scaleform::GFx::Resource *v10; // edi
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // ecx
  void (__thiscall *GetRenderInterfaces)(Scaleform::Render::ThreadCommandQueue *, Scaleform::Render::Interfaces *); // eax
  Scaleform::Render::TextureManager *pTextureManager; // ebp
  Scaleform::Render::DrawableImage *v14; // ebx
  Scaleform::Render::ImageFormat v15; // eax
  Scaleform::Render::ImageBase *v16; // eax
  Scaleform::Render::ImageBase *v17; // edi
  Scaleform::Render::ImageBase *v18; // ecx
  Scaleform::Render::DrawableImage *v19; // eax
  Scaleform::Render::ImageBase *v20; // eax
  Scaleform::Render::ImageBase *pObject; // ecx
  Scaleform::Render::Size<unsigned long> v22; // [esp-14h] [ebp-38h]
  bool Transparent; // [esp-Ch] [ebp-30h]
  unsigned int v24; // [esp-8h] [ebp-2Ch]
  unsigned int clearColor; // [esp+10h] [ebp-14h] BYREF
  Scaleform::Render::Interfaces interfaces; // [esp+14h] [ebp-10h] BYREF

  v3 = argc;
  if ( argc >= 2 )
  {
    v8 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv)->Result )
    {
      this->Width = (unsigned int)argv;
      if ( Scaleform::GFx::AS3::Value::Convert2Int32(v8 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv)->Result )
      {
        this->Height = (unsigned int)argv;
        clearColor = -1;
        if ( v3 >= 3 )
          this->Transparent = Scaleform::GFx::AS3::Value::Convert2Boolean(v8 + 2);
        if ( v3 >= 4 )
          Scaleform::GFx::AS3::Value::Convert2UInt32(v8 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, &clearColor);
        DrawableImageContext = Scaleform::GFx::MovieImpl::GetDrawableImageContext((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
        v10 = (Scaleform::GFx::Resource *)DrawableImageContext;
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
              v19 = (Scaleform::Render::DrawableImage *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x74u);
              if ( v19 )
              {
                Scaleform::Render::DrawableImage::DrawableImage(v19, 1, this->pImageResource.pObject->pImage, v10);
                v17 = v20;
              }
              else
              {
                v17 = 0;
              }
              pObject = this->pImage.pObject;
              if ( pObject )
                pObject->Release(pObject);
            }
            else
            {
              v14 = (Scaleform::Render::DrawableImage *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x74u);
              if ( v14 )
              {
                v24 = clearColor;
                Transparent = this->Transparent;
                v22 = *(Scaleform::Render::Size<unsigned long> *)&this->Width;
                v15 = pTextureManager->GetDrawableImageFormat(pTextureManager);
                Scaleform::Render::DrawableImage::DrawableImage(
                  v14,
                  v15,
                  v22,
                  Transparent,
                  (Scaleform::Render::Color)v24,
                  (Scaleform::Render::DrawableImageContext *)v10);
                v17 = v16;
              }
              else
              {
                v17 = 0;
              }
              v18 = this->pImage.pObject;
              if ( v18 )
              {
                v18->Release(v18);
                this->pImage.pObject = v17;
                return;
              }
            }
            this->pImage.pObject = v17;
          }
        }
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&interfaces, eWrongArgumentCountError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    pHAL = (Scaleform::GFx::ASStringNode *)interfaces.pHAL;
    --interfaces.pHAL->CurrentPass;
    if ( !pHAL->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pHAL);
  }
}
