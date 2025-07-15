char __thiscall Scaleform::GFx::AMP::MessageCompressed::Uncompress(
        Scaleform::GFx::AMP::MessageCompressed *this,
        Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *uncompressedData)
{
  unsigned int Size; // eax
  unsigned __int8 *Data; // ecx
  unsigned int v5; // ebx
  unsigned int v6; // edi
  unsigned __int8 *v7; // edx
  z_stream_s strm; // [esp+0h] [ebp-38h] BYREF

  Size = this->CompressedData.Data.Size;
  strm.opaque = this;
  Data = this->CompressedData.Data.Data;
  strm.zalloc = Scaleform::GFx::AMP::ZLibAllocFunc_AMP;
  strm.zfree = Scaleform::GFx::AMP::ZLibFreeFunc_AMP;
  strm.avail_in = Size;
  strm.next_in = Data;
  if ( inflateInit_(&strm, "1.2.7", 56) )
    return 0;
  v5 = 0;
  do
  {
    v6 = v5 + 1024;
    if ( v5 + 1024 >= uncompressedData->Size )
    {
      if ( v6 >= uncompressedData->Policy.Capacity )
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          uncompressedData,
          uncompressedData,
          v6 + (v6 >> 2));
    }
    else if ( v6 < uncompressedData->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        uncompressedData,
        uncompressedData,
        v5 + 1024);
    }
    v7 = (unsigned __int8 *)&uncompressedData->Data[v5];
    uncompressedData->Size = v6;
    strm.avail_out = 1024;
    strm.next_out = v7;
    inflate(&strm, 0);
    v5 += 1024 - strm.avail_out;
  }
  while ( !strm.avail_out );
  if ( v5 >= uncompressedData->Size )
  {
    if ( v5 >= uncompressedData->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        uncompressedData,
        uncompressedData,
        v5 + (v5 >> 2));
  }
  else if ( v5 < uncompressedData->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      uncompressedData,
      uncompressedData,
      v5);
  }
  uncompressedData->Size = v5;
  inflateEnd(&strm);
  return 1;
}
