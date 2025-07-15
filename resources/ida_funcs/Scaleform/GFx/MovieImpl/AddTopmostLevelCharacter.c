void __userpurge Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        Scaleform::GFx::Sprite *pch,
        int a5,
        unsigned int a6)
{
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::GFx::MovieImpl *v7; // edi
  char *Capacity; // ebp
  unsigned int v9; // ebx
  Scaleform::MemoryHeap *(__thiscall *GetHeap)(Scaleform::GFx::Movie *); // eax
  Scaleform::Render::TreeNode *pObject; // esi
  Scaleform::GFx::InteractiveObject *v12; // eax
  Scaleform::GFx::MovieImpl_vtbl *v13; // edx
  Scaleform::MemoryHeap *(__thiscall *v14)(Scaleform::GFx::Movie *); // eax
  unsigned int v15; // eax
  unsigned int v16; // edi
  unsigned int v17; // eax
  Scaleform::GFx::InteractiveObject *v18; // edi
  int v19; // esi
  Scaleform::GFx::Sprite *pParent; // edi
  Scaleform::GFx::Sprite *v21; // ecx
  unsigned int v22; // esi
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  Scaleform::Render::TreeNode *v26; // eax
  int Level; // edi
  int v31; // [esp+10h] [ebp-30h]
  Scaleform::GFx::InteractiveObject *pchTopPar; // [esp+14h] [ebp-2Ch]
  Scaleform::Ptr<Scaleform::Render::TreeNode> node; // [esp+18h] [ebp-28h] BYREF
  unsigned int n; // [esp+1Ch] [ebp-24h]
  Scaleform::ArrayDH<Scaleform::GFx::DisplayObject *,2,Scaleform::ArrayDefaultPolicy> curParents; // [esp+20h] [ebp-20h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::DisplayObject *,2,Scaleform::ArrayDefaultPolicy> chParents; // [esp+30h] [ebp-10h] BYREF
  unsigned int retaddr; // [esp+40h] [ebp+0h]

  v6 = pch;
  v7 = this;
  if ( (pch->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x400) != 0
    && Scaleform::GFx::Sprite::IsLevelMovie(pch) )
  {
    return;
  }
  Capacity = 0;
  v9 = 0;
  if ( !v7->TopmostLevelCharacters.Data.Size )
    goto LABEL_41;
  GetHeap = v7->GetHeap;
  pObject = 0;
  memset(&chParents, 0, 12);
  v12 = (Scaleform::GFx::InteractiveObject *)((int (__thiscall *)(Scaleform::GFx::MovieImpl *, int, int))GetHeap)(
                                               v7,
                                               a3,
                                               a2);
  v13 = v7->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  pch = (Scaleform::GFx::Sprite *)v12;
  v14 = v13->GetHeap;
  curParents.Data.Policy.Capacity = 0;
  curParents.Data.pHeap = 0;
  chParents.Data.Data = 0;
  v15 = (int)v14(v7);
  v16 = a6;
  chParents.Data.Size = v15;
  do
  {
    v17 = (unsigned int)&pObject->pPrev + 1;
    node.pObject = (Scaleform::Render::TreeNode *)((char *)&pObject->pPrev + 1);
    if ( (Scaleform::Render::TreeNode *)((char *)&pObject->pPrev + 1) >= pObject )
    {
      if ( v17 >= retaddr )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&chParents.Data.Policy,
          pch,
          v17 + (v17 >> 2));
    }
    else if ( v17 < retaddr >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&chParents.Data.Policy,
        pch,
        (unsigned int)&pObject->pPrev + 1);
    }
    pObject = node.pObject;
    chParents.Data.pHeap = (const Scaleform::MemoryHeap *)node.pObject;
    if ( chParents.Data.Policy.Capacity + 4 * (int)node.pObject != 4 )
      *(_DWORD *)(chParents.Data.Policy.Capacity + 4 * (int)node.pObject - 4) = v16;
    n = v16;
    v16 = *(_DWORD *)(v16 + 32);
  }
  while ( v16 );
  v18 = pchTopPar;
  curParents.Data.Size = (unsigned int)pchTopPar[122].Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
  if ( !curParents.Data.Size )
  {
LABEL_40:
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Capacity);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)chParents.Data.Size);
    v7 = this;
    v6 = pch;
LABEL_41:
    ++v6->RefCount;
    pch = (Scaleform::GFx::Sprite *)v6;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &v7->TopmostLevelCharacters,
      0,
      (const Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&pch);
    Scaleform::RefCountNTSImpl::Release(v6);
    Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(v6, &node, v7->pTopMostRoot.pObject);
    if ( node.pObject )
    {
      Scaleform::Render::TreeContainer::Insert(v7->pTopMostRoot.pObject, 0, node.pObject);
      v26 = node.pObject;
      if ( node.pObject )
      {
        --node.pObject->RefCount;
        if ( !v26->RefCount )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v26);
      }
    }
    return;
  }
  while ( 1 )
  {
    v19 = v31;
    if ( *((_DWORD *)v18[121].DisplayCallbackUserPtr + v31) == a6 )
      break;
    if ( v9 )
    {
      if ( ((int)chParents.Data.Data & 0xFFFFFFFE) != 0 )
      {
        if ( Capacity )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Capacity);
          Capacity = 0;
          curParents.Data.Policy.Capacity = 0;
        }
        chParents.Data.Data = 0;
      }
    }
    else if ( !chParents.Data.Data )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&curParents.Data.Policy,
        (const void *)chParents.Data.Size,
        0);
      Capacity = (char *)curParents.Data.Policy.Capacity;
    }
    pParent = (Scaleform::GFx::Sprite *)*((_DWORD *)v18[121].DisplayCallbackUserPtr + v31);
    v9 = 0;
    v21 = 0;
    curParents.Data.pHeap = 0;
    if ( pParent )
    {
      while ( 1 )
      {
        v22 = v9 + 1;
        if ( v9 + 1 >= v9 )
        {
          if ( (Scaleform::GFx::DisplayObject **)v22 >= chParents.Data.Data )
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&curParents.Data.Policy,
              (const void *)chParents.Data.Size,
              v22 + (v22 >> 2));
            goto LABEL_28;
          }
        }
        else if ( v22 < (unsigned int)chParents.Data.Data >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&curParents.Data.Policy,
            (const void *)chParents.Data.Size,
            v9 + 1);
LABEL_28:
          Capacity = (char *)curParents.Data.Policy.Capacity;
        }
        ++v9;
        curParents.Data.pHeap = (const Scaleform::MemoryHeap *)v22;
        if ( &Capacity[4 * v22] != (char *)4 )
          *(_DWORD *)&Capacity[4 * v22 - 4] = pParent;
        v21 = pParent;
        pParent = (Scaleform::GFx::Sprite *)pParent->pParent;
        if ( !pParent )
        {
          v19 = v31;
          break;
        }
      }
    }
    if ( v21 == (Scaleform::GFx::Sprite *)n )
    {
      v23 = (int)&node.pObject[-1].PNode.pVoidNext + 3;
      v24 = v9 - 1;
      if ( (int)&node.pObject[-1].PNode.pVoidNext + 3 >= 0 )
      {
        while ( v24 >= 0 )
        {
          v25 = *(_DWORD *)(chParents.Data.Policy.Capacity + 4 * v23);
          if ( v25 != *(_DWORD *)&Capacity[4 * v24] )
          {
            if ( *(_DWORD *)(v25 + 24) >= *(_DWORD *)(*(_DWORD *)&Capacity[4 * v24] + 24) )
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
      if ( Level > Scaleform::GFx::Sprite::GetLevel((Scaleform::GFx::Sprite *)n) )
        goto LABEL_40;
    }
    v31 = v19 + 1;
    if ( v19 + 1 >= curParents.Data.Size )
      goto LABEL_40;
    v18 = pchTopPar;
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Capacity);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)chParents.Data.Size);
}
