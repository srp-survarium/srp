// local variable allocation has failed, the output may be wrong!
Scaleform::GFx::AS2::Value *__usercall Scaleform::GFx::AS2::Rectangle_ComputeSize@<eax>(
        Scaleform::GFx::AS2::Environment *penv@<edi>,
        Scaleform::Render::Rect<double> r)
{
  Scaleform::GFx::AS2::PointObject *v2; // eax
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // esi
  unsigned int RefCount; // eax
  char v7; // [esp+0h] [ebp-18h]
  Scaleform::Render::Point<double> pt; // [esp+8h] [ebp-10h] BYREF

  v2 = (Scaleform::GFx::AS2::PointObject *)penv->StringContext.pContext->pHeap->Alloc(
                                             penv->StringContext.pContext->pHeap,
                                             52,
                                             0);
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, penv);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  pt.x = *(double *)((char *)&r.x2 + 4) - *(double *)((char *)&r.x1 + 4);
  pt.y = *(double *)((char *)&r.y2 + 4) - *(double *)((char *)&r.y1 + 4);
  Scaleform::GFx::AS2::PointObject::SetProperties(v4, (int)penv, (int)v4, penv, &pt, v7);
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)LODWORD(r.x1), v4);
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
  return (Scaleform::GFx::AS2::Value *)LODWORD(r.x1);
}
