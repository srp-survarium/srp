void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  unsigned int v5; // ecx
  unsigned int v6; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // eax
  bool v8; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // eax
  unsigned int size; // [esp+18h] [ebp+8h]

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->TargetObject.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->TargetObject.pObject, this);
  if ( this->TargetNamespace.pObject )
    op(prcc, &this->TargetNamespace.pObject, this);
  v5 = this->List.Data.Size;
  v6 = 0;
  for ( size = v5; v6 < v5; ++v6 )
  {
    Data = this->List.Data.Data;
    v8 = Data[v6].pObject == 0;
    p_pObject = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[v6].pObject;
    if ( !v8 )
    {
      op(prcc, p_pObject, this);
      v5 = size;
    }
  }
}
