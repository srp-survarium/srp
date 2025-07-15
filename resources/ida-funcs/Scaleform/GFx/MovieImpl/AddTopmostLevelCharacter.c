void __userpurge Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        Scaleform::GFx::Sprite *pch,
        int a5,
        Scaleform::GFx::Sprite *a6)
{
  Scaleform::GFx::Sprite *v6; // esi
  Scaleform::GFx::MovieImpl *v7; // edi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // ebp
  unsigned int v9; // ebx
  Scaleform::MemoryHeap *(__thiscall *GetHeap)(Scaleform::GFx::Movie *); // eax
  Scaleform::Render::TreeNode *pObject; // esi
  Scaleform::GFx::Sprite *v12; // eax
  Scaleform::GFx::MovieImpl_vtbl *v13; // edx
  Scaleform::MemoryHeap *(__thiscall *v14)(Scaleform::GFx::Movie *); // eax
  Scaleform::MemoryHeap *v15; // eax
  Scaleform::GFx::Sprite *pParent; // edi
  unsigned int v17; // eax
  int v18; // edi
  int v19; // esi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v20; // edi
  Scaleform::GFx::Sprite *v21; // ecx
  unsigned int v22; // esi
  int v23; // eax
  int v24; // ecx
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v25; // edi
  Scaleform::Render::TreeNode *v26; // eax
  int Level; // edi
  int v31; // [esp+10h] [ebp-30h]
  int v32; // [esp+14h] [ebp-2Ch]
  Scaleform::Ptr<Scaleform::Render::TreeNode> result; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::Sprite *v34; // [esp+1Ch] [ebp-24h]
  unsigned int v35; // [esp+24h] [ebp-1Ch]
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> v36; // [esp+28h] [ebp-18h] BYREF
  void *pheapAddr; // [esp+34h] [ebp-Ch]
  __int64 v38; // [esp+38h] [ebp-8h] BYREF
  unsigned int retaddr; // [esp+40h] [ebp+0h]

  v6 = pch;
  v7 = this;
  if ( (pch->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x400) != 0
    && Scaleform::GFx::Sprite::IsLevelMovie(pch) )
  {
    return;
  }
  Data = 0;
  v9 = 0;
  if ( !v7->TopmostLevelCharacters.Data.Size )
    goto LABEL_41;
  GetHeap = v7->GetHeap;
  pObject = 0;
  v36.Policy.Capacity = 0;
  pheapAddr = 0;
  LODWORD(v38) = 0;
  v12 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::MovieImpl *, int, int))GetHeap)(v7, a3, a2);
  v13 = v7->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  pch = v12;
  v14 = v13->GetHeap;
  memset(&v36, 0, sizeof(v36));
  v15 = v14(v7);
  pParent = a6;
  pheapAddr = v15;
  do
  {
    v17 = (unsigned int)&pObject->pPrev + 1;
    result.pObject = (Scaleform::Render::TreeNode *)((char *)&pObject->pPrev + 1);
    if ( (Scaleform::Render::TreeNode *)((char *)&pObject->pPrev + 1) >= pObject )
    {
      if ( v17 >= retaddr )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v38,
          pch,
          v17 + (v17 >> 2));
    }
    else if ( v17 < retaddr >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&v38,
        pch,
        (unsigned int)&pObject->pPrev + 1);
    }
    pObject = result.pObject;
    HIDWORD(v38) = result;
    if ( (_DWORD)v38 + 4 * (int)result.pObject != 4 )
      *(_DWORD *)(v38 + 4 * (int)result.pObject - 4) = pParent;
    v34 = pParent;
    pParent = (Scaleform::GFx::Sprite *)pParent->pParent;
  }
  while ( pParent );
  v18 = v32;
  v35 = *(_DWORD *)(v32 + 15128);
  if ( !v35 )
  {
LABEL_40:
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr);
    v7 = this;
    v6 = pch;
LABEL_41:
    ++v6->RefCount;
    pch = v6;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &v7->TopmostLevelCharacters,
      0,
      (const Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&pch);
    Scaleform::RefCountNTSImpl::Release(v6);
    Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(v6, &result, (int)v7->pTopMostRoot.pObject);
    if ( result.pObject )
    {
      Scaleform::Render::TreeContainer::Insert(
        v7->pTopMostRoot.pObject,
        0,
        (Scaleform::Render::TreeNodeArray *)result.pObject);
      v26 = result.pObject;
      if ( result.pObject )
      {
        --result.pObject->RefCount;
        if ( !v26->RefCount )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v26);
      }
    }
    return;
  }
  while ( 1 )
  {
    v19 = v31;
    if ( *(Scaleform::GFx::Sprite **)(*(_DWORD *)(v18 + 15124) + 4 * v31) == a6 )
      break;
    if ( v9 )
    {
      if ( (v36.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
          Data = 0;
          v36.Data = 0;
        }
        v36.Policy.Capacity = 0;
      }
    }
    else if ( !v36.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v36,
        pheapAddr,
        0);
      Data = v36.Data;
    }
    v20 = *(Scaleform::Ptr<Scaleform::GFx::ASStringNode> **)(*(_DWORD *)(v18 + 15124) + 4 * v31);
    v9 = 0;
    v21 = 0;
    v36.Size = 0;
    if ( v20 )
    {
      while ( 1 )
      {
        v22 = v9 + 1;
        if ( v9 + 1 >= v9 )
        {
          if ( v22 >= v36.Policy.Capacity )
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &v36,
              pheapAddr,
              v22 + (v22 >> 2));
            goto LABEL_28;
          }
        }
        else if ( v22 < v36.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v36,
            pheapAddr,
            v9 + 1);
LABEL_28:
          Data = v36.Data;
        }
        ++v9;
        v36.Size = v22;
        if ( &Data[v22] != (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **)4 )
          Data[v22 - 1] = v20;
        v21 = (Scaleform::GFx::Sprite *)v20;
        v20 = (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)v20[8].pObject;
        if ( !v20 )
        {
          v19 = v31;
          break;
        }
      }
    }
    if ( v21 == v34 )
    {
      v23 = (int)&result.pObject[-1].PNode.pVoidNext + 3;
      v24 = v9 - 1;
      if ( (int)&result.pObject[-1].PNode.pVoidNext + 3 >= 0 )
      {
        while ( v24 >= 0 )
        {
          v25 = *(const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **)(v38 + 4 * v23);
          if ( v25 != Data[v24] )
          {
            if ( (int)v25[6].pObject >= (int)Data[v24][6].pObject )
              break;
            goto LABEL_40;
          }
          --v23;
          --v24;
          if ( v23 < 0 )
            break;
        }
      }
    }
    else
    {
      Level = Scaleform::GFx::Sprite::GetLevel(v21);
      if ( Level > Scaleform::GFx::Sprite::GetLevel(v34) )
        goto LABEL_40;
    }
    v31 = v19 + 1;
    if ( v19 + 1 >= v35 )
      goto LABEL_40;
    v18 = v32;
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr);
}
