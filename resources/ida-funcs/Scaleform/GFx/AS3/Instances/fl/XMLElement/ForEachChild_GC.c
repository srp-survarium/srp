void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  unsigned int Size; // ebx
  unsigned int i; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // eax
  bool v7; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // eax
  unsigned int v9; // ebx
  unsigned int j; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *v11; // edx
  unsigned int v12; // ebx
  unsigned int k; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v14; // ecx

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->Parent.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Parent.pObject, this);
  if ( this->Ns.pObject )
    op(prcc, &this->Ns.pObject, this);
  Size = this->Namespaces.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->Namespaces.Data.Data;
    v7 = Data[i].pObject == 0;
    p_pObject = &Data[i].pObject;
    if ( !v7 )
      op(prcc, p_pObject, this);
  }
  v9 = this->Attrs.Data.Size;
  for ( j = 0; j < v9; ++j )
  {
    v11 = this->Attrs.Data.Data;
    if ( v11[j].pObject )
      op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v11[j].pObject, this);
  }
  v12 = this->Children.Data.Size;
  for ( k = 0; k < v12; ++k )
  {
    v14 = this->Children.Data.Data;
    if ( v14[k].pObject )
      op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v14[k].pObject, this);
  }
}
