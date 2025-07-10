void __thiscall Scaleform::GFx::AS3::VTable::VTable(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::Traits *tr,
        const Scaleform::GFx::AS3::VTable *parent)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,331,Scaleform::ArrayDefaultPolicy> *p_VTMethods; // esi
  unsigned int Size; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Value *tra; // [esp+10h] [ebp+4h]

  this->pTraits = tr;
  p_VTMethods = &this->VTMethods;
  this->VTMethods.Data.Data = 0;
  this->VTMethods.Data.Size = 0;
  this->VTMethods.Data.Policy.Capacity = 0;
  Size = parent->VTMethods.Data.Size;
  tra = parent->VTMethods.Data.Data;
  if ( Size )
  {
    v5 = this->VTMethods.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->VTMethods.Data,
      &this->VTMethods,
      v5 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(&p_VTMethods->Data.Data[v5].Flags, Size, tra);
  }
}
