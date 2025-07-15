void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // eax
  bool v7; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // eax

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->TargetObject.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->TargetObject.pObject);
  if ( this->TargetNamespace.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->TargetNamespace.pObject);
  Size = this->List.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->List.Data.Data;
    v7 = Data[i].pObject == 0;
    p_pObject = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[i].pObject;
    if ( !v7 )
      op(prcc, p_pObject);
  }
}
