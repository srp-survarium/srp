Scaleform::GFx::AS2::BitmapFilterObject *__cdecl Scaleform::GFx::AS2::BitmapFilterObject::CreateFromDesc(
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::Render::Filter *filter)
{
  int v2; // esi
  Scaleform::GFx::AS2::BitmapFilterObject *v3; // esi
  Scaleform::Render::Filter *v4; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::Filter *v6; // edi
  Scaleform::GFx::AS2::BitmapFilterObject *result; // eax

  switch ( filter->Type )
  {
    case Filter_Blur:
      v2 = 40;
      goto LABEL_7;
    case Filter_Shadow:
      v2 = 38;
      goto LABEL_7;
    case Filter_Glow:
      v2 = 39;
      goto LABEL_7;
    case Filter_Bevel:
      v2 = 41;
      goto LABEL_7;
    case Filter_ColorMatrix:
      v2 = 42;
LABEL_7:
      v3 = (Scaleform::GFx::AS2::BitmapFilterObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                        penv,
                                                        penv->StringContext.pContext->FlashFiltersPackage,
                                                        (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount
                                                      + v2,
                                                        0,
                                                        -1);
      if ( v3 )
      {
        v4 = filter->Clone(filter, 0);
        pObject = (Scaleform::RefCountVImpl *)v3->pFilter.pObject;
        v6 = v4;
        if ( pObject )
          Scaleform::RefCountImpl::Release(pObject);
        v3->pFilter.pObject = v6;
      }
      result = v3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
