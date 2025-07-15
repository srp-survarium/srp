void __thiscall Scaleform::GFx::AS2::SuperObject::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}
