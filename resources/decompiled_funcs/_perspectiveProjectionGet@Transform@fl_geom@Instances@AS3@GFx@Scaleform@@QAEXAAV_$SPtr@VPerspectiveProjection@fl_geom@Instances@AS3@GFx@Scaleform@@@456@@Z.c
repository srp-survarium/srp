void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::perspectiveProjectionGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  bool v5; // bl
  long double v; // st7
  long double v7; // st7
  Scaleform::GFx::DisplayObject *v8; // ecx
  Scaleform::Render::Point<float> *(__thiscall *GetProjectionCenter)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *); // eax
  const Scaleform::Render::Point<float> *v10; // eax
  Scaleform::Render::Point<float> *v11; // eax
  Scaleform::Render::Point<float> *v12; // eax
  float *v13; // eax
  Scaleform::GFx::AS3::Object *pObject; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Object *v16; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+128h] [ebp-70h] BYREF
  Scaleform::GFx::DisplayObjectBase *pParent; // [esp+12Ch] [ebp-6Ch]
  float x; // [esp+130h] [ebp-68h]
  float y; // [esp+134h] [ebp-64h]
  Scaleform::Render::Point<float> v21; // [esp+138h] [ebp-60h] BYREF
  Scaleform::Render::Point<float> v22; // [esp+140h] [ebp-58h] BYREF
  Scaleform::Render::Point<float> v23; // [esp+148h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value __t; // [esp+158h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v25; // [esp+168h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v26; // [esp+178h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v27; // [esp+188h] [ebp-10h] BYREF

  pDispObj = this->pDispObj;
  if ( pDispObj && pDispObj->pPerspectiveData )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    pobj.pObject = 0;
    `vector constructor iterator'(
      (char *)&__t,
      0x10u,
      4,
      (void *(__thiscall *)(void *))Scaleform::GFx::ResourceKey::ResourceKey);
    v5 = pVM->pMovieRoot->GetRootMovie(pVM->pMovieRoot, 0) == this->pDispObj;
    v = this->pDispObj->GetFOV(this->pDispObj);
    Scaleform::GFx::AS3::Value::SetNumber(&__t, v);
    v7 = this->pDispObj->GetFocalLength(this->pDispObj);
    Scaleform::GFx::AS3::Value::SetNumber(&v25, v7 * 0.05);
    v8 = this->pDispObj;
    if ( v8->pParent )
    {
      GetProjectionCenter = v8->GetProjectionCenter;
      pParent = v8->pParent;
      v10 = GetProjectionCenter(v8, &v21);
      v11 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(pParent, &v22, v10);
    }
    else
    {
      v11 = v8->GetProjectionCenter(v8, &v23);
    }
    x = v11->x;
    y = v11->y;
    if ( v5 && 0.0 == x && 0.0 == y )
    {
      v12 = Scaleform::Render::Rect<float>::Center(&pVM->pMovieRoot->pMovieImpl->VisibleFrameRect, &v23);
      x = v12->x;
      y = v12->y;
    }
    *(float *)&pParent = x * 0.05000000074505806;
    Scaleform::GFx::AS3::Value::SetNumber(&v26, *(float *)&pParent);
    *(float *)&pParent = y * 0.05000000074505806;
    Scaleform::GFx::AS3::Value::SetNumber(&v27, *(float *)&pParent);
    if ( Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, pVM->PerspectiveProjectionClass.pObject, 4u, &__t) )
    {
      pobj.pObject[1].DynAttrs.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)this->pDispObj;
      if ( v5 )
      {
        v13 = (float *)pVM->pMovieRoot->pMovieImpl->GetVisibleFrameRect(
                         pVM->pMovieRoot->pMovieImpl,
                         (Scaleform::Render::Rect<float> *)&v23);
        pObject = pobj.pObject;
        *(float *)&pParent = v13[2] - *v13;
        *(long double *)&pObject[1].pNext = Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::CalculateFocalLength(
                                              (Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *)pobj.pObject,
                                              *(float *)&pParent);
      }
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      result,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pobj);
    `vector destructor iterator'(
      (char *)&__t,
      0x10u,
      4,
      (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    if ( pobj.pObject && ((int)pobj.pObject & 1) == 0 )
    {
      RefCount = pobj.pObject->RefCount;
      v16 = pobj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pobj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
  }
}
