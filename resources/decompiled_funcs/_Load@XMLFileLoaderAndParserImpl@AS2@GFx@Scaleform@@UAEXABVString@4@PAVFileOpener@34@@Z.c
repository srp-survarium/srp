void __thiscall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::Load(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        const Scaleform::String *filename,
        Scaleform::GFx::FileOpener *pfo)
{
  Scaleform::File *v4; // eax
  Scaleform::RefCountVImpl *v5; // esi
  int v6; // eax
  unsigned __int8 *v7; // eax
  int FileLength; // ecx

  v4 = pfo->OpenFile(pfo, (filename->HeapTypeBits & 0xFFFFFFFC) + 8, 33, 438);
  v5 = (Scaleform::RefCountVImpl *)v4;
  if ( v4 )
  {
    if ( v4->IsValid(v4) )
    {
      v6 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v5->__vftable[2].~Scaleform::RefCountVImpl)(v5);
      this->FileLength = v6;
      if ( v6 )
      {
        v7 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v6, 0);
        FileLength = this->FileLength;
        this->pFileData = v7;
        ((void (__thiscall *)(Scaleform::RefCountVImpl *, unsigned __int8 *, int))v5->__vftable[3].AddRef)(
          v5,
          v7,
          FileLength);
      }
    }
    Scaleform::RefCountImpl::Release(v5);
  }
}
