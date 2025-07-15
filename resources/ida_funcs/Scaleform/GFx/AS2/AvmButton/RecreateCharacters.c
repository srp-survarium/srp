void __thiscall Scaleform::GFx::AS2::AvmButton::RecreateCharacters(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  Scaleform::GFx::Button *pDispObj; // ebx
  Scaleform::GFx::Button::ButtonState ButtonState; // esi
  Scaleform::GFx::Button::ButtonState i; // edi
  Scaleform::GFx::Button::ButtonState v5; // esi
  Scaleform::Render::TreeContainer *pObject; // eax
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v7; // eax
  Scaleform::Render::TreeContainer *v8; // edx
  Scaleform::Render::TreeContainer *v9; // eax
  Scaleform::GFx::ButtonRecord *v10; // ebx
  bool v11; // zf
  Scaleform::GFx::Button::CharToRec *v12; // eax
  Scaleform::GFx::DisplayObjectBase *v13; // edi
  unsigned int Size; // eax
  unsigned int v15; // esi
  Scaleform::RefCountNTSImpl **p_pObject; // ebx
  Scaleform::GFx::Button::CharToRec *v17; // esi
  const Scaleform::GFx::ButtonRecord *v18; // ecx
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  Scaleform::RefCountNTSImpl *v22; // ecx
  Scaleform::Render::TreeContainer *v23; // ecx
  int v24; // eax
  unsigned int v25; // edx
  int v26; // eax
  Scaleform::GFx::ASSupport *v27; // ecx
  int v28; // eax
  Scaleform::GFx::DisplayObjectBase *v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // edi
  Scaleform::RefCountNTSImpl **v32; // ebx
  Scaleform::GFx::Button::CharToRec *v33; // edi
  int v34; // eax
  unsigned int v35; // ecx
  int v36; // eax
  Scaleform::GFx::DisplayObjectBase *pParent; // edi
  Scaleform::Render::Rect<float> *Scale9Grid; // ecx
  void (__thiscall *PropagateScale9GridExists)(Scaleform::GFx::DisplayObjectBase *); // eax
  Scaleform::GFx::ASStringNode *v40; // edi
  Scaleform::GFx::ASStringNode *pLower; // eax
  int v42; // eax
  Scaleform::GFx::Button::ButtonState j; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *pheapAddr; // [esp+21Ch] [ebp-5Ch]
  Scaleform::Render::TreeContainer *v45; // [esp+220h] [ebp-58h]
  Scaleform::GFx::ButtonRecord *v46; // [esp+224h] [ebp-54h]
  Scaleform::GFx::Button::ButtonState v48; // [esp+22Ch] [ebp-4Ch]
  Scaleform::GFx::Button *v49; // [esp+230h] [ebp-48h]
  int v50; // [esp+234h] [ebp-44h]
  Scaleform::GFx::ResourceId rid; // [esp+238h] [ebp-40h]
  int pnode; // [esp+23Ch] [ebp-3Ch]
  Scaleform::Render::TreeNode *pnodea; // [esp+23Ch] [ebp-3Ch]
  int pnodeb; // [esp+23Ch] [ebp-3Ch]
  Scaleform::Render::TreeNode *pnodec; // [esp+23Ch] [ebp-3Ch]
  int v56; // [esp+240h] [ebp-38h]
  Scaleform::GFx::Button::ButtonState v57; // [esp+244h] [ebp-34h]
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [esp+248h] [ebp-30h] BYREF
  Scaleform::GFx::Button::CharToRec v59; // [esp+24Ch] [ebp-2Ch] BYREF
  const Scaleform::GFx::ButtonRecord *Record; // [esp+258h] [ebp-20h]
  Scaleform::GFx::CharacterCreateInfo v61; // [esp+25Ch] [ebp-1Ch] BYREF
  Scaleform::Render::Rect<float> v62; // [esp+268h] [ebp-10h] BYREF

  pDispObj = (Scaleform::GFx::Button *)this->pDispObj;
  v49 = pDispObj;
  rid.Id = (unsigned int)pDispObj->pDef;
  ButtonState = Scaleform::GFx::Button::GetButtonState(mouseState);
  v57 = ButtonState;
  for ( i = Up; (unsigned int)i < StatesCount; ++i )
  {
    if ( i != ButtonState && i != Hit )
      Scaleform::GFx::Button::ClearRenderTreeForState(pDispObj, i);
  }
  v5 = Up;
  v48 = Up;
  while ( 1 )
  {
    if ( v5 == v57 || v5 == Hit )
    {
      pObject = pDispObj->States[v5].pRenNode.pObject;
      pheapAddr = &pDispObj->States[v5].Characters.Data;
      if ( pObject )
        ++pObject->RefCount;
      v45 = pObject;
      if ( !pDispObj->States[v5].Characters.Data.Size )
      {
        if ( !pObject )
        {
          v7 = Scaleform::GFx::Button::CreateStateRenderContainer(v49, &result, v5);
          if ( v7->pObject )
            ++v7->pObject->RefCount;
          v8 = v7->pObject;
          v9 = result.pObject;
          v45 = v8;
          if ( result.pObject )
          {
            --result.pObject->RefCount;
            if ( !v9->RefCount )
              Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
          }
        }
        if ( *(_DWORD *)(rid.Id + 24) )
        {
          v50 = 0;
          v56 = *(_DWORD *)(rid.Id + 24);
          while ( 1 )
          {
            v10 = (Scaleform::GFx::ButtonRecord *)(v50 + *(_DWORD *)(rid.Id + 20));
            v46 = v10;
            if ( v5 == Hit )
              break;
            switch ( mouseState )
            {
              case Unknown:
                if ( (v10->Flags & 8) == 0 )
                  break;
LABEL_32:
                if ( v5 != Hit )
                {
                  v12 = Scaleform::GFx::AS2::AvmButton::FindCharacterAndRemove(this, &v59, v10);
                  if ( v12->Char.pObject )
                    ++v12->Char.pObject->RefCount;
                  v13 = v12->Char.pObject;
                  Record = v12->Record;
                  if ( v59.Char.pObject )
                    Scaleform::RefCountNTSImpl::Release(v59.Char.pObject);
                  if ( v13 )
                  {
                    Size = pheapAddr->Size;
                    v15 = Size + 1;
                    if ( Size + 1 >= Size )
                    {
                      if ( v15 >= pheapAddr->Policy.Capacity )
                        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                          pheapAddr,
                          pheapAddr,
                          v15 + (v15 >> 2));
                    }
                    else
                    {
                      p_pObject = &pheapAddr->Data[Size - 1].Char.pObject;
                      pnode = -1;
                      do
                      {
                        if ( *p_pObject )
                          Scaleform::RefCountNTSImpl::Release(*p_pObject);
                        p_pObject -= 2;
                        --pnode;
                      }
                      while ( pnode );
                      if ( v15 < pheapAddr->Policy.Capacity >> 1 )
                        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                          pheapAddr,
                          pheapAddr,
                          v15);
                      v10 = v46;
                    }
                    pheapAddr->Size = v15;
                    v17 = &pheapAddr->Data[v15 - 1];
                    if ( v17 )
                    {
                      ++v13->RefCount;
                      v18 = Record;
                      v17->Char.pObject = v13;
                      v17->Record = v18;
                    }
                    pnodea = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v13);
                    v19 = *(_DWORD *)(*(_DWORD *)(((unsigned int)v45 & 0xFFFFF000) + 0x10)
                                    + 4 * ((int)((int)&v45[-1] - ((unsigned int)v45 & 0xFFFFF000)) / 28)
                                    + 20);
                    v20 = *(_DWORD *)(v19 + 144);
                    v21 = v19 + 144;
                    if ( v20 )
                    {
                      if ( (v20 & 1) != 0 )
                        v20 = *(_DWORD *)((v20 & 0xFFFFFFFE) + 4);
                      else
                        v20 = (*(_DWORD *)(v21 + 4) != 0) + 1;
                    }
                    Scaleform::Render::TreeContainer::Insert(v45, v20, pnodea);
                    if ( v10->pFilters.pObject )
                      v13->SetFilters(v13, v10->pFilters.pObject);
                    v13->SetMatrix(v13, &v10->ButtonMatrix);
                    Scaleform::GFx::DisplayObjectBase::SetCxform(v13, &v10->ButtonCxform);
                    v13->SetBlendMode(v13, v10->BlendMode);
                    v22 = v13;
                    goto LABEL_58;
                  }
                }
                Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                  this->pDispObj->pDefImpl.pObject,
                  (Scaleform::GFx::ResourceBinding *)&v61,
                  v10->CharacterId);
                if ( !v61.pCharDef )
                  break;
                v27 = this->pDispObj->pASRoot->pASSupport.pObject;
                v28 = ((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::InteractiveObject *, unsigned int, _DWORD))v27->CreateCharacterInstance)(
                        v27,
                        this->pDispObj->pASRoot->pMovieImpl,
                        &v61,
                        this->pDispObj,
                        v10->CharacterId.Id,
                        0);
                v29 = (Scaleform::GFx::DisplayObjectBase *)v28;
                if ( v28 )
                  ++*(_DWORD *)(v28 + 4);
                v30 = pheapAddr->Size;
                v31 = v30 + 1;
                if ( v30 + 1 >= v30 )
                {
                  if ( v31 >= pheapAddr->Policy.Capacity )
                    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                      pheapAddr,
                      pheapAddr,
                      v31 + (v31 >> 2));
                }
                else
                {
                  v32 = &pheapAddr->Data[v30 - 1].Char.pObject;
                  pnodeb = -1;
                  do
                  {
                    if ( *v32 )
                      Scaleform::RefCountNTSImpl::Release(*v32);
                    v32 -= 2;
                    --pnodeb;
                  }
                  while ( pnodeb );
                  if ( v31 < pheapAddr->Policy.Capacity >> 1 )
                    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                      pheapAddr,
                      pheapAddr,
                      v31);
                }
                pheapAddr->Size = v31;
                v33 = &pheapAddr->Data[v31 - 1];
                if ( v33 )
                {
                  if ( v29 )
                    ++v29->RefCount;
                  v33->Char.pObject = v29;
                  v33->Record = v46;
                }
                if ( v29 )
                  Scaleform::RefCountNTSImpl::Release(v29);
                pnodec = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v29);
                v34 = *(_DWORD *)(*(_DWORD *)(((unsigned int)v45 & 0xFFFFF000) + 0x10)
                                + 4 * ((int)((int)&v45[-1] - ((unsigned int)v45 & 0xFFFFF000)) / 28)
                                + 20);
                v35 = *(_DWORD *)(v34 + 144);
                v36 = v34 + 144;
                if ( v35 )
                {
                  if ( (v35 & 1) != 0 )
                    v35 = *(_DWORD *)((v35 & 0xFFFFFFFE) + 4);
                  else
                    v35 = (*(_DWORD *)(v36 + 4) != 0) + 1;
                }
                Scaleform::Render::TreeContainer::Insert(v45, v35, pnodec);
                if ( v46->pFilters.pObject )
                  v29->SetFilters(v29, v46->pFilters.pObject);
                v29->SetMatrix(v29, &v46->ButtonMatrix);
                Scaleform::GFx::DisplayObjectBase::SetCxform(v29, &v46->ButtonCxform);
                v29->SetBlendMode(v29, v46->BlendMode);
                pParent = v29->pParent;
                v29->Flags &= ~1u;
                if ( pParent )
                {
                  while ( 1 )
                  {
                    Scale9Grid = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(pParent, &v62);
                    if ( Scale9Grid->x2 > (double)Scale9Grid->x1 && Scale9Grid->y2 > (double)Scale9Grid->y1 )
                      break;
                    pParent = pParent->pParent;
                    if ( !pParent )
                      goto LABEL_94;
                  }
                  PropagateScale9GridExists = v29->PropagateScale9GridExists;
                  v29->Flags |= 1u;
                  PropagateScale9GridExists(v29);
                }
LABEL_94:
                v40 = LOBYTE(v29->Flags) >> 7 != 0 ? (Scaleform::GFx::ASStringNode *)v29 : 0;
                if ( v40 )
                {
                  Scaleform::GFx::AS2::AvmButton::ConstructCharacter(this, v40, v46);
                  Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)v40);
                  pLower = v40[4].pLower;
                  LOBYTE(pLower) = ((unsigned int)pLower & 0x200000) != 0
                                && (pLower = (Scaleform::GFx::ASStringNode *)((unsigned int)pLower >> 22),
                                    ((unsigned __int8)pLower & 1) == 0);
                  v42 = (*((int (__thiscall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASStringNode *))v40->pData
                         + 101))(
                          v40,
                          pLower);
                  if ( v42 == -1 )
                  {
                    v40[4].pLower = (Scaleform::GFx::ASStringNode *)((int)v40[4].pLower
                                                                   | (unsigned int)Scaleform::GFx::AS2::CreateShadow);
                  }
                  else if ( v42 == 1 )
                  {
                    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)v40);
                    v29->OnEventLoad(v29);
                    v22 = v29;
LABEL_58:
                    Scaleform::RefCountNTSImpl::Release(v22);
                    v5 = v48;
                    break;
                  }
                  v29->OnEventLoad(v29);
                }
                v22 = v29;
                goto LABEL_58;
              case MouseMove:
                if ( (v10->Flags & 2) == 0 )
                  break;
                goto LABEL_32;
              case MouseDown:
                v11 = (v10->Flags & 4) == 0;
                goto LABEL_31;
            }
LABEL_59:
            v50 += 96;
            if ( !--v56 )
              goto LABEL_60;
          }
          v11 = (v10->Flags & 1) == 0;
LABEL_31:
          if ( !v11 )
            goto LABEL_32;
          goto LABEL_59;
        }
      }
LABEL_60:
      if ( v5 != Hit && !v45->pParent )
      {
        v23 = v49->GetRenderContainer(v49);
        v24 = *(_DWORD *)(*(_DWORD *)(((unsigned int)v23 & 0xFFFFF000) + 0x10)
                        + 4 * ((int)((int)&v23[-1] - ((unsigned int)v23 & 0xFFFFF000)) / 28)
                        + 20);
        v25 = *(_DWORD *)(v24 + 144);
        v26 = v24 + 144;
        if ( v25 )
        {
          if ( (v25 & 1) != 0 )
            v25 = *(_DWORD *)((v25 & 0xFFFFFFFE) + 4);
          else
            v25 = (*(_DWORD *)(v26 + 4) != 0) + 1;
        }
        Scaleform::Render::TreeContainer::Insert(v23, v25, v45);
        v5 = v48;
      }
      if ( v45 )
      {
        v11 = v45->RefCount-- == 1;
        if ( v11 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v45);
      }
    }
    v48 = ++v5;
    if ( (unsigned int)v5 >= StatesCount )
      break;
    pDispObj = v49;
  }
  for ( j = Up; (unsigned int)j < StatesCount; ++j )
  {
    if ( j != v57 && j != Hit )
      Scaleform::GFx::Button::UnloadCharactersForState(v49, j);
  }
}
