void __thiscall Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::Button::ButtonState bs)
{
  Scaleform::GFx::DisplayObject *pDispObj; // esi
  Scaleform::Render::TreeContainer *v3; // eax
  Scaleform::Render::TreeContainer *v4; // eax
  unsigned int v5; // ebx
  Scaleform::GFx::DisplayObjectBase::GeomDataType **p_pGeomData; // ebp
  int v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v11; // eax
  Scaleform::GFx::Button *v12; // ebp
  Scaleform::GFx::DisplayObjectBase *v13; // esi
  Scaleform::Render::TreeContainer *pObject; // ebx
  Scaleform::GFx::DisplayObjectBase *v15; // edi
  Scaleform::GFx::Button *pParent; // eax
  Scaleform::GFx::InteractiveObject *v17; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v18; // ecx
  unsigned int Size; // eax
  int v20; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v21; // eax
  unsigned int v22; // ebp
  int v23; // ebx
  float v24; // esi
  Scaleform::Render::TreeContainer *v25; // esi
  unsigned int v26; // eax
  Scaleform::Render::TreeNode *RenderNode; // [esp-4h] [ebp-18h]
  Scaleform::GFx::Button *button; // [esp+10h] [ebp-4h]
  Scaleform::GFx::Button::ButtonState bsa; // [esp+18h] [ebp+4h]

  pDispObj = this->pDispObj;
  button = (Scaleform::GFx::Button *)pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0
    && (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0
    && pDispObj->Depth >= -1 )
  {
    v3 = pDispObj->GetRenderContainer(pDispObj);
    if ( Scaleform::Render::TreeContainer::GetSize(v3) )
    {
      v4 = pDispObj->GetRenderContainer(pDispObj);
      Scaleform::Render::TreeContainer::Remove(v4, 0, 1u);
    }
    v5 = 0;
    p_pGeomData = &pDispObj[1].pGeomData;
    do
    {
      if ( p_pGeomData[1] )
      {
        v7 = (*(_BYTE *)((*p_pGeomData)->X + 63) & 1) != 0 ? (*p_pGeomData)->X : 0;
        v8 = (*(_WORD *)(v7 + 0x3E) & 0x200) != 0 ? v7 : 0;
        if ( v5 != bs )
        {
          v9 = *(_DWORD *)((*(_BYTE *)((*p_pGeomData)->X + 63) & 1) != 0 ? (*p_pGeomData)->X + 0x20 : 32);
          if ( v9 )
          {
            (*(void (__thiscall **)(int, int))(*(_DWORD *)(v9 + 4 * *(unsigned __int8 *)(v9 + 65)) + 84))(
              v9 + 4 * *(unsigned __int8 *)(v9 + 65),
              v7);
            *(_DWORD *)(v7 + 32) = 0;
            if ( v8 )
            {
              v10 = (*(int (__thiscall **)(int))(*(_DWORD *)(v8 + 4 * *(unsigned __int8 *)(v8 + 65)) + 4))(v8 + 4 * *(unsigned __int8 *)(v8 + 65));
              if ( v10 )
                v11 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v10 - 28);
              else
                v11 = 0;
              Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v11);
            }
          }
        }
        pDispObj = button;
      }
      ++v5;
      p_pGeomData += 4;
    }
    while ( v5 < 3 );
    if ( *((_DWORD *)&pDispObj[1].pPerspectiveData + 4 * bs) )
    {
      v12 = button;
      v13 = (*(_BYTE *)(**((_DWORD **)&pDispObj[1].pGeomData + 4 * bs) + 63) & 1) != 0
          ? (Scaleform::GFx::DisplayObjectBase *)**((_DWORD **)&pDispObj[1].pGeomData + 4 * bs)
          : 0;
      pObject = button->States[bs].pRenNode.pObject;
      v15 = (v13->Flags & 0x200) != 0 ? v13 : 0;
      bsa = (Scaleform::GFx::Button::ButtonState)pObject;
      if ( pObject )
        ++pObject->RefCount;
      pParent = (Scaleform::GFx::Button *)v13->pParent;
      if ( pParent && (pParent != button || Scaleform::GFx::DisplayObjectBase::GetRenderNode(v13)->pParent != pObject) )
      {
        v17 = v13->pParent;
        if ( v17 )
          v18 = &v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + v17->AvmObjOffset;
        else
          v18 = 0;
        ((void (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **, Scaleform::GFx::DisplayObjectBase *))(*v18)->SetY)(
          v18,
          v13);
      }
      if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(v13)->pParent )
      {
        RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v13);
        Size = Scaleform::Render::TreeContainer::GetSize(pObject);
        Scaleform::Render::TreeContainer::Insert(pObject, Size, RenderNode);
      }
      if ( !v13->pParent )
      {
        v13->pParent = button;
        if ( v15 )
        {
          v20 = (*(int (__thiscall **)(int))(*((_DWORD *)&v15->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + v15->AvmObjOffset)
                                           + 4))((int)v15 + 4 * v15->AvmObjOffset);
          if ( v20 )
            v21 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v20 - 28);
          else
            v21 = 0;
          Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v21);
          v22 = 0;
          if ( *(_DWORD *)&v15[1].ClipDepth )
          {
            v23 = 0;
            do
            {
              v24 = v15[1].pIndXFormData->OrigTransformMatrix.M[0][v23];
              if ( (*(_WORD *)(LODWORD(v24) + 62) & 0x400) != 0 )
              {
                (*(void (__thiscall **)(float, _DWORD))(*(_DWORD *)LODWORD(v24) + 432))(COERCE_FLOAT(LODWORD(v24)), 0);
                (*(void (__thiscall **)(float, _DWORD))(*(_DWORD *)LODWORD(v24) + 448))(COERCE_FLOAT(LODWORD(v24)), 0);
              }
              ++v22;
              v23 += 3;
            }
            while ( v22 < *(_DWORD *)&v15[1].ClipDepth );
            pObject = (Scaleform::Render::TreeContainer *)bsa;
          }
          v12 = button;
        }
      }
      v25 = v12->GetRenderContainer(v12);
      v26 = Scaleform::Render::TreeContainer::GetSize(v25);
      Scaleform::Render::TreeContainer::Insert(v25, v26, pObject);
      if ( pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
      }
    }
  }
}
