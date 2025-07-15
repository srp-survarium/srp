void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::currentSceneGet(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v2; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::Scene *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::DisplayObject *v6; // esi
  unsigned int v7; // edi
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // eax
  int v9; // eax
  Scaleform::GFx::MovieDataDef::SceneInfo *v10; // eax
  int v11; // esi
  unsigned int *i; // eax
  Scaleform::GFx::AS3::Traits *v13; // edx
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *FakeScene; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Scene *v16; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v18; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::AS3::ASVM *asvm; // [esp+10h] [ebp-10h]
  const Scaleform::GFx::MovieDataDef::SceneInfo *scenes; // [esp+14h] [ebp-Ch]
  Scaleform::StringDataPtr gname; // [esp+18h] [ebp-8h] BYREF

  v2 = result;
  pObject = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)result->pObject;
  v18 = this;
  if ( result->pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    v2->pObject = 0;
  }
  v6 = this->pDispObj.pObject;
  asvm = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  if ( (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(v6[1].pNameHandle.pObject->RefCount + 16))(v6[1].pNameHandle.pObject) == 2 )
  {
    v7 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(v6);
    GetResourceMovieDef = v6->GetResourceMovieDef;
    result = 0;
    v9 = (int)GetResourceMovieDef(v6);
    v10 = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
            *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(*(_DWORD *)(v9 + 28) + 12) + 32),
            (unsigned int *)&result);
    v11 = 0;
    scenes = v10;
    if ( result )
    {
      for ( i = &v10->Offset; v7 < *i || v7 >= *i + i[1]; i += 8 )
      {
        if ( ++v11 >= (unsigned int)result )
          return;
      }
      v13 = v18->pTraits.pObject;
      gname.pStr = "flash.display.Scene";
      gname.Size = 19;
      Class = Scaleform::GFx::AS3::VM::GetClass(v13->pVM, &gname, v13->pVM->CurrentDomain);
      Scaleform::GFx::AS3::ASVM::_constructInstance(asvm, v2, Class, 0, 0);
      v2->pObject[1].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&scenes[v11];
    }
  }
  else
  {
    FakeScene = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::CreateFakeScene(
                  this,
                  (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)v2,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)FakeScene);
    if ( result )
    {
      if ( ((unsigned __int8)result & 1) == 0 )
      {
        v16 = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)result[4].pObject;
        v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)result;
        if ( ((unsigned int)v16 & 0x3FFFFF) != 0 )
        {
          result[4].pObject = (Scaleform::GFx::AS3::Instances::fl_display::Scene *)((char *)v16 - 1);
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
        }
      }
    }
  }
}
