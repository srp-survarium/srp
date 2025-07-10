void __cdecl Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // eax

  v2 = *pchild;
  if ( ((unsigned int)&byte_3FFFFF & --v2->RefCount) != 0 )
  {
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*pchild);
  }
  else
  {
    Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(prcc, *pchild);
    (*pchild)->RefCount |= (unsigned int)&unk_800000;
    Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(prcc, *pchild);
  }
}
