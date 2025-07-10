void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Size = this->CTraits.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->CTraits.Data.Data;
    if ( Data[i].pObject )
      op(prcc, &Data[i].pObject);
  }
}
