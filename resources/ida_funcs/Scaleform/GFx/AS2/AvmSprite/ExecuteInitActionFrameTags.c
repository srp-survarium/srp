void __thiscall Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags(
        Scaleform::GFx::AS2::AvmSprite *this,
        unsigned int frame)
{
  Scaleform::RefCountNTSImpl *Capacity; // ebp
  unsigned int v4; // esi
  unsigned int v5; // ecx
  Scaleform::GFx::TimelineDef::Frame initActionsFrame; // [esp+8h] [ebp-8h] BYREF

  if ( !*(_BYTE *)(frame + *(_DWORD *)&this->ASEnvironment.FuncCallNestingLevel) )
  {
    Capacity = (Scaleform::RefCountNTSImpl *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
    v4 = 0;
    if ( Capacity )
      ++Capacity->RefCount;
    v5 = this[-1].InitActionsExecuted.Data.Policy.Capacity;
    initActionsFrame.pTagPtrList = 0;
    initActionsFrame.TagCount = 0;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, Scaleform::GFx::TimelineDef::Frame *, unsigned int))(**(_DWORD **)(v5 + 152) + 48))(
           *(_DWORD *)(v5 + 152),
           &initActionsFrame,
           frame)
      && initActionsFrame.TagCount )
    {
      do
      {
        initActionsFrame.pTagPtrList[v4]->Execute(
          initActionsFrame.pTagPtrList[v4],
          (Scaleform::GFx::DisplayObjContainer *)this[-1].InitActionsExecuted.Data.Policy.Capacity);
        ++v4;
      }
      while ( v4 < initActionsFrame.TagCount );
      *(_BYTE *)(frame + *(_DWORD *)&this->ASEnvironment.FuncCallNestingLevel) = 1;
    }
    if ( Capacity )
      Scaleform::RefCountNTSImpl::Release(Capacity);
  }
}
