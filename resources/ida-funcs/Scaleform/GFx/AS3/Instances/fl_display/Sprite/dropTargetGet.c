void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::dropTargetGet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result)
{
  const Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::InteractiveObject *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v10; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v11; // ecx
  unsigned int RefCount; // eax
  float y; // [esp+4h] [ebp-Ch]
  Scaleform::Render::Point<float> mousePos; // [esp+8h] [ebp-8h] BYREF

  pObject = (const Scaleform::GFx::InteractiveObject *)this->pDispObj.pObject;
  pMovieImpl = pObject->pASRoot->pMovieImpl;
  y = pMovieImpl->mMouseState[0].LastPosition.y;
  mousePos.x = pMovieImpl->mMouseState[0].LastPosition.x;
  mousePos.y = y;
  TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(pMovieImpl, &mousePos, 0.0, 1, pObject);
  v5 = TopMostEntity;
  if ( TopMostEntity )
  {
    v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&TopMostEntity->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + TopMostEntity->AvmObjOffset)
                                    + 4))((int)TopMostEntity + 4 * TopMostEntity->AvmObjOffset);
    if ( v6 )
      v7 = v6 - 28;
    else
      v7 = 0;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 60))(v7, 1);
    v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + v5->AvmObjOffset)
                                    + 4))((int)v5 + 4 * v5->AvmObjOffset);
    if ( v8 )
      v9 = v8 - 28;
    else
      v9 = 0;
    if ( *(_DWORD *)(v9 + 8) )
      v10 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v9 + 8);
    else
      v10 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v9 + 4);
    if ( ((unsigned __int8)v10 & 1) != 0 )
      v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v10 - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v10);
  }
  else
  {
    v11 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v11 - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
        result->pObject = 0;
      }
    }
  }
}
