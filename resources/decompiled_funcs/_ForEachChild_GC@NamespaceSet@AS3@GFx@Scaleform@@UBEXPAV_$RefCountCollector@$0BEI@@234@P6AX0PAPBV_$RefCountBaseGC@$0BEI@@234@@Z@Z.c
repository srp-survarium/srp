void __thiscall Scaleform::GFx::AS3::NamespaceSet::ForEachChild_GC(
        Scaleform::GFx::AS3::NamespaceSet *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // eax
  bool v7; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // eax

  Size = this->Namespaces.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->Namespaces.Data.Data;
    v7 = Data[i].pObject == 0;
    p_pObject = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[i].pObject;
    if ( !v7 )
      op(prcc, p_pObject);
  }
}
