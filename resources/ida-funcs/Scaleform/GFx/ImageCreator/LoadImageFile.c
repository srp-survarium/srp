Scaleform::Render::Image *__userpurge Scaleform::GFx::ImageCreator::LoadImageFile@<eax>(
        Scaleform::GFx::ImageCreator *this@<ecx>,
        int a2@<esi>,
        Scaleform::String info,
        Scaleform::String *url)
{
  Scaleform::String::DataDesc *pData; // ebp
  unsigned int Size; // ebx
  Scaleform::String *v6; // esi
  Scaleform::Render::TextureManager *pObject; // ecx
  char v8; // al
  Scaleform::String *v9; // eax
  Scaleform::String *v10; // eax
  Scaleform::String *v11; // eax
  Scaleform::File *v12; // esi
  Scaleform::Render::ImageFileHandlerRegistry *v13; // ebx
  bool v14; // zf
  int v15; // eax
  int v16; // edx
  Scaleform::Render::ImageSource *v17; // edi
  int v18; // ebx
  void *v20; // esi
  int v21; // [esp+4h] [ebp-44h]
  _DWORD *v23; // [esp+18h] [ebp-30h]
  Scaleform::Render::ImageFileReader *preader; // [esp+1Ch] [ebp-2Ch] BYREF
  int v25; // [esp+20h] [ebp-28h] BYREF
  volatile int RefCount; // [esp+24h] [ebp-24h]
  int v27; // [esp+28h] [ebp-20h]
  int v28; // [esp+2Ch] [ebp-1Ch]
  Scaleform::FileStat pfileStat; // [esp+30h] [ebp-18h] BYREF

  pData = info.pData;
  Size = info.pData[2].Size;
  if ( !Size || !*(_DWORD *)info.pData[1].Data )
    return 0;
  v21 = a2;
  v6 = url;
  Scaleform::String::String(&info, url);
  if ( !Scaleform::String::HasExtension((char *)((v6->HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    pObject = this->pTextureManager.pObject;
    if ( !pObject )
      goto LABEL_13;
    v8 = ((int (__thiscall *)(Scaleform::Render::TextureManager *, int))pObject->GetTextureFormatSupport)(pObject, v21);
    if ( (v8 & 1) != 0 )
    {
      v9 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, (const __m128i *)".dds");
      goto LABEL_12;
    }
    if ( (v8 & 0x28) != 0 )
    {
      v9 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, (const __m128i *)".pvr");
LABEL_12:
      Scaleform::String::operator=(&info, v9);
      Scaleform::String::~String((Scaleform::String *)&url);
      if ( Scaleform::SysFile::GetFileStat(&pfileStat, &info) )
        goto file_detected;
      goto LABEL_13;
    }
    if ( (v8 & 0x10) == 0
      || (v10 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, (const __m128i *)".sif"),
          Scaleform::String::operator=(&info, v10),
          Scaleform::String::~String((Scaleform::String *)&url),
          !Scaleform::SysFile::GetFileStat(&pfileStat, &info)) )
    {
LABEL_13:
      v11 = Scaleform::String::operator+(v6, (Scaleform::String *)&url, (const __m128i *)".tga");
      Scaleform::String::operator=(&info, v11);
      Scaleform::String::~String((Scaleform::String *)&url);
    }
  }
file_detected:
  v12 = (Scaleform::File *)(*(int (__thiscall **)(_DWORD, unsigned int, int, int, int))(**(_DWORD **)pData[1].Data + 4))(
                             *(_DWORD *)pData[1].Data,
                             (info.HeapTypeBits & 0xFFFFFFFC) + 8,
                             33,
                             438,
                             v21);
  v13 = (Scaleform::Render::ImageFileHandlerRegistry *)(Size + 12);
  v25 = 0;
  RefCount = 0;
  v27 = 0;
  v28 = 0;
  LODWORD(pfileStat.ModifyTime) = 0;
  if ( Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(v13, &preader, v12, 0, 0) != 1 )
  {
    v14 = pData[1].Size == 3;
    v15 = *(_DWORD *)pData->Data;
    RefCount = pData->RefCount;
    v16 = v23[3];
    v25 = v15;
    v27 = v16;
    if ( v14 )
      LODWORD(pfileStat.ModifyTime) = 9;
    v17 = preader->ReadImageSource(preader, v12, &v25);
    if ( v17 )
    {
      v18 = (*(int (__thiscall **)(_DWORD *, Scaleform::String::DataDesc *))(*v23 + 16))(v23, pData);
      v17->Release(v17);
      if ( v12 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
      Scaleform::String::~String(&info);
      return (Scaleform::Render::Image *)v18;
    }
  }
  v18 = ((int (__thiscall *)(Scaleform::Render::ImageFileHandlerRegistry *, Scaleform::File *))v13->ReadImage)(v13, v12);
  if ( v12 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
  v20 = (void *)(info.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((info.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
    return (Scaleform::Render::Image *)v18;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  return (Scaleform::Render::Image *)v18;
}
