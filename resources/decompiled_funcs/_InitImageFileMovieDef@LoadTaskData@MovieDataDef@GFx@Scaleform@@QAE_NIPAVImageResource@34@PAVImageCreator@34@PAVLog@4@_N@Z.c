BOOL __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::InitImageFileMovieDef(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int fileLength,
        Scaleform::GFx::ImageResource *pimageResource,
        Scaleform::GFx::ImageCreator *imgCreator,
        Scaleform::Log *plog,
        bool bilinear)
{
  Scaleform::GFx::ImageCreator *v6; // edi
  Scaleform::GFx::ImageResource *v7; // ebx
  Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::Render::Image *(__thiscall *CreateImage)(Scaleform::GFx::ImageCreator *, const Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageSource *); // edx
  Scaleform::Render::Image *v11; // edi
  Scaleform::GFx::ImageResource *v12; // eax
  Scaleform::GFx::ImageResource *v13; // eax
  Scaleform::GFx::ImageShapeCharacterDef *v14; // eax
  Scaleform::GFx::ImageResource *v15; // eax
  Scaleform::ArrayLH<Scaleform::GFx::TimelineDef::Frame,2,Scaleform::ArrayDefaultPolicy> *p_Playlist; // edi
  Scaleform::GFx::DataAllocator::Block *v17; // eax
  Scaleform::GFx::DataAllocator::Block *v18; // ebx
  Scaleform::GFx::DataAllocator::Block *v19; // eax
  const Scaleform::Render::Cxform *v20; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ImageBase *pImage; // [esp+FCh] [ebp-B4h]
  Scaleform::GFx::ImageResource *v24; // [esp+10Ch] [ebp-A4h]
  Scaleform::Render::Matrix2x4<float> matrix; // [esp+110h] [ebp-A0h] BYREF
  Scaleform::Render::Cxform v26; // [esp+130h] [ebp-80h] BYREF
  Scaleform::GFx::CharPosInfo __that; // [esp+150h] [ebp-60h] BYREF

  v6 = imgCreator;
  v7 = 0;
  this->Header.FileLength = fileLength;
  if ( !imgCreator || pimageResource->pImage->GetImageType(pimageResource->pImage) )
  {
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, 0, pimageResource);
LABEL_12:
    if ( pimageResource )
    {
      v14 = (Scaleform::GFx::ImageShapeCharacterDef *)this->pHeap->Alloc(this->pHeap, 24, 0);
      if ( v14 )
      {
        Scaleform::GFx::ImageShapeCharacterDef::ImageShapeCharacterDef(v14, pimageResource, v6, bilinear);
        v7 = v15;
        v24 = v15;
      }
      else
      {
        v24 = 0;
      }
      v7->pImage = (Scaleform::Render::ImageBase *)1;
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId)1, v7);
      EnterCriticalSection(&this->PlaylistLock.cs);
      p_Playlist = &this->Playlist;
      Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Playlist.Data,
        this->Header.FrameCount);
      Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->InitActionList.Data,
        this->Header.FrameCount);
      this->InitActionsCnt = 0;
      v17 = (Scaleform::GFx::DataAllocator::Block *)this->TagMemAllocator.pHeap->Alloc(
                                                      this->TagMemAllocator.pHeap,
                                                      120,
                                                      0);
      if ( v17 )
      {
        v18 = v17 + 1;
        v17->pNext = this->TagMemAllocator.pAllocations;
        this->TagMemAllocator.pAllocations = v17;
        if ( v17 != (Scaleform::GFx::DataAllocator::Block *)-4 )
        {
          v19 = v17 + 2;
          if ( v18 != (Scaleform::GFx::DataAllocator::Block *)-4 )
          {
            v19->pNext = (Scaleform::GFx::DataAllocator::Block *)&Scaleform::GFx::GFxPlaceObjectUnpacked::`vftable';
            Scaleform::GFx::CharPosInfo::CharPosInfo((Scaleform::GFx::CharPosInfo *)&v18[5]);
          }
          matrix.M[0][0] = 1.0;
          matrix.M[0][1] = 0.0;
          matrix.M[0][2] = 0.0;
          matrix.M[0][3] = 0.0;
          matrix.M[1][0] = 0.0;
          matrix.M[1][2] = 0.0;
          matrix.M[1][3] = 0.0;
          matrix.M[1][1] = 1.0;
          Scaleform::Render::Cxform::Cxform(&v26);
          Scaleform::GFx::CharPosInfo::CharPosInfo(
            &__that,
            (Scaleform::GFx::ResourceId)1,
            1,
            0,
            v20,
            1,
            &matrix,
            0,
            0.0,
            0,
            0,
            Blend_None);
          Scaleform::GFx::CharPosInfo::operator=((Scaleform::GFx::CharPosInfo *)&v18[5], &__that);
          v18->pNext = v18 + 1;
          p_Playlist->Data.Data->pTagPtrList = (Scaleform::GFx::ExecuteTag **)v18;
          pObject = (Scaleform::RefCountVImpl *)__that.pFilters.pObject;
          p_Playlist->Data.Data->TagCount = 1;
          if ( pObject )
            Scaleform::RefCountImpl::Release(pObject);
        }
        v7 = v24;
      }
      LeaveCriticalSection(&this->PlaylistLock.cs);
      if ( v7 )
        Scaleform::GFx::Resource::Release(v7);
    }
    goto LABEL_25;
  }
  pHeap = this->pHeap;
  CreateImage = imgCreator->CreateImage;
  LODWORD(matrix.M[0][0]) = 1;
  *(_QWORD *)&matrix.M[0][2] = 0x100000001LL;
  LODWORD(matrix.M[0][1]) = pHeap;
  pImage = pimageResource->pImage;
  memset(matrix.M[1], 0, sizeof(matrix.M[1]));
  v11 = CreateImage(
          imgCreator,
          (const Scaleform::GFx::ImageCreateInfo *)&matrix,
          (Scaleform::Render::ImageSource *)pImage);
  if ( v11 )
  {
    v12 = (Scaleform::GFx::ImageResource *)(*(int (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)LODWORD(matrix.M[0][1])
                                                                                      + 40))(
                                             LODWORD(matrix.M[0][1]),
                                             52,
                                             0);
    if ( v12 )
    {
      Scaleform::GFx::ImageResource::ImageResource(v12, v11, Use_Bitmap);
      v7 = v13;
    }
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, 0, v7);
    pimageResource = v7;
    if ( v7 )
      Scaleform::GFx::Resource::Release(v7);
    v11->Release(v11);
    v6 = imgCreator;
    v7 = 0;
    goto LABEL_12;
  }
  pimageResource = 0;
  if ( plog )
    Scaleform::Log::LogError(plog, "Can't create or decode image.");
LABEL_25:
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->Header.FrameCount, LS_LoadFinished);
  return pimageResource != 0;
}
