Scaleform::GFx::AS3::ASVM *__userpurge Scaleform::GFx::AS3::ASVM::`vector deleting destructor'@<eax>(
        Scaleform::GFx::AS3::ASVM *this@<ecx>,
        int a2@<edi>,
        char a3)
{
  Scaleform::GFx::AS3::ASVM::~ASVM(this, a2);
  if ( (a3 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
