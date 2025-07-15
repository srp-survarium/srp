void __thiscall Scaleform::Render::TreeNode::SetScale9Grid(Scaleform::Render::TreeNode *this, int rect)
{
  Scaleform::Render::StateBag *WritableData; // eax
  const Scaleform::Render::Rect<float> *v4; // edi
  Scaleform::Render::StateBag *v5; // ebx
  void *v6; // eax
  Scaleform::RefCountVImpl *v7; // esi

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                  this,
                                                  (unsigned int)&_sbh_sizeHeaderList);
  v4 = (const Scaleform::Render::Rect<float> *)rect;
  v5 = WritableData;
  if ( *(float *)(rect + 8) <= (double)*(float *)rect || *(float *)(rect + 12) <= (double)*(float *)(rect + 4) )
  {
    Scaleform::Render::StateBag::RemoveState(WritableData + 8, State_Log);
  }
  else
  {
    rect = 2;
    v6 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 32, &rect);
    v7 = (Scaleform::RefCountVImpl *)v6;
    if ( v6 )
    {
      *(_DWORD *)v6 = &Scaleform::RefCountImplCore::`vftable';
      *((_DWORD *)v6 + 1) = 1;
      *(_DWORD *)v6 = &Scaleform::Render::Matrix4x4Ref<float>::`vftable';
      *((float *)v6 + 4) = 0.0;
      *((float *)v6 + 5) = 0.0;
      *((float *)v6 + 6) = 0.0;
      *((float *)v6 + 7) = 0.0;
      Scaleform::Render::Rect<float>::operator=((Scaleform::Render::Rect<float> *)v6 + 1, v4);
      Scaleform::Render::StateBag::SetStateVoid(v5 + 8, &Scaleform::Render::Scale9State::InterfaceImpl, v7);
      Scaleform::RefCountImpl::Release(v7);
    }
  }
}
