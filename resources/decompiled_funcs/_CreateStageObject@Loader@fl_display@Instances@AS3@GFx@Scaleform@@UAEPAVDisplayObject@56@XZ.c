Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this)
{
  Scaleform::GFx::AS3::MovieRoot *v2; // edi
  Scaleform::GFx::AS3::AvmLoader *v3; // eax
  Scaleform::GFx::DisplayObject *v4; // eax
  Scaleform::GFx::DisplayObject *v5; // ebx
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::AS3::VMAppDomain *v7; // eax

  if ( !this->pDispObj.pObject )
  {
    v2 = (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable;
    v3 = (Scaleform::GFx::AS3::AvmLoader *)v2->pMovieImpl->pHeap->Alloc(v2->pMovieImpl->pHeap, 192u, 0);
    if ( v3 )
    {
      Scaleform::GFx::AS3::AvmLoader::AvmLoader(
        v3,
        v2,
        v2->pMovieImpl->pMainMovieDef.pObject,
        0,
        (Scaleform::GFx::ResourceId)0x40000);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    pObject = this->pDispObj.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    this->pDispObj.pObject = v5;
    if ( v5 )
      v5 = (Scaleform::GFx::DisplayObject *)((char *)v5 + 4 * v5->AvmObjOffset);
    Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj((Scaleform::GFx::AS3::AvmDisplayObj *)v5, this);
    v7 = this->pTraits.pObject->GetAppDomain(this->pTraits.pObject);
    Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain((Scaleform::GFx::AS3::AvmDisplayObj *)v5, v7);
    Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
      v2,
      (Scaleform::GFx::DisplayObjContainer *)this->pDispObj.pObject);
  }
  return this->pDispObj.pObject;
}
