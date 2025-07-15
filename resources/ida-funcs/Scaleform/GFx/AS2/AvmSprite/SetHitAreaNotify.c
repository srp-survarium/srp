void __thiscall Scaleform::GFx::AS2::AvmSprite::SetHitAreaNotify(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::Sprite *phitArea)
{
  unsigned int Capacity; // eax
  unsigned int v3; // esi
  signed int v4; // eax
  unsigned int v5; // edi
  _DWORD *v6; // edx
  Scaleform::RefCountNTSImpl *v7; // edi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *v8; // esi
  unsigned int v9; // ecx
  unsigned int Size; // edx
  Scaleform::Ptr<Scaleform::GFx::Sprite> *v11; // eax

  Capacity = this[-1].InitActionsExecuted.Data.Policy.Capacity;
  v3 = *(_DWORD *)(*(_DWORD *)(Capacity + 16) + 800);
  if ( *(_DWORD *)(Capacity + 172) && (v4 = 0, v3) )
  {
    v5 = this[-1].InitActionsExecuted.Data.Policy.Capacity;
    v6 = *(_DWORD **)(*(_DWORD *)(v5 + 16) + 796);
    while ( *v6 != v5 )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v4 = -1;
  }
  if ( phitArea )
  {
    if ( v4 == -1 )
    {
      v7 = (Scaleform::RefCountNTSImpl *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
      if ( v7 )
        ++v7->RefCount;
      v8 = *(Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> **)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 16);
      v9 = v8[66].Policy.Capacity;
      v8 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)((char *)v8 + 796);
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v8,
        v8,
        v9 + 1);
      Size = v8->Size;
      v11 = &v8->Data[Size - 1];
      if ( &v8->Data[Size] != (Scaleform::Ptr<Scaleform::GFx::Sprite> *)4 )
      {
        if ( v7 )
          ++v7->RefCount;
        v11->pObject = (Scaleform::GFx::Sprite *)v7;
      }
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
  else if ( v4 > -1 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> > *)(*(_DWORD *)(this[-1].InitActionsExecuted.Data.Policy.Capacity + 16) + 796),
      v4);
  }
}
