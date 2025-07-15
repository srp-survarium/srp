void __thiscall Scaleform::GFx::AS3::AvmButton::SetStateObject(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::Button::ButtonState state,
        Scaleform::GFx::DisplayObject *ch)
{
  Scaleform::GFx::Button *pDispObj; // ebx
  Scaleform::GFx::Button::ButtonState v4; // ebp
  Scaleform::GFx::DisplayObject *v5; // edi
  Scaleform::Render::TreeContainer *pObject; // esi
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *StateRenderContainer; // eax
  Scaleform::Render::ContextImpl::Entry *v8; // eax
  unsigned int Size; // eax
  Scaleform::GFx::Button *pParent; // eax
  Scaleform::GFx::InteractiveObject *v11; // eax
  int v12; // ecx
  unsigned int v13; // eax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> > *p_Characters; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // esi
  Scaleform::Render::TreeNode *RenderNode; // [esp-4h] [ebp-18h]

  pDispObj = (Scaleform::GFx::Button *)this->pDispObj;
  v4 = state;
  v5 = ch;
  if ( state != 3 )
  {
    pObject = pDispObj->States[state].pRenNode.pObject;
    if ( pObject )
    {
      ++pObject->RefCount;
      Size = Scaleform::Render::TreeContainer::GetSize(pObject);
      Scaleform::Render::TreeContainer::Remove(pObject, 0, Size);
    }
    else
    {
      StateRenderContainer = Scaleform::GFx::Button::CreateStateRenderContainer(
                               pDispObj,
                               (Scaleform::Ptr<Scaleform::Render::TreeContainer> *)&state,
                               state);
      if ( StateRenderContainer->pObject )
        ++StateRenderContainer->pObject->RefCount;
      pObject = StateRenderContainer->pObject;
      v8 = (Scaleform::Render::ContextImpl::Entry *)state;
      if ( state )
      {
        --*(_DWORD *)(state + 4);
        if ( !v8->RefCount )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
      }
    }
    pParent = (Scaleform::GFx::Button *)v5->pParent;
    if ( pParent && (pParent != pDispObj || Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5)->pParent != pObject) )
    {
      v11 = v5->pParent;
      v12 = v11 ? (int)v11 + 4 * v11->AvmObjOffset : 0;
      if ( (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::DisplayObject *))(*(_DWORD *)v12 + 84))(v12, v5) )
        v5->pParent = pDispObj;
    }
    if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5)->pParent )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
      v13 = Scaleform::Render::TreeContainer::GetSize(pObject);
      Scaleform::Render::TreeContainer::Insert(pObject, v13, RenderNode);
    }
    if ( pObject )
    {
      if ( pObject->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
  }
  p_Characters = &pDispObj->States[v4].Characters;
  if ( v5 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_Characters,
      1u);
    p_pObject = &pDispObj->States[v4].Characters.Data.Data->Char.pObject;
    ++v5->RefCount;
    if ( *p_pObject )
      Scaleform::RefCountNTSImpl::Release(*p_pObject);
    *p_pObject = v5;
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_Characters,
      0);
  }
  if ( Scaleform::GFx::Button::GetButtonState(pDispObj->MouseState) == v4 )
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(this, v4);
}
