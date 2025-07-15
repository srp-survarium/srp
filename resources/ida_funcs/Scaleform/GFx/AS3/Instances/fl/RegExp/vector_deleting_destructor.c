Scaleform::GFx::AS3::Instances::fl::RegExp *__thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        char a2)
{
  volatile LONG *v3; // edi
  struct real_pcre *CompRegExp; // [esp-4h] [ebp-Ch]

  CompRegExp = this->CompRegExp;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::RegExp_vtbl *)&Scaleform::GFx::AS3::Instances::fl::RegExp::`vftable';
  pcre_free(CompRegExp);
  v3 = (volatile LONG *)(this->Pattern.HeapTypeBits & 0xFFFFFFFC);
  this->CompRegExp = 0;
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
