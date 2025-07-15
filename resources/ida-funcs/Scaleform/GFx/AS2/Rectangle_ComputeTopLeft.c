Scaleform::GFx::AS2::Value *__usercall Scaleform::GFx::AS2::Rectangle_ComputeTopLeft@<eax>(
        Scaleform::GFx::AS2::Environment *penv@<edi>,
        Scaleform::Render::Rect<double> r)
{
  Scaleform::GFx::AS2::PointObject *v2; // eax
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // esi
  unsigned int RefCount; // eax
  char v7; // [esp+0h] [ebp-18h]
  Scaleform::Render::Point<double> v8; // [esp+8h] [ebp-10h] BYREF

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
  v8.x = *(double *)((char *)&r.x1 + 4);
  v8.y = *(double *)((char *)&r.y1 + 4);
  Scaleform::GFx::AS2::PointObject::SetProperties(v4, (int)penv, (int)v4, penv, &v8, v7);
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)LODWORD(r.x1), v4);
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
  return (Scaleform::GFx::AS2::Value *)LODWORD(r.x1);
}
