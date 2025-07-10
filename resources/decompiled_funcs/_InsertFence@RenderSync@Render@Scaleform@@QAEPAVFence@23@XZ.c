Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *__thiscall Scaleform::Render::RenderSync::InsertFence(
        Scaleform::Render::RenderSync *this)
{
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *p_FenceFrames; // edi
  unsigned __int64 v4; // kr00_8
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v5; // eax
  bool v6; // cf
  Scaleform::Render::FenceFrame *pPrev; // ecx
  int NextFenceID; // edx
  int NextFenceID_high; // edi
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v10; // ebp
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v11; // edi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1> > *p_Data; // esi
  _DWORD *p_pObject; // eax
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *v14; // [esp+8h] [ebp-4h]

  p_FenceFrames = &this->FenceFrames;
  v14 = &this->FenceFrames;
  if ( (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
    return 0;
  v4 = this->SetFence(this);
  v5 = Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2>>::allocate(&this->FenceImplAlloc);
  if ( v5 )
  {
    v6 = __CFADD__(LODWORD(this->NextFenceID)++, 1);
    pPrev = p_FenceFrames->Root.pPrev;
    NextFenceID = this->NextFenceID;
    HIDWORD(this->NextFenceID) += v6;
    NextFenceID_high = HIDWORD(this->NextFenceID);
    LODWORD(v5->Data[0].APIHandle) = v4;
    v5->Data[0].RSContext = this;
    v5->Data[0].Parent = pPrev;
    HIDWORD(v5->Data[0].APIHandle) = HIDWORD(v4);
    LODWORD(v5->Data[0].FenceID) = NextFenceID;
    HIDWORD(v5->Data[0].FenceID) = NextFenceID_high;
    v10 = v5;
  }
  else
  {
    v10 = 0;
  }
  v11 = Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2>>::allocate(&this->FenceAlloc);
  if ( v11 )
  {
    v11->Data[0].Data = 0;
    v11->Data[0].RefCount = 1;
    v11->Data[0].HasData = 0;
  }
  v11->Data[0].HasData = 1;
  v11->Data[0].Data = (Scaleform::Render::FenceImpl *)v10;
  p_Data = &v14->Root.pPrev->Fences.Data;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1>>::ResizeNoConstruct(
    p_Data,
    p_Data,
    v14->Root.pPrev->Fences.Data.Size + 1);
  p_pObject = &p_Data->Data[p_Data->Size - 1].pObject;
  if ( &p_Data->Data[p_Data->Size] != (Scaleform::Ptr<Scaleform::Render::Fence> *)4 )
  {
    ++v11->Data[0].RefCount;
    *p_pObject = v11;
  }
  Scaleform::Render::Fence::Release(v11->Data);
  return v11;
}
