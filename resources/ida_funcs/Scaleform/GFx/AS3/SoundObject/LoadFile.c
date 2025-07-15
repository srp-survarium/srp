void __userpurge Scaleform::GFx::AS3::SoundObject::LoadFile(
        Scaleform::GFx::AS3::SoundObject *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        const Scaleform::String *url,
        bool streaming,
        Scaleform::String *src,
        int a7)
{
  Scaleform::GFx::InteractiveObject *v8; // eax
  Scaleform::RefCountVImpl *v9; // edi
  int v10; // ebx
  Scaleform::GFx::LoadStates *v11; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  Scaleform::GFx::StateBagImpl *pObject; // edi
  Scaleform::GFx::StateBag *v14; // edi
  unsigned int v15; // eax
  Scaleform::GFx::LoadStates *v16; // ebp
  Scaleform::Sound::SoundSample *v17; // ebx
  Scaleform::Sound::SoundSample *v18; // edi
  Scaleform::GFx::SoundResource *v19; // ecx
  Scaleform::String fileName; // [esp+1Ch] [ebp-18h]
  Scaleform::String level0Path; // [esp+20h] [ebp-14h]
  Scaleform::GFx::Sprite *psprite; // [esp+24h] [ebp-10h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo locInfo; // [esp+28h] [ebp-Ch] BYREF
  Scaleform::String retaddr; // [esp+34h] [ebp+0h] BYREF

  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter(this->pTargetHandle.pObject, this->pMovieRoot);
  if ( v8 )
  {
    if ( ((v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
        ? (unsigned int)v8
        : 0) != 0 )
    {
      v9 = (Scaleform::RefCountVImpl *)this->pMovieRoot->GetStateAddRef(&this->pMovieRoot->Scaleform::GFx::StateBag, 29);
      if ( v9 )
      {
        v10 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v9->AddRef)(v9);
        Scaleform::RefCountImpl::Release(v9);
        if ( v10 )
        {
          Scaleform::GFx::AS3::Instances::fl_media::Sound::DispatchEventOpen(this->pSound.pObject);
          v11 = (Scaleform::GFx::LoadStates *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                80,
                                                0,
                                                a3,
                                                a2);
          if ( v11 )
          {
            pMovieRoot = this->pMovieRoot;
            pObject = pMovieRoot->pStateBag.pObject;
            if ( pObject )
              v14 = &pObject->Scaleform::GFx::StateBag;
            else
              v14 = 0;
            Scaleform::GFx::LoadStates::LoadStates(
              v11,
              (Scaleform::GFx::Resource *)pMovieRoot->pMainMovieDef.pObject->pLoaderImpl.pObject,
              v14,
              0);
            v16 = (Scaleform::GFx::LoadStates *)v15;
            locInfo.FileName.HeapTypeBits = v15;
          }
          else
          {
            locInfo.FileName.HeapTypeBits = 0;
            v16 = 0;
          }
          Scaleform::String::String((Scaleform::String *)&locInfo);
          Scaleform::GFx::MovieImpl::GetMainMoviePath(this->pMovieRoot, (Scaleform::String *)&locInfo);
          locInfo.ParentPath.HeapTypeBits = 0;
          Scaleform::String::String(&retaddr, src);
          Scaleform::String::String((Scaleform::String *)&url, (const Scaleform::String *)&locInfo);
          Scaleform::String::String((Scaleform::String *)&psprite);
          Scaleform::GFx::LoadStates::BuildURL(
            v16,
            (Scaleform::String *)&psprite,
            (const Scaleform::GFx::URLBuilder::LocationInfo *)&locInfo.ParentPath);
          v17 = (Scaleform::Sound::SoundSample *)(*(int (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v10 + 8))(
                                                   v10,
                                                   ((unsigned int)psprite & 0xFFFFFFFC) + 8,
                                                   a7);
          if ( v17 )
          {
            InterlockedExchangeAdd(&v17->RefCount.Value, 1);
            v18 = this->pSample.pObject;
            if ( v18 && InterlockedExchangeAdd(&v18->RefCount.Value, -1) == 1 )
              ((void (__thiscall *)(Scaleform::Sound::SoundSample *, int))v18->~Scaleform::Sound::SoundSample)(v18, 1);
            this->pSample.pObject = v17;
            v19 = this->pResource.pObject;
            if ( v19 )
              Scaleform::GFx::Resource::Release(v19);
            this->pResource.pObject = 0;
            Scaleform::GFx::AS3::Instances::fl_media::Sound::DispatchEventComplete(this->pSound.pObject);
            if ( InterlockedExchangeAdd(&v17->RefCount.Value, -1) == 1 )
              ((void (__thiscall *)(Scaleform::Sound::SoundSample *, int))v17->~Scaleform::Sound::SoundSample)(v17, 1);
            if ( InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
              Scaleform::Memory::pGlobalHeap->Free(
                Scaleform::Memory::pGlobalHeap,
                (void *)(fileName.HeapTypeBits & 0xFFFFFFFC));
            Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&locInfo);
            if ( InterlockedExchangeAdd((volatile LONG *)((level0Path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
              Scaleform::Memory::pGlobalHeap->Free(
                Scaleform::Memory::pGlobalHeap,
                (void *)(level0Path.HeapTypeBits & 0xFFFFFFFC));
            if ( psprite )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)psprite);
          }
          else
          {
            Scaleform::GFx::AS3::Instances::fl_media::Sound::DispatchEventIOError(this->pSound.pObject);
            if ( InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
              Scaleform::Memory::pGlobalHeap->Free(
                Scaleform::Memory::pGlobalHeap,
                (void *)(fileName.HeapTypeBits & 0xFFFFFFFC));
            Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&locInfo);
            if ( InterlockedExchangeAdd((volatile LONG *)((level0Path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
              Scaleform::Memory::pGlobalHeap->Free(
                Scaleform::Memory::pGlobalHeap,
                (void *)(level0Path.HeapTypeBits & 0xFFFFFFFC));
            if ( v16 )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v16);
          }
        }
      }
    }
  }
}
