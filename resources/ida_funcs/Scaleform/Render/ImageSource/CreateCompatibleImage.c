Scaleform::Render::RawImage *__userpurge Scaleform::Render::ImageSource::CreateCompatibleImage@<eax>(
        Scaleform::Render::ImageSource *this@<ecx>,
        const Scaleform::Render::ImageCreateArgs *args,
        int a3,
        int a4,
        int a5)
{
  Scaleform::Render::ImageFormat v6; // eax
  Scaleform::Render::TextureManager *pManager; // eax
  Scaleform::MemoryHeap *pHeap; // eax
  unsigned int Use; // ebp
  unsigned int v11; // ebx
  __int16 v12; // ax
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(struct Scaleform::Render::ImageSource *, Scaleform::Render::Size<unsigned long> *); // edx
  int v14; // eax
  Scaleform::GFx::Resource *v15; // edi
  Scaleform::Render::TextureImage *v16; // ebx
  const Scaleform::Render::Size<unsigned long> *v17; // eax
  int v18; // eax
  int v19; // esi
  const Scaleform::Render::Size<unsigned long> *v21; // eax
  Scaleform::Render::RawImage *v22; // edi
  Scaleform::Render::ImageUpdateSync *updateSync; // [esp+28h] [ebp-40h]
  Scaleform::MemoryHeap *heap; // [esp+2Ch] [ebp-3Ch]
  Scaleform::Render::TextureManager_vtbl *v25; // [esp+30h] [ebp-38h] BYREF
  _BYTE v26[4]; // [esp+38h] [ebp-30h] BYREF
  int v27; // [esp+3Ch] [ebp-2Ch]
  Scaleform::Render::ImageData rawData; // [esp+40h] [ebp-28h] BYREF
  Scaleform::Render::ImageFormat format; // [esp+6Ch] [ebp+4h]

  v6 = args->Format;
  if ( v6 == Image_None )
    v6 = this->GetFormat(this);
  format = v6;
  if ( args->pUpdateSync )
  {
    updateSync = args->pUpdateSync;
  }
  else
  {
    pManager = args->pManager;
    if ( pManager )
      updateSync = &pManager->Scaleform::Render::ImageUpdateSync;
    else
      updateSync = 0;
  }
  pHeap = args->pHeap;
  if ( !pHeap )
    pHeap = Scaleform::Memory::pGlobalHeap;
  Use = args->Use;
  heap = pHeap;
  v11 = this->GetMipmapCount(this);
  if ( v11 > 1 )
    Use &= ~2u;
  if ( !args->pManager
    || (v12 = args->pManager->GetTextureUseCaps(args->pManager, format),
        (args->Use & (unsigned __int8)~(_BYTE)v12 & 0xC0) != 0)
    || (v12 & 0x100) == 0
    || (Use |= 0x100u, !args->pManager->CanCreateTextureCurrentThread(args->pManager)) )
  {
    v21 = this->GetSize(this, v26);
    v22 = Scaleform::Render::RawImage::Create(format, v11, v21, Use, heap, updateSync);
    if ( v22 )
    {
      rawData.RawPlaneCount = 1;
      memset(&rawData, 0, 10);
      rawData.pPlanes = &rawData.Plane0;
      memset(&rawData.pPalette, 0, 24);
      Scaleform::Render::ImageData::operator=(&rawData, &v22->Data);
      if ( this->Decode(
             this,
             &rawData,
             (void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *))Scaleform::Render::ImageBase::CopyScanlineDefault,
             0) )
      {
        Scaleform::Render::ImageData::~ImageData(&rawData);
        return v22;
      }
      v22->Release(v22);
      Scaleform::Render::ImageData::~ImageData(&rawData);
    }
    return 0;
  }
  GetSize = this->GetSize;
  v25 = args->pManager->__vftable;
  v14 = ((int (__thiscall *)(Scaleform::Render::ImageSource *, _BYTE *, unsigned int, Scaleform::Render::ImageSource *, _DWORD))GetSize)(
          this,
          v26,
          Use,
          this,
          0);
  v15 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(Scaleform::Render::TextureManager *, int, unsigned int, int))(v27 + 4))(
                                      args->pManager,
                                      a5,
                                      v11,
                                      v14);
  if ( !v15 )
    return 0;
  v16 = (Scaleform::Render::TextureImage *)heap->Alloc(heap, 36u, 0);
  if ( v16 )
  {
    v17 = this->GetSize(this, &v25);
    Scaleform::Render::TextureImage::TextureImage(v16, format, v17, Use, v15, updateSync);
    v19 = v18;
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v15);
    return (Scaleform::Render::RawImage *)v19;
  }
  else
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v15);
    return 0;
  }
}
