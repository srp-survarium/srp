void __thiscall Scaleform::GFx::AS2::ArrayObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS2::Value *v5; // ecx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(this, prcc);
  Size = this->Elements.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    v5 = this->Elements.Data.Data[i];
    if ( v5 )
      Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(v5, prcc);
  }
}
