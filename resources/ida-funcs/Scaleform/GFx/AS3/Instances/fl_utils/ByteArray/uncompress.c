void __userpurge Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::uncompress(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned __int8 *Length; // edi
  unsigned __int8 *v8; // ebx
  const __m128i *v9; // ebx
  int v10; // eax
  unsigned int v11; // edi
  unsigned int Position; // ecx
  int v13; // ebp
  unsigned int v14; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  const __m128i *Data; // [esp+10h] [ebp-50h]
  unsigned __int8 *zdata; // [esp+20h] [ebp-40h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [esp+24h] [ebp-3Ch]
  Scaleform::GFx::AS3::ZStream zstream; // [esp+28h] [ebp-38h] BYREF

  Length = (unsigned __int8 *)this->Length;
  if ( Length )
  {
    v8 = (unsigned __int8 *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned __int8 *, _DWORD, int, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              Length,
                              0,
                              a3,
                              a2);
    Data = (const __m128i *)this->Data.Data.Data;
    zstream.Stream.next_in = v8;
    memcpy((int)v8, Data, (unsigned int)Length);
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, 0);
    memset((int)&zstream.Stream.total_in, 0, sizeof(Scaleform::GFx::AS3::ZStream));
    inflateInit_((z_stream_s *)&zstream.Stream.total_in, "1.2.7", 56);
    zstream.Stream.total_in = (unsigned int)v8;
    zstream.Stream.next_out = Length;
    v9 = (const __m128i *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 0x2000, 0);
    do
    {
      zstream.Stream.total_out = (unsigned int)v9;
      zstream.Stream.msg = (char *)0x2000;
      v10 = inflate((z_stream_s *)&zstream.Stream.total_in, 0);
      v11 = 0x2000 - (unsigned int)zstream.Stream.msg;
      Position = this->Position;
      v13 = v10;
      v14 = Position + 0x2000 - (unsigned int)zstream.Stream.msg;
      if ( v14 < this->Data.Data.Size )
      {
        if ( v14 >= this->Length )
          this->Length = v14;
      }
      else
      {
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, Position + v11);
      }
      memcpy((int)&this->Data.Data.Data[this->Position], v9, v11);
      this->Position += v11;
    }
    while ( !v13 );
    ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
    this->Position = 0;
    if ( v13 != 1 )
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&zdata, eShellCompressedDataError, pVM);
      Scaleform::GFx::AS3::VM::ThrowError(pVM, v16);
      v17 = v20;
      --v20->RefCount;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
    inflateEnd(&zstream.Stream);
  }
}
