void __thiscall Scaleform::GFx::ButtonDef::~ButtonDef(Scaleform::GFx::ButtonDef *this)
{
  Scaleform::GFx::ButtonSoundDef *pSound; // ecx

  pSound = this->pSound;
  this->__vftable = (Scaleform::GFx::ButtonDef_vtbl *)&Scaleform::GFx::ButtonDef::`vftable';
  if ( pSound )
    ((void (__thiscall *)(Scaleform::GFx::ButtonSoundDef *, int))pSound->~Scaleform::GFx::ButtonSoundDef)(pSound, 1);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pScale9Grid);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ButtonActions);
  Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::DestructArray(
    this->ButtonRecords.Data.Data,
    this->ButtonRecords.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ButtonRecords.Data.Data);
  this->__vftable = (Scaleform::GFx::ButtonDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
}
