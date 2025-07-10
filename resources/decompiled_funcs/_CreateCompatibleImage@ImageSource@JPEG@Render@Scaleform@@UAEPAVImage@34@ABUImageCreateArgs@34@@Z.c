void __thiscall Scaleform::Render::JPEG::ImageSource::CreateCompatibleImage(
        Scaleform::Render::JPEG::ImageSource *this,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::JPEG::MemoryBufferImage *v4; // ebp
  Scaleform::Render::ImageUpdateSync *pUpdateSync; // eax
  Scaleform::Render::TextureManager *pManager; // eax
  Scaleform::GFx::Resource *pObject; // ebx
  int v8; // eax
  Scaleform::Render::ImageFormat v9; // eax
  Scaleform::Render::JPEG::MemoryBufferImage *v10; // ebx
  Scaleform::Render::ImageUpdateSync *v11; // eax
  Scaleform::Render::TextureManager *v12; // eax
  int v13; // eax
  Scaleform::Render::ImageFormat v14; // eax
  unsigned int Use; // [esp-1Ch] [ebp-30h]
  unsigned int v16; // [esp-1Ch] [ebp-30h]
  Scaleform::Render::ImageUpdateSync *v17; // [esp-18h] [ebp-2Ch]
  Scaleform::Render::ImageUpdateSync *v18; // [esp-18h] [ebp-2Ch]
  Scaleform::File *v19; // [esp-14h] [ebp-28h]
  Scaleform::File *v20; // [esp-14h] [ebp-28h]
  __int64 FilePos; // [esp-10h] [ebp-24h]
  __int64 v22; // [esp-10h] [ebp-24h]
  unsigned int FileLen; // [esp-8h] [ebp-1Ch]
  unsigned int v24; // [esp-8h] [ebp-1Ch]
  bool WithHeaders; // [esp-4h] [ebp-18h]
  Scaleform::Render::Size<unsigned long> size; // [esp+Ch] [ebp-8h] BYREF

  if ( this->IsDecodeOnlyImageCompatible(this, args) )
  {
    pHeap = args->pHeap;
    if ( this->pExtraData.pObject )
    {
      if ( !pHeap )
        pHeap = Scaleform::Memory::pGlobalHeap;
      v4 = (Scaleform::Render::JPEG::MemoryBufferImage *)pHeap->Alloc(pHeap, 56u, 0);
      if ( v4 )
      {
        pUpdateSync = args->pUpdateSync;
        if ( !pUpdateSync )
        {
          pManager = args->pManager;
          if ( pManager )
            pUpdateSync = &pManager->Scaleform::Render::ImageUpdateSync;
          else
            pUpdateSync = 0;
        }
        pObject = (Scaleform::GFx::Resource *)this->pExtraData.pObject;
        FileLen = this->FileLen;
        FilePos = this->FilePos;
        v19 = this->pFile.pObject;
        v17 = pUpdateSync;
        Use = args->Use;
        v8 = ((int (__thiscall *)(Scaleform::Render::JPEG::ImageSource *))this->GetSize)(this);
        v9 = ((int (__thiscall *)(Scaleform::Render::JPEG::ImageSource *, int))this->GetFormat)(this, v8);
        Scaleform::Render::JPEG::MemoryBufferImage::MemoryBufferImage(
          v4,
          pObject,
          v9,
          &size,
          Use,
          v17,
          v19,
          FilePos,
          FileLen);
      }
    }
    else
    {
      if ( !pHeap )
        pHeap = Scaleform::Memory::pGlobalHeap;
      v10 = (Scaleform::Render::JPEG::MemoryBufferImage *)pHeap->Alloc(pHeap, 56u, 0);
      if ( v10 )
      {
        v11 = args->pUpdateSync;
        if ( !v11 )
        {
          v12 = args->pManager;
          if ( v12 )
            v11 = &v12->Scaleform::Render::ImageUpdateSync;
          else
            v11 = 0;
        }
        WithHeaders = this->WithHeaders;
        v24 = this->FileLen;
        v22 = this->FilePos;
        v20 = this->pFile.pObject;
        v18 = v11;
        v16 = args->Use;
        v13 = ((int (__thiscall *)(Scaleform::Render::JPEG::ImageSource *))this->GetSize)(this);
        v14 = ((int (__thiscall *)(Scaleform::Render::JPEG::ImageSource *, int))this->GetFormat)(this, v13);
        Scaleform::Render::JPEG::MemoryBufferImage::MemoryBufferImage(
          v10,
          v14,
          &size,
          v16,
          v18,
          v20,
          v22,
          v24,
          WithHeaders);
      }
    }
  }
  else
  {
    Scaleform::Render::ImageSource::CreateCompatibleImage(this, args);
  }
}
