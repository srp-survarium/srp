void __thiscall Scaleform::Render::TreeNode::SetRendererString(Scaleform::Render::TreeNode *this, char *str)
{
  Scaleform::Render::StateBag *WritableData; // ebp
  unsigned int State; // eax
  Scaleform::StringLH *v5; // esi
  Scaleform::StringLH *v6; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                  this,
                                                  (unsigned int)Scaleform::GFx::AS2::CreateShadow);
  State = Scaleform::Render::StateBag::GetState(
            (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                      + 4
                                                      * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          + 64),
            State_MultitouchInterface);
  if ( State )
  {
    v5 = *(Scaleform::StringLH **)(State + 4);
    if ( v5 )
      Scaleform::RefCountImpl::AddRef(*(Scaleform::GFx::Resource **)(State + 4));
  }
  else
  {
    v7 = 2;
    v6 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  this,
                                  24,
                                  &v7);
    v5 = v6;
    if ( v6 )
    {
      v6->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      v6[1].HeapTypeBits = 1;
      v6->HeapTypeBits = (unsigned int)&Scaleform::Render::UserDataState::Data::`vftable';
      Scaleform::StringLH::StringLH(v6 + 2);
      *(float *)&v5[3].pData = 0.0;
      LOBYTE(v5[4].pData) = 0;
      v5[5].HeapTypeBits = 0;
    }
    else
    {
      v5 = 0;
    }
  }
  Scaleform::String::operator=(v5 + 2, str);
  v5[5].HeapTypeBits |= 1u;
  Scaleform::Render::StateBag::SetStateVoid(WritableData + 8, &Scaleform::Render::UserDataState::InterfaceImpl, v5);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
}
