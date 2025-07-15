void __thiscall Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl::Load(
        Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl *this,
        const Scaleform::String *filename,
        Scaleform::GFx::FileOpener *pfo)
{
  Scaleform::File *v4; // eax
  Scaleform::RefCountVImpl *v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // eax
  int FileSize; // ecx

  v4 = pfo->OpenFile(pfo, (filename->HeapTypeBits & 0xFFFFFFFC) + 8, 33, 438);
  v5 = (Scaleform::RefCountVImpl *)v4;
  if ( v4 )
  {
    if ( v4->IsValid(v4) )
    {
      v6 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v5->__vftable[2].~Scaleform::RefCountVImpl)(v5);
      this->FileSize = v6;
      if ( v6 )
      {
        v7 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v6 + 2, 0);
        FileSize = this->FileSize;
        this->pFileData = v7;
        ((void (__thiscall *)(Scaleform::RefCountVImpl *, unsigned __int8 *, int))v5->__vftable[3].AddRef)(
          v5,
          v7,
          FileSize);
        this->pFileData[this->FileSize + 1] = 0;
        this->pFileData[this->FileSize] = 0;
      }
    }
    Scaleform::RefCountImpl::Release(v5);
  }
}
