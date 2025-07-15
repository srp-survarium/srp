void __thiscall Scaleform::GFx::MovieDataDef::MovieDataDef(
        Scaleform::GFx::MovieDataDef *this,
        const Scaleform::GFx::ResourceKey *creationKey,
        Scaleform::GFx::MovieDataDef::MovieDataType mtype,
        char *purl,
        Scaleform::MemoryHeap *pargHeap,
        bool debugHeap,
        unsigned int memoryArena)
{
  Scaleform::MemoryHeap *v8; // ebx
  const __m128i *ShortFilename; // eax
  Scaleform::MemoryHeap *v10; // eax
  void *v11; // edi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v12; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v13; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v14; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::String v16; // [esp+10h] [ebp-24h] BYREF
  _DWORD v17[8]; // [esp+14h] [ebp-20h] BYREF

  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDataDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->Id.Id = 0x40000;
  this->Scaleform::GFx::ResourceReport::__vftable = (Scaleform::GFx::ResourceReport_vtbl *)&Scaleform::GFx::ResourceReport::`vftable';
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDataDef_vtbl *)&Scaleform::GFx::MovieDataDef::`vftable'{for `Scaleform::GFx::TimelineDef'};
  this->Scaleform::GFx::ResourceReport::__vftable = (Scaleform::GFx::ResourceReport_vtbl *)&Scaleform::GFx::MovieDataDef::`vftable'{for `Scaleform::GFx::ResourceReport'};
  Scaleform::GFx::ResourceKey::ResourceKey(&this->mResourceKey, creationKey);
  v8 = pargHeap;
  this->MovieType = mtype;
  this->pData.pObject = 0;
  if ( !pargHeap )
  {
    ShortFilename = (const __m128i *)Scaleform::GetShortFilename(purl);
    Scaleform::String::String(&v16, (const __m128i *)"MovieData \"", ShortFilename, (const __m128i *)"\"");
    v17[0] = (debugHeap ? 0x1000 : 0) | 4;
    v17[5] = 0;
    v17[3] = 0;
    v17[1] = 16;
    v17[4] = -1;
    v17[2] = 0x2000;
    v17[6] = 4;
    v17[7] = memoryArena;
    v10 = Scaleform::Memory::pGlobalHeap->CreateHeap(
            Scaleform::Memory::pGlobalHeap,
            (v16.HeapTypeBits & 0xFFFFFFFC) + 8,
            v17);
    v11 = (void *)(v16.HeapTypeBits & 0xFFFFFFFC);
    v8 = v10;
    if ( InterlockedExchangeAdd((volatile LONG *)((v16.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  }
  v12 = (Scaleform::GFx::MovieDataDef::LoadTaskData *)v8->Alloc(v8, 336u, 0);
  if ( v12 )
  {
    Scaleform::GFx::MovieDataDef::LoadTaskData::LoadTaskData(v12, this, (Scaleform::GFx::Resource *)purl, v8);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pData.pObject = v14;
  if ( !pargHeap )
    Scaleform::MemoryHeap::ReleaseOnFree(v8, v14);
}
