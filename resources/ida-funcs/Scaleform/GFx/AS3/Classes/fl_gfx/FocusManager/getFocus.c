void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocus(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result,
        unsigned int controllerIdx)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // eax
  unsigned int v4; // edi
  int v5; // eax
  int v6; // eax
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v9; // eax
  int TraitsType; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *pObject; // ecx
  unsigned int RefCount; // eax

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)v3 + 16 * *((unsigned __int8 *)v3 + controllerIdx + 16212) + 3801,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
  v4 = controllerIdx;
  if ( controllerIdx )
  {
    ++*(_DWORD *)(controllerIdx + 4);
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v4);
    v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(v4 + 4 * *(unsigned __int8 *)(v4 + 65)) + 4))(v4 + 4 * *(unsigned __int8 *)(v4 + 65));
    if ( v5 )
      v6 = v5 - 28;
    else
      v6 = 0;
    if ( *(_DWORD *)(v6 + 8) )
      v9 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v6 + 8);
    else
      v9 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v6 + 4);
    if ( ((unsigned __int8)v9 & 1) != 0 )
      v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v9 - 1);
    if ( v9 )
    {
      TraitsType = v9->pTraits.pObject->TraitsType;
      if ( TraitsType == 18 || TraitsType >= 23 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
          v9);
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v4);
        return;
      }
    }
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)((char *)pObject - 1);
        result->pObject = 0;
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v4);
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      result->pObject = 0;
    }
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v4);
  }
  else
  {
    v7 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)((char *)v7 - 1);
        result->pObject = 0;
      }
      else
      {
        v8 = v7->RefCount;
        if ( (v8 & 0x3FFFFF) != 0 )
        {
          v7->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
        result->pObject = 0;
      }
    }
  }
}
