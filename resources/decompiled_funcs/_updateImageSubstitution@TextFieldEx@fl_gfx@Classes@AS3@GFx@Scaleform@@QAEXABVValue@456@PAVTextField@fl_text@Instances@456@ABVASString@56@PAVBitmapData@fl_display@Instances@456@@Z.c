void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::updateImageSubstitution(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *id,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *image)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::TextField *pObject; // edi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_mHash; // esi
  const Scaleform::GFx::ASString *v10; // ebp
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v11; // eax
  Scaleform::Render::Text::ImageDesc **p_SizeMask; // ebx
  void *v13; // esi
  Scaleform::Render::Text::ImageDesc *v14; // ebx
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // eax
  Scaleform::GFx::ImageResource *ImageResource; // ebx
  Scaleform::GFx::ASString *v17; // eax
  Scaleform::GFx::Resource *v18; // esi
  Scaleform::Render::Image *v19; // ebp
  Scaleform::Render::Image *pImage; // ebx
  Scaleform::GFx::ResourceReport *(__thiscall *GetResourceReport)(Scaleform::GFx::Resource *); // eax
  Scaleform::GFx::Resource *v22; // esi
  Scaleform::RefCountVImpl *v23; // eax
  Scaleform::MemoryHeap *v24; // eax
  Scaleform::GFx::Resource_vtbl *v25; // edx
  Scaleform::GFx::ResourceReport *(__thiscall *v26)(Scaleform::GFx::Resource *); // eax
  Scaleform::RefCountVImpl *v27; // esi
  Scaleform::Render::Image *v28; // ecx
  Scaleform::Render::Text::ImageDesc *pimageDesc; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v30; // [esp+1Ch] [ebp-24h]
  Scaleform::GFx::ImageCreateInfo cinfo; // [esp+20h] [ebp-20h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( textField )
  {
    pObject = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
    p_mHash = &pObject->pImageDescAssoc->mHash;
    if ( p_mHash )
    {
      v10 = id;
      Scaleform::String::String((Scaleform::String *)&textField, (char *)id->pNode->pData);
      v11 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
              p_mHash,
              (const Scaleform::String *)&textField);
      if ( v11 )
        p_SizeMask = (Scaleform::Render::Text::ImageDesc **)&v11->SizeMask;
      else
        p_SizeMask = 0;
      v13 = (void *)((unsigned int)textField & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)textField & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
      if ( p_SizeMask )
      {
        v14 = *p_SizeMask;
        pimageDesc = v14;
        if ( image )
        {
          ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(image);
          v17 = (Scaleform::GFx::ASString *)pObject->GetResourceMovieDef(pObject);
          v18 = (Scaleform::GFx::Resource *)v17;
          id = v17;
          if ( v17 )
            Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v17);
          v19 = 0;
          if ( ImageResource->pImage->GetImageType(ImageResource->pImage) )
          {
            pImage = (Scaleform::Render::Image *)ImageResource->pImage;
            if ( pImage )
              pImage->AddRef(pImage);
            v19 = pImage;
          }
          else
          {
            GetResourceReport = v18[1].GetResourceReport;
            v22 = v18 + 1;
            v23 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))GetResourceReport)(
                                                v22,
                                                11);
            LOBYTE(textField) = v23 == 0;
            if ( v23 )
              Scaleform::RefCountImpl::Release(v23);
            if ( (_BYTE)textField )
            {
              Scaleform::LogDebugMessage(
                (Scaleform::LogMessageId)135168,
                "ImageCreator is null in UpdateImageSubstitution");
            }
            else
            {
              v24 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pObject);
              v25 = v22->__vftable;
              cinfo.pHeap = v24;
              cinfo.Use = 1;
              cinfo.RUse = Use_Bitmap;
              memset(&cinfo.pLog, 0, 16);
              v26 = v25->GetResourceReport;
              cinfo.Type = Create_SourceImage;
              v27 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))v26)(v22, 11);
              v19 = (Scaleform::Render::Image *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageBase *))v27->__vftable[1].AddRef)(
                                                  v27,
                                                  &cinfo,
                                                  ImageResource->pImage);
              Scaleform::RefCountImpl::Release(v27);
            }
            v18 = (Scaleform::GFx::Resource *)id;
          }
          if ( v19 )
            v19->AddRef(v19);
          v28 = pimageDesc->pImage.pObject;
          if ( v28 )
            v28->Release(v28);
          pimageDesc->pImage.pObject = v19;
          Scaleform::GFx::TextField::SetDirtyFlag(pObject);
          if ( v19 )
            v19->Release(v19);
          if ( v18 )
            Scaleform::GFx::Resource::Release(v18);
        }
        else
        {
          ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor(pObject);
          if ( ImageSubstitutor )
          {
            Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(ImageSubstitutor, v14);
            pObject->pDocument.pObject->RTFlags |= 2u;
            Scaleform::GFx::TextField::RemoveIdImageDescAssoc(pObject, (char *)v10->pNode->pData);
            Scaleform::GFx::TextField::SetDirtyFlag(pObject);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&pimageDesc, eNullArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    v7 = v30;
    --v30->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
