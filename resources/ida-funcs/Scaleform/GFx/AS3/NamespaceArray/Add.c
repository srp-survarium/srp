void __thiscall Scaleform::GFx::AS3::NamespaceArray::Add(
        Scaleform::GFx::AS3::NamespaceArray *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *other,
        bool checkUnique)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // ecx
  unsigned int Size; // eax
  const Scaleform::MemoryHeap *pHeap; // ebp
  unsigned int v8; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v9; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v10; // esi
  unsigned int RefCount; // eax

  if ( checkUnique && (v4 = 0, this->Namespaces.Data.Size) )
  {
    Data = this->Namespaces.Data.Data;
    while ( Data->pObject->Uri.pNode != other->Uri.pNode
         || ((*((_BYTE *)other + 20) ^ *((_BYTE *)Data->pObject + 20)) & 0xF) != 0 )
    {
      ++v4;
      ++Data;
      if ( v4 >= this->Namespaces.Data.Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    if ( other )
      other->RefCount = (other->RefCount + 1) & 0x8FBFFFFF;
    Size = this->Namespaces.Data.Size;
    pHeap = this->Namespaces.Data.pHeap;
    v8 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v8 >= this->Namespaces.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
          pHeap,
          v8 + (v8 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&this->Namespaces.Data.Data[Size + 1],
        0xFFFFFFFF);
      if ( v8 < this->Namespaces.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
          pHeap,
          v8);
    }
    v9 = this->Namespaces.Data.Data;
    this->Namespaces.Data.Size = v8;
    v10 = &v9[v8 - 1];
    if ( v10 )
    {
      v10->pObject = other;
      if ( !other )
        return;
      other->RefCount = (other->RefCount + 1) & 0x8FBFFFFF;
    }
    if ( other && ((unsigned __int8)other & 1) == 0 )
    {
      RefCount = other->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        other->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(other);
      }
    }
  }
}
