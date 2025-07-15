void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *pV; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v9; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::Resource *DrawableImageContext; // ebx
  Scaleform::Render::DrawableImage *v12; // eax
  Scaleform::Render::ImageBase *v13; // eax
  Scaleform::Render::ImageBase *v14; // esi
  Scaleform::Render::ImageBase *v15; // ecx
  Scaleform::Ptr<Scaleform::Render::ImageBase> *p_pImage; // edi
  Scaleform::GFx::AS3::VM::Error v17; // [esp+4h] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *)this->pTraits.pObject;
  if ( this->pImage.pObject )
  {
    Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
                 (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *)&v17,
                 pObject);
    pV = Instance->pV;
    v9 = result->pObject;
    if ( Instance->pV != result->pObject )
    {
      if ( v9 )
      {
        if ( ((unsigned __int8)v9 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)v9 - 1);
        }
        else
        {
          RefCount = v9->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v9->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
          }
        }
      }
      result->pObject = pV;
    }
    result->pObject->Width = this->Width;
    result->pObject->Height = this->Height;
    result->pObject->Transparent = this->Transparent;
    result->pObject->Dirty = this->Dirty;
    DrawableImageContext = (Scaleform::GFx::Resource *)Scaleform::GFx::MovieImpl::GetDrawableImageContext((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
    v12 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                116,
                                                0);
    if ( v12 )
    {
      Scaleform::Render::DrawableImage::DrawableImage(
        v12,
        this->Transparent,
        this->pImage.pObject,
        DrawableImageContext);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    v15 = result->pObject->pImage.pObject;
    p_pImage = &result->pObject->pImage;
    if ( v15 )
      v15->Release(v15);
    p_pImage->pObject = v14;
  }
  else
  {
    pVM = pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    pNode = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
