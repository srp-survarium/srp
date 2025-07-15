void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::InitClassName(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        const __m128i *className)
{
  unsigned int v3; // kr00_4
  const char *v4; // edi

  if ( !this->pClassName )
  {
    v3 = strlen(className->m128i_i8);
    v4 = (const char *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                         Scaleform::Memory::pGlobalHeap,
                         this->pDispObj,
                         v3 + 1,
                         0);
    memcpy((int)v4, className, v3 + 1);
    this->pClassName = v4;
  }
}
