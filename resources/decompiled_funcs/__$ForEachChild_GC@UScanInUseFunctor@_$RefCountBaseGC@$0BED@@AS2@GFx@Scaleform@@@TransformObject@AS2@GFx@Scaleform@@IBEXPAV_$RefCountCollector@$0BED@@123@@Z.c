void __thiscall Scaleform::GFx::AS2::TransformObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::MatrixObject *pObject; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::ColorTransformObject *v5; // eax
  unsigned int v6; // ecx
  Scaleform::GFx::AS2::RectangleObject *v7; // eax
  unsigned int v8; // ecx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  pObject = this->Matrix.pObject;
  if ( pObject )
  {
    v4 = ++pObject->RefCount;
    if ( (v4 & 0x70000000) != 0 )
    {
      pObject->RefCount = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObject);
    }
  }
  v5 = this->pColorTransform.pObject;
  if ( v5 )
  {
    v6 = ++v5->RefCount;
    if ( (v6 & 0x70000000) != 0 )
    {
      v5->RefCount = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v5);
    }
  }
  v7 = this->PixelBounds.pObject;
  if ( v7 )
  {
    v8 = ++v7->RefCount;
    if ( (v8 & 0x70000000) != 0 )
    {
      v7->RefCount = v8 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v7);
    }
  }
}
