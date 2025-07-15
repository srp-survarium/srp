void __thiscall Scaleform::GFx::AS3::Instances::fl_system::Domain::load(
        Scaleform::GFx::AS3::Instances::fl_system::Domain *this,
        bool *result,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *fileName)
{
  char v4; // al
  void *v5; // esi
  char v6; // bl
  unsigned int v7; // eax
  unsigned int v8; // edi
  Scaleform::ArrayLH<unsigned char,328,Scaleform::ArrayDefaultPolicy> *p_FileData; // esi
  Scaleform::File *pObject; // ecx
  Scaleform::GFx::AS3::Abc::Reader *v11; // eax
  unsigned __int8 *Data; // esi
  Scaleform::GFx::AS3::Abc::Reader *v13; // ebx
  Scaleform::GFx::AS3::Abc::File *v14; // eax
  Scaleform::GFx::AS3::Abc::File *v15; // eax
  void *v16; // esi
  bool v17; // al
  Scaleform::GFx::AS3::VM *pVM; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // ecx
  const Scaleform::GFx::AS3::VM::Error *v21; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v23; // [esp+Ch] [ebp-30h]
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> pfile; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::VM::Error v25; // [esp+28h] [ebp-14h] BYREF
  Scaleform::SysFile file; // [esp+30h] [ebp-Ch] BYREF

  *result = 0;
  Scaleform::SysFile::SysFile(&file);
  Scaleform::String::String((Scaleform::String *)&pfile, (const __m128i *)fileName->ForEachChild_GC);
  v4 = Scaleform::SysFile::Open(&file, (const Scaleform::String *)&pfile, 33, 438);
  v5 = (void *)((unsigned int)pfile.pObject & 0xFFFFFFFC);
  v6 = v4;
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pfile.pObject & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  if ( v6 )
  {
    v7 = file.pFile.pObject->GetLength(file.pFile.pObject);
    v8 = v7;
    p_FileData = &this->FileData;
    if ( v7 >= this->FileData.Data.Size )
    {
      if ( v7 >= this->FileData.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &this->FileData.Data,
          &this->FileData,
          v7 + (v7 >> 2));
    }
    else if ( v7 < this->FileData.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->FileData.Data,
        &this->FileData,
        v7);
    }
    pObject = file.pFile.pObject;
    this->FileData.Data.Size = v8;
    if ( pObject->Read(pObject, p_FileData->Data.Data, v8) == v8 )
    {
      v11 = (Scaleform::GFx::AS3::Abc::Reader *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  8,
                                                  0);
      if ( v11 )
      {
        Data = p_FileData->Data.Data;
        v11->Size = v8;
        v11->CP = Data;
        v13 = v11;
      }
      else
      {
        v13 = 0;
      }
      v25.ID = 338;
      v14 = (Scaleform::GFx::AS3::Abc::File *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                192,
                                                &v25);
      if ( v14 )
        Scaleform::GFx::AS3::Abc::File::File(v14);
      else
        v15 = 0;
      pfile.pObject = v15;
      Scaleform::String::String((Scaleform::String *)&fileName, (const __m128i *)fileName->ForEachChild_GC);
      Scaleform::String::operator=(&pfile.pObject->Source, (const Scaleform::String *)&fileName);
      v16 = (void *)((unsigned int)fileName & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)fileName & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
      pfile.pObject->DataSize = v8;
      v17 = Scaleform::GFx::AS3::Abc::Reader::Read(v13, pfile.pObject);
      *result = v17;
      if ( v17 )
      {
        pVM = this->pTraits.pObject->pVM;
        Scaleform::GFx::AS3::VM::LoadFile(
          pVM,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&fileName,
          &pfile,
          this->VMDomain,
          0);
        if ( fileName )
        {
          if ( ((unsigned __int8)fileName & 1) == 0 )
          {
            RefCount = fileName->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v20 = fileName;
              fileName->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
            }
          }
        }
        Scaleform::GFx::AS3::VM::AddFile(pVM, &pfile);
      }
      if ( pfile.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile.pObject);
      if ( v13 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
    }
  }
  else
  {
    v23.pStr = "Unable to load file";
    v23.Size = 19;
    Scaleform::GFx::AS3::VM::Error::Error(&v25, eFileOpenError, this->pTraits.pObject->pVM, v23);
    Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v21);
    pNode = v25.Message.pNode;
    --v25.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( file.pFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)file.pFile.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&file);
}
