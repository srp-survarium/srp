void __cdecl Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // eax

  v2 = *pchild;
  if ( (--v2->RefCount & 0x3FFFFF) != 0 )
  {
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*pchild);
  }
  else
  {
    Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(prcc, *pchild);
    (*pchild)->RefCount |= 0x800000u;
    Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(prcc, *pchild);
  }
}
