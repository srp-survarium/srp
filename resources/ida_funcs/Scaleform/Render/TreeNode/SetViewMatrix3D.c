void __thiscall Scaleform::Render::TreeNode::SetViewMatrix3D(
        Scaleform::Render::TreeNode *this,
        const Scaleform::Render::Matrix3x4<float> *mat3D)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // ebp
  float *v4; // eax
  float *v5; // esi
  float *v6; // edi
  Scaleform::RefCountVImpl *v7; // ebx
  int v8; // [esp+10h] [ebp-4h] BYREF

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x80000u);
  v8 = 2;
  v4 = (float *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 64, &v8);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4 + 4;
    memset((int)(v4 + 4), 0, 0x30u);
    *v6 = 1.0;
    v5[9] = 1.0;
    v7 = (Scaleform::RefCountVImpl *)v5;
    v5[14] = 1.0;
    *(_DWORD *)v5 = &Scaleform::RefCountImplCore::`vftable';
    *((_DWORD *)v5 + 1) = 1;
    *(_DWORD *)v5 = &Scaleform::Render::Matrix4x4Ref<float>::`vftable';
  }
  else
  {
    v7 = 0;
  }
  qmemcpy(&v7[2], mat3D, 0x30u);
  Scaleform::Render::StateBag::SetStateVoid(
    (Scaleform::Render::StateBag *)&WritableData[8],
    &Scaleform::Render::ViewMatrix3DState::InterfaceImpl,
    v7);
  WritableData->Flags |= 0x800u;
  Scaleform::RefCountImpl::Release(v7);
}
