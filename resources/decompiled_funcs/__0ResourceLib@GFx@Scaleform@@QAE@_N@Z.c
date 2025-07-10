void __thiscall Scaleform::GFx::ResourceLib::ResourceLib(Scaleform::GFx::ResourceLib *this, bool debug)
{
  Scaleform::GFx::ResourceWeakLib *v3; // eax
  Scaleform::GFx::ResourceWeakLib *v4; // eax

  this->__vftable = (Scaleform::GFx::ResourceLib_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ResourceLib_vtbl *)&Scaleform::GFx::ResourceLib::`vftable';
  this->PinSet.pTable = 0;
  this->DebugFlag = debug;
  v3 = (Scaleform::GFx::ResourceWeakLib *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 44, 0);
  if ( v3 )
  {
    Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(v3, this);
    this->pWeakLib = v4;
  }
  else
  {
    this->pWeakLib = 0;
  }
}
