void __userpurge Scaleform::GFx::AS3::Instances::fl_system::Domain::load(
        Scaleform::GFx::AS3::Instances::fl_system::Domain *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        bool *result,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *fileName)
{
  char v7; // al
  void *v8; // esi
  char v9; // bl
  unsigned int v10; // eax
  unsigned int v11; // edi
  Scaleform::ArrayLH<unsigned char,328,Scaleform::ArrayDefaultPolicy> *p_FileData; // esi
  Scaleform::GFx::AS3::Abc::Reader *v13; // eax
  unsigned __int8 *Data; // esi
  Scaleform::GFx::AS3::Abc::Reader *v15; // ebx
  Scaleform::GFx::AS3::Abc::File *v16; // eax
  Scaleform::GFx::AS3::Abc::File *v17; // eax
  void *v18; // esi
  bool v19; // al
  Scaleform::GFx::AS3::VM *pVM; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // ecx
  Scaleform::GFx::AS3::VM *v23; // esi
  const Scaleform::GFx::AS3::VM::Error *v24; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v26; // [esp+14h] [ebp-28h]
  int v28; // [esp+18h] [ebp-24h]
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> pfile; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::VM::Error v31; // [esp+28h] [ebp-14h] BYREF
  Scaleform::SysFile file; // [esp+30h] [ebp-Ch] BYREF

  *result = 0;
  Scaleform::SysFile::SysFile(&file);
  Scaleform::String::String((Scaleform::String *)&pfile, (char *)fileName->ForEachChild_GC);
  v7 = Scaleform::SysFile::Open(&file, (const Scaleform::String *)&pfile, 33, 438);
  v8 = (void *)((unsigned int)pfile.pObject & 0xFFFFFFFC);
  v9 = v7;
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pfile.pObject & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( v9 )
  {
    v10 = ((int (__thiscall *)(Scaleform::File *, int, int))file.pFile.pObject->GetLength)(file.pFile.pObject, a3, a4);
    v11 = v10;
    p_FileData = &this->FileData;
    if ( v10 >= this->FileData.Data.Size )
    {
      if ( v10 >= this->FileData.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &this->FileData.Data,
          &this->FileData,
          v10 + (v10 >> 2));
    }
    else if ( v10 < this->FileData.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->FileData.Data,
        &this->FileData,
        v10);
    }
    this->FileData.Data.Size = v11;
    if ( (*(int (__thiscall **)(bool *, unsigned __int8 *, unsigned int))(*(_DWORD *)result + 40))(
           result,
           p_FileData->Data.Data,
           v11) == v11 )
    {
      v13 = (Scaleform::GFx::AS3::Abc::Reader *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  8,
                                                  0,
                                                  v26,
                                                  v28,
                                                  a2);
      if ( v13 )
      {
        Data = p_FileData->Data.Data;
        v13->Size = v11;
        v13->CP = Data;
        v15 = v13;
      }
      else
      {
        v15 = 0;
      }
      file.RefCount = 338;
      v16 = (Scaleform::GFx::AS3::Abc::File *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                184,
                                                &file.RefCount);
      if ( v16 )
        Scaleform::GFx::AS3::Abc::File::File(v16);
      else
        v17 = 0;
      pfile.pObject = v17;
      Scaleform::String::String((Scaleform::String *)&fileName, (char *)fileName->ForEachChild_GC);
      Scaleform::String::operator=(&pfile.pObject->Source, (const Scaleform::String *)&fileName);
      v18 = (void *)((unsigned int)fileName & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)fileName & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
      pfile.pObject->DataSize = v11;
      v19 = Scaleform::GFx::AS3::Abc::Reader::Read(v15, pfile.pObject);
      *result = v19;
      if ( v19 )
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
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v22 = fileName;
              fileName->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
            }
          }
        }
        Scaleform::GFx::AS3::VM::AddFile(pVM, &pfile);
      }
      if ( pfile.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfile.pObject);
      if ( v15 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
    }
  }
  else
  {
    v23 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eFileOpenError, v23);
    Scaleform::GFx::AS3::VM::ThrowError(v23, v24);
    pNode = v31.Message.pNode;
    --v31.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( file.pFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)file.pFile.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&file);
}
