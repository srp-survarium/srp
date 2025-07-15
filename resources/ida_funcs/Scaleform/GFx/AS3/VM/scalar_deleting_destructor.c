Scaleform::GFx::AS3::VM *__userpurge Scaleform::GFx::AS3::VM::`scalar deleting destructor'@<eax>(
        Scaleform::GFx::AS3::VM *this@<ecx>,
        int a2@<edi>,
        char a3)
{
  Scaleform::GFx::AS3::VM::~VM(this, a2);
  if ( (a3 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
