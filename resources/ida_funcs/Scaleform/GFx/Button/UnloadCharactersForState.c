void __thiscall Scaleform::GFx::Button::UnloadCharactersForState(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::Button::ButtonState state)
{
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *p_Characters; // esi
  unsigned int v3; // ebx
  Scaleform::GFx::DisplayObjectBase *pObject; // edi
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::GFx::Button::CharToRec *v6; // edi
  unsigned int Size; // eax
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  unsigned int v9; // ebx
  Scaleform::GFx::Button::StateCharacters *v10; // ebp
  Scaleform::Render::TreeContainer *v11; // ecx
  int v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  Scaleform::Render::TreeContainer *v15; // eax

  p_Characters = &this->States[state].Characters;
  v3 = 0;
  if ( this->States[state].Characters.Data.Size )
  {
    do
    {
      pObject = p_Characters->Data.Data[v3].Char.pObject;
      if ( (LOBYTE(pObject->Flags) >> 7 != 0 ? (unsigned int)pObject : 0) != 0
        && pObject->OnUnloading(p_Characters->Data.Data[v3].Char.pObject) )
      {
        pObject->OnEventUnload(pObject);
      }
      v5 = p_Characters->Data.Data[v3].Char.pObject;
      v6 = &p_Characters->Data.Data[v3];
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      ++v3;
      v6->Char.pObject = 0;
    }
    while ( v3 < p_Characters->Data.Size );
  }
  Size = p_Characters->Data.Size;
  if ( Size )
  {
    p_pObject = &p_Characters->Data.Data[Size - 1].Char.pObject;
    v9 = p_Characters->Data.Size;
    do
    {
      if ( *p_pObject )
        Scaleform::RefCountNTSImpl::Release(*p_pObject);
      p_pObject -= 2;
      --v9;
    }
    while ( v9 );
    if ( (p_Characters->Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_Characters->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Characters->Data.Data);
        p_Characters->Data.Data = 0;
      }
      p_Characters->Data.Policy.Capacity = 0;
    }
  }
  else if ( !p_Characters->Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_Characters->Data,
      p_Characters,
      0);
  }
  v10 = &this->States[state];
  p_Characters->Data.Size = 0;
  v11 = v10->pRenNode.pObject;
  if ( v10->pRenNode.pObject )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(((unsigned int)v11 & 0xFFFFF000) + 0x10)
                    + 4 * ((int)((int)&v11[-1] - ((unsigned int)v11 & 0xFFFFF000)) / 28)
                    + 20);
    v13 = *(_DWORD *)(v12 + 144);
    v14 = v12 + 144;
    if ( v13 )
    {
      if ( (v13 & 1) != 0 )
        v13 = *(_DWORD *)((v13 & 0xFFFFFFFE) + 4);
      else
        v13 = (*(_DWORD *)(v14 + 4) != 0) + 1;
    }
    Scaleform::Render::TreeContainer::Remove(v11, 0, v13);
    if ( v10->pRenNode.pObject->pParent )
    {
      v15 = this->GetRenderContainer(this);
      Scaleform::Render::TreeContainer::Remove(v15, 0, 1u);
    }
  }
}
