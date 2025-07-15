Scaleform::Render::Image *__thiscall Scaleform::GFx::ImageCreator::LoadExportedImage(
        Scaleform::GFx::ImageCreator *this,
        const Scaleform::GFx::ImageCreateExportInfo *info,
        Scaleform::String url)
{
  Scaleform::String *pData; // ebp
  Scaleform::Render::Image *v5; // eax
  Scaleform::String *Extension; // eax
  Scaleform::String *v7; // eax
  bool v8; // al
  void *v9; // esi
  void *v10; // esi
  Scaleform::Render::Image *v11; // edi
  void *v12; // esi
  Scaleform::String v13; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::String v14; // [esp+10h] [ebp-8h] BYREF
  Scaleform::Render::Image *result; // [esp+14h] [ebp-4h]

  pData = (Scaleform::String *)url.pData;
  v5 = this->LoadImageFile(this, info, url.pData);
  result = v5;
  if ( !v5 )
  {
    if ( Scaleform::String::HasExtension((const char *)((pData->HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
      Extension = Scaleform::String::GetExtension(pData, &v14);
      v7 = Scaleform::String::ToLower(Extension, &v13);
      v8 = Scaleform::String::operator!=(v7, ".dds");
      v9 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
      LOBYTE(url.pData) = v8;
      if ( InterlockedExchangeAdd((volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
      v10 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
      if ( LOBYTE(url.pData) )
      {
        Scaleform::String::String(&url, pData);
        Scaleform::String::StripExtension(&url);
        Scaleform::String::AppendString(&url, ".dds", 0xFFFFFFFF);
        v11 = this->LoadImageFile(this, info, &url);
        v12 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
        return v11;
      }
      else
      {
        return result;
      }
    }
    else
    {
      return 0;
    }
  }
  return v5;
}
