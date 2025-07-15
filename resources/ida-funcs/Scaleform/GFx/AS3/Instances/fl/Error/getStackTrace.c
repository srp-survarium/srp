void __thiscall Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // edi
  const __m128i *v4; // ecx
  void *v5; // esi

  v2 = result;
  Scaleform::GFx::AS3::Instances::fl::Error::toStringProto(this, result);
  v4 = (const __m128i *)((Scaleform::operator+((Scaleform::String *)&result, (const __m128i *)"\n", &this->StackTrace)->HeapTypeBits
                        & 0xFFFFFFFC)
                       + 8);
  Scaleform::GFx::ASString::Append(v2, v4, (Scaleform::GFx::ASStringNode *)strlen(v4->m128i_i8));
  v5 = (void *)((unsigned int)result & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)result & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
}
