void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::scenesGet(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::DisplayObject *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // edx
  int v9; // eax
  Scaleform::GFx::MovieDataDef::SceneInfo *Scenes; // edi
  Scaleform::GFx::AS3::Traits *v11; // eax
  Scaleform::GFx::AS3::Class *Class; // ebx
  const Scaleform::GFx::MovieDataDef::SceneInfo *v13; // esi
  unsigned int v14; // edx
  Scaleform::GFx::AS3::Instances::fl_display::Scene *v15; // ecx
  int v16; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Scene> scene; // [esp+10h] [ebp-28h] BYREF
  unsigned int cnt; // [esp+14h] [ebp-24h] BYREF
  unsigned int i; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::ASVM *asvm; // [esp+1Ch] [ebp-1Ch]
  Scaleform::StringDataPtr gname; // [esp+20h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+28h] [ebp-10h] BYREF

  pObject = this->pDispObj.pObject;
  asvm = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  pV = Scaleform::GFx::AS3::VM::MakeArray(asvm, (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&i)->pV;
  v5 = result;
  v6 = result->pObject;
  if ( pV != result->pObject )
  {
    if ( v6 )
    {
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v6 - 1);
      }
      else
      {
        RefCount = v6->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
          v5 = result;
        }
      }
    }
    v5->pObject = pV;
  }
  if ( (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(pObject[1].pNameHandle.pObject->RefCount + 16))(pObject[1].pNameHandle.pObject) == 2 )
  {
    GetResourceMovieDef = pObject->GetResourceMovieDef;
    cnt = 0;
    v9 = (int)GetResourceMovieDef(pObject);
    Scenes = Scaleform::GFx::MovieDataDef::LoadTaskData::GetScenes(
               *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(*(_DWORD *)(v9 + 28) + 12) + 32),
               &cnt);
    v11 = this->pTraits.pObject;
    gname.pStr = "flash.display.Scene";
    gname.Size = 19;
    Class = Scaleform::GFx::AS3::VM::GetClass(v11->pVM, &gname, v11->pVM->CurrentDomain);
    i = 0;
    if ( cnt )
    {
      v13 = Scenes;
      do
      {
        scene.pObject = 0;
        Scaleform::GFx::AS3::ASVM::_constructInstance(
          asvm,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&scene,
          Class,
          0,
          0);
        scene.pObject->SceneInfo = v13;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v, scene.pObject);
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&result->pObject->SA, &v);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        if ( scene.pObject && ((int)scene.pObject & 1) == 0 )
        {
          v14 = scene.pObject->RefCount;
          v15 = scene.pObject;
          if ( ((unsigned int)&byte_3FFFFF & v14) != 0 )
          {
            scene.pObject->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
          }
        }
        ++v13;
        ++i;
      }
      while ( i < cnt );
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_display::MovieClip::CreateFakeScene(
      this,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&i);
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v, (Scaleform::GFx::AS3::Object *)i);
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&result->pObject->SA, &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    if ( i )
    {
      if ( (i & 1) == 0 )
      {
        v16 = *(_DWORD *)(i + 16);
        v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
        if ( ((unsigned int)&byte_3FFFFF & v16) != 0 )
        {
          *(_DWORD *)(i + 16) = v16 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
        }
      }
    }
  }
}
