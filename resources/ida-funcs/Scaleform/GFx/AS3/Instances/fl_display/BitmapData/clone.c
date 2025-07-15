void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result)
{
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *pV; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::Resource *DrawableImageContext; // ebx
  Scaleform::Render::DrawableImage *v10; // eax
  Scaleform::Render::ImageBase *v11; // eax
  Scaleform::Render::ImageBase *v12; // esi
  Scaleform::Render::ImageBase *v13; // ecx
  Scaleform::Ptr<Scaleform::Render::ImageBase> *p_pImage; // edi
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v16; // [esp+Ch] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
                 (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *)&v16,
                 (Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *)this->pTraits.pObject);
    pV = Instance->pV;
    pObject = result->pObject;
    if ( Instance->pV != result->pObject )
    {
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)pObject - 1);
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
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
    v10 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                120,
                                                0);
    if ( v10 )
    {
      Scaleform::Render::DrawableImage::DrawableImage(
        v10,
        this->Transparent,
        this->pImage.pObject,
        DrawableImageContext);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    v13 = result->pObject->pImage.pObject;
    p_pImage = &result->pObject->pImage;
    if ( v13 )
      v13->Release(v13);
    p_pImage->pObject = v12;
  }
  else
  {
    v15.pStr = "Invalid BitmapData";
    v15.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eArgumentError, this->pTraits.pObject->pVM, v15);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v3);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
