bool __thiscall Scaleform::GFx::AS3::VMAbcFile::RegisterScrips(Scaleform::GFx::AS3::VMAbcFile *this, bool to_execute)
{
  Scaleform::GFx::AS3::VMAbcFile *v2; // edi
  Scaleform::GFx::AS3::Abc::File *pObject; // eax
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // ebp
  Scaleform::GFx::AS3::Instances::fl::GlobalObject *v6; // ecx
  const Scaleform::GFx::AS3::Abc::ScriptInfo *v8; // esi
  Scaleform::MemoryHeap *MHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v11; // ebx
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v12; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v13; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> *Instance; // eax
  bool v15; // zf
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pV; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_GlobalObjects; // edi
  unsigned int v18; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v20; // esi
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v21; // ebx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v23; // ecx
  unsigned int v24; // eax
  unsigned int RefCount; // ecx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> inst; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript> it; // [esp+14h] [ebp-18h]
  unsigned int i; // [esp+18h] [ebp-14h]
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *v30; // [esp+1Ch] [ebp-10h]
  unsigned int n; // [esp+20h] [ebp-Ch]
  const Scaleform::GFx::AS3::Abc::File *file; // [esp+24h] [ebp-8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> result; // [esp+28h] [ebp-4h] BYREF

  v2 = this;
  pObject = this->File.pObject;
  Size = pObject->Scripts.Info.Data.Size;
  VMRef = v2->VMRef;
  v30 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)v2;
  file = pObject;
  n = Size;
  i = 0;
  if ( !Size )
  {
LABEL_2:
    if ( to_execute )
    {
      if ( Size )
      {
        v6 = VMRef->GlobalObjects.Data.Data[VMRef->GlobalObjects.Data.Size - 1];
        v6->Execute(v6);
      }
    }
    return !VMRef->HandleException;
  }
  while ( 1 )
  {
    v8 = pObject->Scripts.Info.Data.Data[i];
    MHeap = VMRef->MHeap;
    Alloc = MHeap->Alloc;
    v11 = 0;
    it.pObject = 0;
    v12 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)Alloc(MHeap, 128u, 0);
    if ( v12 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::GlobalObjectScript(v12, v2, VMRef, v8);
      if ( v13 )
      {
        it.pObject = v13;
        v11 = v13;
      }
    }
    if ( VMRef->HandleException )
      break;
    Instance = Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::MakeInstance(v11, &result);
    v15 = !VMRef->HandleException;
    pV = Instance->pV;
    inst.pObject = pV;
    if ( !v15 )
    {
      if ( pV )
      {
        if ( ((unsigned __int8)pV & 1) == 0 )
        {
          RefCount = pV->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pV->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
          }
        }
      }
      break;
    }
    p_GlobalObjects = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&VMRef->GlobalObjects;
    v18 = VMRef->GlobalObjects.Data.Size + 1;
    if ( v18 >= VMRef->GlobalObjects.Data.Size )
    {
      if ( v18 < VMRef->GlobalObjects.Data.Policy.Capacity )
        goto LABEL_18;
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_GlobalObjects,
        p_GlobalObjects,
        v18 + (v18 >> 2));
    }
    else
    {
      if ( v18 >= VMRef->GlobalObjects.Data.Policy.Capacity >> 1 )
        goto LABEL_18;
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_GlobalObjects,
        p_GlobalObjects,
        VMRef->GlobalObjects.Data.Size + 1);
    }
    pV = inst.pObject;
LABEL_18:
    Data = p_GlobalObjects->Data;
    VMRef->GlobalObjects.Data.Size = v18;
    v20 = &Data[v18 - 1];
    if ( v20 )
      v20->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)pV;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>>>::Set<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>(
      v30 + 17,
      &v30[17],
      &inst);
    v21 = inst.pObject;
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::InitUserDefinedClassTraits(inst.pObject);
    if ( v21 )
    {
      if ( ((unsigned __int8)v21 & 1) == 0 )
      {
        v22 = v21->RefCount;
        if ( (v22 & 0x3FFFFF) != 0 )
        {
          v21->RefCount = v22 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
        }
      }
    }
    v23 = it.pObject;
    if ( it.pObject )
    {
      if ( ((int)it.pObject & 1) == 0 )
      {
        v24 = it.pObject->RefCount;
        if ( (v24 & 0x3FFFFF) != 0 )
        {
          it.pObject->RefCount = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
        }
      }
    }
    if ( ++i >= n )
    {
      Size = n;
      goto LABEL_2;
    }
    v2 = (Scaleform::GFx::AS3::VMAbcFile *)v30;
    pObject = file;
  }
  if ( v11 )
  {
    if ( ((unsigned __int8)v11 & 1) == 0 )
    {
      v26 = v11->RefCount;
      if ( (v26 & 0x3FFFFF) != 0 )
      {
        v11->RefCount = v26 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
      }
    }
  }
  return 0;
}
