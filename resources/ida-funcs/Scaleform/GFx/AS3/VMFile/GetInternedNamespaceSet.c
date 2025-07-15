Scaleform::GFx::AS3::NamespaceSet *__thiscall Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
        Scaleform::GFx::AS3::VMFile *this,
        unsigned int nsSetIndex)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *v5; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *v6; // eax
  Scaleform::GFx::AS3::NamespaceSet *pV; // ebp
  Scaleform::GFx::AS3::NamespaceSet *pObject; // ecx
  unsigned int RefCount; // eax

  v2 = nsSetIndex;
  if ( nsSetIndex >= this->IntNamespaceSets.Data.Size )
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->IntNamespaceSets,
      nsSetIndex + 1);
  Data = this->IntNamespaceSets.Data.Data;
  v5 = &Data[v2];
  if ( v5->pObject )
    return Data[v2].pObject;
  v6 = this->MakeInternedNamespaceSet(this, &nsSetIndex, v2);
  pV = v6->pV;
  pObject = v5->pObject;
  if ( v6->pV == v5->pObject )
    return this->IntNamespaceSets.Data.Data[v2].pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      v5->pObject = (Scaleform::GFx::AS3::NamespaceSet *)((char *)pObject - 1);
      v5->pObject = pV;
      return this->IntNamespaceSets.Data.Data[v2].pObject;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  v5->pObject = pV;
  return this->IntNamespaceSets.Data.Data[v2].pObject;
}
