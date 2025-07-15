void __cdecl Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  --(*pchild)->RefCount;
  Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(prcc, *pchild);
}
