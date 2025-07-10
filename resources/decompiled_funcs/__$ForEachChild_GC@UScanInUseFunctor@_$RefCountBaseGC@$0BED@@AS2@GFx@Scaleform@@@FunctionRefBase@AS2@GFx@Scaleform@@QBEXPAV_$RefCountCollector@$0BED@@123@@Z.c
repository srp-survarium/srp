void __thiscall Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  unsigned int v6; // ecx

  Function = this->Function;
  if ( this->Function )
  {
    v4 = ++Function->RefCount;
    if ( (v4 & 0x70000000) != 0 )
    {
      Function->RefCount = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, Function);
    }
  }
  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    v6 = ++pLocalFrame->RefCount;
    if ( (v6 & 0x70000000) != 0 )
    {
      pLocalFrame->RefCount = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pLocalFrame);
    }
  }
}
