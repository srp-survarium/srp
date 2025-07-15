Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *__thiscall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespaceSet(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *result,
        unsigned int nsSetIndex)
{
  Scaleform::GFx::AS3::NamespaceSet *v4; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // ecx
  Scaleform::GFx::AS3::Abc::File *pObject; // edx
  Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *v7; // esi
  int v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // eax
  Scaleform::GFx::AS3::NamespaceSet *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // ebx
  unsigned int Size; // esi
  unsigned int v14; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Namespaces; // edi
  unsigned int v16; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx
  _DWORD *p_pObject; // esi
  unsigned int RefCount; // eax
  const unsigned __int8 *ptr; // [esp+Ch] [ebp-4h] BYREF
  unsigned int nsSetIndexa; // [esp+18h] [ebp+8h]

  v4 = (Scaleform::GFx::AS3::NamespaceSet *)this->VMRef->MHeap->Alloc(this->VMRef->MHeap, 32, 0);
  if ( v4 )
  {
    GC = this->VMRef->GC.GC;
    v4->RefCount = 1;
    v4->pRCCRaw = (unsigned int)GC;
    v4->__vftable = (Scaleform::GFx::AS3::NamespaceSet_vtbl *)&Scaleform::GFx::AS3::NamespaceSet::`vftable';
    v4->Namespaces.Data.Data = 0;
    v4->Namespaces.Data.Size = 0;
    v4->Namespaces.Data.Policy.Capacity = 0;
  }
  else
  {
    v4 = 0;
  }
  pObject = this->File.pObject;
  v7 = result;
  result->pV = v4;
  ptr = pObject->Const_Pool.const_ns_set.Data.Data[nsSetIndex].Data;
  v8 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&ptr);
  if ( v8 )
  {
    nsSetIndexa = v8;
    while ( 1 )
    {
      v9 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&ptr);
      pV = v7->pV;
      InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this, v9);
      v12 = InternedNamespace;
      if ( InternedNamespace )
        InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
      Size = pV->Namespaces.Data.Size;
      v14 = Size;
      p_Namespaces = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&pV->Namespaces;
      v16 = Size + 1;
      if ( v16 >= v14 )
      {
        if ( v16 >= p_Namespaces->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_Namespaces,
            p_Namespaces,
            v16 + (v16 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_Namespaces->Data[v16],
          v14 - v16);
        if ( v16 < p_Namespaces->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_Namespaces,
            p_Namespaces,
            v16);
      }
      Data = p_Namespaces->Data;
      p_Namespaces->Size = v16;
      p_pObject = &Data[v16 - 1].pObject;
      if ( p_pObject )
      {
        *p_pObject = v12;
        if ( !v12 )
          goto LABEL_21;
        v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v12 && ((unsigned __int8)v12 & 1) == 0 )
      {
        RefCount = v12->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v12->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
        }
      }
LABEL_21:
      if ( !--nsSetIndexa )
        return result;
      v7 = result;
    }
  }
  return result;
}
