Scaleform::GFx::AS2::Value *__cdecl Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Rect<float> *rect)
{
  Scaleform::GFx::AS2::RectangleObject *v3; // esi
  long double y1; // st6
  long double x2; // st5
  long double y2; // st7
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<double> r; // [esp+Ch] [ebp-20h] BYREF

  result->T.Type = 0;
  v3 = (Scaleform::GFx::AS2::RectangleObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                 penv,
                                                 penv->StringContext.pContext->FlashGeomPackage,
                                                 (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[11].RefCount,
                                                 0,
                                                 -1);
  y1 = rect->y1;
  x2 = rect->x2;
  y2 = rect->y2;
  r.x1 = rect->x1;
  r.y1 = y1;
  r.x2 = x2;
  r.y2 = y2;
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v3, penv, &r);
  Scaleform::GFx::AS2::Value::SetAsObject(result, v3);
  if ( v3 )
  {
    RefCount = v3->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v3->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
  return result;
}
