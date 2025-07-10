Scaleform::Render::Image *__userpurge Scaleform::GFx::ImageCreator::LoadImageFile@<eax>(
        Scaleform::GFx::ImageCreator *this@<ecx>,
        int a2@<esi>,
        Scaleform::String info,
        Scaleform::String *url)
{
  const Scaleform::GFx::ImageCreateInfo *pData; // ebp
  Scaleform::GFx::ImageFileHandlerRegistry *Size; // ebx
  Scaleform::String *v6; // esi
  Scaleform::Render::TextureManager *pObject; // ecx
  char v8; // al
  Scaleform::String *v9; // eax
  Scaleform::String *v10; // eax
  Scaleform::String *v11; // eax
  Scaleform::RefCountVImpl *v12; // esi
  Scaleform::Render::ImageFileHandlerRegistry *v13; // ebx
  bool v14; // zf
  Scaleform::MemoryHeap *Use; // eax
  Scaleform::Render::ImageUpdateSync *v16; // edx
  int v17; // edi
  int v18; // ebx
  void *v20; // esi
  int v21; // [esp+4h] [ebp-44h]
  Scaleform::Render::ImageFileReader *reader; // [esp+18h] [ebp-30h]
  Scaleform::Render::ImageCreateArgs args; // [esp+1Ch] [ebp-2Ch] BYREF
  Scaleform::FileStat tmp; // [esp+30h] [ebp-18h] BYREF

  pData = (const Scaleform::GFx::ImageCreateInfo *)info.pData;
  Size = (Scaleform::GFx::ImageFileHandlerRegistry *)info.pData[2].Size;
  if ( !Size || !*(_DWORD *)info.pData[1].Data )
    return 0;
  v21 = a2;
  v6 = url;
  Scaleform::String::String(&info, url);
  if ( !Scaleform::String::HasExtension((const char *)((v6->HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    pObject = this->pTextureManager.pObject;
    if ( !pObject )
      goto LABEL_13;
    v8 = ((int (__thiscall *)(Scaleform::Render::TextureManager *, int))pObject->GetTextureFormatSupport)(pObject, v21);
    if ( (v8 & 1) != 0 )
    {
      v9 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, ".dds");
      goto LABEL_12;
    }
    if ( (v8 & 0x28) != 0 )
    {
      v9 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, ".pvr");
LABEL_12:
      Scaleform::String::operator=(&info, v9);
      Scaleform::String::~String((Scaleform::String *)&url);
      if ( Scaleform::SysFile::GetFileStat(&tmp, &info) )
        goto file_detected;
      goto LABEL_13;
    }
    if ( (v8 & 0x10) == 0
      || (v10 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, ".sif"),
          Scaleform::String::operator=(&info, v10),
          Scaleform::String::~String((Scaleform::String *)&url),
          !Scaleform::SysFile::GetFileStat(&tmp, &info)) )
    {
LABEL_13:
      v11 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, ".tga");
      Scaleform::String::operator=(&info, v11);
      Scaleform::String::~String((Scaleform::String *)&url);
    }
  }
file_detected:
  v12 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::FileOpener *, unsigned int, int, int, int))pData->pFileOpener->OpenFile)(
                                      pData->pFileOpener,
                                      (info.HeapTypeBits & 0xFFFFFFFC) + 8,
                                      33,
                                      438,
                                      v21);
  v13 = &Size->Scaleform::Render::ImageFileHandlerRegistry;
  memset(&args.pHeap, 0, 16);
  LODWORD(tmp.ModifyTime) = 0;
  if ( Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(
         v13,
         (Scaleform::Render::ImageFileReader **)&args,
         (Scaleform::File *)v12,
         0,
         0) != ImageFile_Unknown )
  {
    v14 = pData->RUse == Use_FontTexture;
    Use = (Scaleform::MemoryHeap *)pData->Use;
    args.pManager = (Scaleform::Render::TextureManager *)pData->pHeap;
    v16 = (Scaleform::Render::ImageUpdateSync *)reader[3].__vftable;
    args.pHeap = Use;
    args.pUpdateSync = v16;
    if ( v14 )
      LODWORD(tmp.ModifyTime) = 9;
    v17 = (*(int (__thiscall **)(unsigned int, Scaleform::RefCountVImpl *, Scaleform::MemoryHeap **))(*(_DWORD *)args.Use + 20))(
            args.Use,
            v12,
            &args.pHeap);
    if ( v17 )
    {
      v18 = ((int (__thiscall *)(Scaleform::Render::ImageFileReader *, const Scaleform::GFx::ImageCreateInfo *))reader->MatchFormat)(
              reader,
              pData);
      (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 8))(v17);
      if ( v12 )
        Scaleform::RefCountImpl::Release(v12);
      Scaleform::String::~String(&info);
      return (Scaleform::Render::Image *)v18;
    }
  }
  v18 = ((int (__thiscall *)(Scaleform::Render::ImageFileHandlerRegistry *, Scaleform::RefCountVImpl *))v13->ReadImage)(
          v13,
          v12);
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v20 = (void *)(info.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((info.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
    return (Scaleform::Render::Image *)v18;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  return (Scaleform::Render::Image *)v18;
}
