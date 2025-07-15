void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  if ( operation )
  {
    if ( operation == Operation_MarkInCycle )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
    else if ( operation == Operation_ScanInUse )
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}
