void __thiscall Scaleform::GFx::AS3::Abc::MethodBodyInfo::~MethodBodyInfo(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo *this)
{
  int *Data; // eax

  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->exception.info.Data.Data);
  Data = this->obj_traits.Data.Data;
  this->code.__vftable = (Scaleform::GFx::AS3::Abc::Code_vtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
