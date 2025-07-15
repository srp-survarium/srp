void __thiscall Scaleform::GFx::AS3::VMAppDomain::AddChild(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::VMAppDomain *childDomain)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy> *p_ChildDomains; // edi
  unsigned int v4; // esi
  Scaleform::GFx::AS3::VMAbcFile **v5; // eax

  p_ChildDomains = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy> *)&this->ChildDomains;
  v4 = this->ChildDomains.Data.Size + 1;
  if ( v4 >= this->ChildDomains.Data.Size )
  {
    if ( v4 >= this->ChildDomains.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ChildDomains,
        p_ChildDomains,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->ChildDomains.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ChildDomains,
      p_ChildDomains,
      this->ChildDomains.Data.Size + 1);
  }
  v5 = &p_ChildDomains->Data[v4 - 1];
  p_ChildDomains->Size = v4;
  if ( v5 )
    *v5 = (Scaleform::GFx::AS3::VMAbcFile *)childDomain;
  childDomain->ParentDomain = this;
}
