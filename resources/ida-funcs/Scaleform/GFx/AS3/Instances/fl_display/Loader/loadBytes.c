void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::loadBytes(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *context)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // esi
  Scaleform::GFx::AS3::VM_vtbl *v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *v7; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *p_applicationDomain; // eax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v9; // eax
  Scaleform::GFx::AS3::VMAppDomain *CursorPos; // eax
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v14; // eax
  Scaleform::RefCountNTSImpl *v15; // ecx
  Scaleform::GFx::AS3::Instances::fl_system::LoaderContext **p_pDispObj; // eax
  Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *v17; // esi
  Scaleform::GFx::AS3::VM *pVM; // [esp-4h] [ebp-18h]
  char v19; // [esp+10h] [ebp-4h]

  pObject = this->pContentLoaderInfo.pObject;
  v6 = this->pTraits.pObject->pVM[1].__vftable;
  v7 = 0;
  v19 = 0;
  if ( pObject )
  {
    if ( context )
    {
      v7 = context;
      p_applicationDomain = &context->applicationDomain;
    }
    else
    {
      v19 = 1;
      context = 0;
      p_applicationDomain = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *)&context;
    }
    v9 = p_applicationDomain->pObject;
    if ( v9 )
    {
      CursorPos = Scaleform::GFx::Text::EditorKit::GetCursorPos(v9);
    }
    else
    {
      pVM = pObject->pTraits.pObject->pVM;
      FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pVM);
      CursorPos = Scaleform::GFx::AS3::VMAppDomain::AddNewChild(FrameAppDomain, pVM);
    }
    pObject->AppDomain = CursorPos;
    if ( (v19 & 1) != 0 )
    {
      v19 &= ~1u;
      if ( v7 )
      {
        if ( ((unsigned __int8)v7 & 1) == 0 )
        {
          RefCount = v7->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v7->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
          }
        }
      }
    }
  }
  v13 = this->pContentLoaderInfo.pObject;
  if ( v13 )
  {
    v14 = v13->Content.pObject;
    if ( v14 )
    {
      v15 = (Scaleform::RefCountNTSImpl *)context;
      p_pDispObj = (Scaleform::GFx::AS3::Instances::fl_system::LoaderContext **)&v14->pDispObj;
    }
    else
    {
      v19 |= 2u;
      v15 = 0;
      context = 0;
      p_pDispObj = &context;
    }
    v17 = *p_pDispObj;
    if ( (v19 & 2) != 0 && v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
    if ( v17 )
      Scaleform::GFx::AS3::MovieRoot::UnloadMovie((Scaleform::GFx::AS3::MovieRoot *)v6, this, 0, 0);
  }
  Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry((Scaleform::GFx::AS3::MovieRoot *)v6, bytes, this, LM_None);
}
