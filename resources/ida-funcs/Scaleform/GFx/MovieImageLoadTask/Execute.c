void __thiscall Scaleform::GFx::MovieImageLoadTask::Execute(Scaleform::GFx::MovieImageLoadTask *this)
{
  Scaleform::GFx::LoadStates *pObject; // eax
  Scaleform::GFx::ResourceWeakLib *v3; // ecx
  Scaleform::GFx::LogState *v4; // eax
  Scaleform::MemoryHeap *v5; // ebx
  Scaleform::Log *GlobalLog; // eax
  Scaleform::Log *v7; // edx
  Scaleform::Render::ImageSource *BuiltinImage; // edi
  Scaleform::GFx::ImageResource *v9; // eax
  Scaleform::GFx::ImageResource *v10; // eax
  Scaleform::GFx::ImageResource *v11; // ebx
  Scaleform::GFx::ImageResource *v12; // ecx
  Scaleform::GFx::LogState *v13; // eax
  Scaleform::Log *v14; // eax
  Scaleform::GFx::State *v15; // eax
  Scaleform::GFx::ImageResource *v16; // ebx
  Scaleform::GFx::MovieDataDef *v17; // ebp
  Scaleform::GFx::ImageCreator *v18; // edi
  unsigned int v19; // eax
  bool inited; // bl
  Scaleform::GFx::MovieDataDef *v21; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v22; // edi
  unsigned int v23; // eax
  Scaleform::GFx::ImageResource *v24; // ecx
  unsigned int FileLength; // [esp-4h] [ebp-1Ch]
  Scaleform::Log *plog; // [esp+Ch] [ebp-Ch]
  Scaleform::Render::ImageSource *v27; // [esp+10h] [ebp-8h]
  Scaleform::File *v28; // [esp+14h] [ebp-4h]

  pObject = this->pLoadStates.pObject;
  v3 = pObject->pWeakResourceLib.pObject;
  v4 = pObject->pLog.pObject;
  v5 = v3->pImageHeap.pObject;
  if ( v4 )
  {
    GlobalLog = v4->pLog.pObject;
    if ( !GlobalLog )
      GlobalLog = Scaleform::Log::GetGlobalLog();
    v7 = GlobalLog;
  }
  else
  {
    v7 = 0;
  }
  BuiltinImage = Scaleform::GFx::LoaderImpl::LoadBuiltinImage(
                   this->pImageFile.pObject,
                   this->ImageFormat,
                   Use_Bitmap,
                   this->pLoadStates.pObject,
                   v7,
                   v5);
  v27 = BuiltinImage;
  if ( BuiltinImage )
  {
    v9 = (Scaleform::GFx::ImageResource *)v5->Alloc(v5, 52u, 0);
    if ( v9 )
    {
      Scaleform::GFx::ImageResource::ImageResource(v9, BuiltinImage, Use_Bitmap);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    v12 = this->pImageRes.pObject;
    if ( v12 )
      Scaleform::GFx::Resource::Release(v12);
    this->pImageRes.pObject = v11;
  }
  if ( this->pImageRes.pObject )
  {
    v28 = this->pImageFile.pObject;
    v13 = this->pLoadStates.pObject->pLog.pObject;
    if ( v13 )
    {
      v14 = v13->pLog.pObject;
      if ( !v14 )
        v14 = Scaleform::Log::GetGlobalLog();
      plog = v14;
    }
    else
    {
      plog = 0;
    }
    v15 = this->pDefImpl.pObject->GetStateAddRef(&this->pDefImpl.pObject->Scaleform::GFx::StateBag, 11);
    v16 = this->pImageRes.pObject;
    v17 = this->pDef.pObject;
    v18 = (Scaleform::GFx::ImageCreator *)v15;
    v19 = v28->GetLength(v28);
    inited = Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
               v17->pData.pObject,
               v19,
               v16,
               v18,
               plog,
               1);
    if ( v18 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18);
    if ( inited )
    {
      v21 = this->pDef.pObject;
      v22 = this->pDefImpl.pObject->pBindData.pObject;
      FileLength = v21->pData.pObject->Header.FileLength;
      v23 = v21->GetLoadingFrame(v21);
      Scaleform::GFx::MovieDefImpl::BindTaskData::UpdateBindingFrame(v22, v23, FileLength);
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pDefImpl.pObject->pBindData.pObject, 0x302u);
      BuiltinImage = v27;
    }
    else
    {
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pDefImpl.pObject->pBindData.pObject, 4u);
      v24 = this->pImageRes.pObject;
      if ( v24 )
        Scaleform::GFx::Resource::Release(v24);
      BuiltinImage = v27;
      this->pImageRes.pObject = 0;
    }
  }
  else
  {
    Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pDefImpl.pObject->pBindData.pObject, 4u);
  }
  if ( BuiltinImage )
    BuiltinImage->Release(BuiltinImage);
}
