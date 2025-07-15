Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::FunctionCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::FunctionCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *v2; // eax
  _DWORD *v3; // esi

  v2 = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap->Alloc(
                                        penv->StringContext.pContext->pHeap,
                                        56,
                                        0);
  v3 = &v2->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
  if ( !v2 )
    return 0;
  Scaleform::GFx::AS2::Object::Object(v2, &penv->StringContext);
  *v3 = &Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3[4] = &Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3[13] = 0;
  return (Scaleform::GFx::AS2::Object *)v3;
}
