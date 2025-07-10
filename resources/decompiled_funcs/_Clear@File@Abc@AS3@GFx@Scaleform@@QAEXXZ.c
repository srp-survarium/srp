void __thiscall Scaleform::GFx::AS3::Abc::File::Clear(Scaleform::GFx::AS3::Abc::File *this)
{
  Scaleform::GFx::AS3::Abc::MethodTable *p_Methods; // esi
  Scaleform::GFx::AS3::Abc::MetadataTable *p_Metadata; // esi
  Scaleform::GFx::AS3::Abc::TraitTable *p_Traits; // esi
  Scaleform::GFx::AS3::Abc::ClassTable *p_AS3_Classes; // esi
  Scaleform::GFx::AS3::Abc::ScriptTable *p_Scripts; // esi
  Scaleform::GFx::AS3::Abc::MethodBodyTable *p_MethodBodies; // esi

  this->MajorVersion = 0;
  this->MinorVersion = 0;
  Scaleform::GFx::AS3::Abc::ConstPool::Clear(&this->Const_Pool);
  p_Methods = &this->Methods;
  if ( this->Methods.Info.Data.Size )
  {
    if ( (this->Methods.Info.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_Methods->Info.Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Methods->Info.Data.Data);
        p_Methods->Info.Data.Data = 0;
      }
      this->Methods.Info.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->Methods.Info.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&this->Methods,
      &this->Methods,
      0);
  }
  this->Methods.Info.Data.Size = 0;
  p_Metadata = &this->Metadata;
  if ( this->Metadata.Info.Data.Size )
  {
    if ( (this->Metadata.Info.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_Metadata->Info.Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Metadata->Info.Data.Data);
        p_Metadata->Info.Data.Data = 0;
      }
      this->Metadata.Info.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->Metadata.Info.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&this->Metadata,
      &this->Metadata,
      0);
  }
  this->Metadata.Info.Data.Size = 0;
  p_Traits = &this->Traits;
  if ( this->Traits.TraitInfos.Data.Size )
  {
    if ( (this->Traits.TraitInfos.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_Traits->TraitInfos.Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Traits->TraitInfos.Data.Data);
        p_Traits->TraitInfos.Data.Data = 0;
      }
      this->Traits.TraitInfos.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->Traits.TraitInfos.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&this->Traits,
      &this->Traits,
      0);
  }
  this->Traits.TraitInfos.Data.Size = 0;
  p_AS3_Classes = &this->AS3_Classes;
  if ( this->AS3_Classes.Info.Data.Size )
  {
    if ( (this->AS3_Classes.Info.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_AS3_Classes->Info.Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_AS3_Classes->Info.Data.Data);
        p_AS3_Classes->Info.Data.Data = 0;
      }
      this->AS3_Classes.Info.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->AS3_Classes.Info.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&this->AS3_Classes,
      &this->AS3_Classes,
      0);
  }
  this->AS3_Classes.Info.Data.Size = 0;
  p_Scripts = &this->Scripts;
  if ( this->Scripts.Info.Data.Size )
  {
    if ( (this->Scripts.Info.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_Scripts->Info.Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Scripts->Info.Data.Data);
        p_Scripts->Info.Data.Data = 0;
      }
      this->Scripts.Info.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->Scripts.Info.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&this->Scripts,
      &this->Scripts,
      0);
  }
  this->Scripts.Info.Data.Size = 0;
  p_MethodBodies = &this->MethodBodies;
  if ( !this->MethodBodies.Info.Data.Size )
  {
    if ( !this->MethodBodies.Info.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&this->MethodBodies,
        &this->MethodBodies,
        0);
    goto LABEL_43;
  }
  if ( (this->MethodBodies.Info.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_43:
    this->MethodBodies.Info.Data.Size = 0;
    return;
  }
  if ( p_MethodBodies->Info.Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_MethodBodies->Info.Data.Data);
    p_MethodBodies->Info.Data.Data = 0;
  }
  this->MethodBodies.Info.Data.Policy.Capacity = 0;
  this->MethodBodies.Info.Data.Size = 0;
}
