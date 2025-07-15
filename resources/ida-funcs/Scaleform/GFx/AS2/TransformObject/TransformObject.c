void __thiscall Scaleform::GFx::AS2::TransformObject::TransformObject(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::MatrixObject *pObject; // ecx
  Scaleform::GFx::AS2::MatrixObject *v8; // ebp
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v11; // ecx
  Scaleform::GFx::AS2::ColorTransformObject *v12; // ebp
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Object *v14; // eax
  Scaleform::GFx::AS2::RectangleObject *v15; // ecx
  Scaleform::GFx::AS2::RectangleObject *v16; // edi
  unsigned int v17; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->pMovieRoot = 0;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TransformObject_vtbl *)&Scaleform::GFx::AS2::TransformObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TransformObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->TargetHandle.pObject = 0;
  this->Matrix.pObject = 0;
  this->pColorTransform.pObject = 0;
  this->PixelBounds.pObject = 0;
  Scaleform::GFx::AS2::TransformObject::SetTarget(this, pcharacter);
  p_StringContext = &penv->StringContext;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Transform);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  v6 = Scaleform::GFx::AS2::Environment::OperatorNew(
         penv,
         p_StringContext->pContext->FlashGeomPackage,
         (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[10].AVMVersion,
         0,
         -1);
  pObject = this->Matrix.pObject;
  v8 = (Scaleform::GFx::AS2::MatrixObject *)v6;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Matrix.pObject = v8;
  v10 = Scaleform::GFx::AS2::Environment::OperatorNew(
          penv,
          p_StringContext->pContext->FlashGeomPackage,
          (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[11].pMovieImpl,
          0,
          -1);
  v11 = this->pColorTransform.pObject;
  v12 = (Scaleform::GFx::AS2::ColorTransformObject *)v10;
  if ( v11 )
  {
    v13 = v11->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v13) != 0 )
    {
      v11->RefCount = v13 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  this->pColorTransform.pObject = v12;
  v14 = Scaleform::GFx::AS2::Environment::OperatorNew(
          penv,
          p_StringContext->pContext->FlashGeomPackage,
          (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[11].RefCount,
          0,
          -1);
  v15 = this->PixelBounds.pObject;
  v16 = (Scaleform::GFx::AS2::RectangleObject *)v14;
  if ( v15 )
  {
    v17 = v15->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v17) != 0 )
    {
      v15->RefCount = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
    }
  }
  this->PixelBounds.pObject = v16;
}
