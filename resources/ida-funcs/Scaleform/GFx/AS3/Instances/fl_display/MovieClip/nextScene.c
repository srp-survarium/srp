void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::nextScene(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // edx
  unsigned int v4; // ebx
  int v5; // eax
  Scaleform::GFx::MovieDataDef::SceneInfo *Scenes; // edi
  int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ebp
  unsigned int *p_Offset; // edi
  unsigned int cnt; // [esp+8h] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  if ( (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(pObject[1].pNameHandle.pObject->RefCount + 16))(pObject[1].pNameHandle.pObject) == 2 )
  {
    GetResourceMovieDef = pObject->GetResourceMovieDef;
    v4 = 0;
    cnt = 0;
    v5 = (int)GetResourceMovieDef(pObject);
    Scenes = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
               *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(*(_DWORD *)(v5 + 28) + 12) + 32),
               &cnt);
    v7 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
    v8 = cnt;
    v9 = v7;
    if ( cnt )
    {
      p_Offset = &Scenes->Offset;
      do
      {
        if ( v9 >= *p_Offset
          && v9 < *p_Offset + p_Offset[1]
          && v4 + 1 < v8
          && p_Offset[8] < ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetXScale)(pObject) )
        {
          ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, unsigned int))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetXScale)(
            pObject,
            p_Offset[8]);
          ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetZScale)(
            pObject,
            0);
        }
        v8 = cnt;
        ++v4;
        p_Offset += 8;
      }
      while ( v4 < cnt );
    }
  }
}
