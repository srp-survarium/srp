void __thiscall Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        unsigned __int8 *start)
{
  Scaleform::HeapMH::MagicHeader *v3; // eax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+4h] [ebp-1Ch] BYREF

  Scaleform::HeapMH::GetMagicHeaders((unsigned int)start, &headers);
  if ( headers.Header1 )
    Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, headers.AlignedStart);
  if ( headers.Header2 )
  {
    v3 = headers.Header2 + 1;
    if ( headers.BitSet > (unsigned int *)headers.Bound )
      v3 = headers.Header2 + 5;
    Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, (unsigned __int8 *)v3);
  }
}
