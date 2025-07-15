char __userpurge Scaleform::GFx::AMP::Message::Compress@<al>(
        Scaleform::GFx::AMP::Message *this@<ecx>,
        int a2@<esi>,
        Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *compressedData)
{
  Scaleform::GFx::AMP::AmpStream *v5; // eax
  unsigned __int8 *v6; // eax
  Scaleform::GFx::AS3::SoundObject *v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  int v12; // [esp+10h] [ebp-43Ch] BYREF
  z_stream_s strm; // [esp+14h] [ebp-438h] BYREF
  _BYTE v14[1024]; // [esp+4Ch] [ebp-400h] BYREF

  strm.zalloc = Scaleform::GFx::AMP::ZLibAllocFunc_AMP;
  strm.zfree = Scaleform::GFx::AMP::ZLibFreeFunc_AMP;
  strm.opaque = this;
  if ( deflateInit_(&strm, 1, "1.2.7", 56) )
    return 0;
  v12 = 2;
  v5 = (Scaleform::GFx::AMP::AmpStream *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AMP::Message *, int, int *, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &v12,
                                           a2);
  if ( v5 )
  {
    Scaleform::GFx::AMP::AmpStream::AmpStream(v5);
    v7 = (Scaleform::GFx::AS3::SoundObject *)v6;
    strm.next_in = v6;
  }
  else
  {
    strm.next_in = 0;
    v7 = 0;
  }
  ((void (__thiscall *)(Scaleform::GFx::AMP::Message *))this->Write)(this);
  strm.avail_in = Scaleform::SysAllocPagedMalloc::GetUsedSpace(v7);
  strm.next_in = (unsigned __int8 *)Scaleform::Render::Renderer2D::GetContextNotify(v7);
  do
  {
    strm.avail_out = 1024;
    strm.next_out = v14;
    deflate(&strm, 4);
    v8 = 1024 - strm.avail_out;
    v9 = 0;
    if ( 1024 != strm.avail_out )
    {
      do
      {
        v10 = compressedData->Size + 1;
        if ( v10 >= compressedData->Size )
        {
          if ( v10 >= compressedData->Policy.Capacity )
            Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              compressedData,
              compressedData,
              v10 + (v10 >> 2));
        }
        else if ( v10 < compressedData->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            compressedData,
            compressedData,
            compressedData->Size + 1);
        }
        v11 = &compressedData->Data[v10 - 1];
        compressedData->Size = v10;
        if ( v11 )
          *v11 = v14[v9];
        ++v9;
      }
      while ( v9 < v8 );
      v7 = (Scaleform::GFx::AS3::SoundObject *)v12;
    }
  }
  while ( !strm.avail_out );
  deflateEnd(&strm);
  if ( v7 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
  return 1;
}
